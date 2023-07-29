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
auto c12= new TCanvas;



void VBSZZH_genpart()
{
    // read file and TTree
    TFile* readf = new TFile ("/home/eslam/uf_work/VBSZZH/merged_0.root","READ");
    TTree* Events = (TTree*) readf->Get("Events");

    // initatie the variables
    float GenPart_pt[333], GenPart_phi[333], GenPart_mass[333], GenPart_eta[333];
    int GenPart_pdgId[333],GenPart_status[333], GenPart_genPartIdxMother[333], nGenPart[333];
    int no_events= Events->GetEntries();

    std::vector<float> pt_Z{};
    std::vector<int> H_index_children{};

    std::vector<ROOT::Math::PtEtaPhiMVector> vecZ {};

    std::vector<ROOT::Math::PtEtaPhiMVector> vecH {};
    std::vector<ROOT::Math::PtEtaPhiMVector> vecQuark {};


    // point to the branches to read data from them afterwards
    Events->SetBranchAddress("GenPart_pt",&GenPart_pt);
    Events->SetBranchAddress("GenPart_phi",&GenPart_phi);
    Events->SetBranchAddress("GenPart_mass",&GenPart_mass);
    Events->SetBranchAddress("GenPart_eta",&GenPart_eta);
    Events->SetBranchAddress("GenPart_pdgId",&GenPart_pdgId);
    Events->SetBranchAddress("GenPart_status",&GenPart_status);
    Events->SetBranchAddress("GenPart_genPartIdxMother",&GenPart_genPartIdxMother);
    Events->SetBranchAddress("nGenPart",&nGenPart);




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
    TH1D* hist_H_pdgid_children = new TH1D ("hist_H_pdgid_children", "pdgId of Higgs children", 100,-50,50);


    std::vector<int> index_parent_quark {};
    // for (int y = 0; y < no_events; y++) {
    //   Events->GetEntry(i);
    //
    //   for (int x=0; x <= 332; x++)
    //   {
    //       if (GenPart_status[x]==21 && GenPart_genPartIdxMother[x]==-1)
    //       {
    //           index_parent_quark.push_back(x);
    //       }
    //   }
    // }

int count=0;
    for (int i=0; i<no_events; i++)
    {
        Events->GetEntry(i);
        for (int x=0; x <= (nGenPart[0]-1); x++)
        {
            if (GenPart_status[x]==21 && GenPart_genPartIdxMother[x]==-1)
            {
                index_parent_quark.push_back(x);
            }
        }


        for (int j=0; j<=(nGenPart[0]-1); j++)
        {

            if  (GenPart_pdgId[j]==25) // recording the indices of where we have higgs then i would loop over all those to fill hist with pdgid
            //then i would see what is the index of last elemnt of this vector and then search for particles with same mother id to put in the hist
            {
                H_index_children.push_back(j);
                //hist_H_pdgid_children->Fill(GenPart_pdgId[j]);

            }
            if (GenPart_genPartIdxMother[j]== index_parent_quark[0] or GenPart_genPartIdxMother[j]== index_parent_quark[1]   )
            {

                //cout << "motherzer:" << "event : " << i << "j index:" << j <<endl;
                if (GenPart_pdgId[j]==25) {
                  //cout << "GenPart_pt[j]==25:" << GenPart_pt[j] <<endl;

                  hist_pt_H->Fill(GenPart_pt[j]);
                  vecH.push_back({GenPart_pt[j],GenPart_eta[j],GenPart_phi[j],GenPart_mass[j]});
                }
                else if (GenPart_pdgId[j]==23) {
                  //cout << "GenPart_pt[j]==23:" << GenPart_pt[j] <<endl;

                  pt_Z.push_back(GenPart_pt[j]);
                  vecZ.push_back({GenPart_pt[j],GenPart_eta[j],GenPart_phi[j],GenPart_mass[j]});

                }
                else {
                  if (GenPart_pt[j] !=0) {
                    //cout << "GenPart_pt[j]:!=0" << GenPart_pt[j] <<endl;

                    vecQuark.push_back({GenPart_pt[j],GenPart_eta[j],GenPart_phi[j],GenPart_mass[j]});
                      }
                }

            }


        }
        if (pt_Z.size()==2 && vecQuark.size()==2)
        {
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


            for (int h=0; h <= (nGenPart[0]-1); h++) {
                if (GenPart_genPartIdxMother[h]==H_index_children[H_index_children.size()-1]) {
                  hist_H_pdgid_children->Fill(GenPart_pdgId[h]);
                  //cout << "event: "<< i << " "<< "childer index h: " << h << "" << "pdgid: " << GenPart_pdgId[h] <<endl;
                }
            }
        }
        else
        {

          //cout <<"event number: " << i <<endl;
          count++;

        }



        H_index_children.clear();
        index_parent_quark.clear();
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

         c12->cd();
         hist_H_pdgid_children->Draw();
         hist_H_pdgid_children->Print("all");
         c12->SaveAs("pdgId of Higgs children.pdf");





     readf->Write();
         readf->Close();
}
