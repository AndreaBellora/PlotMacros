#include "utils.C"

// Plot noise distribution for one plane
TCanvas* TBMDelay_HeadersComparison_POS(
    TString fed = "1463",
    TString fiber = "15",
    TString inFileTBM = "TestRootFiles/PixelRun/Runs/Run_1000/Run_1026/TBMDelay.root",
    TString inFileROC = "TestRootFiles/PixelRun/Runs/Run_1000/Run_1027/TBMDelay.root"
){
    TCanvas *c = makeCanvasWithAspectRatio("c","c",92,80);

    // Open file
    TFile *fileTBM = new TFile(inFileTBM);
    TFile *fileROC = new TFile(inFileROC);
    if (fileTBM->IsZombie() || fileROC->IsZombie())
        return c;

    // Retrieve the plot directly (no dir structure)
    TH1D *histTBM,*histROC; 
    TString plot_re = "FED"+fed+"_Fb"+fiber+"*";
    getFirstPlotFromFile(plot_re, histTBM, fileTBM);
    getFirstPlotFromFile(plot_re, histROC, fileROC);
    if ((histTBM == nullptr) || (histROC == nullptr)){
        cout << "Plots not found in files\n";
        return c;
    }

    // Style the plot
    gROOT->ForceStyle();
    gStyle->SetOptTitle(0);
    histTBM->GetXaxis()->SetTitle("TBMPLL setting");
    histTBM->GetYaxis()->SetRangeUser(0,280);
    histTBM->SetTitle("Found TBM header");
    histROC->SetTitle("Found TBM and ROC header");

    histTBM->SetFillColor(38);
    histTBM->SetLineColor(38);
    histTBM->SetMarkerColor(38);
    histROC->SetLineColor(kRed);
    histROC->SetMarkerColor(kRed);
    histROC->SetLineWidth(2);
    histTBM->Draw("");
    histROC->Draw("same");

    gStyle->SetLegendBorderSize(0);
    gStyle->SetLegendTextSize(0.03);
    gPad->BuildLegend(0.48,0.7,0.89,0.89);

    return c;
}