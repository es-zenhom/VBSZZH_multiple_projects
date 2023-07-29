#include <iostream>
#include <TH1D.h>
#include <vector>
#include <TMath.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include <TCanvas.h>
#include <Math/Vector4D.h>
#include <Math/GenVector/PtEtaPhiM4D.h>
#include <TString.h>
#include <Math/VectorUtil.h>
#include <TH2D.h>
#include <TGraph.h>
#include <TF1.h>
TCanvas* c1= new TCanvas();

void tryy()
{
  //gStyle->SetOptTitle(kFALSE);
  //gStyle->SetOptStat(0);

    TF1* g1= new TF1("g1","sin(x)",0,5);
        TF1* g2= new TF1("g2","x",0,3.14);
    // g1->AddPoint(2,3);
    //     g1->AddPoint(5,3);
    //         g1->AddPoint(8,3);
    //             g1->AddPoint(5,9);
    //                 g1->AddPoint(25,3);
                     g1->SetLineColor(3);
                     g2->SetLineColor(4);

    //
    //
    //                 g2->AddPoint(2,3);
    //     g2->AddPoint(5,3);
 c1->cd();
    g1->Draw();
   g2->Draw();
}
