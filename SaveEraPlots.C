// Copy to interactive session to save plots

string efficiencyFolder2017 = "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2017_EfficiencyTool/CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
string efficiencyFolder2018 = "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2018_EfficiencyTool/CMSSW_10_6_2/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
string outputFolderPng = "~/cernbox/PPS/PlotsForThreePlusThreeStudies/EraPlots/"

TFile *_refined2017EraB = TFile::Open((efficiencyFolder2017+"EraB_refinedEfficiency.root").data())
TFile *_refined2017EraC1 = TFile::Open((efficiencyFolder2017+"EraC1_refinedEfficiency.root").data())
TFile *_refined2017EraC2 = TFile::Open((efficiencyFolder2017+"EraC2_refinedEfficiency.root").data())
TFile *_refined2017EraD = TFile::Open((efficiencyFolder2017+"EraD_refinedEfficiency.root").data())
TFile *_refined2017EraE = TFile::Open((efficiencyFolder2017+"EraE_refinedEfficiency.root").data())
TFile *_refined2017EraF1 = TFile::Open((efficiencyFolder2017+"EraF1_refinedEfficiency.root").data())
TFile *_refined2017EraF2 = TFile::Open((efficiencyFolder2017+"EraF2_refinedEfficiency.root").data())
TFile *_refined2017EraF3 = TFile::Open((efficiencyFolder2017+"EraF3_refinedEfficiency.root").data())
TFile *_xi2017EraB = TFile::Open((efficiencyFolder2017+"EraB_efficiencyVsXi.root").data())
TFile *_xi2017EraC1 = TFile::Open((efficiencyFolder2017+"EraC1_efficiencyVsXi.root").data())
TFile *_xi2017EraC2 = TFile::Open((efficiencyFolder2017+"EraC2_efficiencyVsXi.root").data())
TFile *_xi2017EraD = TFile::Open((efficiencyFolder2017+"EraD_efficiencyVsXi.root").data())
TFile *_xi2017EraE = TFile::Open((efficiencyFolder2017+"EraE_efficiencyVsXi.root").data())
TFile *_xi2017EraF1 = TFile::Open((efficiencyFolder2017+"EraF1_efficiencyVsXi.root").data())
TFile *_xi2017EraF2 = TFile::Open((efficiencyFolder2017+"EraF2_efficiencyVsXi.root").data())
TFile *_xi2017EraF3 = TFile::Open((efficiencyFolder2017+"EraF3_efficiencyVsXi.root").data())
TFile *_refined2018EraA = TFile::Open((efficiencyFolder2018+"EraA_refinedEfficiency.root").data())
TFile *_refined2018EraB1 = TFile::Open((efficiencyFolder2018+"EraB1_refinedEfficiency.root").data())
TFile *_refined2018EraB2 = TFile::Open((efficiencyFolder2018+"EraB2_refinedEfficiency.root").data())
TFile *_refined2018EraB = TFile::Open((efficiencyFolder2018+"EraB_refinedEfficiency.root").data())
TFile *_refined2018EraC = TFile::Open((efficiencyFolder2018+"EraC_refinedEfficiency.root").data())
TFile *_refined2018EraD1 = TFile::Open((efficiencyFolder2018+"EraD1_refinedEfficiency.root").data())
TFile *_refined2018EraD2 = TFile::Open((efficiencyFolder2018+"EraD2_refinedEfficiency.root").data())
TFile *_refined2017EraD = TFile::Open((efficiencyFolder2018+"EraD_refinedEfficiency.root").data())
TFile *_xi2018EraA = TFile::Open((efficiencyFolder2018+"EraA_efficiencyVsXi_Sample323487.root").data())
TFile *_xi2018EraB1 = TFile::Open((efficiencyFolder2018+"EraB1_efficiencyVsXi_Sample323487.root").data())
TFile *_xi2018EraB2 = TFile::Open((efficiencyFolder2018+"EraB2_efficiencyVsXi_Sample323487.root").data())
TFile *_xi2018EraB = TFile::Open((efficiencyFolder2018+"EraB_efficiencyVsXi_Sample323487.root").data())
TFile *_xi2018EraC = TFile::Open((efficiencyFolder2018+"EraC_efficiencyVsXi_Sample323487.root").data())
TFile *_xi2018EraD1 = TFile::Open((efficiencyFolder2018+"EraD1_efficiencyVsXi_Sample323487.root").data())
TFile *_xi2018EraD2 = TFile::Open((efficiencyFolder2018+"EraD2_efficiencyVsXi_Sample323487.root").data())
TFile *_xi2018EraD = TFile::Open((efficiencyFolder2018+"EraD_efficiencyVsXi_Sample323487.root").data())

setRectangularPlots()
setTDRStyle()
TCanvas c
c.SetWindowSize(1430,1023)

TFile* outputFile = new TFile("pixelEfficiencies.root","RECREATE")
outputFile->mkdir("Pixel/2017/2017B")
outputFile->mkdir("Pixel/2017/2017C1")
outputFile->mkdir("Pixel/2017/2017C2")
outputFile->mkdir("Pixel/2017/2017D")
outputFile->mkdir("Pixel/2017/2017E")
outputFile->mkdir("Pixel/2017/2017F1")
outputFile->mkdir("Pixel/2017/2017F2")
outputFile->mkdir("Pixel/2017/2017F3")
outputFile->mkdir("Pixel/2018/2018A")
outputFile->mkdir("Pixel/2018/2018B1")
outputFile->mkdir("Pixel/2018/2018B2")
outputFile->mkdir("Pixel/2018/2018C")
outputFile->mkdir("Pixel/2018/2018D1")
outputFile->mkdir("Pixel/2018/2018D2")



// *******************************************2017 Plots*******************************************

hEfficiency = new TH2D(*((TH2D*)_refined2017EraB->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_0_2_EraB.png").data())
hEfficiency->SetNameTitle("h45_220_2017B_all_2D","h45_220_2017B_all_2D")
outputFile->cd("Pixel/2017/2017B")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2017EraB->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_1_2_EraB.png").data())
hEfficiency->SetNameTitle("h56_220_2017B_all_2D","h56_220_2017B_all_2D")
outputFile->cd("Pixel/2017/2017B")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2017EraC1->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_0_2_EraC1.png").data())
hEfficiency->SetNameTitle("h45_220_2017C1_all_2D","h45_220_2017C1_all_2D")
outputFile->cd("Pixel/2017/2017C1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2017EraC1->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_1_2_EraC1.png").data())
hEfficiency->SetNameTitle("h56_220_2017C1_all_2D","h56_220_2017C1_all_2D")
outputFile->cd("Pixel/2017/2017C1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2017EraE->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_0_2_EraE.png").data())
hEfficiency->SetNameTitle("h45_220_2017E_all_2D","h45_220_2017E_all_2D")
outputFile->cd("Pixel/2017/2017E")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2017EraE->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_1_2_EraE.png").data())
hEfficiency->SetNameTitle("h56_220_2017E_all_2D","h56_220_2017E_all_2D")
outputFile->cd("Pixel/2017/2017E")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2017EraF1->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_0_2_EraF1.png").data())
hEfficiency->SetNameTitle("h45_220_2017F1_all_2D","h45_220_2017F1_all_2D")
outputFile->cd("Pixel/2017/2017F1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2017EraF1->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_1_2_EraF1.png").data())
hEfficiency->SetNameTitle("h56_220_2017F1_all_2D","h56_220_2017F1_all_2D")
outputFile->cd("Pixel/2017/2017F1")
hEfficiency->Write()

// 2017 Xi plots

hBegin = new TH1D(*((TH1D*)_xi2017EraB->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2017_EffVsXi_0_2_EraB.png").data())
hBegin->SetNameTitle("h45_220_2017B_all_1D","h45_220_2017B_all_1D")
outputFile->cd("Pixel/2017/2017B")
hBegin->Write()


hBegin = new TH1D(*((TH1D*)_xi2017EraB->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2017_Xi_0_2_EraB.png").data())

hBegin = new TH1D(*((TH1D*)_xi2017EraB->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2017_EffVsXi_1_2_EraB.png").data())
hBegin->SetNameTitle("h56_220_2017B_all_1D","h56_220_2017B_all_1D")
outputFile->cd("Pixel/2017/2017B")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraB->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2017_Xi_1_2_EraB.png").data())

hBegin = new TH1D(*((TH1D*)_xi2017EraC1->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2017_EffVsXi_0_2_EraC1.png").data())
hBegin->SetNameTitle("h45_220_2017C1_all_1D","h45_220_2017C1_all_1D")
outputFile->cd("Pixel/2017/2017C1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraC1->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2017_Xi_0_2_EraC1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2017EraC1->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2017_EffVsXi_1_2_EraC1.png").data())
hBegin->SetNameTitle("h56_220_2017C1_all_1D","h56_220_2017C1_all_1D")
outputFile->cd("Pixel/2017/2017C1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraC1->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2017_Xi_1_2_EraC1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2017EraE->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2017_EffVsXi_0_2_EraE.png").data())
hBegin->SetNameTitle("h45_220_2017E_all_1D","h45_220_2017E_all_1D")
outputFile->cd("Pixel/2017/2017E")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraE->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2017_Xi_0_2_EraE.png").data())

hBegin = new TH1D(*((TH1D*)_xi2017EraE->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2017_EffVsXi_1_2_EraE.png").data())
hBegin->SetNameTitle("h56_220_2017E_all_1D","h56_220_2017E_all_1D")
outputFile->cd("Pixel/2017/2017E")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraE->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2017_Xi_1_2_EraE.png").data())

hBegin = new TH1D(*((TH1D*)_xi2017EraF1->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2017_EffVsXi_0_2_EraF1.png").data())
hBegin->SetNameTitle("h45_220_2017F1_all_1D","h45_220_2017F1_all_1D")
outputFile->cd("Pixel/2017/2017F1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraF1->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2017_Xi_0_2_EraF1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2017EraF1->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2017_EffVsXi_1_2_EraF1.png").data())
hBegin->SetNameTitle("h56_220_2017F1_all_1D","h56_220_2017F1_all_1D")
outputFile->cd("Pixel/2017/2017F1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraF1->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2017_Xi_1_2_EraF1.png").data())


// *******************************************2018 Plots*******************************************

hEfficiency = new TH2D(*((TH2D*)_refined2018EraA->Get("Arm0_st0_rp3/h2RefinedTrackEfficiency_arm0_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_0_EraA.png").data())
hEfficiency->SetNameTitle("h45_210_2018A_all_2D","h45_210_2018A_all_2D")
outputFile->cd("Pixel/2018/2018A")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraA->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_2_EraA.png").data())
hEfficiency->SetNameTitle("h45_220_2018A_all_2D","h45_220_2018A_all_2D")
outputFile->cd("Pixel/2018/2018A")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraA->Get("Arm1_st0_rp3/h2RefinedTrackEfficiency_arm1_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_0_EraA.png").data())
hEfficiency->SetNameTitle("h56_210_2018A_all_2D","h56_210_2018A_all_2D")
outputFile->cd("Pixel/2018/2018A")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraA->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_2_EraA.png").data())
hEfficiency->SetNameTitle("h56_220_2018A_all_2D","h56_220_2018A_all_2D")
outputFile->cd("Pixel/2018/2018A")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraB1->Get("Arm0_st0_rp3/h2RefinedTrackEfficiency_arm0_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_0_EraB1.png").data())
hEfficiency->SetNameTitle("h45_210_2018B1_all_2D","h45_210_2018B1_all_2D")
outputFile->cd("Pixel/2018/2018B1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraB1->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_2_EraB1.png").data())
hEfficiency->SetNameTitle("h45_220_2018B1_all_2D","h45_220_2018B1_all_2D")
outputFile->cd("Pixel/2018/2018B1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraB1->Get("Arm1_st0_rp3/h2RefinedTrackEfficiency_arm1_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_0_EraB1.png").data())
hEfficiency->SetNameTitle("h56_210_2018B1_all_2D","h56_210_2018B1_all_2D")
outputFile->cd("Pixel/2018/2018B1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraB1->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_2_EraB1.png").data())
hEfficiency->SetNameTitle("h56_220_2018B1_all_2D","h56_220_2018B1_all_2D")
outputFile->cd("Pixel/2018/2018B1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraB2->Get("Arm0_st0_rp3/h2RefinedTrackEfficiency_arm0_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_0_EraB2.png").data())
hEfficiency->SetNameTitle("h45_210_2018B2_all_2D","h45_210_2018B2_all_2D")
outputFile->cd("Pixel/2018/2018B2")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraB2->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_2_EraB2.png").data())
hEfficiency->SetNameTitle("h45_220_2018B2_all_2D","h45_220_2018B2_all_2D")
outputFile->cd("Pixel/2018/2018B2")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraB2->Get("Arm1_st0_rp3/h2RefinedTrackEfficiency_arm1_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_0_EraB2.png").data())
hEfficiency->SetNameTitle("h56_210_2018B2_all_2D","h56_210_2018B2_all_2D")
outputFile->cd("Pixel/2018/2018B2")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraB2->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_2_EraB2.png").data())
hEfficiency->SetNameTitle("h56_220_2018B2_all_2D","h56_220_2018B2_all_2D")
outputFile->cd("Pixel/2018/2018B2")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraC->Get("Arm0_st0_rp3/h2RefinedTrackEfficiency_arm0_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_0_EraC.png").data())
hEfficiency->SetNameTitle("h45_210_2018C_all_2D","h45_210_2018C_all_2D")
outputFile->cd("Pixel/2018/2018C")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraC->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_2_EraC.png").data())
hEfficiency->SetNameTitle("h45_220_2018C_all_2D","h45_220_2018C_all_2D")
outputFile->cd("Pixel/2018/2018C")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraC->Get("Arm1_st0_rp3/h2RefinedTrackEfficiency_arm1_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_0_EraC.png").data())
hEfficiency->SetNameTitle("h56_210_2018C_all_2D","h56_210_2018C_all_2D")
outputFile->cd("Pixel/2018/2018C")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraC->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_2_EraC.png").data())
hEfficiency->SetNameTitle("h56_220_2018C_all_2D","h56_220_2018C_all_2D")
outputFile->cd("Pixel/2018/2018C")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraD1->Get("Arm0_st0_rp3/h2RefinedTrackEfficiency_arm0_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_0_EraD1.png").data())
hEfficiency->SetNameTitle("h45_210_2018D1_all_2D","h45_210_2018D1_all_2D")
outputFile->cd("Pixel/2018/2018D1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraD1->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_2_EraD1.png").data())
hEfficiency->SetNameTitle("h45_220_2018D1_all_2D","h45_220_2018D1_all_2D")
outputFile->cd("Pixel/2018/2018D1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraD1->Get("Arm1_st0_rp3/h2RefinedTrackEfficiency_arm1_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_0_EraD1.png").data())
hEfficiency->SetNameTitle("h56_210_2018D1_all_2D","h56_210_2018D1_all_2D")
outputFile->cd("Pixel/2018/2018D1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraD1->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_2_EraD1.png").data())
hEfficiency->SetNameTitle("h56_220_2018D1_all_2D","h56_220_2018D1_all_2D")
outputFile->cd("Pixel/2018/2018D1")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraD2->Get("Arm0_st0_rp3/h2RefinedTrackEfficiency_arm0_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_0_EraD2.png").data())
hEfficiency->SetNameTitle("h45_210_2018D2_all_2D","h45_210_2018D2_all_2D")
outputFile->cd("Pixel/2018/2018D2")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraD2->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_0_2_EraD2.png").data())
hEfficiency->SetNameTitle("h45_220_2018D2_all_2D","h45_220_2018D2_all_2D")
outputFile->cd("Pixel/2018/2018D2")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraD2->Get("Arm1_st0_rp3/h2RefinedTrackEfficiency_arm1_st0_rp3")))
hEfficiency->Draw("colz")
setRange_st0_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_0_EraD2.png").data())
hEfficiency->SetNameTitle("h56_210_2018D2_all_2D","h56_210_2018D2_all_2D")
outputFile->cd("Pixel/2018/2018D2")
hEfficiency->Write()

hEfficiency = new TH2D(*((TH2D*)_refined2018EraD2->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hEfficiency->Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2018_RefinedEfficiency_1_2_EraD2.png").data())
hEfficiency->SetNameTitle("h56_220_2018D2_all_2D","h56_220_2018D2_all_2D")
outputFile->cd("Pixel/2018/2018D2")
hEfficiency->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraA->Get("Arm0_st0_rp3/h1EfficiencyVsXi_arm0_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_0_EraA.png").data())
hBegin->SetNameTitle("h45_210_2018A_all_1D","h45_210_2018A_all_1D")
outputFile->cd("Pixel/2018/2018A")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraA->Get("Arm0_st0_rp3/h1Xi_arm0_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_0_EraA.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraA->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_2_EraA.png").data())
hBegin->SetNameTitle("h45_220_2018A_all_1D","h45_220_2018A_all_1D")
outputFile->cd("Pixel/2018/2018A")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraA->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_2_EraA.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraA->Get("Arm1_st0_rp3/h1EfficiencyVsXi_arm1_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_0_EraA.png").data())
hBegin->SetNameTitle("h56_210_2018A_all_1D","h56_210_2018A_all_1D")
outputFile->cd("Pixel/2018/2018A")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraA->Get("Arm1_st0_rp3/h1Xi_arm1_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_0_EraA.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraA->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_2_EraA.png").data())
hBegin->SetNameTitle("h56_220_2018A_all_1D","h56_220_2018A_all_1D")
outputFile->cd("Pixel/2018/2018A")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraA->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_2_EraA.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraB1->Get("Arm0_st0_rp3/h1EfficiencyVsXi_arm0_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_0_EraB1.png").data())
hBegin->SetNameTitle("h45_210_2018B1_all_1D","h45_210_2018B1_all_1D")
outputFile->cd("Pixel/2018/2018B1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraB1->Get("Arm0_st0_rp3/h1Xi_arm0_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_0_EraB1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraB1->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_2_EraB1.png").data())
hBegin->SetNameTitle("h45_220_2018B1_all_1D","h45_220_2018B1_all_1D")
outputFile->cd("Pixel/2018/2018B1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraB1->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_2_EraB1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraB1->Get("Arm1_st0_rp3/h1EfficiencyVsXi_arm1_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_0_EraB1.png").data())
hBegin->SetNameTitle("h56_210_2018B1_all_1D","h56_210_2018B1_all_1D")
outputFile->cd("Pixel/2018/2018B1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraB1->Get("Arm1_st0_rp3/h1Xi_arm1_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_0_EraB1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraB1->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_2_EraB1.png").data())
hBegin->SetNameTitle("h56_220_2018B1_all_1D","h56_220_2018B1_all_1D")
outputFile->cd("Pixel/2018/2018B1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraB1->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_2_EraB1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraB2->Get("Arm0_st0_rp3/h1EfficiencyVsXi_arm0_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_0_EraB2.png").data())
hBegin->SetNameTitle("h45_210_2018B2_all_1D","h45_210_2018B2_all_1D")
outputFile->cd("Pixel/2018/2018B2")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraB2->Get("Arm0_st0_rp3/h1Xi_arm0_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_0_EraB2.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraB2->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_2_EraB2.png").data())
hBegin->SetNameTitle("h45_220_2018B2_all_1D","h45_220_2018B2_all_1D")
outputFile->cd("Pixel/2018/2018B2")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraB2->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_2_EraB2.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraB2->Get("Arm1_st0_rp3/h1EfficiencyVsXi_arm1_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_0_EraB2.png").data())
hBegin->SetNameTitle("h56_210_2018B2_all_1D","h56_210_2018B2_all_1D")
outputFile->cd("Pixel/2018/2018B2")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraB2->Get("Arm1_st0_rp3/h1Xi_arm1_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_0_EraB2.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraB2->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_2_EraB2.png").data())
hBegin->SetNameTitle("h56_220_2018B2_all_1D","h56_220_2018B2_all_1D")
outputFile->cd("Pixel/2018/2018B2")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraB2->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_2_EraB2.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraC->Get("Arm0_st0_rp3/h1EfficiencyVsXi_arm0_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_0_EraC.png").data())
hBegin->SetNameTitle("h45_210_2018C_all_1D","h45_210_2018C_all_1D")
outputFile->cd("Pixel/2018/2018C")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraC->Get("Arm0_st0_rp3/h1Xi_arm0_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_0_EraC.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraC->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)

hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_2_EraC.png").data())
hBegin->SetNameTitle("h45_220_2018C_all_1D","h45_220_2018C_all_1D")
outputFile->cd("Pixel/2018/2018C")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraC->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_2_EraC.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraC->Get("Arm1_st0_rp3/h1EfficiencyVsXi_arm1_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")


// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_0_EraC.png").data())
hBegin->SetNameTitle("h56_210_2018C_all_1D","h56_210_2018C_all_1D")
outputFile->cd("Pixel/2018/2018C")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraC->Get("Arm1_st0_rp3/h1Xi_arm1_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_0_EraC.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraC->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_2_EraC.png").data())
hBegin->SetNameTitle("h56_220_2018C_all_1D","h56_220_2018C_all_1D")
outputFile->cd("Pixel/2018/2018C")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraC->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_2_EraC.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraD1->Get("Arm0_st0_rp3/h1EfficiencyVsXi_arm0_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_0_EraD1.png").data())
hBegin->SetNameTitle("h45_210_2018D1_all_1D","h45_210_2018D1_all_1D")
outputFile->cd("Pixel/2018/2018D1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraD1->Get("Arm0_st0_rp3/h1Xi_arm0_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_0_EraD1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraD1->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_2_EraD1.png").data())
hBegin->SetNameTitle("h45_220_2018D1_all_1D","h45_220_2018D1_all_1D")
outputFile->cd("Pixel/2018/2018D1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraD1->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_2_EraD1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraD1->Get("Arm1_st0_rp3/h1EfficiencyVsXi_arm1_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_0_EraD1.png").data())
hBegin->SetNameTitle("h56_210_2018D1_all_1D","h56_210_2018D1_all_1D")
outputFile->cd("Pixel/2018/2018D1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraD1->Get("Arm1_st0_rp3/h1Xi_arm1_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_0_EraD1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraD1->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_2_EraD1.png").data())
hBegin->SetNameTitle("h56_220_2018D1_all_1D","h56_220_2018D1_all_1D")
outputFile->cd("Pixel/2018/2018D1")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraD1->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_2_EraD1.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraD2->Get("Arm0_st0_rp3/h1EfficiencyVsXi_arm0_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_0_EraD2.png").data())
hBegin->SetNameTitle("h45_210_2018D2_all_1D","h45_210_2018D2_all_1D")
outputFile->cd("Pixel/2018/2018D2")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraD2->Get("Arm0_st0_rp3/h1Xi_arm0_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_0_EraD2.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraD2->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_0_2_EraD2.png").data())
hBegin->SetNameTitle("h45_220_2018D2_all_1D","h45_220_2018D2_all_1D")
outputFile->cd("Pixel/2018/2018D2")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraD2->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_0_2_EraD2.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraD2->Get("Arm1_st0_rp3/h1EfficiencyVsXi_arm1_st0_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_0_EraD2.png").data())
hBegin->SetNameTitle("h56_210_2018D2_all_1D","h56_210_2018D2_all_1D")
outputFile->cd("Pixel/2018/2018D2")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraD2->Get("Arm1_st0_rp3/h1Xi_arm1_st0_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_0_EraD2.png").data())

hBegin = new TH1D(*((TH1D*)_xi2018EraD2->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

// ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
c.Print((outputFolderPng+"2018_EffVsXi_1_2_EraD2.png").data())
hBegin->SetNameTitle("h56_220_2018D2_all_1D","h56_220_2018D2_all_1D")
outputFile->cd("Pixel/2018/2018D2")
hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2018EraD2->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->Draw()
c.Print((outputFolderPng+"2018_Xi_1_2_EraD2.png").data())


outputFile->Close()
.q


// Eff vs. Xi vs. xangle plots
setRectangularPlots()
setTDRStyle()
TCanvas c
c.SetWindowSize(1430,1023)

hBegin = new TH1D(*((TH1D*)_xi2017EraB->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(kBlue-10)
// hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("120")

hBegin = new TH1D(*((TH1D*)_xi2017EraC1->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kRed)
hBegin->SetMarkerColor(kRed)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(kRed-10)
// hBegin->SetFillColor(38)
hBegin->Draw("P E2 same")
hBegin->Draw("P E1 same")
hBegin->SetTitle("130")

hBegin = new TH1D(*((TH1D*)_xi2017EraE->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(8)
hBegin->SetMarkerColor(8)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(kGreen-10)
// hBegin->SetFillColor(38)
hBegin->Draw("P E2 same")
hBegin->Draw("P E1 same")
hBegin->SetTitle("140")

hBegin = new TH1D(*((TH1D*)_xi2017EraF1->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX()+1;i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);}

hBegin->SetLineColor(kMagenta)
hBegin->SetMarkerColor(kMagenta)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(kMagenta-10)
// hBegin->SetFillColor(38)
hBegin->Draw("P E2 same")
hBegin->Draw("P E1 same")
hBegin->SetTitle("150")




// Xi vs. xangle plots 
setRectangularPlots()
setTDRStyle()
TCanvas c
c.SetWindowSize(1430,1023)

hBegin = new TH1D(*((TH1D*)_refined2017EraF1->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->SetLineColor(kMagenta)
hBegin->SetMarkerColor(kMagenta)
hBegin->SetTitle("150")
hBegin->Draw()
hBegin = new TH1D(*((TH1D*)_refined2017EraB->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetTitle("120")
hBegin->Draw("same")
hBegin = new TH1D(*((TH1D*)_refined2017EraC1->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->SetLineColor(kRed)
hBegin->SetMarkerColor(kRed)
hBegin->SetTitle("130")
hBegin->Draw("same")
hBegin = new TH1D(*((TH1D*)_refined2017EraE->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
hBegin->SetLineColor(8)
hBegin->SetMarkerColor(8)
hBegin->SetTitle("140")
hBegin->Draw("same")
c.Print("/home/andrea/cernbox/PPS/Meetings/DPG_2019_10_28/2017_Xi_0_2_EraB_xangles.png").data())

hBegin = new TH1D(*((TH1D*)_refined2017EraF1->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->SetLineColor(kMagenta)
hBegin->SetMarkerColor(kMagenta)
hBegin->SetTitle("150")
hBegin->Draw()
hBegin = new TH1D(*((TH1D*)_refined2017EraB->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetTitle("120")
hBegin->Draw("same")
hBegin = new TH1D(*((TH1D*)_refined2017EraC1->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->SetLineColor(kRed)
hBegin->SetMarkerColor(kRed)
hBegin->SetTitle("130")
hBegin->Draw("same")
hBegin = new TH1D(*((TH1D*)_refined2017EraE->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hBegin->SetLineColor(8)
hBegin->SetMarkerColor(8)
hBegin->SetTitle("140")
hBegin->Draw("same")
c.Print("/home/andrea/cernbox/PPS/Meetings/DPG_2019_10_28/2017_Xi_1_2_EraB_xangles.png").data())

// c.Print((outputFolderPng+"2017_RefinedEfficiency_0_2_EraB.png").data())

