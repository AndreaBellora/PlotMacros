#include "FiducialCuts_ReMiniAOD.C"
#include "TStyle.h"
#include "CMS_lumi.h"

// Macro used to produce the POG paper efficiency plots

using namespace std;

// Folder to save plots
TString outputFolderImages = "/eos/home-a/abellora/PPS/PlotsForTrackerPaper/";

void setRange_st2_rectangular(TPad *pad, bool isEfficiency = false) {
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetXaxis()->SetRangeUser(0, 27);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetYaxis()->SetRangeUser(-13, 6);

  if (isEfficiency) {
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.0001);
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMaximum(1);
  }
  pad->Update();
}

void setRange_st0_rectangular(TPad *pad, bool isEfficiency = false) {
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetXaxis()->SetRangeUser(0, 27);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))
      ->GetYaxis()
      ->SetRangeUser(-11.5, 7.5);
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

void SavePlotsTrackerPaper() {

  setRectangularPlots();
  setTDRStyle();
  TCanvas c;
  c.SetWindowSize(1430, 1023);
  TH2D *effHist;
  std::map<std::pair<int, int>, double> fiducialXLow, fiducialXHigh,
      fiducialYLow, fiducialYHigh;

  TFile *_file0 = TFile::Open(
      "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2017_EfficiencyTool/"
      "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/EraB.root");
  TFile *_file1 = TFile::Open(
      "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2017_EfficiencyTool/"
      "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
      "EraB_refinedEfficiency.root");
  TFile *_file2 = TFile::Open(
      "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2018_EfficiencyTool/"
      "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
      "Run315512_refinedEfficiency.root");
  TFile *_file3 = TFile::Open(
      "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2018_EfficiencyTool/"
      "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
      "Run319337_refinedEfficiency.root");
  TFile *_file4 = TFile::Open(
      "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2018_EfficiencyTool/"
      "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
      "Run323487_refinedEfficiency.root");
  TFile *_file5 = TFile::Open(
      "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2018_EfficiencyTool/"
      "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
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
  TFile *_file10 = TFile::Open(
      "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2018_EfficiencyTool/"
      "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
      "EraA_reMiniAOD.root");
  TFile *_file11 = TFile::Open(
      "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2018_EfficiencyTool/"
      "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
      "EraA_refinedEfficiency.root");
  TFile *_file12 =
      TFile::Open("/afs/cern.ch/user/a/abellora/Work/CT-PPS/"
                  "2018_EfficiencyTool/CMSSW_10_6_10/src/RecoCTPPS/"
                  "RPixEfficiencyTools/EfficiencyVsLumiPlot.root");
  TFile *_file13 = TFile::Open(
      "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2017_EfficiencyTool/"
      "CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
      "EraB_resolution_reMiniAOD_VerySmallRegion_OneTrack_OneHit.root");
  //
  // Plane efficiency 2017B 45-220-4
  //
  effHist = (TH2D *)_file0->Get(
      "Arm0_st2_rp3/Arm0_st2_rp3_pl4/h2EfficiencyMap_arm0_st2_rp3_pl4");
  fillFiducialCutsVectors("2017B", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(0, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(0, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_rectangular((TPad *)c.GetPad(0));
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-220 FAR Plane 4", 2017);
  // Write it to file
  c.Print(outputFolderImages + "pixels-plane-efficiency.pdf");

  //
  // Radiation efficiency 2017B 45-220
  //
  effHist =
      (TH2D *)_file1->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
  fillFiducialCutsVectors("2017B", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(0, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(0, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_rectangular((TPad *)c.GetPad(0));
  effHist->SetMinimum(0.8);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-220 FAR", 2017);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2017-45-220.pdf");

  //
  // Radiation efficiency 2017B 56-220
  //
  effHist =
      (TH2D *)_file1->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3");
  fillFiducialCutsVectors("2017B", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(0, 2)] + 0.3 ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(0, 2)] + 0.1 ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(0, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_rectangular((TPad *)c.GetPad(0), true);
  effHist->SetMinimum(0.8);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 56-220 FAR", 2017);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2017-56-220.pdf");

  //
  // Radiation efficiency 2018A 
  //
  effHist = (TH2D *)_file11->Get(
      "Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
  fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(0, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(0, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_rectangular((TPad *)c.GetPad(0));
  effHist->SetMinimum(0.5);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-220 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-220.pdf");

  effHist = (TH2D *)_file11->Get(
      "Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3");
  fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(1, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(1, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(1, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(1, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_rectangular((TPad *)c.GetPad(0));
  effHist->SetMinimum(0.5);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 56-220 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-56-220.pdf");

  effHist = (TH2D *)_file11->Get(
      "Arm0_st0_rp3/h2RefinedTrackEfficiency_arm0_st0_rp3");
  fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) -
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) <
              fiducialXLow[make_pair<int, int>(0, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) -
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) >
              fiducialXHigh[make_pair<int, int>(0, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) +
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) <
              fiducialYLow[make_pair<int, int>(0, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) +
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) >
              fiducialYHigh[make_pair<int, int>(0, 0)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st0_rectangular((TPad *)c.GetPad(0));
  effHist->SetMinimum(0.5);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-210 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-210.pdf");

  effHist = (TH2D *)_file11->Get(
      "Arm1_st0_rp3/h2RefinedTrackEfficiency_arm1_st0_rp3");
  fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) -
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) <
              fiducialXLow[make_pair<int, int>(1, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) -
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) >
              fiducialXHigh[make_pair<int, int>(1, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) +
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) <
              fiducialYLow[make_pair<int, int>(1, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) +
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) >
              fiducialYHigh[make_pair<int, int>(1, 0)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st0_rectangular((TPad *)c.GetPad(0));
  effHist->SetMinimum(0.5);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 56-210 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-56-210.pdf");

  //
  // Track Hit Distributions for 2018A
  //
  effHist =
      (TH2D *)_file10->Get("Arm0_st2_rp3/h2TrackHitDistribution_arm0_st2_rp3");
  fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(0, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(0, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->SetContour(40);
  effHist->SetMinimum(100);
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_rectangular((TPad *)c.GetPad(0));
  c.SetLogz(true);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-220 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-track-distribution-2018-45-220.pdf");
  c.SetLogz(false);

  effHist =
      (TH2D *)_file10->Get("Arm1_st2_rp3/h2TrackHitDistribution_arm1_st2_rp3");
  fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(1, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(1, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(1, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(1, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->SetContour(40);
  effHist->SetMinimum(100);
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_rectangular((TPad *)c.GetPad(0));
  c.SetLogz(true);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 56-220 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-track-distribution-2018-56-220.pdf");
  c.SetLogz(false);

  effHist =
      (TH2D *)_file10->Get("Arm0_st0_rp3/h2TrackHitDistribution_arm0_st0_rp3");
  fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) -
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) <
              fiducialXLow[make_pair<int, int>(0, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) -
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) >
              fiducialXHigh[make_pair<int, int>(0, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) +
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) <
              fiducialYLow[make_pair<int, int>(0, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) +
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) >
              fiducialYHigh[make_pair<int, int>(0, 0)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->SetContour(40);
  effHist->SetMinimum(100);
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st0_rectangular((TPad *)c.GetPad(0));
  c.SetLogz(true);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-210 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-track-distribution-2018-45-210.pdf");
  c.SetLogz(false);

  effHist =
      (TH2D *)_file10->Get("Arm1_st0_rp3/h2TrackHitDistribution_arm1_st0_rp3");
  fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) -
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) <
              fiducialXLow[make_pair<int, int>(1, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) -
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) >
              fiducialXHigh[make_pair<int, int>(1, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) +
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) <
              fiducialYLow[make_pair<int, int>(1, 0)] ||
          effHist->GetXaxis()->GetBinLowEdge(i) *
                      TMath::Sin(-8. / 180. * TMath::Pi()) +
                  effHist->GetYaxis()->GetBinLowEdge(j) *
                      TMath::Cos(-8. / 180. * TMath::Pi()) >
              fiducialYHigh[make_pair<int, int>(1, 0)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->SetContour(40);
  effHist->SetMinimum(100);
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st0_rectangular((TPad *)c.GetPad(0));
  c.SetLogz(true);
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 56-210 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-track-distribution-2018-56-210.pdf");
  c.SetLogz(false);

  //
  // Radiation efficiency sequence for 2018
  //
  effHist =
      (TH2D *)_file2->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
  fillFiducialCutsVectors("2018A", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(0, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(0, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_square((TPad *)c.GetPad(0));
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-220 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-220_1.pdf");

  effHist =
      (TH2D *)_file3->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
  fillFiducialCutsVectors("2018C", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(0, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(0, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_square((TPad *)c.GetPad(0));
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-220 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-220_2.pdf");

  effHist =
      (TH2D *)_file4->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
  fillFiducialCutsVectors("2018D2", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(0, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(0, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_square((TPad *)c.GetPad(0));
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-220 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-220_3.pdf");

  effHist =
      (TH2D *)_file5->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3");
  fillFiducialCutsVectors("2018D2", fiducialXLow, fiducialXHigh, fiducialYLow,
                          fiducialYHigh);
  for (int i = 1; i < effHist->GetNbinsX(); i++) {
    for (int j = 1; j < effHist->GetNbinsY(); j++) {
      if (effHist->GetXaxis()->GetBinLowEdge(i) <
              fiducialXLow[make_pair<int, int>(0, 2)] ||
          effHist->GetXaxis()->GetBinUpEdge(i) >
              fiducialXHigh[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinLowEdge(j) <
              fiducialYLow[make_pair<int, int>(0, 2)] ||
          effHist->GetYaxis()->GetBinUpEdge(j) >
              fiducialYHigh[make_pair<int, int>(0, 2)])
        effHist->SetBinContent(i, j, 0.);
    }
  }
  effHist->Draw("colz");
  // Set the right range and proportions
  setRange_st2_square((TPad *)c.GetPad(0));
  // Write CMS watermark
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "LHC Sector 45-220 FAR", 2018);
  // Write it to file
  c.Print(outputFolderImages + "pixels-radiation-efficiency-2018-45-220_4.pdf");

  setRectangularPlots();
  c.SetWindowSize(1430, 1023);

  //
  // Peak average efficiency plot
  //

  TMultiGraph *mgAvgEfficiencyPeakFitted =
      new TMultiGraph("mgAvgEfficiencyPeakFitted",
                      "Irradiation Peak Average Efficiency (Fit Method); "
                      "Integrated Luminosity (fb^{-1}); Average Efficiency");

  TGraph *avgEffGraph_0_0 =
      (TGraph *)_file12->Get("gAvgEfficiencyPeakFitted_arm0_st0");
  TGraph *avgEffGraph_0_2 =
      (TGraph *)_file12->Get("gAvgEfficiencyPeakFitted_arm0_st2");
  TGraph *avgEffGraph_1_0 =
      (TGraph *)_file12->Get("gAvgEfficiencyPeakFitted_arm1_st0");
  TGraph *avgEffGraph_1_2 =
      (TGraph *)_file12->Get("gAvgEfficiencyPeakFitted_arm1_st2");
  avgEffGraph_0_0->SetTitle("RP 45-210 Far");
  avgEffGraph_0_2->SetTitle("RP 45-220 Far");
  avgEffGraph_1_0->SetTitle("RP 56-210 Far");
  avgEffGraph_1_2->SetTitle("RP 56-220 Far");
  mgAvgEfficiencyPeakFitted->Add(avgEffGraph_0_0, "PL");
  mgAvgEfficiencyPeakFitted->Add(avgEffGraph_0_2, "PL");
  mgAvgEfficiencyPeakFitted->Add(avgEffGraph_1_0, "PL");
  mgAvgEfficiencyPeakFitted->Add(avgEffGraph_1_2, "PL");
  mgAvgEfficiencyPeakFitted->GetXaxis()->SetTitleOffset(1);
  mgAvgEfficiencyPeakFitted->GetXaxis()->SetTitleSize(0.01);
  mgAvgEfficiencyPeakFitted->GetYaxis()->SetTitleOffset(1);
  mgAvgEfficiencyPeakFitted->GetXaxis()->SetTitleSize(0.035);
  mgAvgEfficiencyPeakFitted->GetYaxis()->SetTitleSize(0.035);
  mgAvgEfficiencyPeakFitted->GetXaxis()->SetLabelOffset(0.005);
  mgAvgEfficiencyPeakFitted->GetYaxis()->SetLabelOffset(0.005);
  mgAvgEfficiencyPeakFitted->GetXaxis()->SetLabelSize(0.035);
  mgAvgEfficiencyPeakFitted->GetYaxis()->SetLabelSize(0.035);

  mgAvgEfficiencyPeakFitted->SetMinimum(0.3);
  mgAvgEfficiencyPeakFitted->SetMaximum(1.05);
  mgAvgEfficiencyPeakFitted->Draw("A pmc plc");
  mgAvgEfficiencyPeakFitted->GetXaxis()->SetLimits(-1., 61);

  auto legend = c.BuildLegend(0.15, 0.15, 0.5, 0.4);
  legend->SetLineWidth(0);
  CMS_lumi((TPad *)c.GetPad(0), 0, 0, "", 2018);
  c.Print(outputFolderImages + "pixels-avg-efficiency-2018.pdf");

  //
  // Resolution plots
  //

  TH1D *h1 = (TH1D*)_file13->Get("Arm0_St2_rp3/h1XUnconstrainedResidualsCls2RP_arm0_st2_rp3");
  TH1D *h2 = (TH1D*)_file13->Get("Arm1_St2_rp3/h1XUnconstrainedResidualsCls2RP_arm1_st2_rp3");
  h1->Add(h2);
  h1->Rebin(2);
  h1->SetLineWidth(2);
  h1->SetFillStyle(1001);
  h1->SetFillColorAlpha(38,0.5);
  TF1* f1 = new TF1("gaus","gaus");
  f1->SetLineWidth(2);
  h1->Fit(f1);
  h1->GetXaxis()->SetTitle("x residual (mm)");
  gStyle->SetOptFit(11);
  // TPaveStats *ps = (TPaveStats*)c.GetPrimitive("stats");
  c.Print(outputFolderImages + "pixels-x-resolution-cls2.pdf");

  h1 = (TH1D*)_file13->Get("Arm0_St2_rp3/h1YUnconstrainedResidualsCls2RP_arm0_st2_rp3");
  h2 = (TH1D*)_file13->Get("Arm1_St2_rp3/h1YUnconstrainedResidualsCls2RP_arm1_st2_rp3");
  h1->Add(h2);
  h1->Rebin(4);
  h1->SetLineWidth(2);
  h1->SetFillStyle(1001);
  h1->SetFillColorAlpha(38,0.5);
  TF1* f2 = new TF1("gaus","gaus");
  f2->SetLineWidth(2);
  h1->Fit(f2);
  h1->GetXaxis()->SetTitle("y residual (mm)");
  gStyle->SetOptFit(11);
  c.Print(outputFolderImages + "pixels-y-resolution-cls2.pdf");

}