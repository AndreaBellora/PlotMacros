#include "utils.C"

// Plot noise distribution for one plane
TCanvas* POHBias_POS(
    TString fed = "1463",
    TString fiber = "16",
    TString inFile = "TestRootFiles/PixelRun/Runs/Run_1000/Run_1037/POHBias.root"
){
    TCanvas *c = makeCanvasWithAspectRatio("c","c",14,9);

    // Open file
    TFile *file = new TFile(inFile);
    if (file->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TString dirPath = "gain2/FED"+fed;
    TDirectory *dir = (TDirectory*)file->Get(dirPath);
    if (dir == nullptr){
        cout << "Directory path " << dirPath << " not found in file " << inFile << "\n";
        return c;
    }

    TCanvas *c_0; 
    TString plot_re_0 = "*"+fed+"*"+fiber+"*";
    getFirstPlotFromDir(plot_re_0, c_0, dir);

    if (c_0 == nullptr){
        cout << "Plot "+plot_re_0+" not found in file "+inFile+"\n";
        return c;
    }
    
    // Extract graph from canvas
    c->cd();
    TGraphErrors *ge = new TGraphErrors(*((TGraphErrors*)(c_0->GetListOfPrimitives()->At(0))));
    ge->GetListOfFunctions()->RemoveLast();
    ge->SetLineWidth(1);
    ge->SetMarkerStyle(8);
    ge->SetMarkerColor(kBlue);
    ge->SetLineColor(kBlue);
    ge->Draw("AP");

    double chosenSetting = ((TLine*)(c_0->GetListOfPrimitives()->At(1)))->GetX1();
    double yValue = ge->Eval(chosenSetting);
    double yMin = ge->GetYaxis()->GetXmin();
    TArrow *arrow = new TArrow(chosenSetting,0.1*(yValue-yMin)+yMin,chosenSetting,0.9*(yValue-yMin)+yMin,0.02,">");
    arrow->SetLineWidth(4);
    arrow->SetLineColor(kRed+1);
    arrow->SetFillColor(kBlack);
    arrow->Draw();

    // Style the plot
    gROOT->ForceStyle();
    gStyle->SetOptTitle(0);
    ge->GetXaxis()->SetTitleOffset(1);
    ge->GetYaxis()->SetTitleOffset(1.2);
    ge->GetXaxis()->SetTitle("POHBias");
    ge->GetYaxis()->SetTitle("RSSI");
    ge->SetLineWidth(2);

    // Separation lines
    // *** HARDCODED VALUES ***
    double firstSlopeChange = 7;
    double secondSlopeChange = 20;
    double ymin = ge->GetYaxis()->GetXmin();
    double ymax = ge->GetYaxis()->GetXmax();

    TLine *vertical1 = new TLine(firstSlopeChange,ymin,firstSlopeChange,ymax);
    vertical1->SetLineWidth(2);
    vertical1->SetLineColor(kBlack);
    vertical1->Draw("same");

    TLine *vertical2 = new TLine(secondSlopeChange,ymin,secondSlopeChange,ymax);
    vertical2->SetLineWidth(2);
    vertical2->SetLineColor(kBlack);
    vertical2->Draw("same");


    return c;
}