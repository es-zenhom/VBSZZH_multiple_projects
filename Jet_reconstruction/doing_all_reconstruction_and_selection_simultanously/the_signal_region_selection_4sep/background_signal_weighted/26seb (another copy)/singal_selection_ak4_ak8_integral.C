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
#include <TMultiGraph.h>


TCanvas* c1= new TCanvas();

void singal_selection_ak4_ak8_integral()
{
  TFile* b =new TFile("background.root");
  TFile* s1 =new TFile("sig_VBSWWH.root");
  TFile* s2 =new TFile("sig_VBSZZH.root");
  TFile* s3 =new TFile("sig_VBSOSWWH.root");
  TFile* s4 =new TFile("sig_VBSWZH.root");

  TH1D* background=(TH1D*)b->Get("hist_absDelta_eta_of_twoVBFjets");
  TH1D* h1=(TH1D*)s1->Get("hist_absDelta_eta_of_twoVBFjets");
  TH1D* h2=(TH1D*)s2->Get("hist_absDelta_eta_of_twoVBFjets");
  TH1D* h3=(TH1D*)s3->Get("hist_absDelta_eta_of_twoVBFjets");
  TH1D* h4=(TH1D*)s4->Get("hist_absDelta_eta_of_twoVBFjets");

  float x[3333], y[3333], y1[3333], y2[3333], y3[3333], y4[3333];
  // std::vector<float> y{};
  // std::vector<float> y1{};
  // std::vector<float> y2{};
  // std::vector<float> y3{};
  // std::vector<float> y4{};

  // TF1* g1= new TF1("g1","my_function(x)",0,10);
  TGraph* g1= new TGraph();
  TGraph* g2= new TGraph();
  TGraph* g3= new TGraph();
  TGraph* g4= new TGraph();


  for (float i = 0; i < 81; i++)
  {
    if (background->Integral(i,81)>0)
    {
        g1->AddPoint(i*10/80,(h1->Integral(i,81))/sqrt(background->Integral(i,81)));
        g2->AddPoint(i*10/80,(h2->Integral(i,81))/sqrt(background->Integral(i,81)));
        g3->AddPoint(i*10/80,(h3->Integral(i,81))/sqrt(background->Integral(i,81)));
        g4->AddPoint(i*10/80,(h4->Integral(i,81))/sqrt(background->Integral(i,81)));
        cout << i << "     "<< (h1->Integral(i,81))/sqrt(background->Integral(i,81))<<endl;

    }


  }


  g1->SetLineColor(1); //g1->SetTitle("VBSWWH");
  g2->SetLineColor(2); //g2->SetTitle("VBSWWH");
  g3->SetLineColor(3); //g3->SetTitle("VBSWWH");
  g4->SetLineColor(4); //g4->SetTitle("VBSWWH");


  //cout<< h1->Integral(0,10)<<endl;
   auto mg = new TMultiGraph();
        mg->Add(g1);
         mg->Add(g2);
         mg->Add(g3);
         mg->Add(g4);

  c1->cd();

   // g1->Draw();
  // // g2->Draw("SAME");
  // // g3->Draw("SAME");
  // g4->Draw("SAME");
  // c1->BuildLegend();

  mg->Draw("a");
  auto legend = new TLegend(0.7,0.7,0.9,0.9);
   // legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
   legend->AddEntry(g1,"VBSWWH");
   legend->AddEntry(g2,"VBSZZH");
   legend->AddEntry(g3,"VBSOSWWH");
   legend->AddEntry(g4,"VBSWZH");
   legend->Draw();
  c1->SaveAs("sensitivity.pdf");
  // mg->GetHistogram()->GetXaxis()->SetRangeUser(0.,10);
     // gPad->Modified();
     // gPad->Update();



}
