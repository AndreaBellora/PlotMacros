#include "utils.C"
#include <memory>
#include "CMS_lumi.h"

void MakePlots_ch3(
    TString inFile = "TestRootFiles/TrackingPlots/EraB_resolution_reMiniAOD_VerySmallRegion_OneTrack_OneHit.root",
    TString arm = "1"
){
    TString saveDir = "ch-3/fig/";
    TCanvas *c = makeCanvasWithAspectRatio("c","c",92,80);
    
    // Open file
    auto file = make_unique<TFile>(inFile);
    if (file->IsZombie())
        return c;

    // Look in the right directory and find the plot
    TTree *tTracks = (TTree*)file->Get("tTracks");
    if (tTracks == nullptr){
        cout << "Tree not found in file " << inFile << "\n";
        return c;
    }
    
    gStyle->SetOptTitle(0);

    // Horizontal cluster size 
    tTracks->Draw("clsSizeCol>>ClusterSizeX(3,1,4)","arm=="+arm);
    TH1D *hCls_x = (TH1D*)gDirectory->Get("ClusterSizeX");
    hCls_x->SetDirectory(0);
    hCls_x->SetTitle("Horizontal cluster size;Horizontal cluster size;Frequency");
    hCls_x->Scale(1./hCls_x->GetEntries());
    c->cd();
    hCls_x->SetLineWidth(2);
    // Style stat block
    gStyle->SetOptStat(100);
    TPaveStats *st = (TPaveStats*)hCls_x->FindObject("stats");
    st->SetBorderSize(0);
    st->SetX1NDC(0.6);
    st->SetX2NDC(0.84);
    st->SetY1NDC(0.8);
    st->SetY2NDC(0.85);
    st->SetStatFormat(".2f");
    hCls_x->Draw("hist");

    CMS_TOTEM_lumi((TPad *)c->GetPad(0),-1,1,"2017",false,false);
    c->SaveAs(saveDir+"Horizontal_cls.pdf");

    // Vertical cluster size 
    tTracks->Draw("clsSizeRow>>ClusterSizeY(3,1,4)","arm=="+arm);
    TH1D *hCls_y = (TH1D*)gDirectory->Get("ClusterSizeY");
    hCls_y->SetDirectory(0);
    hCls_y->SetTitle("Vertical cluster size;Vertical cluster size;Frequency");
    hCls_y->Scale(1./hCls_y->GetEntries());
    c->cd();
    hCls_y->SetLineWidth(2);
    // Style stat block
    gStyle->SetOptStat(100);
    st = (TPaveStats*)hCls_y->FindObject("stats");
    st->SetBorderSize(0);
    st->SetX1NDC(0.6);
    st->SetX2NDC(0.84);
    st->SetY1NDC(0.8);
    st->SetY2NDC(0.85);
    st->SetStatFormat(".2f");
    hCls_y->Draw("hist");

    CMS_TOTEM_lumi((TPad *)c->GetPad(0),-1,1,"2017",false,false);
    c->SaveAs(saveDir+"Vertical_cls.pdf");

    // Points in fit 
    tTracks->Draw("nPointsUsedForFit>>nPointsForFit(7,0,7)","arm=="+arm);
    TH1D *hnPointsForFit = (TH1D*)gDirectory->Get("nPointsForFit");
    hnPointsForFit->SetDirectory(0);
    hnPointsForFit->SetTitle("nPointsForFit;Number of points;Frequency");
    hnPointsForFit->Scale(1./hnPointsForFit->GetEntries());
    c->cd();
    hnPointsForFit->SetLineWidth(2);
    // Style stat block
    gStyle->SetOptStat(100);
    st = (TPaveStats*)hnPointsForFit->FindObject("stats");
    st->SetBorderSize(0);
    st->SetX1NDC(0.15);
    st->SetX2NDC(0.39);
    st->SetY1NDC(0.8);
    st->SetY2NDC(0.85);
    st->SetStatFormat(".2f");
    hnPointsForFit->Draw("hist");

    CMS_TOTEM_lumi((TPad *)c->GetPad(0),-1,1,"2017",false,false);
    c->SaveAs(saveDir+"PointsForFit.pdf");

    // Chi2
    tTracks->Draw("(nPointsUsedForFit*2-4)*chi2OverNDF>>hChi2(50,0,50)","arm=="+arm+" && nPlanesWithRowCls2_ > 2 && nPlanesWithColCls2_ > 1 && nPointsUsedForFit == 6");
    // tTracks->Draw("(nPointsUsedForFit*2-4)*chi2OverNDF>>hChi2(50,0,50)","arm=="+arm+" && nPlanesWithRowCls2_ > 0 && nPlanesWithColCls2_ > 1 && nPointsUsedForFit == 6");
    TH1D *hChi2 = (TH1D*)gDirectory->Get("hChi2");
    hChi2->SetDirectory(0);
    hChi2->SetTitle("hChi2;#chi^{2}");
    // hChi2->Scale(1./hChi2->GetEntries());
    // cout << hChi2->Integral() << endl; 
    c->cd();
    hChi2->SetLineWidth(2);
    // Style stat block
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(2);
 
    hChi2->Draw("hist E1");

    // Trying to fit a chi2 function, not that successful
    // TF1 *f = new TF1("f","ROOT::Math::chisquared_pdf(x,[0])",0,20);
    // f->SetParameter(0,8);
    // hChi2->Fit(f,"");
    // cout << f->Integral(0,30) << endl;
    // f->Draw("same");

    CMS_TOTEM_lumi((TPad *)c->GetPad(0),-1,1,"2017",false,false);
    c->SaveAs(saveDir+"Chi2.pdf");

}