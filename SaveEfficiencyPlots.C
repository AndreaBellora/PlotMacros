// Macro used to produce the 2017 + 2018 reMiniAOD efficiency corrections

using namespace std;

// Folder containing 2017 efficiency files
string efficiencyFolder2017 =
    "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2017_EfficiencyTool/"
    "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/";
// Folder containing 2018 efficiency files
string efficiencyFolder2018 =
    "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2018_EfficiencyTool/"
    "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/";
// Folder to save plots
string outputFolderImages = "~/cernbox/PPS/Efficiency_reMiniAOD/";

// Creates efficiency files locally
void SaveEfficiencyPlots() {

  TFile *outputFile_multiRP =
      new TFile("pixelEfficiencies_multiRP_reMiniAOD.root", "RECREATE");
  TFile *outputFile_radiation =
      new TFile("pixelEfficiencies_radiation_reMiniAOD.root", "RECREATE");
  TFile *outputFile_planes =
      new TFile("pixelEfficiencies_planes_reMiniAOD.root", "RECREATE");

  vector<pair<string, string>> years_and_eras = {
      pair<string, string>("2017", "B"),
      pair<string, string>("2017", "C1"),
      pair<string, string>("2017", "C2"),
      pair<string, string>("2017", "D"),
      pair<string, string>("2017", "E"),
      pair<string, string>("2017", "Elumicorr"),
      pair<string, string>("2017", "F1"),
      pair<string, string>("2017", "F2"),
      pair<string, string>("2017", "F3"),
      pair<string, string>("2018", "A"),
      pair<string, string>("2018", "B1"),
      pair<string, string>("2018", "B2"),
      pair<string, string>("2018", "C"),
      pair<string, string>("2018", "D1"),
      pair<string, string>("2018", "D2"),
  };

  vector<string> arms = {"0", "1"};
  vector<string> stations = {"0", "2"};
  vector<string> planes = {"0", "1", "2", "3", "4", "5"};

  setRectangularPlots();
  setTDRStyle();
  TCanvas c;
  c.SetWindowSize(1430, 1023);

  // Save plots
  for (auto year_and_era : years_and_eras) {
    string year = year_and_era.first;
    string era = year_and_era.second;

    outputFile_multiRP->mkdir(("Pixel/" + year + "/" + year + era).data());
    outputFile_radiation->mkdir(("Pixel/" + year + "/" + year + era).data());
    outputFile_planes->mkdir(("Pixel/" + year + "/" + year + era).data());

    TFile *inputFile_multiRP;
    TFile *inputFile_multiRP_VsXiSingle;
    TFile *inputFile_radiation;
    TFile *inputFile_radiation_vsXi;
    TFile *inputFile_planes;

    if (year == "2017") {
      inputFile_multiRP = TFile::Open((efficiencyFolder2017 + "Era" + era +
                                       "_interpotEfficiency_reMiniAOD.root")
                                          .data());
      inputFile_multiRP_VsXiSingle =
          TFile::Open((efficiencyFolder2017 + "Era" + era +
                       "_efficiencyVsXi_fromMultiRP_XiSingle_reMiniAOD.root")
                          .data());
      inputFile_radiation = TFile::Open(
          (efficiencyFolder2017 + "Era" + era + "_refinedEfficiency.root")
              .data());
      inputFile_radiation_vsXi = TFile::Open(
          (efficiencyFolder2017 + "Era" + era + "_efficiencyVsXi.root").data());
      inputFile_planes =
          TFile::Open((efficiencyFolder2017 + "Era" + era + ".root").data());
    } else if (year == "2018") {
      inputFile_multiRP = TFile::Open((efficiencyFolder2018 + "Era" + era +
                                       "_interpotEfficiency_reMiniAOD.root")
                                          .data());
      inputFile_multiRP_VsXiSingle =
          TFile::Open((efficiencyFolder2018 + "Era" + era +
                       "_efficiencyVsXi_fromMultiRP_XiSingle_reMiniAOD.root")
                          .data());
      inputFile_radiation = TFile::Open((efficiencyFolder2018 + "Era" + era +
                                         "_refinedEfficiency_reMiniAOD.root")
                                            .data());
      inputFile_radiation_vsXi =
          TFile::Open((efficiencyFolder2018 + "Era" + era +
                       "_efficiencyVsXi_reMiniAOD.root")
                          .data());
      inputFile_planes = TFile::Open(
          (efficiencyFolder2018 + "Era" + era + "_reMiniAOD.root").data());

    } else
      return;

    for (auto arm : arms) {
      for (auto station : stations) {
        string arm_name = (arm == "0") ? "45" : "56";
        string station_name = (station == "0") ? "210" : "220";

        // Save plane efficiency plots
        if (inputFile_planes != NULL) {
          for (auto plane : planes) {
            string histName_input = "Arm" + arm + "_st" + station + "_rp3/" +
                                    "Arm" + arm + "_st" + station + "_rp3_pl" +
                                    plane + "/h2EfficiencyMap_arm" + arm +
                                    "_st" + station + "_rp3_pl" + plane;
            if (inputFile_planes->Get((histName_input).data()) != NULL) {
              TH2D h2PlaneEfficiency = TH2D(
                  *((TH2D *)inputFile_planes->Get((histName_input).data())));
              h2PlaneEfficiency.Draw("colz");
              h2PlaneEfficiency.GetXaxis()->SetRangeUser(0., 27.);
              h2PlaneEfficiency.GetYaxis()->SetRangeUser(-12.0, 7.5);
              c.Print((outputFolderImages + year + "_h2PlaneEfficiency_" + arm +
                       "_" + station + "_" + plane + "_Era" + era +
                       "_reMiniAOD.png")
                          .data());
              string histName_output = "h" + arm_name + "_" + station_name +
                                       "_" + plane + "_" + year + era +
                                       "_all_2D";
              h2PlaneEfficiency.SetNameTitle(histName_output.data(),
                                             histName_output.data());

              outputFile_planes->mkdir(("Pixel/" + year + "/" + year + era +
                                        "/Arm" + arm + "_st" + station + "_pl" +
                                        plane)
                                           .data());
              outputFile_planes->cd(("Pixel/" + year + "/" + year + era +
                                     "/Arm" + arm + "_st" + station + "_pl" +
                                     plane)
                                        .data());
              h2PlaneEfficiency.Write();
            }
          }
        }

        // Save radiation efficiency plots
        if (inputFile_radiation != NULL) {
          string histName_input = "Arm" + arm + "_st" + station +
                                  "_rp3/h2RefinedTrackEfficiency_arm" + arm +
                                  "_st" + station + "_rp3";
          if (inputFile_radiation->Get((histName_input).data()) != NULL) {
            TH2D h2RefinedEfficiency = TH2D(
                *((TH2D *)inputFile_radiation->Get((histName_input).data())));
            h2RefinedEfficiency.Draw("colz");
            h2RefinedEfficiency.GetXaxis()->SetRangeUser(0., 27.);
            h2RefinedEfficiency.GetYaxis()->SetRangeUser(-12.0, 7.5);
            string histName_output = "h" + arm_name + "_" + station_name + "_" +
                                     year + era + "_all_2D";
            h2RefinedEfficiency.SetNameTitle(histName_output.data(),
                                             histName_output.data());
            c.Print((outputFolderImages + year + "_h2RefinedEfficiency_" + arm +
                     "_" + station + "_Era" + era + "_reMiniAOD.png")
                        .data());
            outputFile_radiation->cd(
                ("Pixel/" + year + "/" + year + era).data());
            h2RefinedEfficiency.Write();

            string histVsXiName_input = "Arm" + arm + "_st" + station +
                                        "_rp3/h1EfficiencyVsXi_arm" + arm +
                                        "_st" + station + "_rp3";
            if (inputFile_radiation_vsXi != NULL &&
                inputFile_radiation_vsXi->Get((histVsXiName_input).data()) !=
                    NULL) {

              TH1D h1RefinedEfficiencyVsXi =
                  TH1D(*((TH1D *)inputFile_radiation_vsXi->Get(
                      histVsXiName_input.data())));
              for (auto i = 0; i < h1RefinedEfficiencyVsXi.GetNbinsX() + 1;
                   i++) {
                if (h1RefinedEfficiencyVsXi.GetBinContent(i) != 0)
                  h1RefinedEfficiencyVsXi.SetBinError(i, 0.01);
              }
              h1RefinedEfficiencyVsXi.SetLineColor(kBlue);
              h1RefinedEfficiencyVsXi.SetMarkerColor(kBlue);
              h1RefinedEfficiencyVsXi.SetMarkerStyle(kFullSquare);
              h1RefinedEfficiencyVsXi.SetFillColor(38);
              h1RefinedEfficiencyVsXi.Draw("P E2");
              h1RefinedEfficiencyVsXi.Draw("P E1 same");
              h1RefinedEfficiencyVsXi.GetYaxis()->SetRangeUser(0.001, 1.1);
              h1RefinedEfficiencyVsXi.GetYaxis()->SetNdivisions(22, 1, 1);
              string histVsXiName_output = "h" + arm_name + "_" + station_name +
                                           "_" + year + era + "_all_1D";
              h1RefinedEfficiencyVsXi.SetNameTitle(histVsXiName_output.data(),
                                                   histVsXiName_output.data());
              c.SetGridy(true);

              c.Print((outputFolderImages + year +
                       "_h1RefinedEfficiencyVsXiSingle_" + arm + "_" + station +
                       "_Era" + era + "_reMiniAOD.png")
                          .data());
              c.SetGridy(false);
              outputFile_radiation->cd(
                  ("Pixel/" + year + "/" + year + era).data());
              h1RefinedEfficiencyVsXi.Write();
            }
          }
        }

        // Save multiRP efficiency plots
        // Only 220 Far RPs
        if (station == "2" && inputFile_multiRP != NULL) {
          string histName_input = "Arm" + arm + "_st" + station +
                                  "_rp3/h2InterPotEfficiencyMapMultiRP_arm" +
                                  arm + "_st" + station + "_rp3";
          if (inputFile_multiRP->Get((histName_input).data()) != NULL) {
            TH2D h2MultiRPEfficiency = TH2D(
                *((TH2D *)inputFile_multiRP->Get((histName_input).data())));
            h2MultiRPEfficiency.Draw("colz");
            h2MultiRPEfficiency.GetXaxis()->SetRangeUser(0., 27.);
            h2MultiRPEfficiency.GetYaxis()->SetRangeUser(-12.0, 7.5);
            string histName_output = "h" + arm_name + "_" + station_name + "_" +
                                     year + era + "_all_2D";
            h2MultiRPEfficiency.SetNameTitle(histName_output.data(),
                                             histName_output.data());
            c.Print((outputFolderImages + year + "_h2MultiRPEfficiency_" + arm +
                     "_" + station + "_Era" + era + "_reMiniAOD.png")
                        .data());
            outputFile_multiRP->cd(("Pixel/" + year + "/" + year + era).data());
            h2MultiRPEfficiency.Write();

            // Save TEfficiency too
            string TEffName_input = "Arm" + arm + "_st" + station +
                                    "_rp3/TEInterPotEfficiencyMapMultiRP_arm" +
                                    arm + "_st" + station + "_rp3";
            TEfficiency TEMultiRPEfficiency =
                TEfficiency(*((TEfficiency *)inputFile_multiRP->Get(
                    (TEffName_input).data())));
            string TEffName_output = "TE" + arm_name + "_" + station_name +
                                     "_" + year + era + "_all_2D";
            TEMultiRPEfficiency.SetNameTitle(TEffName_output.data(),
                                             TEffName_output.data());
            TEMultiRPEfficiency.Write();
          }

          string histVsXiName_input = "Arm" + arm + "_st" + station +
                                      "_rp3/h1EfficiencyVsXi_arm" + arm +
                                      "_st" + station + "_rp3";
          if (inputFile_multiRP_VsXiSingle != NULL &&
              inputFile_multiRP_VsXiSingle->Get((histVsXiName_input).data()) !=
                  NULL) {

            TH1D h1MultiRPEffVsXiSingle =
                TH1D(*((TH1D *)inputFile_multiRP_VsXiSingle->Get(
                    histVsXiName_input.data())));
            for (auto i = 0; i < h1MultiRPEffVsXiSingle.GetNbinsX() + 1; i++) {
              if (h1MultiRPEffVsXiSingle.GetBinContent(i) != 0)
                h1MultiRPEffVsXiSingle.SetBinError(i, 0.01);
            }
            h1MultiRPEffVsXiSingle.SetLineColor(kBlue);
            h1MultiRPEffVsXiSingle.SetMarkerColor(kBlue);
            h1MultiRPEffVsXiSingle.SetMarkerStyle(kFullSquare);
            h1MultiRPEffVsXiSingle.SetFillColor(38);
            h1MultiRPEffVsXiSingle.Draw("P E2");
            h1MultiRPEffVsXiSingle.Draw("P E1 same");
            h1MultiRPEffVsXiSingle.GetYaxis()->SetRangeUser(0.001, 1.1);
            h1MultiRPEffVsXiSingle.GetYaxis()->SetNdivisions(22, 1, 1);
            string histVsXiName_output = "h" + arm_name + "_" + station_name +
                                         "_" + year + era + "_all_1D";
            h1MultiRPEffVsXiSingle.SetNameTitle(histVsXiName_output.data(),
                                                histVsXiName_output.data());
            c.SetGridy(true);

            c.Print((outputFolderImages + year + "_h1MultiRPEffVsXiSingle_" +
                     arm + "_" + station + "_Era" + era + "_reMiniAOD.png")
                        .data());
            c.SetGridy(false);
          }
        }
      }
    }
  }

  outputFile_multiRP->Close();
  outputFile_radiation->Close();
  outputFile_planes->Close();
}
