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
#include <Math/VectorUtil.h>


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
// auto c12= new TCanvas;
auto c13= new TCanvas;
auto c14= new TCanvas;
auto c15= new TCanvas;
auto c16= new TCanvas;
auto c17= new TCanvas;
auto c18= new TCanvas;
auto c19= new TCanvas;
auto c20= new TCanvas;
auto c21= new TCanvas;
auto c22= new TCanvas;
auto c23= new TCanvas;
auto c24= new TCanvas;
auto c25= new TCanvas;
auto c26= new TCanvas;
auto c27= new TCanvas;
auto c28= new TCanvas;
auto c29= new TCanvas;
auto c30= new TCanvas;
auto c31= new TCanvas;
auto c32= new TCanvas;
auto c33= new TCanvas;
auto c34= new TCanvas;
auto c35= new TCanvas;



void VBSZZH_genpart111()
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
    std::vector<int> Zlead_index_children{};
    std::vector<int> Zsublead_index_children{};
    std::vector<int> Z_lead_sublead_index{};

    std::vector<int> place_of_Zlead_qurks{};
    std::vector<int> place_of_Zsublead_qurks{};
    std::vector<int> place_of_H_qurksbb{};
    std::vector<int> place_of_quarks_outgoing{};






    std::vector<ROOT::Math::PtEtaPhiMVector> vecZ {};

    std::vector<ROOT::Math::PtEtaPhiMVector> vecH {};
    std::vector<ROOT::Math::PtEtaPhiMVector> vecQuark {};

    std::vector<ROOT::Math::PtEtaPhiMVector> vec4d_bb_H {};
    std::vector<ROOT::Math::PtEtaPhiMVector> vec4d_qq_Zlead {};
    std::vector<ROOT::Math::PtEtaPhiMVector> vec4d_qq_Zsublead {};
    std::vector<ROOT::Math::PtEtaPhiMVector> vec4d_qq_outgoing {};







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
    // TH1D* hist_H_pdgid_children = new TH1D ("hist_H_pdgid_children", "pdgId of Higgs children", 100,-50,50);
    TH1D* hist_H_pdgid_children_bb = new TH1D ("hist_H_pdgid_children_bb", "pdgId of Higgs children bb", 100,-50,50);
    TH1D* hist_Zlead_pdgid_children = new TH1D ("hist_Zlead_pdgid_children", "pdgId of leading Z children", 100,-50,50);
    TH1D* hist_Zsublead_pdgid_children = new TH1D ("hist_Zsublead_pdgid_children", "pdgId of subleading Z children", 100,-50,50);
    TH1D* hist_Zlead_pdgid_children_restriction = new TH1D ("hist_Zlead_pdgid_children_restriction", "pdgId of leading Z children_uu_cc_dd_ss_bb", 100,-50,50);
    TH1D* hist_Zsublead_pdgid_children_restriction = new TH1D ("hist_subZlead_pdgid_children_restriction", "pdgId of subleading Z children_uu_cc_dd_ss_bb", 100,-50,50);

// the histograms for the restirction staff H->bb, Zlead->qq, Zsublead->qq
TH1D* hist_pt_H_bb = new TH1D ("hist_pt_H_bb", "pT of H->bb system", 80,0,450);
TH1D* hist_pt_Zlead_qq = new TH1D ("hist_pt_Zlead_qq", "pT of Zlead->qq system", 80,0,450);
TH1D* hist_pt_Zsublead_qq = new TH1D ("hist_pt_Zsublead_qq", "pT of Zsublead->qq system", 80,0,450);
TH1D* hist_m_H_bb = new TH1D ("hist_m_H_bb","invariant mass of H->bb system", 80,0,150);
TH1D* hist_m_Zlead_qq = new TH1D ("hist_m_Zlead_qq","invariant mass of Zlead->qq system", 80,0,150);
TH1D* hist_m_Zsublead_qq = new TH1D ("hist_m_Zsublead_qq","invariant mass of Zsublead->qq system", 80,0,150);
TH1D* hist_eta_H_bb = new TH1D ("hist_eta_H_bb", "eta of H->bb system", 80,-6,6);
TH1D* hist_eta_Zlead_qq = new TH1D ("hist_eta_Zlead_qq", "eta of Zlead->qq system", 80,-6,6);
TH1D* hist_eta_Zsublead_qq = new TH1D ("hist_eta_subZlead_qq", "eta of subZlead->qq system", 80,-6,6);
TH1D* hist_abs_EtaDiff_H_bb = new TH1D ("hist_abs_EtaDiff_H_bb", "abs eta difference between quarks of H->bb system", 80,0,20);
TH1D* hist_abs_EtaDiff_Zlead_qq = new TH1D ("hist_abs_EtaDiff_Zlead_qq", "abs eta difference between quarks of Zlead->qq system", 80,0,20);
TH1D* hist_abs_EtaDiff_Zsublead_qq = new TH1D ("hist_abs_EtaDiff_Zsublead_qq", "abs eta difference between quarks of Zsublead->qq system", 80,0,20);
TH1D* hist_abs_phiDiff_H_bb = new TH1D ("hist_abs_phiDiff_H_bb", "abs phi difference between quarks of H->bb system", 80,0,20);
TH1D* hist_abs_phiDiff_Zlead_qq = new TH1D ("hist_abs_phiDiff_Zlead_qq", "abs phi difference between quarks of Zlead->qq system", 80,0,20);
TH1D* hist_abs_phiDiff_Zsublead_qq = new TH1D ("hist_abs_phiDiff_Zsublead_qq", "abs phi difference between quarks of Zsublead->qq system", 80,0,20);
TH1D* hist_abs_deltaR_H_bb = new TH1D ("hist_abs_deltaR_H_bb", "delta R of H->bb system", 80,0,40);
TH1D* hist_abs_deltaR_Zlead_qq = new TH1D ("hist_abs_deltaR_Zlead_qq", "delta R of Zlead->qq system", 80,0,40);
TH1D* hist_abs_deltaR_Zsublead_qq = new TH1D ("hist_abs_deltaR_Zsublead_qq", "delta R of Zsublead->qq system", 80,0,40);





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
int count_leftover=0;
    for (int i=0; i<no_events; i++)
    {
        Events->GetEntry(i);
        int Zsublead_index = 9999;
        int Zlead_index= 9999;
        int x= 9999;
        int y=9999;
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

            if (GenPart_pdgId[j]==23 && Z_lead_sublead_index.size()<2) // just getting the mother id of the two z and then would see who is subleading and leading
            {
                Z_lead_sublead_index.push_back(j);
            }

            if ( Z_lead_sublead_index.size()==2)
            {
                if (GenPart_pt[Z_lead_sublead_index[0]]> GenPart_pt[Z_lead_sublead_index[1]] )
                {
                   Zlead_index= Z_lead_sublead_index[0];
                   Zsublead_index= Z_lead_sublead_index[1];
                }
                  else
                  {
                     Zlead_index= Z_lead_sublead_index[1];
                     Zsublead_index= Z_lead_sublead_index[0];
                  }


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
                    place_of_quarks_outgoing.push_back(j);
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
                if (GenPart_genPartIdxMother[h]==H_index_children[H_index_children.size()-1] && TMath::Abs(GenPart_pdgId[h])==5 ) {
                  //hist_H_pdgid_children->Fill(GenPart_pdgId[h]);
                  hist_H_pdgid_children_bb->Fill(GenPart_pdgId[h]);
                  place_of_H_qurksbb.push_back(h);


                  //cout << "event: "<< i << " "<< "childer index h: " << h << "" << "pdgid: " << GenPart_pdgId[h] <<endl;
                }
            }

            x = Zsublead_index;
            y = Zlead_index;
            //cout << "y = Zlead_index:: " << y <<endl;
            //cout << "x = Zlead_index:: " << x <<endl;

            for (int s = 0; s <= (nGenPart[0]-1); s++)
            {
                 if (GenPart_pdgId[s]==23 && Z_lead_sublead_index.size()==2 && s!= Z_lead_sublead_index[0] && s!= Z_lead_sublead_index[1]  )
                 {
                     if (GenPart_genPartIdxMother[s] == y) // then this is z results from the leading parent z
                     {
                         y = s;
                         //cout << "trace lead cascade index:  " << s <<endl;
                         //cout << "y value:   " << y <<endl;
                         Zlead_index_children.push_back(s);
                     }
                         else
                          {
                                 x = s;
                                 //cout << "x value:   " << x <<endl;

                                Zsublead_index_children.push_back(s);
                         }


                 }
            }
            for (int q = 0; q <= (nGenPart[0]-1); q++)
            {
                if (GenPart_genPartIdxMother[q]==Zlead_index_children.back())
                {
                    hist_Zlead_pdgid_children->Fill(GenPart_pdgId[q]);


                     // now we do the restriction for leading z zz->uu, zz->dd, zz->cc, zz->ss, zz->bb
                    if (TMath::Abs(GenPart_pdgId[q])==1 or TMath::Abs(GenPart_pdgId[q])==2 or TMath::Abs(GenPart_pdgId[q])==3 or TMath::Abs(GenPart_pdgId[q])==4 or TMath::Abs(GenPart_pdgId[q])==5)
                    {
                        hist_Zlead_pdgid_children_restriction->Fill(GenPart_pdgId[q]);
                        place_of_Zlead_qurks.push_back(q);
                    }
                    //cout << "event: "<< i << " "<< "childer index Zlead " << q << "" << "pdgid: " << GenPart_pdgId[q] <<endl;


                }
                    else if (GenPart_genPartIdxMother[q]==Zsublead_index_children.back())
                    {
                        hist_Zsublead_pdgid_children->Fill(GenPart_pdgId[q]);
                        // now we do the restriction for sub-leading z zz->uu, zz->dd, zz->cc, zz->ss, zz->bb

                        if (TMath::Abs(GenPart_pdgId[q])==1 or TMath::Abs(GenPart_pdgId[q])==2 or TMath::Abs(GenPart_pdgId[q])==3 or TMath::Abs(GenPart_pdgId[q])==4 or TMath::Abs(GenPart_pdgId[q])==5)
                        {
                            hist_Zsublead_pdgid_children_restriction->Fill(GenPart_pdgId[q]);
                            place_of_Zsublead_qurks.push_back(q);

                        }

                        //cout << "event: "<< i << " "<< "childer index Zsublead " << q << "" << "pdgid: " << GenPart_pdgId[q] <<endl;

                    }

            }

            if (place_of_H_qurksbb.size()==2 && place_of_Zlead_qurks.size()==2 && place_of_Zsublead_qurks.size()==2)
            // check if those vectors are filled with events which H->bb and (Z-> uu, cc, dd, bb, or ss)
            {
                 count_leftover++;
                 vec4d_bb_H.push_back({GenPart_pt[place_of_H_qurksbb[0]],GenPart_eta[place_of_H_qurksbb[0]],GenPart_phi[place_of_H_qurksbb[0]],GenPart_mass[place_of_H_qurksbb[0]]});
                 vec4d_bb_H.push_back({GenPart_pt[place_of_H_qurksbb[1]],GenPart_eta[place_of_H_qurksbb[1]],GenPart_phi[place_of_H_qurksbb[1]],GenPart_mass[place_of_H_qurksbb[1]]});
                 vec4d_qq_Zlead.push_back({GenPart_pt[place_of_Zlead_qurks[0]],GenPart_eta[place_of_Zlead_qurks[0]],GenPart_phi[place_of_Zlead_qurks[0]],GenPart_mass[place_of_Zlead_qurks[0]]});
                 vec4d_qq_Zlead.push_back({GenPart_pt[place_of_Zlead_qurks[1]],GenPart_eta[place_of_Zlead_qurks[1]],GenPart_phi[place_of_Zlead_qurks[1]],GenPart_mass[place_of_Zlead_qurks[1]]});
                 vec4d_qq_Zsublead.push_back({GenPart_pt[place_of_Zsublead_qurks[0]],GenPart_eta[place_of_Zsublead_qurks[0]],GenPart_phi[place_of_Zsublead_qurks[0]],GenPart_mass[place_of_Zsublead_qurks[0]]});
                 vec4d_qq_Zsublead.push_back({GenPart_pt[place_of_Zsublead_qurks[1]],GenPart_eta[place_of_Zsublead_qurks[1]],GenPart_phi[place_of_Zsublead_qurks[1]],GenPart_mass[place_of_Zsublead_qurks[1]]});
                 vec4d_qq_outgoing.push_back({GenPart_pt[place_of_quarks_outgoing[0]],GenPart_eta[place_of_quarks_outgoing[0]],GenPart_phi[place_of_quarks_outgoing[0]],GenPart_mass[place_of_quarks_outgoing[0]]});
                 vec4d_qq_outgoing.push_back({GenPart_pt[place_of_quarks_outgoing[1]],GenPart_eta[place_of_quarks_outgoing[1]],GenPart_phi[place_of_quarks_outgoing[1]],GenPart_mass[place_of_quarks_outgoing[1]]});
                 //cout <<" event number: " << i << endl;

                 hist_pt_H_bb->Fill((vec4d_bb_H[0]+vec4d_bb_H[1]).pt());
                 hist_pt_Zlead_qq->Fill((vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).pt());
                 hist_pt_Zsublead_qq->Fill((vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).pt());
                 hist_m_H_bb->Fill((vec4d_bb_H[0]+vec4d_bb_H[1]).mass());
                 hist_m_Zlead_qq->Fill((vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).mass());
                 hist_m_Zsublead_qq->Fill((vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).mass());
                 hist_eta_H_bb->Fill((vec4d_bb_H[0]+vec4d_bb_H[1]).eta());
                 hist_eta_Zlead_qq->Fill((vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).eta());
                 hist_eta_Zsublead_qq->Fill((vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).eta());
                 hist_abs_EtaDiff_H_bb->Fill(TMath::Abs(vec4d_bb_H[0].eta()-vec4d_bb_H[1].eta()));
                 hist_abs_EtaDiff_Zlead_qq->Fill(TMath::Abs(vec4d_qq_Zlead[0].eta()-vec4d_qq_Zlead[1].eta()));
                 hist_abs_EtaDiff_Zsublead_qq->Fill(TMath::Abs(vec4d_qq_Zsublead[0].eta()-vec4d_qq_Zsublead[1].eta()));

                 hist_abs_phiDiff_H_bb->Fill(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_bb_H[0],vec4d_bb_H[1])));
                 hist_abs_phiDiff_Zlead_qq->Fill(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_qq_Zlead[0],vec4d_qq_Zlead[1])));
                 hist_abs_phiDiff_Zsublead_qq->Fill(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_qq_Zsublead[0],vec4d_qq_Zsublead[1])));

                 hist_abs_deltaR_H_bb->Fill(sqrt(pow(TMath::Abs(vec4d_bb_H[0].eta()-vec4d_bb_H[1].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_bb_H[0],vec4d_bb_H[1])),2)));
                 hist_abs_deltaR_Zlead_qq->Fill(sqrt(pow(TMath::Abs(vec4d_qq_Zlead[0].eta()-vec4d_qq_Zlead[1].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_qq_Zlead[0],vec4d_qq_Zlead[1])),2)));
                 hist_abs_deltaR_Zsublead_qq->Fill(sqrt(pow(TMath::Abs(vec4d_qq_Zsublead[0].eta()-vec4d_qq_Zsublead[1].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_qq_Zsublead[0],vec4d_qq_Zsublead[1])),2)));





             }



        }
        else
        {

          //cout <<"event number: " << i <<endl;
          count++;

        }



        H_index_children.clear();
        Z_lead_sublead_index.clear();
        Zlead_index_children.clear();
        Zsublead_index_children.clear();
        index_parent_quark.clear();
        vecQuark.clear();
        vecH.clear();
        vecZ.clear();
        pt_Z.clear();

        place_of_Zlead_qurks.clear();
        place_of_Zsublead_qurks.clear();
        place_of_H_qurksbb.clear();
        place_of_quarks_outgoing.clear();


        vec4d_bb_H.clear();
        vec4d_qq_Zlead.clear();
        vec4d_qq_Zsublead.clear();
        vec4d_qq_outgoing.clear();
     }

         cout << "number of left-over events: " << count_leftover << endl;
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

         // c12->cd();
         // hist_H_pdgid_children->Draw();
         // hist_H_pdgid_children->Print("all");
         // c12->SaveAs("pdgId of Higgs children.pdf");

         c13->cd();
         hist_H_pdgid_children_bb->Draw();
         //hist_H_pdgid_children_bb->Print("all");
         c13->SaveAs("pdgId of Higgs children_bb.pdf");

         c14->cd();
         hist_Zlead_pdgid_children->Draw();
         c14->SaveAs("pdgId of leading Z children.pdf");

         c15->cd();
         hist_Zsublead_pdgid_children->Draw();
         c15->SaveAs("pdgId of subleading Z children.pdf");

         c16->cd();
         hist_Zlead_pdgid_children_restriction->Draw();
         c16->SaveAs("pdgId of leading Z children_uu_cc_dd_ss_bb.pdf");

         c17->cd();
         hist_Zsublead_pdgid_children_restriction->Draw();
         c17->SaveAs("pdgId of subleading Z children_uu_cc_dd_ss_bb.pdf");

         c18->cd();
         hist_pt_H_bb->Draw();
         c18->SaveAs("pT of H->bb system.pdf");

         c19->cd();
         hist_pt_Zlead_qq->Draw();
         c19->SaveAs("pT of Zlead->qq system.pdf");

         c20->cd();
         hist_pt_Zsublead_qq->Draw();
         c20->SaveAs("pT of Zsublead->qq system.pdf");

         c21->cd();
         hist_m_H_bb->Draw();
         c21->SaveAs("invariant mass of H->bb system.pdf");

         c22->cd();
         hist_m_Zlead_qq->Draw();
         c22->SaveAs("invariant mass of Zlead->qq system.pdf");

         c23->cd();
         hist_m_Zsublead_qq->Draw();
         c23->SaveAs("invariant mass of Zsublead->qq system.pdf");

         c24->cd();
         hist_eta_H_bb->Draw();
         c24->SaveAs("eta of H->bb system.pdf");

         c25->cd();
         hist_eta_Zlead_qq->Draw();
         c25->SaveAs("eta of Zlead->qq system.pdf");

         c26->cd();
         hist_eta_Zsublead_qq->Draw();
         c26->SaveAs("eta of Zsublead->qq system.pdf");

         c27->cd();
         hist_abs_EtaDiff_H_bb->Draw();
         c27->SaveAs("abs eta difference between quarks of H->bb system.pdf");


         c28->cd();
         hist_abs_EtaDiff_Zlead_qq->Draw();
         c28->SaveAs("abs eta difference between quarks of Zlead->qq system.pdf");


         c29->cd();
         hist_abs_EtaDiff_Zsublead_qq->Draw();
         c29->SaveAs("abs eta difference between quarks of Zsublead->qq system.pdf");


         c30->cd();
         hist_abs_phiDiff_H_bb->Draw();
         c30->SaveAs("abs phi difference between quarks of H->bb system.pdf");


         c31->cd();
         hist_abs_phiDiff_Zlead_qq->Draw();
         c31->SaveAs("abs phi difference between quarks of Zlead->qq system.pdf");


         c32->cd();
         hist_abs_phiDiff_Zsublead_qq->Draw();
         c32->SaveAs("abs phi difference between quarks of Zsublead->qq system.pdf");


         c33->cd();
         hist_abs_deltaR_H_bb->Draw();
         c33->SaveAs("delta R of H->bb system.pdf");


         c34->cd();
         hist_abs_deltaR_Zlead_qq->Draw();
         c34->SaveAs("delta R of Zlead->qq system.pdf");


         c35->cd();
         hist_abs_deltaR_Zsublead_qq->Draw();
         c35->SaveAs("delta R of Zsublead->qq system.pdf");










     readf->Write();
         readf->Close();
}
