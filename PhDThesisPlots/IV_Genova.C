#include "utils.C"

void IV_Genova(){
    using namespace std;
    TCanvas *c = makeCanvasWithAspectRatio("c","c",10,10);

    TString folder = "IVCurves/";
    vector<TString> inFiles = {
        "V5-1-000_IV.dat",
        "V5-1-002_IV.dat",
        "V5-1-003_IV.dat",
        "V5-1-005_IV.dat",
        "V5-1-018_IV.dat",
        "V5-1-020_IV.dat"
    };

    auto mg = new TMultiGraph();
    mg->SetTitle(";Reverse bias voltage (V); Current (#muA)");
    TGraph *g;
    for (const auto &filename : inFiles){
        auto g = new TGraph((folder+filename).Data());
        TString title(filename);
        g->SetTitle(title.ReplaceAll("_IV.dat",""));
        g->SetLineWidth(2);
        g->SetMarkerStyle(8);
        mg->Add(g, "PL");
    }

    gStyle->SetPalette(kCMYK);
    gStyle->SetLegendBorderSize(0);
    gStyle->SetLegendTextSize(0.037);
    mg->GetYaxis()->SetRangeUser(0.01,150);
    mg->GetXaxis()->SetLimits(0,140);
    mg->GetYaxis()->SetTitleOffset(1.2);
    mg->GetXaxis()->SetTitleOffset(1.2);
    mg->Draw("a pmc plc");
    c->SetLogy();
    c->BuildLegend(0.7,0.6,0.89,0.89);
    c->SaveAs("ch-5/fig/IVCurves.pdf");
}