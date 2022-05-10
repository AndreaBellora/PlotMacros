// This is a macro to average radiation efficiencies for 2018 near stations

#include <iomanip>
#include <iostream>

using namespace std;

void addEfficiencyAverages() {
  TFile *radiation_efficiency_file =
      TFile::Open(("pixelEfficiencies_radiation_reMiniAOD.root"));
  TFile *multiRP_efficiency_file =
      TFile::Open(("pixelEfficiencies_multiRP_reMiniAOD.root"));

  if (radiation_efficiency_file == NULL) {
    cout << "ERROR: input file was not found, exiting..." << endl;
    return;
  }

  if (multiRP_efficiency_file == NULL) {
    cout << "ERROR: input file was not found, exiting..." << endl;
    return;
  }

  vector<TString> years_to_avg = {"2018"};
  vector<TString> years_to_analyze = {"2017", "2018"};

  vector<TString> eras2017 = {"B", "C1", "C2", "D", "E", "F1", "F2", "F3"};
  vector<TString> eras2017_avg = {"C", "F"};
  vector<TString> eras2018 = {"A", "B1", "B2", "C", "D1", "D2"};
  vector<TString> eras2018_avg = {"B", "D"};

  map<TString, double> lumiWeights = {
      {"C1", 5372685500.084013939 / 8.6806766e+09},
      {"C2", 3307991145.520657539 / 8.6806766e+09},
      {"F1", 1714884890.072064877 / 1.3247273e+10},
      {"F2", 7889974131.627684593 / 1.3247273e+10},
      {"F3", 3642413583.456357479 / 1.3247273e+10},
      {"B1", 6135903882.410737991 / 6517624249.612241745},
      {"B2", 381720367.201503396 / 6517624249.612241745},
      {"D1", 19998142938.951736450 / 30496850186.283702850},
      {"D2", 10498707247.331964493 / 30496850186.283702850}};

  TFile *radiationAvgFile = new TFile(
      "pixelEfficiencies_radiation_withAvg_reMiniAOD.root", "RECREATE");

  TFile *multiRPAvgFile =
      new TFile("pixelEfficiencies_multiRP_withAvg_reMiniAOD.root", "RECREATE");

  vector<TString> sectors = {"45", "56"};
  vector<TString> stations = {"210", "220"};

  for (auto &year : years_to_analyze) {
    vector<TString> eras;
    vector<TString> eras_to_avg;
    if (year == "2017") {
      eras = eras2017;
      eras_to_avg = eras2017_avg;
    } else if (year == "2018") {
      eras = eras2018;
      eras_to_avg = eras2018_avg;
    }

    TH2D *h2Radiation_efficiency;
    TH2D *h2MultiRP_efficiency;
    TEfficiency *TEMultiRP_efficiency;

    // Copy all radiation plots
    for (auto &era : eras) {
      TString map_path = "Pixel/" + year + "/" + year + era + "/";
      radiationAvgFile->mkdir(map_path);
      for (auto &sector : sectors) {
        for (auto &station : stations) {
          TString map_name =
              "h" + sector + "_" + station + "_" + year + era + "_all_2D";

          cout << "Analyzing radiation map " + map_name + "..." << endl;
          if (radiation_efficiency_file->Get(map_path + map_name) == NULL) {
            cout << "ERROR: radiation efficiency map " << map_name << " not found" << endl;
            continue;
          }
          h2Radiation_efficiency = new TH2D(
              *((TH2D *)radiation_efficiency_file->Get(map_path + map_name)));
          radiationAvgFile->cd(map_path);
          h2Radiation_efficiency->Write();
          delete h2Radiation_efficiency;
        }
      }
    }

    for (auto era_avg : eras_to_avg) {
      TString map_path_avg = "Pixel/" + year + "/" + year + era_avg + "/";

      for (auto sector : sectors) {
        for (auto station : stations) {
          TString map_name_avg =
              "h" + sector + "_" + station + "_" + year + era_avg + "_all_2D";
          TH2D *h2Radiation_efficiency_avg = 0;

          cout << "Producing radiation map: " + map_name_avg << endl;
          for (auto era : eras) {
            TString map_path = "Pixel/" + year + "/" + year + era + "/";
            if (era[0] == era_avg) {
              TString map_name =
                  "h" + sector + "_" + station + "_" + year + era + "_all_2D";

              cout << "Adding radiation map " + map_name + " to the average"
                   << endl;

              if (radiation_efficiency_file->Get(map_path + map_name) == NULL) {
                cout << "Radiation efficiency map " << map_name << " not found, skipping..."
                     << endl;
                continue;
              }
              TH2D *h2Radiation_efficiency = new TH2D(*(
                  (TH2D *)radiation_efficiency_file->Get(map_path + map_name)));
              if (h2Radiation_efficiency_avg == NULL) {
                h2Radiation_efficiency_avg = new TH2D(*h2Radiation_efficiency);
                h2Radiation_efficiency_avg->Scale(lumiWeights[era]);
              } else {
                h2Radiation_efficiency_avg->Add(h2Radiation_efficiency,
                                                lumiWeights[era]);
              }
            }
          }
          if (h2Radiation_efficiency_avg != NULL) {
            radiationAvgFile->mkdir(map_path_avg);
            radiationAvgFile->cd(map_path_avg);
            h2Radiation_efficiency_avg->SetNameTitle(map_name_avg,
                                                     map_name_avg);
            h2Radiation_efficiency_avg->SetMaximum(1.);
            h2Radiation_efficiency_avg->Write();
            delete h2Radiation_efficiency_avg;
            h2Radiation_efficiency_avg = 0;
          }
        }
      }
    }

    // Copy all multiRP plots
    for (auto &era : eras) {
      TString map_path = "Pixel/" + year + "/" + year + era + "/";
      multiRPAvgFile->mkdir(map_path);
      for (auto &sector : sectors) {
        for (auto &station : stations) {
          TString map_name =
              "h" + sector + "_" + station + "_" + year + era + "_all_2D";
          TString teff_map_name =
              "TE" + sector + "_" + station + "_" + year + era + "_all_2D";

          cout << "Analyzing multiRP map " + map_name + "..." << endl;
          if (multiRP_efficiency_file->Get(map_path + map_name) == NULL) {
            cout << "ERROR: multiRP efficiency map " << map_name << " not found" << endl;
            continue;
          }
          h2MultiRP_efficiency = new TH2D(
              *((TH2D *)multiRP_efficiency_file->Get(map_path + map_name)));
          multiRPAvgFile->cd(map_path);
          h2MultiRP_efficiency->Write();
          delete h2MultiRP_efficiency;
          TEMultiRP_efficiency = new TEfficiency(
              *((TEfficiency *)multiRP_efficiency_file->Get(map_path + teff_map_name)));
          multiRPAvgFile->cd(map_path);
          TEMultiRP_efficiency->Write();
          delete TEMultiRP_efficiency;
        }
      }
    }

    for (auto era_avg : eras_to_avg) {
      TString map_path_avg = "Pixel/" + year + "/" + year + era_avg + "/";

      for (auto sector : sectors) {
        for (auto station : stations) {
          TString map_name_avg =
              "h" + sector + "_" + station + "_" + year + era_avg + "_all_2D";
          TH2D *h2MultiRP_efficiency_avg = 0;

          cout << "Producing multiRP map: " + map_name_avg << endl;
          for (auto era : eras) {
            TString map_path = "Pixel/" + year + "/" + year + era + "/";
            if (era[0] == era_avg) {
              TString map_name =
                  "h" + sector + "_" + station + "_" + year + era + "_all_2D";

              cout << "Adding multiRP map " + map_name + " to the average"
                   << endl;

              if (multiRP_efficiency_file->Get(map_path + map_name) == NULL) {
                cout << "MultiRP efficiency map " << map_name << " not found, skipping..." << endl;
                continue;
              }
              TH2D *h2MultiRP_efficiency = new TH2D(
                  *((TH2D *)multiRP_efficiency_file->Get(map_path + map_name)));
              if (h2MultiRP_efficiency_avg == NULL) {
                h2MultiRP_efficiency_avg = new TH2D(*h2MultiRP_efficiency);
                h2MultiRP_efficiency_avg->Scale(lumiWeights[era]);
              } else {
                h2MultiRP_efficiency_avg->Add(h2MultiRP_efficiency,
                                              lumiWeights[era]);
              }
            }
          }
          if (h2MultiRP_efficiency_avg != NULL) {
            multiRPAvgFile->mkdir(map_path_avg);
            multiRPAvgFile->cd(map_path_avg);
            h2MultiRP_efficiency_avg->SetNameTitle(map_name_avg, map_name_avg);
            h2MultiRP_efficiency_avg->SetMaximum(1.);
            h2MultiRP_efficiency_avg->Write();
            delete h2MultiRP_efficiency_avg;
            h2MultiRP_efficiency_avg = 0;
          }
        }
      }
    }
  }
  radiationAvgFile->Close();
  multiRPAvgFile->Close();
  cout << "Results stored in " << radiationAvgFile->GetName() << " and "
       << multiRPAvgFile->GetName() << endl;
}