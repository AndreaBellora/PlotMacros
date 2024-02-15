#include "utils.C"

// Plot noise distribution for one plane
TCanvas* GainCalibration_Slope_POS(
    TString sector = "45",
    TString rpId = "003",
    TString plane = "0",
    TString inFile = "TestRootFiles/PixelRun/Runs/Run_1000/Run_522/Gain_Fed_1462-1463_Run_522.root"
){
    TCanvas *c = makeCanvasWithAspectRatio("c","c",92,80);

    // Open file
    TFile *file = new TFile(inFile);
    if (file->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TString planeTag = "CTPPS_SEC"+sector+"_RP"+rpId+"_PLN"+plane;
    TString dirPath = "CTPPS/CTPPS_SEC"+sector+"/CTPPS_SEC"+sector+"_RP"+rpId+"/"+planeTag;
    TDirectory *dir = (TDirectory*)file->Get(dirPath);
    if (dir == nullptr){
        cout << "Directory path " << dirPath << " not found in file " << inFile << "\n";
        return c;
    }

    TH1D *hist_0,*hist_1,*hist_2,*hist_3; 
    TString plot_re_0 = planeTag+"_ROC0_Slope1D*";
    TString plot_re_1 = planeTag+"_ROC1_Slope1D*";
    TString plot_re_2 = planeTag+"_ROC4_Slope1D*";
    TString plot_re_3 = planeTag+"_ROC5_Slope1D*";
    getFirstPlotFromDir(plot_re_0, hist_0, dir);
    getFirstPlotFromDir(plot_re_1, hist_1, dir);
    getFirstPlotFromDir(plot_re_2, hist_2, dir);
    getFirstPlotFromDir(plot_re_3, hist_3, dir);
    if ((hist_0 == nullptr) || (hist_1 == nullptr) || (hist_2 == nullptr) || (hist_3 == nullptr)){
        cout << "Plots not found in file "+inFile+"\n";
        return c;
    }
        
    // Fill the plot with all the results
    double x_min = hist_0->GetBinLowEdge(1);
    double x_max = hist_0->GetBinLowEdge(hist_0->GetNbinsX()+1);
    TH1D *hist = new TH1D("","",hist_0->GetNbinsX(),x_min,x_max);
    hist->Add(hist_0);
    hist->Add(hist_1);
    hist->Add(hist_2);
    hist->Add(hist_3);

    // Style the plot
    gROOT->ForceStyle();
    gStyle->SetOptTitle(0);
    hist->GetXaxis()->SetTitleOffset(1);
    hist->GetYaxis()->SetTitleOffset(1.2);
    hist->GetXaxis()->SetTitle("Slope (ADC/Vcal)");
    hist->SetLineWidth(2);
    hist->SetStats(1);
    hist->Draw();
    gPad->SetRightMargin(0.15);

    // Style stat block
    gStyle->SetOptStat(1100);
    TPaveStats *st = (TPaveStats*)hist->FindObject("stats");
    st->SetBorderSize(0);
    st->SetX1NDC(0.6);
    st->SetX2NDC(0.84);
    st->SetY1NDC(0.7);
    st->SetY2NDC(0.89);
    st->SetStatFormat(".2f");
    st->Draw();

    return c;
}