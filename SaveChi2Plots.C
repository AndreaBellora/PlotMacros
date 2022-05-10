string outputFolderPng = "~/cernbox/PPS/PlotsForThreePlusThreeStudies/EraPlots/Chi2Plots/"
string suffix = "_Chi2OverNDF_ROC0_EraF3"
setRectangularPlots()
setTDRStyle()
TCanvas c
c.SetWindowSize(1430,1023)
gStyle->SetLegendBorderSize(0)

h1Chi2WhenInterpotMatch = TH1D(*((TH1D*)_file0->Get("Arm0_st2_rp3/h1Chi2WhenInterpotMatch_arm0_st2_rp3")))
h1Chi2WhenInterpotMatchANDmultiRP = TH1D(*((TH1D*)_file0->Get("Arm0_st2_rp3/h1Chi2WhenInterpotMatchANDmultiRP_arm0_st2_rp3")))
h1Chi2WhenInterpotMatchANDNOTmultiRP = TH1D(*((TH1D*)_file0->Get("Arm0_st2_rp3/h1Chi2WhenInterpotMatchANDNOTmultiRP_arm0_st2_rp3")))
h1Chi2WhenNoInterpotMatchANDmultiRP = TH1D(*((TH1D*)_file0->Get("Arm0_st2_rp3/h1Chi2WhenNoInterpotMatchANDmultiRP_arm0_st2_rp3")))

h1Chi2WhenInterpotMatch.SetTitle("Interpot Match;#chi^{2}")
h1Chi2WhenInterpotMatchANDmultiRP.SetTitle("Interpot Match && multiRP found;#chi^{2}")
h1Chi2WhenInterpotMatchANDNOTmultiRP.SetTitle("Interpot Match && multiRP not found;#chi^{2}")
h1Chi2WhenNoInterpotMatchANDmultiRP.SetTitle("No Interpot Match && multiRP")

h1Chi2WhenInterpotMatch.SetFillStyle(3001)
h1Chi2WhenInterpotMatchANDmultiRP.SetFillStyle(3001)
h1Chi2WhenInterpotMatchANDNOTmultiRP.SetFillStyle(3001)
h1Chi2WhenNoInterpotMatchANDmultiRP.SetFillStyle(3001)

h1Chi2WhenInterpotMatch.SetFillColor(38)
h1Chi2WhenInterpotMatchANDmultiRP.SetFillColor(46)
h1Chi2WhenInterpotMatchANDNOTmultiRP.SetFillColor(41)
h1Chi2WhenNoInterpotMatchANDmultiRP.SetFillColor(46)

h1Chi2WhenInterpotMatch.SetLineColor(kBlack)
h1Chi2WhenInterpotMatchANDmultiRP.SetLineColor(kBlack)
h1Chi2WhenInterpotMatchANDNOTmultiRP.SetLineColor(kBlack)
h1Chi2WhenNoInterpotMatchANDmultiRP.SetLineColor(kBlack)

h1Chi2WhenInterpotMatch.Draw()
h1Chi2WhenInterpotMatchANDmultiRP.Draw("same")
h1Chi2WhenInterpotMatchANDNOTmultiRP.Draw("same")


legendWhenInterpotMatch = new TLegend(0.55,0.65,0.9,0.9)
legendWhenInterpotMatch->SetFillStyle(0)

legendWhenInterpotMatch->AddEntry(&h1Chi2WhenInterpotMatch,"Interpot Match")
legendWhenInterpotMatch->AddEntry(&h1Chi2WhenInterpotMatchANDmultiRP,"Interpot Match && multiRP found")
legendWhenInterpotMatch->AddEntry(&h1Chi2WhenInterpotMatchANDNOTmultiRP,"Interpot Match && multiRP not found")
legendWhenInterpotMatch->Draw()

c.Print((outputFolderPng+"45-220_Chi2WhenInterpotMatch"+suffix+".png").data())

h1Chi2WhenInterpotMatch.DrawNormalized()
h1Chi2WhenInterpotMatchANDmultiRP.DrawNormalized("same")
h1Chi2WhenInterpotMatchANDNOTmultiRP.DrawNormalized("same")
legendWhenInterpotMatch->Draw("same")

c.Print((outputFolderPng+"45-220_Chi2WhenInterpotMatch_Normalized"+suffix+".png").data())

legendComparisonPlot = new TLegend(0.55,0.65,0.9,0.9)
legendComparisonPlot->SetFillStyle(0)
legendComparisonPlot->AddEntry(&h1Chi2WhenInterpotMatch,"Interpot Match")
legendComparisonPlot->AddEntry(&h1Chi2WhenNoInterpotMatchANDmultiRP, "No Interpot Match && multiRP")

h1Chi2WhenInterpotMatch.DrawNormalized()
h1Chi2WhenNoInterpotMatchANDmultiRP.DrawNormalized("same")
legendComparisonPlot->Draw("same")

c.Print((outputFolderPng+"45-220_Chi2Comparison_Normalized"+suffix+".png").data())




h1Chi2WhenInterpotMatch = TH1D(*((TH1D*)_file0->Get("Arm1_st2_rp3/h1Chi2WhenInterpotMatch_arm1_st2_rp3")))
h1Chi2WhenInterpotMatchANDmultiRP = TH1D(*((TH1D*)_file0->Get("Arm1_st2_rp3/h1Chi2WhenInterpotMatchANDmultiRP_arm1_st2_rp3")))
h1Chi2WhenInterpotMatchANDNOTmultiRP = TH1D(*((TH1D*)_file0->Get("Arm1_st2_rp3/h1Chi2WhenInterpotMatchANDNOTmultiRP_arm1_st2_rp3")))
h1Chi2WhenNoInterpotMatchANDmultiRP = TH1D(*((TH1D*)_file0->Get("Arm1_st2_rp3/h1Chi2WhenNoInterpotMatchANDmultiRP_arm1_st2_rp3")))

h1Chi2WhenInterpotMatch.SetTitle("Interpot Match;#chi^{2}")
h1Chi2WhenInterpotMatchANDmultiRP.SetTitle("Interpot Match && multiRP found;#chi^{2}")
h1Chi2WhenInterpotMatchANDNOTmultiRP.SetTitle("Interpot Match && multiRP not found;#chi^{2}")
h1Chi2WhenNoInterpotMatchANDmultiRP.SetTitle("No Interpot Match && multiRP")

h1Chi2WhenInterpotMatch.SetFillStyle(3001)
h1Chi2WhenInterpotMatchANDmultiRP.SetFillStyle(3001)
h1Chi2WhenInterpotMatchANDNOTmultiRP.SetFillStyle(3001)
h1Chi2WhenNoInterpotMatchANDmultiRP.SetFillStyle(3001)

h1Chi2WhenInterpotMatch.SetFillColor(38)
h1Chi2WhenInterpotMatchANDmultiRP.SetFillColor(46)
h1Chi2WhenInterpotMatchANDNOTmultiRP.SetFillColor(41)
h1Chi2WhenNoInterpotMatchANDmultiRP.SetFillColor(46)

h1Chi2WhenInterpotMatch.SetLineColor(kBlack)
h1Chi2WhenInterpotMatchANDmultiRP.SetLineColor(kBlack)
h1Chi2WhenInterpotMatchANDNOTmultiRP.SetLineColor(kBlack)
h1Chi2WhenNoInterpotMatchANDmultiRP.SetLineColor(kBlack)

h1Chi2WhenInterpotMatch.Draw()
h1Chi2WhenInterpotMatchANDmultiRP.Draw("same")
h1Chi2WhenInterpotMatchANDNOTmultiRP.Draw("same")


legendWhenInterpotMatch = new TLegend(0.55,0.65,0.9,0.9)
legendWhenInterpotMatch->SetFillStyle(0)

legendWhenInterpotMatch->AddEntry(&h1Chi2WhenInterpotMatch,"Interpot Match")
legendWhenInterpotMatch->AddEntry(&h1Chi2WhenInterpotMatchANDmultiRP,"Interpot Match && multiRP found")
legendWhenInterpotMatch->AddEntry(&h1Chi2WhenInterpotMatchANDNOTmultiRP,"Interpot Match && multiRP not found")
legendWhenInterpotMatch->Draw()

c.Print((outputFolderPng+"56-220_Chi2WhenInterpotMatch"+suffix+".png").data())

h1Chi2WhenInterpotMatch.DrawNormalized()
h1Chi2WhenInterpotMatchANDmultiRP.DrawNormalized("same")
h1Chi2WhenInterpotMatchANDNOTmultiRP.DrawNormalized("same")
legendWhenInterpotMatch->Draw()

c.Print((outputFolderPng+"56-220_Chi2WhenInterpotMatch_Normalized"+suffix+".png").data())

legendComparisonPlot = new TLegend(0.55,0.65,0.9,0.9)
legendComparisonPlot->SetFillStyle(0)
legendComparisonPlot->AddEntry(&h1Chi2WhenInterpotMatch,"Interpot Match")
legendComparisonPlot->AddEntry(&h1Chi2WhenNoInterpotMatchANDmultiRP, "No Interpot Match && multiRP")


h1Chi2WhenInterpotMatch.DrawNormalized()
h1Chi2WhenNoInterpotMatchANDmultiRP.DrawNormalized("same")
legendComparisonPlot->Draw("same")

c.Print((outputFolderPng+"56-220_Chi2Comparison_Normalized"+suffix+".png").data())
