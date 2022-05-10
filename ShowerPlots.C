TFile *showerFile = TFile::Open("OutputFiles/EraA_showers_Run316569_End.root")
int totalBins = 101;
int bin60 = 31;
int bin40 = 21;// 21
int binStart = 3; // >= 4 recHits

int arm = 0;
int station = 0;
TH1D nRecHitsWithNoProton  = TH1D(*((TH1D*)showerFile->Get(Form("Arm%i_st%i_rp3/h1NumberOfRecHitsInPotWithNoProton_arm%i_st%i_rp3",arm,station,arm,station))));
TH1D nRecHitsWithOneProton = TH1D(*((TH1D*)showerFile->Get(Form("Arm%i_st%i_rp3/h1NumberOfRecHitsInPotWithOneProtonMinusTrackHits_arm%i_st%i_rp3",arm,station,arm,station))));
TH1D nRecHitsTotal = TH1D(*((TH1D*)showerFile->Get(Form("Arm%i_st%i_rp3/h1NumberOfRecHitsInPot_arm%i_st%i_rp3",arm,station,arm,station))));

normalization_NoProton = 1. / nRecHitsWithNoProton.Integral(binStart, bin60 -1);
normalization_OneProton = 1. / nRecHitsWithOneProton.Integral(binStart, bin60 -1);

totalEventsWithTrack = nRecHitsTotal.Integral(binStart, totalBins+1);
eventsWithTooManyRecHitsPerRP = nRecHitsWithNoProton.Integral(bin60,totalBins+1);
eventsWithNoTrackUnder60 = nRecHitsWithNoProton.Integral(bin40,bin60);

cout << "Fraction of events with too many recHits in RP: " << (double) eventsWithTooManyRecHitsPerRP/totalEventsWithTrack *100 << " %" << endl;
cout << "Fraction of events with no tracks and 40-60 recHits in RP: " << (double) eventsWithNoTrackUnder60/totalEventsWithTrack *100 << " %" << endl;

nRecHitsWithNoProton.Scale(normalization_NoProton);
nRecHitsWithOneProton.Scale(normalization_OneProton);

TCanvas c1;
c1.SetLogy();

nRecHitsWithNoProton.SetLineColor(kBlue);
nRecHitsWithNoProton.SetLineWidth(2);
nRecHitsWithNoProton.Draw("hist");

nRecHitsWithOneProton.SetLineColor(kRed);
nRecHitsWithOneProton.SetLineWidth(2);
nRecHitsWithOneProton.Draw("histsame");

