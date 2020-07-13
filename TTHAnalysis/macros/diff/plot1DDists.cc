{
// *** Constants ***
  const int nBins = 100;
  const double Offset = 1.2;
  const TString TVet = "NoTop";
  const TString BVet = "MediumBottom";
  const TString PTResBool = ""; // "_NoPTRes"
  const TString fileName = "2lss_diff/TTHnobb_fxfx_Friend_"+TVet+BVet+PTResBool+"Veto.root";

// *** Files ***
//  TFile f(fileName);
//  TFile f("2lss_diff/original/TTHnobb_fxfx_Friend_NoTopMediumBottomVeto.root");
  TFile f("2lss_diff/TTHnobb_fxfx_Friend.root");
//  TFile f("2lss_diff/backups/OptimizationPresentation_062320/TTHnobb_fxfx_Default_Friend.root");
//  TFile f("2lss_diff/backups/OptimizationPresentation_062320/TTHnobb_fxfx_NoWindows_Friend.root");
//  TFile f("2lss_diff/backups/OptimizationPresentation_062320/TTHnobb_fxfx_NoWindowsNoConstraint_Friend.root");
//  TFile f("2lss_diff/backups/OptimizationPresentation_062320/TTHnobb_fxfx_NewDefaultMediumBVeto_Friend.root");
//  TFile f("2lss_diff/backups/OptimizationPresentation_062320/TTHnobb_fxfx_Correct_Friend.root");
//  TFile f("2lss_diff/backups/OptimizationPresentation_062320/TTHnobb_fxfx_DelLWThenDelRMediumBVeto_Friend.root");
//  TFile f("2lss_diff/backups/OptimizationPresentation_062320/TTHnobb_fxfx_LepWithLeastBLikeNeighbourThenDelRNoBVeto_Friend.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Current_Friend.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_NoWindows_Friend.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_NoTopNoBottomVeto.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_NoTopMediumBottomVeto.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_NoTopLooseBottomVeto.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_TopNoBottomVeto.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_TopMediumBottomVeto.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_TopLooseBottomVeto.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_NoTopNoBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_NoTopMediumBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_NoTopLooseBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_TopNoBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_TopMediumBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff/TTHnobb_fxfx_Friend_TopLooseBottomVeto_NoPTRes.root");
  TTree *ft = (TTree*) f.Get("Friends");

// *** Declare variables ***
  // reconstruction loop dependent vars
  float Hreco_minDRlj;
  float Hreco_delR_H_j1j2;
  float Hreco_visHmass;
  float Hreco_Wmass;
  float Hreco_lepIdx;
  float Hreco_j1Idx;
  float Hreco_j2Idx;
  float Hreco_pTVisPlusNu;
  float Hreco_pTHvis;
  float Hreco_pTVis_jets_match;
  float Hreco_MVis_jets_match;
  float Hreco_nmatchedleptons;
  float Hreco_nmatchedpartons;
  float Hreco_nmismatchedtoptaggedjets;
  float Hreco_delR_H_j1l_reco;
  float Hreco_delR_H_j2l_reco;
  float Hreco_maxdR;
  float Hreco_mindR;
  float Hreco_maxdRW;
  float Hreco_mindRW;
  float Hreco_PtTop_recohtt;
  float Hreco_MTop_recohtt;
  float Hreco_PtWFromTop_recohtt;
  float Hreco_MWFromTop_recohtt;
  float Hreco_WFromTop_rightlep_delr;
  float Hreco_WFromTop_wronglep_delr;

  float Hreco_minDRlj_correct;
  float Hreco_delR_H_j1j2_correct;
  float Hreco_visHmass_correct;
  float Hreco_Wmass_correct;
  float Hreco_lepIdx_correct;
  float Hreco_j1Idx_correct;
  float Hreco_j2Idx_correct;
  float Hreco_pTVisPlusNu_correct;
  float Hreco_pTHvis_correct;
  float Hreco_delR_H_j1l_reco_correct;
  float Hreco_delR_H_j2l_reco_correct;
  float Hreco_maxdR_correct;
  float Hreco_mindR_correct;
  float Hreco_maxdRW_correct;
  float Hreco_mindRW_correct;

  // delR and closest jet vars
  float Hreco_delR_H_partons;
  float Hreco_delR_H_q1l;
  float Hreco_delR_H_q2l;
  float Hreco_closestJetInDelR_pt_ToQ1FromWFromH;
  float Hreco_closestJetInDelR_pt_ToQ2FromWFromH;
  float Hreco_closestJetInDelR_ptres_ToQ1FromWFromH;
  float Hreco_closestJetInDelR_ptres_ToQ2FromWFromH;
  float Hreco_closestJetInDelR_delR_ToQ1FromWFromH;
  float Hreco_closestJetInDelR_delR_ToQ2FromWFromH;
  float Hreco_closestJetInDelR_flavour_ToQ1FromWFromH;
  float Hreco_closestJetInDelR_flavour_ToQ2FromWFromH;
  float Hreco_closestJetInPTRes_pt_ToQ1FromWFromH;
  float Hreco_closestJetInPTRes_pt_ToQ2FromWFromH;
  float Hreco_closestJetInPTRes_ptres_ToQ1FromWFromH;
  float Hreco_closestJetInPTRes_ptres_ToQ2FromWFromH;
  float Hreco_closestJetInPTRes_delR_ToQ1FromWFromH;
  float Hreco_closestJetInPTRes_delR_ToQ2FromWFromH;
  float Hreco_closestJetInPTRes_flavour_ToQ1FromWFromH;
  float Hreco_closestJetInPTRes_flavour_ToQ2FromWFromH;
  
  // lists from gen loop
  float Hreco_nWFromH;
  float Hreco_nQFromWFromH;
  float Hreco_nLFromWFromH;
  float Hreco_nQFromWFromT;
  float Hreco_nLFromWFromT;
  float Hreco_nNuFromWFromH;
  float Hreco_nNuFromWFromT;
  float Hreco_nZFromH;
  float Hreco_nQFromZFromH;
  float Hreco_nLFromZFromH;
  float Hreco_nNuFromZFromH;
  float Hreco_nTauFromH;
  float Hreco_nPiFromTauFromH;
  float Hreco_nLFromTauFromH;
  float Hreco_nNuFromTauFromH;
  float Hreco_nTNuFromTauFromH;
  float Hreco_nKaFromTauFromH;
  float Hreco_nLFromTauFromWFromH;
  float Hreco_nhFromTauFromWFromH;
  float Hreco_nTauFromWFromH;
  float Hreco_nFO;
  float Hreco_nLeptonicTops;
  float Hreco_nHadTop;
  float Hreco_nJetsInCollection;
  
  // kinematics of gen-level objects and matched objects
  float Hreco_pTTrueGen;
  float Hreco_MTrueGen;
  float Hreco_pTTrueGenPlusNu;
  float Hreco_pTGenQuarks;
  float Hreco_dRGenQuarks;
  float Hreco_MGenQuarks;
  float Hreco_pTtgen;
  float Hreco_pTHgen;
  float Hreco_quark1pT;
  float Hreco_quark2pT;
  float Hreco_quark1Eta;
  float Hreco_quark2Eta;
  float Hreco_quark1Flavour;
  float Hreco_quark2Flavour;
  float Hreco_jet_matches_quark1_delr;
  float Hreco_jet_matches_quark2_delr;
  float Hreco_jet_matches_quark1_ptres;
  float Hreco_jet_matches_quark2_ptres;
  float Hreco_M_jets_match;
  float Hreco_matchRank;
  float Hreco_bestRank;
  float Hreco_mHRightLepton;
  float Hreco_mHWrongLepton;
  float Hreco_HadTopPt;
  float Hreco_HadTopM;
  float Hreco_WFromHadTopPt;
  float Hreco_WFromHadTopM;
  float Hreco_WFromHiggsPt;
  float Hreco_WFromHiggsM;

  // reconstruction loop dependent vars
  ft->SetBranchAddress("Hreco_minDRlj",&Hreco_minDRlj);
  ft->SetBranchAddress("Hreco_delR_H_j1j2",&Hreco_delR_H_j1j2);
  ft->SetBranchAddress("Hreco_visHmass",&Hreco_visHmass);
  ft->SetBranchAddress("Hreco_Wmass",&Hreco_Wmass);
  ft->SetBranchAddress("Hreco_lepIdx",&Hreco_lepIdx);
  ft->SetBranchAddress("Hreco_j1Idx",&Hreco_j1Idx);
  ft->SetBranchAddress("Hreco_j2Idx",&Hreco_j2Idx);
  ft->SetBranchAddress("Hreco_pTVisPlusNu",&Hreco_pTVisPlusNu);
  ft->SetBranchAddress("Hreco_pTHvis",&Hreco_pTHvis);
  ft->SetBranchAddress("Hreco_pTVis_jets_match",&Hreco_pTVis_jets_match);
  ft->SetBranchAddress("Hreco_MVis_jets_match",&Hreco_MVis_jets_match);
  ft->SetBranchAddress("Hreco_nmatchedleptons",&Hreco_nmatchedleptons);
  ft->SetBranchAddress("Hreco_nmatchedpartons",&Hreco_nmatchedpartons);
  ft->SetBranchAddress("Hreco_nmismatchedtoptaggedjets",&Hreco_nmismatchedtoptaggedjets);
  ft->SetBranchAddress("Hreco_delR_H_j1l_reco",&Hreco_delR_H_j1l_reco);
  ft->SetBranchAddress("Hreco_delR_H_j2l_reco",&Hreco_delR_H_j2l_reco);
  ft->SetBranchAddress("Hreco_maxdR",&Hreco_maxdR);
  ft->SetBranchAddress("Hreco_mindR",&Hreco_mindR);
  ft->SetBranchAddress("Hreco_maxdRW",&Hreco_maxdRW);
  ft->SetBranchAddress("Hreco_mindRW",&Hreco_mindRW);
  ft->SetBranchAddress("Hreco_PtTop_recohtt",&Hreco_PtTop_recohtt);
  ft->SetBranchAddress("Hreco_MTop_recohtt",&Hreco_MTop_recohtt);
  ft->SetBranchAddress("Hreco_PtWFromTop_recohtt",&Hreco_PtWFromTop_recohtt);
  ft->SetBranchAddress("Hreco_MWFromTop_recohtt",&Hreco_MWFromTop_recohtt);
  ft->SetBranchAddress("Hreco_WFromTop_rightlep_delr",&Hreco_WFromTop_rightlep_delr);
  ft->SetBranchAddress("Hreco_WFromTop_wronglep_delr",&Hreco_WFromTop_wronglep_delr);

  ft->SetBranchAddress("Hreco_minDRlj_correct",&Hreco_minDRlj_correct);
  ft->SetBranchAddress("Hreco_delR_H_j1j2_correct",&Hreco_delR_H_j1j2_correct);
  ft->SetBranchAddress("Hreco_visHmass_correct",&Hreco_visHmass_correct);
  ft->SetBranchAddress("Hreco_Wmass_correct",&Hreco_Wmass_correct);
  ft->SetBranchAddress("Hreco_lepIdx_correct",&Hreco_lepIdx_correct);
  ft->SetBranchAddress("Hreco_j1Idx_correct",&Hreco_j1Idx_correct);
  ft->SetBranchAddress("Hreco_j2Idx_correct",&Hreco_j2Idx_correct);
  ft->SetBranchAddress("Hreco_pTVisPlusNu_correct",&Hreco_pTVisPlusNu_correct);
  ft->SetBranchAddress("Hreco_pTHvis_correct",&Hreco_pTHvis_correct);
  ft->SetBranchAddress("Hreco_delR_H_j1l_reco_correct",&Hreco_delR_H_j1l_reco_correct);
  ft->SetBranchAddress("Hreco_delR_H_j2l_reco_correct",&Hreco_delR_H_j2l_reco_correct);
  ft->SetBranchAddress("Hreco_maxdR_correct",&Hreco_maxdR_correct);
  ft->SetBranchAddress("Hreco_mindR_correct",&Hreco_mindR_correct);
  ft->SetBranchAddress("Hreco_maxdRW_correct",&Hreco_maxdRW_correct);
  ft->SetBranchAddress("Hreco_mindRW_correct",&Hreco_mindRW_correct);
   
  // delR and closest jet vars
  ft->SetBranchAddress("Hreco_delR_H_partons",&Hreco_delR_H_partons);
  ft->SetBranchAddress("Hreco_delR_H_q1l",&Hreco_delR_H_q1l);
  ft->SetBranchAddress("Hreco_delR_H_q2l",&Hreco_delR_H_q2l);
  ft->SetBranchAddress("Hreco_closestJetInDelR_pt_ToQ1FromWFromH",&Hreco_closestJetInDelR_pt_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInDelR_pt_ToQ2FromWFromH",&Hreco_closestJetInDelR_pt_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInDelR_ptres_ToQ1FromWFromH",&Hreco_closestJetInDelR_ptres_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInDelR_ptres_ToQ2FromWFromH",&Hreco_closestJetInDelR_ptres_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInDelR_delR_ToQ1FromWFromH",&Hreco_closestJetInDelR_delR_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInDelR_delR_ToQ2FromWFromH",&Hreco_closestJetInDelR_delR_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInDelR_flavour_ToQ1FromWFromH",&Hreco_closestJetInDelR_flavour_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInDelR_flavour_ToQ2FromWFromH",&Hreco_closestJetInDelR_flavour_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInPTRes_pt_ToQ1FromWFromH",&Hreco_closestJetInPTRes_pt_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInPTRes_pt_ToQ2FromWFromH",&Hreco_closestJetInPTRes_pt_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInPTRes_ptres_ToQ1FromWFromH",&Hreco_closestJetInPTRes_ptres_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInPTRes_ptres_ToQ2FromWFromH",&Hreco_closestJetInPTRes_ptres_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInPTRes_delR_ToQ1FromWFromH",&Hreco_closestJetInPTRes_delR_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInPTRes_delR_ToQ2FromWFromH",&Hreco_closestJetInPTRes_delR_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInPTRes_flavour_ToQ1FromWFromH",&Hreco_closestJetInPTRes_flavour_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJetInPTRes_flavour_ToQ2FromWFromH",&Hreco_closestJetInPTRes_flavour_ToQ2FromWFromH);
  
  // lists from gen loop
  ft->SetBranchAddress("Hreco_nWFromH",&Hreco_nWFromH);
  ft->SetBranchAddress("Hreco_nQFromWFromH",&Hreco_nQFromWFromH);
  ft->SetBranchAddress("Hreco_nLFromWFromH",&Hreco_nLFromWFromH);
  ft->SetBranchAddress("Hreco_nQFromWFromT",&Hreco_nQFromWFromT);
  ft->SetBranchAddress("Hreco_nLFromWFromT",&Hreco_nLFromWFromT);
  ft->SetBranchAddress("Hreco_nNuFromWFromH",&Hreco_nNuFromWFromH);
  ft->SetBranchAddress("Hreco_nNuFromWFromT",&Hreco_nNuFromWFromT);
  ft->SetBranchAddress("Hreco_nZFromH",&Hreco_nZFromH);
  ft->SetBranchAddress("Hreco_nQFromZFromH",&Hreco_nQFromZFromH);
  ft->SetBranchAddress("Hreco_nLFromZFromH",&Hreco_nLFromZFromH);
  ft->SetBranchAddress("Hreco_nNuFromZFromH",&Hreco_nNuFromZFromH);
  ft->SetBranchAddress("Hreco_nTauFromH",&Hreco_nTauFromH);
  ft->SetBranchAddress("Hreco_nPiFromTauFromH",&Hreco_nPiFromTauFromH);
  ft->SetBranchAddress("Hreco_nLFromTauFromH",&Hreco_nLFromTauFromH);
  ft->SetBranchAddress("Hreco_nNuFromTauFromH",&Hreco_nNuFromTauFromH);
  ft->SetBranchAddress("Hreco_nTNuFromTauFromH",&Hreco_nTNuFromTauFromH);
  ft->SetBranchAddress("Hreco_nKaFromTauFromH",&Hreco_nKaFromTauFromH);
  ft->SetBranchAddress("Hreco_nLFromTauFromWFromH",&Hreco_nLFromTauFromWFromH);
  ft->SetBranchAddress("Hreco_nhFromTauFromWFromH",&Hreco_nhFromTauFromWFromH);
  ft->SetBranchAddress("Hreco_nTauFromWFromH",&Hreco_nTauFromWFromH);
  ft->SetBranchAddress("Hreco_nFO",&Hreco_nFO);
  ft->SetBranchAddress("Hreco_nLeptonicTops",&Hreco_nLeptonicTops);
  ft->SetBranchAddress("Hreco_nHadTop",&Hreco_nHadTop);
  ft->SetBranchAddress("Hreco_nJetsInCollection",&Hreco_nJetsInCollection);
  
  // kinematics of gen-level objects and matched objects
  ft->SetBranchAddress("Hreco_pTTrueGen",&Hreco_pTTrueGen);
  ft->SetBranchAddress("Hreco_MTrueGen",&Hreco_MTrueGen);
  ft->SetBranchAddress("Hreco_pTTrueGenPlusNu",&Hreco_pTTrueGenPlusNu);
  ft->SetBranchAddress("Hreco_pTGenQuarks",&Hreco_pTGenQuarks);
  ft->SetBranchAddress("Hreco_dRGenQuarks",&Hreco_dRGenQuarks);
  ft->SetBranchAddress("Hreco_MGenQuarks",&Hreco_MGenQuarks);
  ft->SetBranchAddress("Hreco_pTtgen",&Hreco_pTtgen);
  ft->SetBranchAddress("Hreco_pTHgen",&Hreco_pTHgen);
  ft->SetBranchAddress("Hreco_quark1pT",&Hreco_quark1pT);
  ft->SetBranchAddress("Hreco_quark2pT",&Hreco_quark2pT);
  ft->SetBranchAddress("Hreco_quark1Eta",&Hreco_quark1Eta);
  ft->SetBranchAddress("Hreco_quark2Eta",&Hreco_quark2Eta);  
  ft->SetBranchAddress("Hreco_quark1Flavour",&Hreco_quark1Flavour);
  ft->SetBranchAddress("Hreco_quark2Flavour",&Hreco_quark2Flavour);
  ft->SetBranchAddress("Hreco_jet_matches_quark1_delr",&Hreco_jet_matches_quark1_delr);
  ft->SetBranchAddress("Hreco_jet_matches_quark2_delr",&Hreco_jet_matches_quark2_delr);
  ft->SetBranchAddress("Hreco_jet_matches_quark1_ptres",&Hreco_jet_matches_quark1_ptres);
  ft->SetBranchAddress("Hreco_jet_matches_quark2_ptres",&Hreco_jet_matches_quark2_ptres);
  ft->SetBranchAddress("Hreco_M_jets_match",&Hreco_M_jets_match);
  ft->SetBranchAddress("Hreco_matchRank",&Hreco_matchRank);
  ft->SetBranchAddress("Hreco_bestRank",&Hreco_bestRank);
  ft->SetBranchAddress("Hreco_mHRightLepton",&Hreco_mHRightLepton);
  ft->SetBranchAddress("Hreco_mHWrongLepton",&Hreco_mHWrongLepton);
  ft->SetBranchAddress("Hreco_HadTopPt",&Hreco_HadTopPt);
  ft->SetBranchAddress("Hreco_HadTopM",&Hreco_HadTopM);
  ft->SetBranchAddress("Hreco_WFromHadTopPt",&Hreco_WFromHadTopPt);
  ft->SetBranchAddress("Hreco_WFromHadTopM",&Hreco_WFromHadTopM);
  ft->SetBranchAddress("Hreco_WFromHiggsPt",&Hreco_WFromHiggsPt);
  ft->SetBranchAddress("Hreco_WFromHiggsM",&Hreco_WFromHiggsM);  

// *** Declare histograms *** 
  TH1D *hst_pTHvis = new TH1D("hst_pTHvis","hst_pTHvis",nBins,-0.5,599.5);
  TH1D *hst_pTVisPlusNu = new TH1D("pTVisPlusNu","pTVisPlusNu",nBins,-0.5,599.5);
  TH1D *hst_pTHgen = new TH1D("hst_pTHgen","hst_pTHgen",nBins,-0.5,599.5);
  TH1D *hst_pTTrueGen = new TH1D("hst_pTTrueGen","hst_pTTrueGen",nBins,-0.5,599.5);
  TH1D *hst_pTTrueGenPlusNu = new TH1D("pTTrueGenPlusNu","pTTrueGenPlusNu",nBins,-0.5,599.5);
  TH1D *hst_MTrueGen = new TH1D("hst_MTrueGen","hst_MTrueGen",nBins,-0.5,299.5);
  TH1D *hst_pTGenQuarks = new TH1D("hst_pTGenQuarks","hst_pTGenQuarks",nBins,-0.5,599.5);
  TH1D *hst_MGenQuarks = new TH1D("hst_MGenQuarks","hst_MGenQuarks",nBins,-0.5,299.5);
  TH1D *hst_pTVis_jets_match = new TH1D("hst_pTVis_jets_match","hst_pTVis_jets_match",nBins,-0.5,599.5);

  TH1D *hst_closestJetInDelR_delR_ToQ1FromWFromH   = new TH1D("hst_closestJetInDelR_delR_Q1","hst_closestJetInDelR_delR_Q1",nBins,0,3);
  TH1D *hst_closestJetInDelR_ptres_ToQ1FromWFromH  = new TH1D("hst_closestJetInDelR_ptres_Q1","hst_closestJetInDelR_ptres_Q1",nBins,-2,3);
  TH1D *hst_closestJetInPTRes_delR_ToQ1FromWFromH  = new TH1D("hst_closestJetInPTRes_delR_Q1","hst_closestJetInPTRes_delR_Q1",nBins,0,3);
  TH1D *hst_closestJetInPTRes_ptres_ToQ1FromWFromH = new TH1D("hst_closestJetInPTRes_ptres_Q1","hst_closestJetInPTRes_ptres_Q1",nBins,-2,3);

  TH1D *hst_closestJetInDelR_delR_ToQ2FromWFromH   = new TH1D("hst_closestJetInDelR_delR_Q2","hst_closestJetInDelR_delR_Q2",nBins,0,3);
  TH1D *hst_closestJetInDelR_ptres_ToQ2FromWFromH  = new TH1D("hst_closestJetInDelR_ptres_Q2","hst_closestJetInDelR_ptres_Q2",nBins,-2,3);
  TH1D *hst_closestJetInPTRes_delR_ToQ2FromWFromH  = new TH1D("hst_closestJetInPTRes_delR_Q2","hst_closestJetInPTRes_delR_Q2",nBins,0,3);
  TH1D *hst_closestJetInPTRes_ptres_ToQ2FromWFromH = new TH1D("hst_closestJetInPTRes_ptres_Q2","hst_closestJetInPTRes_ptres_Q2",nBins,-2,3);

  TH1D *hst_matchRank = new TH1D("hst_matchRank","hst_matchRank",7,-0.5,6.5);
  TH1D *hst_bestRank = new TH1D("hst_bestRank","hst_bestRank",51,-0.5,50.5);
  TH1D *hst_Wmass = new TH1D("hst_Wmass","hst_Wmass",nBins,0,299.5);
  TH1D *hst_M_jets_match = new TH1D("hst_M_jets_match","hst_M_jets_match",nBins,0,130);
  TH1D *hst_M_jets_match_ifbest = new TH1D("hst_M_jets_match_ifbest","hst_M_jets_match_ifbest",nBins,0,130);
  TH1D *hst_mHRightLepton = new TH1D("hst_mHRightLepton","hst_mHRightLepton",nBins,0,400);
  TH1D *hst_mHWrongLepton = new TH1D("hst_mHWrongLepton","hst_mHWrongLepton",nBins,0,400);
  TH1D *hst_HadTopPt = new TH1D("hst_HadTopPt","hst_HadTopPt",nBins,0,500);
  TH1D *hst_HadTopM = new TH1D("hst_HadTopM","hst_HadTopM",nBins,130,220);
  TH1D *hst_WFromHadTopPt = new TH1D("hst_WFromHadTopPt","hst_WFromHadTopPt",nBins,0,500);
  TH1D *hst_WFromHadTopM = new TH1D("hst_WFromHadTopM","hst_WFromHadTopM",nBins,0,220);
  TH1D *hst_WFromHiggsPt = new TH1D("hst_WFromHiggsPt","hst_WFromHiggsPt",nBins,0,500);
  TH1D *hst_WFromHiggsM = new TH1D("hst_WFromHiggsM","hst_WFromHiggsM",nBins,0,220);
  TH1D *hst_PtTop_recohtt = new TH1D("hst_PtTop_recohtt","hst_PtTop_recohtt",nBins,0,500);
  TH1D *hst_MTop_recohtt = new TH1D("hst_MTop_recohtt","hst_MTop_recohtt",nBins,130,220);
  TH1D *hst_PtWFromTop_recohtt = new TH1D("hst_PtWFromTop_recohtt","hst_PtWFromTop_recohtt",nBins,0,500);
  TH1D *hst_MWFromTop_recohtt = new TH1D("hst_MWFromTop_recohtt","hst_MWFromTop_recohtt",nBins,0,220);

  TH2D *hst_WFromTop_2leps_delr = new TH2D("hst_WFromTop_2leps_delr","hst_WFromTop_2leps_delr",40,0,6,40,0,6);

  TH2D *hst_recogen_PtTop = new TH2D("hst_recogen_PtTop","hst_recogen_PtTop",10,0,500,10,0,500);

  TH1D *hst_nWFromH = new TH1D("hst_nWFromH","hst_nWFromH",6,-0.5,5.5);
  TH1D *hst_nQFromWFromH = new TH1D("hst_nQFromWFromH","hst_nQFromWFromH",6,-0.5,5.5);
  TH1D *hst_nNuFromWFromH = new TH1D("hst_nNuFromWFromH","hst_nNuFromWFromH",6,-0.5,5.5);
  TH1D *hst_nLFromWFromH = new TH1D("hst_nLFromWFromH","hst_nLFromWFromH",6,-0.5,5.5);
  TH1D *hst_nLFromWFromT = new TH1D("hst_nLFromWFromT","hst_nLFromWFromT",6,-0.5,5.5);
  TH1D *hst_nZFromH = new TH1D("hst_nZFromH","hst_nZFromH",6,-0.5,5.5);
  TH1D *hst_nQFromZFromH = new TH1D("hst_nQFromZFromH","hst_nQFromZFromH",6,-0.5,5.5);
  TH1D *hst_nNuFromZFromH = new TH1D("hst_nNuFromZFromH","hst_nNuFromZFromH",6,-0.5,5.5);
  TH1D *hst_nLFromZFromH = new TH1D("hst_nLFromZFromH","hst_nLFromZFromH",6,-0.5,5.5);
  TH1D *hst_nTauFromH = new TH1D("hst_nTauFromH","hst_nTauFromH",6,-0.5,5.5);
  TH1D *hst_nPiFromTauFromH = new TH1D("hst_nPiFromTauFromH","hst_nPiFromTauFromH",6,-0.5,5.5);
  TH1D *hst_nLFromTauFromH = new TH1D("hst_nLFromTauFromH","hst_nLFromTauFromH",6,-0.5,5.5);
  TH1D *hst_nNuFromTauFromH = new TH1D("hst_nNuFromTauFromH","hst_nNuFromTauFromH",6,-0.5,5.5);
  TH1D *hst_nTNuFromTauFromH = new TH1D("hst_nTNuFromTauFromH","hst_nTNuFromTauFromH",10,-0.5,9.5);
  TH1D *hst_nKaFromTauFromH = new TH1D("hst_nKaFromTauFromH","hst_nKaFromTauFromH",10,-0.5,9.5);
  TH1D *hst_nLFromTauFromWFromH = new TH1D("hst_nLFromTauFromWFromH","hst_nLFromTauFromWFromH",6,-0.5,5.5);
  TH1D *hst_nhFromTauFromWFromH = new TH1D("hst_nhFromTauFromWFromH","hst_nhFromTauFromWFromH",6,-0.5,5.5);
  TH1D *hst_nTauFromWFromH = new TH1D("hst_nTauFromWFromH","hst_nTauFromWFromH",6,-0.5,5.5);
  TH1D *hst_nFO = new TH1D("hst_nFO","hst_nFO",6,-0.5,5.5);
  TH1D *hst_nJetsInCollection = new TH1D("hst_nJetsInCollection","hst_nJetsInCollection",20,-0.5,19.5);
  
  TH1D *hst_qLargePtNJet0 = new TH1D("hst_qLargePtNJet0","hst_qLargePtNJet0",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet1 = new TH1D("hst_qLargePtNJet1","hst_qLargePtNJet1",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet2 = new TH1D("hst_qLargePtNJet2","hst_qLargePtNJet2",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet3 = new TH1D("hst_qLargePtNJet3","hst_qLargePtNJet3",nBins,-0.5,299.5);
  TH1D *hst_qSmallPtNJet0 = new TH1D("hst_qSmallPtNJet0","hst_qSmallPtNJet0",nBins,-0.5,299.5);
  TH1D *hst_qSmallPtNJet1 = new TH1D("hst_qSmallPtNJet1","hst_qSmallPtNJet1",nBins,-0.5,299.5);
  TH1D *hst_qSmallPtNJet2 = new TH1D("hst_qSmallPtNJet2","hst_qSmallPtNJet2",nBins,-0.5,299.5);
  TH1D *hst_qSmallPtNJet3 = new TH1D("hst_qSmallPtNJet3","hst_qSmallPtNJet3",nBins,-0.5,299.5);

  TH1D *hst_qLargePtNJet0F1 = new TH1D("hst_qLargePtNJet0F1","hst_qLargePtNJet0F1",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet0F2 = new TH1D("hst_qLargePtNJet0F2","hst_qLargePtNJet0F2",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet0F3 = new TH1D("hst_qLargePtNJet0F3","hst_qLargePtNJet0F3",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet0F4 = new TH1D("hst_qLargePtNJet0F4","hst_qLargePtNJet0F4",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet1F1 = new TH1D("hst_qLargePtNJet1F1","hst_qLargePtNJet1F1",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet1F2 = new TH1D("hst_qLargePtNJet1F2","hst_qLargePtNJet1F2",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet1F3 = new TH1D("hst_qLargePtNJet1F3","hst_qLargePtNJet1F3",nBins,-0.5,299.5);
  TH1D *hst_qLargePtNJet1F4 = new TH1D("hst_qLargePtNJet1F4","hst_qLargePtNJet1F4",nBins,-0.5,299.5);

  TH1D *hst_NSelectedMatchesVsNJet = new TH1D("hst_NSelectedMatchesVsNJet","hst_NSelectedMatchesVsNJet",20,-0.5,19.5);
  TH1D *hst_NSelectedMatchesVsNJetFrac = new TH1D("hst_NSelectedMatchesVsNJetFrac","hst_NSelectedMatchesVsNJetFrac",20,-0.5,19.5);

  TH2D *hst_flavourMatchEffQ1 = new TH2D("hst_flavourMatchEffQ1","hst_flavourMatchEffQ1",80,0.0125,2.0125,80,0.0125,2.0125); // FIXME
  TH2D *hst_flavourMatchEffQ2 = new TH2D("hst_flavourMatchEffQ2","hst_flavourMatchEffQ2",80,0.0125,2.0125,80,0.0125,2.0125); // FIXME

  TH1D *hst_Q1VsPt = new TH1D("hst_Q1VsPt","hst_Q1VsPt",nBins,-0.5,299.5);
  TH1D *hst_Q1MatchVsPt = new TH1D("hst_Q1MatchVsPt","hst_Q1MatchVsPt",nBins,-0.5,299.5);
  TH1D *hst_Q1EffVsPt = new TH1D("hst_Q1EffVsPt","hst_Q1EffVsPt",nBins,-0.5,299.5);
  TH1D *hst_Q2VsPt = new TH1D("hst_Q2VsPt","hst_Q2VsPt",nBins,-0.5,299.5);
  TH1D *hst_Q2MatchVsPt = new TH1D("hst_Q2MatchVsPt","hst_Q2MatchVsPt",nBins,-0.5,299.5);
  TH1D *hst_Q2EffVsPt = new TH1D("hst_Q2EffVsPt","hst_Q2EffVsPt",nBins,-0.5,299.5);

  TH1D *hst_Q1VsEta = new TH1D("hst_Q1VsEta","hst_Q1VsEta",nBins,-4.0,4.0);
  TH1D *hst_Q1MatchVsEta = new TH1D("hst_Q1MatchVsEta","hst_Q1MatchVsEta",nBins,-4.0,4.0);
  TH1D *hst_Q1EffVsEta = new TH1D("hst_Q1EffVsEta","hst_Q1EffVsEta",nBins,-4.0,4.0);
  TH1D *hst_Q2VsEta = new TH1D("hst_Q2VsEta","hst_Q2VsEta",nBins,-4.0,4.0);
  TH1D *hst_Q2MatchVsEta = new TH1D("hst_Q2MatchVsEta","hst_Q2MatchVsEta",nBins,-4.0,4.0);
  TH1D *hst_Q2EffVsEta = new TH1D("hst_Q2EffVsEta","hst_Q2EffVsEta",nBins,-4.0,4.0);

  TH2D *hst_closest2DPTResVsDr = new TH2D("hst_closest2DPTResVsDr","hst_closest2DPTResVsDr",nBins,-1,3,nBins,0,1.5);

  TH2D *hst_mjjVsdRjj = new TH2D("hst_mjjVsdRjj","hst_mjjVsdRjj",25,-0.5,139.5,25,0,8);
  TH2D *hst_mqqVsdRqq = new TH2D("hst_mqqVsdRqq","hst_mqqVsdRqq",25,-0.5,139.5,25,0,8);
  TH2D *hst_bestVsPTRes = new TH2D("hst_bestVsPTRes","hst_bestVsPTRes",51,-0.5,50.5,30,-1.1,4.1);

  TH1D *hst_matchComb = new TH1D("hst_matchComb","hst_matchComb",12,-0.5,11.5);
  TH1D *hst_delRlj2 = new TH1D("hst_delRlj2","hst_delRlj2",30,0,5);
  TH1D *hst_delRlj2_correct = new TH1D("hst_delRlj2_correct","hst_delRlj2_correct",30,0,5);
  TH1D *hst_delRlj2_diff = new TH1D("hst_delRlj2_diff","hst_delRlj2_diff",30,-5,5);
  TH1D *hst_delRj1j2 = new TH1D("hst_delRj1j2","hst_delRj1j2",30,0,5);
  TH1D *hst_delRj1j2_correct = new TH1D("hst_delRj1j2_correct","hst_delRj1j2_correct",30,0,5);
  TH1D *hst_delRj1j2_diff = new TH1D("hst_delRj1j2_diff","hst_delRj1j2_diff",30,-5,5);
  TH1D *hst_mj1j2 = new TH1D("hst_mj1j2","hst_mj1j2",nBins,0,200);
  TH1D *hst_mj1j2_correct = new TH1D("hst_mj1j2_correct","hst_mj1j2_correct",nBins,0,200);
  TH1D *hst_j2delIdx = new TH1D("hst_j2delIdx","hst_j2delIdx",11,-5.5,5.5);

  TH1D *hst_zWMass_correct = new TH1D("hst_zWMass_correct","hst_zWMass_correct",200,0,300);
  TH1D *hst_zHMass_correct = new TH1D("hst_zHMass_correct","hst_zHMass_correct",200,0,300);
  TH1D *hst_zmaxDR_correct = new TH1D("hst_zmaxDR_correct","hst_zmaxDR_correct",200,0,5);
  TH1D *hst_zminDR_correct = new TH1D("hst_zminDR_correct","hst_zminDR_correct",200,0,5);
  TH1D *hst_zmaxDRW_correct = new TH1D("hst_zmaxDRW_correct","hst_zmaxDRW_correct",200,0,5);
  TH1D *hst_zminDRW_correct = new TH1D("hst_zminDRW_correct","hst_zminDRW_correct",200,0,5);
  TH1D *hst_zDRj1j2_correct = new TH1D("hst_zDRj1j2_correct","hst_zDRj1j2_correct",200,0,5);

  TH1D *hst_lepIdx_correct = new TH1D("hst_lepIdx_correct","hst_lepIdx_correct",6,-0.5,5.5);

// *** Declare Counts ***
  const int nFMBins = 80;
  const int dRMax   = 2;
  const int dPtMax  = 2;
  int nEventsJetMatchesQ1             = 0;
  int nEventsJetMatchesQ2             = 0;
  int nEvents2UniqueMatchedJets       = 0;
  int nEventsJetMatchesQ1NoCond       = 0;
  int nEventsJetMatchesQ2NoCond       = 0;
  int nEvents2UniqueMatchedJetsNoCond = 0;
  int nEventsQ1MatchFlavour[nFMBins][nFMBins];
  int nEventsQ1Total[nFMBins][nFMBins];
  int nEventsQ2MatchFlavour[nFMBins][nFMBins];
  int nEventsQ2Total[nFMBins][nFMBins];
  for (int i=0; i<nFMBins; i++) {
    for (int j=0; j<nFMBins; j++) {
      nEventsQ1MatchFlavour[i][j] = 0;
      nEventsQ1Total[i][j] = 0;
      nEventsQ2MatchFlavour[i][j] = 0;;
      nEventsQ2Total[i][j] = 0;
    }
  }
  int j1closest = 0;
  int j2closest = 0;
  int closestjetiscorrect = 0;
  int closestlepiscorrect = 0;
  int oneoffour = 0;
  int twooffour = 0;
  int threeoffour = 0;
  int fouroffour = 0;
  int combocheck = 0;
  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    // Calculate Counts
    if (Hreco_nQFromWFromH != 2 || Hreco_nLFromWFromH != 1) continue;
    if (Hreco_nLFromWFromH == 1 && (0||Hreco_nLFromTauFromWFromH == 1)) oneoffour ++;
    if (Hreco_nLFromWFromH == 1 && (0||Hreco_nhFromTauFromWFromH >= 1)) twooffour ++;
    if (Hreco_nQFromWFromH == 2 && (0||Hreco_nLFromTauFromWFromH == 1)) threeoffour ++;
    if (Hreco_nQFromWFromH == 2 && (0||Hreco_nhFromTauFromWFromH >= 1)) fouroffour ++;
    if (Hreco_nQFromWFromH == 2 && Hreco_nLFromWFromH == 1 && Hreco_nLFromWFromT == 1) combocheck ++;
    bool Q1Match = Hreco_closestJetInDelR_delR_ToQ1FromWFromH != -99 && Hreco_closestJetInDelR_delR_ToQ1FromWFromH < 0.3 && abs(Hreco_closestJetInDelR_ptres_ToQ1FromWFromH) < 0.6;
    bool Q2Match = Hreco_closestJetInDelR_delR_ToQ2FromWFromH != -99 && Hreco_closestJetInDelR_delR_ToQ2FromWFromH < 0.3 && abs(Hreco_closestJetInDelR_ptres_ToQ2FromWFromH) < 0.6;
    bool uniqueJetMatch = Q1Match && Q2Match && Hreco_closestJetInDelR_pt_ToQ1FromWFromH != Hreco_closestJetInDelR_pt_ToQ2FromWFromH;
    if (Q1Match) nEventsJetMatchesQ1NoCond ++;
    if (Q2Match) nEventsJetMatchesQ2NoCond ++;
    if (uniqueJetMatch) nEvents2UniqueMatchedJetsNoCond ++;
    if (Q1Match && Hreco_pTHvis != -99) nEventsJetMatchesQ1 ++;
    if (Q2Match && Hreco_pTHvis != -99) nEventsJetMatchesQ2 ++;
    if (uniqueJetMatch && Hreco_pTHvis != -99) nEvents2UniqueMatchedJets ++;

    // Plot matching efficiency vs quark pt & eta
    if (Hreco_quark1pT != -99) hst_Q1VsPt->Fill(Hreco_quark1pT);
    if (Hreco_quark1pT != -99 && Q1Match) hst_Q1MatchVsPt->Fill(Hreco_quark1pT);
    if (Hreco_quark2pT != -99) hst_Q2VsPt->Fill(Hreco_quark2pT);
    if (Hreco_quark2pT != -99 && Q2Match) hst_Q2MatchVsPt->Fill(Hreco_quark2pT);
    if (Hreco_quark1Eta != -99) hst_Q1VsEta->Fill(Hreco_quark1Eta);
    if (Hreco_quark1Eta != -99 && Q1Match) hst_Q1MatchVsEta->Fill(Hreco_quark1Eta);
    if (Hreco_quark2Eta != -99) hst_Q2VsEta->Fill(Hreco_quark2Eta);
    if (Hreco_quark2Eta != -99 && Q2Match) hst_Q2MatchVsEta->Fill(Hreco_quark2Eta);

    if (Hreco_matchRank == 0) {
      hst_NSelectedMatchesVsNJet->Fill(Hreco_nJetsInCollection);
    }
    // Calculate flavour matching plot
    for (int i=0; i<nFMBins; i++) {
      for (int j=0; j<nFMBins; j++) {
        if ((Hreco_closestJetInDelR_delR_ToQ1FromWFromH < (float)(i+1)*((float)dRMax/(float)nFMBins)) && (abs(Hreco_closestJetInDelR_ptres_ToQ1FromWFromH) < (float)(j+1)*((float)dPtMax/(float)nFMBins))) {
          if (Hreco_closestJetInDelR_delR_ToQ1FromWFromH != -99 && abs(Hreco_closestJetInDelR_ptres_ToQ1FromWFromH) != -99) {
            nEventsQ1Total[i][j] ++;
            nEventsQ1MatchFlavour[i][j] += (Hreco_closestJetInDelR_flavour_ToQ1FromWFromH == Hreco_quark1Flavour);
          }
        }
        if ((Hreco_closestJetInDelR_delR_ToQ2FromWFromH < (float)(i+1)*((float)dRMax/(float)nFMBins)) && (abs(Hreco_closestJetInDelR_ptres_ToQ2FromWFromH) < (float)(j+1)*((float)dPtMax/(float)nFMBins))) {
          if (Hreco_closestJetInDelR_delR_ToQ2FromWFromH != -99 && abs(Hreco_closestJetInDelR_ptres_ToQ2FromWFromH) != -99) {
            nEventsQ2Total[i][j] ++;
            nEventsQ2MatchFlavour[i][j] += (Hreco_closestJetInDelR_flavour_ToQ2FromWFromH == Hreco_quark2Flavour);
          }
        }
      }
    }

    // Fill z histograms
    hst_zWMass_correct->Fill(Hreco_Wmass_correct);
    hst_zHMass_correct->Fill(Hreco_visHmass_correct);
    hst_zmaxDR_correct->Fill(Hreco_maxdR_correct);
    hst_zminDR_correct->Fill(Hreco_mindR_correct);
    hst_zmaxDRW_correct->Fill(Hreco_maxdRW_correct);
    hst_zminDRW_correct->Fill(Hreco_mindRW_correct);
    hst_zDRj1j2_correct->Fill(Hreco_delR_H_j1j2_correct);

    // Fill mHRight and mHWrong
    if (Hreco_mHRightLepton != -99) hst_mHRightLepton->Fill(Hreco_mHRightLepton);
    if (Hreco_mHWrongLepton != -99) hst_mHWrongLepton->Fill(Hreco_mHWrongLepton);

    // Fill Had Top histos
    if (Hreco_HadTopPt != -99 && Hreco_PtTop_recohtt != -99 && Hreco_WFromHadTopPt != -99 && Hreco_WFromHiggsPt != -99 && Hreco_PtWFromTop_recohtt != -99 && Hreco_nHadTop == 1) {
      hst_HadTopPt->Fill(Hreco_HadTopPt);
      hst_HadTopM->Fill(Hreco_HadTopM);
      hst_WFromHadTopPt->Fill(Hreco_WFromHadTopPt);
      hst_WFromHadTopM->Fill(Hreco_WFromHadTopM);
      hst_WFromHiggsPt->Fill(Hreco_WFromHiggsPt);
      hst_WFromHiggsM->Fill(Hreco_WFromHiggsM);
      hst_PtTop_recohtt->Fill(Hreco_PtTop_recohtt);
      hst_MTop_recohtt->Fill(Hreco_MTop_recohtt);
      hst_PtWFromTop_recohtt->Fill(Hreco_PtWFromTop_recohtt);
      hst_MWFromTop_recohtt->Fill(Hreco_MWFromTop_recohtt);
      hst_recogen_PtTop->Fill(Hreco_PtTop_recohtt,Hreco_HadTopPt);
    }

    if (Hreco_WFromTop_rightlep_delr != -99 and Hreco_WFromTop_wronglep_delr != -99) {
      hst_WFromTop_2leps_delr->Fill(Hreco_WFromTop_rightlep_delr, Hreco_WFromTop_wronglep_delr);
    }

    // Plot 2D m_jj distributions
    if (uniqueJetMatch) hst_mjjVsdRjj->Fill(Hreco_M_jets_match,Hreco_delR_H_j1j2);
    if (Hreco_dRGenQuarks != -99) hst_mqqVsdRqq->Fill(Hreco_MGenQuarks,Hreco_dRGenQuarks);

    // Fill matching combination histogram
    int matchCode = 0;
    if (Hreco_bestRank <= 5 && Hreco_bestRank >= 0) {
      if (Hreco_lepIdx == Hreco_lepIdx_correct) matchCode += 6;
      if (Hreco_j1Idx == Hreco_j1Idx_correct && Hreco_j2Idx == Hreco_j2Idx_correct) { matchCode += 5;
      } else if (Hreco_j1Idx == Hreco_j1Idx_correct) { matchCode += 4;
      } else if (Hreco_j2Idx == Hreco_j1Idx_correct) { matchCode += 3;
      } else if (Hreco_j2Idx == Hreco_j2Idx_correct) { matchCode += 2;
      } else if (Hreco_j1Idx == Hreco_j2Idx_correct) { matchCode += 1;
      }
      hst_matchComb->Fill(matchCode);
    }
    if (matchCode == 10) {
//    if (Hreco_j1Idx == Hreco_j1Idx_correct) {
      hst_delRlj2->Fill(Hreco_delR_H_j2l_reco);
      hst_delRlj2_correct->Fill(Hreco_delR_H_j2l_reco_correct);
      hst_delRlj2_diff->Fill(Hreco_delR_H_j2l_reco - Hreco_delR_H_j2l_reco_correct);
      hst_delRj1j2->Fill(Hreco_delR_H_j1j2);
      hst_delRj1j2_correct->Fill(Hreco_delR_H_j1j2_correct);
      hst_delRj1j2_diff->Fill(Hreco_delR_H_j1j2 - Hreco_delR_H_j1j2_correct);
      hst_mj1j2->Fill(Hreco_Wmass);
      hst_mj1j2_correct->Fill(Hreco_Wmass_correct);
      hst_j2delIdx->Fill(Hreco_j2Idx - Hreco_j2Idx_correct);
    }
    if (Hreco_delR_H_j1l_reco == Hreco_minDRlj && Hreco_minDRlj != -99) j1closest ++;
    if (Hreco_delR_H_j2l_reco == Hreco_minDRlj && Hreco_minDRlj != -99) j2closest ++;

    // Check how often closest jet to lepton is correct
    bool j1isclosest = (Hreco_delR_H_j1l_reco == Hreco_minDRlj && Hreco_minDRlj != -99);
    if (j1isclosest && (Hreco_j1Idx == Hreco_j1Idx_correct || Hreco_j1Idx == Hreco_j2Idx_correct)) closestjetiscorrect ++;
    if (!(j1isclosest) && (Hreco_j2Idx == Hreco_j1Idx_correct || Hreco_j2Idx == Hreco_j2Idx_correct)) closestjetiscorrect ++;
//    if (Hreco_lepIdx == Hreco_lepIdx_correct && Hreco_lepIdx != -99) closestlepiscorrect ++;
    if (Hreco_mindRW == 0) closestlepiscorrect ++;

    // Plot delR and PTRes distributions
    if (Hreco_closestJetInDelR_delR_ToQ1FromWFromH != -99) hst_closestJetInDelR_delR_ToQ1FromWFromH->Fill(Hreco_closestJetInDelR_delR_ToQ1FromWFromH);
    if (Hreco_closestJetInDelR_ptres_ToQ1FromWFromH != -99) hst_closestJetInDelR_ptres_ToQ1FromWFromH->Fill(Hreco_closestJetInDelR_ptres_ToQ1FromWFromH);
    if (Hreco_closestJetInPTRes_delR_ToQ1FromWFromH != -99) hst_closestJetInPTRes_delR_ToQ1FromWFromH->Fill(Hreco_closestJetInPTRes_delR_ToQ1FromWFromH);
    if (Hreco_closestJetInPTRes_ptres_ToQ1FromWFromH != -99) hst_closestJetInPTRes_ptres_ToQ1FromWFromH->Fill(Hreco_closestJetInPTRes_ptres_ToQ1FromWFromH);

    if (Hreco_closestJetInDelR_delR_ToQ2FromWFromH != -99) hst_closestJetInDelR_delR_ToQ2FromWFromH->Fill(Hreco_closestJetInDelR_delR_ToQ2FromWFromH);
    if (Hreco_closestJetInDelR_ptres_ToQ2FromWFromH != -99) hst_closestJetInDelR_ptres_ToQ2FromWFromH->Fill(Hreco_closestJetInDelR_ptres_ToQ2FromWFromH);
    if (Hreco_closestJetInPTRes_delR_ToQ2FromWFromH != -99) hst_closestJetInPTRes_delR_ToQ2FromWFromH->Fill(Hreco_closestJetInPTRes_delR_ToQ2FromWFromH);
    if (Hreco_closestJetInPTRes_ptres_ToQ2FromWFromH != -99) hst_closestJetInPTRes_ptres_ToQ2FromWFromH->Fill(Hreco_closestJetInPTRes_ptres_ToQ2FromWFromH);

    if (Hreco_closestJetInDelR_delR_ToQ1FromWFromH != -99) hst_closest2DPTResVsDr->Fill(Hreco_closestJetInDelR_ptres_ToQ1FromWFromH,Hreco_closestJetInDelR_delR_ToQ1FromWFromH);
    if (Hreco_closestJetInDelR_delR_ToQ2FromWFromH != -99) hst_closest2DPTResVsDr->Fill(Hreco_closestJetInDelR_ptres_ToQ2FromWFromH,Hreco_closestJetInDelR_delR_ToQ2FromWFromH);
    
    // Plot pT dists if entry != -99
    if (Hreco_pTHvis != -99) hst_pTHvis->Fill(Hreco_pTHvis);
    if (Hreco_pTVisPlusNu != -99) hst_pTVisPlusNu->Fill(Hreco_pTVisPlusNu);
    if (Hreco_pTHgen != -99) hst_pTHgen->Fill(Hreco_pTHgen);
    if (Hreco_pTTrueGen != -99) hst_pTTrueGen->Fill(Hreco_pTTrueGen);
    if (Hreco_pTTrueGenPlusNu != -99) hst_pTTrueGenPlusNu->Fill(Hreco_pTTrueGenPlusNu);
    if (Hreco_pTGenQuarks != -99) hst_pTGenQuarks->Fill(Hreco_pTGenQuarks);
    if (Hreco_pTVis_jets_match != -99) hst_pTVis_jets_match->Fill(Hreco_pTVis_jets_match);

    // Plot M dists if entry != -99
    if (Hreco_MTrueGen != -99) hst_MTrueGen->Fill(Hreco_MTrueGen);
    if (Hreco_MGenQuarks != -99) hst_MGenQuarks->Fill(Hreco_MGenQuarks);
    if (Hreco_Wmass != -99) hst_Wmass->Fill(Hreco_Wmass);
    if (Hreco_M_jets_match != -99) hst_M_jets_match->Fill(Hreco_M_jets_match);
    if (Hreco_M_jets_match != -99 && Hreco_pTHvis != -99) hst_M_jets_match_ifbest->Fill(Hreco_M_jets_match);

    // Plot match rank & best rank if entry != -99
    if (Hreco_matchRank != -99) hst_matchRank->Fill(Hreco_matchRank);
    if (Hreco_bestRank > hst_bestRank->GetNbinsX()-1) Hreco_bestRank = hst_bestRank->GetNbinsX()-1;
    if (Hreco_bestRank != -99) hst_bestRank->Fill(Hreco_bestRank);
    double tempptres = (Hreco_pTVisPlusNu-Hreco_pTHgen)/Hreco_pTHgen;
    if (tempptres > 4.09) tempptres = 4.09;
    if (Hreco_bestRank != -99) hst_bestVsPTRes->Fill(Hreco_bestRank,tempptres);

    // Plot number of gen objects
    hst_nWFromH->Fill(Hreco_nWFromH);
    hst_nQFromWFromH->Fill(Hreco_nQFromWFromH);
    hst_nNuFromWFromH->Fill(Hreco_nNuFromWFromH);
    hst_nLFromWFromH->Fill(Hreco_nLFromWFromH);
    hst_nLFromWFromT->Fill(Hreco_nLFromWFromT);
    hst_nZFromH->Fill(Hreco_nZFromH);
    hst_nQFromZFromH->Fill(Hreco_nQFromZFromH);
    hst_nNuFromZFromH->Fill(Hreco_nNuFromZFromH);
    hst_nLFromZFromH->Fill(Hreco_nLFromZFromH);
    hst_nTauFromH->Fill(Hreco_nTauFromH);
    hst_nPiFromTauFromH->Fill(Hreco_nPiFromTauFromH);
    hst_nLFromTauFromH->Fill(Hreco_nLFromTauFromH);
    hst_nNuFromTauFromH->Fill(Hreco_nNuFromTauFromH);
    hst_nTNuFromTauFromH->Fill(Hreco_nTNuFromTauFromH);
    hst_nKaFromTauFromH->Fill(Hreco_nKaFromTauFromH);
    hst_nLFromTauFromWFromH->Fill(Hreco_nLFromTauFromWFromH);
    hst_nhFromTauFromWFromH->Fill(Hreco_nhFromTauFromWFromH);
    hst_nTauFromWFromH->Fill(Hreco_nTauFromWFromH);
    hst_nFO->Fill(Hreco_nFO);
    if (Hreco_matchRank != -99) hst_nJetsInCollection->Fill(Hreco_nJetsInCollection);

    hst_lepIdx_correct->Fill(Hreco_lepIdx_correct);

    // Plot quark pT for events with varying nJets & flavour
    float qpt_large = Hreco_quark1pT > Hreco_quark2pT ? Hreco_quark1pT : Hreco_quark2pT;
    float qfl_large = Hreco_quark1pT > Hreco_quark2pT ? Hreco_quark1Flavour : Hreco_quark2Flavour;
    float qpt_small = Hreco_quark1pT > Hreco_quark2pT ? Hreco_quark2pT : Hreco_quark1pT;
    float qfl_small = Hreco_quark1pT > Hreco_quark2pT ? Hreco_quark2Flavour : Hreco_quark1Flavour;
    qfl_large = abs(qfl_large);
    qfl_small = abs(qfl_small);
    if (Hreco_nJetsInCollection == 0) {
      hst_qLargePtNJet0->Fill(qpt_large);
      hst_qSmallPtNJet0->Fill(qpt_small);
      if (qfl_large == 1) {
        hst_qLargePtNJet0F1->Fill(qpt_large);
      } else if (qfl_large == 2) {
        hst_qLargePtNJet0F2->Fill(qpt_large);
      } else if (qfl_large == 3) {
        hst_qLargePtNJet0F3->Fill(qpt_large);
      } else if (qfl_large == 4) {
        hst_qLargePtNJet0F4->Fill(qpt_large);
      }
    } else if (Hreco_nJetsInCollection == 1) {
      hst_qLargePtNJet1->Fill(qpt_large);
      hst_qSmallPtNJet1->Fill(qpt_small);
        if (qfl_large == 1) {
        hst_qLargePtNJet1F1->Fill(qpt_large);
      } else if (qfl_large == 2) {
        hst_qLargePtNJet1F2->Fill(qpt_large);
      } else if (qfl_large == 3) {
        hst_qLargePtNJet1F3->Fill(qpt_large);
      } else if (qfl_large == 4) {
        hst_qLargePtNJet1F4->Fill(qpt_large);
      }
    } else if (Hreco_nJetsInCollection == 2) {
      hst_qLargePtNJet2->Fill(qpt_large);
      hst_qSmallPtNJet2->Fill(qpt_small);
    } else if (Hreco_nJetsInCollection >= 3) {
      hst_qLargePtNJet3->Fill(qpt_large);
      hst_qSmallPtNJet3->Fill(qpt_small);
    }
  }

  // Compute correlations
  // xx: pTHVisReco
  // yy: pTHVisGen
  // zz: pTHFullGen
  double NN;
  double xx;
  double yy;
  double zz;
  double xxxx;
  double xxyy;
  double xxzz;
  double yyyy;
  double yyzz;
  double zzzz;
  NN = 0;
  xx = 0;
  yy = 0;
  xxxx = 0;
  xxyy = 0;
  yyyy = 0;
  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    if (Hreco_nQFromWFromH != 2 || Hreco_nLFromWFromH != 1) continue;
    if (Hreco_pTHvis == -99 || Hreco_pTTrueGen == -99) continue;
    NN ++;
    xx += Hreco_pTHvis;
    yy += Hreco_pTTrueGen;
    xxxx += Hreco_pTHvis*Hreco_pTHvis;
    xxyy += Hreco_pTHvis*Hreco_pTTrueGen;
    yyyy += Hreco_pTTrueGen*Hreco_pTTrueGen;
  }
  double recogencorr = (NN*xxyy - xx*yy)/sqrt((NN*xxxx-xx*xx)*(NN*yyyy-yy*yy));
  NN = 0;
  yy = 0;
  zz = 0;
  yyyy = 0;
  yyzz = 0;
  zzzz = 0;
  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    if (Hreco_nQFromWFromH != 2 || Hreco_nLFromWFromH != 1) continue;
    if (Hreco_pTTrueGen == -99 || Hreco_pTHgen == -99) continue;
    NN ++;
    yy += Hreco_pTTrueGen;
    zz += Hreco_pTHgen;
    yyyy += Hreco_pTTrueGen*Hreco_pTTrueGen;
    yyzz += Hreco_pTTrueGen*Hreco_pTHgen;
    zzzz += Hreco_pTHgen*Hreco_pTHgen;
  }
  double visfullcorr = (NN*yyzz - yy*zz)/sqrt((NN*yyyy-yy*yy)*(NN*zzzz-zz*zz));
  NN = 0;
  xx = 0;
  zz = 0;
  xxxx = 0;
  xxzz = 0;
  zzzz = 0;
  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    if (Hreco_nQFromWFromH != 2 || Hreco_nLFromWFromH != 1) continue;
    if (Hreco_pTHvis == -99 || Hreco_pTHgen == -99) continue;
    NN ++;
    xx += Hreco_pTHvis;
    zz += Hreco_pTHgen;
    xxxx += Hreco_pTHvis*Hreco_pTHvis;
    xxzz += Hreco_pTHvis*Hreco_pTHgen;
    zzzz += Hreco_pTHgen*Hreco_pTHgen;
  }
  double totalcorr   = (NN*xxzz - xx*zz)/sqrt((NN*xxxx-xx*xx)*(NN*zzzz-zz*zz));
  NN = 0;
  xx = 0;
  zz = 0;
  xxxx = 0;
  xxzz = 0;
  zzzz = 0;
  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    if (Hreco_pTHvis == -99 || Hreco_pTHgen == -99) continue;
    NN ++;
    xx += Hreco_pTHvis;
    zz += Hreco_pTHgen;
    xxxx += Hreco_pTHvis*Hreco_pTHvis;
    xxzz += Hreco_pTHvis*Hreco_pTHgen;
    zzzz += Hreco_pTHgen*Hreco_pTHgen;
  }
  double totalcorrnocuts   = (NN*xxzz - xx*zz)/sqrt((NN*xxxx-xx*xx)*(NN*zzzz-zz*zz));

  NN = 0;
  xx = 0;
  zz = 0;
  xxxx = 0;
  xxzz = 0;
  zzzz = 0;
  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    if (Hreco_PtTop_recohtt == -99 || Hreco_HadTopPt == -99) continue;
    NN ++;
    xx += Hreco_PtTop_recohtt;
    zz += Hreco_HadTopPt;
    xxxx += Hreco_PtTop_recohtt*Hreco_PtTop_recohtt;
    xxzz += Hreco_PtTop_recohtt*Hreco_HadTopPt;
    zzzz += Hreco_HadTopPt*Hreco_HadTopPt;
  }
  double TopPtCorr   = (NN*xxzz - xx*zz)/sqrt((NN*xxxx-xx*xx)*(NN*zzzz-zz*zz));

  // Populate 2D flavour matching histograms
  for (int i=0; i<nFMBins; i++) {
    for (int j=0; j<nFMBins; j++) {
      float Q1frac = (float) nEventsQ1MatchFlavour[i][j] / (float) nEventsQ1Total[i][j];
      hst_flavourMatchEffQ1->Fill((float)(i+1)*((float)dRMax/(float)nFMBins),(float)(j+1)*((float)dPtMax/(float)nFMBins),Q1frac);
      float Q2frac = (float) nEventsQ2MatchFlavour[i][j] / (float) nEventsQ2Total[i][j];
      hst_flavourMatchEffQ2->Fill((float)(i+1)*((float)dRMax/(float)nFMBins),(float)(j+1)*((float)dPtMax/(float)nFMBins),Q2frac);
    }
  }

  // Populate NSelectedMatchesVsNJetFrac histogram
  for (int i=1; i<= hst_NSelectedMatchesVsNJetFrac->GetNbinsX(); i++) {
    float Num = hst_NSelectedMatchesVsNJet->GetBinContent(i);
    float Den = hst_nJetsInCollection->GetBinContent(i);
    float sf = 1; //(i-1)*(i-2)/2.0;
    if (Den == 0) {
      hst_NSelectedMatchesVsNJetFrac->SetBinContent(i,0);
    } else {
      hst_NSelectedMatchesVsNJetFrac->SetBinContent(i,sf*Num/Den);
      hst_NSelectedMatchesVsNJetFrac->SetBinError(i,sf*sqrt(Num)/Den);
    }
  }

  // Calculate efficiency plots for pt and eta
  double A1, B1, A2, B2;
  for (int i=1; i<=nBins; i++) {
    A1 = (double)hst_Q1MatchVsPt->GetBinContent(i);
    B1 = (double)hst_Q1VsPt->GetBinContent(i);
    A2 = (double)hst_Q2MatchVsPt->GetBinContent(i);
    B2 = (double)hst_Q2VsPt->GetBinContent(i);
    hst_Q1EffVsPt->SetBinContent(i,A1/B1);
    hst_Q2EffVsPt->SetBinContent(i,A2/B2);
    hst_Q1EffVsPt->SetBinError(i,(A1*sqrt(B1)+B1*sqrt(A1))/(B1*B1));
    hst_Q2EffVsPt->SetBinError(i,(A2*sqrt(B2)+B2*sqrt(A2))/(B2*B2));
    if (hst_Q1VsPt->GetBinContent(i) == 0) { hst_Q1EffVsPt->SetBinContent(i,0); hst_Q1EffVsPt->SetBinError(i,0); };
    if (hst_Q2VsPt->GetBinContent(i) == 0) { hst_Q2EffVsPt->SetBinContent(i,0); hst_Q2EffVsPt->SetBinError(i,0); };
    A1 = (double)hst_Q1MatchVsEta->GetBinContent(i);
    B1 = (double)hst_Q1VsEta->GetBinContent(i);
    A2 = (double)hst_Q2MatchVsEta->GetBinContent(i);
    B2 = (double)hst_Q2VsEta->GetBinContent(i);
    hst_Q1EffVsEta->SetBinContent(i,A1/B1);
    hst_Q2EffVsEta->SetBinContent(i,A2/B2);
    hst_Q1EffVsEta->SetBinError(i,(A1*sqrt(B1)+B1*sqrt(A1))/(B1*B1));
    hst_Q2EffVsEta->SetBinError(i,(A2*sqrt(B2)+B2*sqrt(A2))/(B2*B2));
    if (hst_Q1VsEta->GetBinContent(i) == 0) { hst_Q1EffVsEta->SetBinContent(i,0); hst_Q1EffVsEta->SetBinError(i,0); };
    if (hst_Q2VsEta->GetBinContent(i) == 0) { hst_Q2EffVsEta->SetBinContent(i,0); hst_Q2EffVsEta->SetBinError(i,0); };
  }
  hst_Q1EffVsPt->Rebin(4);
  hst_Q1EffVsPt->Scale(1.0/4.0);
  hst_Q2EffVsPt->Rebin(4);
  hst_Q2EffVsPt->Scale(1.0/4.0);
  hst_Q1EffVsEta->Rebin(4);
  hst_Q1EffVsEta->Scale(1.0/4.0);
  hst_Q2EffVsEta->Rebin(4);
  hst_Q2EffVsEta->Scale(1.0/4.0);

  // Normalize 2D best distribution
  TH2D *hst_bestVsPTResNormed = (TH2D *) hst_bestVsPTRes->Clone();
  for (int i=1; i<=51; i++) {
    for (int j=1; j<=nBins; j++) {
        int bin = hst_bestVsPTResNormed->GetBin(i,j);
      hst_bestVsPTResNormed->SetBinContent(bin,hst_bestVsPTResNormed->GetBinContent(bin)/hst_bestRank->GetBinContent(i));
    }
  }

  // Scale all distributions
  hst_pTHvis->Scale(1/hst_pTHvis->GetEntries());
  hst_pTVisPlusNu->Scale(1/hst_pTVisPlusNu->GetEntries());
  hst_pTHgen->Scale(1/hst_pTHgen->GetEntries());
  hst_pTTrueGen->Scale(1/hst_pTTrueGen->GetEntries());
  hst_pTTrueGenPlusNu->Scale(1/hst_pTTrueGenPlusNu->GetEntries());
  hst_pTGenQuarks->Scale(1/hst_pTGenQuarks->GetEntries());
  hst_pTVis_jets_match->Scale(1/hst_pTVis_jets_match->GetEntries());

  hst_qLargePtNJet0->Scale(1/hst_qLargePtNJet0->GetEntries());
  hst_qLargePtNJet1->Scale(1/hst_qLargePtNJet1->GetEntries());
  hst_qLargePtNJet2->Scale(1/hst_qLargePtNJet2->GetEntries());
  hst_qLargePtNJet3->Scale(1/hst_qLargePtNJet3->GetEntries());
  hst_qSmallPtNJet0->Scale(1/hst_qSmallPtNJet0->GetEntries());
  hst_qSmallPtNJet1->Scale(1/hst_qSmallPtNJet1->GetEntries());
  hst_qSmallPtNJet2->Scale(1/hst_qSmallPtNJet2->GetEntries());
  hst_qSmallPtNJet3->Scale(1/hst_qSmallPtNJet3->GetEntries());

  hst_qLargePtNJet0F1->Scale(1/hst_qLargePtNJet0F1->GetEntries());
  hst_qLargePtNJet0F2->Scale(1/hst_qLargePtNJet0F2->GetEntries());
  hst_qLargePtNJet0F3->Scale(1/hst_qLargePtNJet0F3->GetEntries());
  hst_qLargePtNJet0F4->Scale(1/hst_qLargePtNJet0F4->GetEntries());
  hst_qLargePtNJet1F1->Scale(1/hst_qLargePtNJet1F1->GetEntries());
  hst_qLargePtNJet1F2->Scale(1/hst_qLargePtNJet1F2->GetEntries());
  hst_qLargePtNJet1F3->Scale(1/hst_qLargePtNJet1F3->GetEntries());
  hst_qLargePtNJet1F4->Scale(1/hst_qLargePtNJet1F4->GetEntries());

  // *** Print Counts ***
  cout << endl << "*** Print Counts For Chart***" << endl;
  cout << "No cuts:                                                 " << hst_nQFromWFromH->GetBinContent(3) << endl;
  cout << "Has a NuFromWFromH:                                      " << hst_nNuFromWFromH->GetEntries() - hst_nNuFromWFromH->GetBinContent(1) << endl;
  cout << "Has a jet that matches quark 1:                          " << nEventsJetMatchesQ1NoCond << endl;
  cout << "Has a jet that matches quark 2:                          " << nEventsJetMatchesQ2NoCond << endl;
  cout << "Has two jets, one of each matches quark 1 & 2:           " << nEvents2UniqueMatchedJetsNoCond << endl;
  cout << "Passes default reconstruction algorithm (*):             " << hst_pTHvis->GetEntries() << endl;
  cout << "(*) + Has a NuFromWFromH:                                " << hst_pTVisPlusNu->GetEntries() << endl;
  cout << "(*) + Has a jet that matches quark 1:                    " << nEventsJetMatchesQ1 << endl;
  cout << "(*) + Has a jet that matches quark 2:                    " << nEventsJetMatchesQ2 << endl;
  cout << "(*) + Has two jets, one of each matches quark 1 & 2:     " << nEvents2UniqueMatchedJets << endl;
  cout << "(*) + Has two jets, one of each matches quark 1 & 2 and" << endl;
  cout << "the jet pair passes the reco algo as a candidate:        " << hst_matchRank->GetEntries() << endl;
  cout << "(*) + Has two jets, one of each matches quark 1 & 2 and" << endl;
  cout << "both jets are correctly selected by the algo:            " << hst_matchRank->GetBinContent(1) << endl;
  cout << endl << "*** Correlations ***" << endl;
  cout << "recogencorr:     " << recogencorr << endl;
  cout << "visfullcorr:     " << visfullcorr << endl;
  cout << "totalcorr:       " << totalcorr << endl;
  cout << "totalcorrnocuts: " << totalcorrnocuts << endl;
  cout << "TopPtCorr:       " << TopPtCorr << endl;
  cout << "\n\n";

  cout << "j1closest: " << j1closest << endl;
  cout << "j2closest: " << j2closest << endl;
  cout << "closestjetiscorrect: " << closestjetiscorrect << endl;
  cout << "closestlepiscorrect: " << closestlepiscorrect << endl;
  cout << "\n\n";

  cout << "oneoffour:   " << oneoffour << endl;
  cout << "twooffour:   " << twooffour << endl;
  cout << "threeoffour: " << threeoffour << endl;
  cout << "fouroffour:  " << fouroffour << endl;
  cout << "combocheck:  " << combocheck << endl;

  gSystem->Exec("mkdir 1DDistPlots");
  TString VetoString = TVet+BVet+"Veto";

  TCanvas *can1 = new TCanvas();
  hst_matchRank->GetXaxis()->SetTitle("Entry in Candidate List");
  hst_matchRank->GetYaxis()->SetTitle("N Event");
  hst_matchRank->SetTitle("Rank of candidates for reconstructible events");
  hst_matchRank->Draw();
  TLatex tex1(.4,.85,VetoString);
  tex1.SetTextSize(0.03);
  tex1.SetNDC(kTRUE);
  tex1.Draw();
  can1->SaveAs("1DDistPlots/plot_MatchRank.png");  

  TCanvas *can2 = new TCanvas();
  hst_pTHvis->SetLineColor(kBlue);
  hst_pTHgen->SetLineColor(kRed);
  hst_pTVisPlusNu->SetLineColor(kGreen);
  hst_pTTrueGen->SetLineColor(kMagenta);
  hst_pTTrueGenPlusNu->SetLineColor(kBlack);
  hst_pTVis_jets_match->SetLineColor(kCyan);
  hst_pTHvis->GetXaxis()->SetTitle("pT");
  hst_pTHvis->GetYaxis()->SetTitle("a.u.");
  hst_pTHvis->GetXaxis()->CenterTitle();
  hst_pTHvis->GetYaxis()->CenterTitle();
  hst_pTHvis->GetXaxis()->SetTitleOffset(Offset);
  hst_pTHvis->GetYaxis()->SetTitleOffset(Offset);
  hst_pTHvis->GetYaxis()->SetRangeUser(0,0.07);
  hst_pTHvis->SetTitle("PT Dists");
  hst_pTHvis->Draw("HIST");
  hst_pTHgen->Draw("HIST SAME");
  hst_pTVisPlusNu->Draw("HIST SAME");
  hst_pTTrueGen->Draw("HIST SAME");
  hst_pTTrueGenPlusNu->Draw("HIST SAME");
//  hst_pTVis_jets_match->Draw("HIST SAME");
  TLatex tex2(.4,.85,VetoString);
  tex2.SetTextSize(0.03);
  tex2.SetNDC(kTRUE);
  tex2.Draw();

  TLegend *leg2 = new TLegend(0.65,0.65,0.85,0.85);
  leg2->AddEntry(hst_pTHvis,"Reco");
  leg2->AddEntry(hst_pTHgen,"Gen");
  leg2->AddEntry(hst_pTVisPlusNu,"RecoPlusNu");
  leg2->AddEntry(hst_pTTrueGen,"Gen(q1) + Gen(q2) + Gen(l)");
  leg2->AddEntry(hst_pTTrueGenPlusNu,"Gen(q1) + Gen(q2) + Gen(l) + Gen(nu)");
//  leg2->AddEntry(hst_pTVis_jets_match,"Reco with Matched Jets");
  leg2->Draw();
  can2->SaveAs("1DDistPlots/plot_PTDists.png");

  TCanvas *can3 = new TCanvas();
  hst_Wmass->GetXaxis()->SetTitle("W pT");
  hst_Wmass->GetYaxis()->SetTitle("a.u.");
  hst_Wmass->GetXaxis()->CenterTitle();
  hst_Wmass->GetYaxis()->CenterTitle();
  hst_Wmass->GetXaxis()->SetTitleOffset(Offset);
  hst_Wmass->GetYaxis()->SetTitleOffset(Offset);
  hst_Wmass->SetTitle("Mass Selected Jet Pair");
  hst_Wmass->Draw();
  TLatex tex3(.4,.85,VetoString);
  tex3.SetTextSize(0.03);
  tex3.SetNDC(kTRUE);
  tex3.Draw();
  can3->SaveAs("1DDistPlots/plot_WMass.png");

  TCanvas *can4 = new TCanvas();
  hst_closestJetInDelR_delR_ToQ1FromWFromH->GetXaxis()->SetTitle("Minimum #DeltaR");
  hst_closestJetInDelR_delR_ToQ1FromWFromH->GetYaxis()->SetTitle("N Events");
  hst_closestJetInDelR_delR_ToQ1FromWFromH->SetTitle("Quark 1 #DeltaR");
  hst_closestJetInDelR_delR_ToQ1FromWFromH->SetLineColor(kRed);
  hst_closestJetInPTRes_delR_ToQ1FromWFromH->SetLineColor(kBlue);
  hst_closestJetInDelR_delR_ToQ1FromWFromH->Draw();
  hst_closestJetInPTRes_delR_ToQ1FromWFromH->Draw("SAME");
  TLatex tex4(.4,.85,VetoString);
  tex4.SetTextSize(0.03);
  tex4.SetNDC(kTRUE);
  tex4.Draw();

  TLegend *leg4 = new TLegend(0.65,0.65,0.85,0.85);
  leg4->AddEntry(hst_closestJetInPTRes_delR_ToQ1FromWFromH,"Min pT_res");
  leg4->AddEntry(hst_closestJetInDelR_delR_ToQ1FromWFromH,"Min #DeltaR");
  leg4->Draw();
  can4->SaveAs("1DDistPlots/plot_Q1dR.png");

  TCanvas *can5 = new TCanvas();
  hst_closestJetInPTRes_ptres_ToQ1FromWFromH->GetXaxis()->SetTitle("Minimum pT_res");
  hst_closestJetInPTRes_ptres_ToQ1FromWFromH->GetYaxis()->SetTitle("N Events");
  hst_closestJetInPTRes_ptres_ToQ1FromWFromH->SetTitle("Quark 1 pT_res");
  hst_closestJetInPTRes_ptres_ToQ1FromWFromH->SetLineColor(kBlue);
  hst_closestJetInDelR_ptres_ToQ1FromWFromH->SetLineColor(kRed);
  hst_closestJetInPTRes_ptres_ToQ1FromWFromH->Draw();
  hst_closestJetInDelR_ptres_ToQ1FromWFromH->Draw("SAME");
  TLatex tex5(.4,.85,VetoString);
  tex5.SetTextSize(0.03);
  tex5.SetNDC(kTRUE);
  tex5.Draw();
  
  TLegend *leg5 = new TLegend(0.65,0.65,0.85,0.85);
  leg5->AddEntry(hst_closestJetInPTRes_ptres_ToQ1FromWFromH,"Min pT_res");
  leg5->AddEntry(hst_closestJetInDelR_ptres_ToQ1FromWFromH,"Min #DeltaR");
  leg5->Draw();
  can5->SaveAs("1DDistPlots/plot_Q1DPtOPt.png");

  TCanvas *can4_4 = new TCanvas();
  hst_closestJetInDelR_delR_ToQ2FromWFromH->GetXaxis()->SetTitle("Minimum #DeltaR");
  hst_closestJetInDelR_delR_ToQ2FromWFromH->GetYaxis()->SetTitle("N Events");
  hst_closestJetInDelR_delR_ToQ2FromWFromH->SetTitle("Quark 2 #DeltaR");
  hst_closestJetInDelR_delR_ToQ2FromWFromH->SetLineColor(kRed);
  hst_closestJetInDelR_delR_ToQ2FromWFromH->Draw();
  hst_closestJetInPTRes_delR_ToQ2FromWFromH->Draw("SAME");
  TLatex tex4_4(.4,.85,VetoString);
  tex4_4.SetTextSize(0.03);
  tex4_4.SetNDC(kTRUE);
  tex4_4.Draw();

  TLegend *leg4_4 = new TLegend(0.65,0.65,0.85,0.85);
  leg4_4->AddEntry(hst_closestJetInPTRes_delR_ToQ2FromWFromH,"Min pT_res");
  leg4_4->AddEntry(hst_closestJetInDelR_delR_ToQ2FromWFromH,"Min #DeltaR");
  leg4_4->Draw();
  can4_4->SaveAs("1DDistPlots/plot_Q2dR.png");

  TCanvas *can5_5 = new TCanvas();
  hst_closestJetInPTRes_ptres_ToQ2FromWFromH->GetXaxis()->SetTitle("Minimum pT_res");
  hst_closestJetInPTRes_ptres_ToQ2FromWFromH->GetYaxis()->SetTitle("N Events");
  hst_closestJetInPTRes_ptres_ToQ2FromWFromH->SetTitle("Quark 2 pT_res");
  hst_closestJetInPTRes_ptres_ToQ2FromWFromH->SetLineColor(kRed);
  hst_closestJetInPTRes_ptres_ToQ2FromWFromH->Draw();
  hst_closestJetInDelR_ptres_ToQ2FromWFromH->Draw("SAME");
  TLatex tex5_5(.4,.85,VetoString);
  tex5_5.SetTextSize(0.03);
  tex5_5.SetNDC(kTRUE);
  tex5_5.Draw();

  TLegend *leg5_5 = new TLegend(0.65,0.65,0.85,0.85);
  leg5_5->AddEntry(hst_closestJetInPTRes_ptres_ToQ2FromWFromH,"Min pT_res");
  leg5_5->AddEntry(hst_closestJetInDelR_ptres_ToQ2FromWFromH,"Min #DeltaR");
  leg5_5->Draw();
  can5_5->SaveAs("1DDistPlots/plot_Q2DPtOPt.png");

  TCanvas *can6 = new TCanvas();
  hst_nQFromWFromH->GetXaxis()->SetTitle("nQFromWFromH");
  hst_nQFromWFromH->GetYaxis()->SetTitle("nEvents");
  hst_nQFromWFromH->SetTitle("Num Q from W from H");
  hst_nQFromWFromH->Draw();
  TLatex tex6(.4,.85,VetoString);
  tex6.SetTextSize(0.03);
  tex6.SetNDC(kTRUE);
  tex6.Draw();
  can6->SaveAs("1DDistPlots/plot_nEventWithQFromWFromH.png");

  TCanvas *can7 = new TCanvas();
  hst_nJetsInCollection->GetXaxis()->SetTitle("N Jets");
  hst_nJetsInCollection->GetYaxis()->SetTitle("N Events");
  hst_nJetsInCollection->SetTitle("N Jets that pass vetos (No T + Medium B)");
  hst_nJetsInCollection->Draw("HIST");
  TLatex tex7(.4,.85,VetoString);
  tex7.SetTextSize(0.03);
  tex7.SetNDC(kTRUE);
  tex7.Draw();
  can7->SaveAs("1DDistPlots/plot_nJetsNoTopNoB.png");

  TCanvas *can8 = new TCanvas();
  hst_qLargePtNJet0->SetLineColor(kBlack);
  hst_qLargePtNJet1->SetLineColor(kBlue);
  hst_qLargePtNJet2->SetLineColor(kGreen);
  hst_qLargePtNJet3->SetLineColor(kRed);
  hst_qLargePtNJet0->GetXaxis()->SetTitle("Leading Quark Pt");
  hst_qLargePtNJet0->GetYaxis()->SetTitle("Event Fraction");
  hst_qLargePtNJet0->SetTitle("Leading Quark Pt (T + Loose B Veto)");
  hst_qLargePtNJet0->Draw("HIST");
  hst_qLargePtNJet1->Draw("HIST SAME");
  hst_qLargePtNJet2->Draw("HIST SAME");
  hst_qLargePtNJet3->Draw("HIST SAME");
  TLatex tex8(.4,.85,VetoString);
  tex8.SetTextSize(0.03);
  tex8.SetNDC(kTRUE);
  tex8.Draw();

  TLegend *leg8 = new TLegend(0.65,0.65,0.85,0.85);
  leg8->AddEntry(hst_qLargePtNJet0,"0 Jets");
  leg8->AddEntry(hst_qLargePtNJet1,"1 Jets");
  leg8->AddEntry(hst_qLargePtNJet2,"2 Jets");
  leg8->AddEntry(hst_qLargePtNJet3,">=3 Jets");
  leg8->Draw();
  can8->SaveAs("1DDistPlots/plot_LeadingQuarkPtvsNJet.png");

  TCanvas *can9 = new TCanvas();
  hst_qSmallPtNJet0->SetLineColor(kBlack);
  hst_qSmallPtNJet1->SetLineColor(kBlue);
  hst_qSmallPtNJet2->SetLineColor(kGreen);
  hst_qSmallPtNJet3->SetLineColor(kRed);
  hst_qSmallPtNJet0->GetXaxis()->SetTitle("Subleading Quark Pt");
  hst_qSmallPtNJet0->GetYaxis()->SetTitle("Event Fraction");
  hst_qSmallPtNJet0->SetTitle("Subleading Quark Pt (T + Loose B Veto)");
  hst_qSmallPtNJet0->Draw("HIST");
  hst_qSmallPtNJet1->Draw("HIST SAME");
  hst_qSmallPtNJet2->Draw("HIST SAME");
  hst_qSmallPtNJet3->Draw("HIST SAME");
  TLatex tex9(.4,.85,VetoString);
  tex9.SetTextSize(0.03);
  tex9.SetNDC(kTRUE);
  tex9.Draw();

  TLegend *leg9 = new TLegend(0.65,0.65,0.85,0.85);
  leg9->AddEntry(hst_qSmallPtNJet0,"0 Jets");
  leg9->AddEntry(hst_qSmallPtNJet1,"1 Jets");
  leg9->AddEntry(hst_qSmallPtNJet2,"2 Jets");
  leg9->AddEntry(hst_qSmallPtNJet3,">=3 Jets");
  leg9->Draw();
  can9->SaveAs("1DDistPlots/plot_SubLeadingQuarkPtvsNJet.png");

  TCanvas *can10 = new TCanvas();
  hst_NSelectedMatchesVsNJet->GetXaxis()->SetTitle("N Jets");
  hst_NSelectedMatchesVsNJet->GetYaxis()->SetTitle("N Events");
  hst_NSelectedMatchesVsNJet->SetTitle("N Events where algo chooses closest matched jets");
  hst_NSelectedMatchesVsNJet->Draw();
  TLatex tex10(.4,.85,VetoString);
  tex10.SetTextSize(0.03);
  tex10.SetNDC(kTRUE);
  tex10.Draw();
  can10->SaveAs("1DDistPlots/plot_NSelectedMatchesVsNJet.png");

  TCanvas *can12 = new TCanvas();
  hst_qLargePtNJet0F1->SetLineColor(kBlack);
  hst_qLargePtNJet0F2->SetLineColor(kBlue);
  hst_qLargePtNJet0F3->SetLineColor(kGreen);
  hst_qLargePtNJet0F4->SetLineColor(kRed);
  hst_qLargePtNJet0F1->GetXaxis()->SetTitle("Leading Quark Pt");
  hst_qLargePtNJet0F1->GetYaxis()->SetTitle("Event Fraction");
  hst_qLargePtNJet0F1->SetTitle("Events with 0 Jets");
  hst_qLargePtNJet0F1->GetYaxis()->SetRangeUser(0,0.1);
  hst_qLargePtNJet0F1->Draw("HIST");
  hst_qLargePtNJet0F2->Draw("HIST SAME");
  hst_qLargePtNJet0F3->Draw("HIST SAME");
  hst_qLargePtNJet0F4->Draw("HIST SAME");
  TLatex tex12(.4,.85,VetoString);
  tex12.SetTextSize(0.03);
  tex12.SetNDC(kTRUE);
  tex12.Draw();

  TLegend *leg12 = new TLegend(0.65,0.65,0.85,0.85);
  leg12->AddEntry(hst_qLargePtNJet0F1,"d");
  leg12->AddEntry(hst_qLargePtNJet0F2,"u");
  leg12->AddEntry(hst_qLargePtNJet0F3,"s");
  leg12->AddEntry(hst_qLargePtNJet0F4,"c");
  leg12->Draw();
  can12->SaveAs("1DDistPlots/plot_LeadingQuarkPt0JetByFlavour.png");

  TCanvas *can13 = new TCanvas();
  hst_qLargePtNJet1F1->SetLineColor(kBlack);
  hst_qLargePtNJet1F2->SetLineColor(kBlue);
  hst_qLargePtNJet1F3->SetLineColor(kGreen);
  hst_qLargePtNJet1F4->SetLineColor(kRed);
  hst_qLargePtNJet1F1->GetXaxis()->SetTitle("Leading Quark Pt");
  hst_qLargePtNJet1F1->GetYaxis()->SetTitle("Event Fraction");
  hst_qLargePtNJet1F1->SetTitle("Events with 1 Jets");
  hst_qLargePtNJet1F1->GetYaxis()->SetRangeUser(0,0.1);
  hst_qLargePtNJet1F1->Draw("HIST");
  hst_qLargePtNJet1F2->Draw("HIST SAME");
  hst_qLargePtNJet1F3->Draw("HIST SAME");
  hst_qLargePtNJet1F4->Draw("HIST SAME");
  TLatex tex13(.4,.85,VetoString);
  tex13.SetTextSize(0.03);
  tex13.SetNDC(kTRUE);
  tex13.Draw();

  TLegend *leg13 = new TLegend(0.65,0.65,0.85,0.85);
  leg13->AddEntry(hst_qLargePtNJet1F1,"d");
  leg13->AddEntry(hst_qLargePtNJet1F2,"u");
  leg13->AddEntry(hst_qLargePtNJet1F3,"s");
  leg13->AddEntry(hst_qLargePtNJet1F4,"c");
  leg13->Draw();
  can13->SaveAs("1DDistPlots/plot_LeadingQuarkPt1JetByFlavour.png");

  TCanvas *can14 = new TCanvas();
  hst_flavourMatchEffQ1->SetStats(0);
  hst_flavourMatchEffQ1->GetXaxis()->SetTitle("delR Match Criteria");
  hst_flavourMatchEffQ1->GetYaxis()->SetTitle("ptres Match Criteria");
  hst_flavourMatchEffQ1->GetZaxis()->SetRangeUser(0.5,1);
  hst_flavourMatchEffQ1->SetTitle("Fraction of Events where jet matched to leading Q also matches parton flavour");
  hst_flavourMatchEffQ1->Draw("colz");
  TLatex tex14(.4,.85,VetoString);
  tex14.SetTextSize(0.03);
  tex14.SetNDC(kTRUE);
  tex14.Draw();
  can14->SaveAs("1DDistPlots/plot_MatchEfficiency_Q1.png");

  TCanvas *can15 = new TCanvas();
  hst_flavourMatchEffQ2->SetStats(0);
  hst_flavourMatchEffQ2->GetXaxis()->SetTitle("delR Match Criteria");
  hst_flavourMatchEffQ2->GetYaxis()->SetTitle("ptres Match Criteria");
  hst_flavourMatchEffQ2->GetZaxis()->SetRangeUser(0.5,1);
  hst_flavourMatchEffQ2->SetTitle("Fraction of Events where jet matched to sub-leading Q also matches parton flavour");
  hst_flavourMatchEffQ2->Draw("colz");
  TLatex tex15(.4,.85,VetoString);
  tex15.SetTextSize(0.03);
  tex15.SetNDC(kTRUE);
  tex15.Draw();
  can15->SaveAs("1DDistPlots/plot_MatchEfficiency_Q2.png");

  TCanvas *can16 = new TCanvas();
  hst_MTrueGen->GetXaxis()->SetTitle("M Visible");
  hst_MTrueGen->GetYaxis()->SetTitle("N Events");
  hst_MTrueGen->SetTitle("M Visible");
  hst_MTrueGen->Draw();
  TLatex tex16(.4,.85,VetoString);
  tex16.SetTextSize(0.03);
  tex16.SetNDC(kTRUE);
  tex16.Draw();
  can16->SaveAs("1DDistPlots/plot_GenM.png");

  TCanvas *can17 = new TCanvas();
  hst_MGenQuarks->GetXaxis()->SetTitle("M Generator Quarks from W from H");
  hst_MGenQuarks->GetYaxis()->SetTitle("N Events");
  hst_MGenQuarks->SetTitle("M Quarks");
  hst_MGenQuarks->Draw();
  TLatex tex17(.4,.85,VetoString);
  tex17.SetTextSize(0.03);
  tex17.SetNDC(kTRUE);
  tex17.Draw();
  can17->SaveAs("1DDistPlots/plot_GenMQuark.png");

  TCanvas *can18 = new TCanvas();
  hst_M_jets_match->SetLineColor(kBlue);
  hst_M_jets_match_ifbest->SetLineColor(kRed);
  hst_M_jets_match->GetXaxis()->SetTitle("M Matched Jets");
  hst_M_jets_match->GetYaxis()->SetTitle("N Events");
  hst_M_jets_match->SetTitle("M Matched Jets");
  hst_M_jets_match->Draw();
  hst_M_jets_match_ifbest->Draw("SAME");
  TLatex tex18(.4,.85,VetoString);
  tex18.SetTextSize(0.03);
  tex18.SetNDC(kTRUE);
  tex18.Draw();

  TLegend *leg18 = new TLegend(0.65,0.65,0.85,0.85);
  leg18->AddEntry(hst_M_jets_match,"No Cond");
  leg18->AddEntry(hst_M_jets_match_ifbest,"If Best");
  leg18->Draw();
  can18->SaveAs("1DDistPlots/plot_MatchedJetsM.png");

  TCanvas *can20 = new TCanvas();
  hst_Q1VsPt->SetLineColor(kBlue);
  hst_Q1MatchVsPt->SetLineColor(kRed);
  hst_Q1VsPt->GetXaxis()->SetTitle("Quark Pt");
  hst_Q1VsPt->GetYaxis()->SetTitle("N Events");
  hst_Q1VsPt->SetTitle("Leading Gen Quark Pt Distribution");
  hst_Q1VsPt->Draw();
  hst_Q1MatchVsPt->Draw("SAME");

  TLegend *leg20 = new TLegend(0.65,0.65,0.85,0.85);
  leg20->AddEntry(hst_Q1VsPt,"All Gen Quarks");
  leg20->AddEntry(hst_Q1MatchVsPt,"Matched Gen Quarks");
  leg20->Draw();
  can20->SaveAs("1DDistPlots/plot_Q1MatchesVsPt.png");

  TCanvas *can21 = new TCanvas();
  hst_Q2VsPt->SetLineColor(kBlue);
  hst_Q2MatchVsPt->SetLineColor(kRed);
  hst_Q2VsPt->GetXaxis()->SetTitle("Quark Pt");
  hst_Q2VsPt->GetYaxis()->SetTitle("N Events");
  hst_Q2VsPt->SetTitle("Sub-leading Gen Quark Pt Distribution");
  hst_Q2VsPt->Draw();
  hst_Q2MatchVsPt->Draw("SAME");

  TLegend *leg21 = new TLegend(0.65,0.65,0.85,0.85);
  leg21->AddEntry(hst_Q2VsPt,"All Gen Quarks");
  leg21->AddEntry(hst_Q2MatchVsPt,"Matched Gen Quarks");
  leg21->Draw();
  can21->SaveAs("1DDistPlots/plot_Q2MatchesVsPt.png");

  TCanvas *can22 = new TCanvas();
  hst_Q1EffVsPt->SetLineColor(kBlue);
  hst_Q2EffVsPt->SetLineColor(kRed);
  hst_Q1EffVsPt->GetXaxis()->SetTitle("Quark Pt");
  hst_Q1EffVsPt->GetYaxis()->SetTitle("Matching Efficiency");
  hst_Q1EffVsPt->GetYaxis()->SetRangeUser(0,1);
  hst_Q1EffVsPt->SetTitle("Quark Matching Efficiency");
  hst_Q1EffVsPt->Draw();
  hst_Q2EffVsPt->Draw("SAME");

  TLegend *leg22 = new TLegend(0.65,0.65,0.85,0.85);
  leg22->AddEntry(hst_Q1EffVsPt,"Leading Quark");
  leg22->AddEntry(hst_Q2EffVsPt,"Sub-leading Quark");
  leg22->Draw();
  can22->SaveAs("1DDistPlots/plot_QMatchEffVsPt.png");

  TCanvas *can23 = new TCanvas();
  hst_Q1VsEta->SetLineColor(kBlue);
  hst_Q1MatchVsEta->SetLineColor(kRed);
  hst_Q1VsEta->GetXaxis()->SetTitle("Quark Eta");
  hst_Q1VsEta->GetYaxis()->SetTitle("N Events");
  hst_Q1VsEta->SetTitle("Leading Gen Quark Eta Distribution");
  hst_Q1VsEta->Draw();
  hst_Q1MatchVsEta->Draw("SAME");

  TLegend *leg23 = new TLegend(0.65,0.65,0.85,0.85);
  leg23->AddEntry(hst_Q1VsEta,"All Gen Quarks");
  leg23->AddEntry(hst_Q1MatchVsEta,"Matched Gen Quarks");
  leg23->Draw();
  can23->SaveAs("1DDistPlots/plot_Q1MatchesVsEta.png");

  TCanvas *can24 = new TCanvas();
  hst_Q2VsEta->SetLineColor(kBlue);
  hst_Q2MatchVsEta->SetLineColor(kRed);
  hst_Q2VsEta->GetXaxis()->SetTitle("Quark Eta");
  hst_Q2VsEta->GetYaxis()->SetTitle("N Events");
  hst_Q2VsEta->SetTitle("Sub-leading Gen Quark Eta Distribution");
  hst_Q2VsEta->Draw();
  hst_Q2MatchVsEta->Draw("SAME");

  TLegend *leg24 = new TLegend(0.65,0.65,0.85,0.85);
  leg24->AddEntry(hst_Q2VsEta,"All Gen Quarks");
  leg24->AddEntry(hst_Q2MatchVsEta,"Matched Gen Quarks");
  leg24->Draw();
  can24->SaveAs("1DDistPlots/plot_Q2MatchesVsEta.png");

  TCanvas *can25 = new TCanvas();
  hst_Q1EffVsEta->SetLineColor(kBlue);
  hst_Q2EffVsEta->SetLineColor(kRed);
  hst_Q1EffVsEta->GetXaxis()->SetTitle("Quark Eta");
  hst_Q1EffVsEta->GetYaxis()->SetTitle("Matching Efficiency");
  hst_Q1EffVsEta->GetYaxis()->SetRangeUser(0,1);
  hst_Q1EffVsEta->SetTitle("Quark Matching Efficiency");
  hst_Q1EffVsEta->Draw();
  hst_Q2EffVsEta->Draw("SAME");

  TLegend *leg25 = new TLegend(0.65,0.65,0.85,0.85);
  leg25->AddEntry(hst_Q1EffVsEta,"Leading Quark");
  leg25->AddEntry(hst_Q2EffVsEta,"Sub-leading Quark");
  leg25->Draw();
  can25->SaveAs("1DDistPlots/plot_QMatchEffVsEta.png");

  TCanvas *can26 = new TCanvas();
  hst_closest2DPTResVsDr->SetStats(0);
  hst_closest2DPTResVsDr->GetXaxis()->SetTitle("PT Resolution");
  hst_closest2DPTResVsDr->GetYaxis()->SetTitle("Delta R");
  hst_closest2DPTResVsDr->SetTitle("Closest Jet");
  hst_closest2DPTResVsDr->Draw("colz");
  can26->SaveAs("1DDistPlots/plot_closest2DPTResVsDr.png");

  TCanvas *can27 = new TCanvas();
  hst_mjjVsdRjj->SetStats(0);
  hst_mjjVsdRjj->GetXaxis()->SetTitle("M_{jj}");
  hst_mjjVsdRjj->GetYaxis()->SetTitle("dR_{jj}");
  hst_mjjVsdRjj->SetTitle("Matched Jets");
  hst_mjjVsdRjj->Draw("colz");
  can27->SaveAs("1DDistPlots/plot_mjjVsdRjj.png");

  TCanvas *can28 = new TCanvas();
  hst_mqqVsdRqq->SetStats(0);
  hst_mqqVsdRqq->GetXaxis()->SetTitle("M_{qq}");
  hst_mqqVsdRqq->GetYaxis()->SetTitle("dR_{qq}");
  hst_mqqVsdRqq->SetTitle("Gen Quarks");
  hst_mqqVsdRqq->Draw("colz");
  can28->SaveAs("1DDistPlots/plot_mqqVsdRqq.png");

  TCanvas *can29 = new TCanvas();
  hst_bestRank->SetStats(0);
  hst_bestRank->GetXaxis()->SetTitle("Entry in Candidate List");
  hst_bestRank->GetYaxis()->SetTitle("N Event");
  hst_bestRank->SetTitle("Rank of best (smallest relative difference between reco+nu & gen) candidate");
  hst_bestRank->Draw();
  TLatex tex29(.4,.85,VetoString);
  tex29.SetTextSize(0.03);
  tex29.SetNDC(kTRUE);
  tex29.Draw();
  can29->SaveAs("1DDistPlots/plot_bestRank.png");

  TCanvas *can30 = new TCanvas();
  hst_bestVsPTRes->SetStats(0);
  hst_bestVsPTRes->GetXaxis()->SetTitle("Entry in Candidate List");
  hst_bestVsPTRes->GetYaxis()->SetTitle("N Event");
  hst_bestVsPTRes->SetTitle("Rank of best candidate vs pT resolution");
  hst_bestVsPTRes->Draw("colz");
  can30->SetLogz();
  can30->SaveAs("1DDistPlots/plot_bestVsPTRes.png");

//  TCanvas *can31 = new TCanvas();
//  hst_bestVsPTResNormed->SetStats(0);
//  hst_bestVsPTResNormed->GetXaxis()->SetTitle("Entry in Candidate List");
//  hst_bestVsPTResNormed->GetYaxis()->SetTitle("N Event");
//  hst_bestVsPTResNormed->SetTitle("Rank of best candidate vs pT resolution (normed by column)");
//  hst_bestVsPTResNormed->Draw("colz");
//  can31->SetLogz();
//  can31->SaveAs("1DDistPlots/plot_bestVsPTResNormed.png");

  TCanvas *can32 = new TCanvas();
  hst_matchComb->Draw();
  can32->SaveAs("1DDistPlots/plot_matchComb.png");

  TCanvas *can33 = new TCanvas();
  hst_delRlj2_correct->SetLineColor(kRed);
  hst_delRlj2->Draw();
  hst_delRlj2_correct->Draw("SAME");
  can33->SaveAs("1DDistPlots/plot_delRlj2.png");

  TCanvas *can34 = new TCanvas();
  hst_delRlj2_diff->Draw();
  can34->SaveAs("1DDistPlots/plot_delRlj2_diff.png");

  TCanvas *can35 = new TCanvas();
  hst_delRj1j2_correct->SetLineColor(kRed);
  hst_delRj1j2->Draw();
  hst_delRj1j2_correct->Draw("SAME");
  can35->SaveAs("1DDistPlots/plot_delRj1j2.png");

  TCanvas *can36 = new TCanvas();
  hst_delRj1j2_diff->Draw();
  can36->SaveAs("1DDistPlots/plot_delRj1j2_diff.png");

  TCanvas *can37 = new TCanvas();
  hst_mj1j2_correct->SetLineColor(kRed);
  hst_mj1j2->Draw();
  hst_mj1j2_correct->Draw("SAME");
  can37->SaveAs("1DDistPlots/plot_mj1j2.png");

  TCanvas *can38 = new TCanvas();
  hst_j2delIdx->Draw();
  can38->SaveAs("1DDistPlots/plot_j2delIdx.png");

  TCanvas *can39 = new TCanvas();
  hst_zWMass_correct->Draw();
  can39->SaveAs("1DDistPlots/plot_zWMass_correct.png");

  TCanvas *can40 = new TCanvas();
  hst_zHMass_correct->Draw();
  can40->SaveAs("1DDistPlots/plot_zHMass_correct.png");

  TCanvas *can41 = new TCanvas();
  hst_zmaxDR_correct->Draw();
  can41->SaveAs("1DDistPlots/plot_zmaxDR_correct.png");

  TCanvas *can42 = new TCanvas();
  hst_zminDR_correct->Draw();
  can42->SaveAs("1DDistPlots/plot_zminDR_correct.png");

  TCanvas *can43 = new TCanvas();
  hst_zmaxDRW_correct->Draw();
  can43->SaveAs("1DDistPlots/plot_zmaxDRW_correct.png");

  TCanvas *can44 = new TCanvas();
  hst_zminDRW_correct->Draw();
  can44->SaveAs("1DDistPlots/plot_zminDRW_correct.png");

  TCanvas *can45 = new TCanvas();
  hst_zDRj1j2_correct->Draw();
  can45->SaveAs("1DDistPlots/plot_zDRj1j2_correct.png");

  TCanvas *can46 = new TCanvas();
  hst_mHRightLepton->GetXaxis()->SetTitle("M(q,q,l)");
  hst_mHRightLepton->GetYaxis()->SetTitle("N Events");
  hst_mHRightLepton->SetTitle("Visible M for Right & Wrong Lepton");
  hst_mHWrongLepton->SetLineColor(kRed);
  hst_mHRightLepton->Draw();
  hst_mHWrongLepton->Draw("SAME");

  TLegend *leg46 = new TLegend(0.65,0.65,0.85,0.85);
  leg46->AddEntry(hst_mHRightLepton,"Gen Quarks + Correct Lepton");
  leg46->AddEntry(hst_mHWrongLepton,"Gen Quarks + Wrong Lepton");
  leg46->Draw();
  can46->SaveAs("1DDistPlots/plot_mHRightWrongLepton.png");

  TCanvas *can47 = new TCanvas();
  hst_HadTopPt->GetXaxis()->SetTitle("Pt");
  hst_HadTopPt->GetYaxis()->SetTitle("N Events");
  hst_HadTopPt->SetTitle("Hadronic Top Pt");
  hst_HadTopPt->GetYaxis()->SetRangeUser(0,1500);
  hst_HadTopPt->SetLineColor(kRed);
  hst_HadTopPt->Draw();
  hst_PtTop_recohtt->Draw("SAME");

  TLegend *leg47 = new TLegend(0.65,0.65,0.85,0.85);
  leg47->AddEntry(hst_PtTop_recohtt,"Reco");
  leg47->AddEntry(hst_HadTopPt,"Gen");
  leg47->Draw();
  can47->SaveAs("1DDistPlots/plot_zzHadTopPtRecoGen.png");

  TCanvas *can48 = new TCanvas();
  hst_HadTopM->GetXaxis()->SetTitle("M");
  hst_HadTopM->GetYaxis()->SetTitle("N Events");
  hst_HadTopM->SetTitle("Hadronic Top M");
  hst_HadTopM->SetLineColor(kRed);
  hst_HadTopM->Draw();
  hst_MTop_recohtt->Draw("SAME");

  TLegend *leg48 = new TLegend(0.65,0.65,0.85,0.85);
  leg48->AddEntry(hst_MTop_recohtt,"Reco");
  leg48->AddEntry(hst_HadTopM,"Gen");
  leg48->Draw();
  can48->SaveAs("1DDistPlots/plot_zzHadTopMRecoGen.png");

  TCanvas *can49 = new TCanvas();
  hst_recogen_PtTop->GetXaxis()->SetTitle("Reco");
  hst_recogen_PtTop->GetYaxis()->SetTitle("Gen");
  hst_recogen_PtTop->SetTitle("HTT Reconstructed vs Generator Hadronic Top Pt");
  hst_recogen_PtTop->Draw("colz");
  can49->SaveAs("1DDistPlots/plot_zzrecogen_PtTop_2D.png");

  TCanvas *can50 = new TCanvas();
  hst_PtWFromTop_recohtt->GetXaxis()->SetTitle("Pt");
  hst_PtWFromTop_recohtt->GetYaxis()->SetTitle("N Events");
  hst_PtWFromTop_recohtt->SetTitle("W From Hadronic Top Pt");
  hst_PtWFromTop_recohtt->GetYaxis()->SetRangeUser(0,3000);
  hst_WFromHadTopPt->SetLineColor(kRed);
  hst_WFromHiggsPt->SetLineColor(kGreen+2);
  hst_PtWFromTop_recohtt->Draw();
  hst_WFromHadTopPt->Draw("SAME");
  hst_WFromHiggsPt->Draw("SAME");

  TLegend *leg50 = new TLegend(0.65,0.65,0.85,0.85);
  leg50->AddEntry(hst_PtWFromTop_recohtt,"Pt From non-B HTT Jets");
  leg50->AddEntry(hst_WFromHadTopPt,"W From Hadronic Top");
  leg50->AddEntry(hst_WFromHiggsPt,"Hadronic W From Higgs");
  leg50->Draw();
  can50->SaveAs("1DDistPlots/plot_zzWFromHadTopPt.png");

  TCanvas *can51 = new TCanvas();
  hst_MWFromTop_recohtt->GetXaxis()->SetTitle("M");
  hst_MWFromTop_recohtt->GetYaxis()->SetTitle("N Events");
  hst_MWFromTop_recohtt->SetTitle("W From Hadronic Top M");
  hst_MWFromTop_recohtt->GetYaxis()->SetRangeUser(0,7000);
  hst_WFromHadTopM->SetLineColor(kRed);
  hst_WFromHiggsM->SetLineColor(kGreen+2);
  hst_MWFromTop_recohtt->Draw();
  hst_WFromHadTopM->Draw("SAME");
  hst_WFromHiggsM->Draw("SAME");

  TLegend *leg51 = new TLegend(0.65,0.65,0.85,0.85);
  leg51->AddEntry(hst_MWFromTop_recohtt,"M From non-B HTT Jets");
  leg51->AddEntry(hst_WFromHadTopM,"W From Hadronic Top");
  leg51->AddEntry(hst_WFromHiggsM,"Hadronic W From Higgs");
  leg51->Draw();
  can51->SaveAs("1DDistPlots/plot_zzWFromHadTopM.png");

  TCanvas *can52 = new TCanvas();
  hst_NSelectedMatchesVsNJetFrac->GetXaxis()->SetTitle("N Jets");
  hst_NSelectedMatchesVsNJetFrac->GetYaxis()->SetTitle("Fraction");
  hst_NSelectedMatchesVsNJetFrac->SetTitle("(H->WW->qqlnu NEvents w/ 2 quarks matched)/(H->WW->qqlnu NEvents)");
  hst_NSelectedMatchesVsNJetFrac->GetYaxis()->SetRangeUser(0,1.2);
  hst_NSelectedMatchesVsNJetFrac->SetLineColor(kRed);
  hst_NSelectedMatchesVsNJetFrac->Draw();
  can52->SaveAs("1DDistPlots/plot_NSelectedMatchesVsNJetFrac.png");

  TCanvas *can53 = new TCanvas();
  hst_WFromTop_2leps_delr->GetXaxis()->SetTitle("DelR(RightLepton,HadronicTop");
  hst_WFromTop_2leps_delr->GetYaxis()->SetTitle("DelR(WrongLepton,HadronicTop");
  hst_WFromTop_2leps_delr->SetTitle("DelR Hadronic Tops & Lepton");
  hst_WFromTop_2leps_delr->Draw("colz");
  can53->SaveAs("1DDistPlots/plot_WFromTop_2leps_delr.png");

}
