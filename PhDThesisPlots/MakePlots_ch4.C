#include "utils.C"
#include "CMS_lumi.h"

using namespace std;

void setRange_st2_rectangular(TPad *pad, bool isEfficiency = false) {
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetXaxis()->SetRangeUser(0, 27);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetYaxis()->SetRangeUser(-12.5, 7);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.);

  if (isEfficiency) {
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.0001);
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMaximum(1);
  }
  pad->Update();
}

void setRange_st0_rectangular(TPad *pad, bool isEfficiency = false) {
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetXaxis()->SetRangeUser(0, 15);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetYaxis()->SetRangeUser(-5, 5);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.);

  if (isEfficiency) {
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.0001);
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMaximum(1);
  }
  pad->Update();
}

void setRange_st2_square(TPad *pad, bool isEfficiency = false) {
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->GetXaxis()->SetRangeUser(0, 9.5);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))
      ->GetYaxis()
      ->SetRangeUser(-3.25, 6);
  ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.0001);
  if (isEfficiency) {
    ((TH2D *)pad->GetListOfPrimitives()->At(0))->SetMinimum(0.8);
  }
  pad->Update();
}



void MakePlots_ch4(){
    // Folder to save plots
    TString outputFolderImages = "ch-4/fig/";
    TFile *inputEff_all = TFile::Open("TestRootFiles/EfficiencyComponentPlots/output.root");
    TFile *inputEff_radNearOff_multiRPOff = TFile::Open("TestRootFiles/EfficiencyComponentPlots/output_radNearOff_multiRPOff.root");
    TFile *inputEff_multiRPOff = TFile::Open("TestRootFiles/EfficiencyComponentPlots/output_multiRPOff.root");
  TCanvas *c = makeCanvasWithAspectRatio("c","c",14,9);


	gStyle->SetPalette(kViridis);
	auto cols = TColor::GetPalette();

	vector<TString> arms = {"0","1"};
	vector<TString> years = {"2016","2017","2018"};
  
	for(const auto &arm : arms){
		for(const auto &year : years){
			TH1D *hAcceptance = 
				(TH1D *)inputEff_all->Get("Acceptance"+year+"_"+arm);
			TH1D *hEfficiency_radNearOff_multiRPOff = 
				(TH1D *)inputEff_radNearOff_multiRPOff->Get("Efficiency"+year+"_"+arm);
			TH1D *hEfficiency_multiRPOff = 
				(TH1D *)inputEff_multiRPOff->Get("Efficiency"+year+"_"+arm);
			TH1D *hEfficiency_full = 
				(TH1D *)inputEff_all->Get("Efficiency"+year+"_"+arm);
				
			hAcceptance->Smooth(2);
			hEfficiency_radNearOff_multiRPOff->Smooth(2);
			hEfficiency_multiRPOff->Smooth(2);
			hEfficiency_full->Smooth(2);

			TGraphErrors *gAcceptance = new TGraphErrors();
			gAcceptance->SetLineColor(cols.At(50));
			gAcceptance->SetFillColor(cols.At(51));
			gAcceptance->SetFillStyle(1001);
			gAcceptance->SetLineWidth(2);
			for (int i = 2; i < hAcceptance->GetNbinsX();i++){
				int nPoint = gAcceptance->GetN();
				gAcceptance->SetPoint(nPoint,hAcceptance->GetBinCenter(i), hAcceptance->GetBinContent(i));
				gAcceptance->SetPointError(nPoint,0., 0);
			}
			// Close area below graph
			gAcceptance->SetPoint(gAcceptance->GetN(),hAcceptance->GetBinCenter(hAcceptance->GetNbinsX()-1),0);

			TGraphErrors *gEfficiency_radNearOff_multiRPOff = new TGraphErrors();
			gEfficiency_radNearOff_multiRPOff->SetLineColor(cols.At(100));
			gEfficiency_radNearOff_multiRPOff->SetFillColor(cols.At(101));
			gEfficiency_radNearOff_multiRPOff->SetFillStyle(1001);
			gEfficiency_radNearOff_multiRPOff->SetLineWidth(2);
			for (int i = 2; i < hEfficiency_full->GetNbinsX();i++){
				int nPoint = gEfficiency_radNearOff_multiRPOff->GetN();
				gEfficiency_radNearOff_multiRPOff->SetPoint(nPoint,hEfficiency_radNearOff_multiRPOff->GetBinCenter(i), hEfficiency_radNearOff_multiRPOff->GetBinContent(i));
				gEfficiency_radNearOff_multiRPOff->SetPointError(nPoint,0., 0);
			}
			// Close area below graph
			gEfficiency_radNearOff_multiRPOff->SetPoint(gEfficiency_radNearOff_multiRPOff->GetN(),hEfficiency_radNearOff_multiRPOff->GetBinCenter(hEfficiency_radNearOff_multiRPOff->GetNbinsX()-1),0);


			TGraphErrors *gEfficiency_multiRPOff = new TGraphErrors();
			gEfficiency_multiRPOff->SetLineColor(cols.At(150));
			gEfficiency_multiRPOff->SetFillColor(cols.At(151));
			gEfficiency_multiRPOff->SetFillStyle(1001);
			gEfficiency_multiRPOff->SetLineWidth(2);
			for (int i = 2; i < hEfficiency_full->GetNbinsX();i++){
				int nPoint = gEfficiency_multiRPOff->GetN();
				gEfficiency_multiRPOff->SetPoint(nPoint,hEfficiency_multiRPOff->GetBinCenter(i), hEfficiency_multiRPOff->GetBinContent(i));
				gEfficiency_multiRPOff->SetPointError(nPoint,0., 0);
			}
			// Close area below graph
			gEfficiency_multiRPOff->SetPoint(gEfficiency_multiRPOff->GetN(),hEfficiency_multiRPOff->GetBinCenter(hEfficiency_multiRPOff->GetNbinsX()-1),0);

			TGraphErrors *gEfficiency_full = new TGraphErrors();
			gEfficiency_full->SetLineColor(cols.At(200));
			gEfficiency_full->SetFillColor(cols.At(201));
			gEfficiency_full->SetFillStyle(1001);
			gEfficiency_full->SetLineWidth(2);
			for (int i = 2; i < hEfficiency_full->GetNbinsX();i++){
				int nPoint = gEfficiency_full->GetN();
				gEfficiency_full->SetPoint(nPoint,hEfficiency_full->GetBinCenter(i), hEfficiency_full->GetBinContent(i));
				gEfficiency_full->SetPointError(nPoint,0., 0);
			}
			// Close area below graph
			gEfficiency_full->SetPoint(gEfficiency_full->GetN(),hEfficiency_full->GetBinCenter(hEfficiency_full->GetNbinsX()-1),0);

			gAcceptance->Draw("alx");
			gAcceptance->GetXaxis()->SetLimits(0.,0.3);
			gAcceptance->GetYaxis()->SetLabelSize(0.035);
			gAcceptance->GetXaxis()->SetLabelSize(0.035);
			gAcceptance->GetXaxis()->SetTitleSize(0.035);
			gAcceptance->GetXaxis()->SetTitleOffset(1.2);
			gAcceptance->GetXaxis()->SetTitle("#it{#xi}_{#font[132]{multi}}");
			gAcceptance->GetYaxis()->SetTitleSize(0.035);
			gAcceptance->GetYaxis()->SetTitleOffset(1.2);
			gAcceptance->GetYaxis()->SetTitle("Fraction of reconstructed protons");
			gAcceptance->GetHistogram()->SetMinimum(0.);
			gAcceptance->GetHistogram()->SetMaximum(1.15);
			gAcceptance->Draw("alfx");
			gEfficiency_radNearOff_multiRPOff->Draw("lfsamex");
			gEfficiency_multiRPOff->Draw("lfsamex");
			gEfficiency_full->Draw("lfsamex");
			TLegend *legend = new TLegend(0.5,0.55,0.9,0.85);
			legend->SetFillStyle(0);
			legend->SetBorderSize(0);
			legend->AddEntry(gAcceptance,"Acceptance","f");
			legend->AddEntry(gEfficiency_radNearOff_multiRPOff,"Acceptance #times multi-tracking","f");
			legend->AddEntry(gEfficiency_multiRPOff,"All components but multiRP","f");
			legend->AddEntry(gEfficiency_full,"All components","f");
			legend->SetTextSize(0.037);
			legend->SetTextFont(62);
			legend->Draw();

			if (year == "2018"){
				CMS_lumi((TPad *)c->GetPad(0),-1,1,year,false,true);
			} else {
				CMS_TOTEM_lumi((TPad *)c->GetPad(0),-1,1,year,false,true);
			}
			c->SaveAs(outputFolderImages+"EfficiencyComponents_"+year+"_Arm"+arm+".pdf");
		}
	}





}