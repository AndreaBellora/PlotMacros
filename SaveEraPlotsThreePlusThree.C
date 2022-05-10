string efficiencyFolder2017 = "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2017_EfficiencyTool/CMSSW_10_6_10/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
string efficiencyFolder2018 = "/afs/cern.ch/user/a/abellora/Work/CT-PPS/2018_EfficiencyTool/CMSSW_10_6_2/src/RecoCTPPS/RPixEfficiencyTools/OutputFiles/"
string outputFolderPng = "~/cernbox/PPS/PlotsForThreePlusThreeStudies/EraPlots/"

TFile *_refined2017EraC2 = TFile::Open((efficiencyFolder2017+"EraC2_refinedEfficiency.root").data())
TFile *_refined2017EraD = TFile::Open((efficiencyFolder2017+"EraD_refinedEfficiency.root").data())
TFile *_refined2017EraF2 = TFile::Open((efficiencyFolder2017+"EraF2_refinedEfficiency.root").data())
TFile *_refined2017EraF3 = TFile::Open((efficiencyFolder2017+"EraF3_refinedEfficiency.root").data())
TFile *_inter2017EraC2 = TFile::Open((efficiencyFolder2017+"EraC2_interpotEfficiency_noMaxPixelTracks.root").data())
TFile *_inter2017EraD = TFile::Open((efficiencyFolder2017+"EraD_interpotEfficiency_noMaxPixelTracks.root").data())
TFile *_inter2017EraF2 = TFile::Open((efficiencyFolder2017+"EraF2_interpotEfficiency_noMaxPixelTracks.root").data())
TFile *_inter2017EraF3 = TFile::Open((efficiencyFolder2017+"EraF3_interpotEfficiency_noMaxPixelTracks.root").data())
TFile *_xi2017EraB = TFile::Open((efficiencyFolder2017+"EraB_efficiencyVsXi.root").data())
TFile *_xi2017EraC1 = TFile::Open((efficiencyFolder2017+"EraC1_efficiencyVsXi.root").data())
TFile *_xi2017EraC2 = TFile::Open((efficiencyFolder2017+"EraC2_efficiencyVsXi.root").data())
TFile *_xi2017EraD = TFile::Open((efficiencyFolder2017+"EraD_efficiencyVsXi.root").data())
TFile *_xi2017EraE = TFile::Open((efficiencyFolder2017+"EraE_efficiencyVsXi.root").data())
TFile *_xi2017EraF1 = TFile::Open((efficiencyFolder2017+"EraF1_efficiencyVsXi.root").data())
TFile *_xi2017EraF2 = TFile::Open((efficiencyFolder2017+"EraF2_efficiencyVsXi.root").data())
TFile *_xi2017EraF3 = TFile::Open((efficiencyFolder2017+"EraF3_efficiencyVsXi.root").data())
TFile *_xiCombined2017EraC2 = TFile::Open((efficiencyFolder2017+"EraC2_efficiencyVsXi_fromCombinedEfficiencyPlot_noMaxPixelTracks.root").data())
TFile *_xiCombined2017EraD = TFile::Open((efficiencyFolder2017+"EraD_efficiencyVsXi_fromCombinedEfficiencyPlot_noMaxPixelTracks.root").data())
TFile *_xiCombined2017EraF2 = TFile::Open((efficiencyFolder2017+"EraF2_efficiencyVsXi_fromCombinedEfficiencyPlot_noMaxPixelTracks.root").data())
TFile *_xiCombined2017EraF3 = TFile::Open((efficiencyFolder2017+"EraF3_efficiencyVsXi_fromCombinedEfficiencyPlot_noMaxPixelTracks.root").data())

// TFile* outputFile = new TFile("pixelEfficiencies.root","RECREATE")

// outputFile.mkdir("Pixel/2017/2017C2")
// outputFile.mkdir("Pixel/2017/2017D")
// outputFile.mkdir("Pixel/2017/2017F2")
// outputFile.mkdir("Pixel/2017/2017F3")

setRectangularPlots()
setTDRStyle()
TCanvas c
c.SetWindowSize(1430,1023)

hNormalEfficiency = TH2D(*((TH2D*)_refined2017EraC2->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hNormalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_0_2_EraC2.png").data())
hNormalEfficiency.SetNameTitle("h45_220_2017C2_all_2D","h45_220_2017C2_all_2D")

hInterpotEfficiency = TH2D(*((TH2D*)_inter2017EraC2->Get("Arm0_st2_rp3/h2InterPotEfficiencyMap_arm0_st2_rp3")))
hInterpotEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_InterpotEfficiency_0_2_EraC2.png").data())
hInterpotEfficiency.SetNameTitle("h45_220_2017C2_all_2D","h45_220_2017C2_all_2D")

hFinalEfficiency = TH2D(hNormalEfficiency)
for(auto i=0;i<hNormalEfficiency.GetNbinsX();i++){
	for(auto j=0;j<hNormalEfficiency.GetNbinsY();j++){
		if(i < 68 && j > 128) hFinalEfficiency.SetBinContent(i,j,hInterpotEfficiency.GetBinContent(i,j));
	}
}
hFinalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_FinalEfficiency_0_2_EraC2.png").data())
hFinalEfficiency.SetNameTitle("h45_220_2017C2_all_2D","h45_220_2017C2_all_2D")
// Salva qui nel file per il pog
// outputFile->cd("Pixel/2017/2017C2")
// hFinalEfficiency->Write()
combinedPlotFile = new TFile((efficiencyFolder2017+"EraC2_combinedEfficiencyPlot.root").data(),"RECREATE")
combinedPlotFile->mkdir("Arm0_st2_rp3")
hFinalEfficiency.SetNameTitle("h2RefinedTrackEfficiency_arm0_st2_rp3","h2RefinedTrackEfficiency_arm0_st2_rp3")
combinedPlotFile->cd("Arm0_st2_rp3")
hFinalEfficiency.Write()
combinedPlotFile->Close()


hNormalEfficiency = TH2D(*((TH2D*)_refined2017EraC2->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hNormalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_1_2_EraC2.png").data())
hNormalEfficiency.SetNameTitle("h56_220_2017C2_all_2D","h56_220_2017C2_all_2D")
// Salva qui nel file per il pog
// outputFile->cd("Pixel/2017/2017C2")
// hNormalEfficiency->Write()

hInterpotEfficiency = TH2D(*((TH2D*)_inter2017EraC2->Get("Arm1_st2_rp3/h2InterPotEfficiencyMap_arm1_st2_rp3")))
hInterpotEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_InterpotEfficiency_1_2_EraC2.png").data())
hInterpotEfficiency.SetNameTitle("h56_220_2017C2_all_2D","h56_220_2017C2_all_2D")


hNormalEfficiency = TH2D(*((TH2D*)_refined2017EraD->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hNormalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_0_2_EraD.png").data())
hNormalEfficiency.SetNameTitle("h45_220_2017D_all_2D","h45_220_2017D_all_2D")

hInterpotEfficiency = TH2D(*((TH2D*)_inter2017EraD->Get("Arm0_st2_rp3/h2InterPotEfficiencyMap_arm0_st2_rp3")))
hInterpotEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_InterpotEfficiency_0_2_EraD.png").data())
hInterpotEfficiency.SetNameTitle("h45_220_2017D_all_2D","h45_220_2017D_all_2D")

hFinalEfficiency = TH2D(hNormalEfficiency)
for(auto i=0;i<hNormalEfficiency.GetNbinsX();i++){
	for(auto j=0;j<hNormalEfficiency.GetNbinsY();j++){
		if(i < 68 && j > 128) hFinalEfficiency.SetBinContent(i,j,hInterpotEfficiency.GetBinContent(i,j));
	}
}
hFinalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_FinalEfficiency_0_2_EraD.png").data())
hFinalEfficiency.SetNameTitle("h45_220_2017D_all_2D","h45_220_2017D_all_2D")
// Salva qui nel file per il pog
// outputFile->cd("Pixel/2017/2017D")
// hFinalEfficiency->Write()
combinedPlotFile = new TFile((efficiencyFolder2017+"EraD_combinedEfficiencyPlot.root").data(),"RECREATE")
combinedPlotFile->mkdir("Arm0_st2_rp3")
hFinalEfficiency.SetNameTitle("h2RefinedTrackEfficiency_arm0_st2_rp3","h2RefinedTrackEfficiency_arm0_st2_rp3")
combinedPlotFile->cd("Arm0_st2_rp3")
hFinalEfficiency.Write()
combinedPlotFile->Close()

hNormalEfficiency = TH2D(*((TH2D*)_refined2017EraD->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hNormalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_1_2_EraD.png").data())
hNormalEfficiency.SetNameTitle("h56_220_2017D_all_2D","h56_220_2017D_all_2D")
// Salva qui nel file per il pog
// outputFile->cd("Pixel/2017/2017D")
// hNormalEfficiency->Write()

hInterpotEfficiency = TH2D(*((TH2D*)_inter2017EraD->Get("Arm1_st2_rp3/h2InterPotEfficiencyMap_arm1_st2_rp3")))
hInterpotEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_InterpotEfficiency_1_2_EraD.png").data())
hInterpotEfficiency.SetNameTitle("h56_220_2017D_all_2D","h56_220_2017D_all_2D")


hNormalEfficiency = TH2D(*((TH2D*)_refined2017EraF2->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hNormalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_0_2_EraF2.png").data())
hNormalEfficiency.SetNameTitle("h45_220_2017F2_all_2D","h45_220_2017F2_all_2D")

hInterpotEfficiency = TH2D(*((TH2D*)_inter2017EraF2->Get("Arm0_st2_rp3/h2InterPotEfficiencyMap_arm0_st2_rp3")))
hInterpotEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_InterpotEfficiency_0_2_EraF2.png").data())
hInterpotEfficiency.SetNameTitle("h45_220_2017F2_all_2D","h45_220_2017F2_all_2D")

hFinalEfficiency = TH2D(hNormalEfficiency)
for(auto i=0;i<hNormalEfficiency.GetNbinsX();i++){
	for(auto j=0;j<hNormalEfficiency.GetNbinsY();j++){
		if(i < 68 && j > 133) hFinalEfficiency.SetBinContent(i,j,hInterpotEfficiency.GetBinContent(i,j));
	}
}
hFinalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_FinalEfficiency_0_2_EraF2.png").data())
hFinalEfficiency.SetNameTitle("h45_220_2017F2_all_2D","h45_220_2017F2_all_2D")
// Salva qui nel file per il pog
// outputFile->cd("Pixel/2017/2017F2")
// hFinalEfficiency->Write()
combinedPlotFile = new TFile((efficiencyFolder2017+"EraF2_combinedEfficiencyPlot.root").data(),"RECREATE")
combinedPlotFile->mkdir("Arm0_st2_rp3")
hFinalEfficiency.SetNameTitle("h2RefinedTrackEfficiency_arm0_st2_rp3","h2RefinedTrackEfficiency_arm0_st2_rp3")
combinedPlotFile->cd("Arm0_st2_rp3")
hFinalEfficiency.Write()
combinedPlotFile->Close()

hNormalEfficiency = TH2D(*((TH2D*)_refined2017EraF2->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hNormalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_1_2_EraF2.png").data())
hNormalEfficiency.SetNameTitle("h56_220_2017F2_all_2D","h56_220_2017F2_all_2D")
// Salva qui nel file per il pog
// outputFile->cd("Pixel/2017/2017F2")
// hNormalEfficiency->Write()

hInterpotEfficiency = TH2D(*((TH2D*)_inter2017EraF2->Get("Arm1_st2_rp3/h2InterPotEfficiencyMap_arm1_st2_rp3")))
hInterpotEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_InterpotEfficiency_1_2_EraF2.png").data())
hInterpotEfficiency.SetNameTitle("h56_220_2017F2_all_2D","h56_220_2017F2_all_2D")


hNormalEfficiency = TH2D(*((TH2D*)_refined2017EraF3->Get("Arm0_st2_rp3/h2RefinedTrackEfficiency_arm0_st2_rp3")))
hNormalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_0_2_EraF3.png").data())
hNormalEfficiency.SetNameTitle("h45_220_2017F3_all_2D","h45_220_2017F3_all_2D")

hInterpotEfficiency = TH2D(*((TH2D*)_inter2017EraF3->Get("Arm0_st2_rp3/h2InterPotEfficiencyMap_arm0_st2_rp3")))
hInterpotEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_InterpotEfficiency_0_2_EraF3.png").data())
hInterpotEfficiency.SetNameTitle("h45_220_2017F3_all_2D","h45_220_2017F3_all_2D")

hFinalEfficiency = TH2D(hNormalEfficiency)
for(auto i=0;i<hNormalEfficiency.GetNbinsX();i++){
	for(auto j=0;j<hNormalEfficiency.GetNbinsY();j++){
		if(i < 68 && j > 133) hFinalEfficiency.SetBinContent(i,j,hInterpotEfficiency.GetBinContent(i,j));
	}
}
hFinalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_FinalEfficiency_0_2_EraF3.png").data())
hFinalEfficiency.SetNameTitle("h45_220_2017F3_all_2D","h45_220_2017F3_all_2D")
// Salva qui nel file per il pog
// outputFile->cd("Pixel/2017/2017F3")
// hFinalEfficiency->Write()
combinedPlotFile = new TFile((efficiencyFolder2017+"EraF3_combinedEfficiencyPlot.root").data(),"RECREATE")
combinedPlotFile->mkdir("Arm0_st2_rp3")
hFinalEfficiency.SetNameTitle("h2RefinedTrackEfficiency_arm0_st2_rp3","h2RefinedTrackEfficiency_arm0_st2_rp3")
combinedPlotFile->cd("Arm0_st2_rp3")
hFinalEfficiency.Write()

hNormalEfficiency = TH2D(*((TH2D*)_refined2017EraF3->Get("Arm1_st2_rp3/h2RefinedTrackEfficiency_arm1_st2_rp3")))
hNormalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_RefinedEfficiency_1_2_EraF3.png").data())
hNormalEfficiency.SetNameTitle("h56_220_2017F3_all_2D","h56_220_2017F3_all_2D")

hInterpotEfficiency = TH2D(*((TH2D*)_inter2017EraF3->Get("Arm1_st2_rp3/h2InterPotEfficiencyMap_arm1_st2_rp3")))
hInterpotEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_InterpotEfficiency_1_2_EraF3.png").data())
hInterpotEfficiency.SetNameTitle("h56_220_2017F3_all_2D","h56_220_2017F3_all_2D")

hFinalEfficiency = TH2D(hNormalEfficiency)
for(auto i=0;i<hNormalEfficiency.GetNbinsX();i++){
	for(auto j=0;j<hNormalEfficiency.GetNbinsY();j++){
		if(i < 69 && j > 141) hFinalEfficiency.SetBinContent(i,j,hInterpotEfficiency.GetBinContent(i,j));
	}
}
hFinalEfficiency.Draw("colz")
setRange_st2_rectangular()
c.Print((outputFolderPng+"2017_FinalEfficiency_1_2_EraF3.png").data())
hFinalEfficiency.SetNameTitle("h56_220_2017F3_all_2D","h56_220_2017F3_all_2D")
// Salva qui nel file per il pog
// outputFile->cd("Pixel/2017/2017F3")
// hFinalEfficiency->Write()
combinedPlotFile->mkdir("Arm1_st2_rp3")
hFinalEfficiency.SetNameTitle("h2RefinedTrackEfficiency_arm1_st2_rp3","h2RefinedTrackEfficiency_arm1_st2_rp3")
combinedPlotFile->cd("Arm1_st2_rp3")
hFinalEfficiency.Write()
combinedPlotFile->Close()

// 2017 Efficiency vs. xi plots

hBegin = new TH1D(*((TH1D*)_xiCombined2017EraC2->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
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
c.Print((outputFolderPng+"2017_EffVsXi_0_2_EraC2.png").data())
hBegin->SetNameTitle("h45_220_2017C2_all_1D","h45_220_2017C2_all_1D")
// outputFile->cd("Pixel/2017/2017C2")
// hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraC2->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
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
c.Print((outputFolderPng+"2017_EffVsXi_1_2_EraC2.png").data())
hBegin->SetNameTitle("h56_220_2017C2_all_1D","h56_220_2017C2_all_1D")
// outputFile->cd("Pixel/2017/2017C2")
// hBegin->Write()


hBegin = new TH1D(*((TH1D*)_xiCombined2017EraD->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
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
c.Print((outputFolderPng+"2017_EffVsXi_0_2_EraD.png").data())
hBegin->SetNameTitle("h45_220_2017D_all_1D","h45_220_2017D_all_1D")
// outputFile->cd("Pixel/2017/2017D")
// hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraD->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
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
c.Print((outputFolderPng+"2017_EffVsXi_1_2_EraD.png").data())
hBegin->SetNameTitle("h56_220_2017D_all_1D","h56_220_2017D_all_1D")
// outputFile->cd("Pixel/2017/2017D")
// hBegin->Write()


hBegin = new TH1D(*((TH1D*)_xiCombined2017EraF2->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
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
c.Print((outputFolderPng+"2017_EffVsXi_0_2_EraF2.png").data())
hBegin->SetNameTitle("h45_220_2017F2_all_1D","h45_220_2017F2_all_1D")
// outputFile->cd("Pixel/2017/2017F2")
// hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xi2017EraF2->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
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
c.Print((outputFolderPng+"2017_EffVsXi_1_2_EraF2.png").data())
hBegin->SetNameTitle("h56_220_2017F2_all_1D","h56_220_2017F2_all_1D")
// outputFile->cd("Pixel/2017/2017F2")
// hBegin->Write()


hBegin = new TH1D(*((TH1D*)_xiCombined2017EraF3->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
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
c.Print((outputFolderPng+"2017_EffVsXi_0_2_EraF3.png").data())
hBegin->SetNameTitle("h45_220_2017F3_all_1D","h45_220_2017F3_all_1D")
// outputFile->cd("Pixel/2017/2017F3")
// hBegin->Write()

hBegin = new TH1D(*((TH1D*)_xiCombined2017EraF3->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
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
c.Print((outputFolderPng+"2017_EffVsXi_1_2_EraF3.png").data())
hBegin->SetNameTitle("h56_220_2017F3_all_1D","h56_220_2017F3_all_1D")
// outputFile->cd("Pixel/2017/2017F3")
// hBegin->Write()
