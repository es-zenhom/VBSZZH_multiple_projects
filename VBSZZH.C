#include <iostream>
#include <TH1D.h>
#include <vector>
#include <TMath.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TCanvas.h>
#include <Math/Vector4D.h>
#include <Math/GenVector/PtEtaPhiM4D.h>
#include <TString.h>


auto c1= new TCanvas;
auto c2= new TCanvas;
auto c3= new TCanvas;
auto c4= new TCanvas;
auto c5= new TCanvas;
auto c6= new TCanvas;
auto c7= new TCanvas;
auto c8= new TCanvas;
auto c9= new TCanvas;
auto c10= new TCanvas;
auto c11= new TCanvas;




void VBSZZH()
{
    // read file and TTree
    TFile* readf = new TFile ("merged_0.root","READ");
    TTree* Events = (TTree*) readf->Get("Events");

    // initatie the variables
    float LHEPart_pt[7], LHEPart_phi[7], LHEPart_mass[7], LHEPart_eta[7];
    int LHEPart_pdgId[7];
    int no_events= Events->GetEntries();
    std::vector<float> pt_Z{};
    std::vector<ROOT::Math::PtEtaPhiMVector> vecZ {};

    std::vector<ROOT::Math::PtEtaPhiMVector> vecH {};
    std::vector<ROOT::Math::PtEtaPhiMVector> vecQuark {};


    // point to the branches to read data from them afterwards
    Events->SetBranchAddress("LHEPart_pt",&LHEPart_pt);
    Events->SetBranchAddress("LHEPart_phi",&LHEPart_phi);
    Events->SetBranchAddress("LHEPart_mass",&LHEPart_mass);
    Events->SetBranchAddress("LHEPart_eta",&LHEPart_eta);
    Events->SetBranchAddress("LHEPart_pdgId",&LHEPart_pdgId);

    // create the histograms
    TH1D* hist_pt_H = new TH1D ("hist_pt_H", "pT of Higgs", 80,0,450);
    TH1D* hist_pt_leadZ = new TH1D ("hist_pt_leadZ", "pT of leading Z", 80,0,1800);
    TH1D* hist_pt_subleadZ = new TH1D ("hist_pt_subleadZ", "pT of subleading Z", 80,0,450);
    TH1D* hist_pt_leadQuark = new TH1D ("hist_pt_leadQuark", "pT of leading quark", 80,0,250);
    TH1D* hist_pt_subleadQuark = new TH1D ("hist_pt_subleadQuark", "pT of subleading quark", 80,0,160);
    TH1D* hist_m_ZZH = new TH1D ("hist_m_ZZH","invariant mass of the ZZH system", 80,0,2800);
    TH1D* hist_eta_leadQuark = new TH1D ("hist_eta_leadQuark", "eta of leading quark", 80,-6,6);
    TH1D* hist_eta_subleadQuark = new TH1D ("hist_eta_subleadQuark", "eta of subleading quark", 80,-6,6);
    TH1D* hist_abs_EtaDiff = new TH1D ("hist_abs_EtaDiff", "abs eta difference between quarks", 80,0,20);
    TH1D* hist_m_quarks = new TH1D ("hist_m_quarks", "Invariant mass of the two outgoing quarks system", 80,0,120);
    TH1D* hist_m_widerange_quarks = new TH1D ("hist_m_quarks", "Invariant mass of the two outgoing quarks system with wider range", 80,0,2500);

    for (int i=0; i<no_events; i++)
    {
        Events->GetEntry(i);
        for (int j=0; j<=6; j++)
        {

            if (LHEPart_pdgId[j]==25) {
                hist_pt_H->Fill(LHEPart_pt[j]);
                vecH.push_back({LHEPart_pt[j],LHEPart_eta[j],LHEPart_phi[j],LHEPart_mass[j]});
            }
            else if (LHEPart_pdgId[j]==23) {
                  pt_Z.push_back(LHEPart_pt[j]);
                  vecZ.push_back({LHEPart_pt[j],LHEPart_eta[j],LHEPart_phi[j],LHEPart_mass[j]});

            }
            else {
                  if (LHEPart_pt[j] !=0) {
                      vecQuark.push_back({LHEPart_pt[j],LHEPart_eta[j],LHEPart_phi[j],LHEPart_mass[j]});
                  }
            }
        }
        if (pt_Z.at(0)> pt_Z.at(1)){
        hist_pt_leadZ->Fill(pt_Z.at(0)) ;
        hist_pt_subleadZ->Fill(pt_Z.at(1)) ;
        }
        else {
        hist_pt_leadZ->Fill(pt_Z.at(1)) ;
        hist_pt_subleadZ->Fill(pt_Z.at(0)) ;
        }

        hist_m_ZZH->Fill((vecZ.at(0)+vecZ.at(1)+vecH.at(0)).mass());



        if (vecQuark[0].pt()> vecQuark[1].pt()){
        hist_pt_leadQuark->Fill(vecQuark[0].pt()) ;
        hist_pt_subleadQuark->Fill(vecQuark[1].pt()) ;

        hist_eta_leadQuark->Fill(vecQuark[0].eta()) ;
        hist_eta_subleadQuark->Fill(vecQuark[1].eta()) ;
        }
        else {
        hist_pt_leadQuark->Fill(vecQuark[1].pt()) ;
        hist_pt_subleadQuark->Fill(vecQuark[0].pt()) ;

        hist_eta_leadQuark->Fill(vecQuark[1].eta()) ;
        hist_eta_subleadQuark->Fill(vecQuark[0].eta()) ;
        }
        hist_m_quarks->Fill((vecQuark[0]+vecQuark[1]).mass());
        hist_m_widerange_quarks->Fill((vecQuark[0]+vecQuark[1]).mass());
        hist_abs_EtaDiff->Fill(TMath::Abs((vecQuark[1].eta())-(vecQuark[0].eta())));

      vecQuark.clear();
      vecH.clear();
      vecZ.clear();
      pt_Z.clear();

     }

         c1->cd();
         hist_pt_H->Draw();
         c1->SaveAs("pT of Higgs.pdf");

         c2->cd();
         hist_pt_leadZ->Draw();
         c2->SaveAs("pT of leading Z.pdf");

         c3->cd();
         hist_pt_subleadZ->Draw();
         c3->SaveAs("pT of subleading Z.pdf");

         c4->cd();
         hist_pt_leadQuark->Draw();
         c4->SaveAs("pT of leading quark.pdf");

         c5->cd();
         hist_pt_subleadQuark->Draw();
         c5->SaveAs("pT of subleading quark.pdf");

         c6->cd();
         hist_m_ZZH->Draw();
         c6->SaveAs("invariant mass of the ZZH system.pdf");

         c7->cd();
         hist_eta_leadQuark->Draw();
         c7->SaveAs("eta of leading quark.pdf");

         c8->cd();
         hist_eta_subleadQuark->Draw();
         c8->SaveAs("eta of subleading quark.pdf");

         c9->cd();
         hist_m_quarks->Draw();
         c9->SaveAs("Invariant mass of the two outgoing quarks system.pdf");

         c10->cd();
         hist_abs_EtaDiff->Draw();
         c10->SaveAs("abs eta difference between quarks.pdf");

         c11->cd();
         hist_m_widerange_quarks->Draw();
         c11->SaveAs("Invariant mass of the two outgoing quarks system with wider range.pdf");






     readf->Write();
         readf->Close();
}
