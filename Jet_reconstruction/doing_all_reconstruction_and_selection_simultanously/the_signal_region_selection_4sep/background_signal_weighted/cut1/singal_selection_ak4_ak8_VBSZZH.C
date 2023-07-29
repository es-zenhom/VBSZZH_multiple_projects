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


TCanvas* c1= new TCanvas();
TCanvas* c2= new TCanvas();
TCanvas* c3= new TCanvas();
TCanvas* c4= new TCanvas();
TCanvas* c5= new TCanvas();
TCanvas* c6= new TCanvas();
TCanvas* c7= new TCanvas();
TCanvas* c8= new TCanvas();
TCanvas* c9= new TCanvas();
TCanvas* c10= new TCanvas();
TCanvas* c11= new TCanvas();
TCanvas* c12= new TCanvas();
TCanvas* c13= new TCanvas();
TCanvas* c14= new TCanvas();
TCanvas* c15= new TCanvas();
TCanvas* c16= new TCanvas();
TCanvas* c17= new TCanvas();
TCanvas* c18= new TCanvas();
TCanvas* c19= new TCanvas();
TCanvas* c20= new TCanvas();
TCanvas* c21= new TCanvas();
TCanvas* c22= new TCanvas();
//sdnsdsadasds

//  for tjhe background enEventCount   = 1320000
 //genEventSumw    = 4.14463e+08
 //for the signal



void singal_selection_ak4_ak8_VBSZZH()
{
    // read file and TTree
    TChain* chain = new TChain("Events");
    chain->Add("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/*.root");
    //TFile* readf = new TFile ("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/*.root","READ");
    //TTree* Events = (TTree*) chain->Get("Events");
    TFile * f_output =new TFile ("sig_VBSZZH.root","recreate");

    // initatie the variables
    float GenPart_pt[333], GenPart_phi[333], GenPart_mass[333], GenPart_eta[333], Jet_pt[333],Jet_eta[333], Jet_phi[333], Jet_mass[333];
    float FatJet_eta[333], FatJet_pt[333], FatJet_phi[333], FatJet_mass[333], FatJet_particleNetMD_Xbb[333],FatJet_particleNetMD_Xqq[333],FatJet_particleNetMD_QCD[333];
    float FatJet_msoftdrop[333];
    float genWeight[333];
    int GenPart_pdgId[333],GenPart_status[333], GenPart_genPartIdxMother[333], nGenPart[333], nJet[333];
    int nFatJet[333];
    int no_events= chain->GetEntries();




    // singal selection
    std::vector<ROOT::Math::PtEtaPhiMVector> ak4_pt_eta_cut {};
    std::vector<ROOT::Math::PtEtaPhiMVector> ak8_pt_msoftdrop_cut_4d {};
    std::vector<ROOT::Math::PtEtaPhiMVector> ak4_pt_eta_cut_overlap_4d {};
    //std::vector<ROOT::Math::PtEtaPhiMVector> ak8_pt_msoftdrop_cut_4d_overlab {};
    std::vector<float> marker{};
    std::vector<float> inariant_mass_compare{};
    std::vector<vector<int>> inariant_mass_compare_index_2d{};

    std::vector<float>   vec_H_score{};

    std::vector<ROOT::Math::PtEtaPhiMVector> vec_lead_sublead_bosons_4d {};

    std::vector<float>   vec_msoftdrop_two_bosons{};
    std::vector<float>   vec_msoftdrop{};




    // point to the branches to read data from them afterwards
    chain->SetBranchAddress("GenPart_pt",&GenPart_pt);
    chain->SetBranchAddress("GenPart_phi",&GenPart_phi);
    chain->SetBranchAddress("GenPart_mass",&GenPart_mass);
    chain->SetBranchAddress("GenPart_eta",&GenPart_eta);
    chain->SetBranchAddress("GenPart_pdgId",&GenPart_pdgId);
    chain->SetBranchAddress("GenPart_status",&GenPart_status);
    chain->SetBranchAddress("GenPart_genPartIdxMother",&GenPart_genPartIdxMother);
    chain->SetBranchAddress("nGenPart",&nGenPart);

    chain->SetBranchAddress("Jet_pt",&Jet_pt);
    chain->SetBranchAddress("Jet_eta",&Jet_eta);
    chain->SetBranchAddress("Jet_phi",&Jet_phi);
    chain->SetBranchAddress("Jet_mass",&Jet_mass);
    chain->SetBranchAddress("nJet",&nJet);
    // do the FatJet setting branches
    chain->SetBranchAddress("FatJet_eta",&FatJet_eta);
    chain->SetBranchAddress("FatJet_pt",&FatJet_pt);
    chain->SetBranchAddress("FatJet_phi",&FatJet_phi);
    chain->SetBranchAddress("FatJet_mass",&FatJet_mass);
    chain->SetBranchAddress("FatJet_particleNetMD_Xbb",&FatJet_particleNetMD_Xbb);
    chain->SetBranchAddress("FatJet_particleNetMD_Xqq",&FatJet_particleNetMD_Xqq);
    chain->SetBranchAddress("FatJet_particleNetMD_QCD",&FatJet_particleNetMD_QCD);
    chain->SetBranchAddress("nFatJet",&nFatJet);
    chain->SetBranchAddress("FatJet_msoftdrop",&FatJet_msoftdrop);

    chain->SetBranchAddress("genWeight",&genWeight);






    // create the histograms
    TH1D* hist_pt_leadVBFQuark = new TH1D ("hist_pt_leadVBFQuark", "pT of leading VBFquark", 80,0,250);
    TH1D* hist_pt_subleadVBFQuark = new TH1D ("hist_pt_subleadVBFQuark", "pT of subleading VBFquark", 80,0,160);
    TH1D* hist_eta_leadVBFQuark = new TH1D ("hist_eta_leadVBFQuark", "eta of leading VBFquark", 80,-6,6);
    TH1D* hist_eta_subleadVBFQuark = new TH1D ("hist_eta_subleadVBFQuark", "eta of subleading VBFquark", 80,-6,6);
    TH1D* hist_phi_leadVBFQuark = new TH1D ("hist_phi_leadVBFQuark", "phi of leading VBFquark", 80,-6,6);
    TH1D* hist_phi_subleadVBFQuark = new TH1D ("hist_phi_subleadVBFQuark", "phi of subleading VBFquark", 80,-6,6);

    TH1D* hist_pt_H_fatjet = new TH1D ("hist_pt_H_fatjet", "pT of Higgs", 80,0,1800);
    TH1D* hist_eta_H_fatjet = new TH1D ("hist_eta_H_fatjet", "eta of Higgs", 80,-6,6);
    TH1D* hist_phi_H_fatjet = new TH1D ("hist_phi_H_fatjet", "phi of Higgs", 80,-6,6);
    TH1D* hist_m_H_msoftdrop = new TH1D ("hist_m_H_msoftdrop"," msoftdrop of H (mass)", 80,0,150);

    TH1D* hist_pt_leadboson_fatjet = new TH1D ("hist_pt_leadboson_fatjet", "pT of leadboson", 80,0,1800);
    TH1D* hist_eta_leadboson_fatjet = new TH1D ("hist_eta_leadboson_fatjet", "eta of leadboson", 80,-6,6);
    TH1D* hist_phi_leadboson_fatjet = new TH1D ("hist_phi_leadboson_fatjet", "phi of leadboson", 80,-6,6);
    TH1D* hist_m_leadboson_msoftdrop = new TH1D ("hist_m_leadboson_msoftdrop"," msoftdrop of leadboson (mass)", 80,0,150);

    TH1D* hist_pt_subleadboson_fatjet = new TH1D ("hist_pt_subleadboson_fatjet", "pT of subleadboson", 80,0,1800);
    TH1D* hist_eta_subleadboson_fatjet = new TH1D ("hist_eta_subleadboson_fatjet", "eta of subleadboson", 80,-6,6);
    TH1D* hist_phi_subleadboson_fatjet = new TH1D ("hist_phi_subleadboson_fatjet", "phi of subleadboson", 80,-6,6);
    TH1D* hist_m_subleadboson_msoftdrop = new TH1D ("hist_m_subleadboson_msoftdrop"," msoftdrop of subleadboson (mass)", 80,0,150);

    TH1D* hist_mjj_mass_of_twoVBFjets = new TH1D ("hist_mjj_mass_of_twoVBFjets"," mjj_mass_of_twoVBFjets", 80,0,2500);
    TH1D* hist_absDelta_eta_of_twoVBFjets = new TH1D ("hist_absDelta_eta_of_twoVBFjets"," absDelta_eta_mass_of_twoVBFjets", 80,0,10);
    TH1D* hist_mass_HBosonBoson_system = new TH1D ("hist_mass_HBosonBoson_system"," mass of H_Boson_Boson system", 80,0,3000);





int numberm=0;
int numberm1=0;
int overlab1=0;
int cut1=0;
int cut2=0;
int cut3=0;
int nooffat3=0;
float sumweights=0;
//getting the summation of all weights
for (int iii = 0; iii < no_events; iii++)
{
  chain->GetEntry(iii);

  sumweights=sumweights+genWeight[0];


}
cout << "summweights: " << sumweights<<endl;
    for (int i=0; i<no_events; i++)
    {
        chain->GetEntry(i);
        if(i% 10000 ==0) cout<<i<<endl;
        // int Zsublead_index = 9999;
        // int Zlead_index= 9999;
        // int x= 9999;
        // int y=9999;

if (nFatJet[0]>0)
{
// nevents++;

         // do the events weights:
         float weight_of_eachevent= (genWeight[0]/sumweights)*0.0008036*1000*137;
         //doing the signal region selction (in this part (i assume i dont know the gen level information and procced from that so i start with all the events i had in the beginging))
         if (nJet[0]>=2 && nFatJet[0]>=3)
         {
              numberm++;
         }
         for (int i1 = 0; i1 < nJet[0]; i1++)
         {
             if (Jet_pt[i1]>30 && TMath::Abs(Jet_eta[i1]<4.5))
             {
                  ak4_pt_eta_cut.push_back({Jet_pt[i1],Jet_eta[i1],Jet_phi[i1],Jet_mass[i1]});

             }
         }

         for (int i2 = 0; i2 < nFatJet[0]; i2++)
         {
             if (FatJet_pt[i2]>180 &&FatJet_msoftdrop[i2]>40)
             {
                 ak8_pt_msoftdrop_cut_4d.push_back({FatJet_pt[i2],FatJet_eta[i2],FatJet_phi[i2],FatJet_mass[i2]});
                 vec_H_score.push_back(FatJet_particleNetMD_Xbb[i2]/(FatJet_particleNetMD_Xbb[i2]+FatJet_particleNetMD_QCD[i2]));
                 vec_msoftdrop.push_back(FatJet_msoftdrop[i2]);


             }
         }


             numberm1++;
         for (int i3 = 0; i3 < ak4_pt_eta_cut.size(); i3++)
         {
              for (int i4 = 0; i4 < ak8_pt_msoftdrop_cut_4d.size(); i4++)
              {
                  double drrr1= sqrt(pow(TMath::Abs(ak4_pt_eta_cut[i3].eta()-ak8_pt_msoftdrop_cut_4d[i4].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(ak4_pt_eta_cut[i3],ak8_pt_msoftdrop_cut_4d[i4])),2));
                  if (drrr1<0.8)
                  {
                      marker.push_back(1);
                      overlab1++;
                      //cout << "overlabevent: " << i <<endl;
                  }
              }
              //cout << "marker size: " <<marker.size() << "event: " << i <<endl;
              //cout << "i3: " << i3<< "event : " <<i << endl;
              if (marker.size()==0)
              {
                  ak4_pt_eta_cut_overlap_4d.push_back({ak4_pt_eta_cut[i3].pt(),ak4_pt_eta_cut[i3].eta(),ak4_pt_eta_cut[i3].phi(),ak4_pt_eta_cut[i3].mass()});
              }
              marker.clear();
         }
         if (ak4_pt_eta_cut_overlap_4d.size()>=2)
         {
             cut1++;
             if (ak8_pt_msoftdrop_cut_4d.size()>=3)
             {
                 cut2++;
                 //cout << "ak4_pt_eta_cut_overlap_4d.size(): " <<ak4_pt_eta_cut_overlap_4d.size()<< endl;
                 for (int i5 = 0; i5 < ak4_pt_eta_cut_overlap_4d.size()-1; i5++)
                 {
                      //cout <<"i5:"<<i5<< endl;
                     for (int i6 = i5+1; i6 < ak4_pt_eta_cut_overlap_4d.size(); i6++)
                     {
                          //cout <<"i6:"<<i6<< endl;
                          inariant_mass_compare.push_back((ak4_pt_eta_cut_overlap_4d[i5]+ak4_pt_eta_cut_overlap_4d[i6]).mass());
                          // cout << "inariant_mass_compare: "<< (ak4_pt_eta_cut_overlap_4d[i5]+ak4_pt_eta_cut_overlap_4d[i6]).mass()<< endl;
                          // cout << "i5: " << i5 <<endl;
                          // cout << "i6: " << i6 <<endl;

                          inariant_mass_compare_index_2d.push_back({i5,i6});

                     }
                 }
                 int position_first_quark_with_high_mqq=inariant_mass_compare_index_2d[max_element(inariant_mass_compare.begin(),inariant_mass_compare.end())-inariant_mass_compare.begin()][0];
                 int position_second_quark_with_high_mqq=inariant_mass_compare_index_2d[max_element(inariant_mass_compare.begin(),inariant_mass_compare.end())-inariant_mass_compare.begin()][1];
                 if ((TMath::Abs(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta()-ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta()))>6.5)
                 {

                      // this previous if is for cutting over (hist_absDelta_eta_of_twoVBFjets > 6.5)
                       cut3++;

                       if (ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].pt()>ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].pt())
                       {
                            hist_pt_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].pt(),weight_of_eachevent);
                            hist_pt_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].pt(),weight_of_eachevent);
                            hist_eta_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta(),weight_of_eachevent);
                            hist_eta_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta(),weight_of_eachevent);
                            hist_phi_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].phi(),weight_of_eachevent);
                            hist_phi_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].phi(),weight_of_eachevent);

                       }
                       else
                       {
                            hist_pt_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].pt(),weight_of_eachevent);
                            hist_pt_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].pt(),weight_of_eachevent);
                            hist_eta_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta(),weight_of_eachevent);
                            hist_eta_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta(),weight_of_eachevent);
                            hist_phi_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].phi(),weight_of_eachevent);
                            hist_phi_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].phi(),weight_of_eachevent);

                       }
                       // create mjj (invariant mass of the two vbf jets)
                       hist_mjj_mass_of_twoVBFjets->Fill((ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq]+ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq]).mass(),weight_of_eachevent);
                       // get the abs eta of the two vbf quarks
                       hist_absDelta_eta_of_twoVBFjets->Fill(TMath::Abs(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta()-ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta()),weight_of_eachevent);

                       // for (int i7 = 0; i7 < ak8_pt_msoftdrop_cut_4d.size(); i7++)
                       // {
                       //     vec_H_score.push_back(FatJet_particleNetMD_Xbb[i7]/(FatJet_particleNetMD_Xbb[i7]+FatJet_particleNetMD_QCD[i7]));
                       // }

                       int position_max_H_score=max_element(vec_H_score.begin(),vec_H_score.end())-vec_H_score.begin();
                       hist_pt_H_fatjet->Fill(ak8_pt_msoftdrop_cut_4d[position_max_H_score].pt(),weight_of_eachevent);
                       hist_eta_H_fatjet->Fill(ak8_pt_msoftdrop_cut_4d[position_max_H_score].eta(),weight_of_eachevent);
                       hist_phi_H_fatjet->Fill(ak8_pt_msoftdrop_cut_4d[position_max_H_score].phi(),weight_of_eachevent);
                       hist_m_H_msoftdrop->Fill(vec_msoftdrop[position_max_H_score],weight_of_eachevent);
                       // if (ak8_pt_msoftdrop_cut_4d.size()==3)
                       // {
                        nooffat3++;
                        for (int i8 = 0; i8 < ak8_pt_msoftdrop_cut_4d.size(); i8++)
                        {
                             if (i8!=position_max_H_score)
                             {
                                  vec_lead_sublead_bosons_4d.push_back({ak8_pt_msoftdrop_cut_4d[i8].pt(),ak8_pt_msoftdrop_cut_4d[i8].eta(),ak8_pt_msoftdrop_cut_4d[i8].phi(),ak8_pt_msoftdrop_cut_4d[i8].mass()});
                                  vec_msoftdrop_two_bosons.push_back(vec_msoftdrop[i8]);
                             }
                        }
                        if (vec_lead_sublead_bosons_4d[0].pt()>vec_lead_sublead_bosons_4d[1].pt())
                        {
                            hist_pt_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[0].pt(),weight_of_eachevent);
                            hist_pt_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[1].pt(),weight_of_eachevent);
                            hist_eta_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[0].eta(),weight_of_eachevent);
                            hist_eta_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[1].eta(),weight_of_eachevent);
                            hist_phi_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[0].phi(),weight_of_eachevent);
                            hist_phi_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[1].phi(),weight_of_eachevent);
                            hist_m_leadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[0],weight_of_eachevent);
                            hist_m_subleadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[1],weight_of_eachevent);

                        }
                        else
                        {
                            hist_pt_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[1].pt(),weight_of_eachevent);
                            hist_pt_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[0].pt(),weight_of_eachevent);
                            hist_eta_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[1].eta(),weight_of_eachevent);
                            hist_eta_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[0].eta(),weight_of_eachevent);
                            hist_phi_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[1].phi(),weight_of_eachevent);
                            hist_phi_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[0].phi(),weight_of_eachevent);
                            hist_m_leadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[1],weight_of_eachevent);
                            hist_m_subleadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[0],weight_of_eachevent);
                        }

                        // invariant mass of H_Boson_Boson system
                      hist_mass_HBosonBoson_system->Fill((ak8_pt_msoftdrop_cut_4d[position_max_H_score]+vec_lead_sublead_bosons_4d[0]+vec_lead_sublead_bosons_4d[1]).mass(),weight_of_eachevent);

                       // }

               }

             }


         }


         ak4_pt_eta_cut.clear();
         ak8_pt_msoftdrop_cut_4d.clear();
         ak4_pt_eta_cut_overlap_4d.clear();
         //ak8_pt_msoftdrop_cut_4d_overlab.clear();
         marker.clear();
         inariant_mass_compare.clear();
         inariant_mass_compare_index_2d.clear();
         vec_H_score.clear();
         vec_lead_sublead_bosons_4d.clear();
         vec_msoftdrop_two_bosons.clear();
         vec_msoftdrop.clear();

// the first bracked here is for the if condition that nFatJets large than zero to start redaing the ttres and all that cuz other events doesnt have fat jet in this root file
}     }


         cout << "numberm: " << numberm << endl;
         cout << "numberm1: " << numberm1 << endl;
         cout << "overlab1: " << overlab1 << endl;
         cout << "cut2: " << cut2 << endl;
         cout << "cut1: " << cut1 << endl;
         cout << "cut3: " << cut3 << endl;
         cout << "nooffat3: " << nooffat3 << endl;


         f_output->cd();
         hist_pt_leadVBFQuark->Write();
         hist_pt_subleadVBFQuark->Write();
         hist_eta_leadVBFQuark->Write();
         hist_eta_subleadVBFQuark->Write();
         hist_phi_subleadVBFQuark->Write();
         hist_pt_H_fatjet->Write();
         hist_eta_H_fatjet->Write();
         hist_phi_H_fatjet->Write();
         hist_m_H_msoftdrop->Write();
         hist_pt_leadboson_fatjet->Write();
         hist_eta_leadboson_fatjet->Write();
         hist_phi_leadboson_fatjet->Write();
         hist_m_leadboson_msoftdrop->Write();
         hist_pt_subleadboson_fatjet->Write();
         hist_eta_subleadboson_fatjet->Write();
         hist_phi_subleadboson_fatjet->Write();
         hist_m_subleadboson_msoftdrop->Write();
         hist_mjj_mass_of_twoVBFjets->Write();
         hist_absDelta_eta_of_twoVBFjets->Write();
         hist_mass_HBosonBoson_system->Write();
         // ->Write();

         // c1->cd();
         // hist_pt_leadVBFQuark->Draw();
         // c1->SaveAs("pT of leading VBFquark.pdf");
         //
         // c2->cd();
         // hist_pt_subleadVBFQuark->Draw();
         // c2->SaveAs("pT of subleading VBFquark.pdf");
         //
         // c3->cd();
         // hist_eta_leadVBFQuark->Draw();
         // c3->SaveAs("eta of leading VBFquark.pdf");
         //
         // c4->cd();
         // hist_eta_subleadVBFQuark->Draw();
         // c4->SaveAs("eta of subleading VBFquark.pdf");
         //
         // c5->cd();
         // hist_phi_leadVBFQuark->Draw();
         // c5->SaveAs("phi of leading VBFquark.pdf");
         //
         // c6->cd();
         // hist_phi_subleadVBFQuark->Draw();
         // c6->SaveAs("phi of subleading VBFquark.pdf");
         //
         // c7->cd();
         // hist_pt_H_fatjet->Draw();
         // c7->SaveAs("pT of Higgs.pdf");
         //
         // c8->cd();
         // hist_eta_H_fatjet->Draw();
         // c8->SaveAs("eta of Higgs.pdf");
         //
         // c9->cd();
         // hist_phi_H_fatjet->Draw();
         // c9->SaveAs("phi of Higgs.pdf");
         //
         // c10->cd();
         // hist_m_H_msoftdrop->Draw();
         // c10->SaveAs("msoftdrop of H (mass).pdf");
         //
         // c11->cd();
         // hist_pt_leadboson_fatjet->Draw();
         // c11->SaveAs("pT of leadboson.pdf");
         //
         // c12->cd();
         // hist_eta_leadboson_fatjet->Draw();
         // c12->SaveAs("eta of leadboson.pdf");
         //
         // c13->cd();
         // hist_phi_leadboson_fatjet->Draw();
         // c13->SaveAs("phi of leadboson.pdf");
         //
         // c14->cd();
         // hist_m_leadboson_msoftdrop->Draw();
         // c14->SaveAs("msoftdrop of leadboson (mass).pdf");
         //
         // c15->cd();
         // hist_pt_subleadboson_fatjet->Draw();
         // c15->SaveAs("pT of subleadboson.pdf");
         //
         // c16->cd();
         // hist_eta_subleadboson_fatjet->Draw();
         // c16->SaveAs("eta of subleadboson.pdf");
         //
         // c17->cd();
         // hist_phi_subleadboson_fatjet->Draw();
         // c17->SaveAs("phi of subleadboson.pdf");
         //
         // c18->cd();
         // hist_m_subleadboson_msoftdrop->Draw();
         // c18->SaveAs("msoftdrop of subleadboson (mass).pdf");
         //
         //
         // c19->cd();
         // hist_mjj_mass_of_twoVBFjets->Draw();
         // c19->SaveAs("mjj_mass_of_twoVBFjets.pdf");
         //
         // c20->cd();
         // hist_absDelta_eta_of_twoVBFjets->Draw();
         // c20->SaveAs("absDelta_eta_mass_of_twoVBFjets.pdf");
         //
         // c21->cd();
         // hist_mass_HBosonBoson_system->Draw();
         // c21->SaveAs("mass of H_Boson_Boson system.pdf");

















     //readf->Write();
         //readf->Close();
     chain->Write();
         //chain->Close();
}
