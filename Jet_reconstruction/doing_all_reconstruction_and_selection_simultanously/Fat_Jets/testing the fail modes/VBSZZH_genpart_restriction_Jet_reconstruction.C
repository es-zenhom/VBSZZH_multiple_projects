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
#include <TH2D.h>


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
auto c36 =new TCanvas;
auto c37 =new TCanvas;
auto c38 =new TCanvas;
auto c39 =new TCanvas;
auto c40 =new TCanvas;
auto c41 =new TCanvas;
auto c42 =new TCanvas;
auto c43 =new TCanvas;
auto c44 =new TCanvas;
auto c45 =new TCanvas;
auto c46 =new TCanvas;
auto c47 =new TCanvas;
auto c48 =new TCanvas;
auto c49 =new TCanvas;
auto c50 =new TCanvas;
auto c51 =new TCanvas;
auto c52 =new TCanvas;
auto c53 =new TCanvas;
auto c54 =new TCanvas;
auto c55 =new TCanvas;
auto c56 =new TCanvas;
auto c57 =new TCanvas;
auto c58 =new TCanvas;
auto c59 =new TCanvas;
auto c60 =new TCanvas;
auto c61 =new TCanvas;
auto c62 =new TCanvas;
auto c63 =new TCanvas;
auto c64 =new TCanvas;
auto c65 =new TCanvas;
auto c66 =new TCanvas;
auto c67 =new TCanvas;
auto c68 =new TCanvas;
auto c69 =new TCanvas;
auto c70 =new TCanvas;
auto c71 =new TCanvas;
auto c72 =new TCanvas;
auto c73 =new TCanvas;
auto c74 =new TCanvas;
auto c75 =new TCanvas;
auto c76 =new TCanvas;
auto c77 =new TCanvas;
auto c78 =new TCanvas;
auto c79 =new TCanvas;
auto c80 =new TCanvas;
auto c81 =new TCanvas;
auto c82 =new TCanvas;
auto c83 =new TCanvas;
auto c84 =new TCanvas;
auto c85 =new TCanvas;
auto c86 =new TCanvas;
auto c87 =new TCanvas;
auto c88 =new TCanvas;
auto c89 =new TCanvas;
auto c90 =new TCanvas;
auto c91 =new TCanvas;
auto c92 =new TCanvas;
auto c93 =new TCanvas;
auto c94 =new TCanvas;
auto c95 =new TCanvas;
auto c96 =new TCanvas;
// fat jets canvases
auto c97 =new TCanvas;
auto c98 =new TCanvas;
auto c99 =new TCanvas;
auto c100 =new TCanvas;
auto c101 =new TCanvas;
auto c102 =new TCanvas;
auto c103 =new TCanvas;
auto c104 =new TCanvas;
auto c105 =new TCanvas;
auto c106 =new TCanvas;
auto c107 =new TCanvas;
auto c108 =new TCanvas;
auto c109 =new TCanvas;
auto c110 =new TCanvas;
auto c111 =new TCanvas;
auto c112 =new TCanvas;
auto c113 =new TCanvas;
auto c114 =new TCanvas;
auto c115 =new TCanvas;
auto c116 =new TCanvas;
auto c117 =new TCanvas;
auto c118 =new TCanvas;
auto c119 =new TCanvas;
auto c120 =new TCanvas;
auto c121 =new TCanvas;





void VBSZZH_genpart_restriction_Jet_reconstruction()
{
    // read file and TTree
    TFile* readf = new TFile ("/home/eslam/uf_work/VBSZZH/merged_0.root","READ");
    TTree* Events = (TTree*) readf->Get("Events");

    // initatie the variables
    float GenPart_pt[333], GenPart_phi[333], GenPart_mass[333], GenPart_eta[333], Jet_pt[333],Jet_eta[333], Jet_phi[333], Jet_mass[333];
    float FatJet_eta[333], FatJet_pt[333], FatJet_phi[333], FatJet_mass[333], FatJet_particleNetMD_Xbb[333],FatJet_particleNetMD_Xqq[333],FatJet_particleNetMD_QCD[333];
    int GenPart_pdgId[333],GenPart_status[333], GenPart_genPartIdxMother[333], nGenPart[333], nJet[333];
    int nFatJet[333];
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

    std::vector<ROOT::Math::PtEtaPhiMVector> vec4d_leadingQuark_VBFquark {};
    std::vector<float> vec_deltaR_leadingVBFquark{};
    std::vector<float> vec_positiondeltaR_leadingVBFquark{};
    std::vector<ROOT::Math::PtEtaPhiMVector> vec4d_jets {};

    std::vector<ROOT::Math::PtEtaPhiMVector> vec4d_subleadingQuark_VBFquark {};
    std::vector<float> vec_deltaR_subleadingVBFquark{};
    std::vector<float> vec_positiondeltaR_subleadingVBFquark{};

    std::vector<float> vec_deltaR_Q1_leadZ{};
    std::vector<float> vec_positiondeltaR_Q1_leadZ{};

    std::vector<float> vec_deltaR_Q2_leadZ{};
    std::vector<float> vec_positiondeltaR_Q2_leadZ{};

    std::vector<float> vec_deltaR_Q1_subleadZ{};
    std::vector<float> vec_positiondeltaR_Q1_subleadZ{};

    std::vector<float> vec_deltaR_Q2_subleadZ{};
    std::vector<float> vec_positiondeltaR_Q2_subleadZ{};

    std::vector<float> vec_deltaR_Q1_H_bb{};
    std::vector<float> vec_positiondeltaR_Q1_H_bb{};

    std::vector<float> vec_deltaR_Q2_H_bb{};
    std::vector<float> vec_positiondeltaR_Q2_H_bb{};

    std::vector<ROOT::Math::PtEtaPhiMVector> vec4d_Zlead {};

    // vectors for the fat jets staff
    std::vector<ROOT::Math::PtEtaPhiMVector> vec4d_fat_jets {};

    std::vector<float> vec_deltaR_fatjet_QQ_leadZ{};
    std::vector<float> vec_positiondeltaR_fatjet_QQ_leadZ{};

    std::vector<float> vec_deltaR_fatjet_QQ_subleadZ{};
    std::vector<float> vec_positiondeltaR_fatjet_QQ_subleadZ{};

    std::vector<float> vec_deltaR_fatjet_bb_H{};
    std::vector<float> vec_positiondeltaR_fatjet_bb_H{};

    // vectors for the fat jets staff_for the score staff FatJet_particleNetMD_Xbb
    std::vector<float> vec_H_score{};

    std::vector<float> vec_deltaR_fatjet_bb_H_dRmethod{};
    std::vector<float> vec_positiondeltaR_fatjet_bb_H_dRmethod{};

    // vector for fail mode 1
    std::vector<float> vec_deltaR_largethan_fatjet_bb_H{};
    std::vector<float> vec_deltaR_failmode2_fatjet_bb_H{};
    std::vector<float> vec_positiondeltaR_failmode2_fatjet_bb_H{};
















    // point to the branches to read data from them afterwards
    Events->SetBranchAddress("GenPart_pt",&GenPart_pt);
    Events->SetBranchAddress("GenPart_phi",&GenPart_phi);
    Events->SetBranchAddress("GenPart_mass",&GenPart_mass);
    Events->SetBranchAddress("GenPart_eta",&GenPart_eta);
    Events->SetBranchAddress("GenPart_pdgId",&GenPart_pdgId);
    Events->SetBranchAddress("GenPart_status",&GenPart_status);
    Events->SetBranchAddress("GenPart_genPartIdxMother",&GenPart_genPartIdxMother);
    Events->SetBranchAddress("nGenPart",&nGenPart);

    Events->SetBranchAddress("Jet_pt",&Jet_pt);
    Events->SetBranchAddress("Jet_eta",&Jet_eta);
    Events->SetBranchAddress("Jet_phi",&Jet_phi);
    Events->SetBranchAddress("Jet_mass",&Jet_mass);
    Events->SetBranchAddress("nJet",&nJet);
    // do the FatJet setting branches
    Events->SetBranchAddress("FatJet_eta",&FatJet_eta);
    Events->SetBranchAddress("FatJet_pt",&FatJet_pt);
    Events->SetBranchAddress("FatJet_phi",&FatJet_phi);
    Events->SetBranchAddress("FatJet_mass",&FatJet_mass);
    Events->SetBranchAddress("FatJet_particleNetMD_Xbb",&FatJet_particleNetMD_Xbb);
    Events->SetBranchAddress("FatJet_particleNetMD_Xqq",&FatJet_particleNetMD_Xqq);
    Events->SetBranchAddress("FatJet_particleNetMD_QCD",&FatJet_particleNetMD_QCD);
    Events->SetBranchAddress("nFatJet",&nFatJet);






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

    TH1D* hist_jet_leadVBFquark_ptFraction= new TH1D ("hist_jet_leadVBFquark_ptFraction","(Reco_pt - Gen_pt) / Gen_pt _leadQuark",80,-1,1);
    TH1D* hist_jet_leadVBFquark_etaFraction= new TH1D ("hist_jet_leadVBFquark_etaFraction","(Reco_eta - Gen_eta) / Gen_eta _leadQuark",80,-.5,0.5);
    TH1D* hist_jet_leadVBFquark_phiFraction= new TH1D ("hist_jet_leadVBFquark_phiFraction","(Reco_phi - Gen_phi) / Gen_phi _leadQuark",80,-.5,0.5);
    TH1D* hist_jet_leadVBFquark_pt= new TH1D ("hist_jet_leadVBFquark_pt","Reco_pt_leadQuark",80,0,200);
    TH1D* hist_jet_leadVBFquark_eta= new TH1D ("hist_jet_leadVBFquark_eta","Reco_eta_leadQuark",80,-5,5);
    TH1D* hist_jet_leadVBFquark_phi= new TH1D ("hist_jet_leadVBFquark_phi","Reco_phi_leadQuark",40,-10,10);
    TH1D* hist_jet_leadVBFquark_Gen_pt= new TH1D ("hist_jet_leadVBFquark_Gen_pt","Gen_pt_leadQuark",80,0,200);
    TH1D* hist_jet_leadVBFquark_Gen_eta= new TH1D ("hist_jet_leadVBFquark_Gen_eta","Gen_eta_leadQuark",80,-5,5);
    TH1D* hist_jet_leadVBFquark_Gen_phi= new TH1D ("hist_jet_leadVBFquark_Gen_phi","Gen_phi_leadQuark",40,-10,10);
    TH1D* hist_jet_leadVBFquark_deltaR_Reco_Gen= new TH1D ("hist_jet_leadVBFquark_deltaR_Reco_Gen","deltaR_Reco_Gen_leadQuark",80,0,1);
    TH1D* hist_jet_leadVBFquark_deltaPhi_Reco_Gen= new TH1D ("hist_jet_leadVBFquark_deltaPhi_Reco_Gen","deltaPhi_Reco_Gen_leadQuark",80,0,1);
    TH1D* hist_jet_leadVBFquark_deltaEta_Reco_Gen= new TH1D ("hist_jet_leadVBFquark_deltaEta_Reco_Gen","deltaEta_Reco_Gen_leadQuark",80,0,1);

    TH1D* hist_jet_subleadVBFquark_ptFraction= new TH1D ("hist_jet_subleadVBFquark_ptFraction","(Reco_pt - Gen_pt) / Gen_pt _subleadQuark",80,-1,1);
    TH1D* hist_jet_subleadVBFquark_etaFraction= new TH1D ("hist_jet_subleadVBFquark_etaFraction","(Reco_eta - Gen_eta) / Gen_eta _subleadQuark",80,-.5,0.5);
    TH1D* hist_jet_subleadVBFquark_phiFraction= new TH1D ("hist_jet_subleadVBFquark_phiFraction","(Reco_phi - Gen_phi) / Gen_phi _subleadQuark",80,-.5,0.5);
    TH1D* hist_jet_subleadVBFquark_pt= new TH1D ("hist_jet_subleadVBFquark_pt","Reco_pt_subleadQuark",80,0,200);
    TH1D* hist_jet_subleadVBFquark_eta= new TH1D ("hist_jet_subleadVBFquark_eta","Reco_eta_subleadQuark",80,-5,5);
    TH1D* hist_jet_subleadVBFquark_phi= new TH1D ("hist_jet_subleadVBFquark_phi","Reco_phi_subleadQuark",40,-10,10);
    TH1D* hist_jet_subleadVBFquark_Gen_pt= new TH1D ("hist_jet_subleadVBFquark_Gen_pt","Gen_pt_subleadQuark",80,0,200);
    TH1D* hist_jet_subleadVBFquark_Gen_eta= new TH1D ("hist_jet_subleadVBFquark_Gen_eta","Gen_eta_subleadQuark",80,-5,5);
    TH1D* hist_jet_subleadVBFquark_Gen_phi= new TH1D ("hist_jet_subleadVBFquark_Gen_phi","Gen_phi_subleadQuark",40,-10,10);
    TH1D* hist_jet_subleadVBFquark_deltaR_Reco_Gen= new TH1D ("hist_jet_subleadVBFquark_deltaR_Reco_Gen","deltaR_Reco_Gen_subleadQuark",80,0,1);
    TH1D* hist_jet_subleadVBFquark_deltaPhi_Reco_Gen= new TH1D ("hist_jet_subleadVBFquark_deltaPhi_Reco_Gen","deltaPhi_Reco_Gen_subleadQuark",80,0,1);
    TH1D* hist_jet_subleadVBFquark_deltaEta_Reco_Gen= new TH1D ("hist_jet_subleadVBFquark_deltaEta_Reco_Gen","deltaEta_Reco_Gen_subleadQuark",80,0,1);

    TH1D* hist_jet_Zlead_qq_ptFraction= new TH1D ("hist_jet_Zlead_qq_ptFraction","(Reco_pt - Gen_pt) / Gen_pt _Zlead->qq system",80,-1,1);
    TH1D* hist_jet_Zlead_qq_etaFraction= new TH1D ("hist_jet_Zlead_qq_etaFraction","(Reco_eta - Gen_eta) / Gen_eta _Zlead->qq system",80,-.5,0.5);
    TH1D* hist_jet_Zlead_qq_phiFraction= new TH1D ("hist_jet_Zlead_qq_phiFraction","(Reco_phi - Gen_phi) / Gen_phi _Zlead->qq system",80,-.5,0.5);
    TH1D* hist_jet_Zlead_qq_pt= new TH1D ("hist_jet_Zlead_qq_pt","Reco_pt_Zlead->qq system",80,0,1800);
    TH1D* hist_jet_Zlead_qq_eta= new TH1D ("hist_jet_Zlead_qq_eta","Reco_eta_Zlead->qq system",80,-5,5);
    TH1D* hist_jet_Zlead_qq_phi= new TH1D ("hist_jet_Zlead_qq_phi","Reco_phi_Zlead->qq system",40,-10,10);
    TH1D* hist_jet_Zlead_qq_Gen_pt= new TH1D ("hist_jet_Zlead_qq_Gen_pt","Gen_pt_Zlead->qq system",80,0,200);
    TH1D* hist_jet_Zlead_qq_Gen_eta= new TH1D ("hist_jet_Zlead_qq_Gen_eta","Gen_eta_Zlead->qq system",80,-5,5);
    TH1D* hist_jet_Zlead_qq_Gen_phi= new TH1D ("hist_jet_Zlead_qq_Gen_phi","Gen_phi_Zlead->qq system",40,-10,10);
    TH1D* hist_jet_Zlead_qq_deltaR_Reco_Gen_Q1= new TH1D ("hist_jet_Zlead_qq_deltaR_Reco_Gen_Q1","deltaR_Reco_Gen_Zlead->qq for Q1",80,0,1);
    TH1D* hist_jet_Zlead_qq_deltaPhi_Reco_Gen_Q1= new TH1D ("hist_jet_Zlead_qq_deltaPhi_Reco_Gen_Q1","deltaPhi_Reco_Gen_Zlead->qq for Q1",80,0,1);
    TH1D* hist_jet_Zlead_qq_deltaEta_Reco_Gen_Q1= new TH1D ("hist_jet_Zlead_qq_deltaEta_Reco_Gen_Q1","deltaEta_Reco_Gen_Zlead->qq for Q1",80,0,1);

    TH1D* hist_jet_Zsublead_qq_ptFraction= new TH1D ("hist_jet_Zsublead_qq_ptFraction","(Reco_pt - Gen_pt) / Gen_pt _Zsublead->qq system",80,-1,1);
    TH1D* hist_jet_Zsublead_qq_etaFraction= new TH1D ("hist_jet_Zsublead_qq_etaFraction","(Reco_eta - Gen_eta) / Gen_eta _Zsublead->qq system",80,-.5,0.5);
    TH1D* hist_jet_Zsublead_qq_phiFraction= new TH1D ("hist_jet_Zsublead_qq_phiFraction","(Reco_phi - Gen_phi) / Gen_phi _Zsublead->qq system",80,-.5,0.5);
    TH1D* hist_jet_Zsublead_qq_pt= new TH1D ("hist_jet_Zsublead_qq_pt","Reco_pt_Zsublead->qq system",80,0,1800);
    TH1D* hist_jet_Zsublead_qq_eta= new TH1D ("hist_jet_Zsublead_qq_eta","Reco_eta_Zsublead->qq system",80,-5,5);
    TH1D* hist_jet_Zsublead_qq_phi= new TH1D ("hist_jet_Zsublead_qq_phi","Reco_phi_Zsublead->qq system",40,-10,10);
    TH1D* hist_jet_Zsublead_qq_Gen_pt= new TH1D ("hist_jet_Zsublead_qq_Gen_pt","Gen_pt_Zsublead->qq system",80,0,200);
    TH1D* hist_jet_Zsublead_qq_Gen_eta= new TH1D ("hist_jet_Zsublead_qq_Gen_eta","Gen_eta_Zsublead->qq system",80,-5,5);
    TH1D* hist_jet_Zsublead_qq_Gen_phi= new TH1D ("hist_jet_Zsublead_qq_Gen_phi","Gen_phi_Zsublead->qq system",40,-10,10);
    TH1D* hist_jet_Zsublead_qq_deltaR_Reco_Gen_Q1= new TH1D ("hist_jet_Zsublead_qq_deltaR_Reco_Gen_Q1","deltaR_Reco_Gen_Zsublead->qq for Q1",80,0,1);
    TH1D* hist_jet_Zsublead_qq_deltaPhi_Reco_Gen_Q1= new TH1D ("hist_jet_Zsublead_qq_deltaPhi_Reco_Gen_Q1","deltaPhi_Reco_Gen_Zsublead->qq for Q1",80,0,1);
    TH1D* hist_jet_Zsublead_qq_deltaEta_Reco_Gen_Q1= new TH1D ("hist_jet_Zsublead_qq_deltaEta_Reco_Gen_Q1","deltaEta_Reco_Gen_Zsublead->qq for Q1",80,0,1);

    TH1D* hist_jet_H_bb_ptFraction= new TH1D ("hist_jet_H_bb_ptFraction","(Reco_pt - Gen_pt) / Gen_pt _H->bb system",80,-1,1);
    TH1D* hist_jet_H_bb_etaFraction= new TH1D ("hist_jet_H_bb_etaFraction","(Reco_eta - Gen_eta) / Gen_eta _H->bb system",80,-.5,0.5);
    TH1D* hist_jet_H_bb_phiFraction= new TH1D ("hist_jet_H_bb_phiFraction","(Reco_phi - Gen_phi) / Gen_phi _H->bb system",80,-.5,0.5);
    TH1D* hist_jet_H_bb_pt= new TH1D ("hist_jet_H_bb_pt","Reco_pt_H->bb system",80,0,1800);
    TH1D* hist_jet_H_bb_eta= new TH1D ("hist_jet_H_bb_eta","Reco_eta_H->bb system",80,-5,5);
    TH1D* hist_jet_H_bb_phi= new TH1D ("hist_jet_H_bb_phi","Reco_phi_H->bb system",40,-10,10);
    TH1D* hist_jet_H_bb_Gen_pt= new TH1D ("hist_jet_H_bb_Gen_pt","Gen_pt_H->bb system",80,0,200);
    TH1D* hist_jet_H_bb_Gen_eta= new TH1D ("hist_jet_H_bb_Gen_eta","Gen_eta_H->bb system",80,-5,5);
    TH1D* hist_jet_H_bb_Gen_phi= new TH1D ("hist_jet_H_bb_Gen_phi","Gen_phi_H->bb system",40,-10,10);
    TH1D* hist_jet_H_bb_deltaR_Reco_Gen_Q1= new TH1D ("hist_jet_H_bb_deltaR_Reco_Gen_Q1","deltaR_Reco_Gen_H->bb for Q1",80,0,1);
    TH1D* hist_jet_H_bb_deltaPhi_Reco_Gen_Q1= new TH1D ("hist_jet_H_bb_deltaPhi_Reco_Gen_Q1","deltaPhi_Reco_Gen_H->bb for Q1",80,0,1);
    TH1D* hist_jet_H_bb_deltaEta_Reco_Gen_Q1= new TH1D ("hist_jet_H_bb_deltaEta_Reco_Gen_Q1","deltaEta_Reco_Gen_H->bb for Q1",80,0,1);

    TH2D* hist_2d_pt_zlead_DeltaR_qq= new TH2D("hist_2d_pt_zlead_DeltaR_qq","pt_Zlead vs delta R _qq ",80,0,1800,80,0,1);

    // The fat jets histograms


    TH1D* hist_fatjet_H_bb_ptFraction= new TH1D ("hist_fatjet_H_bb_ptFraction","(Reco_pt - Gen_pt) / Gen_pt _H->bb system_fat",80,-1,1);
    TH1D* hist_fatjet_H_bb_etaFraction= new TH1D ("hist_fatjet_H_bb_etaFraction","(Reco_eta - Gen_eta) / Gen_eta _H->bb system_fat",80,-.5,0.5);
    TH1D* hist_fatjet_H_bb_phiFraction= new TH1D ("hist_fatjet_H_bb_phiFraction","(Reco_phi - Gen_phi) / Gen_phi _H->bb system_fat",80,-.5,0.5);
    TH1D* hist_fatjet_H_bb_pt= new TH1D ("hist_fatjet_H_bb_pt","Reco_pt_H->bb system_fat",80,0,1800);
    TH1D* hist_fatjet_H_bb_eta= new TH1D ("hist_fatjet_H_bb_eta","Reco_eta_H->bb system_fat",80,-5,5);
    TH1D* hist_fatjet_H_bb_phi= new TH1D ("hist_fatjet_H_bb_phi","Reco_phi_H->bb system_fat",40,-10,10);
    TH1D* hist_fatjet_H_bb_Gen_pt= new TH1D ("hist_fatjet_H_bb_Gen_pt","Gen_pt_H->bb system_fat",80,0,1800);
    TH1D* hist_fatjet_H_bb_Gen_eta= new TH1D ("hist_fatjet_H_bb_Gen_eta","Gen_eta_H->bb system_fat",80,-5,5);
    TH1D* hist_fatjet_H_bb_Gen_phi= new TH1D ("hist_fatjet_H_bb_Gen_phi","Gen_phi_H->bb system_fat",40,-10,10);
    TH1D* hist_fatjet_H_bb_deltaR_Reco_Gen_Q1= new TH1D ("hist_fatjet_H_bb_deltaR_Reco_Gen_Q1","deltaR_Reco_Gen_H->bb for Q1_fat",80,0,1);
    TH1D* hist_fatjet_H_bb_deltaPhi_Reco_Gen_Q1= new TH1D ("hist_fatjet_H_bb_deltaPhi_Reco_Gen_Q1","deltaPhi_Reco_Gen_H->bb for Q1_fat",80,0,1);
    TH1D* hist_fatjet_H_bb_deltaEta_Reco_Gen_Q1= new TH1D ("hist_fatjet_H_bb_deltaEta_Reco_Gen_Q1","deltaEta_Reco_Gen_H->bb for Q1_fat",80,0,1);

    // the fat jet hostphrams for the case of score FatJet_particleNetMD_Xbb
    TH1D* hist_fatjet_H_bb_ptFraction_score_method= new TH1D ("hist_fatjet_H_bb_ptFraction_score_method","(Reco_pt - G_pt)/Gen_pt _H->bb system_fat_score_method",80,-1,1);
    TH1D* hist_fatjet_H_bb_ptFraction_dRmin_method= new TH1D ("hist_fatjet_H_bb_ptFraction_dRmin_method","(Reco_pt - Ge_pt)/Gen_pt _H->bb system_fat_dRmin_method",80,-1,1);

    //fail mode 2
    TH1D* hist_failmode2_Xbbscore_diff_maxXbbscore=new TH1D ("hist_failmode2_Xbbscore_diff_maxXbbscore","failmode2_Xbbscore_diff_maxXbbscore",80,-2,2);









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


int compete=0;
int compete22=0;
int indexzzz=0;
int count=0;
int count_leftover=0;
int wrong1=0;
int no_events_fatjet_three=0;
int no_events_dR_largethan=0;
int failmode1=0;
int failmode2=0;
int failmode2cometescores=0;
int zleadcomete=0;
int zsubleadcomete=0;
int zleadcamefrombb=0;
int zsubleadcamefrombb=0;
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
                  //cout << "z: " << vecZ.size()<<endl;

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
            //vec4d_Zlead.push_back({vecZ[0].pt(),vecZ[0].eta(),vecZ[0].phi(),vecZ[0].mass()}); // i did this vector for the 2d hist of zlead pt vs delta r for qq from that Z
            //cout << "vec4d_Zlead pt 1: " << vec4d_Zlead[0].pt()<<"size 1: " <<vec4d_Zlead.size()<<endl;
            }
            else {
            hist_pt_leadZ->Fill(pt_Z.at(1)) ;
            hist_pt_subleadZ->Fill(pt_Z.at(0)) ;
            //vec4d_Zlead.push_back({vecZ[1].pt(),vecZ[1].eta(),vecZ[1].phi(),vecZ[1].mass()}); // i did this vector for the 2d hist of zlead pt vs delta r for qq from that Zcout << "vec4d_Zlead pt: " << vec4d_Zlead[0].pt();
            //cout << "vec4d_Zlead pt 2: " << vec4d_Zlead[0].pt()<<"size 2: " <<vec4d_Zlead.size()<<endl;

            }

            hist_m_ZZH->Fill((vecZ.at(0)+vecZ.at(1)+vecH.at(0)).mass());



            if (vecQuark[0].pt()> vecQuark[1].pt()){
            hist_pt_leadQuark->Fill(vecQuark[0].pt()) ;
            hist_pt_subleadQuark->Fill(vecQuark[1].pt()) ;
            vec4d_leadingQuark_VBFquark.push_back({vecQuark[0].pt(),vecQuark[0].eta(),vecQuark[0].phi(),vecQuark[0].mass()});
            vec4d_subleadingQuark_VBFquark.push_back({vecQuark[1].pt(),vecQuark[1].eta(),vecQuark[1].phi(),vecQuark[1].mass()});

            hist_eta_leadQuark->Fill(vecQuark[0].eta()) ;
            hist_eta_subleadQuark->Fill(vecQuark[1].eta()) ;
            }
            else {
            hist_pt_leadQuark->Fill(vecQuark[1].pt()) ;
            hist_pt_subleadQuark->Fill(vecQuark[0].pt()) ;
            vec4d_leadingQuark_VBFquark.push_back({vecQuark[1].pt(),vecQuark[1].eta(),vecQuark[1].phi(),vecQuark[1].mass()});
            vec4d_subleadingQuark_VBFquark.push_back({vecQuark[0].pt(),vecQuark[0].eta(),vecQuark[0].phi(),vecQuark[0].mass()});

            hist_eta_leadQuark->Fill(vecQuark[1].eta()) ;
            hist_eta_subleadQuark->Fill(vecQuark[0].eta()) ;
            }
            hist_m_quarks->Fill((vecQuark[0]+vecQuark[1]).mass());
            hist_m_widerange_quarks->Fill((vecQuark[0]+vecQuark[1]).mass());
            hist_abs_EtaDiff->Fill(TMath::Abs((vecQuark[1].eta())-(vecQuark[0].eta())));
            //cout << "event: "<< i <<" pt: " << vec4d_leadingQuark_VBFquark[0].pt()<< " eta: " << vec4d_leadingQuark_VBFquark[0].eta()<< endl;


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
                      //  place_of_Zsublead_qurks.push_back(q);  // this was a mistake i did this one line should be put in the next if comdition
                      //cuz this was of doing it i just ignored the decay of the z->qq, i didn't do that selection
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

                 if (pt_Z.at(0)> pt_Z.at(1)){

                 vec4d_Zlead.push_back({vecZ[0].pt(),vecZ[0].eta(),vecZ[0].phi(),vecZ[0].mass()}); // i did this vector for the 2d hist of zlead pt vs delta r for qq from that Z
                 //cout << "vec4d_Zlead pt 11: " << vec4d_Zlead[0].pt()<<"size 1: " <<vec4d_Zlead.size()<<endl;
                 }
                 else {

                 vec4d_Zlead.push_back({vecZ[1].pt(),vecZ[1].eta(),vecZ[1].phi(),vecZ[1].mass()}); // i did this vector for the 2d hist of zlead pt vs delta r for qq from that Zcout << "vec4d_Zlead pt: " << vec4d_Zlead[0].pt();
                 //cout << "vec4d_Zlead pt 22: " << vec4d_Zlead[0].pt()<<"size 2: " <<vec4d_Zlead.size()<<endl;

                 }

                 hist_2d_pt_zlead_DeltaR_qq->Fill(vec4d_Zlead[0].pt(),sqrt(pow(TMath::Abs(vec4d_qq_Zlead[0].eta()-vec4d_qq_Zlead[1].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_qq_Zlead[0],vec4d_qq_Zlead[1])),2)));



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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                 // do the jet reconstruction staff

                 for (int hh = 0; hh < nJet[0]; hh++) {
                      vec4d_jets.push_back({Jet_pt[hh],Jet_eta[hh],Jet_phi[hh],Jet_mass[hh]});
                 }


                 for (int m = 0; m < nJet[0]; m++)
                 {
                     //vec4d_jets.push_back({Jet_pt[m],Jet_eta[m],Jet_phi[m],Jet_mass[m]});

                     double dr = sqrt(pow(TMath::Abs(vec4d_jets[m].eta()-vec4d_leadingQuark_VBFquark[0].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[m],vec4d_leadingQuark_VBFquark[0])),2));
                     if (dr <0.4)
                     {
                         vec_deltaR_leadingVBFquark.push_back(dr);
                         vec_positiondeltaR_leadingVBFquark.push_back(m);
                     }
                 }
                 // do the same staff to do reconstruction for the subleading quark this time
                 for (int mm = 0; mm < nJet[0]; mm++)
                 {
                     //vec4d_jets.push_back({Jet_pt[m],Jet_eta[m],Jet_phi[m],Jet_mass[m]});

                     double drr = sqrt(pow(TMath::Abs(vec4d_jets[mm].eta()-vec4d_subleadingQuark_VBFquark[0].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[mm],vec4d_subleadingQuark_VBFquark[0])),2));
                     if (drr <0.4)
                     {
                         vec_deltaR_subleadingVBFquark.push_back(drr);
                         vec_positiondeltaR_subleadingVBFquark.push_back(mm);
                     }
                 }
                 // do the same staff to do reconstruction for the two quarks of the lead Z this time
                 for (int mmm = 0; mmm < nJet[0]; mmm++)
                 {

                     double drq1 = sqrt(pow(TMath::Abs(vec4d_jets[mmm].eta()-vec4d_qq_Zlead[0].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[mmm],vec4d_qq_Zlead[0])),2));
                     if (drq1 <0.4)
                     {
                         vec_deltaR_Q1_leadZ.push_back(drq1);
                         vec_positiondeltaR_Q1_leadZ.push_back(mmm);
                     }
                 }

                 for (int mmmm = 0; mmmm < nJet[0]; mmmm++)
                 {

                     double drq2 = sqrt(pow(TMath::Abs(vec4d_jets[mmmm].eta()-vec4d_qq_Zlead[1].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[mmmm],vec4d_qq_Zlead[1])),2));
                     if (drq2 <0.4)
                     {
                         vec_deltaR_Q2_leadZ.push_back(drq2);
                         vec_positiondeltaR_Q2_leadZ.push_back(mmmm);
                     }
                 }

                 // do the same staff to do reconstruction for the two quarks of the sublead Z this time

                 for (int m4 = 0; m4 < nJet[0]; m4++)
                 {

                     double drrq1 = sqrt(pow(TMath::Abs(vec4d_jets[m4].eta()-vec4d_qq_Zsublead[0].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[m4],vec4d_qq_Zsublead[0])),2));
                     if (drrq1 <0.4)
                     {
                         vec_deltaR_Q1_subleadZ.push_back(drrq1);
                         vec_positiondeltaR_Q1_subleadZ.push_back(m4);
                     }
                 }

                 for (int m5 = 0; m5 < nJet[0]; m5++)
                 {

                     double drrq2 = sqrt(pow(TMath::Abs(vec4d_jets[m5].eta()-vec4d_qq_Zsublead[1].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[m5],vec4d_qq_Zsublead[1])),2));
                     if (drrq2 <0.4)
                     {
                         vec_deltaR_Q2_subleadZ.push_back(drrq2);
                         vec_positiondeltaR_Q2_subleadZ.push_back(m5);
                     }
                 }

                 // do the same for the higss to bb reconstruction staff h->bb
                 for (int m6 = 0; m6 < nJet[0]; m6++)
                 {

                     double mrq1 = sqrt(pow(TMath::Abs(vec4d_jets[m6].eta()-vec4d_bb_H[0].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[m6],vec4d_bb_H[0])),2));
                     if (mrq1 <0.4)
                     {
                         vec_deltaR_Q1_H_bb.push_back(mrq1);
                         vec_positiondeltaR_Q1_H_bb.push_back(m6);
                     }
                 }
                 for (int m7 = 0; m7 < nJet[0]; m7++)
                 {

                     double mrq2 = sqrt(pow(TMath::Abs(vec4d_jets[m7].eta()-vec4d_bb_H[1].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[m7],vec4d_bb_H[1])),2));
                     if (mrq2 <0.4)
                     {
                         vec_deltaR_Q2_H_bb.push_back(mrq2);
                         vec_positiondeltaR_Q2_H_bb.push_back(m7);
                     }
                 }

                 if (vec_deltaR_leadingVBFquark.size()>0 && vec_deltaR_subleadingVBFquark.size()>0 && vec_deltaR_Q1_leadZ.size()>0 && vec_deltaR_Q2_leadZ.size()>0
                  && vec_deltaR_Q1_subleadZ.size()>0 &&vec_deltaR_Q2_subleadZ.size()>0 &&vec_deltaR_Q1_H_bb.size()>0 &&vec_deltaR_Q2_H_bb.size()>0)
                 {
                     int index_jet_leadingVBFquark= vec_positiondeltaR_leadingVBFquark[min_element(vec_deltaR_leadingVBFquark.begin(),vec_deltaR_leadingVBFquark.end())-vec_deltaR_leadingVBFquark.begin()];
                     // min_element(v1.begin(),v1.end())-v1.begin()   ->this gives the position of the min value in a vector v1

                     int index_jet_subleadingVBFquark= vec_positiondeltaR_subleadingVBFquark[min_element(vec_deltaR_subleadingVBFquark.begin(),vec_deltaR_subleadingVBFquark.end())-vec_deltaR_subleadingVBFquark.begin()];
                     // min_element(v1.begin(),v1.end())-v1.begin()   ->this gives the position of the min value in a vector v1

                     int index_jet_Q1_leadZ= vec_positiondeltaR_Q1_leadZ[min_element(vec_deltaR_Q1_leadZ.begin(),vec_deltaR_Q1_leadZ.end())-vec_deltaR_Q1_leadZ.begin()];
                     int index_jet_Q2_leadZ= vec_positiondeltaR_Q2_leadZ[min_element(vec_deltaR_Q2_leadZ.begin(),vec_deltaR_Q2_leadZ.end())-vec_deltaR_Q2_leadZ.begin()];

                     int index_jet_Q1_subleadZ= vec_positiondeltaR_Q1_subleadZ[min_element(vec_deltaR_Q1_subleadZ.begin(),vec_deltaR_Q1_subleadZ.end())-vec_deltaR_Q1_subleadZ.begin()];
                     int index_jet_Q2_subleadZ= vec_positiondeltaR_Q2_subleadZ[min_element(vec_deltaR_Q2_subleadZ.begin(),vec_deltaR_Q2_subleadZ.end())-vec_deltaR_Q2_subleadZ.begin()];

                     int index_jet_Q1_H_bb= vec_positiondeltaR_Q1_H_bb[min_element(vec_deltaR_Q1_H_bb.begin(),vec_deltaR_Q1_H_bb.end())-vec_deltaR_Q1_H_bb.begin()];
                     int index_jet_Q2_H_bb= vec_positiondeltaR_Q2_H_bb[min_element(vec_deltaR_Q2_H_bb.begin(),vec_deltaR_Q2_H_bb.end())-vec_deltaR_Q2_H_bb.begin()];

                     indexzzz++;

                     if (index_jet_subleadingVBFquark!=index_jet_leadingVBFquark &&index_jet_subleadingVBFquark!=index_jet_Q1_leadZ &&index_jet_subleadingVBFquark!=index_jet_Q2_leadZ
                       &&index_jet_subleadingVBFquark!=index_jet_Q1_subleadZ &&index_jet_subleadingVBFquark!=index_jet_Q2_subleadZ
                       &&index_jet_subleadingVBFquark!= index_jet_Q1_H_bb &&index_jet_subleadingVBFquark!= index_jet_Q2_H_bb
                     && index_jet_leadingVBFquark!=index_jet_Q1_leadZ && index_jet_leadingVBFquark!=index_jet_Q2_leadZ
                     && index_jet_leadingVBFquark!=index_jet_Q1_subleadZ && index_jet_leadingVBFquark!=index_jet_Q2_subleadZ
                     && index_jet_leadingVBFquark!= index_jet_Q1_H_bb && index_jet_leadingVBFquark!= index_jet_Q2_H_bb
                     && index_jet_Q1_leadZ!=index_jet_Q2_leadZ && index_jet_Q1_leadZ!=index_jet_Q1_subleadZ && index_jet_Q1_leadZ!=index_jet_Q2_subleadZ
                     && index_jet_Q1_leadZ!=index_jet_Q1_H_bb && index_jet_Q1_leadZ!=index_jet_Q2_H_bb
                     &&index_jet_Q2_leadZ!=index_jet_Q1_subleadZ &&index_jet_Q2_leadZ!=index_jet_Q2_subleadZ
                     && index_jet_Q2_leadZ!=index_jet_Q1_H_bb && index_jet_Q2_leadZ!=index_jet_Q2_H_bb
                     &&index_jet_Q1_subleadZ!= index_jet_Q2_subleadZ   && index_jet_Q1_subleadZ!=index_jet_Q1_H_bb && index_jet_Q1_subleadZ!=index_jet_Q2_H_bb
                     && index_jet_Q2_subleadZ!=index_jet_Q1_H_bb && index_jet_Q2_subleadZ!=index_jet_Q2_H_bb
                     &&index_jet_Q1_H_bb!=index_jet_Q2_H_bb
                          )
                     {
                         hist_jet_leadVBFquark_ptFraction->Fill((vec4d_jets[index_jet_leadingVBFquark].pt()-vec4d_leadingQuark_VBFquark[0].pt())/vec4d_leadingQuark_VBFquark[0].pt());
                         hist_jet_leadVBFquark_etaFraction->Fill((vec4d_jets[index_jet_leadingVBFquark].eta()-vec4d_leadingQuark_VBFquark[0].eta())/vec4d_leadingQuark_VBFquark[0].eta());
                         hist_jet_leadVBFquark_phiFraction->Fill((vec4d_jets[index_jet_leadingVBFquark].phi()-vec4d_leadingQuark_VBFquark[0].phi())/vec4d_leadingQuark_VBFquark[0].phi());
                         hist_jet_leadVBFquark_pt->Fill(vec4d_jets[index_jet_leadingVBFquark].pt());
                         hist_jet_leadVBFquark_eta->Fill(vec4d_jets[index_jet_leadingVBFquark].eta());
                         hist_jet_leadVBFquark_phi->Fill(vec4d_jets[index_jet_leadingVBFquark].phi());
                         hist_jet_leadVBFquark_Gen_pt->Fill(vec4d_leadingQuark_VBFquark[0].pt());
                         hist_jet_leadVBFquark_Gen_phi->Fill(vec4d_leadingQuark_VBFquark[0].phi());
                         hist_jet_leadVBFquark_Gen_eta->Fill(vec4d_leadingQuark_VBFquark[0].eta());
                         hist_jet_leadVBFquark_deltaR_Reco_Gen->Fill(vec_deltaR_leadingVBFquark[min_element(vec_deltaR_leadingVBFquark.begin(),vec_deltaR_leadingVBFquark.end())-vec_deltaR_leadingVBFquark.begin()]);
                         hist_jet_leadVBFquark_deltaPhi_Reco_Gen->Fill(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[index_jet_leadingVBFquark],vec4d_leadingQuark_VBFquark[0])));
                         hist_jet_leadVBFquark_deltaEta_Reco_Gen->Fill(TMath::Abs(vec4d_jets[index_jet_leadingVBFquark].eta()-vec4d_leadingQuark_VBFquark[0].eta()));


                         hist_jet_subleadVBFquark_ptFraction->Fill((vec4d_jets[index_jet_subleadingVBFquark].pt()-vec4d_subleadingQuark_VBFquark[0].pt())/vec4d_subleadingQuark_VBFquark[0].pt());
                         hist_jet_subleadVBFquark_etaFraction->Fill((vec4d_jets[index_jet_subleadingVBFquark].eta()-vec4d_subleadingQuark_VBFquark[0].eta())/vec4d_subleadingQuark_VBFquark[0].eta());
                         hist_jet_subleadVBFquark_phiFraction->Fill((vec4d_jets[index_jet_subleadingVBFquark].phi()-vec4d_subleadingQuark_VBFquark[0].phi())/vec4d_subleadingQuark_VBFquark[0].phi());
                         hist_jet_subleadVBFquark_pt->Fill(vec4d_jets[index_jet_subleadingVBFquark].pt());
                         hist_jet_subleadVBFquark_eta->Fill(vec4d_jets[index_jet_subleadingVBFquark].eta());
                         hist_jet_subleadVBFquark_phi->Fill(vec4d_jets[index_jet_subleadingVBFquark].phi());
                         hist_jet_subleadVBFquark_Gen_pt->Fill(vec4d_subleadingQuark_VBFquark[0].pt());
                         hist_jet_subleadVBFquark_Gen_phi->Fill(vec4d_subleadingQuark_VBFquark[0].phi());
                         hist_jet_subleadVBFquark_Gen_eta->Fill(vec4d_subleadingQuark_VBFquark[0].eta());
                         hist_jet_subleadVBFquark_deltaR_Reco_Gen->Fill(vec_deltaR_subleadingVBFquark[min_element(vec_deltaR_subleadingVBFquark.begin(),vec_deltaR_subleadingVBFquark.end())-vec_deltaR_subleadingVBFquark.begin()]);
                         hist_jet_subleadVBFquark_deltaPhi_Reco_Gen->Fill(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[index_jet_subleadingVBFquark],vec4d_subleadingQuark_VBFquark[0])));
                         hist_jet_subleadVBFquark_deltaEta_Reco_Gen->Fill(TMath::Abs(vec4d_jets[index_jet_subleadingVBFquark].eta()-vec4d_subleadingQuark_VBFquark[0].eta()));

                         hist_jet_Zlead_qq_ptFraction->Fill(((vec4d_jets[index_jet_Q1_leadZ]+vec4d_jets[index_jet_Q2_leadZ]).pt()-(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).pt())/(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).pt());
                         hist_jet_Zlead_qq_etaFraction->Fill(((vec4d_jets[index_jet_Q1_leadZ]+vec4d_jets[index_jet_Q2_leadZ]).eta()-(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).eta())/(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).eta());
                         hist_jet_Zlead_qq_phiFraction->Fill(((vec4d_jets[index_jet_Q1_leadZ]+vec4d_jets[index_jet_Q2_leadZ]).phi()-(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).phi())/(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).phi());
                         hist_jet_Zlead_qq_pt->Fill((vec4d_jets[index_jet_Q1_leadZ]+vec4d_jets[index_jet_Q2_leadZ]).pt());
                         hist_jet_Zlead_qq_eta->Fill((vec4d_jets[index_jet_Q1_leadZ]+vec4d_jets[index_jet_Q2_leadZ]).eta());
                         hist_jet_Zlead_qq_phi->Fill((vec4d_jets[index_jet_Q1_leadZ]+vec4d_jets[index_jet_Q2_leadZ]).phi());
                         hist_jet_Zlead_qq_Gen_pt->Fill((vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).pt());
                         hist_jet_Zlead_qq_Gen_phi->Fill((vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).phi());
                         hist_jet_Zlead_qq_Gen_eta->Fill((vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).eta());
                         hist_jet_Zlead_qq_deltaR_Reco_Gen_Q1->Fill(vec_deltaR_Q1_leadZ[min_element(vec_deltaR_Q1_leadZ.begin(),vec_deltaR_Q1_leadZ.end())-vec_deltaR_Q1_leadZ.begin()]);
                         hist_jet_Zlead_qq_deltaPhi_Reco_Gen_Q1->Fill(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[index_jet_Q1_leadZ],vec4d_qq_Zlead[0])));
                         hist_jet_Zlead_qq_deltaEta_Reco_Gen_Q1->Fill(TMath::Abs(vec4d_jets[index_jet_Q1_leadZ].eta()-vec4d_qq_Zlead[0].eta()));

                         hist_jet_Zsublead_qq_ptFraction->Fill(((vec4d_jets[index_jet_Q1_subleadZ]+vec4d_jets[index_jet_Q2_subleadZ]).pt()-(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).pt())/(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).pt());
                         hist_jet_Zsublead_qq_etaFraction->Fill(((vec4d_jets[index_jet_Q1_subleadZ]+vec4d_jets[index_jet_Q2_subleadZ]).eta()-(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).eta())/(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).eta());
                         hist_jet_Zsublead_qq_phiFraction->Fill(((vec4d_jets[index_jet_Q1_subleadZ]+vec4d_jets[index_jet_Q2_subleadZ]).phi()-(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).phi())/(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).phi());
                         hist_jet_Zsublead_qq_pt->Fill((vec4d_jets[index_jet_Q1_subleadZ]+vec4d_jets[index_jet_Q2_subleadZ]).pt());
                         hist_jet_Zsublead_qq_eta->Fill((vec4d_jets[index_jet_Q1_subleadZ]+vec4d_jets[index_jet_Q2_subleadZ]).eta());
                         hist_jet_Zsublead_qq_phi->Fill((vec4d_jets[index_jet_Q1_subleadZ]+vec4d_jets[index_jet_Q2_subleadZ]).phi());
                         hist_jet_Zsublead_qq_Gen_pt->Fill((vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).pt());
                         hist_jet_Zsublead_qq_Gen_phi->Fill((vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).phi());
                         hist_jet_Zsublead_qq_Gen_eta->Fill((vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).eta());
                         hist_jet_Zsublead_qq_deltaR_Reco_Gen_Q1->Fill(vec_deltaR_Q1_subleadZ[min_element(vec_deltaR_Q1_subleadZ.begin(),vec_deltaR_Q1_subleadZ.end())-vec_deltaR_Q1_subleadZ.begin()]);
                         hist_jet_Zsublead_qq_deltaPhi_Reco_Gen_Q1->Fill(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[index_jet_Q1_subleadZ],vec4d_qq_Zsublead[0])));
                         hist_jet_Zsublead_qq_deltaEta_Reco_Gen_Q1->Fill(TMath::Abs(vec4d_jets[index_jet_Q1_subleadZ].eta()-vec4d_qq_Zsublead[0].eta()));

                         hist_jet_H_bb_ptFraction->Fill(((vec4d_jets[index_jet_Q1_H_bb]+vec4d_jets[index_jet_Q2_H_bb]).pt()-(vec4d_bb_H[0]+vec4d_bb_H[1]).pt())/(vec4d_bb_H[0]+vec4d_bb_H[1]).pt());
                         hist_jet_H_bb_etaFraction->Fill(((vec4d_jets[index_jet_Q1_H_bb]+vec4d_jets[index_jet_Q2_H_bb]).eta()-(vec4d_bb_H[0]+vec4d_bb_H[1]).eta())/(vec4d_bb_H[0]+vec4d_bb_H[1]).eta());
                         hist_jet_H_bb_phiFraction->Fill(((vec4d_jets[index_jet_Q1_H_bb]+vec4d_jets[index_jet_Q2_H_bb]).phi()-(vec4d_bb_H[0]+vec4d_bb_H[1]).phi())/(vec4d_bb_H[0]+vec4d_bb_H[1]).phi());
                         hist_jet_H_bb_pt->Fill((vec4d_jets[index_jet_Q1_H_bb]+vec4d_jets[index_jet_Q2_H_bb]).pt());
                         hist_jet_H_bb_eta->Fill((vec4d_jets[index_jet_Q1_H_bb]+vec4d_jets[index_jet_Q2_H_bb]).eta());
                         hist_jet_H_bb_phi->Fill((vec4d_jets[index_jet_Q1_H_bb]+vec4d_jets[index_jet_Q2_H_bb]).phi());
                         hist_jet_H_bb_Gen_pt->Fill((vec4d_bb_H[0]+vec4d_bb_H[1]).pt());
                         hist_jet_H_bb_Gen_phi->Fill((vec4d_bb_H[0]+vec4d_bb_H[1]).phi());
                         hist_jet_H_bb_Gen_eta->Fill((vec4d_bb_H[0]+vec4d_bb_H[1]).eta());
                         hist_jet_H_bb_deltaR_Reco_Gen_Q1->Fill(vec_deltaR_Q1_H_bb[min_element(vec_deltaR_Q1_H_bb.begin(),vec_deltaR_Q1_H_bb.end())-vec_deltaR_Q1_H_bb.begin()]);
                         hist_jet_H_bb_deltaPhi_Reco_Gen_Q1->Fill(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_jets[index_jet_Q1_H_bb],vec4d_bb_H[0])));
                         hist_jet_H_bb_deltaEta_Reco_Gen_Q1->Fill(TMath::Abs(vec4d_jets[index_jet_Q1_H_bb].eta()-vec4d_bb_H[0].eta()));

                     }
                     else
                     {
                         compete++;
                     }


                 }

                 // do the FatJet reconstruction staff
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                 for (int f1 = 0; f1 < nFatJet[0]; f1++) {
                      vec4d_fat_jets.push_back({FatJet_pt[f1],FatJet_eta[f1],FatJet_phi[f1],FatJet_mass[f1]});
                 }
                 // do the delta r matching at 0.8 for the zlead qq and the fat jet
                 for (int f2 = 0; f2 < nFatJet[0]; f2++)
                 {

                     double df1 = sqrt(pow(TMath::Abs(vec4d_fat_jets[f2].eta()-(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[f2],(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]))),2));
                     if (df1 <0.8)
                     {
                         vec_deltaR_fatjet_QQ_leadZ.push_back(df1);
                         vec_positiondeltaR_fatjet_QQ_leadZ.push_back(f2);
                     }
                 }

                 // do the delta r matching at 0.8 for the zsublead qq and the fat jet
                 for (int f3 = 0; f3 < nFatJet[0]; f3++)
                 {

                     double df2 = sqrt(pow(TMath::Abs(vec4d_fat_jets[f3].eta()-(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[f3],(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]))),2));
                     if (df2 <0.8)
                     {
                         vec_deltaR_fatjet_QQ_subleadZ.push_back(df2);
                         vec_positiondeltaR_fatjet_QQ_subleadZ.push_back(f3);
                     }
                 }

                 // do the delta r matching at 0.8 for the H bb and the fat jet
                 for (int f4 = 0; f4 < nFatJet[0]; f4++)
                 {

                     double df3 = sqrt(pow(TMath::Abs(vec4d_fat_jets[f4].eta()-(vec4d_bb_H[0]+vec4d_bb_H[1]).eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[f4],(vec4d_bb_H[0]+vec4d_bb_H[1]))),2));
                     if (df3 <0.8)
                     {
                         vec_deltaR_fatjet_bb_H.push_back(df3);
                         vec_positiondeltaR_fatjet_bb_H.push_back(f4);
                     }
                 }

                 if (vec_deltaR_leadingVBFquark.size()>0 && vec_deltaR_subleadingVBFquark.size()>0 && vec_deltaR_fatjet_QQ_leadZ.size()>0 &&vec_deltaR_fatjet_QQ_subleadZ.size()>0 && vec_deltaR_fatjet_bb_H.size()>0)
                 {
                       int index_jet_leadingVBFquark11= vec_positiondeltaR_leadingVBFquark[min_element(vec_deltaR_leadingVBFquark.begin(),vec_deltaR_leadingVBFquark.end())-vec_deltaR_leadingVBFquark.begin()];
                       // min_element(v1.begin(),v1.end())-v1.begin()   ->this gives the position of the min value in a vector v1

                       int index_jet_subleadingVBFquark11= vec_positiondeltaR_subleadingVBFquark[min_element(vec_deltaR_subleadingVBFquark.begin(),vec_deltaR_subleadingVBFquark.end())-vec_deltaR_subleadingVBFquark.begin()];
                       int index_fatjet_QQ_leadZ= vec_positiondeltaR_fatjet_QQ_leadZ[min_element(vec_deltaR_fatjet_QQ_leadZ.begin(),vec_deltaR_fatjet_QQ_leadZ.end())-vec_deltaR_fatjet_QQ_leadZ.begin()];
                       int index_fatjet_QQ_subleadZ= vec_positiondeltaR_fatjet_QQ_subleadZ[min_element(vec_deltaR_fatjet_QQ_subleadZ.begin(),vec_deltaR_fatjet_QQ_subleadZ.end())-vec_deltaR_fatjet_QQ_subleadZ.begin()];
                       int index_fatjet_bb_H= vec_positiondeltaR_fatjet_bb_H[min_element(vec_deltaR_fatjet_bb_H.begin(),vec_deltaR_fatjet_bb_H.end())-vec_deltaR_fatjet_bb_H.begin()];

                       if (index_jet_subleadingVBFquark11!=index_jet_leadingVBFquark11
                         && index_fatjet_QQ_leadZ!=index_fatjet_QQ_subleadZ &&index_fatjet_QQ_leadZ!=index_fatjet_bb_H &&index_fatjet_QQ_subleadZ!=index_fatjet_bb_H)
                       {
                             hist_fatjet_H_bb_ptFraction->Fill((vec4d_fat_jets[index_fatjet_bb_H].pt()-(vec4d_bb_H[0]+vec4d_bb_H[1]).pt())/(vec4d_bb_H[0]+vec4d_bb_H[1]).pt());
                             hist_fatjet_H_bb_etaFraction->Fill((vec4d_fat_jets[index_fatjet_bb_H].eta()-(vec4d_bb_H[0]+vec4d_bb_H[1]).eta())/(vec4d_bb_H[0]+vec4d_bb_H[1]).eta());
                             hist_fatjet_H_bb_phiFraction->Fill((vec4d_fat_jets[index_fatjet_bb_H].phi()-(vec4d_bb_H[0]+vec4d_bb_H[1]).phi())/(vec4d_bb_H[0]+vec4d_bb_H[1]).phi());
                             hist_fatjet_H_bb_pt->Fill(vec4d_fat_jets[index_fatjet_bb_H].pt());
                             hist_fatjet_H_bb_eta->Fill(vec4d_fat_jets[index_fatjet_bb_H].eta());
                             hist_fatjet_H_bb_phi->Fill(vec4d_fat_jets[index_fatjet_bb_H].phi());
                             hist_fatjet_H_bb_Gen_pt->Fill((vec4d_bb_H[0]+vec4d_bb_H[1]).pt());
                             hist_fatjet_H_bb_Gen_phi->Fill((vec4d_bb_H[0]+vec4d_bb_H[1]).phi());
                             hist_fatjet_H_bb_Gen_eta->Fill((vec4d_bb_H[0]+vec4d_bb_H[1]).eta());
                             hist_fatjet_H_bb_deltaR_Reco_Gen_Q1->Fill(vec_deltaR_fatjet_bb_H[min_element(vec_deltaR_fatjet_bb_H.begin(),vec_deltaR_fatjet_bb_H.end())-vec_deltaR_fatjet_bb_H.begin()]);
                             hist_fatjet_H_bb_deltaPhi_Reco_Gen_Q1->Fill(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[index_fatjet_bb_H],vec4d_bb_H[0]+vec4d_bb_H[1])));
                             hist_fatjet_H_bb_deltaEta_Reco_Gen_Q1->Fill(TMath::Abs(vec4d_fat_jets[index_fatjet_bb_H].eta()-(vec4d_bb_H[0]+vec4d_bb_H[1]).eta()));

                       }
                       else
                       {
                           compete22++;
                       }

                 }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                // do the FatJet reconstruction staff using the FatJet_particleNetMD_Xbb/Xqq/ with highest score.
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (nFatJet[0]==3)
                {
                    no_events_fatjet_three++;
                    for (int ff1 = 0; ff1 < nFatJet[0]; ff1++)
                    {
                        vec_H_score.push_back(FatJet_particleNetMD_Xbb[ff1]/(FatJet_particleNetMD_Xbb[ff1]+FatJet_particleNetMD_QCD[ff1]));

                    }
                    int position_max_H_score=max_element(vec_H_score.begin(),vec_H_score.end())-vec_H_score.begin();
                    int dff1=sqrt(pow(TMath::Abs(vec4d_fat_jets[position_max_H_score].eta()-(vec4d_bb_H[0]+vec4d_bb_H[1]).eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[position_max_H_score],(vec4d_bb_H[0]+vec4d_bb_H[1]))),2));
                    if (dff1<0.8)

                    {
                         hist_fatjet_H_bb_ptFraction_score_method->Fill((vec4d_fat_jets[position_max_H_score].pt()-(vec4d_bb_H[0]+vec4d_bb_H[1]).pt())/(vec4d_bb_H[0]+vec4d_bb_H[1]).pt());
                    }
                    else
                    {
                         wrong1++;
                         // doing Fail mode 1: The Higgs did not create an AK8< we are seeing how many events had all the three fat jets with dr large than 0.8 from the bad events we got
                         // by bad events i mean the events with high Xbb scre but still their dR was higher than 0.8
                         for (int no1 = 0; no1 < nFatJet[0]; no1++)
                         {
                             double dff3 = sqrt(pow(TMath::Abs(vec4d_fat_jets[no1].eta()-(vec4d_bb_H[0]+vec4d_bb_H[1]).eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[no1],(vec4d_bb_H[0]+vec4d_bb_H[1]))),2));
                             if (dff3>0.8)
                             {
                                 vec_deltaR_largethan_fatjet_bb_H.push_back(dff3);
                             }

                         }
                         // test fail mode 2  see if there is any higgs produced without being the highest xbb score
                         for (int no2 = 0; no2 < nFatJet[0]; no2++)
                         {
                             double dff4 = sqrt(pow(TMath::Abs(vec4d_fat_jets[no2].eta()-(vec4d_bb_H[0]+vec4d_bb_H[1]).eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[no2],(vec4d_bb_H[0]+vec4d_bb_H[1]))),2));
                             if (dff4<0.8)
                             {
                                 vec_deltaR_failmode2_fatjet_bb_H.push_back(dff4);
                                 vec_positiondeltaR_failmode2_fatjet_bb_H.push_back(no2);
                             }

                         }

                    }
                    // do the condition to see how many events fr fail mode 1
                    if (vec_deltaR_largethan_fatjet_bb_H.size()==3)
                    {
                        failmode1++;
                    }
                    // continue fail mode 2
                    if (vec_deltaR_failmode2_fatjet_bb_H.size()>0)
                    {
                        failmode2++;
                        int index_fatjet_failmode2_bb_H= vec_positiondeltaR_failmode2_fatjet_bb_H[min_element(vec_deltaR_failmode2_fatjet_bb_H.begin(),vec_deltaR_failmode2_fatjet_bb_H.end())-vec_deltaR_failmode2_fatjet_bb_H.begin()];
                        hist_failmode2_Xbbscore_diff_maxXbbscore->Fill(vec_H_score[index_fatjet_failmode2_bb_H]-vec_H_score[position_max_H_score]);
                        //cout << "score: " << vec_H_score[index_fatjet_failmode2_bb_H]-vec_H_score[position_max_H_score] <<endl;

                        if (vec_H_score[position_max_H_score]-vec_H_score[index_fatjet_failmode2_bb_H]<0.1)
                        {
                            failmode2cometescores++;
                            double dff5 = sqrt(pow(TMath::Abs(vec4d_fat_jets[position_max_H_score].eta()-(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]).eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[position_max_H_score],(vec4d_qq_Zlead[0]+vec4d_qq_Zlead[1]))),2));
                            if (dff5<0.8)
                            {
                                zleadcomete++;
                                if (TMath::Abs(GenPart_pdgId[place_of_Zlead_qurks[0]])==5 && TMath::Abs(GenPart_pdgId[place_of_Zlead_qurks[1]])==5)
                                {
                                      zleadcamefrombb++;
                                }
                                else
                                {
                                    cout << "pdgid for lead z:" << GenPart_pdgId[place_of_Zlead_qurks[0]] << ", "<<GenPart_pdgId[place_of_Zlead_qurks[1]]<< endl;
                                }

                            }
                            double dff6 = sqrt(pow(TMath::Abs(vec4d_fat_jets[position_max_H_score].eta()-(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]).eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[position_max_H_score],(vec4d_qq_Zsublead[0]+vec4d_qq_Zsublead[1]))),2));
                            if (dff6<0.8)
                            {
                                zsubleadcomete++;
                                if (TMath::Abs(GenPart_pdgId[place_of_Zsublead_qurks[0]])==5 && TMath::Abs(GenPart_pdgId[place_of_Zsublead_qurks[1]])==5)
                                {
                                      zsubleadcamefrombb++;
                                }
                            }

                        }

                    }

                    // then do the normal method using minmium delta R only for the higgs to be able to compare it with the score method

                    for (int ff2 = 0; ff2 < nFatJet[0]; ff2++)
                    {

                        double dff2 = sqrt(pow(TMath::Abs(vec4d_fat_jets[ff2].eta()-(vec4d_bb_H[0]+vec4d_bb_H[1]).eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec4d_fat_jets[ff2],(vec4d_bb_H[0]+vec4d_bb_H[1]))),2));
                        if (dff2 <0.8)
                        {
                            vec_deltaR_fatjet_bb_H_dRmethod.push_back(dff2);
                            vec_positiondeltaR_fatjet_bb_H_dRmethod.push_back(ff2);
                        }

                    }
                    if (vec_deltaR_fatjet_bb_H_dRmethod.size()>0)
                    {
                      int index_fatjet_bb_H_dRmethod= vec_positiondeltaR_fatjet_bb_H_dRmethod[min_element(vec_deltaR_fatjet_bb_H_dRmethod.begin(),vec_deltaR_fatjet_bb_H_dRmethod.end())-vec_deltaR_fatjet_bb_H_dRmethod.begin()];
                      hist_fatjet_H_bb_ptFraction_dRmin_method->Fill((vec4d_fat_jets[index_fatjet_bb_H_dRmethod].pt()-(vec4d_bb_H[0]+vec4d_bb_H[1]).pt())/(vec4d_bb_H[0]+vec4d_bb_H[1]).pt());


                    }
                    else
                    {
                        no_events_dR_largethan++;
                    }


                }





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

        vec4d_leadingQuark_VBFquark.clear();
        vec_deltaR_leadingVBFquark.clear();
        vec_positiondeltaR_leadingVBFquark.clear();
        vec4d_jets.clear();
        vec4d_subleadingQuark_VBFquark.clear();
        vec_deltaR_subleadingVBFquark.clear();
        vec_positiondeltaR_subleadingVBFquark.clear();

         vec_deltaR_Q1_leadZ.clear();
         vec_positiondeltaR_Q1_leadZ.clear();
         vec_deltaR_Q2_leadZ.clear();
         vec_positiondeltaR_Q2_leadZ.clear();

         vec_deltaR_Q1_subleadZ.clear();
         vec_positiondeltaR_Q1_subleadZ.clear();
         vec_deltaR_Q2_subleadZ.clear();
         vec_positiondeltaR_Q2_subleadZ.clear();

         vec_deltaR_Q1_H_bb.clear();
         vec_positiondeltaR_Q1_H_bb.clear();
         vec_deltaR_Q2_H_bb.clear();
         vec_positiondeltaR_Q2_H_bb.clear();

         vec4d_Zlead.clear();

         // clear vectors for fat jets

         vec4d_fat_jets.clear();

         vec_deltaR_fatjet_QQ_leadZ.clear();
         vec_positiondeltaR_fatjet_QQ_leadZ.clear();

         vec_deltaR_fatjet_QQ_subleadZ.clear();
         vec_positiondeltaR_fatjet_QQ_subleadZ.clear();

         vec_deltaR_fatjet_bb_H.clear();
         vec_positiondeltaR_fatjet_bb_H.clear();
         // clear vectors for fat jet Xbb scores FatJet_particleNetMD_Xbb
         vec_H_score.clear();

         vec_deltaR_fatjet_bb_H_dRmethod.clear();
         vec_positiondeltaR_fatjet_bb_H_dRmethod.clear();

         // the vector for fail mode 1 and 2
         vec_deltaR_largethan_fatjet_bb_H.clear();
         vec_deltaR_failmode2_fatjet_bb_H.clear();
         vec_positiondeltaR_failmode2_fatjet_bb_H.clear();

         //cout << "event: " << i <<endl;
     }

         cout << "number of left-over events: " << count_leftover << endl;
         cout << "number of events which had compete jets for VBF quarks" << compete++ << endl;
         cout << "number of events which had compete fatjets:" << compete22++ << endl;
         cout << "number of events which had wrong1 score after comparing dR:" << wrong1++ << endl;
         cout << "number of events which had dR large than 0.8:" << no_events_dR_largethan++ << endl;
         cout << "number of events which had three fat jets:" <<  no_events_fatjet_three++ << endl;
         cout << "indexzzz: " << indexzzz++ << endl;
         cout <<"no of events for fail mode one (no higgs): " << failmode1 << endl;
         cout <<"no of events for fail mode two: " << failmode2 << endl;
         cout <<"no of events for fail mode two with competing scores: " << failmode2cometescores << endl;
         cout <<"no of events for fail mode two with competing scores from z lead: " << zleadcomete << endl;
         cout <<"no of events for fail mode two with competing scores from z sublead: " << zsubleadcomete << endl;
         cout <<"no of events for fail mode two with competing scores from z lead came from bb: " << zleadcamefrombb << endl;
         cout <<"no of events for fail mode two with competing scores from z sublead came from bb: " << zsubleadcamefrombb << endl;


         // c1->cd();
         // hist_pt_H->Draw();
         // c1->SaveAs("pT of Higgs.pdf");
         //
         // c2->cd();
         // hist_pt_leadZ->Draw();
         // c2->SaveAs("pT of leading Z.pdf");
         //
         // c3->cd();
         // hist_pt_subleadZ->Draw();
         // c3->SaveAs("pT of subleading Z.pdf");
         //
         // c4->cd();
         // hist_pt_leadQuark->Draw();
         // c4->SaveAs("pT of leading quark.pdf");
         //
         // c5->cd();
         // hist_pt_subleadQuark->Draw();
         // c5->SaveAs("pT of subleading quark.pdf");
         //
         // c6->cd();
         // hist_m_ZZH->Draw();
         // c6->SaveAs("invariant mass of the ZZH system.pdf");
         //
         // c7->cd();
         // hist_eta_leadQuark->Draw();
         // c7->SaveAs("eta of leading quark.pdf");
         //
         // c8->cd();
         // hist_eta_subleadQuark->Draw();
         // c8->SaveAs("eta of subleading quark.pdf");
         //
         // c9->cd();
         // hist_m_quarks->Draw();
         // c9->SaveAs("Invariant mass of the two outgoing quarks system.pdf");
         //
         // c10->cd();
         // hist_abs_EtaDiff->Draw();
         // c10->SaveAs("abs eta difference between quarks.pdf");
         //
         // c11->cd();
         // hist_m_widerange_quarks->Draw();
         // c11->SaveAs("Invariant mass of the two outgoing quarks system with wider range.pdf");
         //
         // // c12->cd();
         // // hist_H_pdgid_children->Draw();
         // // hist_H_pdgid_children->Print("all");
         // // c12->SaveAs("pdgId of Higgs children.pdf");
         //
         // c13->cd();
         // hist_H_pdgid_children_bb->Draw();
         // //hist_H_pdgid_children_bb->Print("all");
         // c13->SaveAs("pdgId of Higgs children_bb.pdf");
         //
         // c14->cd();
         // hist_Zlead_pdgid_children->Draw();
         // c14->SaveAs("pdgId of leading Z children.pdf");
         //
         // c15->cd();
         // hist_Zsublead_pdgid_children->Draw();
         // c15->SaveAs("pdgId of subleading Z children.pdf");
         //
         // c16->cd();
         // hist_Zlead_pdgid_children_restriction->Draw();
         // c16->SaveAs("pdgId of leading Z children_uu_cc_dd_ss_bb.pdf");
         //
         // c17->cd();
         // hist_Zsublead_pdgid_children_restriction->Draw();
         // c17->SaveAs("pdgId of subleading Z children_uu_cc_dd_ss_bb.pdf");
         //
         // c18->cd();
         // hist_pt_H_bb->Draw();
         // c18->SaveAs("pT of H->bb system.pdf");
         //
         // c19->cd();
         // hist_pt_Zlead_qq->Draw();
         // c19->SaveAs("pT of Zlead->qq system.pdf");
         //
         // c20->cd();
         // hist_pt_Zsublead_qq->Draw();
         // c20->SaveAs("pT of Zsublead->qq system.pdf");
         //
         // c21->cd();
         // hist_m_H_bb->Draw();
         // c21->SaveAs("invariant mass of H->bb system.pdf");
         //
         // c22->cd();
         // hist_m_Zlead_qq->Draw();
         // c22->SaveAs("invariant mass of Zlead->qq system.pdf");
         //
         // c23->cd();
         // hist_m_Zsublead_qq->Draw();
         // c23->SaveAs("invariant mass of Zsublead->qq system.pdf");
         //
         // c24->cd();
         // hist_eta_H_bb->Draw();
         // c24->SaveAs("eta of H->bb system.pdf");
         //
         // c25->cd();
         // hist_eta_Zlead_qq->Draw();
         // c25->SaveAs("eta of Zlead->qq system.pdf");
         //
         // c26->cd();
         // hist_eta_Zsublead_qq->Draw();
         // c26->SaveAs("eta of Zsublead->qq system.pdf");
         //
         // c27->cd();
         // hist_abs_EtaDiff_H_bb->Draw();
         // c27->SaveAs("abs eta difference between quarks of H->bb system.pdf");
         //
         //
         // c28->cd();
         // hist_abs_EtaDiff_Zlead_qq->Draw();
         // c28->SaveAs("abs eta difference between quarks of Zlead->qq system.pdf");
         //
         //
         // c29->cd();
         // hist_abs_EtaDiff_Zsublead_qq->Draw();
         // c29->SaveAs("abs eta difference between quarks of Zsublead->qq system.pdf");
         //
         //
         // c30->cd();
         // hist_abs_phiDiff_H_bb->Draw();
         // c30->SaveAs("abs phi difference between quarks of H->bb system.pdf");
         //
         //
         // c31->cd();
         // hist_abs_phiDiff_Zlead_qq->Draw();
         // c31->SaveAs("abs phi difference between quarks of Zlead->qq system.pdf");
         //
         //
         // c32->cd();
         // hist_abs_phiDiff_Zsublead_qq->Draw();
         // c32->SaveAs("abs phi difference between quarks of Zsublead->qq system.pdf");
         //
         //
         // c33->cd();
         // hist_abs_deltaR_H_bb->Draw();
         // c33->SaveAs("delta R of H->bb system.pdf");
         //
         //
         // c34->cd();
         // hist_abs_deltaR_Zlead_qq->Draw();
         // c34->SaveAs("delta R of Zlead->qq system.pdf");
         //
         //
         // c35->cd();
         // hist_abs_deltaR_Zsublead_qq->Draw();
         // c35->SaveAs("delta R of Zsublead->qq system.pdf");

         // lead quark VBF jet reconstruction

//          c36->cd();
//          hist_jet_leadVBFquark_ptFraction->Draw();
//          c36->SaveAs("jet_leadVBFquark_ptFraction.pdf");
//
//          c37->cd();
//          hist_jet_leadVBFquark_etaFraction->Draw();
//          c37->SaveAs("jet_leadVBFquark_etaFraction.pdf");
//
//          c38->cd();
//          hist_jet_leadVBFquark_phiFraction->Draw();
//          c38->SaveAs("jet_leadVBFquark_phiFraction.pdf");
//
//          c39->cd();
//          hist_jet_leadVBFquark_pt->Draw();
//          c39->SaveAs("Reco_pt.pdf");
//
//          c40->cd();
//          hist_jet_leadVBFquark_phi->Draw();
//          c40->SaveAs("Reco_phi.pdf");
//
//          c41->cd();
//          hist_jet_leadVBFquark_eta->Draw();
//          c41->SaveAs("Reco_eta.pdf");
//
//          c42->cd();
//          hist_jet_leadVBFquark_Gen_pt->Draw();
//          c42->SaveAs("Gen_pt.pdf");
//
//          c43->cd();
//          hist_jet_leadVBFquark_Gen_eta->Draw();
//          c43->SaveAs("Gen_eta.pdf");
//
//          c44->cd();
//          hist_jet_leadVBFquark_Gen_phi->Draw();
//          c44->SaveAs("Gen_phi.pdf");
//
//          c45->cd();
//          hist_jet_leadVBFquark_deltaR_Reco_Gen->Draw();
//          c45->SaveAs("deltaR_Reco_Gen.pdf");
//
//
//          c46->cd();
//          hist_jet_leadVBFquark_deltaPhi_Reco_Gen->Draw();
//          c46->SaveAs("deltaPhi_Reco_Gen.pdf");
//
//
//          c47->cd();
//          hist_jet_leadVBFquark_deltaEta_Reco_Gen->Draw();
//          c47->SaveAs("deltaEta_Reco_Gen.pdf");
//
//
// // supblead quark VBF jet reconstruction
//
//         c48->cd();
//         hist_jet_subleadVBFquark_ptFraction->Draw();
//         c48->SaveAs("jet_subleadVBFquark_ptFraction.pdf");
//
//         c49->cd();
//         hist_jet_subleadVBFquark_etaFraction->Draw();
//         c49->SaveAs("jet_subleadVBFquark_etaFraction.pdf");
//
//         c50->cd();
//         hist_jet_subleadVBFquark_phiFraction->Draw();
//         c50->SaveAs("jet_subleadVBFquark_phiFraction.pdf");
//
//         c51->cd();
//         hist_jet_subleadVBFquark_pt->Draw();
//         c51->SaveAs("Reco_pt_sublead.pdf");
//
//         c52->cd();
//         hist_jet_subleadVBFquark_phi->Draw();
//         c52->SaveAs("Reco_phi_sublead.pdf");
//
//         c53->cd();
//         hist_jet_subleadVBFquark_eta->Draw();
//         c53->SaveAs("Reco_eta_sublead.pdf");
//
//         c54->cd();
//         hist_jet_subleadVBFquark_Gen_pt->Draw();
//         c54->SaveAs("Gen_pt_sublead.pdf");
//
//         c55->cd();
//         hist_jet_subleadVBFquark_Gen_eta->Draw();
//         c55->SaveAs("Gen_eta_sublead.pdf");
//
//         c56->cd();
//         hist_jet_subleadVBFquark_Gen_phi->Draw();
//         c56->SaveAs("Gen_phi_sublead.pdf");
//
//         c57->cd();
//         hist_jet_subleadVBFquark_deltaR_Reco_Gen->Draw();
//         c57->SaveAs("deltaR_Reco_Gen_sublead.pdf");
//
//
//         c58->cd();
//         hist_jet_subleadVBFquark_deltaPhi_Reco_Gen->Draw();
//         c58->SaveAs("deltaPhi_Reco_Gen_sublead.pdf");
//
//
//         c59->cd();
//         hist_jet_subleadVBFquark_deltaEta_Reco_Gen->Draw();
//         c59->SaveAs("deltaEta_Reco_Gen_sublead.pdf");
//
//         c60->cd();
//         hist_jet_Zlead_qq_ptFraction->Draw();
//         c60->SaveAs("jet_Zlead_qq_ptFraction.pdf");
//
//         c61->cd();
//         hist_jet_Zlead_qq_etaFraction->Draw();
//         c61->SaveAs("jet_Zlead_qq_etaFraction.pdf");
//
//         c62->cd();
//         hist_jet_Zlead_qq_phiFraction->Draw();
//         c62->SaveAs("jet_Zlead_qq_phiFraction.pdf");
//
//         c63->cd();
//         hist_jet_Zlead_qq_pt->Draw();
//         c63->SaveAs("jet_Zlead_qq_pt.pdf");
//
//         c64->cd();
//         hist_jet_Zlead_qq_eta->Draw();
//         c64->SaveAs("jet_Zlead_qq_eta.pdf");
//
//         c65->cd();
//         hist_jet_Zlead_qq_phi->Draw();
//         c65->SaveAs("jet_Zlead_qq_phi.pdf");
//
//         c66->cd();
//         hist_jet_Zlead_qq_Gen_pt->Draw();
//         c66->SaveAs("jet_Zlead_qq_Gen_pt.pdf");
//
//         c67->cd();
//         hist_jet_Zlead_qq_Gen_eta->Draw();
//         c67->SaveAs("jet_Zlead_qq_Gen_eta.pdf");
//
//         c68->cd();
//         hist_jet_Zlead_qq_Gen_phi->Draw();
//         c68->SaveAs("jet_Zlead_qq_Gen_phi.pdf");
//
//         c69->cd();
//         hist_jet_Zlead_qq_deltaR_Reco_Gen_Q1->Draw();
//         c69->SaveAs("jet_Zlead_qq_deltaR_Reco_Gen_Q1.pdf");
//
//         c70->cd();
//         hist_jet_Zlead_qq_deltaPhi_Reco_Gen_Q1->Draw();
//         c70->SaveAs("jet_Zlead_qq_deltaPhi_Reco_Gen_Q1.pdf");
//
//         c71->cd();
//         hist_jet_Zlead_qq_deltaEta_Reco_Gen_Q1->Draw();
//         c71->SaveAs("jet_Zlead_qq_deltaEta_Reco_Gen_Q1.pdf");
// // the sublead zqq histos
//         c72->cd();
//         hist_jet_Zsublead_qq_ptFraction->Draw();
//         c72->SaveAs("jet_Zsublead_qq_ptFraction.pdf");
//
//         c73->cd();
//         hist_jet_Zsublead_qq_etaFraction->Draw();
//         c73->SaveAs("jet_Zsublead_qq_etaFraction.pdf");
//
//         c74->cd();
//         hist_jet_Zsublead_qq_phiFraction->Draw();
//         c74->SaveAs("jet_Zsublead_qq_phiFraction.pdf");
//
//         c75->cd();
//         hist_jet_Zsublead_qq_pt->Draw();
//         c75->SaveAs("jet_Zsublead_qq_pt.pdf");
//
//         c76->cd();
//         hist_jet_Zsublead_qq_eta->Draw();
//         c76->SaveAs("jet_Zsublead_qq_eta.pdf");
//
//         c77->cd();
//         hist_jet_Zsublead_qq_phi->Draw();
//         c77->SaveAs("jet_Zsublead_qq_phi.pdf");
//
//         c78->cd();
//         hist_jet_Zsublead_qq_Gen_pt->Draw();
//         c78->SaveAs("jet_Zsublead_qq_Gen_pt.pdf");
//
//         c79->cd();
//         hist_jet_Zsublead_qq_Gen_eta->Draw();
//         c79->SaveAs("jet_Zsublead_qq_Gen_eta.pdf");
//
//         c80->cd();
//         hist_jet_Zsublead_qq_Gen_phi->Draw();
//         c80->SaveAs("jet_Zsublead_qq_Gen_phi.pdf");
//
//         c81->cd();
//         hist_jet_Zsublead_qq_deltaR_Reco_Gen_Q1->Draw();
//         c81->SaveAs("jet_Zsublead_qq_deltaR_Reco_Gen_Q1.pdf");
//
//         c82->cd();
//         hist_jet_Zsublead_qq_deltaPhi_Reco_Gen_Q1->Draw();
//         c82->SaveAs("jet_Zsublead_qq_deltaPhi_Reco_Gen_Q1.pdf");
//
//         c83->cd();
//         hist_jet_Zsublead_qq_deltaEta_Reco_Gen_Q1->Draw();
//         c83->SaveAs("jet_Zsublead_qq_deltaEta_Reco_Gen_Q1.pdf");
//
//         // for the Higgs reconstruction
//
//         c84->cd();
//         hist_jet_H_bb_ptFraction->Draw();
//         c84->SaveAs("jet_H_bb_ptFraction.pdf");
//
//         c85->cd();
//         hist_jet_H_bb_etaFraction->Draw();
//         c85->SaveAs("jet_H_bb_etaFraction.pdf");
//
//         c86->cd();
//         hist_jet_H_bb_phiFraction->Draw();
//         c86->SaveAs("jet_H_bb_phiFraction.pdf");
//
//         c87->cd();
//         hist_jet_H_bb_pt->Draw();
//         c87->SaveAs("jet_H_bb_pt.pdf");
//
//         c88->cd();
//         hist_jet_H_bb_eta->Draw();
//         c88->SaveAs("jet_H_bb_eta.pdf");
//
//         c89->cd();
//         hist_jet_H_bb_phi->Draw();
//         c89->SaveAs("jet_H_bb_phi.pdf");
//
//         c90->cd();
//         hist_jet_H_bb_Gen_pt->Draw();
//         c90->SaveAs("jet_H_bb_Gen_pt.pdf");
//
//         c91->cd();
//         hist_jet_H_bb_Gen_eta->Draw();
//         c91->SaveAs("jet_H_bb_Gen_eta.pdf");
//
//         c92->cd();
//         hist_jet_H_bb_Gen_phi->Draw();
//         c92->SaveAs("jet_H_bb_Gen_phi.pdf");
//
//         c93->cd();
//         hist_jet_H_bb_deltaR_Reco_Gen_Q1->Draw();
//         c93->SaveAs("jet_H_bb_deltaR_Reco_Gen_Q1.pdf");
//
//         c94->cd();
//         hist_jet_H_bb_deltaPhi_Reco_Gen_Q1->Draw();
//         c94->SaveAs("jet_H_bb_deltaPhi_Reco_Gen_Q1.pdf");
//
//         c95->cd();
//         hist_jet_H_bb_deltaEta_Reco_Gen_Q1->Draw();
//         c95->SaveAs("jet_H_bb_deltaEta_Reco_Gen_Q1.pdf");

           // c96->cd();
           // hist_2d_pt_zlead_DeltaR_qq->Draw();
           // c96->SaveAs("pt_Zlead vs delta R _qq.pdf");
           //

// for the faaat Higgs reconstruction

        // c97->cd();
        // hist_fatjet_H_bb_ptFraction->Draw();
        // c97->SaveAs("fatjet_H_bb_ptFraction.pdf");
        //
        // c98->cd();
        // hist_fatjet_H_bb_etaFraction->Draw();
        // c98->SaveAs("fatjet_H_bb_etaFraction.pdf");
        //
        // c99->cd();
        // hist_fatjet_H_bb_phiFraction->Draw();
        // c99->SaveAs("fatjet_H_bb_phiFraction.pdf");
        //
        // c100->cd();
        // hist_fatjet_H_bb_pt->Draw();
        // c100->SaveAs("fatjet_H_bb_pt.pdf");
        //
        // c101->cd();
        // hist_fatjet_H_bb_eta->Draw();
        // c101->SaveAs("fatjet_H_bb_eta.pdf");
        //
        // c102->cd();
        // hist_fatjet_H_bb_phi->Draw();
        // c102->SaveAs("fatjet_H_bb_phi.pdf");
        //
        // c103->cd();
        // hist_fatjet_H_bb_Gen_pt->Draw();
        // c103->SaveAs("fatjet_H_bb_Gen_pt.pdf");
        //
        // c104->cd();
        // hist_fatjet_H_bb_Gen_eta->Draw();
        // c104->SaveAs("fatjet_H_bb_Gen_eta.pdf");
        //
        // c105->cd();
        // hist_fatjet_H_bb_Gen_phi->Draw();
        // c105->SaveAs("fatjet_H_bb_Gen_phi.pdf");
        //
        // c106->cd();
        // hist_fatjet_H_bb_deltaR_Reco_Gen_Q1->Draw();
        // c106->SaveAs("fatjet_H_bb_deltaR_Reco_Gen_Q1.pdf");
        //
        // c107->cd();
        // hist_fatjet_H_bb_deltaPhi_Reco_Gen_Q1->Draw();
        // c107->SaveAs("fatjet_H_bb_deltaPhi_Reco_Gen_Q1.pdf");
        //
        // c108->cd();
        // hist_fatjet_H_bb_deltaEta_Reco_Gen_Q1->Draw();
        // c108->SaveAs("fatjet_H_bb_deltaEta_Reco_Gen_Q1.pdf");
        //
        // // for the higgs for the fat jet for the score staff
        // c109->cd();
        // hist_fatjet_H_bb_ptFraction_score_method->Draw();
        // c109->SaveAs("fatjet_H_bb_ptFraction_score_method.pdf");
        //
        // c110->cd();
        // hist_fatjet_H_bb_ptFraction_dRmin_method->Draw();
        // c110->SaveAs("fatjet_H_bb_ptFraction_dRmin_method.pdf");

        c121->cd();
        hist_failmode2_Xbbscore_diff_maxXbbscore->Draw();
        c121->SaveAs("failmode2_Xbbscore_diff_maxXbbscore.pdf");














     readf->Write();
         readf->Close();
}
