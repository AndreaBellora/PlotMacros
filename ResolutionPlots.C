TCut arm0_st2 = TCut("arm0_st2","arm[0] == 0 && station[0] == 2")
TCut arm1_st2 = TCut("arm1_st2","arm[0] == 1 && station[0] == 2")
TCut recoInfoGood = TCut("recoInfoGood","recoInfo[0] == 0 || recoInfo[0] == 2")
TCut recoInfo0 = TCut("recoInfo0","recoInfo[0] == 0")
TCut recoInfo2 = TCut("recoInfo2","recoInfo[0] == 2")
TCut used3Planes = TCut("used3Planes","nPointsUsedForFit == 3")
TCut used4Planes = TCut("used3Planes","nPointsUsedForFit == 4")
TCut used5Planes = TCut("used3Planes","nPointsUsedForFit == 5")
TCut used6Planes = TCut("used3Planes","nPointsUsedForFit == 6")
TCut planesWithColCls2_0 = TCut("PlanesWithColCls2_0","nPlanesWithColCls2_ == 0")
TCut planesWithColCls2_1 = TCut("PlanesWithColCls2_1","nPlanesWithColCls2_ == 1")
TCut planesWithColCls2_2 = TCut("PlanesWithColCls2_2","nPlanesWithColCls2_ == 2")
TCut planesWithColCls2_3 = TCut("PlanesWithColCls2_3","nPlanesWithColCls2_ == 3")
TCut planesWithColCls2_4 = TCut("PlanesWithColCls2_4","nPlanesWithColCls2_ == 4")
TCut planesWithColCls2_5 = TCut("PlanesWithColCls2_5","nPlanesWithColCls2_ == 5")
TCut planesWithColCls2_6 = TCut("PlanesWithColCls2_6","nPlanesWithColCls2_ == 6")
TCut planesWithRowCls2_0 = TCut("PlanesWithRowCls2_0","nPlanesWithRowCls2_ == 0")
TCut planesWithRowCls2_1 = TCut("PlanesWithRowCls2_1","nPlanesWithRowCls2_ == 1")
TCut planesWithRowCls2_2 = TCut("PlanesWithRowCls2_2","nPlanesWithRowCls2_ == 2")
TCut planesWithRowCls2_3 = TCut("PlanesWithRowCls2_3","nPlanesWithRowCls2_ == 3")
TCut planesWithRowCls2_4 = TCut("PlanesWithRowCls2_4","nPlanesWithRowCls2_ == 4")
TCut planesWithRowCls2_5 = TCut("PlanesWithRowCls2_5","nPlanesWithRowCls2_ == 5")
TCut planesWithRowCls2_6 = TCut("PlanesWithRowCls2_6","nPlanesWithRowCls2_ == 6")

int mapXbins = 200
float mapXmin = 0. * TMath::Cos(18.4 / 180. * TMath::Pi())
float mapXmax = 30. * TMath::Cos(18.4 / 180. * TMath::Pi())
int mapYbins = 240
float mapYmin = -16.
float mapYmax = 8.

TH2D h2Template = TH2D("h2Template","title",mapXbins,mapXmin,mapXmax,mapYbins,mapYmin,mapYmax)	

tTracks->Draw("chi2OverNDF", arm0_st2+recoInfo2, "")

tTracks->Draw("chi2OverNDF", arm0_st2+recoInfo2+planesWithRowCls2_0, "same")
