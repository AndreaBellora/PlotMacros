TFile *EraF3_interpot = TFile::Open("OutputFiles/EraF3_interpotEfficiency_Chi2OverNDF_simMultiRP.root")
TFile *EraF3_effVsXi_multiRP = TFile::Open("OutputFiles/EraF3_efficiencyVsXi_multiRP_simMultiRP.root")
TFile *EraF3_effVsXi_fromInter = TFile::Open("OutputFiles/EraF3_efficiencyVsXi_fromInterpot_simMultiRP.root")
TFile *EraF3_effVsXi_combinatory = TFile::Open("OutputFiles/EraF3_efficiencyVsXi_simMultiRP.root")
TFile *EraF3_effVsXi_newMultiRP = TFile::Open("OutputFiles/EraF3_efficiencyVsXi_fromInterpot_simMultiRP.root")
TFile *EraB_interpot = TFile::Open("OutputFiles/EraB_interpotEfficiency_Chi2OverNDF_simMultiRP.root")
TFile *EraB_effVsXi_multiRP = TFile::Open("OutputFiles/EraB_efficiencyVsXi_multiRP_simMultiRP.root")
TFile *EraB_effVsXi_fromInter = TFile::Open("OutputFiles/EraB_efficiencyVsXi_fromInterpot_simMultiRP.root")
TFile *EraB_effVsXi_combinatory = TFile::Open("OutputFiles/EraB_efficiencyVsXi_simMultiRP.root")
TFile *EraB_effVsXi_newMultiRP = TFile::Open("OutputFiles/EraB_efficiencyVsXi_fromInterpot_simMultiRP.root")
TFile *EraF2_interpot_TimingIn = TFile::Open("OutputFiles/EraF2_interpotEfficiency_Chi2OverNDF_TimingIn.root")
TFile *EraF2_effVsXi_multiRP_TimingIn = TFile::Open("OutputFiles/EraF2_efficiencyVsXi_multiRP_TimingIn.root")
TFile *EraF2_effVsXi_fromInter_TimingIn = TFile::Open("OutputFiles/EraF2_efficiencyVsXi_fromInterpot_TimingIn.root")
TFile *EraF2_interpot_TimingOut = TFile::Open("OutputFiles/EraF2_interpotEfficiency_Chi2OverNDF_TimingOut.root")
TFile *EraF2_effVsXi_multiRP_TimingOut = TFile::Open("OutputFiles/EraF2_efficiencyVsXi_multiRP_TimingOut.root")
TFile *EraF2_effVsXi_fromInter_TimingOut = TFile::Open("OutputFiles/EraF2_efficiencyVsXi_fromInterpot_TimingOut.root")
TFile *EraF2_effVsXi_combinatory_TimingOut = TFile::Open("OutputFiles/EraF2_efficiencyVsXi_TimingOut.root")


string outputFolderPng = "~/cernbox/PPS/PlotsForThreePlusThreeStudies/EraPlots/"

setRectangularPlots()
setTDRStyle()
TCanvas c
c.SetWindowSize(1430,1023)


// **************************************************Comparison plots vs xi**************************************************
c.SetGridy()

h1EffVsXi_multiRP = TH1D(*((TH1D*)EraF3_effVsXi_multiRP->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_fromInter = TH1D(*((TH1D*)EraF3_effVsXi_fromInter->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_combinatory = TH1D(*((TH1D*)EraF3_effVsXi_combinatory->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_multiRP.SetLineWidth(2)
h1EffVsXi_fromInter.SetLineWidth(2)
h1EffVsXi_combinatory.SetLineWidth(2)
h1EffVsXi_multiRP.SetLineColor(4)
h1EffVsXi_fromInter.SetLineColor(2)
h1EffVsXi_combinatory.SetLineColor(8)

for(int i = 1; i < h1EffVsXi_combinatory.GetNbinsX();i++) {
	if (h1EffVsXi_combinatory.GetBinContent(i) < 0.9) h1EffVsXi_combinatory.SetBinContent(i,0);
}

h1EffVsXi_multiRP.GetYaxis()->SetNdivisions(22,1,1)
h1EffVsXi_multiRP.Draw()
h1EffVsXi_fromInter.Draw("same")
h1EffVsXi_combinatory.Draw("same")

legend = new TLegend(0.65,0.45,0.9,0.6)
legend->SetFillStyle(0)
legend->SetBorderSize(0)
legend->AddEntry(&h1EffVsXi_multiRP,"Old multiRP","l")
legend->AddEntry(&h1EffVsXi_fromInter,"New multiRP","l")
legend->AddEntry(&h1EffVsXi_combinatory,"Combinatory","l")
legend->Draw()

c.Print((outputFolderPng+"45-220_EraF3_EffVsXiComparison.png").data())


h1EffVsXi_multiRP = TH1D(*((TH1D*)EraF3_effVsXi_multiRP->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_fromInter = TH1D(*((TH1D*)EraF3_effVsXi_fromInter->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_combinatory = TH1D(*((TH1D*)EraF3_effVsXi_combinatory->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_multiRP.SetLineWidth(2)
h1EffVsXi_fromInter.SetLineWidth(2)
h1EffVsXi_combinatory.SetLineWidth(2)
h1EffVsXi_multiRP.SetLineColor(4)
h1EffVsXi_fromInter.SetLineColor(2)
h1EffVsXi_combinatory.SetLineColor(8)

for(int i = 1; i < h1EffVsXi_combinatory.GetNbinsX();i++) {
	if (h1EffVsXi_combinatory.GetBinContent(i) < 0.9) h1EffVsXi_combinatory.SetBinContent(i,0);
}

h1EffVsXi_multiRP.GetYaxis()->SetNdivisions(22,1,1)
h1EffVsXi_multiRP.Draw()
h1EffVsXi_fromInter.Draw("same")
h1EffVsXi_combinatory.Draw("same")

legend = new TLegend(0.15,0.7,0.40,0.85)
legend->SetFillStyle(0)
legend->SetBorderSize(0)
legend->AddEntry(&h1EffVsXi_multiRP,"Old multiRP","l")
legend->AddEntry(&h1EffVsXi_fromInter,"New multiRP","l")
legend->AddEntry(&h1EffVsXi_combinatory,"Combinatory","l")
legend->Draw()

c.Print((outputFolderPng+"56-220_EraF3_EffVsXiComparison.png").data())


h1EffVsXi_multiRP = TH1D(*((TH1D*)EraB_effVsXi_multiRP->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_fromInter = TH1D(*((TH1D*)EraB_effVsXi_fromInter->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_combinatory = TH1D(*((TH1D*)EraB_effVsXi_combinatory->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_multiRP.SetLineWidth(2)
h1EffVsXi_fromInter.SetLineWidth(2)
h1EffVsXi_combinatory.SetLineWidth(2)
h1EffVsXi_multiRP.SetLineColor(4)
h1EffVsXi_fromInter.SetLineColor(2)
h1EffVsXi_combinatory.SetLineColor(8)

for(int i = 1; i < h1EffVsXi_combinatory.GetNbinsX();i++) {
	if (h1EffVsXi_combinatory.GetBinContent(i) < 0.9) h1EffVsXi_combinatory.SetBinContent(i,0);
}

h1EffVsXi_multiRP.GetYaxis()->SetNdivisions(22,1,1)
h1EffVsXi_multiRP.Draw()
h1EffVsXi_fromInter.Draw("same")
h1EffVsXi_combinatory.Draw("same")

legend = new TLegend(0.65,0.45,0.9,0.6)
legend->SetFillStyle(0)
legend->SetBorderSize(0)
legend->AddEntry(&h1EffVsXi_multiRP,"Old multiRP","l")
legend->AddEntry(&h1EffVsXi_fromInter,"New multiRP","l")
legend->AddEntry(&h1EffVsXi_combinatory,"Combinatory","l")
legend->Draw()

c.Print((outputFolderPng+"45-220_EraB_EffVsXiComparison.png").data())


h1EffVsXi_multiRP = TH1D(*((TH1D*)EraB_effVsXi_multiRP->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_fromInter = TH1D(*((TH1D*)EraB_effVsXi_fromInter->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_combinatory = TH1D(*((TH1D*)EraB_effVsXi_combinatory->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_multiRP.SetLineWidth(2)
h1EffVsXi_fromInter.SetLineWidth(2)
h1EffVsXi_combinatory.SetLineWidth(2)
h1EffVsXi_multiRP.SetLineColor(4)
h1EffVsXi_fromInter.SetLineColor(2)
h1EffVsXi_combinatory.SetLineColor(8)

for(int i = 1; i < h1EffVsXi_combinatory.GetNbinsX();i++) {
	if (h1EffVsXi_combinatory.GetBinContent(i) < 0.9) h1EffVsXi_combinatory.SetBinContent(i,0);
}

h1EffVsXi_multiRP.GetYaxis()->SetNdivisions(22,1,1)
h1EffVsXi_multiRP.Draw()
h1EffVsXi_fromInter.Draw("same")
h1EffVsXi_combinatory.Draw("same")

legend = new TLegend(0.15,0.15,0.40,0.30)
legend->SetFillStyle(0)
legend->SetBorderSize(0)
legend->AddEntry(&h1EffVsXi_multiRP,"Old multiRP","l")
legend->AddEntry(&h1EffVsXi_fromInter,"New multiRP","l")
legend->AddEntry(&h1EffVsXi_combinatory,"Combinatory","l")
legend->Draw()

c.Print((outputFolderPng+"56-220_EraB_EffVsXiComparison.png").data())


h1EffVsXi_multiRP_TimingOut = TH1D(*((TH1D*)EraF2_effVsXi_multiRP_TimingOut->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_fromInter_TimingOut = TH1D(*((TH1D*)EraF2_effVsXi_fromInter_TimingOut->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_combinatory_TimingOut = TH1D(*((TH1D*)EraF2_effVsXi_combinatory_TimingOut->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_multiRP_TimingOut.SetLineWidth(2)
h1EffVsXi_fromInter_TimingOut.SetLineWidth(2)
h1EffVsXi_combinatory_TimingOut.SetLineWidth(2)
h1EffVsXi_multiRP_TimingOut.SetLineColor(4)
h1EffVsXi_fromInter_TimingOut.SetLineColor(2)
h1EffVsXi_combinatory_TimingOut.SetLineColor(8)

h1EffVsXi_multiRP_TimingIn = TH1D(*((TH1D*)EraF2_effVsXi_multiRP_TimingIn->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_fromInter_TimingIn = TH1D(*((TH1D*)EraF2_effVsXi_fromInter_TimingIn->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
h1EffVsXi_multiRP_TimingIn.SetLineWidth(2)
h1EffVsXi_fromInter_TimingIn.SetLineWidth(2)
h1EffVsXi_multiRP_TimingIn.SetLineColor(4)
h1EffVsXi_fromInter_TimingIn.SetLineColor(2)
h1EffVsXi_multiRP_TimingIn.SetLineStyle(9)
h1EffVsXi_fromInter_TimingIn.SetLineStyle(9)

for(int i = 1; i < h1EffVsXi_combinatory_TimingOut.GetNbinsX();i++) {
	if (h1EffVsXi_combinatory_TimingOut.GetBinContent(i) < 0.9) h1EffVsXi_combinatory_TimingOut.SetBinContent(i,0);
}

h1EffVsXi_multiRP_TimingOut.GetYaxis()->SetNdivisions(22,1,1)
h1EffVsXi_multiRP_TimingOut.Draw("hist")
h1EffVsXi_fromInter_TimingOut.Draw("hist same")
h1EffVsXi_combinatory_TimingOut.Draw("hist same")
h1EffVsXi_fromInter_TimingIn.Draw("hist same")
h1EffVsXi_multiRP_TimingIn.Draw("hist same")

legend = new TLegend(0.12,0.74,0.37,0.89)
legend->SetFillStyle(0)
legend->SetBorderSize(0)
legend->AddEntry(&h1EffVsXi_multiRP_TimingOut,"Old multiRP","l")
legend->AddEntry(&h1EffVsXi_fromInter_TimingOut,"New multiRP","l")
legend->AddEntry(&h1EffVsXi_combinatory_TimingOut,"Combinatory","l")
legend->Draw()

c.Print((outputFolderPng+"45-220_EraF2_EffVsXiComparison_TimingInOut.png").data())

h1EffVsXi_multiRP_TimingOut = TH1D(*((TH1D*)EraF2_effVsXi_multiRP_TimingOut->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_fromInter_TimingOut = TH1D(*((TH1D*)EraF2_effVsXi_fromInter_TimingOut->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_combinatory_TimingOut = TH1D(*((TH1D*)EraF2_effVsXi_combinatory_TimingOut->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_multiRP_TimingOut.SetLineWidth(2)
h1EffVsXi_fromInter_TimingOut.SetLineWidth(2)
h1EffVsXi_combinatory_TimingOut.SetLineWidth(2)
h1EffVsXi_multiRP_TimingOut.SetLineColor(4)
h1EffVsXi_fromInter_TimingOut.SetLineColor(2)
h1EffVsXi_combinatory_TimingOut.SetLineColor(8)

h1EffVsXi_multiRP_TimingIn = TH1D(*((TH1D*)EraF2_effVsXi_multiRP_TimingIn->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_fromInter_TimingIn = TH1D(*((TH1D*)EraF2_effVsXi_fromInter_TimingIn->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
h1EffVsXi_multiRP_TimingIn.SetLineWidth(2)
h1EffVsXi_fromInter_TimingIn.SetLineWidth(2)
h1EffVsXi_multiRP_TimingIn.SetLineColor(4)
h1EffVsXi_fromInter_TimingIn.SetLineColor(2)
h1EffVsXi_multiRP_TimingIn.SetLineStyle(9)
h1EffVsXi_fromInter_TimingIn.SetLineStyle(9)

for(int i = 1; i < h1EffVsXi_combinatory_TimingOut.GetNbinsX();i++) {
	if (h1EffVsXi_combinatory_TimingOut.GetBinContent(i) < 0.9) h1EffVsXi_combinatory_TimingOut.SetBinContent(i,0);
}

h1EffVsXi_multiRP_TimingOut.GetYaxis()->SetNdivisions(22,1,1)
h1EffVsXi_multiRP_TimingOut.Draw("hist")
// h1EffVsXi_fromInter_TimingOut.Draw("hist same")
h1EffVsXi_combinatory_TimingOut.Draw("hist same")
h1EffVsXi_multiRP_TimingIn.Draw("hist same")
// h1EffVsXi_fromInter_TimingIn.Draw("hist same")

legend = new TLegend(0.2,0.15,0.45,0.30)
legend->SetFillStyle(0)
legend->SetBorderSize(0)
legend->AddEntry(&h1EffVsXi_multiRP_TimingOut,"Old multiRP (same as new for non-3+3)","l")
// legend->AddEntry(&h1EffVsXi_fromInter_TimingOut,"New multiRP","l")
legend->AddEntry(&h1EffVsXi_combinatory_TimingOut,"Combinatory","l")
legend->Draw()

c.Print((outputFolderPng+"56-220_EraF2_EffVsXiComparison_TimingInOut.png").data())

