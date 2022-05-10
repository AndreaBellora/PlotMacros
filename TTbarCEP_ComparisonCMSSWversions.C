void makePlots(){
using namespace std;
gStyle->SetOptStat(0);
gStyle->SetOptTitle(1);

TFile *_file0 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_601.root");
TFile *_file1 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_602.root");
TFile *_file2 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_603.root");
TFile *_file3 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_604.root");
TFile *_file4 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_605.root");
TFile *_file5 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_old_601.root");
TFile *_file6 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_old_602.root");
TFile *_file7 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_old_603.root");
TFile *_file8 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_old_604.root");
TFile *_file9 = TFile::Open("RecEvents_Signal_ANDREA_10_6_2_old_605.root");


TCanvas c;
c.SetWindowSize(1280,720);

TH1F ch_tag_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("ch_tag")));
TH1F ch_tag_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("ch_tag")));
TH1F ch_tag_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("ch_tag")));
TH1F ch_tag_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("ch_tag")));
TH1F ch_tag_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("ch_tag")));
TH1F *ch_tag_9_4_7 = new TH1F(ch_tag_9_4_7_1);
ch_tag_9_4_7->Add(&ch_tag_9_4_7_2);
ch_tag_9_4_7->Add(&ch_tag_9_4_7_3);
ch_tag_9_4_7->Add(&ch_tag_9_4_7_4);
ch_tag_9_4_7->Add(&ch_tag_9_4_7_5);

ch_tag_9_4_7->SetLineColor(kBlue);
ch_tag_9_4_7->SetTitle("ch_tag");

TH1F ch_tag_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("ch_tag")));
TH1F ch_tag_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("ch_tag")));
TH1F ch_tag_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("ch_tag")));
TH1F ch_tag_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("ch_tag")));
TH1F ch_tag_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("ch_tag")));
TH1F *ch_tag_10_6_2 = new TH1F(ch_tag_10_6_2_1);
ch_tag_10_6_2->Add(&ch_tag_10_6_2_2);
ch_tag_10_6_2->Add(&ch_tag_10_6_2_3);
ch_tag_10_6_2->Add(&ch_tag_10_6_2_4);
ch_tag_10_6_2->Add(&ch_tag_10_6_2_5);

ch_tag_10_6_2->SetLineColor(kRed);

ch_tag_9_4_7->Draw("hist");
ch_tag_10_6_2->Draw("hist same");

auto legend = new TLegend(0.1,0.75,0.35,0.9);
legend->SetMargin(0.2);
legend->AddEntry(ch_tag_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(ch_tag_9_4_7,"CMSSW_9_4_7","l");
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/ch_tag.png");

TH1F evt_count_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("evt_count")));
TH1F evt_count_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("evt_count")));
TH1F evt_count_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("evt_count")));
TH1F evt_count_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("evt_count")));
TH1F evt_count_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("evt_count")));
TH1F *evt_count_9_4_7 = new TH1F(evt_count_9_4_7_1);
evt_count_9_4_7->Add(&evt_count_9_4_7_2);
evt_count_9_4_7->Add(&evt_count_9_4_7_3);
evt_count_9_4_7->Add(&evt_count_9_4_7_4);
evt_count_9_4_7->Add(&evt_count_9_4_7_5);

evt_count_9_4_7->SetLineColor(kBlue);
evt_count_9_4_7->SetTitle("evt_count");

TH1F evt_count_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("evt_count")));
TH1F evt_count_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("evt_count")));
TH1F evt_count_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("evt_count")));
TH1F evt_count_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("evt_count")));
TH1F evt_count_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("evt_count")));
TH1F *evt_count_10_6_2 = new TH1F(evt_count_10_6_2_1);
evt_count_10_6_2->Add(&evt_count_10_6_2_2);
evt_count_10_6_2->Add(&evt_count_10_6_2_3);
evt_count_10_6_2->Add(&evt_count_10_6_2_4);
evt_count_10_6_2->Add(&evt_count_10_6_2_5);

evt_count_10_6_2->SetLineColor(kRed);

evt_count_9_4_7->Draw("hist");
evt_count_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(evt_count_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(evt_count_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/evt_count.png");

TH1F ht_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("ht")));
TH1F ht_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("ht")));
TH1F ht_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("ht")));
TH1F ht_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("ht")));
TH1F ht_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("ht")));
TH1F *ht_9_4_7 = new TH1F(ht_9_4_7_1);
ht_9_4_7->Add(&ht_9_4_7_2);
ht_9_4_7->Add(&ht_9_4_7_3);
ht_9_4_7->Add(&ht_9_4_7_4);
ht_9_4_7->Add(&ht_9_4_7_5);

ht_9_4_7->SetLineColor(kBlue);
ht_9_4_7->SetTitle("ht");

TH1F ht_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("ht")));
TH1F ht_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("ht")));
TH1F ht_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("ht")));
TH1F ht_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("ht")));
TH1F ht_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("ht")));
TH1F *ht_10_6_2 = new TH1F(ht_10_6_2_1);
ht_10_6_2->Add(&ht_10_6_2_2);
ht_10_6_2->Add(&ht_10_6_2_3);
ht_10_6_2->Add(&ht_10_6_2_4);
ht_10_6_2->Add(&ht_10_6_2_5);

ht_10_6_2->SetLineColor(kRed);

ht_9_4_7->Draw("hist");
ht_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(ht_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(ht_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/ht.png");

TH1F mt_res_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("mt_res")));
TH1F mt_res_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("mt_res")));
TH1F mt_res_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("mt_res")));
TH1F mt_res_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("mt_res")));
TH1F mt_res_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("mt_res")));
TH1F *mt_res_9_4_7 = new TH1F(mt_res_9_4_7_1);
mt_res_9_4_7->Add(&mt_res_9_4_7_2);
mt_res_9_4_7->Add(&mt_res_9_4_7_3);
mt_res_9_4_7->Add(&mt_res_9_4_7_4);
mt_res_9_4_7->Add(&mt_res_9_4_7_5);

mt_res_9_4_7->SetLineColor(kBlue);
mt_res_9_4_7->SetTitle("mt_res");

TH1F mt_res_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("mt_res")));
TH1F mt_res_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("mt_res")));
TH1F mt_res_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("mt_res")));
TH1F mt_res_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("mt_res")));
TH1F mt_res_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("mt_res")));
TH1F *mt_res_10_6_2 = new TH1F(mt_res_10_6_2_1);
mt_res_10_6_2->Add(&mt_res_10_6_2_2);
mt_res_10_6_2->Add(&mt_res_10_6_2_3);
mt_res_10_6_2->Add(&mt_res_10_6_2_4);
mt_res_10_6_2->Add(&mt_res_10_6_2_5);

mt_res_10_6_2->SetLineColor(kRed);

mt_res_9_4_7->Draw("hist");
mt_res_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(mt_res_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(mt_res_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/mt_res.png");

TH1F mtbar_res_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("mtbar_res")));
TH1F mtbar_res_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("mtbar_res")));
TH1F mtbar_res_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("mtbar_res")));
TH1F mtbar_res_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("mtbar_res")));
TH1F mtbar_res_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("mtbar_res")));
TH1F *mtbar_res_9_4_7 = new TH1F(mtbar_res_9_4_7_1);
mtbar_res_9_4_7->Add(&mtbar_res_9_4_7_2);
mtbar_res_9_4_7->Add(&mtbar_res_9_4_7_3);
mtbar_res_9_4_7->Add(&mtbar_res_9_4_7_4);
mtbar_res_9_4_7->Add(&mtbar_res_9_4_7_5);

mtbar_res_9_4_7->SetLineColor(kBlue);
mtbar_res_9_4_7->SetTitle("mtbar_res");

TH1F mtbar_res_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("mtbar_res")));
TH1F mtbar_res_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("mtbar_res")));
TH1F mtbar_res_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("mtbar_res")));
TH1F mtbar_res_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("mtbar_res")));
TH1F mtbar_res_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("mtbar_res")));
TH1F *mtbar_res_10_6_2 = new TH1F(mtbar_res_10_6_2_1);
mtbar_res_10_6_2->Add(&mtbar_res_10_6_2_2);
mtbar_res_10_6_2->Add(&mtbar_res_10_6_2_3);
mtbar_res_10_6_2->Add(&mtbar_res_10_6_2_4);
mtbar_res_10_6_2->Add(&mtbar_res_10_6_2_5);

mtbar_res_10_6_2->SetLineColor(kRed);

mtbar_res_9_4_7->Draw("hist");
mtbar_res_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(mtbar_res_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(mtbar_res_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/mtbar_res.png");

TH1F mtop_res_hadronic_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("mtop_res_hadronic")));
TH1F mtop_res_hadronic_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("mtop_res_hadronic")));
TH1F mtop_res_hadronic_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("mtop_res_hadronic")));
TH1F mtop_res_hadronic_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("mtop_res_hadronic")));
TH1F mtop_res_hadronic_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("mtop_res_hadronic")));
TH1F *mtop_res_hadronic_9_4_7 = new TH1F(mtop_res_hadronic_9_4_7_1);
mtop_res_hadronic_9_4_7->Add(&mtop_res_hadronic_9_4_7_2);
mtop_res_hadronic_9_4_7->Add(&mtop_res_hadronic_9_4_7_3);
mtop_res_hadronic_9_4_7->Add(&mtop_res_hadronic_9_4_7_4);
mtop_res_hadronic_9_4_7->Add(&mtop_res_hadronic_9_4_7_5);

mtop_res_hadronic_9_4_7->SetLineColor(kBlue);
mtop_res_hadronic_9_4_7->SetTitle("mtop_res_hadronic");

TH1F mtop_res_hadronic_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("mtop_res_hadronic")));
TH1F mtop_res_hadronic_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("mtop_res_hadronic")));
TH1F mtop_res_hadronic_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("mtop_res_hadronic")));
TH1F mtop_res_hadronic_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("mtop_res_hadronic")));
TH1F mtop_res_hadronic_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("mtop_res_hadronic")));
TH1F *mtop_res_hadronic_10_6_2 = new TH1F(mtop_res_hadronic_10_6_2_1);
mtop_res_hadronic_10_6_2->Add(&mtop_res_hadronic_10_6_2_2);
mtop_res_hadronic_10_6_2->Add(&mtop_res_hadronic_10_6_2_3);
mtop_res_hadronic_10_6_2->Add(&mtop_res_hadronic_10_6_2_4);
mtop_res_hadronic_10_6_2->Add(&mtop_res_hadronic_10_6_2_5);

mtop_res_hadronic_10_6_2->SetLineColor(kRed);

mtop_res_hadronic_9_4_7->Draw("hist");
mtop_res_hadronic_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(mtop_res_hadronic_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(mtop_res_hadronic_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/mtop_res_hadronic.png");

TH1F mtop_res_leptonic_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("mtop_res_leptonic")));
TH1F mtop_res_leptonic_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("mtop_res_leptonic")));
TH1F mtop_res_leptonic_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("mtop_res_leptonic")));
TH1F mtop_res_leptonic_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("mtop_res_leptonic")));
TH1F mtop_res_leptonic_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("mtop_res_leptonic")));
TH1F *mtop_res_leptonic_9_4_7 = new TH1F(mtop_res_leptonic_9_4_7_1);
mtop_res_leptonic_9_4_7->Add(&mtop_res_leptonic_9_4_7_2);
mtop_res_leptonic_9_4_7->Add(&mtop_res_leptonic_9_4_7_3);
mtop_res_leptonic_9_4_7->Add(&mtop_res_leptonic_9_4_7_4);
mtop_res_leptonic_9_4_7->Add(&mtop_res_leptonic_9_4_7_5);

mtop_res_leptonic_9_4_7->SetLineColor(kBlue);
mtop_res_leptonic_9_4_7->SetTitle("mtop_res_leptonic");

TH1F mtop_res_leptonic_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("mtop_res_leptonic")));
TH1F mtop_res_leptonic_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("mtop_res_leptonic")));
TH1F mtop_res_leptonic_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("mtop_res_leptonic")));
TH1F mtop_res_leptonic_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("mtop_res_leptonic")));
TH1F mtop_res_leptonic_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("mtop_res_leptonic")));
TH1F *mtop_res_leptonic_10_6_2 = new TH1F(mtop_res_leptonic_10_6_2_1);
mtop_res_leptonic_10_6_2->Add(&mtop_res_leptonic_10_6_2_2);
mtop_res_leptonic_10_6_2->Add(&mtop_res_leptonic_10_6_2_3);
mtop_res_leptonic_10_6_2->Add(&mtop_res_leptonic_10_6_2_4);
mtop_res_leptonic_10_6_2->Add(&mtop_res_leptonic_10_6_2_5);

mtop_res_leptonic_10_6_2->SetLineColor(kRed);

mtop_res_leptonic_9_4_7->Draw("hist");
mtop_res_leptonic_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(mtop_res_leptonic_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(mtop_res_leptonic_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/mtop_res_leptonic.png");

TH1F mttbar_gen_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("mttbar_gen")));
TH1F mttbar_gen_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("mttbar_gen")));
TH1F mttbar_gen_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("mttbar_gen")));
TH1F mttbar_gen_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("mttbar_gen")));
TH1F mttbar_gen_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("mttbar_gen")));
TH1F *mttbar_gen_9_4_7 = new TH1F(mttbar_gen_9_4_7_1);
mttbar_gen_9_4_7->Add(&mttbar_gen_9_4_7_2);
mttbar_gen_9_4_7->Add(&mttbar_gen_9_4_7_3);
mttbar_gen_9_4_7->Add(&mttbar_gen_9_4_7_4);
mttbar_gen_9_4_7->Add(&mttbar_gen_9_4_7_5);

mttbar_gen_9_4_7->SetLineColor(kBlue);
mttbar_gen_9_4_7->SetTitle("mttbar_gen");

TH1F mttbar_gen_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("mttbar_gen")));
TH1F mttbar_gen_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("mttbar_gen")));
TH1F mttbar_gen_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("mttbar_gen")));
TH1F mttbar_gen_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("mttbar_gen")));
TH1F mttbar_gen_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("mttbar_gen")));
TH1F *mttbar_gen_10_6_2 = new TH1F(mttbar_gen_10_6_2_1);
mttbar_gen_10_6_2->Add(&mttbar_gen_10_6_2_2);
mttbar_gen_10_6_2->Add(&mttbar_gen_10_6_2_3);
mttbar_gen_10_6_2->Add(&mttbar_gen_10_6_2_4);
mttbar_gen_10_6_2->Add(&mttbar_gen_10_6_2_5);

mttbar_gen_10_6_2->SetLineColor(kRed);

mttbar_gen_9_4_7->Draw("hist");
mttbar_gen_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(mttbar_gen_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(mttbar_gen_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/mttbar_gen.png");

TH1F mttbar_res_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("mttbar_res")));
TH1F mttbar_res_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("mttbar_res")));
TH1F mttbar_res_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("mttbar_res")));
TH1F mttbar_res_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("mttbar_res")));
TH1F mttbar_res_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("mttbar_res")));
TH1F *mttbar_res_9_4_7 = new TH1F(mttbar_res_9_4_7_1);
mttbar_res_9_4_7->Add(&mttbar_res_9_4_7_2);
mttbar_res_9_4_7->Add(&mttbar_res_9_4_7_3);
mttbar_res_9_4_7->Add(&mttbar_res_9_4_7_4);
mttbar_res_9_4_7->Add(&mttbar_res_9_4_7_5);

mttbar_res_9_4_7->SetLineColor(kBlue);
mttbar_res_9_4_7->SetTitle("mttbar_res");

TH1F mttbar_res_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("mttbar_res")));
TH1F mttbar_res_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("mttbar_res")));
TH1F mttbar_res_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("mttbar_res")));
TH1F mttbar_res_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("mttbar_res")));
TH1F mttbar_res_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("mttbar_res")));
TH1F *mttbar_res_10_6_2 = new TH1F(mttbar_res_10_6_2_1);
mttbar_res_10_6_2->Add(&mttbar_res_10_6_2_2);
mttbar_res_10_6_2->Add(&mttbar_res_10_6_2_3);
mttbar_res_10_6_2->Add(&mttbar_res_10_6_2_4);
mttbar_res_10_6_2->Add(&mttbar_res_10_6_2_5);

mttbar_res_10_6_2->SetLineColor(kRed);

mttbar_res_9_4_7->Draw("hist");
mttbar_res_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(mttbar_res_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(mttbar_res_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/mttbar_res.png");

TH1F mttbar_rec_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("mttbar_rec")));
TH1F mttbar_rec_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("mttbar_rec")));
TH1F mttbar_rec_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("mttbar_rec")));
TH1F mttbar_rec_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("mttbar_rec")));
TH1F mttbar_rec_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("mttbar_rec")));
TH1F *mttbar_rec_9_4_7 = new TH1F(mttbar_rec_9_4_7_1);
mttbar_rec_9_4_7->Add(&mttbar_rec_9_4_7_2);
mttbar_rec_9_4_7->Add(&mttbar_rec_9_4_7_3);
mttbar_rec_9_4_7->Add(&mttbar_rec_9_4_7_4);
mttbar_rec_9_4_7->Add(&mttbar_rec_9_4_7_5);

mttbar_rec_9_4_7->SetLineColor(kBlue);
mttbar_rec_9_4_7->SetTitle("mttbar_rec");

TH1F mttbar_rec_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("mttbar_rec")));
TH1F mttbar_rec_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("mttbar_rec")));
TH1F mttbar_rec_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("mttbar_rec")));
TH1F mttbar_rec_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("mttbar_rec")));
TH1F mttbar_rec_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("mttbar_rec")));
TH1F *mttbar_rec_10_6_2 = new TH1F(mttbar_rec_10_6_2_1);
mttbar_rec_10_6_2->Add(&mttbar_rec_10_6_2_2);
mttbar_rec_10_6_2->Add(&mttbar_rec_10_6_2_3);
mttbar_rec_10_6_2->Add(&mttbar_rec_10_6_2_4);
mttbar_rec_10_6_2->Add(&mttbar_rec_10_6_2_5);

mttbar_rec_10_6_2->SetLineColor(kRed);

mttbar_rec_9_4_7->Draw("hist");
mttbar_rec_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(mttbar_rec_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(mttbar_rec_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/mttbar_rec.png");

TH1F nbjets_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("nbjets")));
TH1F nbjets_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("nbjets")));
TH1F nbjets_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("nbjets")));
TH1F nbjets_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("nbjets")));
TH1F nbjets_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("nbjets")));
TH1F *nbjets_9_4_7 = new TH1F(nbjets_9_4_7_1);
nbjets_9_4_7->Add(&nbjets_9_4_7_2);
nbjets_9_4_7->Add(&nbjets_9_4_7_3);
nbjets_9_4_7->Add(&nbjets_9_4_7_4);
nbjets_9_4_7->Add(&nbjets_9_4_7_5);

nbjets_9_4_7->SetLineColor(kBlue);
nbjets_9_4_7->SetTitle("nbjets");

TH1F nbjets_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("nbjets")));
TH1F nbjets_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("nbjets")));
TH1F nbjets_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("nbjets")));
TH1F nbjets_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("nbjets")));
TH1F nbjets_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("nbjets")));
TH1F *nbjets_10_6_2 = new TH1F(nbjets_10_6_2_1);
nbjets_10_6_2->Add(&nbjets_10_6_2_2);
nbjets_10_6_2->Add(&nbjets_10_6_2_3);
nbjets_10_6_2->Add(&nbjets_10_6_2_4);
nbjets_10_6_2->Add(&nbjets_10_6_2_5);

nbjets_10_6_2->SetLineColor(kRed);

nbjets_9_4_7->Draw("hist");
nbjets_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(nbjets_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(nbjets_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/nbjets.png");

TH1F njets_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("njets")));
TH1F njets_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("njets")));
TH1F njets_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("njets")));
TH1F njets_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("njets")));
TH1F njets_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("njets")));
TH1F *njets_9_4_7 = new TH1F(njets_9_4_7_1);
njets_9_4_7->Add(&njets_9_4_7_2);
njets_9_4_7->Add(&njets_9_4_7_3);
njets_9_4_7->Add(&njets_9_4_7_4);
njets_9_4_7->Add(&njets_9_4_7_5);

njets_9_4_7->SetLineColor(kBlue);
njets_9_4_7->SetTitle("njets");

TH1F njets_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("njets")));
TH1F njets_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("njets")));
TH1F njets_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("njets")));
TH1F njets_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("njets")));
TH1F njets_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("njets")));
TH1F *njets_10_6_2 = new TH1F(njets_10_6_2_1);
njets_10_6_2->Add(&njets_10_6_2_2);
njets_10_6_2->Add(&njets_10_6_2_3);
njets_10_6_2->Add(&njets_10_6_2_4);
njets_10_6_2->Add(&njets_10_6_2_5);

njets_10_6_2->SetLineColor(kRed);

njets_9_4_7->Draw("hist");
njets_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(njets_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(njets_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/njets.png");

TH1F nvtx_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("nvtx")));
TH1F nvtx_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("nvtx")));
TH1F nvtx_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("nvtx")));
TH1F nvtx_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("nvtx")));
TH1F nvtx_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("nvtx")));
TH1F *nvtx_9_4_7 = new TH1F(nvtx_9_4_7_1);
nvtx_9_4_7->Add(&nvtx_9_4_7_2);
nvtx_9_4_7->Add(&nvtx_9_4_7_3);
nvtx_9_4_7->Add(&nvtx_9_4_7_4);
nvtx_9_4_7->Add(&nvtx_9_4_7_5);

nvtx_9_4_7->SetLineColor(kBlue);
nvtx_9_4_7->SetTitle("nvtx");

TH1F nvtx_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("nvtx")));
TH1F nvtx_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("nvtx")));
TH1F nvtx_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("nvtx")));
TH1F nvtx_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("nvtx")));
TH1F nvtx_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("nvtx")));
TH1F *nvtx_10_6_2 = new TH1F(nvtx_10_6_2_1);
nvtx_10_6_2->Add(&nvtx_10_6_2_2);
nvtx_10_6_2->Add(&nvtx_10_6_2_3);
nvtx_10_6_2->Add(&nvtx_10_6_2_4);
nvtx_10_6_2->Add(&nvtx_10_6_2_5);

nvtx_10_6_2->SetLineColor(kRed);

nvtx_9_4_7->Draw("hist");
nvtx_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(nvtx_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(nvtx_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/nvtx.png");

TH1F ptt_res_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("ptt_res")));
TH1F ptt_res_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("ptt_res")));
TH1F ptt_res_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("ptt_res")));
TH1F ptt_res_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("ptt_res")));
TH1F ptt_res_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("ptt_res")));
TH1F *ptt_res_9_4_7 = new TH1F(ptt_res_9_4_7_1);
ptt_res_9_4_7->Add(&ptt_res_9_4_7_2);
ptt_res_9_4_7->Add(&ptt_res_9_4_7_3);
ptt_res_9_4_7->Add(&ptt_res_9_4_7_4);
ptt_res_9_4_7->Add(&ptt_res_9_4_7_5);

ptt_res_9_4_7->SetLineColor(kBlue);
ptt_res_9_4_7->SetTitle("ptt_res");

TH1F ptt_res_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("ptt_res")));
TH1F ptt_res_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("ptt_res")));
TH1F ptt_res_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("ptt_res")));
TH1F ptt_res_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("ptt_res")));
TH1F ptt_res_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("ptt_res")));
TH1F *ptt_res_10_6_2 = new TH1F(ptt_res_10_6_2_1);
ptt_res_10_6_2->Add(&ptt_res_10_6_2_2);
ptt_res_10_6_2->Add(&ptt_res_10_6_2_3);
ptt_res_10_6_2->Add(&ptt_res_10_6_2_4);
ptt_res_10_6_2->Add(&ptt_res_10_6_2_5);

ptt_res_10_6_2->SetLineColor(kRed);

ptt_res_9_4_7->Draw("hist");
ptt_res_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(ptt_res_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(ptt_res_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/ptt_res.png");

TH1F pttop_res_hadronic_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("pttop_res_hadronic")));
TH1F pttop_res_hadronic_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("pttop_res_hadronic")));
TH1F pttop_res_hadronic_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("pttop_res_hadronic")));
TH1F pttop_res_hadronic_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("pttop_res_hadronic")));
TH1F pttop_res_hadronic_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("pttop_res_hadronic")));
TH1F *pttop_res_hadronic_9_4_7 = new TH1F(pttop_res_hadronic_9_4_7_1);
pttop_res_hadronic_9_4_7->Add(&pttop_res_hadronic_9_4_7_2);
pttop_res_hadronic_9_4_7->Add(&pttop_res_hadronic_9_4_7_3);
pttop_res_hadronic_9_4_7->Add(&pttop_res_hadronic_9_4_7_4);
pttop_res_hadronic_9_4_7->Add(&pttop_res_hadronic_9_4_7_5);

pttop_res_hadronic_9_4_7->SetLineColor(kBlue);
pttop_res_hadronic_9_4_7->SetTitle("pttop_res_hadronic");

TH1F pttop_res_hadronic_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("pttop_res_hadronic")));
TH1F pttop_res_hadronic_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("pttop_res_hadronic")));
TH1F pttop_res_hadronic_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("pttop_res_hadronic")));
TH1F pttop_res_hadronic_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("pttop_res_hadronic")));
TH1F pttop_res_hadronic_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("pttop_res_hadronic")));
TH1F *pttop_res_hadronic_10_6_2 = new TH1F(pttop_res_hadronic_10_6_2_1);
pttop_res_hadronic_10_6_2->Add(&pttop_res_hadronic_10_6_2_2);
pttop_res_hadronic_10_6_2->Add(&pttop_res_hadronic_10_6_2_3);
pttop_res_hadronic_10_6_2->Add(&pttop_res_hadronic_10_6_2_4);
pttop_res_hadronic_10_6_2->Add(&pttop_res_hadronic_10_6_2_5);

pttop_res_hadronic_10_6_2->SetLineColor(kRed);

pttop_res_hadronic_9_4_7->Draw("hist");
pttop_res_hadronic_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(pttop_res_hadronic_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(pttop_res_hadronic_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/pttop_res_hadronic.png");

TH1F pttop_res_leptonic_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("pttop_res_leptonic")));
TH1F pttop_res_leptonic_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("pttop_res_leptonic")));
TH1F pttop_res_leptonic_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("pttop_res_leptonic")));
TH1F pttop_res_leptonic_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("pttop_res_leptonic")));
TH1F pttop_res_leptonic_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("pttop_res_leptonic")));
TH1F *pttop_res_leptonic_9_4_7 = new TH1F(pttop_res_leptonic_9_4_7_1);
pttop_res_leptonic_9_4_7->Add(&pttop_res_leptonic_9_4_7_2);
pttop_res_leptonic_9_4_7->Add(&pttop_res_leptonic_9_4_7_3);
pttop_res_leptonic_9_4_7->Add(&pttop_res_leptonic_9_4_7_4);
pttop_res_leptonic_9_4_7->Add(&pttop_res_leptonic_9_4_7_5);

pttop_res_leptonic_9_4_7->SetLineColor(kBlue);
pttop_res_leptonic_9_4_7->SetTitle("pttop_res_leptonic");

TH1F pttop_res_leptonic_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("pttop_res_leptonic")));
TH1F pttop_res_leptonic_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("pttop_res_leptonic")));
TH1F pttop_res_leptonic_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("pttop_res_leptonic")));
TH1F pttop_res_leptonic_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("pttop_res_leptonic")));
TH1F pttop_res_leptonic_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("pttop_res_leptonic")));
TH1F *pttop_res_leptonic_10_6_2 = new TH1F(pttop_res_leptonic_10_6_2_1);
pttop_res_leptonic_10_6_2->Add(&pttop_res_leptonic_10_6_2_2);
pttop_res_leptonic_10_6_2->Add(&pttop_res_leptonic_10_6_2_3);
pttop_res_leptonic_10_6_2->Add(&pttop_res_leptonic_10_6_2_4);
pttop_res_leptonic_10_6_2->Add(&pttop_res_leptonic_10_6_2_5);

pttop_res_leptonic_10_6_2->SetLineColor(kRed);

pttop_res_leptonic_9_4_7->Draw("hist");
pttop_res_leptonic_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(pttop_res_leptonic_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(pttop_res_leptonic_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/pttop_res_leptonic.png");

TH1F ptttbar_gen_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("ptttbar_gen")));
TH1F ptttbar_gen_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("ptttbar_gen")));
TH1F ptttbar_gen_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("ptttbar_gen")));
TH1F ptttbar_gen_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("ptttbar_gen")));
TH1F ptttbar_gen_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("ptttbar_gen")));
TH1F *ptttbar_gen_9_4_7 = new TH1F(ptttbar_gen_9_4_7_1);
ptttbar_gen_9_4_7->Add(&ptttbar_gen_9_4_7_2);
ptttbar_gen_9_4_7->Add(&ptttbar_gen_9_4_7_3);
ptttbar_gen_9_4_7->Add(&ptttbar_gen_9_4_7_4);
ptttbar_gen_9_4_7->Add(&ptttbar_gen_9_4_7_5);

ptttbar_gen_9_4_7->SetLineColor(kBlue);
ptttbar_gen_9_4_7->SetTitle("ptttbar_gen");

TH1F ptttbar_gen_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("ptttbar_gen")));
TH1F ptttbar_gen_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("ptttbar_gen")));
TH1F ptttbar_gen_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("ptttbar_gen")));
TH1F ptttbar_gen_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("ptttbar_gen")));
TH1F ptttbar_gen_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("ptttbar_gen")));
TH1F *ptttbar_gen_10_6_2 = new TH1F(ptttbar_gen_10_6_2_1);
ptttbar_gen_10_6_2->Add(&ptttbar_gen_10_6_2_2);
ptttbar_gen_10_6_2->Add(&ptttbar_gen_10_6_2_3);
ptttbar_gen_10_6_2->Add(&ptttbar_gen_10_6_2_4);
ptttbar_gen_10_6_2->Add(&ptttbar_gen_10_6_2_5);

ptttbar_gen_10_6_2->SetLineColor(kRed);

ptttbar_gen_9_4_7->Draw("hist");
ptttbar_gen_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(ptttbar_gen_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(ptttbar_gen_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/ptttbar_gen.png");

TH1F ptttbar_rec_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("ptttbar_rec")));
TH1F ptttbar_rec_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("ptttbar_rec")));
TH1F ptttbar_rec_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("ptttbar_rec")));
TH1F ptttbar_rec_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("ptttbar_rec")));
TH1F ptttbar_rec_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("ptttbar_rec")));
TH1F *ptttbar_rec_9_4_7 = new TH1F(ptttbar_rec_9_4_7_1);
ptttbar_rec_9_4_7->Add(&ptttbar_rec_9_4_7_2);
ptttbar_rec_9_4_7->Add(&ptttbar_rec_9_4_7_3);
ptttbar_rec_9_4_7->Add(&ptttbar_rec_9_4_7_4);
ptttbar_rec_9_4_7->Add(&ptttbar_rec_9_4_7_5);

ptttbar_rec_9_4_7->SetLineColor(kBlue);
ptttbar_rec_9_4_7->SetTitle("ptttbar_rec");

TH1F ptttbar_rec_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("ptttbar_rec")));
TH1F ptttbar_rec_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("ptttbar_rec")));
TH1F ptttbar_rec_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("ptttbar_rec")));
TH1F ptttbar_rec_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("ptttbar_rec")));
TH1F ptttbar_rec_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("ptttbar_rec")));
TH1F *ptttbar_rec_10_6_2 = new TH1F(ptttbar_rec_10_6_2_1);
ptttbar_rec_10_6_2->Add(&ptttbar_rec_10_6_2_2);
ptttbar_rec_10_6_2->Add(&ptttbar_rec_10_6_2_3);
ptttbar_rec_10_6_2->Add(&ptttbar_rec_10_6_2_4);
ptttbar_rec_10_6_2->Add(&ptttbar_rec_10_6_2_5);

ptttbar_rec_10_6_2->SetLineColor(kRed);

ptttbar_rec_9_4_7->Draw("hist");
ptttbar_rec_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(ptttbar_rec_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(ptttbar_rec_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/ptttbar_rec.png");

TH1F ptttbar_res_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("ptttbar_res")));
TH1F ptttbar_res_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("ptttbar_res")));
TH1F ptttbar_res_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("ptttbar_res")));
TH1F ptttbar_res_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("ptttbar_res")));
TH1F ptttbar_res_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("ptttbar_res")));
TH1F *ptttbar_res_9_4_7 = new TH1F(ptttbar_res_9_4_7_1);
ptttbar_res_9_4_7->Add(&ptttbar_res_9_4_7_2);
ptttbar_res_9_4_7->Add(&ptttbar_res_9_4_7_3);
ptttbar_res_9_4_7->Add(&ptttbar_res_9_4_7_4);
ptttbar_res_9_4_7->Add(&ptttbar_res_9_4_7_5);

ptttbar_res_9_4_7->SetLineColor(kBlue);
ptttbar_res_9_4_7->SetTitle("ptttbar_res");

TH1F ptttbar_res_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("ptttbar_res")));
TH1F ptttbar_res_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("ptttbar_res")));
TH1F ptttbar_res_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("ptttbar_res")));
TH1F ptttbar_res_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("ptttbar_res")));
TH1F ptttbar_res_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("ptttbar_res")));
TH1F *ptttbar_res_10_6_2 = new TH1F(ptttbar_res_10_6_2_1);
ptttbar_res_10_6_2->Add(&ptttbar_res_10_6_2_2);
ptttbar_res_10_6_2->Add(&ptttbar_res_10_6_2_3);
ptttbar_res_10_6_2->Add(&ptttbar_res_10_6_2_4);
ptttbar_res_10_6_2->Add(&ptttbar_res_10_6_2_5);

ptttbar_res_10_6_2->SetLineColor(kRed);

ptttbar_res_9_4_7->Draw("hist");
ptttbar_res_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(ptttbar_res_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(ptttbar_res_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/ptttbar_res.png");

TH1F puwgtctr_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("puwgtctr")));
TH1F puwgtctr_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("puwgtctr")));
TH1F puwgtctr_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("puwgtctr")));
TH1F puwgtctr_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("puwgtctr")));
TH1F puwgtctr_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("puwgtctr")));
TH1F *puwgtctr_9_4_7 = new TH1F(puwgtctr_9_4_7_1);
puwgtctr_9_4_7->Add(&puwgtctr_9_4_7_2);
puwgtctr_9_4_7->Add(&puwgtctr_9_4_7_3);
puwgtctr_9_4_7->Add(&puwgtctr_9_4_7_4);
puwgtctr_9_4_7->Add(&puwgtctr_9_4_7_5);

puwgtctr_9_4_7->SetLineColor(kBlue);
puwgtctr_9_4_7->SetTitle("puwgtctr");

TH1F puwgtctr_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("puwgtctr")));
TH1F puwgtctr_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("puwgtctr")));
TH1F puwgtctr_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("puwgtctr")));
TH1F puwgtctr_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("puwgtctr")));
TH1F puwgtctr_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("puwgtctr")));
TH1F *puwgtctr_10_6_2 = new TH1F(puwgtctr_10_6_2_1);
puwgtctr_10_6_2->Add(&puwgtctr_10_6_2_2);
puwgtctr_10_6_2->Add(&puwgtctr_10_6_2_3);
puwgtctr_10_6_2->Add(&puwgtctr_10_6_2_4);
puwgtctr_10_6_2->Add(&puwgtctr_10_6_2_5);

puwgtctr_10_6_2->SetLineColor(kRed);

puwgtctr_9_4_7->Draw("hist");
puwgtctr_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(puwgtctr_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(puwgtctr_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/puwgtctr.png");

TH1F yt_res_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("yt_res")));
TH1F yt_res_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("yt_res")));
TH1F yt_res_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("yt_res")));
TH1F yt_res_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("yt_res")));
TH1F yt_res_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("yt_res")));
TH1F *yt_res_9_4_7 = new TH1F(yt_res_9_4_7_1);
yt_res_9_4_7->Add(&yt_res_9_4_7_2);
yt_res_9_4_7->Add(&yt_res_9_4_7_3);
yt_res_9_4_7->Add(&yt_res_9_4_7_4);
yt_res_9_4_7->Add(&yt_res_9_4_7_5);

yt_res_9_4_7->SetLineColor(kBlue);
yt_res_9_4_7->SetTitle("yt_res");

TH1F yt_res_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("yt_res")));
TH1F yt_res_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("yt_res")));
TH1F yt_res_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("yt_res")));
TH1F yt_res_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("yt_res")));
TH1F yt_res_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("yt_res")));
TH1F *yt_res_10_6_2 = new TH1F(yt_res_10_6_2_1);
yt_res_10_6_2->Add(&yt_res_10_6_2_2);
yt_res_10_6_2->Add(&yt_res_10_6_2_3);
yt_res_10_6_2->Add(&yt_res_10_6_2_4);
yt_res_10_6_2->Add(&yt_res_10_6_2_5);

yt_res_10_6_2->SetLineColor(kRed);

yt_res_9_4_7->Draw("hist");
yt_res_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(yt_res_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(yt_res_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/yt_res.png");

TH1F ytbar_res_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("ytbar_res")));
TH1F ytbar_res_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("ytbar_res")));
TH1F ytbar_res_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("ytbar_res")));
TH1F ytbar_res_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("ytbar_res")));
TH1F ytbar_res_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("ytbar_res")));
TH1F *ytbar_res_9_4_7 = new TH1F(ytbar_res_9_4_7_1);
ytbar_res_9_4_7->Add(&ytbar_res_9_4_7_2);
ytbar_res_9_4_7->Add(&ytbar_res_9_4_7_3);
ytbar_res_9_4_7->Add(&ytbar_res_9_4_7_4);
ytbar_res_9_4_7->Add(&ytbar_res_9_4_7_5);

ytbar_res_9_4_7->SetLineColor(kBlue);
ytbar_res_9_4_7->SetTitle("ytbar_res");

TH1F ytbar_res_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("ytbar_res")));
TH1F ytbar_res_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("ytbar_res")));
TH1F ytbar_res_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("ytbar_res")));
TH1F ytbar_res_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("ytbar_res")));
TH1F ytbar_res_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("ytbar_res")));
TH1F *ytbar_res_10_6_2 = new TH1F(ytbar_res_10_6_2_1);
ytbar_res_10_6_2->Add(&ytbar_res_10_6_2_2);
ytbar_res_10_6_2->Add(&ytbar_res_10_6_2_3);
ytbar_res_10_6_2->Add(&ytbar_res_10_6_2_4);
ytbar_res_10_6_2->Add(&ytbar_res_10_6_2_5);

ytbar_res_10_6_2->SetLineColor(kRed);

ytbar_res_9_4_7->Draw("hist");
ytbar_res_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(ytbar_res_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(ytbar_res_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/ytbar_res.png");

TH1F ytop_res_hadronic_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("ytop_res_hadronic")));
TH1F ytop_res_hadronic_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("ytop_res_hadronic")));
TH1F ytop_res_hadronic_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("ytop_res_hadronic")));
TH1F ytop_res_hadronic_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("ytop_res_hadronic")));
TH1F ytop_res_hadronic_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("ytop_res_hadronic")));
TH1F *ytop_res_hadronic_9_4_7 = new TH1F(ytop_res_hadronic_9_4_7_1);
ytop_res_hadronic_9_4_7->Add(&ytop_res_hadronic_9_4_7_2);
ytop_res_hadronic_9_4_7->Add(&ytop_res_hadronic_9_4_7_3);
ytop_res_hadronic_9_4_7->Add(&ytop_res_hadronic_9_4_7_4);
ytop_res_hadronic_9_4_7->Add(&ytop_res_hadronic_9_4_7_5);

ytop_res_hadronic_9_4_7->SetLineColor(kBlue);
ytop_res_hadronic_9_4_7->SetTitle("ytop_res_hadronic");


TH1F ytop_res_hadronic_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("ytop_res_hadronic")));
TH1F ytop_res_hadronic_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("ytop_res_hadronic")));
TH1F ytop_res_hadronic_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("ytop_res_hadronic")));
TH1F ytop_res_hadronic_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("ytop_res_hadronic")));
TH1F ytop_res_hadronic_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("ytop_res_hadronic")));
TH1F *ytop_res_hadronic_10_6_2 = new TH1F(ytop_res_hadronic_10_6_2_1);
ytop_res_hadronic_10_6_2->Add(&ytop_res_hadronic_10_6_2_2);
ytop_res_hadronic_10_6_2->Add(&ytop_res_hadronic_10_6_2_3);
ytop_res_hadronic_10_6_2->Add(&ytop_res_hadronic_10_6_2_4);
ytop_res_hadronic_10_6_2->Add(&ytop_res_hadronic_10_6_2_5);

ytop_res_hadronic_10_6_2->SetLineColor(kRed);

ytop_res_hadronic_9_4_7->Draw("hist");
ytop_res_hadronic_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(ytop_res_hadronic_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(ytop_res_hadronic_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/ytop_res_hadronic.png");

TH1F ytop_res_leptonic_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("ytop_res_leptonic")));
TH1F ytop_res_leptonic_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("ytop_res_leptonic")));
TH1F ytop_res_leptonic_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("ytop_res_leptonic")));
TH1F ytop_res_leptonic_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("ytop_res_leptonic")));
TH1F ytop_res_leptonic_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("ytop_res_leptonic")));
TH1F *ytop_res_leptonic_9_4_7 = new TH1F(ytop_res_leptonic_9_4_7_1);
ytop_res_leptonic_9_4_7->Add(&ytop_res_leptonic_9_4_7_2);
ytop_res_leptonic_9_4_7->Add(&ytop_res_leptonic_9_4_7_3);
ytop_res_leptonic_9_4_7->Add(&ytop_res_leptonic_9_4_7_4);
ytop_res_leptonic_9_4_7->Add(&ytop_res_leptonic_9_4_7_5);

ytop_res_leptonic_9_4_7->SetLineColor(kBlue);
ytop_res_leptonic_9_4_7->SetTitle("ytop_res_leptonic");

TH1F ytop_res_leptonic_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("ytop_res_leptonic")));
TH1F ytop_res_leptonic_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("ytop_res_leptonic")));
TH1F ytop_res_leptonic_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("ytop_res_leptonic")));
TH1F ytop_res_leptonic_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("ytop_res_leptonic")));
TH1F ytop_res_leptonic_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("ytop_res_leptonic")));
TH1F *ytop_res_leptonic_10_6_2 = new TH1F(ytop_res_leptonic_10_6_2_1);
ytop_res_leptonic_10_6_2->Add(&ytop_res_leptonic_10_6_2_2);
ytop_res_leptonic_10_6_2->Add(&ytop_res_leptonic_10_6_2_3);
ytop_res_leptonic_10_6_2->Add(&ytop_res_leptonic_10_6_2_4);
ytop_res_leptonic_10_6_2->Add(&ytop_res_leptonic_10_6_2_5);

ytop_res_leptonic_10_6_2->SetLineColor(kRed);

ytop_res_leptonic_9_4_7->Draw("hist");
ytop_res_leptonic_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(ytop_res_leptonic_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(ytop_res_leptonic_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/ytop_res_leptonic.png");

TH1F yttbar_gen_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("yttbar_gen")));
TH1F yttbar_gen_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("yttbar_gen")));
TH1F yttbar_gen_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("yttbar_gen")));
TH1F yttbar_gen_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("yttbar_gen")));
TH1F yttbar_gen_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("yttbar_gen")));
TH1F *yttbar_gen_9_4_7 = new TH1F(yttbar_gen_9_4_7_1);
yttbar_gen_9_4_7->Add(&yttbar_gen_9_4_7_2);
yttbar_gen_9_4_7->Add(&yttbar_gen_9_4_7_3);
yttbar_gen_9_4_7->Add(&yttbar_gen_9_4_7_4);
yttbar_gen_9_4_7->Add(&yttbar_gen_9_4_7_5);

yttbar_gen_9_4_7->SetLineColor(kBlue);
yttbar_gen_9_4_7->SetTitle("yttbar_gen");

TH1F yttbar_gen_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("yttbar_gen")));
TH1F yttbar_gen_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("yttbar_gen")));
TH1F yttbar_gen_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("yttbar_gen")));
TH1F yttbar_gen_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("yttbar_gen")));
TH1F yttbar_gen_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("yttbar_gen")));
TH1F *yttbar_gen_10_6_2 = new TH1F(yttbar_gen_10_6_2_1);
yttbar_gen_10_6_2->Add(&yttbar_gen_10_6_2_2);
yttbar_gen_10_6_2->Add(&yttbar_gen_10_6_2_3);
yttbar_gen_10_6_2->Add(&yttbar_gen_10_6_2_4);
yttbar_gen_10_6_2->Add(&yttbar_gen_10_6_2_5);

yttbar_gen_10_6_2->SetLineColor(kRed);

yttbar_gen_9_4_7->Draw("hist");
yttbar_gen_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(yttbar_gen_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(yttbar_gen_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/yttbar_gen.png");

TH1F yttbar_rec_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("yttbar_rec")));
TH1F yttbar_rec_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("yttbar_rec")));
TH1F yttbar_rec_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("yttbar_rec")));
TH1F yttbar_rec_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("yttbar_rec")));
TH1F yttbar_rec_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("yttbar_rec")));
TH1F *yttbar_rec_9_4_7 = new TH1F(yttbar_rec_9_4_7_1);
yttbar_rec_9_4_7->Add(&yttbar_rec_9_4_7_2);
yttbar_rec_9_4_7->Add(&yttbar_rec_9_4_7_3);
yttbar_rec_9_4_7->Add(&yttbar_rec_9_4_7_4);
yttbar_rec_9_4_7->Add(&yttbar_rec_9_4_7_5);

yttbar_rec_9_4_7->SetLineColor(kBlue);
yttbar_rec_9_4_7->SetTitle("yttbar_rec");

TH1F yttbar_rec_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("yttbar_rec")));
TH1F yttbar_rec_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("yttbar_rec")));
TH1F yttbar_rec_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("yttbar_rec")));
TH1F yttbar_rec_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("yttbar_rec")));
TH1F yttbar_rec_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("yttbar_rec")));
TH1F *yttbar_rec_10_6_2 = new TH1F(yttbar_rec_10_6_2_1);
yttbar_rec_10_6_2->Add(&yttbar_rec_10_6_2_2);
yttbar_rec_10_6_2->Add(&yttbar_rec_10_6_2_3);
yttbar_rec_10_6_2->Add(&yttbar_rec_10_6_2_4);
yttbar_rec_10_6_2->Add(&yttbar_rec_10_6_2_5);

yttbar_rec_10_6_2->SetLineColor(kRed);

yttbar_rec_9_4_7->Draw("hist");
yttbar_rec_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(yttbar_rec_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(yttbar_rec_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/yttbar_rec.png");

TH1F yttbar_res_9_4_7_1 = TH1F(*((TH1F*)_file5->Get("yttbar_res")));
TH1F yttbar_res_9_4_7_2 = TH1F(*((TH1F*)_file6->Get("yttbar_res")));
TH1F yttbar_res_9_4_7_3 = TH1F(*((TH1F*)_file7->Get("yttbar_res")));
TH1F yttbar_res_9_4_7_4 = TH1F(*((TH1F*)_file8->Get("yttbar_res")));
TH1F yttbar_res_9_4_7_5 = TH1F(*((TH1F*)_file9->Get("yttbar_res")));
TH1F *yttbar_res_9_4_7 = new TH1F(yttbar_res_9_4_7_1);
yttbar_res_9_4_7->Add(&yttbar_res_9_4_7_2);
yttbar_res_9_4_7->Add(&yttbar_res_9_4_7_3);
yttbar_res_9_4_7->Add(&yttbar_res_9_4_7_4);
yttbar_res_9_4_7->Add(&yttbar_res_9_4_7_5);

yttbar_res_9_4_7->SetLineColor(kBlue);
yttbar_res_9_4_7->SetTitle("yttbar_res");

TH1F yttbar_res_10_6_2_1 = TH1F(*((TH1F*)_file0->Get("yttbar_res")));
TH1F yttbar_res_10_6_2_2 = TH1F(*((TH1F*)_file1->Get("yttbar_res")));
TH1F yttbar_res_10_6_2_3 = TH1F(*((TH1F*)_file2->Get("yttbar_res")));
TH1F yttbar_res_10_6_2_4 = TH1F(*((TH1F*)_file3->Get("yttbar_res")));
TH1F yttbar_res_10_6_2_5 = TH1F(*((TH1F*)_file4->Get("yttbar_res")));
TH1F *yttbar_res_10_6_2 = new TH1F(yttbar_res_10_6_2_1);
yttbar_res_10_6_2->Add(&yttbar_res_10_6_2_2);
yttbar_res_10_6_2->Add(&yttbar_res_10_6_2_3);
yttbar_res_10_6_2->Add(&yttbar_res_10_6_2_4);
yttbar_res_10_6_2->Add(&yttbar_res_10_6_2_5);

yttbar_res_10_6_2->SetLineColor(kRed);

yttbar_res_9_4_7->Draw("hist");
yttbar_res_10_6_2->Draw("hist same");

legend->Clear();
legend->AddEntry(yttbar_res_10_6_2,"CMSSW_10_6_2","l");
legend->AddEntry(yttbar_res_9_4_7,"CMSSW_9_4_7","l");
legend->SetX1NDC(0.65);
legend->SetX2NDC(0.9);
legend->Draw();

c.Print("/home/andrea/cernbox/TtbarCEP/ComparisonCMSSWversionsPlots/yttbar_res.png");
}