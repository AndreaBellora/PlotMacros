#include "AddressDecoding_DTB.C"
#include "Delay25_POS.C"
#include "Iana_DTB.C"
#include "Mask_DTB.C"
#include "Noise1D_PLN_POS.C"
#include "Noise2D_POS.C"
#include "PixelAlive_DTB.C"
#include "POHBias_POS.C"
#include "TBMDelay_HeadersComparison_POS.C"
#include "Threshold1D_PLN_POS.C"
#include "Threshold2D_POS.C"
#include "TornadoPlot_DTB.C"
#include "Xray_DTB.C"
#include "Trimming_DTB_POS.C"
#include "GainCalibration_Slope_POS.C"
#include "GainCalibration_Pedestal_POS.C"
#include "GainCalibration_Fit_POS.C"

void MakePlots_ch5(){
    TCanvas *c;
    TString saveDir = "ch-5/fig/"; 

    c = AddressDecoding_DTB();
    c->SaveAs(saveDir+"AddressDecoding.pdf");
    delete c;

    c = Delay25_POS(
        "45",
        "003",
        "2",
        "",
        "RootFiles/PixelRun/Runs/Run_1000/Run_1072/delay25_1.root"
    );
    c->SaveAs(saveDir+"Delay25_intersection.pdf");
    delete c;

    c = Delay25_POS(
        "45",
        "003",
        "2",
        "1",
        "RootFiles/PixelRun/Runs/Run_1000/Run_1072/delay25_1.root"
    );
    c->SaveAs(saveDir+"Delay25_easyCommand.pdf");
    delete c;
    
    c = Iana_DTB();
    c->SaveAs(saveDir+"Iana.pdf");
    delete c;

    c = Mask_DTB();
    c->SaveAs(saveDir+"MaskTest.pdf");
    delete c;

    c = Noise1D_PLN_POS();
    c->SaveAs(saveDir+"NoiseAllPixels_preTrim.pdf");
    delete c;

    c = Noise2D_POS();
    c->SaveAs(saveDir+"NoiseMap.pdf");
    delete c;

    c = PixelAlive_DTB();
    c->SaveAs(saveDir+"PixelAlive.pdf");
    delete c;

    c = POHBias_POS();
    c->SaveAs(saveDir+"POHBias.pdf");
    delete c;

    c = TBMDelay_HeadersComparison_POS();
    c->SaveAs(saveDir+"TBMDelay_HeadersComparison.pdf");
    delete c;

    c = Threshold1D_PLN_POS();
    c->SaveAs(saveDir+"ThresholdAllPixels_preTrim.pdf");
    delete c;

    c = Threshold2D_POS();
    c->SaveAs(saveDir+"ThresholdMap.pdf");
    delete c;

    c = TornadoPlot_DTB();
    c->SaveAs(saveDir+"Tornado.pdf");
    delete c;

    c = Xray_DTB();
    c->SaveAs(saveDir+"Xray.pdf");
    delete c;

    c = Trimming_DTB_POS();
    c->SaveAs(saveDir+"Trimming.pdf");
    delete c;

    c = GainCalibration_Slope_POS();
    c->SaveAs(saveDir+"GainCalibration_slope.pdf");
    delete c;

    c = GainCalibration_Pedestal_POS();
    c->SaveAs(saveDir+"GainCalibration_pedestal.pdf");
    delete c;

    c = GainCalibration_Fit_POS();
    c->SaveAs(saveDir+"GainCalibration_fit.pdf");
    delete c;
}