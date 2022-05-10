void makeItBlue(TH1 *hist, TString title=""){
	hist->SetLineColor(kBlue);
	hist->SetLineWidth(2);
	hist->SetTitle(title);
}
void makeItRed(TH1 *hist, TString title=""){
	hist->SetLineColor(kRed);
	hist->SetLineWidth(2);
	hist->SetTitle(title);
}

void comparePlots(TString plotPath, TString file0_title,TString file1_title){
	TCanvas *c1 = new TCanvas();
	TH1D *h1 = new TH1D(*(TH1D*)_file0->Get(plotPath)); // "multiRPPlots/arm0/h_xi"
	TH1D *h2 = new TH1D(*(TH1D*)_file1->Get(plotPath));
	makeItRed(h1,file0_title);
	makeItBlue(h2,file1_title);
	h1->GetXaxis()->SetTitle(plotPath+": "+h1->GetXaxis()->GetTitle());
	h1->Draw("ehist");
	h2->Draw("ehistsame");
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	c1->BuildLegend(0.6,0.7,0.89,0.89)->SetBorderSize(0);
}

void comparePlotsNormalized(TString plotPath, TString file0_title,TString file1_title){
	TCanvas *c1 = new TCanvas();
	TH1D *h1 = new TH1D(*(TH1D*)_file0->Get(plotPath)); // "multiRPPlots/arm0/h_xi"
	TH1D *h2 = new TH1D(*(TH1D*)_file1->Get(plotPath));
	makeItRed(h1,file0_title);
	makeItBlue(h2,file1_title);
	h1->GetXaxis()->SetTitle(plotPath+": "+h1->GetXaxis()->GetTitle());
	h1->DrawNormalized("ehist");
	h2->DrawNormalized("ehistsame");
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	c1->BuildLegend(0.6,0.7,0.89,0.89)->SetBorderSize(0);
}