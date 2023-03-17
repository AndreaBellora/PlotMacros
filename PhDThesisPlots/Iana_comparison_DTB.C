#include "Iana_DTB.C"

TCanvas* Iana_comparison_DTB(
    TString inFileBefore = "/home/andrea/Work/CT-PPS/DTB/pxar/testFlexV5-1_028/pxar_20220323_160127.root",
    TString inFileAfter  = "/home/andrea/Work/CT-PPS/DTB/pxar/testFlexV5-1_028/pxar_20220404_181531.root"
){
    TCanvas *c = Iana_DTB(inFileAfter);
    TH1D *histAfter = (TH1D*)(c->GetPrimitive("Iana_V0"))->Clone();
    histAfter->SetLineColor(kRed);
    histAfter->SetTitle("After");
    delete c;
    c = Iana_DTB(inFileBefore);
    ((TH1D*)c->GetPrimitive("Iana_V0"))->SetTitle("Before");
    histAfter->Draw("same");
    c->BuildLegend(0.6,0.75,0.9,0.9);
    return c;
}