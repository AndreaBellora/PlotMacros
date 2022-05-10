void setRange_st2_rectangular(bool isEfficiency = false) {
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 27);
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))
      ->GetYaxis()
      ->SetRangeUser(-13, 6);
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))->SetMinimum(0.);

  if (isEfficiency) {
    ((TH2D *)gPad->GetListOfPrimitives()->At(1))->SetMinimum(0.0001);
    ((TH2D *)gPad->GetListOfPrimitives()->At(1))->SetMaximum(1);
  }
  gPad->Update();
}

void setRange_st0_rectangular(bool isEfficiency = false) {
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))->GetXaxis()->SetRangeUser(0, 27);
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))
      ->GetYaxis()
      ->SetRangeUser(-11.5, 7.5);
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))->SetMinimum(0.);
  if (isEfficiency) {
    ((TH2D *)gPad->GetListOfPrimitives()->At(1))->SetMinimum(0.8);
  }
  gPad->Update();
}

void setRange_st0_square(bool isEfficiency = false) {
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))
      ->GetXaxis()
      ->SetRangeUser(0, 9.5);
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))
      ->GetYaxis()
      ->SetRangeUser(-3.25, 6);
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))->SetMinimum(0.0001);
  if (isEfficiency) {
    ((TH2D *)gPad->GetListOfPrimitives()->At(1))->SetMinimum(0.8);
  }
  gPad->Update();
}

void setRange_st2_square(bool isEfficiency = false) {
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))
      ->GetXaxis()
      ->SetRangeUser(0, 9.5);
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))
      ->GetYaxis()
      ->SetRangeUser(-3.25, 6);
  ((TH2D *)gPad->GetListOfPrimitives()->At(1))->SetMinimum(0.0001);
  if (isEfficiency) {
    ((TH2D *)gPad->GetListOfPrimitives()->At(1))->SetMinimum(0.8);
  }
  gPad->Update();
}

void setRectangularPlots() {
  gStyle->SetCanvasDefH(1023);             // Height of canvas
  gStyle->SetCanvasDefW(1544);             // Width of canvas
  gStyle->SetPadLeftMargin(192. / 1544.);  // Same margins as in 1080p
  gStyle->SetPadRightMargin(192. / 1544.); // Same margins as in 1080p
}

void setSquarePlots() {
  gStyle->SetCanvasDefH(1023);             // Height of canvas
  gStyle->SetCanvasDefW(1201);             // Width of canvas
  gStyle->SetPadLeftMargin(192. / 1201.);  // Same margin as rectangular plots
  gStyle->SetPadRightMargin(192. / 1201.); // Same margin as rectangular plots
}

void cropPlot_st2() {
  double canvasW = gStyle->GetCanvasDefW();
  double padLMargin = gStyle->GetPadLeftMargin() * canvasW;
  double padRMargin = gStyle->GetPadRightMargin() * canvasW;
  double plotW = canvasW - padRMargin - padLMargin;
  double xMax = 27. * (plotW / (0.8 * 1920.));

  ((TH2D *)gPad->GetListOfPrimitives()->At(1))
      ->GetXaxis()
      ->SetRangeUser(0, xMax);
}