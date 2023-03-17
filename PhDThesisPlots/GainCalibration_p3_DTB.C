#include "utils.C"

// Plot noise distribution for one plane
TCanvas* GainCalibration_p3_DTB(
    TString chip = "0",
    TString inFile = "TestRootFiles/PPS-tests/V5-1-010/pxar_FullTest.root"
){
    TCanvas *c = makeCanvasWithAspectRatio("c","c",92,80);

    // Open file
    TFile *file = new TFile(inFile);
    if (file->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TString dirPath = "GainPedestal";
    TDirectory *dir = (TDirectory*)file->Get(dirPath);
    if (dir == nullptr){
        cout << "Directory path " << dirPath << " not found in file " << inFile << "\n";
        return c;
    }

    TH1D *hist; 
    TString plot_re = "gainPedestalP3_C"+chip+"*";
    getFirstPlotFromDir(plot_re, hist, dir);
    if (hist == nullptr){
        cout << "Plots not found in file "+inFile+"\n";
        return c;
    }

    // Style the plot
    gROOT->ForceStyle();
    gStyle->SetOptTitle(0);
    hist->GetXaxis()->SetTitleOffset(1);
    hist->GetYaxis()->SetTitleOffset(1.2);
    hist->GetXaxis()->SetTitleSize(0.035);
    hist->GetYaxis()->SetTitleSize(0.035);
    hist->GetXaxis()->SetLabelSize(0.035);
    hist->GetYaxis()->SetLabelSize(0.035);
    hist->GetXaxis()->SetTitle("p_{3}");
    hist->GetYaxis()->SetTitle("");
    hist->SetLineWidth(2);
    hist->SetStats(1);
    hist->SetMaximum(900);
    hist->Draw();

    // Style stat block
    gStyle->SetOptStat(1100);
    TPaveStats *st = (TPaveStats*)hist->FindObject("stats");
    st->SetBorderSize(0);
    st->SetX1NDC(0.6);
    st->SetX2NDC(0.84);
    st->SetY1NDC(0.7);
    st->SetY2NDC(0.89);
    st->SetStatFormat(".1f");
    st->Draw();

    return c;
}