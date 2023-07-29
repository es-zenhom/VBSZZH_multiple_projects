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

void tryy()
{
    TGraph* g1= new TGraph();
    g1->SetPoint(2,3);
    g1->Drawt();
}
