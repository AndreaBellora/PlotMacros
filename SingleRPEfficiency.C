// This is a macro to produce he singleRP efficiency plots from the multiRP and
// radiation efficiency file

#include <iomanip>
#include <iostream>

using namespace std;

// Fit plateau. Use same ranges for all maps, for now
void fitPlateau(double &p0, double &e_p0, double &chi2r, TH2D *map,
                vector<double> fitRanges);

void varPlateau(TFile *multiRP_efficiency_file, TCanvas *c, TString year,
                TString era, TString sector, TString station, double variation);

// Compute singleRP efficiency corrections and store them in the file
void SingleRPEfficiency() {

  TFile *multiRP_efficiency_file =
      TFile::Open(("pixelEfficiencies_multiRP_reMiniAOD.root"));
  TFile *radiation_efficiency_file =
      TFile::Open(("pixelEfficiencies_radiation_reMiniAOD.root"));

  if (multiRP_efficiency_file == NULL || radiation_efficiency_file == NULL) {
    cout << "ERROR: One of the input files was not found, exiting..." << endl;
    return;
  }

  // vector<TString> years_to_analyze = {"2017"};
  vector<TString> years_to_analyze = {"2017", "2018"};

  vector<TString> eras2017 = {"B", "C1", "C2", "D", "E", "F1", "F2", "F3"};
  vector<TString> eras2017_avg = {"C", "F"};
  vector<TString> eras2018 = {"A", "B1", "B2", "C", "D1", "D2"};
  vector<TString> eras2018_avg = {"B", "D"};
  map<TString, double> lumiWeights = {
      {"C1", 5372685500.084013939 / 8.6806766e+09},
      {"C2", 3307991145.520657539 / 8.6806766e+09},
      {"F1", 1714884890.072064877 / 1.3247273e+10},
      {"F2", 7889974131.627684593 / 1.3247273e+10},
      {"F3", 3642413583.456357479 / 1.3247273e+10},
      {"B1", 6135903882.410737991 / 6517624249.612241745},
      {"B2", 381720367.201503396 / 6517624249.612241745},
      {"D1", 19998142938.951736450 / 30496850186.283702850},
      {"D2", 10498707247.331964493 / 30496850186.283702850}};

  TFile *singleRPEfficiencyFile =
      new TFile("pixelEfficiencies_singleRP_reMiniAOD.root", "RECREATE");
  TFile *singleRPChecksFile =
      new TFile("singleRPChecks_reMiniAOD.root", "RECREATE");

  vector<TString> sectors = {"45", "56"};
  // vector<TString> stations = {"210", "220"};
  vector<TString> stations = {"220"};

  for (auto &year : years_to_analyze) {
    vector<TString> eras;
    if (year == "2017")
      eras = eras2017;
    else if (year == "2018")
      eras = eras2018;

    TH2D *h2MultiRP_efficiency;
    TH2D *h2Radiation_efficiency;
    TH2D *h2SingleRP_efficiency;

    // Produce map for each era, sector and station
    for (auto &era : eras) {
      TString map_path = "Pixel/" + year + "/" + year + era + "/";
      singleRPEfficiencyFile->mkdir(map_path);
      singleRPChecksFile->mkdir(map_path);
      bool is3plus3 = false;
      if (era == "C2" || era == "F2" || era == "F3")
        is3plus3 = true;
      for (auto &sector : sectors) {
        for (auto &station : stations) {
          if (station == "220") {

            TString map_name =
                "h" + sector + "_" + station + "_" + year + era + "_all_2D";

            cout << "Analyzing " + map_name + "..." << endl;

            // Try to retrieve maps
            if (multiRP_efficiency_file->Get(map_path + map_name) == NULL) {
              cout << "MultiRP efficiency map not found, skipping..." << endl
                   << endl;
              continue;
            }

            h2MultiRP_efficiency = new TH2D(
                *((TH2D *)multiRP_efficiency_file->Get(map_path + map_name)));

            if (radiation_efficiency_file->Get(map_path + map_name) == NULL) {
              cout << "Radiation efficiency map not found, assuming it's 3+3 "
                      "mode"
                   << endl;
            }

            // If the multiRP map is found, but not the radiation,
            // assume it's 3+3

            if (is3plus3) {
              // If we are in 3+3 the singleRP efficiency will be the multiRP
              // one, valid only at high xi
              h2SingleRP_efficiency = new TH2D(*h2MultiRP_efficiency);
            } else {
              // If we are not in 3+3, get the radiation efficiency and
              // initialize the singleRP with the radiation, then rescale to
              // match the multiRP efficiency plateau
              h2Radiation_efficiency = new TH2D(*(
                  (TH2D *)radiation_efficiency_file->Get(map_path + map_name)));
              h2SingleRP_efficiency = new TH2D(*h2Radiation_efficiency);

              // Fit a horizontal plane on the multiRP efficiency plateu region
              // I'll use the same fit range for all the maps, this could be
              // improved
              vector<double> fitRanges = {11., 14., -2.5, 3.5};
              double plateau, e_plateau, chi2r;

              fitPlateau(plateau, e_plateau, chi2r, h2MultiRP_efficiency,
                         fitRanges);

              cout << "Fit results: " << endl;
              cout << "Plateau value = " << setprecision(2) << plateau
                   << " +/- " << e_plateau << endl;
              cout << "Chi2r = " << chi2r << endl << endl;
              h2SingleRP_efficiency->Scale(plateau);

              // Plot all the checks
              TCanvas *c = new TCanvas(
                  TString("VariationPlots") + "_" + sector + "_" + station,
                  TString("VariationPlots") + "_" + sector + "_" + station,
                  1280, 720);
              c->Divide(2, 2);
              varPlateau(multiRP_efficiency_file, c, year, era, sector, station,
                         1);
              singleRPChecksFile->cd(map_path);
              c->Write();
              delete c;
            }

            cout << "Saving " + map_name << endl << endl;

            singleRPEfficiencyFile->cd(map_path);
            h2SingleRP_efficiency->SetMaximum(1.);
            // h2SingleRP_efficiency->SetMinimum(0.75);
            h2SingleRP_efficiency->Write();

            delete h2MultiRP_efficiency;
            delete h2SingleRP_efficiency;
            if (!is3plus3)
              delete h2Radiation_efficiency;
            cout << "**********************************************************"
                    "**************"
                 << endl;
          }
        }
      }
    }
  }

  // Create singleRP efficiencies averaged over multiple eras
  for (auto &year : years_to_analyze) {
    vector<TString> eras_avg;
    vector<TString> eras;
    if (year == "2017") {
      eras = eras2017;
      eras_avg = eras2017_avg;
    } else if (year == "2018") {
      eras = eras2018;
      eras_avg = eras2018_avg;
    }

    for (auto era_avg : eras_avg) {
      TString map_path_avg = "Pixel/" + year + "/" + year + era_avg + "/";
      for (auto sector : sectors) {
        for (auto station : stations) {
          TString map_name_avg =
              "h" + sector + "_" + station + "_" + year + era_avg + "_all_2D";
          TH2D *h2SingleRP_efficiency_avg = 0;
          cout << "Producing " + map_name_avg << endl;

          if (station == "220") {
            for (auto era : eras) {
              TString map_path = "Pixel/" + year + "/" + year + era + "/";
              if (era[0] == era_avg) {
                TString map_name =
                    "h" + sector + "_" + station + "_" + year + era + "_all_2D";

                cout << "Adding " + map_name + " to the average" << endl;

                if (singleRPEfficiencyFile->Get(map_path + map_name) == NULL) {
                  cout << "SingleRP efficiency map not found, skipping..."
                       << endl;
                  continue;
                }

                TH2D *h2SingleRP_efficiency = new TH2D(*(
                    (TH2D *)singleRPEfficiencyFile->Get(map_path + map_name)));
                if (h2SingleRP_efficiency_avg == NULL) {
                  h2SingleRP_efficiency_avg = new TH2D(*h2SingleRP_efficiency);
                  h2SingleRP_efficiency_avg->Scale(lumiWeights[era]);
                } else {
                  // sum the histograms by hand
                  for (int xbin = 1;
                       xbin < h2SingleRP_efficiency_avg->GetNbinsX(); xbin++) {
                    for (int ybin = 1;
                         ybin < h2SingleRP_efficiency_avg->GetNbinsY();
                         ybin++) {
                      double xbin_center =
                          h2SingleRP_efficiency_avg->GetXaxis()->GetBinCenter(
                              xbin);
                      double ybin_center =
                          h2SingleRP_efficiency_avg->GetYaxis()->GetBinCenter(
                              ybin);
                      double binContent =
                          h2SingleRP_efficiency_avg->GetBinContent(xbin, ybin) +
                          h2SingleRP_efficiency->GetBinContent(
                              h2SingleRP_efficiency->FindBin(xbin_center,
                                                             ybin_center)) *
                              lumiWeights[era];
                      h2SingleRP_efficiency_avg->SetBinContent(xbin, ybin,
                                                               binContent);
                      h2SingleRP_efficiency_avg->SetBinError(xbin,ybin,0.01);
                      // Do something for errors?
                    }
                  }
                }
              }
            }
          }
          singleRPEfficiencyFile->mkdir(map_path_avg);
          singleRPEfficiencyFile->cd(map_path_avg);
          h2SingleRP_efficiency_avg->SetNameTitle(map_name_avg, map_name_avg);
          h2SingleRP_efficiency_avg->SetMaximum(1.);
          h2SingleRP_efficiency_avg->Write();
          delete h2SingleRP_efficiency_avg;
          h2SingleRP_efficiency_avg = 0;
        }
      }
    }
  }

  singleRPEfficiencyFile->Close();
  singleRPChecksFile->Close();
  cout << "Results stored in " << singleRPEfficiencyFile->GetName() << endl;
  cout << "Checks stored in " << singleRPChecksFile->GetName() << endl;
}

void varPlateau(TFile *multiRP_efficiency_file, TCanvas *c, TString year,
                TString era, TString sector, TString station,
                double variation) {

  vector<double> fitRanges = {11., 14., -2.5, 3.5};

  if (multiRP_efficiency_file == NULL) {
    cout << "ERROR: Input file not found" << endl;
    return;
  }

  TString map_path = "Pixel/" + year + "/" + year + era + "/";
  TString map_name =
      "h" + sector + "_" + station + "_" + year + era + "_all_2D";

  // Get multiRP efficiency hist
  TH2D *h2MultiRP_efficiency =
      new TH2D(*((TH2D *)multiRP_efficiency_file->Get(map_path + map_name)));

  if (h2MultiRP_efficiency == NULL) {
    cout << "ERROR: Efficiency histogram not found. Exiting..." << endl;
    return;
  }

  int nPoints = 20;
  double variationStep = 2 * variation / (nPoints - 1);

  // Book graphs & cosmetics
  TGraphErrors *xVariationPlot = new TGraphErrors(nPoints);
  xVariationPlot->SetTitle(
      "Plateau value vs. x offset;x offset (mm);Plateau value");
  xVariationPlot->SetMarkerStyle(20);

  TGraphErrors *yVariationPlot = new TGraphErrors(nPoints);
  yVariationPlot->SetTitle(
      "Plateau value vs. y offset;y offset (mm);Plateau value");
  yVariationPlot->SetMarkerStyle(20);

  TGraph *xChi2Plot = new TGraph(nPoints);
  xChi2Plot->SetTitle(
      "Reduced #chi^{2} of fit vs. x offset;x offset (mm);Reduced #chi^{2}");
  xChi2Plot->SetMarkerStyle(20);

  TGraph *yChi2Plot = new TGraph(nPoints);
  yChi2Plot->SetTitle(
      "Reduced #chi^{2} of fit vs. y offset;y offset (mm);Reduced #chi^{2}");
  yChi2Plot->SetMarkerStyle(20);

  // Cycle for x variations
  for (int i = 0; i < nPoints; i++) {
    vector<double> fitRanges_mod = fitRanges;
    double offset = -variation + variationStep * i;
    fitRanges_mod.at(0) = fitRanges.at(0) + offset;
    fitRanges_mod.at(1) = fitRanges.at(1) + offset;

    // Variables to store the fit results
    double plateau, e_plateau, chi2r;
    fitPlateau(plateau, e_plateau, chi2r, h2MultiRP_efficiency, fitRanges_mod);
    xVariationPlot->SetPoint(i, offset, plateau);
    xVariationPlot->SetPointError(i, 0, e_plateau);
    xChi2Plot->SetPoint(i, offset, chi2r);
  }

  // Cycle for y variations
  for (int i = 0; i < nPoints; i++) {
    vector<double> fitRanges_mod = fitRanges;
    double offset = -variation + variationStep * i;
    fitRanges_mod.at(2) = fitRanges.at(2) + offset;
    fitRanges_mod.at(3) = fitRanges.at(3) + offset;

    // Variables to store the fit results
    double plateau, e_plateau, chi2r;
    fitPlateau(plateau, e_plateau, chi2r, h2MultiRP_efficiency, fitRanges_mod);
    yVariationPlot->SetPoint(i, offset, plateau);
    yVariationPlot->SetPointError(i, 0, e_plateau);
    yChi2Plot->SetPoint(i, offset, chi2r);
  }

  // Detect eventual issues
  // (maximum 1% efficiency variation when moving the area)
  double maxSlope = 0.01 / 2 * variation;
  if (abs(xVariationPlot->Fit("pol1", "SQ")->Parameter(1)) > maxSlope)
    cout << "WARNING: The slope along x is quite high!" << endl;
  if (xChi2Plot->GetMaximum() > 3)
    cout << "WARNING: High Chi2 values along x!" << endl;
  if (abs(yVariationPlot->Fit("pol1", "SQ")->Parameter(1)) > maxSlope)
    cout << "WARNING: The slope along y is quite high!" << endl;
  if (yChi2Plot->GetMaximum() > 3)
    cout << "WARNING: High Chi2 values along y!" << endl;

  c->cd(1);
  c->GetPad(1)->SetGrid();
  xVariationPlot->Draw("AP");
  c->cd(2);
  c->GetPad(2)->SetGrid();
  xChi2Plot->Draw("AP");
  c->cd(3);
  c->GetPad(3)->SetGrid();
  yVariationPlot->Draw("AP");
  c->cd(4);
  c->GetPad(4)->SetGrid();
  yChi2Plot->Draw("AP");
}

void fitPlateau(double &p0, double &e_p0, double &chi2r, TH2D *map,
                vector<double> fitRanges) {

  TF2 *fitFunc = new TF2("fitFunction", "[0]", fitRanges.at(0), fitRanges.at(1),
                         fitRanges.at(2), fitRanges.at(3));
  map->Fit(fitFunc, "RNQ");
  p0 = fitFunc->GetParameter(0);
  e_p0 = fitFunc->GetParError(0);
  chi2r = fitFunc->GetChisquare() / fitFunc->GetNDF();

  delete fitFunc;
}