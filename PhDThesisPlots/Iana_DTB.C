#include "utils.C"

TCanvas* Iana_DTB(
    TString inFile = "RootFiles/PPS-tests/V5-1-010/pxar_FullTest.root"
){
    TCanvas *c = makeCanvasWithAspectRatio("c","c",92,80);

    // Open file
    TFile *file = new TFile(inFile);
    if (file->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TDirectory *dir = (TDirectory*)file->Get("Pretest");
    TH1D *hist; 
    TString plot_re = "Iana*";
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
    hist->GetXaxis()->SetTitle("ROC number");
    hist->GetXaxis()->SetBinLabel(1,"0");
    hist->GetXaxis()->SetBinLabel(2,"1");
    hist->GetXaxis()->SetBinLabel(3,"4");
    hist->GetXaxis()->SetBinLabel(4,"5");
    hist->SetLabelSize(0.05);
    hist->GetYaxis()->SetTitleOffset(1);
    hist->GetYaxis()->SetTitle("Iana (mA)");
    hist->SetLineWidth(2);
    hist->Draw();
    
    return c;
}