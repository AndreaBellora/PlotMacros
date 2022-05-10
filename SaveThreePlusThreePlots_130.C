// Plots to be saved:
// - TrackMux 				-> Done
// - RecoInfo 				-> Done
// - Xi 					-> Done
// - DeltaXiMatch 			-> Done
// - DeltaYMatch 			-> Done
// - Interpot efficiencies 	-> Done
// - Matching rates			-> Done

// ***********************************Preparation*************************************

setRectangularPlots()
setTDRStyle()
TCanvas c
c.SetWindowSize(1430,1023)
string path = "~/cernbox/PPS/Meetings/DPG_2020_03_09/"

TFile *_file1 = TFile::Open("Run297057_130_interpotEfficiency_oneTrackInPixels.root")
TFile *_file4 = TFile::Open("Run297057_130_interpotEfficiency.root")
TFile *_file7 = TFile::Open("Run305081_130_interpotEfficiency_oneTrackInPixels.root")
TFile *_file9 = TFile::Open("Run305081_130_interpotEfficiency.root")
TFile *_file11 = TFile::Open("Run306135_130_interpotEfficiency_allShiftedPlanes_oneTrackInPixels.root")
TFile *_file12 = TFile::Open("Run306135_130_interpotEfficiency_allShiftedPlanes.root")
TFile *_file13 = TFile::Open("Run306135_130_interpotEfficiency_mixedPlanes_oneTrackInPixels.root")
TFile *_file14 = TFile::Open("Run306135_130_interpotEfficiency_mixedPlanes.root")
TFile *_file15 = TFile::Open("Run306135_130_interpotEfficiency_noShiftedPlanes_noLowLimitForEff.root")
TFile *_file16 = TFile::Open("Run306135_130_interpotEfficiency_noShiftedPlanes_oneTrackInPixels.root")
TFile *_file17 = TFile::Open("Run306135_130_interpotEfficiency_noShiftedPlanes.root")
TFile *_file19 = TFile::Open("Run306135_130_interpotEfficiency_oneTrackInPixels.root")
TFile *_file20 = TFile::Open("Run306135_130_interpotEfficiency.root")

// ***********************************************************************************

// ***********************************Save Xi Plots***********************************
setTDRStyle()

TH1D histNormal = TH1D(*((TH1D*)_file9->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
TH1D histThreePlusThree = TH1D(*((TH1D*)_file20->Get("Arm0_st2_rp3/h1Xi_arm0_st2_rp3")))
TH1D* hNormal = new TH1D(histNormal)
TH1D* hThreePlusThree = new TH1D(histThreePlusThree)

hNormal->SetLineWidth(1)
hThreePlusThree->SetLineWidth(1)

hNormal->SetLineColor(kBlack)
hThreePlusThree->SetLineColor(kBlack)

hNormal->SetFillStyle(3001)
hThreePlusThree->SetFillStyle(3001)

hNormal->SetFillColor(38)
hThreePlusThree->SetFillColor(46)

hThreePlusThree->Draw()
hNormal->Draw("same")

auto legend_0_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_0_2->SetMargin(0.2)
legend_0_2->AddEntry(hNormal,"Run305081","fl")
legend_0_2->AddEntry(hThreePlusThree,"Run306135","fl")
legend_0_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"Xi_0_2_Run306135_Run305081_ThreePlusThreeVsNormal_130.png").c_str())

histNormal = TH1D(*((TH1D*)_file9->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file20->Get("Arm1_st2_rp3/h1Xi_arm1_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)

hNormal->SetLineWidth(1)
hThreePlusThree->SetLineWidth(1)

hNormal->SetLineColor(kBlack)
hThreePlusThree->SetLineColor(kBlack)

hNormal->SetFillStyle(3001)
hThreePlusThree->SetFillStyle(3001)

hNormal->SetFillColor(38)
hThreePlusThree->SetFillColor(46)

hThreePlusThree->Draw()
hNormal->Draw("same")

auto legend_1_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_1_2->SetMargin(0.2)
legend_1_2->AddEntry(hNormal,"Run305081","fl")
legend_1_2->AddEntry(hThreePlusThree,"Run306135","fl")
legend_1_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"Xi_1_2_Run306135_Run305081_ThreePlusThreeVsNormal_130.png").c_str())

// ***********************************************************************************

// ************************Save Xi Plots With Matching Strips*************************
setTDRStyle()

histNormal = TH1D(*((TH1D*)_file7->Get("Arm0_st2_rp3/h1XiWhenPurityMatch_arm0_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file19->Get("Arm0_st2_rp3/h1XiWhenPurityMatch_arm0_st2_rp3")))
histThreePlusThree_allShifted = TH1D(*((TH1D*)_file11->Get("Arm0_st2_rp3/h1XiWhenPurityMatch_arm0_st2_rp3")))
histThreePlusThree_noShifted = TH1D(*((TH1D*)_file16->Get("Arm0_st2_rp3/h1XiWhenPurityMatch_arm0_st2_rp3")))
histThreePlusThree_mixed = TH1D(*((TH1D*)_file13->Get("Arm0_st2_rp3/h1XiWhenPurityMatch_arm0_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hThreePlusThree_allShifted = new TH1D(histThreePlusThree_allShifted)
hThreePlusThree_noShifted = new TH1D(histThreePlusThree_noShifted)
hThreePlusThree_mixed = new TH1D(histThreePlusThree_mixed)

hNormal->SetLineWidth(1)
hThreePlusThree->SetLineWidth(1)
hThreePlusThree_allShifted->SetLineWidth(1)
hThreePlusThree_noShifted->SetLineWidth(1)
hThreePlusThree_mixed->SetLineWidth(1)

hNormal->SetLineColor(kBlack)
hThreePlusThree->SetLineColor(kBlack)
hThreePlusThree_allShifted->SetLineColor(kBlack)
hThreePlusThree_noShifted->SetLineColor(kBlack)
hThreePlusThree_mixed->SetLineColor(kBlack)

hNormal->SetFillStyle(3001)
hThreePlusThree->SetFillStyle(3001)
hThreePlusThree_allShifted->SetFillStyle(3001)
hThreePlusThree_noShifted->SetFillStyle(3001)
hThreePlusThree_mixed->SetFillStyle(3001)

hNormal->SetFillColor(38)
hThreePlusThree->SetFillColor(46)
hThreePlusThree_allShifted->SetFillColor(34)
hThreePlusThree_noShifted->SetFillColor(41)
hThreePlusThree_mixed->SetFillColor(30)

hNormal->Draw()
hThreePlusThree->Draw("same")
hThreePlusThree_noShifted->Draw("same")
hThreePlusThree_mixed->Draw("same")
hThreePlusThree_allShifted->Draw("same")

legend_0_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_0_2->SetMargin(0.2)
legend_0_2->AddEntry(hNormal,"Run305081","lf")
legend_0_2->AddEntry(hThreePlusThree,"Run306135","lf")
legend_0_2->AddEntry(hThreePlusThree_noShifted,"Run306135 - noShifted","lf")
legend_0_2->AddEntry(hThreePlusThree_mixed,"Run306135 - mixed","lf")
legend_0_2->AddEntry(hThreePlusThree_allShifted,"Run306135 - allShifted","lf")
legend_0_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"XiWhenPurityMatch_0_2_Run306135_Run305081_ThreePlusThreeVsNormal_130.png").c_str())

histNormal = TH1D(*((TH1D*)_file7->Get("Arm1_st2_rp3/h1XiWhenPurityMatch_arm1_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file19->Get("Arm1_st2_rp3/h1XiWhenPurityMatch_arm1_st2_rp3")))
histThreePlusThree_allShifted = TH1D(*((TH1D*)_file11->Get("Arm1_st2_rp3/h1XiWhenPurityMatch_arm1_st2_rp3")))
histThreePlusThree_noShifted = TH1D(*((TH1D*)_file16->Get("Arm1_st2_rp3/h1XiWhenPurityMatch_arm1_st2_rp3")))
histThreePlusThree_mixed = TH1D(*((TH1D*)_file13->Get("Arm1_st2_rp3/h1XiWhenPurityMatch_arm1_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hThreePlusThree_allShifted = new TH1D(histThreePlusThree_allShifted)
hThreePlusThree_noShifted = new TH1D(histThreePlusThree_noShifted)
hThreePlusThree_mixed = new TH1D(histThreePlusThree_mixed)

hNormal->SetLineWidth(1)
hThreePlusThree->SetLineWidth(1)
hThreePlusThree_allShifted->SetLineWidth(1)
hThreePlusThree_noShifted->SetLineWidth(1)
hThreePlusThree_mixed->SetLineWidth(1)

hNormal->SetLineColor(kBlack)
hThreePlusThree->SetLineColor(kBlack)
hThreePlusThree_allShifted->SetLineColor(kBlack)
hThreePlusThree_noShifted->SetLineColor(kBlack)
hThreePlusThree_mixed->SetLineColor(kBlack)

hNormal->SetFillStyle(3001)
hThreePlusThree->SetFillStyle(3001)
hThreePlusThree_allShifted->SetFillStyle(3001)
hThreePlusThree_noShifted->SetFillStyle(3001)
hThreePlusThree_mixed->SetFillStyle(3001)

hNormal->SetFillColor(38)
hThreePlusThree->SetFillColor(46)
hThreePlusThree_allShifted->SetFillColor(34)
hThreePlusThree_noShifted->SetFillColor(41)
hThreePlusThree_mixed->SetFillColor(30)

hNormal->Draw()
hThreePlusThree->Draw("same")
hThreePlusThree_noShifted->Draw("same")
hThreePlusThree_mixed->Draw("same")
hThreePlusThree_allShifted->Draw("same")

legend_1_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_1_2->SetMargin(0.2)
legend_1_2->AddEntry(hNormal,"Run305081","lf")
legend_1_2->AddEntry(hThreePlusThree,"Run306135","lf")
legend_1_2->AddEntry(hThreePlusThree_noShifted,"Run306135 - noShifted","lf")
legend_1_2->AddEntry(hThreePlusThree_mixed,"Run306135 - mixed","lf")
legend_1_2->AddEntry(hThreePlusThree_allShifted,"Run306135 - allShifted","lf")
legend_1_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"XiWhenPurityMatch_1_2_Run306135_Run305081_ThreePlusThreeVsNormal_130.png").c_str())

// ***********************************************************************************

// ***************************Save Track Multiplicity Plots***************************

// NoShifted
histNormal = TH1D(*((TH1D*)_file9->Get("Arm0_st2_rp3/h1PixelTrackMux_arm0_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file20->Get("Arm0_st2_rp3/h1PixelTrackMux_arm0_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hNormal->SetLineColor(kBlue)
hNormal->SetMarkerColor(kBlue)
hNormal->SetMarkerStyle(kFullSquare)
hNormal->Draw("hist")
hNormal->SetTitle("Run305081")

hThreePlusThree->SetLineColor(kRed)
hThreePlusThree->SetMarkerColor(kRed)
hThreePlusThree->SetMarkerStyle(kFullTriangleUp)
hThreePlusThree->SetMarkerSize(1.3)
hThreePlusThree->Draw("hist same")
hThreePlusThree->SetTitle("Run306135")

hNormal->SetLineWidth(2)
hThreePlusThree->SetLineWidth(2)

legend_0_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_0_2->SetMargin(0.2)
legend_0_2->AddEntry(hNormal,"Run305081","l")
legend_0_2->AddEntry(hThreePlusThree,"Run306135","l")
legend_0_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"PixelTrackMux_0_2_Run306135_Run305081_ThreePlusThreeVsNormal_130.png").c_str())

histNormal = TH1D(*((TH1D*)_file9->Get("Arm1_st2_rp3/h1PixelTrackMux_arm1_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file20->Get("Arm1_st2_rp3/h1PixelTrackMux_arm1_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hNormal->SetLineColor(kBlue)
hNormal->SetMarkerColor(kBlue)
hNormal->SetMarkerStyle(kFullSquare)
hNormal->Draw("hist")
hNormal->SetTitle("Run305081")

hThreePlusThree->SetLineColor(kRed)
hThreePlusThree->SetMarkerColor(kRed)
hThreePlusThree->SetMarkerStyle(kFullTriangleUp)
hThreePlusThree->SetMarkerSize(1.3)
hThreePlusThree->Draw("hist same")
hThreePlusThree->SetTitle("Run306135")

hNormal->SetLineWidth(2)
hThreePlusThree->SetLineWidth(2)

legend_1_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_1_2->SetMargin(0.2)
legend_1_2->AddEntry(hNormal,"Run305081","l")
legend_1_2->AddEntry(hThreePlusThree,"Run306135","l")
legend_1_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"PixelTrackMux_1_2_Run306135_Run305081_ThreePlusThreeVsNormal_130.png").c_str())

// ***********************************************************************************

// *****************************Save Matching Rate vs. Xi*****************************

histNormal = TH1D(*((TH1D*)_file7->Get("Arm0_st2_rp3/h1MatchingRate_arm0_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file16->Get("Arm0_st2_rp3/h1MatchingRate_arm0_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hNormal->SetLineColor(kBlue)
hNormal->SetMarkerColor(kBlue)
hNormal->SetMarkerStyle(kFullSquare)
hNormal->Draw("hist")
hNormal->SetTitle("Run305081")

hThreePlusThree->SetLineColor(kRed)
hThreePlusThree->SetMarkerColor(kRed)
hThreePlusThree->SetMarkerStyle(kFullTriangleUp)
hThreePlusThree->SetMarkerSize(1.3)
hThreePlusThree->Draw("hist same")
hThreePlusThree->SetTitle("Run306135")

hNormal->SetLineWidth(2)
hThreePlusThree->SetLineWidth(2)

legend_0_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_0_2->SetMargin(0.2)
legend_0_2->AddEntry(hNormal,"Run305081","l")
legend_0_2->AddEntry(hThreePlusThree,"Run306135","l")
legend_0_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"MatchingRateVsXi_0_2_Run306135_Run305081_ThreePlusThreeVsNormal_noShifted_130.png").c_str())

histNormal = TH1D(*((TH1D*)_file7->Get("Arm1_st2_rp3/h1MatchingRate_arm1_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file16->Get("Arm1_st2_rp3/h1MatchingRate_arm1_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hNormal->SetLineColor(kBlue)
hNormal->SetMarkerColor(kBlue)
hNormal->SetMarkerStyle(kFullSquare)
hNormal->Draw("hist")
hNormal->SetTitle("Run305081")

hThreePlusThree->SetLineColor(kRed)
hThreePlusThree->SetMarkerColor(kRed)
hThreePlusThree->SetMarkerStyle(kFullTriangleUp)
hThreePlusThree->SetMarkerSize(1.3)
hThreePlusThree->Draw("hist same")
hThreePlusThree->SetTitle("Run306135")

hNormal->SetLineWidth(2)
hThreePlusThree->SetLineWidth(2)

legend_1_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_1_2->SetMargin(0.2)
legend_1_2->AddEntry(hNormal,"Run305081","l")
legend_1_2->AddEntry(hThreePlusThree,"Run306135","l")
legend_1_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"MatchingRateVsXi_1_2_Run306135_Run305081_ThreePlusThreeVsNormal_noShifted_130.png").c_str())

// AllShifted
histNormal = TH1D(*((TH1D*)_file7->Get("Arm0_st2_rp3/h1MatchingRate_arm0_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file11->Get("Arm0_st2_rp3/h1MatchingRate_arm0_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hNormal->SetLineColor(kBlue)
hNormal->SetMarkerColor(kBlue)
hNormal->SetMarkerStyle(kFullSquare)
hNormal->Draw("hist")
hNormal->SetTitle("Run305081")

hThreePlusThree->SetLineColor(kRed)
hThreePlusThree->SetMarkerColor(kRed)
hThreePlusThree->SetMarkerStyle(kFullTriangleUp)
hThreePlusThree->SetMarkerSize(1.3)
hThreePlusThree->Draw("hist same")
hThreePlusThree->SetTitle("Run306135")

hNormal->SetLineWidth(2)
hThreePlusThree->SetLineWidth(2)

legend_0_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_0_2->SetMargin(0.2)
legend_0_2->AddEntry(hNormal,"Run305081","l")
legend_0_2->AddEntry(hThreePlusThree,"Run306135","l")
legend_0_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"MatchingRateVsXi_0_2_Run306135_Run305081_ThreePlusThreeVsNormal_allShifted_130.png").c_str())

histNormal = TH1D(*((TH1D*)_file7->Get("Arm1_st2_rp3/h1MatchingRate_arm1_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file11->Get("Arm1_st2_rp3/h1MatchingRate_arm1_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hNormal->SetLineColor(kBlue)
hNormal->SetMarkerColor(kBlue)
hNormal->SetMarkerStyle(kFullSquare)
hNormal->Draw("hist")
hNormal->SetTitle("Run305081")

hThreePlusThree->SetLineColor(kRed)
hThreePlusThree->SetMarkerColor(kRed)
hThreePlusThree->SetMarkerStyle(kFullTriangleUp)
hThreePlusThree->SetMarkerSize(1.3)
hThreePlusThree->Draw("hist same")
hThreePlusThree->SetTitle("Run306135")

hNormal->SetLineWidth(2)
hThreePlusThree->SetLineWidth(2)

legend_1_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_1_2->SetMargin(0.2)
legend_1_2->AddEntry(hNormal,"Run305081","l")
legend_1_2->AddEntry(hThreePlusThree,"Run306135","l")
legend_1_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"MatchingRateVsXi_1_2_Run306135_Run305081_ThreePlusThreeVsNormal_allShifted_130.png").c_str())

// Mixed
histNormal = TH1D(*((TH1D*)_file7->Get("Arm0_st2_rp3/h1MatchingRate_arm0_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file13->Get("Arm0_st2_rp3/h1MatchingRate_arm0_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hNormal->SetLineColor(kBlue)
hNormal->SetMarkerColor(kBlue)
hNormal->SetMarkerStyle(kFullSquare)
hNormal->Draw("hist")
hNormal->SetTitle("Run305081")

hThreePlusThree->SetLineColor(kRed)
hThreePlusThree->SetMarkerColor(kRed)
hThreePlusThree->SetMarkerStyle(kFullTriangleUp)
hThreePlusThree->SetMarkerSize(1.3)
hThreePlusThree->Draw("hist same")
hThreePlusThree->SetTitle("Run306135")

hNormal->SetLineWidth(2)
hThreePlusThree->SetLineWidth(2)

legend_0_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_0_2->SetMargin(0.2)
legend_0_2->AddEntry(hNormal,"Run305081","l")
legend_0_2->AddEntry(hThreePlusThree,"Run306135","l")
legend_0_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"MatchingRateVsXi_0_2_Run306135_Run305081_ThreePlusThreeVsNormal_mixed_130.png").c_str())

histNormal = TH1D(*((TH1D*)_file7->Get("Arm1_st2_rp3/h1MatchingRate_arm1_st2_rp3")))
histThreePlusThree = TH1D(*((TH1D*)_file13->Get("Arm1_st2_rp3/h1MatchingRate_arm1_st2_rp3")))
hNormal = new TH1D(histNormal)
hThreePlusThree = new TH1D(histThreePlusThree)
hNormal->SetLineColor(kBlue)
hNormal->SetMarkerColor(kBlue)
hNormal->SetMarkerStyle(kFullSquare)
hNormal->Draw("hist")
hNormal->SetTitle("Run305081")

hThreePlusThree->SetLineColor(kRed)
hThreePlusThree->SetMarkerColor(kRed)
hThreePlusThree->SetMarkerStyle(kFullTriangleUp)
hThreePlusThree->SetMarkerSize(1.3)
hThreePlusThree->Draw("hist same")
hThreePlusThree->SetTitle("Run306135")

hNormal->SetLineWidth(2)
hThreePlusThree->SetLineWidth(2)

legend_1_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_1_2->SetMargin(0.2)
legend_1_2->AddEntry(hNormal,"Run305081","l")
legend_1_2->AddEntry(hThreePlusThree,"Run306135","l")
legend_1_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"MatchingRateVsXi_1_2_Run306135_Run305081_ThreePlusThreeVsNormal_mixed_130.png").c_str())

// ***********************************************************************************

// *****************************Save Interpot Efficiency******************************

// NoShiftedPlanes
_file17->cd()
gDirectory->cd("Arm0_st2_rp3")
h2InterPotEfficiencyMap_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"InterpotEfficiency_0_2_Run306135_oneTrackInPixels_noShiftedPlanes_130.png").c_str())

_file17->cd()
gDirectory->cd("Arm1_st2_rp3")
h2InterPotEfficiencyMap_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"InterpotEfficiency_1_2_Run306135_oneTrackInPixels_noShiftedPlanes_130.png").c_str())

// allShiftedPlanes
_file11->cd()
gDirectory->cd("Arm0_st2_rp3")
h2InterPotEfficiencyMap_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"InterpotEfficiency_0_2_Run306135_oneTrackInPixels_allShiftedPlanes_130.png").c_str())

_file11->cd()
gDirectory->cd("Arm1_st2_rp3")
h2InterPotEfficiencyMap_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"InterpotEfficiency_1_2_Run306135_oneTrackInPixels_allShiftedPlanes_130.png").c_str())

// mixedPlanes
_file13->cd()
gDirectory->cd("Arm0_st2_rp3")
h2InterPotEfficiencyMap_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"InterpotEfficiency_0_2_Run306135_oneTrackInPixels_mixedPlanes_130.png").c_str())

_file13->cd()
gDirectory->cd("Arm1_st2_rp3")
h2InterPotEfficiencyMap_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"InterpotEfficiency_1_2_Run306135_oneTrackInPixels_mixedPlanes_130.png").c_str())

// Irradiated, but not Run306135
_file7->cd()
gDirectory->cd("Arm0_st2_rp3")
h2InterPotEfficiencyMap_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"InterpotEfficiency_0_2_Run305081_oneTrackInPixels_130.png").c_str())

_file9->cd()
gDirectory->cd("Arm0_st2_rp3")
h2InterPotEfficiencyMap_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"InterpotEfficiency_0_2_Run305081_130.png").c_str())

_file7->cd()
gDirectory->cd("Arm1_st2_rp3")
h2InterPotEfficiencyMap_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"InterpotEfficiency_1_2_Run305081_oneTrackInPixels_130.png").c_str())

// Beginning of data taking
_file1->cd()
gDirectory->cd("Arm0_st2_rp3")
h2InterPotEfficiencyMap_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"InterpotEfficiency_0_2_Run297050_oneTrackInPixels_130.png").c_str())

_file1->cd()
gDirectory->cd("Arm1_st2_rp3")
h2InterPotEfficiencyMap_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"InterpotEfficiency_1_2_Run297050_oneTrackInPixels_130.png").c_str())

// ***********************************************************************************

// ********************************Save recoInfo Plots********************************
// gStyle->SetOptStat(1110)

// RecoInfo in Run306135 run
TH1D histAll = TH1D(*((TH1D*)_file19->Get("Arm0_st2_rp3/h1RecoInfo_arm0_st2_rp3")))
TH1D histMatching = TH1D(*((TH1D*)_file19->Get("Arm0_st2_rp3/h1RecoInfoWithPurityMatch_arm0_st2_rp3")))
TH1D* hAll = new TH1D(histAll)
TH1D* hMatching = new TH1D(histMatching)
hAll->GetXaxis()->SetBinLabel(1,"notShiftedROC")
hAll->GetXaxis()->SetBinLabel(2,"allShifted")
hAll->GetXaxis()->SetBinLabel(3,"noShifted")
hAll->GetXaxis()->SetBinLabel(4,"mixed")
hMatching->SetLineColor(kRed)

hAll->SetLineWidth(2)
hMatching->SetLineWidth(2)

hAll->Draw()
hMatching->Draw("same")

legend_0_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_0_2->SetMargin(0.2)
legend_0_2->AddEntry(hAll,"All events","l")
legend_0_2->AddEntry(hMatching,"Events matching strips track","l")
legend_0_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"RecoInfo_0_2_Run306135_withPurityMatch_130.png").c_str())

histAll = TH1D(*((TH1D*)_file19->Get("Arm1_st2_rp3/h1RecoInfo_arm1_st2_rp3")))
histMatching = TH1D(*((TH1D*)_file19->Get("Arm1_st2_rp3/h1RecoInfoWithPurityMatch_arm1_st2_rp3")))
hAll = new TH1D(histAll)
hMatching = new TH1D(histMatching)
hAll->GetXaxis()->SetBinLabel(1,"notShiftedROC")
hAll->GetXaxis()->SetBinLabel(2,"allShifted")
hAll->GetXaxis()->SetBinLabel(3,"noShifted")
hAll->GetXaxis()->SetBinLabel(4,"mixed")
hMatching->SetLineColor(kRed)

hAll->SetLineWidth(2)
hMatching->SetLineWidth(2)

hAll->Draw()
hMatching->Draw("same")

legend_1_2 = new TLegend(0.65,0.75,0.9,0.9)
legend_1_2->SetMargin(0.2)
legend_1_2->AddEntry(hAll,"All events","l")
legend_1_2->AddEntry(hMatching,"Events matching strips track","l")
legend_1_2->Draw()

CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"RecoInfo_1_2_Run306135_withPurityMatch_130.png").c_str())

// ***********************************************************************************



// ******************************Save DeltaXiMatch Plots******************************
gStyle->SetOptStat(1110)

_file9->cd()
gDirectory->cd("Arm0_st2_rp3")
h1DeltaXiMatch_arm0_st2_rp3->Draw()
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"DeltaXiMatch_0_2_Run305081_130.png").c_str())

_file9->cd()
gDirectory->cd("Arm1_st2_rp3")
h1DeltaXiMatch_arm1_st2_rp3->Draw()
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"DeltaXiMatch_1_2_Run305081_130.png").c_str())

_file20->cd()
gDirectory->cd("Arm0_st2_rp3")
h1DeltaXiMatch_arm0_st2_rp3->Draw()
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"DeltaXiMatch_0_2_Run306135_130.png").c_str())

_file20->cd()
gDirectory->cd("Arm1_st2_rp3")
h1DeltaXiMatch_arm1_st2_rp3->Draw()
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"DeltaXiMatch_1_2_Run306135_130.png").c_str())

// ***********************************************************************************

// ******************************Save DeltaYMatch Plots*******************************

_file9->cd()
gDirectory->cd("Arm0_st2_rp3")
h1DeltaYMatch_arm0_st2_rp3->Draw()
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"DeltaYMatch_0_2_Run305081_130.png").c_str())

_file9->cd()
gDirectory->cd("Arm1_st2_rp3")
h1DeltaYMatch_arm1_st2_rp3->Draw()
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"DeltaYMatch_1_2_Run305081_130.png").c_str())

_file20->cd()
gDirectory->cd("Arm0_st2_rp3")
h1DeltaYMatch_arm0_st2_rp3->Draw()
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"DeltaYMatch_0_2_Run306135_130.png").c_str())

_file20->cd()
gDirectory->cd("Arm1_st2_rp3")
h1DeltaYMatch_arm1_st2_rp3->Draw()
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"DeltaYMatch_1_2_Run306135_130.png").c_str())

// ***********************************************************************************

// ******************************Save Matching Rate Maps******************************
setTDRStyle()

// NoShiftedPlanes
_file16->cd()
gDirectory->cd("Arm0_st2_rp3")
h2MatchingRate_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"MatchingRate_0_2_Run306135_oneTrackInPixels_noShiftedPlanes_130.png").c_str())

_file16->cd()
gDirectory->cd("Arm1_st2_rp3")
h2MatchingRate_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"MatchingRate_1_2_Run306135_oneTrackInPixels_noShiftedPlanes_130.png").c_str())

// allShiftedPlanes
_file11->cd()
gDirectory->cd("Arm0_st2_rp3")
h2MatchingRate_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"MatchingRate_0_2_Run306135_oneTrackInPixels_allShiftedPlanes_130.png").c_str())

_file11->cd()
gDirectory->cd("Arm1_st2_rp3")
h2MatchingRate_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"MatchingRate_1_2_Run306135_oneTrackInPixels_allShiftedPlanes_130.png").c_str())

// mixedPlanes
_file13->cd()
gDirectory->cd("Arm0_st2_rp3")
h2MatchingRate_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"MatchingRate_0_2_Run306135_oneTrackInPixels_mixedPlanes_130.png").c_str())

_file13->cd()
gDirectory->cd("Arm1_st2_rp3")
h2MatchingRate_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"MatchingRate_1_2_Run306135_oneTrackInPixels_mixedPlanes_130.png").c_str())

// Irradiated, but not Run306135
_file7->cd()
gDirectory->cd("Arm0_st2_rp3")
h2MatchingRate_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"MatchingRate_0_2_Run305081_oneTrackInPixels_130.png").c_str())

_file7->cd()
gDirectory->cd("Arm1_st2_rp3")
h2MatchingRate_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"MatchingRate_1_2_Run305081_oneTrackInPixels_130.png").c_str())

// Beginning of data taking
_file1->cd()
gDirectory->cd("Arm0_st2_rp3")
h2MatchingRate_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"MatchingRate_0_2_Run297050_oneTrackInPixels_130.png").c_str())

_file1->cd()
gDirectory->cd("Arm1_st2_rp3")
h2MatchingRate_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"MatchingRate_1_2_Run297050_oneTrackInPixels_130.png").c_str())

_file4->cd()
gDirectory->cd("Arm0_st2_rp3")
h2MatchingRate_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"MatchingRate_0_2_Run297050_130.png").c_str())

// ***********************************************************************************

// *****************************Save Proton Distributions*****************************

// NoShiftedPlanes
_file16->cd()
gDirectory->cd("Arm0_st2_rp3")
h2ProtonDistributionWithStrips_arm0_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_0_2_Run306135_oneTrackInPixels_noShiftedPlanes_130.png").c_str())

_file16->cd()
gDirectory->cd("Arm1_st2_rp3")
h2ProtonDistributionWithStrips_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_1_2_Run306135_oneTrackInPixels_noShiftedPlanes_130.png").c_str())

_file16->cd()
gDirectory->cd("Arm0_st2_rp3")
h2ProtonDistributionWithNoPurityMatch_arm0_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"ProtonDistributionWithNoPurityMatch_0_2_Run306135_oneTrackInPixels_noShiftedPlanes_130.png").c_str())

_file16->cd()
gDirectory->cd("Arm1_st2_rp3")
h2ProtonDistributionWithNoPurityMatch_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"ProtonDistributionWithNoPurityMatch_1_2_Run306135_oneTrackInPixels_noShiftedPlanes_130.png").c_str())

// allShiftedPlanes
_file11->cd()
gDirectory->cd("Arm0_st2_rp3")
h2ProtonDistributionWithStrips_arm0_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_0_2_Run306135_oneTrackInPixels_allShiftedPlanes_130.png").c_str())

_file11->cd()
gDirectory->cd("Arm1_st2_rp3")
h2ProtonDistributionWithStrips_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_1_2_Run306135_oneTrackInPixels_allShiftedPlanes_130.png").c_str())

_file11->cd()
gDirectory->cd("Arm0_st2_rp3")
h2ProtonDistributionWithNoPurityMatch_arm0_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"ProtonDistributionWithNoPurityMatch_0_2_Run306135_oneTrackInPixels_allShiftedPlanes_130.png").c_str())

_file11->cd()
gDirectory->cd("Arm1_st2_rp3")
h2ProtonDistributionWithNoPurityMatch_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"ProtonDistributionWithNoPurityMatch_1_2_Run306135_oneTrackInPixels_allShiftedPlanes_130.png").c_str())

// mixedPlanes
_file13->cd()
gDirectory->cd("Arm0_st2_rp3")
h2ProtonDistributionWithStrips_arm0_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_0_2_Run306135_oneTrackInPixels_mixedPlanes_130.png").c_str())

_file13->cd()
gDirectory->cd("Arm1_st2_rp3")
h2ProtonDistributionWithStrips_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_1_2_Run306135_oneTrackInPixels_mixedPlanes_130.png").c_str())

_file13->cd()
gDirectory->cd("Arm0_st2_rp3")
h2ProtonDistributionWithNoPurityMatch_arm0_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"ProtonDistributionWithNoPurityMatch_0_2_Run306135_oneTrackInPixels_mixedPlanes_130.png").c_str())

_file13->cd()
gDirectory->cd("Arm1_st2_rp3")
h2ProtonDistributionWithNoPurityMatch_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"ProtonDistributionWithNoPurityMatch_1_2_Run306135_oneTrackInPixels_mixedPlanes_130.png").c_str())

// all
_file20->cd()
gDirectory->cd("Arm0_st2_rp3")
h2ProtonDistributionWithStrips_arm0_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_0_2_Run306135_130.png").c_str())

_file20->cd()
gDirectory->cd("Arm1_st2_rp3")
h2ProtonDistributionWithStrips_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_1_2_Run306135_130.png").c_str())

// Irradiated, but not Run306135
_file9->cd()
gDirectory->cd("Arm0_st2_rp3")
h2ProtonDistributionWithStrips_arm0_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_0_2_Run305081_130.png").c_str())

_file9->cd()
gDirectory->cd("Arm1_st2_rp3")
h2ProtonDistributionWithStrips_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular(false)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print((path+"ProtonDistributionWithStrips_1_2_Run305081_130.png").c_str())

// ***********************************************************************************

