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
#include "TChain.h"
#include <string>
#include "TString.h"
#include "Nano.h"









//  for tjhe background enEventCount   = 1320000
//nt.genEventSumw()    = 4.14463e+08
//for the signal



int main(int argc, const char* argv[])
{

    using namespace std;
    std::vector<TString> input_files;


    if (argc < 2)
    {
        std::cout << "Error! you must provide a valid argument!"<<std::endl;
        std::cout << "help:" << std::endl;
        std::cout << "" << std::endl;
        std::cout << " e.g." << std::endl;
        std::cout << "    $ " << argv[0] << " " << "signal_zzh" << std::endl;
        std::cout << "    $ " << argv[0] << " " << "signal_wzh" << std::endl;
        std::cout << "    $ " << argv[0] << " " << "signal_wwh" << std::endl;
        std::cout << "    $ " << argv[0] << " " << "signal_oswwh" << std::endl;
        std::cout << "    $ " << argv[0] << " " << "background" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "  User must run the program with one of the above" << std::endl;
        return 1;
    }
    if (argc >2)
    {
        cout << "Error! enter only 2 arguments"<<endl;
        return 2;
    }




    std::string sample_type1 = argv[1];



    TFile * f_output;
    TChain * chain1;
    float cross_section=0;
    // read file and TTree

    if (sample_type1=="background")
    {

        input_files.push_back("/home/users/phchang/public_html/dump/forEslam/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E6EE03D7-5EC1-9D4D-9E41-605619ADD3C2.root ");
        //nt.SetYear(2018);
        f_output =new TFile ("background.root","recreate");
        cross_section=687.1;
        chain1 = new TChain("Runs");
        chain1->Add("/home/users/eslam.zenhom/public_html/uf_work/VBSZZH/E6EE03D7-5EC1-9D4D-9E41-605619ADD3C2.root");
    }
    if (sample_type1=="signal_zzh")
    {

        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_0.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_10.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_11.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_12.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_13.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_14.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_15.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_16.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_17.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_1.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_2.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_3.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_4.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_5.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_6.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_7.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_8.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_9.root");
        f_output =new TFile ("sig_VBSZZH.root","recreate");
        chain1 = new TChain("Runs");
        chain1->Add("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/*.root");
        cross_section=0.0008036;

    }
    if (sample_type1=="signal_oswwh")
    {

        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_0.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_1.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_10.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_11.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_12.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_13.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_14.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_15.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_16.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_17.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_2.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_3.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_4.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_5.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_6.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_7.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_8.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_9.root");

        f_output =new TFile ("sig_VBSOSWWH.root","recreate");
        chain1 = new TChain("Runs");
        chain1->Add("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/*.root");
        cross_section=0.001747;

    }
    if (sample_type1=="signal_wwh")
    {

        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_0.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_1.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_10.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_11.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_12.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_13.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_14.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_15.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_16.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_17.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_2.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_3.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_4.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_5.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_6.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_7.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_8.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_9.root");

        f_output =new TFile ("sig_VBSWWH.root","recreate");
        chain1 = new TChain("Runs");
        chain1->Add("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/*.root");
        cross_section=0.001037;

    }
    if (sample_type1=="signal_wzh")
    {

        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_0.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_1.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_10.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_11.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_12.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_13.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_14.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_15.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_16.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_17.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_2.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_4.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_5.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_6.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_7.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_8.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_9.root");

        f_output =new TFile ("sig_VBSWZH.root","recreate");
        chain1 = new TChain("Runs");
        chain1->Add("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/*.root");
        cross_section=0.001169;

    }


    // initatie the variables



    // singal selection
    std::vector<ROOT::Math::PtEtaPhiMVector> ak4_pt_eta_cut {};
    std::vector<ROOT::Math::PtEtaPhiMVector> ak8_pt_msoftdrop_cut_4d {};
    std::vector<ROOT::Math::PtEtaPhiMVector> ak4_pt_eta_cut_overlap_4d {};
    //std::vector<ROOT::Math::PtEtaPhiMVector> ak8_pt_msoftdrop_cut_4d_overlab {};
    std::vector<float> marker{};
    // std::vector<float> inariant_mass_compare{};
    // std::vector<std::vector<int>> inariant_mass_compare_index_2d{};

    std::vector<float>   vec_H_score{};

    std::vector<ROOT::Math::PtEtaPhiMVector> vec_lead_sublead_bosons_4d {};

    std::vector<float>   vec_msoftdrop_two_bosons{};
    std::vector<float>   vec_msoftdrop{};

    std::vector<float>   vec_V_score{};
    std::vector<float>   vec_btag_score{};
    std::vector<ROOT::Math::PtEtaPhiMVector> vec_btag_4d {};


    std::vector<float>   vec_WvsQCD_score{};
    std::vector<float>   vec_ZvsQCD_score{};
    std::vector<float>   vec_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_XCD_score{};
    std::vector<float>   vec_Vboson_WvsQCD_score{};
    std::vector<float>   vec_Vboson_ZvsQCD_score{};
    std::vector<float>   vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score{};

    //  using the Max-E scheme
    std::vector<float>   vec_lead_sublead_vbfquarks_positive_eta{};
    std::vector<int>   vec_lead_sublead_vbfquarks_positive_eta_index{};
    std::vector<float>   vec_lead_sublead_vbfquarks_negative_eta{};
    std::vector<int>   vec_lead_sublead_vbfquarks_negative_eta_index{};

    // take the other two vv bosons to be the ones with the highest pt after we exclude the highest xbb score from the fat jets to be the higgs
    std::vector<float>   vec_lead_sublead_bosons_pt_tocompare{};





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

    // 29seb hists
    TH1D* hist_pt_scalarsum_VVH_system = new TH1D ("hist_pt_scalarsum_VVH_system"," pt-scalar sum VVH", 80,0,3000);
    TH1D* hist_Xbb_score = new TH1D ("hist_Xbb_score"," Xbb score", 80,0,1);
    TH1D* hist_Vlead_score = new TH1D ("hist_Vlead_score"," Xbb Vlead_score", 80,0,1);
    TH1D* hist_Vsublead_score = new TH1D ("hist_Vsublead_score"," Xbb Vsublead_score", 80,0,1);
    TH1D* hist_btag_score = new TH1D ("hist_btag_score"," b tag score", 80,0,1);
    TH1D* hist_btag_number_inevent = new TH1D ("hist_btag_number_inevent"," btag_number_inevent", 10,0,10);

    TH1D* hist_WvsQCD_Vlead = new TH1D ("hist_WvsQCD_Vlead"," WvsQCD_Vlead", 80,0,1);
    TH1D* hist_WvsQCD_Vsublead = new TH1D ("hist_WvsQCD_Vsublead"," WvsQCD_Vsublead", 80,0,1);
    TH1D* hist_ZvsQCD_Vlead = new TH1D ("hist_ZvsQCD_Vlead"," ZvsQCD_Vlead", 80,0,1);
    TH1D* hist_ZvsQCD_Vsublead = new TH1D ("hist_ZvsQCD_Vsublead"," ZvsQCD_Vsublead", 80,0,1);
    TH1D* hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead = new TH1D ("hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead"," _Vlead", 80,0,1);
    TH1D* hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead = new TH1D ("hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead"," _Vsublead", 80,0,1);




    double genEventSumw[333];
    Long64_t genEventCount[333];
    chain1->SetBranchAddress("genEventCount",&genEventCount);
    chain1->SetBranchAddress("genEventSumw",&genEventSumw);
    int no_runs= chain1->GetEntries();





    int numberm=0;
    int numberm1=0;
    int overlab1=0;
    int cut1=0;
    int cut2=0;
    int cut3=0;
    int cut4=0;
    int cut5=0;
    int nooffat3=0;
    float sumweights=0;
    float sumweights1=0;
    float events_count=0;
    int Nb_lose_nonoverlabbing=0;
    int position_first_quark_with_high_mqq=0;
    int position_second_quark_with_high_mqq=0;




    // for (unsigned ifile2 = 0; ifile2 < input_files.size(); ifile2++)
    // {
    //      TFile* f2 = new TFile(input_files[ifile2]);
    //      TTree* t2 = (TTree*) f2->Get("Runs");
    //      nt.Init(t2);
    //      for (int iii = 0; iii < t2->GetEntries(); ++iii)
    //      {
    //          nt.GetEntry(iii);
    //          // std::cout << "sum: " << sumweights<<std::endl;
    //          //   std::cout << "nt.genEventSumw()[0]: " << nt.genEventSumw()[0]<<std::endl;
    //          sumweights=sumweights+nt.genEventSumw()[0];
    //          events_count=events_count+nt.genEventCount()[0];
    //          // std::cout << "event: " << iii<<std::endl;
    //
    //      }
    //
    // }

    for (int iii = 0; iii < no_runs; iii++)
    {
        chain1->GetEntry(iii);
        // cout << "sum: " << sumweights<<endl;
        //   cout << "genEventSumw[0]: " << genEventSumw[0]<<endl;
        sumweights=sumweights+genEventSumw[0];
        events_count=events_count+genEventCount[0];

        // cout << "event: " << iii<<endl;


    }

    std::cout << "summweights: " << sumweights<<std::endl;
    // std::cout << "summweights1: " << sumweights<<std::endl;

    for (unsigned ifile1 = 0; ifile1 < input_files.size(); ifile1++)
    {
        TFile* f1 = new TFile(input_files[ifile1]);
        TTree* t1 = (TTree*) f1->Get("Events");
        nt.Init(t1);

        for (int i=0; i< t1->GetEntries(); i++)
        {
            nt.GetEntry(i);
            int btag_number_inevent=0;
            if(i% 10000 ==0) std::cout<<i<<std::endl;
            // int Zsublead_index = 9999;
            // int Zlead_index= 9999;
            // int x= 9999;
            // int y=9999;


            if (nt.nFatJet()>0)
            {
                // nevents++;

                // for (int f1 = 0; f1 < nJet[0]; f1++)
                // {
                //   // use the loose btage selection
                //   if (nt.Jet_btagDeepFlavB()[f1]>0.0490 && Jet_pt[f1]>30)
                //   {
                //     vec_btag_score.push_back(nt.Jet_btagDeepFlavB()[f1]);
                //     vec_btag_4d.push_back({nt.Jet_pt[f1],Jet_eta[f1],Jet_phi[f1],Jet_mass[f1]});
                //
                //   }
                // }
                // do the events weights:
                float weight_of_eachevent= (nt.genWeight() /sumweights)*cross_section*1000*137;
                //doing the signal region selction (in this part (i assume i dont know the gen level information and procced from that so i start with all the events i had in the beginging))
                if (nt.nJet()>=2 && nt.nFatJet()>=3)
                {
                    numberm++;
                }
                for (UInt_t i1 = 0; i1 < nt.nJet(); i1++)
                {
                    if (nt.Jet_pt()[i1]>30 && TMath::Abs(nt.Jet_eta()[i1]<4.5) &&nt.Jet_jetId()[i1]>2)
                    {
                        ak4_pt_eta_cut.push_back({nt.Jet_pt()[i1],nt.Jet_eta()[i1],nt.Jet_phi()[i1],nt.Jet_mass()[i1]});

                    }
                }

                for (UInt_t i2 = 0; i2 < nt.nFatJet(); i2++)
                {
                    if (nt.FatJet_pt()[i2]>250 &&nt.FatJet_msoftdrop()[i2]>40 && TMath::Abs(nt.FatJet_eta()[i2]<4.5))
                    {
                        ak8_pt_msoftdrop_cut_4d.push_back({nt.FatJet_pt()[i2],nt.FatJet_eta()[i2],nt.FatJet_phi()[i2],nt.FatJet_mass()[i2]});
                        vec_H_score.push_back(nt.FatJet_particleNetMD_Xbb()[i2]/(nt.FatJet_particleNetMD_Xbb()[i2]+nt.FatJet_particleNetMD_QCD()[i2]));
                        vec_msoftdrop.push_back(nt.FatJet_msoftdrop()[i2]);

                        vec_WvsQCD_score.push_back(nt.FatJet_particleNet_WvsQCD()[i2]);
                        vec_ZvsQCD_score.push_back(nt.FatJet_particleNet_ZvsQCD()[i2]);
                        vec_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_XCD_score.push_back((nt.FatJet_particleNetMD_Xqq()[i2]+nt.FatJet_particleNetMD_Xcc()[i2])/(nt.FatJet_particleNetMD_Xqq()[i2]+nt.FatJet_particleNetMD_Xcc()[i2]+nt.FatJet_particleNetMD_QCD()[i2]));





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
                            //std::cout << "overlabevent: " << i <<std::endl;
                        }
                    }
                    //std::cout << "marker size: " <<marker.size() << "event: " << i <<std::endl;
                    //std::cout << "i3: " << i3<< "event : " <<i << std::endl;
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
                        //std::cout << "ak4_pt_eta_cut_overlap_4d.size(): " <<ak4_pt_eta_cut_overlap_4d.size()<< std::endl;

                            //std::cout <<"i5:"<<i5<< std::endl;
                        for (int i6 = 0; i6 < ak4_pt_eta_cut_overlap_4d.size(); i6++)
                        {

                            //std::cout <<"i6:"<<i6<< std::endl;
                            // inariant_mass_compare.push_back((ak4_pt_eta_cut_overlap_4d[i5]+ak4_pt_eta_cut_overlap_4d[i6]).mass());
                            // std::cout << "inariant_mass_compare: "<< (ak4_pt_eta_cut_overlap_4d[i5]+ak4_pt_eta_cut_overlap_4d[i6]).mass()<< std::endl;
                            // std::cout << "i5: " << i5 <<std::endl;
                            // std::cout << "i6: " << i6 <<std::endl;

                            // inariant_mass_compare_index_2d.push_back({i5,i6});

                            //  using the Max-E scheme
                            // cout<< "event" << i<< endl;
                            // cout << "eta:" << ak4_pt_eta_cut_overlap_4d[i6].eta()<<endl;
                            // cout << "energy:" << ak4_pt_eta_cut_overlap_4d[i6].energy()<<endl;
                            // cout << "index:" <<i6<<endl;


                            if (ak4_pt_eta_cut_overlap_4d[i6].eta()>0)
                            {
                                vec_lead_sublead_vbfquarks_positive_eta.push_back(ak4_pt_eta_cut_overlap_4d[i6].energy());
                                vec_lead_sublead_vbfquarks_positive_eta_index.push_back(i6);
                            }

                            if (ak4_pt_eta_cut_overlap_4d[i6].eta()<0)
                            {
                                vec_lead_sublead_vbfquarks_negative_eta.push_back(ak4_pt_eta_cut_overlap_4d[i6].energy());
                                vec_lead_sublead_vbfquarks_negative_eta_index.push_back(i6);
                            }


                        }
                        if (vec_lead_sublead_vbfquarks_positive_eta.size()>=1 && vec_lead_sublead_vbfquarks_negative_eta.size()>=1)
                        {
                            position_first_quark_with_high_mqq=vec_lead_sublead_vbfquarks_positive_eta_index[max_element(vec_lead_sublead_vbfquarks_positive_eta.begin(),vec_lead_sublead_vbfquarks_positive_eta.end())-vec_lead_sublead_vbfquarks_positive_eta.begin()];
                            position_second_quark_with_high_mqq=vec_lead_sublead_vbfquarks_negative_eta_index[max_element(vec_lead_sublead_vbfquarks_negative_eta.begin(),vec_lead_sublead_vbfquarks_negative_eta.end())-vec_lead_sublead_vbfquarks_negative_eta.begin()];
                        }
                        if (vec_lead_sublead_vbfquarks_positive_eta.size()>=2 && vec_lead_sublead_vbfquarks_negative_eta.size()<1)
                        {
                            position_first_quark_with_high_mqq=vec_lead_sublead_vbfquarks_positive_eta_index[max_element(vec_lead_sublead_vbfquarks_positive_eta.begin(),vec_lead_sublead_vbfquarks_positive_eta.end())-vec_lead_sublead_vbfquarks_positive_eta.begin()];
                            vec_lead_sublead_vbfquarks_positive_eta[max_element(vec_lead_sublead_vbfquarks_positive_eta.begin(),vec_lead_sublead_vbfquarks_positive_eta.end())-vec_lead_sublead_vbfquarks_positive_eta.begin()]=0;
                            position_second_quark_with_high_mqq=vec_lead_sublead_vbfquarks_positive_eta_index[max_element(vec_lead_sublead_vbfquarks_positive_eta.begin(),vec_lead_sublead_vbfquarks_positive_eta.end())-vec_lead_sublead_vbfquarks_positive_eta.begin()];

                        }
                        if (vec_lead_sublead_vbfquarks_positive_eta.size()<1 && vec_lead_sublead_vbfquarks_negative_eta.size()>=2)
                        {
                            position_first_quark_with_high_mqq=vec_lead_sublead_vbfquarks_negative_eta_index[max_element(vec_lead_sublead_vbfquarks_negative_eta.begin(),vec_lead_sublead_vbfquarks_negative_eta.end())-vec_lead_sublead_vbfquarks_negative_eta.begin()];
                            vec_lead_sublead_vbfquarks_negative_eta[max_element(vec_lead_sublead_vbfquarks_negative_eta.begin(),vec_lead_sublead_vbfquarks_negative_eta.end())-vec_lead_sublead_vbfquarks_negative_eta.begin()]=0;
                            position_second_quark_with_high_mqq=vec_lead_sublead_vbfquarks_negative_eta_index[max_element(vec_lead_sublead_vbfquarks_negative_eta.begin(),vec_lead_sublead_vbfquarks_negative_eta.end())-vec_lead_sublead_vbfquarks_negative_eta.begin()];

                        }


                        // int position_first_quark_with_high_mqq=inariant_mass_compare_index_2d[max_element(inariant_mass_compare.begin(),inariant_mass_compare.end())-inariant_mass_compare.begin()][0];
                        // int position_second_quark_with_high_mqq=inariant_mass_compare_index_2d[max_element(inariant_mass_compare.begin(),inariant_mass_compare.end())-inariant_mass_compare.begin()][1];
                        // cout << "first ppostion:" <<  position_first_quark_with_high_mqq<<endl;
                        // cout << "second ppostion:" <<  position_second_quark_with_high_mqq<<endl;

                        if (TMath::Abs(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta()-ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta())>3)
                        {
                            cut3++;
                            if ((ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq]+ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq]).mass()>700)
                            {
                                cut4++;
                                if ((TMath::Abs(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta()-ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta()))>5)
                                {
                                    cut5++;



                                    // for (int i5 = 0; i5 < ak4_pt_eta_cut_overlap_4d.size()-1; i5++)
                                    // {
                                    //     //std::cout <<"i5:"<<i5<< std::endl;
                                    //     for (int i6 = i5+1; i6 < ak4_pt_eta_cut_overlap_4d.size(); i6++)
                                    //     {
                                    //         //std::cout <<"i6:"<<i6<< std::endl;
                                    //         inariant_mass_compare.push_back((ak4_pt_eta_cut_overlap_4d[i5]+ak4_pt_eta_cut_overlap_4d[i6]).mass());
                                    //         // std::cout << "inariant_mass_compare: "<< (ak4_pt_eta_cut_overlap_4d[i5]+ak4_pt_eta_cut_overlap_4d[i6]).mass()<< std::endl;
                                    //         // std::cout << "i5: " << i5 <<std::endl;
                                    //         // std::cout << "i6: " << i6 <<std::endl;
                                    //
                                    //         inariant_mass_compare_index_2d.push_back({i5,i6});
                                    //
                                    //     }
                                    // }
                                    // int position_first_quark_with_high_mqq=inariant_mass_compare_index_2d[max_element(inariant_mass_compare.begin(),inariant_mass_compare.end())-inariant_mass_compare.begin()][0];
                                    // int position_second_quark_with_high_mqq=inariant_mass_compare_index_2d[max_element(inariant_mass_compare.begin(),inariant_mass_compare.end())-inariant_mass_compare.begin()][1];

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
                                    //     vec_H_score.push_back(nt.FatJet_particleNetMD_Xbb()[i7]/(nt.FatJet_particleNetMD_Xbb()[i7]+nt.FatJet_particleNetMD_QCD()[i7]));
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
                                            vec_V_score.push_back(vec_H_score[i8]);

                                            vec_Vboson_WvsQCD_score.push_back(vec_WvsQCD_score[i8]);
                                            vec_Vboson_ZvsQCD_score.push_back(vec_ZvsQCD_score[i8]);
                                            vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score.push_back(vec_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_XCD_score[i8]);



                                        }
                                    }


                                    // take the other two vv bosons to be the ones with the highest pt after we exclude the highest xbb score from the fat jets to be the higgs
                                    //cout << "event number: " << i<< endl;


                                    for (int ss1 = 0; ss1 < vec_lead_sublead_bosons_4d.size(); ss1++)
                                    {
                                        vec_lead_sublead_bosons_pt_tocompare.push_back(vec_lead_sublead_bosons_4d[ss1].pt());
                                        // cout << "index of boson: " << ss1<< endl;
                                        // cout << "pt of boson: " << vec_lead_sublead_bosons_4d[ss1].pt()<< endl;
                                    }

                                    int v0 =max_element(vec_lead_sublead_bosons_pt_tocompare.begin(),vec_lead_sublead_bosons_pt_tocompare.end())-vec_lead_sublead_bosons_pt_tocompare.begin();
                                    vec_lead_sublead_bosons_pt_tocompare[v0]=0;
                                    int v1 =max_element(vec_lead_sublead_bosons_pt_tocompare.begin(),vec_lead_sublead_bosons_pt_tocompare.end())-vec_lead_sublead_bosons_pt_tocompare.begin();
                                    // cout << "index of first boson: " << v0<< endl;
                                    // cout << "index of second boson: " << v1<< endl;



                                    for (int f1 = 0; f1 < nt.nJet(); f1++)
                                    {
                                        // use the loose btage selection
                                        if (nt.Jet_btagDeepFlavB()[f1]>0.0490 && nt.Jet_pt()[f1]>30)
                                        {
                                            vec_btag_score.push_back(nt.Jet_btagDeepFlavB()[f1]);
                                            vec_btag_4d.push_back({nt.Jet_pt()[f1],nt.Jet_eta()[f1],nt.Jet_phi()[f1],nt.Jet_mass()[f1]});

                                        }
                                    }
                                    // compare overlapping of btag jets with the higgs max xbb score and then i would do it inside the below loop when the xbb isn't max to compare the btagged b with the other b's which resukted in the VV H_Boson_Boson
                                    for (int f3 = 0; f3 < vec_btag_score.size(); f3++)
                                    {


                                        double drrr2= sqrt(pow(TMath::Abs(vec_btag_4d[f3].eta()-ak8_pt_msoftdrop_cut_4d[position_max_H_score].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec_btag_4d[f3],ak8_pt_msoftdrop_cut_4d[position_max_H_score])),2));
                                        double drrr3= sqrt(pow(TMath::Abs(vec_btag_4d[f3].eta()-vec_lead_sublead_bosons_4d[v0].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec_btag_4d[f3],vec_lead_sublead_bosons_4d[v0])),2));
                                        double drrr4= sqrt(pow(TMath::Abs(vec_btag_4d[f3].eta()-vec_lead_sublead_bosons_4d[v1].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec_btag_4d[f3],vec_lead_sublead_bosons_4d[v1])),2));

                                        if (drrr2>0.8 && drrr3>0.8 && drrr4>0.8)
                                        {
                                            Nb_lose_nonoverlabbing++;
                                            hist_btag_score->Fill(vec_btag_score[f3],weight_of_eachevent);
                                            btag_number_inevent++;

                                        }
                                    }
                                    hist_btag_number_inevent->Fill(btag_number_inevent);
                                    // std::cout <<"event: "<< i <<std::endl;
                                    // std::cout <<"btag_number_inevent:" <<btag_number_inevent<<std::endl;



                                    if (vec_lead_sublead_bosons_4d[v0].pt()>vec_lead_sublead_bosons_4d[v1].pt())
                                    {
                                        hist_pt_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].pt(),weight_of_eachevent);
                                        hist_pt_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].pt(),weight_of_eachevent);
                                        hist_eta_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].eta(),weight_of_eachevent);
                                        hist_eta_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].eta(),weight_of_eachevent);
                                        hist_phi_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].phi(),weight_of_eachevent);
                                        hist_phi_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].phi(),weight_of_eachevent);
                                        hist_m_leadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[v0],weight_of_eachevent);
                                        hist_m_subleadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[v1],weight_of_eachevent);

                                        hist_Vlead_score->Fill(vec_V_score[v0],weight_of_eachevent);
                                        hist_Vsublead_score->Fill(vec_V_score[v1],weight_of_eachevent);

                                        hist_WvsQCD_Vlead->Fill(vec_Vboson_WvsQCD_score[v0],weight_of_eachevent);
                                        hist_WvsQCD_Vsublead->Fill(vec_Vboson_WvsQCD_score[v1],weight_of_eachevent);
                                        hist_ZvsQCD_Vlead->Fill(vec_Vboson_ZvsQCD_score[v0],weight_of_eachevent);
                                        hist_ZvsQCD_Vsublead->Fill(vec_Vboson_ZvsQCD_score[v1],weight_of_eachevent);
                                        hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead->Fill(vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score[v0],weight_of_eachevent);
                                        hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead->Fill(vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score[v1],weight_of_eachevent);




                                    }
                                    else
                                    {
                                        hist_pt_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].pt(),weight_of_eachevent);
                                        hist_pt_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].pt(),weight_of_eachevent);
                                        hist_eta_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].eta(),weight_of_eachevent);
                                        hist_eta_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].eta(),weight_of_eachevent);
                                        hist_phi_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].phi(),weight_of_eachevent);
                                        hist_phi_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].phi(),weight_of_eachevent);
                                        hist_m_leadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[v1],weight_of_eachevent);
                                        hist_m_subleadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[v0],weight_of_eachevent);

                                        hist_Vlead_score->Fill(vec_V_score[v1],weight_of_eachevent);
                                        hist_Vsublead_score->Fill(vec_V_score[v0],weight_of_eachevent);

                                        hist_WvsQCD_Vlead->Fill(vec_Vboson_WvsQCD_score[v1],weight_of_eachevent);
                                        hist_WvsQCD_Vsublead->Fill(vec_Vboson_WvsQCD_score[v0],weight_of_eachevent);
                                        hist_ZvsQCD_Vlead->Fill(vec_Vboson_ZvsQCD_score[v1],weight_of_eachevent);
                                        hist_ZvsQCD_Vsublead->Fill(vec_Vboson_ZvsQCD_score[v0],weight_of_eachevent);
                                        hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead->Fill(vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score[v1],weight_of_eachevent);
                                        hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead->Fill(vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score[v0],weight_of_eachevent);
                                    }

                                    // invariant mass of H_Boson_Boson system
                                    hist_mass_HBosonBoson_system->Fill(ak8_pt_msoftdrop_cut_4d[position_max_H_score].pt()+vec_lead_sublead_bosons_4d[v0].pt()+vec_lead_sublead_bosons_4d[v1].pt(),weight_of_eachevent);

                                    hist_pt_scalarsum_VVH_system->Fill((ak8_pt_msoftdrop_cut_4d[position_max_H_score]+vec_lead_sublead_bosons_4d[v0]+vec_lead_sublead_bosons_4d[v1]).mass(),weight_of_eachevent);
                                    hist_Xbb_score->Fill(vec_H_score[position_max_H_score],weight_of_eachevent);


                                    // }

                                }
                            }

                        }
                    }


                }


                ak4_pt_eta_cut.clear();
                ak8_pt_msoftdrop_cut_4d.clear();
                ak4_pt_eta_cut_overlap_4d.clear();
                //ak8_pt_msoftdrop_cut_4d_overlab.clear();
                marker.clear();
                // inariant_mass_compare.clear();
                // inariant_mass_compare_index_2d.clear();
                vec_H_score.clear();
                vec_lead_sublead_bosons_4d.clear();
                vec_msoftdrop_two_bosons.clear();
                vec_msoftdrop.clear();
                vec_V_score.clear();
                vec_btag_score.clear();
                vec_btag_4d.clear();

                vec_WvsQCD_score.clear();
                vec_ZvsQCD_score.clear();
                vec_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_XCD_score.clear();
                vec_Vboson_WvsQCD_score.clear();
                vec_Vboson_ZvsQCD_score.clear();
                vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score.clear();

                vec_lead_sublead_vbfquarks_positive_eta.clear();
                vec_lead_sublead_vbfquarks_positive_eta_index.clear();
                vec_lead_sublead_vbfquarks_negative_eta.clear();
                vec_lead_sublead_vbfquarks_negative_eta_index.clear();
                vec_lead_sublead_bosons_pt_tocompare.clear();




            }


        }
    }
    // the first bracked here is for the if condition that nt.nFatJet()s large than zero to start redaing the ttres and all that cuz other events doesnt have fat jet in this root file




    // std::cout << "numberm: " << numberm << std::endl;
    // std::cout << "numberm1: " << numberm1 << std::endl;
    // std::cout << "overlab1: " << overlab1 << std::endl;
    // std::cout << "nooffat3: " << nooffat3 << std::endl;
    float cut1_weighted=0;
    float cut2_weighted=0;
    float cut3_weighted=0;
    float cut4_weighted=0;
    float cut5_weighted=0;
    cut1_weighted=(cut1/events_count)*137*1000*cross_section;
    cut2_weighted=(cut2/events_count)*137*1000*cross_section;
    cut3_weighted=(cut3/events_count)*137*1000*cross_section;
    cut4_weighted=(cut4/events_count)*137*1000*cross_section;
    cut5_weighted=(cut5/events_count)*137*1000*cross_section;
    std::cout << "cut1: " << cut1 << std::endl;
    std::cout << "cut2: " << cut2 << std::endl;
    std::cout << "cut3: " << cut3 << std::endl;
    std::cout << "cut4: " << cut4 << std::endl;
    std::cout << "cut5: " << cut5 << std::endl;
    std::cout << "events_count: " << events_count << std::endl;
    std::cout << "Nb_lose_nonoverlabbing: " << Nb_lose_nonoverlabbing << std::endl;
    std::cout<< "cut1 weighted:" << cut1_weighted<<endl;
    std::cout<< "cut2 weighted:" << cut2_weighted<<endl;
    std::cout<< "cut3 weighted:" << cut3_weighted<<endl;
    std::cout<< "cut4 weighted:" << cut4_weighted<<endl;
    std::cout<< "cut5 weighted:" << cut5_weighted<<endl;
    std::cout<< "nocut weighted:" << (events_count/events_count)*137*1000*cross_section<<endl;
    std::cout<< "error cut1 weighted:" << cut1_weighted *(sqrt(cut1)/cut1)<<endl;
    std::cout<< "error cut2 weighted:" << cut2_weighted *(sqrt(cut2)/cut2)<<endl;
    std::cout<< "error cut3 weighted:" << cut3_weighted *(sqrt(cut3)/cut3)<<endl;
    std::cout<< "error cut4 weighted:" << cut4_weighted *(sqrt(cut4)/cut4)<<endl;
    std::cout<< "error cut5 weighted:" << cut5_weighted *(sqrt(cut5)/cut5)<<endl;
    std::cout<< "error nocut weighted:" << ((events_count/events_count)*137*1000*cross_section)*(sqrt(events_count)/events_count)<<endl;




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
    //29seb
    hist_pt_scalarsum_VVH_system->Write();
    hist_Xbb_score->Write();
    hist_Vlead_score->Write();
    hist_Vsublead_score->Write();
    hist_btag_score->Write();
    hist_btag_number_inevent->Write();

    hist_WvsQCD_Vlead->Write();
    hist_WvsQCD_Vsublead->Write();
    hist_ZvsQCD_Vlead->Write();
    hist_ZvsQCD_Vsublead->Write();
    hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead->Write();
    hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead->Write();


    // ->Write();



















}
