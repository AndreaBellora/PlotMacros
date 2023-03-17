#include "utils.C"

TCanvas* Trimming_DTB_POS(
    TString chip_DTB = "1",
    TString sector = "45",
    TString rpId = "003",
    TString plane = "5",
    TString roc = "0",
    TString inFile_DTB = "RootFiles/PPS-tests/V5-1-010/pxar_FullTest.root",
    TString inFile_POS = "RootFiles/PixelRun/Runs/Run_1000/Run_1011/SCurve_Fed_1462-1463_Run_1011.root"
){
    using namespace std;
    TCanvas *c = makeCanvasWithAspectRatio("c","c",92,80);

    // Open the DTB file
    TFile *file_DTB = new TFile(inFile_DTB);
    if (file_DTB->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TDirectory *dir_DTB = (TDirectory*)file_DTB->Get("Trim");
    
    // Get 1D hist after trimming
    TH1D *hist_after;
    TString hist_after_re = "dist_thr_TrimThrFinal_vcal_C"+chip_DTB+"*";
    getFirstPlotFromDir(hist_after_re, hist_after, dir_DTB);
    if (hist_after == nullptr){
        cout << "Plot matching "+hist_after_re+" not found in file "+inFile_DTB+"\n";
        return c;
    }

    // Open the POS file
    TFile *file_POS = new TFile(inFile_POS);
    if (file_POS->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TString planeTag = "CTPPS_SEC"+sector+"_RP"+rpId+"_PLN"+plane;
    TString dirPath = "CTPPS/CTPPS_SEC"+sector+"/CTPPS_SEC"+sector+"_RP"+rpId+"/"+planeTag;
    TDirectory *dir_POS = (TDirectory*)file_POS->Get(dirPath);

    TH1D *hist_before;
    TString hist_before_re = planeTag+"_ROC"+roc+"_Threshold1D*";
    getFirstPlotFromDir(hist_before_re, hist_before, dir_POS);
    if (hist_before == nullptr){
        cout << "Plot matching "+hist_before_re+" not found in file "+inFile_POS+"\n";
        return c;
    }

    // Get some stat info
    TString mu_before = Form("%.1f",hist_before->GetMean());
    TString rms_before = Form("%.1f",hist_before->GetRMS());
    TString mu_after = Form("%.1f",hist_after->GetMean());
    TString rms_after = Form("%.1f",hist_after->GetRMS());

    // Style the plots
    gROOT->ForceStyle();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    hist_after->GetXaxis()->SetTitleOffset(1);
    hist_after->GetXaxis()->SetRangeUser(0,150);
    hist_after->GetYaxis()->SetTitleOffset(1);
    hist_after->GetXaxis()->SetTitle("Threshold (Vcal)");
    hist_before->SetLineWidth(2);
    hist_after->SetLineWidth(2);
    hist_after->SetLineColor(kRed);
    
    gStyle->SetLegendBorderSize(0);
    gStyle->SetLegendTextSize(0.03);
    TLegend *leg = new TLegend(0.38,0.7,0.89,0.89);
    
    leg->AddEntry(hist_before,"Before: mean = "+mu_before+", Std Dev = "+rms_before);
    leg->AddEntry(hist_after,"After: mean = "+mu_after+", Std Dev = "+rms_after);

    hist_after->Draw();    
    hist_before->Draw("same");    
    leg->Draw();
    
    return c;
}