#include "utils.C"

TCanvas* Delay25_POS(
    TString sector = "45",
    TString rpId = "003",
    TString plane = "2",
    TString command = "1",
    TString inFile = "TestRootFiles/PixelRun/Runs/Run_1000/Run_1072/delay25_1.root"
){
    TCanvas *c = makeCanvasWithAspectRatio("c","c",92,80);

    // Open file
    TFile *file = new TFile(inFile);
    if (file->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TString rpTag = "CTPPS_SEC"+sector+"_RP"+rpId;
    TString dirPath = "CTPPS/CTPPS_SEC"+sector+"/"+rpTag;
    TDirectory *dir = (TDirectory*)file->Get(dirPath);
    if (dir == nullptr){
        cout << "Directory path " << dirPath << " not found in file " << inFile << "\n";
        return c;
    }

    // Get the canvas with the plot
    TCanvas *c_0; 
    TString plot_re = "*"+rpTag+"*PLN"+plane+"*";
    if (command != "")
        plot_re += "_command"+command;
    getFirstPlotFromDir(plot_re, c_0, dir);
    if (c_0 == nullptr){
        cout << "Plots not found in file "+inFile+"\n";
        return c;
    }

    // Get the histogram for plot axis
    TH2F *hist = new TH2F(*((TH2F*)(c_0->GetListOfPrimitives()->At(0))));
    
    // Style the plot
    gROOT->ForceStyle();
    gStyle->SetOptTitle(0);
    hist->GetXaxis()->SetTitle("SDa delay");
    hist->GetYaxis()->SetTitle("RDa delay");
    hist->GetYaxis()->SetTitleOffset(1.2);
    c->cd();
    hist->Draw();

    // Get all the dots
    for (auto&& marker : *(c_0->GetListOfPrimitives())){
        if (marker->InheritsFrom("TMarker")){
            c->cd();
            marker->Draw("same");
        }
    }
    
    return c;
}