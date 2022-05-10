Root OutputFiles/EraB* OutputFiles/Run297050* OutputFiles/Run297219* OutputFiles/Run300558* OutputFiles/Run303832* OutputFiles/Run305081*


setRectangularPlots()
setTDRStyle()
TCanvas c
c.SetWindowSize(1430,1023)

_file3->cd()
gDirectory->cd("Arm0_st2_rp3")
h2RefinedTrackEfficiency_arm0_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_0_2_EraB.png")

_file3->cd()
gDirectory->cd("Arm1_st2_rp3")
h2RefinedTrackEfficiency_arm1_st2_rp3->Draw("colz")
setRange_st2_rectangular(true)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_1_2_EraB.png")

_file4->cd()
gDirectory->cd("Arm0_st2_rp3/Arm0_st2_rp3_pl4")
h2EfficiencyMap_arm0_st2_rp3_pl4->Draw("colz")
setRange_st2_rectangular()
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR Plane 4")
c.Print("~/cernbox/PPS/PlotsForDPGNote/2017_PlaneEfficiency_0_2_4_EraB.png")


_file12->cd()
gDirectory->cd("Arm0_st2_rp3")
h2TrackHitDistribution_arm0_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular()
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print("~/cernbox/PPS/PlotsForDPGNote/2017_TrackHitDistribution_0_2_Run297219.png")

_file12->cd()
gDirectory->cd("Arm1_st2_rp3/BinShift")
h2TrackHitDistributionBinShift_50_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular()
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print("~/cernbox/PPS/PlotsForDPGNote/2017_TrackHitDistribution_50_1_2_Run297219.png")

_file12->cd()
gDirectory->cd("Arm1_st2_rp3")
h2TrackHitDistribution_arm1_st2_rp3->Draw("colz")
c.SetLogz()
setRange_st2_rectangular()
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print("~/cernbox/PPS/PlotsForDPGNote/2017_TrackHitDistribution_1_2_Run297219.png")

setSquarePlots()
setTDRStyle()
TCanvas c1
c1.SetWindowSize(1101,1023)

_file11->cd()
gDirectory->cd("Arm0_st2_rp3")
h2RefinedTrackEfficiency_arm0_st2_rp3->Draw("colz")
setRange_st2_square()
CMS_lumi(&c1,0,0,"LHC Sector 45 220 FAR")
c1.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_0_2_Run297219.png")

_file11->cd()
gDirectory->cd("Arm1_st2_rp3")
h2RefinedTrackEfficiency_arm1_st2_rp3->Draw("colz")
setRange_st2_square()
CMS_lumi(&c1,0,0,"LHC Sector 56 220 FAR")
c1.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_1_2_Run297219.png")

_file15->cd()
gDirectory->cd("Arm0_st2_rp3")
h2RefinedTrackEfficiency_arm0_st2_rp3->Draw("colz")
setRange_st2_square()
CMS_lumi(&c1,0,0,"LHC Sector 45 220 FAR")
c1.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_0_2_Run300576.png")

_file15->cd()
gDirectory->cd("Arm1_st2_rp3")
h2RefinedTrackEfficiency_arm1_st2_rp3->Draw("colz")
setRange_st2_square()
CMS_lumi(&c1,0,0,"LHC Sector 56 220 FAR")
c1.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_1_2_Run300576.png")

_file19->cd()
gDirectory->cd("Arm0_st2_rp3")
h2RefinedTrackEfficiency_arm0_st2_rp3->Draw("colz")
setRange_st2_square()
CMS_lumi(&c1,0,0,"LHC Sector 45 220 FAR")
c1.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_0_2_Run303832.png")

_file19->cd()
gDirectory->cd("Arm1_st2_rp3")
h2RefinedTrackEfficiency_arm1_st2_rp3->Draw("colz")
setRange_st2_square()
CMS_lumi(&c1,0,0,"LHC Sector 56 220 FAR")
c1.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_1_2_Run303832.png")

_file23->cd()
gDirectory->cd("Arm0_st2_rp3")
h2RefinedTrackEfficiency_arm0_st2_rp3->Draw("colz")
setRange_st2_square()
CMS_lumi(&c1,0,0,"LHC Sector 45 220 FAR")
c1.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_0_2_Run305081.png")

_file23->cd()
gDirectory->cd("Arm1_st2_rp3")
h2RefinedTrackEfficiency_arm1_st2_rp3->Draw("colz")
setRange_st2_square()
CMS_lumi(&c1,0,0,"LHC Sector 56 220 FAR")
c1.Print("~/cernbox/PPS/PlotsForDPGNote/2017_RefinedEfficiency_1_2_Run305081.png")

// Efficiency vs Xi
Root OutputFiles/Run297219_efficiencyVsXi.root OutputFiles/Run305081_efficiencyVsXi.root

setRectangularPlots()
setTDRStyle()
TCanvas c
c.SetWindowSize(1430,1023)

hBegin = new TH1D(*((TH1D*)_file0->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
hEnd = new TH1D(*((TH1D*)_file1->Get("Arm0_st2_rp3/h1EfficiencyVsXi_arm0_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX();i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);if(hBegin->GetBinContent(i) != 0 )hEnd->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

hEnd->SetLineColor(kRed)
hEnd->SetMarkerColor(kRed)
hEnd->SetMarkerStyle(kFullTriangleUp)
hEnd->SetFillColor(45)
hEnd->SetMarkerSize(1.3)
hEnd->Draw("P E2 same")
hEnd->Draw("P E1 same")
hEnd->SetTitle("L_{int} = 29.6 fb^{-1}")

auto legend_0_2 = new TLegend(0.65,0.1,0.9,0.25)
legend_0_2->SetMargin(0.2)
legend_0_2->AddEntry(hBegin,"Beginning of data taking","lp")
legend_0_2->AddEntry(hEnd,"L_{int} = 29.6 fb^{-1}","lp")
legend_0_2->Draw()
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.12)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
CMS_lumi(&c,0,0,"LHC Sector 45 220 FAR")
c.Print("~/cernbox/PPS/PlotsForDPGNote/2017_EffVsXi_0_2_Run297219_Run305081.png")

hBegin = new TH1D(*((TH1D*)_file0->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
hEnd = new TH1D(*((TH1D*)_file1->Get("Arm1_st2_rp3/h1EfficiencyVsXi_arm1_st2_rp3")))
for(auto i=0;i<hBegin->GetNbinsX();i++){if(hBegin->GetBinContent(i) != 0 )hBegin->SetBinError(i,0.01);if(hBegin->GetBinContent(i) != 0 )hEnd->SetBinError(i,0.01);}

hBegin->SetLineColor(kBlue)
hBegin->SetMarkerColor(kBlue)
hBegin->SetMarkerStyle(kFullSquare)
hBegin->SetFillColor(38)
hBegin->Draw("P E2")
hBegin->Draw("P E1 same")
hBegin->SetTitle("Beginning of data taking")

hEnd->SetLineColor(kRed)
hEnd->SetMarkerColor(kRed)
hEnd->SetMarkerStyle(kFullTriangleUp)
hEnd->SetFillColor(45)
hEnd->SetMarkerSize(1.3)
hEnd->Draw("P E2 same")
hEnd->Draw("P E1 same")
hEnd->SetTitle("L_{int} = 29.6 fb^{-1}")

auto legend_1_2 = new TLegend(0.65,0.1,0.9,0.25)
legend_1_2->SetMargin(0.2)
legend_1_2->AddEntry(hBegin,"Beginning of data taking","lp")
legend_1_2->AddEntry(hEnd,"L_{int} = 29.6 fb^{-1}","lp")
legend_1_2->Draw()
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 0.16)
((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetYaxis()->SetRangeUser(0.001, 1.1)
CMS_lumi(&c,0,0,"LHC Sector 56 220 FAR")
c.Print("~/cernbox/PPS/PlotsForDPGNote/2017_EffVsXi_1_2_Run297219_Run305081.png")

// For efficiency vs. lumi plots
gStyle->SetCanvasDefH(1025)
gStyle->SetCanvasDefW(1853)
gStyle->SetOptTitle(0);
gStyle->SetPadTickX(1);
.x EfficiencyVsLumiPlot.C
cAvgEfficiencyPeakFitted->cd();
CMS_lumi(cAvgEfficiencyPeakFitted,0,0," Irradiation Peak Area")
cAvgEfficiencyPeakFitted->Print("~/cernbox/PPS/PlotsForDPGNote/2017_EffVsLumi_Peak.png")
cControlAreaEfficiency->cd();
CMS_lumi(cControlAreaEfficiency,0,0,"Complementary Area")
cControlAreaEfficiency->Print("~/cernbox/PPS/PlotsForDPGNote/2017_EffVsLumi_Complementary.png")