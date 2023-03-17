#include "utils.C"

// Plot noise distribution for one plane
TCanvas* GainCalibration_Fit_POS(
    TString sector = "45",
    TString rpId = "023",
    TString plane = "4",
    TString roc = "3",
    TString pixelString = "row0_col13",
    TString inFile = "RootFiles/PixelRun/Runs/Run_1000/Run_522/Gain_Fed_1462-1463_Run_522.root"
){
    TCanvas *c = makeCanvasWithAspectRatio("c","c",92,80);

    // Open file
    TFile *file = new TFile(inFile);
    if (file->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TString planeTag = "CTPPS_SEC"+sector+"_RP"+rpId+"_PLN"+plane;
    TString dirPath = "GoodCells";
    TDirectory *dir = (TDirectory*)file->Get(dirPath);
    if (dir == nullptr){
        cout << "Directory path " << dirPath << " not found in file " << inFile << "\n";
        return c;
    }

    TH1D *hist; 
    TString plot_re = planeTag+"_ROC"+roc+"_"+pixelString;
    getFirstPlotFromDir(plot_re, hist, dir);
    if (hist == nullptr){
        cout << "Plots not found in file "+inFile+"\n";
        return c;
    }

    TF1 *linearFit = (TF1*)hist->GetListOfFunctions()->At(0);
    linearFit->SetLineWidth(2);
    linearFit->SetLineColor(kRed);
    linearFit->SetRange(20,90);
    TF1 *tanhFit = (TF1*)hist->GetListOfFunctions()->At(1);
    tanhFit->SetLineWidth(2);
    tanhFit->SetLineColor(kGray+2);
    
    hist->Draw();

    // Style the plot
    gROOT->ForceStyle();
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);
    hist->GetXaxis()->SetTitleOffset(1);
    hist->GetYaxis()->SetTitleOffset(1.2);
    hist->GetXaxis()->SetTitle("Injected charge (Vcal)");
    hist->GetXaxis()->SetTitleSize(0.035);
    hist->GetXaxis()->SetLabelSize(0.035);
    hist->GetXaxis()->SetRangeUser(0,200);
    hist->GetYaxis()->SetTitle("ADC counts");
    
    hist->SetLineWidth(2);
    hist->Draw();
    gPad->SetRightMargin(0.15);

    return c;
}