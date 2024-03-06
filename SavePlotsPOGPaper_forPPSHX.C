#include "FiducialCuts_ReMiniAOD.C"
#include "plotconfigs.C"
#include "tdrstyle.C"
#include "TStyle.h"
#include "CMS_lumi.h"

// Macro used to produce the POG paper efficiency plots

using namespace std;

// Folder to save plots
TString outputFolderImages = "plotsForPPSHX/";

void setRange_st2_rectangular(TPad *pad, bool isEfficiency = false) {
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetXaxis()->SetRangeUser(0, 27);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetYaxis()->SetRangeUser(-12.5, 7);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.);

  if (isEfficiency) {
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.0001);
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMaximum(1);
  }
  pad->Update();
}

void setRange_st0_rectangular(TPad *pad, bool isEfficiency = false) {
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetXaxis()->SetRangeUser(0, 15);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetYaxis()->SetRangeUser(-5, 5);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.);

  if (isEfficiency) {
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.0001);
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMaximum(1);
  }
  pad->Update();
}

void setRange_st2_square(TPad *pad, bool isEfficiency = false) {
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetXaxis()->SetRangeUser(0, 9.5);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))
      ->GetYaxis()
      ->SetRangeUser(-3.25, 6);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.0001);
  if (isEfficiency) {
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.8);
  }
  pad->Update();
}

void SavePlotsPOGPaper_forPPSHX() {

  setRectangularPlots();
  setTDRStyle();
  TCanvas c;
  c.SetWindowSize(1430, 1023);
  TH2D *effHist;
  std::map<std::pair<int, int>, double> fiducialXLow, fiducialXHigh,
      fiducialYLow, fiducialYHigh;

  TFile *_file0 = TFile::Open(
      "/eos/project/c/ctpps/subsystems/Pixel/RPixTracking/EfficiencyCalculation2017/Results/EraB.root");
  TFile *_file1 = TFile::Open(
      "/eos/project/c/ctpps/subsystems/Pixel/RPixTracking/EfficiencyCalculation2017/Results/"
      "EraB_refinedEfficiency.root");
  TFile *_file2 = TFile::Open(
      "/eos/project/c/ctpps/subsystems/Pixel/RPixTracking/EfficiencyCalculation2018/Results/"
      "Run315512_refinedEfficiency.root");
  TFile *_file3 = TFile::Open(
      "/eos/project/c/ctpps/subsystems/Pixel/RPixTracking/EfficiencyCalculation2018/Results/"
      "Run319337_refinedEfficiency.root");
  TFile *_file4 = TFile::Open(
      "/eos/project/c/ctpps/subsystems/Pixel/RPixTracking/EfficiencyCalculation2018/Results/"
      "Run323487_refinedEfficiency.root");
  TFile *_file5 = TFile::Open(
      "/eos/project/c/ctpps/subsystems/Pixel/RPixTracking/EfficiencyCalculation2018/Results/"
      "Run324841_refinedEfficiency.root");
  TFile *_file6 =
      TFile::Open("/eos/project-c/ctpps/subsystems/Pixel/RPixTracking/"
                  "pixelEfficiencies_multiRP_reMiniAOD.root");
  TFile *_file7 =
      TFile::Open("/eos/project/c/ctpps/subsystems/Strips/StripsTracking/"
                  "PreliminaryEfficiencies_July132020_1D2DMultiTrack.root");
  TFile *_file8 = TFile::Open("/afs/cern.ch/work/a/abellora/Work/CT-PPS/"
                              "POGPaper/CMSSW_11_3_0_pre5/src/"
                              "Validation/CTPPS/test/simu/output_Up.root");
  TFile *_file9 = TFile::Open("/afs/cern.ch/work/a/abellora/Work/CT-PPS/"
                              "POGPaper/CMSSW_11_3_0_pre5/src/"
                              "Validation/CTPPS/test/simu/output_Down.root");
  TFile *_file10 = TFile::Open("/afs/cern.ch/work/a/abellora/Work/CT-PPS/"
                              "POGPaper/CMSSW_11_3_0_pre5/src/"
                              "Validation/CTPPS/test/simu/output.root");
  TFile *_file11 = TFile::Open("/afs/cern.ch/work/a/abellora/Work/CT-PPS/POGPaper/Strips_h56_2017F3_all_2DStrips_h56_2017F3_all_2D.root");

//   //
//   // Plane efficiency 2017B 45-220-4
//   //
//   effHist = (TH2D *)_file0->Get(
//       "Arm0_st2_rp3/Arm0_st2_rp3_pl4/h2EfficiencyMap_arm0_st2_rp3_pl4");
//   fillFiducialCutsVectors("2017B", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(0, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_rectangular((TPad *)c.GetPad(0));
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "LHC Sector 45-220 FAR Plane 4", 2017);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-plane-efficiency.pdf");

//   //
//   // Radiation efficiency 2017B 45-220
//   //
//   effHist =
//       (TH2D *)_file1->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
//   fillFiducialCutsVectors("2017B", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(0, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
  
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_rectangular((TPad *)c.GetPad(0));
//   effHist->SetMinimum(0.8);
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2017);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-radiation-efficiency-2017-45-220.pdf");

//   //
//   // Radiation efficiency 2017B 56-220
//   //
//   effHist =
//       (TH2D *)_file1->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3");
//   fillFiducialCutsVectors("2017B", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(0, 2)] + 0.3 ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(0, 2)] + 0.1 ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(0, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_rectangular((TPad *)c.GetPad(0), true);
//   effHist->SetMinimum(0.8);
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2017);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-radiation-efficiency-2017-56-220.pdf");

//   //
//   // MultiRP efficiency 2017E
//   //
//   effHist = (TH2D *)_file6->Get("Pixel/2017/2017E/h45_220_2017E_all_2D");
//   fillFiducialCutsVectors("2017E", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(0, 2)] + 0.3 ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(0, 2)] + 0.1 ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(0, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_rectangular((TPad *)c.GetPad(0));
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2017);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-multiRP-efficiency-2017-45-220.pdf");

//   effHist = (TH2D *)_file6->Get("Pixel/2017/2017E/h56_220_2017E_all_2D");
//   fillFiducialCutsVectors("2017E", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(0, 2)] + 0.3 ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(0, 2)] + 0.1 ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(0, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_rectangular((TPad *)c.GetPad(0));
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2017);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-multiRP-efficiency-2017-56-220.pdf");

//   //
//   // MultiRP efficiency 2018A
//   //
//   effHist = (TH2D *)_file6->Get("Pixel/2018/2018A/h45_220_2018A_all_2D");
//   fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(1, 2)] + 0.3 ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(1, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(1, 2)] + 0.1 ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(1, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->SetContour(40);
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_rectangular((TPad *)c.GetPad(0));
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2018);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-multiRP-efficiency-2018-45-220.pdf");

//   effHist = (TH2D *)_file6->Get("Pixel/2018/2018A/h56_220_2018A_all_2D");
//   fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(1, 2)] + 0.3 ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(1, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(1, 2)] + 0.1 ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(1, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->SetContour(40);
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_rectangular((TPad *)c.GetPad(0));
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2018);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-multiRP-efficiency-2018-56-220.pdf");

//   setSquarePlots();
//   c.SetWindowSize(1101, 1023);

//   //
//   // Radiation efficiency sequence for 2018
//   //
//   effHist =
//       (TH2D *)_file2->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
//   fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(0, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_square((TPad *)c.GetPad(0));
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2018);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-220_1.pdf");

//   effHist =
//       (TH2D *)_file3->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
//   fillFiducialCutsVectors("2018C", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(0, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_square((TPad *)c.GetPad(0));
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2018);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-220_2.pdf");

//   effHist =
//       (TH2D *)_file4->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
//   fillFiducialCutsVectors("2018D2", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(0, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_square((TPad *)c.GetPad(0));
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2018);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-220_3.pdf");

//   effHist =
//       (TH2D *)_file5->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
//   fillFiducialCutsVectors("2018D2", fiducialXLow, fiducialXHigh, fiducialYLow,
//                           fiducialYHigh);
//   for (int i = 1; i < effHist->GetNbinsX(); i++) {
//     for (int j = 1; j < effHist->GetNbinsY(); j++) {
//       if (effHist->GetXaxis()->GetBinLowEdge(i) <
//               fiducialXLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetXaxis()->GetBinUpEdge(i) >
//               fiducialXHigh[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinLowEdge(j) <
//               fiducialYLow[make_pair<int, int>(0, 2)] ||
//           effHist->GetYaxis()->GetBinUpEdge(j) >
//               fiducialYHigh[make_pair<int, int>(0, 2)])
//         effHist->SetBinContent(i, j, 0.);
//     }
//   }
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st2_square((TPad *)c.GetPad(0));
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 11, "", 2018);
//   // Write it to file
//   c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-220_4.pdf");
  
  // 
  // Avg efficiencies per year
  // 
  setTDRStyle();

  // Sector 45 
  TH1D *eff2016_Up = 
      (TH1D *)_file8->Get("Efficiency2016_0");
  TH1D *eff2016_Down = 
      (TH1D *)_file9->Get("Efficiency2016_0");
  TH1D *eff2017_Up = 
      (TH1D *)_file8->Get("Efficiency2017_0");
  TH1D *eff2017_Down = 
      (TH1D *)_file9->Get("Efficiency2017_0");
  TH1D *eff2018_Up = 
      (TH1D *)_file8->Get("Efficiency2018_0");
  TH1D *eff2018_Down = 
      (TH1D *)_file9->Get("Efficiency2018_0");
  eff2016_Up->Smooth(2);
  eff2016_Down->Smooth(2);
  eff2017_Up->Smooth(2);
  eff2017_Down->Smooth(2);
  eff2018_Up->Smooth(2);
  eff2018_Down->Smooth(2);
  TGraphErrors *eff2016 = new TGraphErrors();
  eff2016->SetFillColor(kGreen);
  eff2016->SetLineColor(kGreen);
  eff2016->SetLineWidth(2);
  eff2016->SetFillStyle(3002);
  TGraphErrors *eff2017 = new TGraphErrors();
  eff2017->SetFillColor(eff2017_Up->GetFillColor());
  eff2017->SetLineColor(eff2017_Up->GetFillColor());
  eff2017->SetLineWidth(2);
  eff2017->SetFillStyle(3002);
  TGraphErrors *eff2018 = new TGraphErrors();
  eff2018->SetFillColor(eff2018_Up->GetFillColor());
  eff2018->SetLineColor(eff2018_Up->GetFillColor());
  eff2018->SetLineWidth(2);
  eff2018->SetFillStyle(3002);
  for (int i = 2; i < eff2016_Up->GetNbinsX();i++){
    int nPoint = eff2016->GetN();
    eff2016->SetPoint(nPoint,eff2016_Up->GetBinCenter(i), (eff2016_Up->GetBinContent(i)+eff2016_Down->GetBinContent(i))/2.);
    eff2016->SetPointError(nPoint,0., (eff2016_Up->GetBinContent(i)-eff2016_Down->GetBinContent(i))/2.);
    eff2017->SetPoint(nPoint,eff2017_Up->GetBinCenter(i), (eff2017_Up->GetBinContent(i)+eff2017_Down->GetBinContent(i))/2.);
    eff2017->SetPointError(nPoint,0., (eff2017_Up->GetBinContent(i)-eff2017_Down->GetBinContent(i))/2.);
    eff2018->SetPoint(nPoint,eff2018_Up->GetBinCenter(i), (eff2018_Up->GetBinContent(i)+eff2018_Down->GetBinContent(i))/2.);
    eff2018->SetPointError(nPoint,0., (eff2018_Up->GetBinContent(i)-eff2018_Down->GetBinContent(i))/2.);
  }

  // eff2018->Draw("a3");
  eff2018->Draw("alx");
  eff2018->GetXaxis()->SetLimits(0.,0.2);
  eff2018->GetYaxis()->SetLabelSize(0.035);
  eff2018->GetXaxis()->SetLabelSize(0.035);
  eff2018->GetXaxis()->SetTitleSize(0.035);
  eff2018->GetXaxis()->SetTitleOffset(1.2);
  eff2018->GetXaxis()->SetTitle("#it{#xi}_{#font[132]{multi}}");
  eff2018->GetYaxis()->SetTitleSize(0.035);
  eff2018->GetYaxis()->SetTitleOffset(1.2);
  eff2018->GetYaxis()->SetTitle("Acceptance #times  Efficiency");
  eff2018->GetHistogram()->SetMinimum(0.);
  eff2018->GetHistogram()->SetMaximum(0.95);
  // eff2018->Draw("a3");
  // eff2016->Draw("3same");
  // eff2017->Draw("3same");
  eff2018->Draw("alx");
//   eff2016->Draw("lsamex");
//   eff2017->Draw("lsamex");
  auto legend = new TLegend(0.65,0.65,0.9,0.85);
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);
//   legend->AddEntry(eff2016,"2016","l");
//   legend->AddEntry(eff2017,"2017","l");
  legend->AddEntry(eff2018,"2018","l");
  legend->Draw();

  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 4, 11, "Sector 45");
  eff2018->SetName("AccTimesEff_2018_45");
  eff2018->SaveAs(outputFolderImages + "AccTimesEff_2018_45.root");
  c.Print(outputFolderImages + "AccTimesEff_2018_45.pdf");

  // Sector 56
  eff2016_Up = 
      (TH1D *)_file8->Get("Efficiency2016_1");
  eff2016_Down = 
      (TH1D *)_file9->Get("Efficiency2016_1");
  eff2017_Up = 
      (TH1D *)_file8->Get("Efficiency2017_1");
  eff2017_Down = 
      (TH1D *)_file9->Get("Efficiency2017_1");
  eff2018_Up = 
      (TH1D *)_file8->Get("Efficiency2018_1");
  eff2018_Down = 
      (TH1D *)_file9->Get("Efficiency2018_1");
  eff2016_Up->Smooth(2);
  eff2016_Down->Smooth(2);
  eff2017_Up->Smooth(2);
  eff2017_Down->Smooth(2);
  eff2018_Up->Smooth(2);
  eff2018_Down->Smooth(2);
  eff2016 = new TGraphErrors();
  eff2016->SetFillColor(kGreen);
  eff2016->SetLineColor(kGreen);
  eff2016->SetLineWidth(2);
  eff2016->SetFillStyle(3002);
  eff2017 = new TGraphErrors();
  eff2017->SetFillColor(eff2017_Up->GetFillColor());
  eff2017->SetLineColor(eff2017_Up->GetFillColor());
  eff2017->SetLineWidth(2);
  eff2017->SetFillStyle(3002);
  eff2018 = new TGraphErrors();
  eff2018->SetFillColor(eff2018_Up->GetFillColor());
  eff2018->SetLineColor(eff2018_Up->GetFillColor());
  eff2018->SetLineWidth(2);
  eff2018->SetFillStyle(3002);
  for (int i = 2; i < eff2016_Up->GetNbinsX();i++){
    int nPoint = eff2016->GetN();
    eff2016->SetPoint(nPoint,eff2016_Up->GetBinCenter(i), (eff2016_Up->GetBinContent(i)+eff2016_Down->GetBinContent(i))/2.);
    eff2016->SetPointError(nPoint,0., (eff2016_Up->GetBinContent(i)-eff2016_Down->GetBinContent(i))/2.);
    eff2017->SetPoint(nPoint,eff2017_Up->GetBinCenter(i), (eff2017_Up->GetBinContent(i)+eff2017_Down->GetBinContent(i))/2.);
    eff2017->SetPointError(nPoint,0., (eff2017_Up->GetBinContent(i)-eff2017_Down->GetBinContent(i))/2.);
    eff2018->SetPoint(nPoint,eff2018_Up->GetBinCenter(i), (eff2018_Up->GetBinContent(i)+eff2018_Down->GetBinContent(i))/2.);
    eff2018->SetPointError(nPoint,0., (eff2018_Up->GetBinContent(i)-eff2018_Down->GetBinContent(i))/2.);
  }

  // eff2018->Draw("a3");
  eff2018->Draw("alx");
  eff2018->GetXaxis()->SetLimits(0.,0.2);
  eff2018->GetYaxis()->SetLabelSize(0.035);
  eff2018->GetXaxis()->SetLabelSize(0.035);
  eff2018->GetXaxis()->SetTitleSize(0.035);
  eff2018->GetXaxis()->SetTitleOffset(1.2);
  eff2018->GetXaxis()->SetTitle("#it{#xi}_{#font[132]{multi}}");
  eff2018->GetYaxis()->SetTitleSize(0.035);
  eff2018->GetYaxis()->SetTitleOffset(1.2);
  eff2018->GetYaxis()->SetTitle("Acceptance #times  Efficiency");
  eff2018->GetHistogram()->SetMinimum(0.);
  eff2018->GetHistogram()->SetMaximum(0.95);
  eff2018->Draw("alx");
//   eff2016->Draw("lsamex");
//   eff2017->Draw("lsamex");
  // eff2018->Draw("a3");
  // eff2016->Draw("3same");
  // eff2017->Draw("3same");
  legend = new TLegend(0.65,0.65,0.9,0.85);
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);
  legend->AddEntry(eff2016,"2016","l");
  legend->AddEntry(eff2017,"2017","l");
  legend->AddEntry(eff2018,"2018","l");
  legend->Draw();

  // // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 4, 11, "Sector 56");
  eff2018->SetName("AccTimesEff_2018_56");
  eff2018->SaveAs(outputFolderImages + "AccTimesEff_2018_56.root");
  c.Print(outputFolderImages + "AccTimesEff_2018_56.pdf");

  // 
  // Avg acceptances per year
  // 
  // setTDRStyle();

  // Sector 45 
  eff2016_Up = 
      (TH1D *)_file10->Get("Acceptance2016_0");
  eff2017_Up = 
      (TH1D *)_file10->Get("Acceptance2017_0");
  eff2018_Up = 
      (TH1D *)_file10->Get("Acceptance2018_0");
  eff2016_Up->Smooth(2);
  eff2017_Up->Smooth(2);
  eff2018_Up->Smooth(2);
  eff2016 = new TGraphErrors();
  eff2016->SetFillColor(kGreen);
  eff2016->SetLineColor(kGreen);
  eff2016->SetLineWidth(2);
  eff2016->SetFillStyle(3002);
  eff2017 = new TGraphErrors();
  eff2017->SetFillColor(eff2017_Up->GetFillColor());
  eff2017->SetLineColor(eff2017_Up->GetFillColor());
  eff2017->SetLineWidth(2);
  eff2017->SetFillStyle(3002);
  eff2018 = new TGraphErrors();
  eff2018->SetFillColor(eff2018_Up->GetFillColor());
  eff2018->SetLineColor(eff2018_Up->GetFillColor());
  eff2018->SetLineWidth(2);
  eff2018->SetFillStyle(3002);
  for (int i = 2; i < eff2016_Up->GetNbinsX();i++){
    int nPoint = eff2016->GetN();
    eff2016->SetPoint(nPoint,eff2016_Up->GetBinCenter(i), eff2016_Up->GetBinContent(i));
    eff2016->SetPointError(nPoint,0., 0);
    eff2017->SetPoint(nPoint,eff2017_Up->GetBinCenter(i), eff2017_Up->GetBinContent(i));
    eff2017->SetPointError(nPoint,0., 0);
    eff2018->SetPoint(nPoint,eff2018_Up->GetBinCenter(i), eff2018_Up->GetBinContent(i));
    eff2018->SetPointError(nPoint,0., 0);
  }

  // eff2018->Draw("a3");
  eff2018->Draw("alx");
  eff2018->GetXaxis()->SetLimits(0.,0.2);
  eff2018->GetYaxis()->SetLabelSize(0.035);
  eff2018->GetXaxis()->SetLabelSize(0.035);
  eff2018->GetXaxis()->SetTitleSize(0.035);
  eff2018->GetXaxis()->SetTitleOffset(1.2);
  eff2018->GetXaxis()->SetTitle("#it{#xi}_{#font[132]{multi}}");
  eff2018->GetYaxis()->SetTitleSize(0.035);
  eff2018->GetYaxis()->SetTitleOffset(1.2);
  eff2018->GetYaxis()->SetTitle("Acceptance");
  eff2018->GetHistogram()->SetMinimum(0.);
  eff2018->GetHistogram()->SetMaximum(1.15);
  // eff2018->Draw("a3");
  // eff2016->Draw("3same");
  // eff2017->Draw("3same");
  eff2018->Draw("alx");
//   eff2016->Draw("lsamex");
//   eff2017->Draw("lsamex");
  legend = new TLegend(0.65,0.65,0.9,0.85);
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);
  legend->AddEntry(eff2016,"2016","l");
  legend->AddEntry(eff2017,"2017","l");
  legend->AddEntry(eff2018,"2018","l");
  legend->Draw();

  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 4, 11, "Sector 45");
  eff2018->SetName("Acc_2018_45");
  eff2018->SaveAs(outputFolderImages + "Acc_2018_45.root");
  c.Print(outputFolderImages + "Acc_2018_45.pdf");

  // Sector 56
  eff2016_Up = 
      (TH1D *)_file10->Get("Acceptance2016_1");
  eff2017_Up = 
      (TH1D *)_file10->Get("Acceptance2017_1");
  eff2018_Up = 
      (TH1D *)_file10->Get("Acceptance2018_1");
  eff2016_Up->Smooth(2);
  eff2017_Up->Smooth(2);
  eff2018_Up->Smooth(2);
  eff2016 = new TGraphErrors();
  eff2016->SetFillColor(kGreen);
  eff2016->SetLineColor(kGreen);
  eff2016->SetLineWidth(2);
  eff2016->SetFillStyle(3002);
  eff2017 = new TGraphErrors();
  eff2017->SetFillColor(eff2017_Up->GetFillColor());
  eff2017->SetLineColor(eff2017_Up->GetFillColor());
  eff2017->SetLineWidth(2);
  eff2017->SetFillStyle(3002);
  eff2018 = new TGraphErrors();
  eff2018->SetFillColor(eff2018_Up->GetFillColor());
  eff2018->SetLineColor(eff2018_Up->GetFillColor());
  eff2018->SetLineWidth(2);
  eff2018->SetFillStyle(3002);
  for (int i = 2; i < eff2016_Up->GetNbinsX();i++){
    int nPoint = eff2016->GetN();
    eff2016->SetPoint(nPoint,eff2016_Up->GetBinCenter(i), eff2016_Up->GetBinContent(i));
    eff2016->SetPointError(nPoint,0., 0);
    eff2017->SetPoint(nPoint,eff2017_Up->GetBinCenter(i), eff2017_Up->GetBinContent(i));
    eff2017->SetPointError(nPoint,0., 0);
    eff2018->SetPoint(nPoint,eff2018_Up->GetBinCenter(i), eff2018_Up->GetBinContent(i));
    eff2018->SetPointError(nPoint,0., 0);
  }

  // eff2018->Draw("a3");
  eff2018->Draw("alx");
  eff2018->GetXaxis()->SetLimits(0.,0.2);
  eff2018->GetYaxis()->SetLabelSize(0.035);
  eff2018->GetXaxis()->SetLabelSize(0.035);
  eff2018->GetXaxis()->SetTitleSize(0.035);
  eff2018->GetXaxis()->SetTitleOffset(1.2);
  eff2018->GetXaxis()->SetTitle("#it{#xi}_{#font[132]{multi}}");
  eff2018->GetYaxis()->SetTitleSize(0.035);
  eff2018->GetYaxis()->SetTitleOffset(1.2);
  eff2018->GetYaxis()->SetTitle("Acceptance");
  eff2018->GetHistogram()->SetMinimum(0.);
  eff2018->GetHistogram()->SetMaximum(1.15);
  eff2018->Draw("alx");
//   eff2016->Draw("lsamex");
//   eff2017->Draw("lsamex");
  // eff2018->Draw("a3");
  // eff2016->Draw("3same");
  // eff2017->Draw("3same");
  legend = new TLegend(0.65,0.65,0.9,0.85);
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);
  legend->AddEntry(eff2016,"2016","l");
  legend->AddEntry(eff2017,"2017","l");
  legend->AddEntry(eff2018,"2018","l");
  legend->Draw();

  // // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 4, 11, "Sector 56");
  eff2018->SetName("Acc_2018_56");
  eff2018->SaveAs(outputFolderImages + "Acc_2018_56.root");
  c.Print(outputFolderImages + "Acc_2018_56.pdf");


//   setRectangularPlots();
//   setTDRStyle();
//   c.SetWindowSize(1430, 1023);


//   //
//   // Strips radiation sequence for 2017
//   //
//   gStyle->SetPalette(kThermometer);
//   effHist = (TH2D *)_file7->Get("Strips/2017/2017E/h56_2017E_all_2D");
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitle("y (mm)");
//   effHist->GetXaxis()->SetTitle("x (mm)");
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st0_rectangular((TPad *)c.GetPad(0), true);
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 0, "", 2017);
//   // Write it to file
//   c.Print(outputFolderImages + "strips-radiation-efficiency-2017-56-210_0.pdf");

//   gStyle->SetPalette(kThermometer);
//   effHist = (TH2D *)_file7->Get("Strips/2017/2017F1/h56_2017F1_all_2D");
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitle("y (mm)");
//   effHist->GetXaxis()->SetTitle("x (mm)");
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st0_rectangular((TPad *)c.GetPad(0), true);
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 0, "", 2017);
//   // Write it to file
//   c.Print(outputFolderImages + "strips-radiation-efficiency-2017-56-210_1.pdf");

//   gStyle->SetPalette(kThermometer);
//   effHist = (TH2D *)_file7->Get("Strips/2017/2017F2/h56_2017F2_all_2D");
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitle("y (mm)");
//   effHist->GetXaxis()->SetTitle("x (mm)");
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st0_rectangular((TPad *)c.GetPad(0), true);
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 0, "", 2017);
//   // Write it to file
//   c.Print(outputFolderImages + "strips-radiation-efficiency-2017-56-210_2.pdf");

//   gStyle->SetPalette(kThermometer);

//   effHist = new TH2D(*((TH2D*)((TCanvas*)_file11->Get("cx"))->GetPad(0)->GetPrimitive("hblahdiv")));
//   c.cd();
//   effHist->GetZaxis()->SetLabelSize(0.035);
//   effHist->GetYaxis()->SetLabelSize(0.035);
//   effHist->GetYaxis()->SetTitle("y (mm)");
//   effHist->GetXaxis()->SetTitle("x (mm)");
//   effHist->GetXaxis()->SetLabelSize(0.035);  
//   effHist->GetXaxis()->SetTitleSize(0.05);
//   effHist->GetYaxis()->SetTitleSize(0.05);
//   effHist->GetXaxis()->SetTitleOffset(0.9);
//   effHist->GetYaxis()->SetTitleOffset(0.9);
//   effHist->GetXaxis()->SetLabelOffset(0.005);
//   effHist->GetYaxis()->SetLabelOffset(0.005);
//   effHist->GetZaxis()->SetLabelOffset(0.005);
//   effHist->Draw("colz");
//   // Set the right range and proportions
//   setRange_st0_rectangular((TPad *)c.GetPad(0), true);
//   // Write CMS watermark
//   CMS_lumi((TPad *)c.GetPad(0), 4, 0, "", 2017);
//   // Write it to file
//   c.Print(outputFolderImages + "strips-radiation-efficiency-2017-56-210_3.pdf");


}