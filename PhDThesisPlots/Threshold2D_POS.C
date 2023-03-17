#include "utils.C"

TCanvas* Threshold2D_POS(
    TString sector = "45",
    TString rpId = "003",
    TString plane = "0",
    TString inFile = "TestRootFiles/PixelRun/Runs/Run_1000/Run_1011/SCurve_Fed_1462-1463_Run_1011.root"
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

    TH2D *hist_0,*hist_1,*hist_2,*hist_3; 
    TString plot_re_0 = planeTag+"_ROC0_Threshold2D*";
    TString plot_re_1 = planeTag+"_ROC1_Threshold2D*";
    TString plot_re_2 = planeTag+"_ROC4_Threshold2D*";
    TString plot_re_3 = planeTag+"_ROC5_Threshold2D*";
    getFirstPlotFromDir(plot_re_0, hist_0, dir);
    getFirstPlotFromDir(plot_re_1, hist_1, dir);
    getFirstPlotFromDir(plot_re_2, hist_2, dir);
    getFirstPlotFromDir(plot_re_3, hist_3, dir);
    if ((hist_0 == nullptr) || (hist_1 == nullptr) || (hist_2 == nullptr) || (hist_3 == nullptr)){
        cout << "Plots not found in file "+inFile+"\n";
        return c;
    }
    
    // Flip plots on ROC 0,1
    TH2D *hist_0_flip = new TH2D(*hist_0);
    TH2D *hist_1_flip = new TH2D(*hist_1);
    for (int x=1; x<=hist_0->GetNbinsX(); x++) 
        for (int y=1; y<=hist_0->GetNbinsY(); y++) {
            hist_0_flip->SetBinContent(x,y, 
                hist_0->GetBinContent(hist_0->GetNbinsX()-x+1,hist_0->GetNbinsY()-y+1) );
            hist_1_flip->SetBinContent(x,y, 
                hist_1->GetBinContent(hist_1->GetNbinsX()-x+1,hist_1->GetNbinsY()-y+1) );
        }
    
    // Fill the plot with all the results
    TH2D *hist = new TH2D("","",2*hist_0->GetNbinsX(),0,2*hist_0->GetNbinsX(),2*hist_0->GetNbinsY(),0,2*hist_0->GetNbinsY());
    for (int x=1; x<=hist_0->GetNbinsX(); x++) 
        for (int y=1; y<=hist_0->GetNbinsY(); y++) {
            hist->SetBinContent(x,hist_0->GetNbinsY()+y,hist_0_flip->GetBinContent(x,y));
            hist->SetBinContent(hist_0->GetNbinsX()+x,hist_0->GetNbinsY()+y,hist_1_flip->GetBinContent(x,y));
            hist->SetBinContent(hist_0->GetNbinsX()+x,y,hist_2->GetBinContent(x,y));
            hist->SetBinContent(x,y,hist_3->GetBinContent(x,y));
    }

    // Style the plot
    gROOT->ForceStyle();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    hist->GetXaxis()->SetTitleOffset(1);
    hist->GetYaxis()->SetTitleOffset(1.2);
    hist->GetXaxis()->SetTitle("Column");
    hist->GetYaxis()->SetTitle("Row");
    hist->SetMinimum(0);
    hist->SetMaximum(80);
    hist->Draw("colz");
    gPad->SetRightMargin(0.15);

    // ROC lines
    TLine *vertical = new TLine(52,0,52,160);
    vertical->SetLineWidth(2);
    vertical->SetLineColor(kBlack);
    vertical->Draw("same");

    TLine *horizontal = new TLine(0,80,104,80);
    horizontal->SetLineWidth(2);
    horizontal->SetLineColor(kBlack);
    horizontal->Draw("same");

    return c;
}