#include "utils.C"

TCanvas* TornadoPlot_DTB(
    TString chip = "1",
    TString inFile = "TestRootFiles/PPS-tests/V5-1-010/pxar_FullTest.root"
){
    TCanvas *c = makeCanvasWithAspectRatio("c","c",14,9);

    // Open file
    TFile *file = new TFile(inFile);
    if (file->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TDirectory *dir = (TDirectory*)file->Get("Pretest");
    TH2D *hist; 
    TString plot_re = "pretestVthrCompCalDel_*_C"+chip+"*";
    getFirstPlotFromDir(plot_re, hist, dir);
    if (hist == nullptr){
        cout << "Plot matching "+plot_re+" not found in file "+inFile+"\n";
        return c;
    }
    
    // Style the plot
    gROOT->ForceStyle();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    hist->GetXaxis()->SetTitleOffset(0.9);
    hist->GetYaxis()->SetTitleOffset(1);
    hist->GetYaxis()->SetTitle("VcThr");
    hist->Draw("colz");    
    
    return c;
}