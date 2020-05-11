{
// *** Constants ***
  const int nBins = 100;
  const double Offset = 1.2;
  const TString TVet = "NoTop";
  const TString BVet = "MediumBottom";
  const TString PTResBool = ""; // "_NoPTRes"
  const TString fileName = "2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_"+TVet+BVet+PTResBool+"Veto.root";

// *** Files ***
  TFile f(fileName);
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_NoTopNoBottomVeto.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_NoTopMediumBottomVeto.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_NoTopLooseBottomVeto.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_TopNoBottomVeto.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_TopMediumBottomVeto.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_TopLooseBottomVeto.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_NoTopNoBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_NoTopMediumBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_NoTopLooseBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_TopNoBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_TopMediumBottomVeto_NoPTRes.root");
//  TFile f("2lss_diff_Top-tagged/TTHnobb_fxfx_Friend_TopLooseBottomVeto_NoPTRes.root");
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
  float Hreco_nQFromWFromH;
  float Hreco_nLFromWFromH;
  float Hreco_nQFromWFromT;
  float Hreco_nLFromWFromT;
  float Hreco_nNuFromWFromH;
  float Hreco_nNuFromWFromT;
  float Hreco_nJetsInCollection;
  
  // kinematics of gen-level objects and matched objects
  float Hreco_pTTrueGen;
  float Hreco_MTrueGen;
  float Hreco_pTTrueGenPlusNu;
  float Hreco_pTGenQuarks;
  float Hreco_MGenQuarks;
  float Hreco_pTtgen;
  float Hreco_pTHgen;
  float Hreco_quark1pT;
  float Hreco_quark2pT;
  float Hreco_quark1Flavour;
  float Hreco_quark2Flavour;
  float Hreco_jet_matches_quark1_delr;
  float Hreco_jet_matches_quark2_delr;
  float Hreco_jet_matches_quark1_ptres;
  float Hreco_jet_matches_quark2_ptres;
  float Hreco_M_jets_match;
  float Hreco_matchRank;

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
  ft->SetBranchAddress("Hreco_nQFromWFromH",&Hreco_nQFromWFromH);
  ft->SetBranchAddress("Hreco_nLFromWFromH",&Hreco_nLFromWFromH);
  ft->SetBranchAddress("Hreco_nQFromWFromT",&Hreco_nQFromWFromT);
  ft->SetBranchAddress("Hreco_nLFromWFromT",&Hreco_nLFromWFromT);
  ft->SetBranchAddress("Hreco_nNuFromWFromH",&Hreco_nNuFromWFromH);
  ft->SetBranchAddress("Hreco_nNuFromWFromT",&Hreco_nNuFromWFromT);
  ft->SetBranchAddress("Hreco_nJetsInCollection",&Hreco_nJetsInCollection);
  
  // kinematics of gen-level objects and matched objects
  ft->SetBranchAddress("Hreco_pTTrueGen",&Hreco_pTTrueGen);
  ft->SetBranchAddress("Hreco_MTrueGen",&Hreco_MTrueGen);
  ft->SetBranchAddress("Hreco_pTTrueGenPlusNu",&Hreco_pTTrueGenPlusNu);
  ft->SetBranchAddress("Hreco_pTGenQuarks",&Hreco_pTGenQuarks);
  ft->SetBranchAddress("Hreco_MGenQuarks",&Hreco_MGenQuarks);
  ft->SetBranchAddress("Hreco_pTtgen",&Hreco_pTtgen);
  ft->SetBranchAddress("Hreco_pTHgen",&Hreco_pTHgen);
  ft->SetBranchAddress("Hreco_quark1pT",&Hreco_quark1pT);
  ft->SetBranchAddress("Hreco_quark2pT",&Hreco_quark2pT);
  ft->SetBranchAddress("Hreco_quark1Flavour",&Hreco_quark1Flavour);
  ft->SetBranchAddress("Hreco_quark2Flavour",&Hreco_quark2Flavour);
  ft->SetBranchAddress("Hreco_jet_matches_quark1_delr",&Hreco_jet_matches_quark1_delr);
  ft->SetBranchAddress("Hreco_jet_matches_quark2_delr",&Hreco_jet_matches_quark2_delr);
  ft->SetBranchAddress("Hreco_jet_matches_quark1_ptres",&Hreco_jet_matches_quark1_ptres);
  ft->SetBranchAddress("Hreco_jet_matches_quark2_ptres",&Hreco_jet_matches_quark2_ptres);
  ft->SetBranchAddress("Hreco_M_jets_match",&Hreco_M_jets_match);
  ft->SetBranchAddress("Hreco_matchRank",&Hreco_matchRank);

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

  TH1D *hst_closestJetInDelR_delR_ToQ1FromWFromH   = new TH1D("hst_closestJetInDelR_delR","hst_closestJetInDelR_delR",nBins,0,3);
  TH1D *hst_closestJetInDelR_ptres_ToQ1FromWFromH  = new TH1D("hst_closestJetInDelR_ptres","hst_closestJetInDelR_ptres",nBins,-2,3);
  TH1D *hst_closestJetInPTRes_delR_ToQ1FromWFromH  = new TH1D("hst_closestJetInPTRes_delR","hst_closestJetInPTRes_delR",nBins,0,3);
  TH1D *hst_closestJetInPTRes_ptres_ToQ1FromWFromH = new TH1D("hst_closestJetInPTRes_ptres","hst_closestJetInPTRes_ptres",nBins,-2,3);

  TH1D *hst_matchRank = new TH1D("hst_matchRank","hst_matchRank",7,-0.5,6.5);
  TH1D *hst_Wmass = new TH1D("hst_Wmass","hst_Wmass",nBins,45,115);
  TH1D *hst_M_jets_match = new TH1D("hst_M_jets_match","hst_M_jets_match",nBins,0,130);
  TH1D *hst_M_jets_match_ifbest = new TH1D("hst_M_jets_match_ifbest","hst_M_jets_match_ifbest",nBins,0,130);

  TH1D *hst_nQFromWFromH = new TH1D("hst_nQFromWFromH","hst_nQFromWFromH",6,-0.5,5.5);
  TH1D *hst_nNuFromWFromH = new TH1D("hst_nNuFromWFromH","hst_nNuFromWFromH",6,-0.5,5.5);
  TH1D *hst_nLFromWFromH = new TH1D("hst_nLFromWFromH","hst_nLFromWFromH",6,-0.5,5.5);
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

  TH2D *hst_flavourMatchEffQ1 = new TH2D("hst_flavourMatchEffQ1","hst_flavourMatchEffQ1",20,0.05,2.05,20,0.05,2.05); // FIXME
  TH2D *hst_flavourMatchEffQ2 = new TH2D("hst_flavourMatchEffQ2","hst_flavourMatchEffQ2",20,0.05,2.05,20,0.05,2.05); // FIXME

// *** Declare Counts ***
  const int nFMBins = 20;
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
  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    // Calculate Counts
    if (Hreco_nQFromWFromH != 2) continue;
    bool uniqueJetMatch = (Hreco_jet_matches_quark1_delr != -99 && 
                           Hreco_jet_matches_quark2_delr != -99 &&
                           Hreco_jet_matches_quark1_delr != Hreco_jet_matches_quark2_delr);
    if (Hreco_jet_matches_quark1_delr != -99) nEventsJetMatchesQ1NoCond ++;
    if (Hreco_jet_matches_quark2_delr != -99) nEventsJetMatchesQ2NoCond ++;
    if (uniqueJetMatch) nEvents2UniqueMatchedJetsNoCond ++;
    if (Hreco_jet_matches_quark1_delr != -99 && Hreco_pTHvis != -99) nEventsJetMatchesQ1 ++;
    if (Hreco_jet_matches_quark2_delr != -99 && Hreco_pTHvis != -99) nEventsJetMatchesQ2 ++;
    if (uniqueJetMatch && Hreco_pTHvis != -99) nEvents2UniqueMatchedJets ++;
    if (Hreco_matchRank == 0) {
      hst_NSelectedMatchesVsNJet->Fill(Hreco_nJetsInCollection);
    }
    for (int i=0; i<nFMBins; i++) {
      for (int j=0; j<nFMBins; j++) {
        if ((Hreco_closestJetInDelR_delR_ToQ1FromWFromH < (float)(i+1)*0.1) && (abs(Hreco_closestJetInDelR_ptres_ToQ1FromWFromH) < (float)(j+1)*0.1)) {
          if (Hreco_closestJetInDelR_delR_ToQ1FromWFromH != -99 && abs(Hreco_closestJetInDelR_ptres_ToQ1FromWFromH) != -99) {
            nEventsQ1Total[i][j] ++;
            nEventsQ1MatchFlavour[i][j] += (Hreco_closestJetInDelR_flavour_ToQ1FromWFromH == Hreco_quark1Flavour);
          }
        }
        if ((Hreco_closestJetInDelR_delR_ToQ2FromWFromH < (float)(i+1)*0.1) && (abs(Hreco_closestJetInDelR_ptres_ToQ2FromWFromH) < (float)(j+1)*0.1)) {
          if (Hreco_closestJetInDelR_delR_ToQ2FromWFromH != -99 && abs(Hreco_closestJetInDelR_ptres_ToQ2FromWFromH) != -99) {
            nEventsQ2Total[i][j] ++;
            nEventsQ2MatchFlavour[i][j] += (Hreco_closestJetInDelR_flavour_ToQ2FromWFromH == Hreco_quark2Flavour);
          }
        }
      }
    }
    // Reorder quarks based on closest in delR to lepton
//    float jet_matches_quark_near_delr = Hreco_delR_H_q1l_no_cond < Hreco_delR_H_q2l_no_cond ? Hreco_jet_matches_quark1_delr : Hreco_jet_matches_quark2_delr;
//    float jet_matches_quark_far_delr = Hreco_delR_H_q1l_no_cond < Hreco_delR_H_q2l_no_cond ? Hreco_jet_matches_quark2_delr : Hreco_jet_matches_quark1_delr;
//    float jet_matches_quark_near_delr_no_cond = Hreco_delR_H_q1l_no_cond < Hreco_delR_H_q2l_no_cond ? Hreco_jet_matches_quark1_delr_no_cond : Hreco_jet_matches_quark2_delr_no_cond;
//    float jet_matches_quark_far_delr_no_cond = Hreco_delR_H_q1l_no_cond < Hreco_delR_H_q2l_no_cond ? Hreco_jet_matches_quark2_delr_no_cond : Hreco_jet_matches_quark1_delr_no_cond;
//    jet_matches_quark_near_delr = Hreco_jet_matches_quark1_delr;
//    jet_matches_quark_far_delr = Hreco_jet_matches_quark2_delr;
//    jet_matches_quark_near_delr_no_cond = Hreco_jet_matches_quark1_delr_no_cond;
//    jet_matches_quark_far_delr_no_cond = Hreco_jet_matches_quark2_delr_no_cond;
//    if (jet_matches_quark_near_delr >= 0) hstJetMatchesQ1DelR->Fill(jet_matches_quark_near_delr);
//    if (jet_matches_quark_near_delr_no_cond >= 0) hstJetMatchesQ1DelRNoCond->Fill(jet_matches_quark_near_delr_no_cond);
//    if (jet_matches_quark_far_delr >= 0) hstJetMatchesQ2DelR->Fill(jet_matches_quark_far_delr);
//    if (jet_matches_quark_far_delr_no_cond >= 0) hstJetMatchesQ2DelRNoCond->Fill(jet_matches_quark_far_delr_no_cond);

    // Plot DelR and PTRes Distributions
    if (Hreco_closestJetInDelR_delR_ToQ1FromWFromH != -99) hst_closestJetInDelR_delR_ToQ1FromWFromH->Fill(Hreco_closestJetInDelR_delR_ToQ1FromWFromH);
    if (Hreco_closestJetInDelR_ptres_ToQ1FromWFromH != -99) hst_closestJetInDelR_ptres_ToQ1FromWFromH->Fill(Hreco_closestJetInDelR_ptres_ToQ1FromWFromH);
    if (Hreco_closestJetInPTRes_delR_ToQ1FromWFromH != -99) hst_closestJetInPTRes_delR_ToQ1FromWFromH->Fill(Hreco_closestJetInPTRes_delR_ToQ1FromWFromH);
    if (Hreco_closestJetInPTRes_ptres_ToQ1FromWFromH != -99) hst_closestJetInPTRes_ptres_ToQ1FromWFromH->Fill(Hreco_closestJetInPTRes_ptres_ToQ1FromWFromH);
    
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

    // Plot Match Rank if entry != -99
    if (Hreco_matchRank != -99) hst_matchRank->Fill(Hreco_matchRank);

    // Plot number of gen objects
    hst_nQFromWFromH->Fill(Hreco_nQFromWFromH);
    hst_nNuFromWFromH->Fill(Hreco_nNuFromWFromH);
    hst_nLFromWFromH->Fill(Hreco_nLFromWFromH);
    hst_nJetsInCollection->Fill(Hreco_nJetsInCollection);

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

  // *** Print Counts ***
  cout << "*** Print Counts For Chart***" << endl;
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
  cout << "\n\n";

  // Populate 2D flavour matching histograms
  for (int i=0; i<nFMBins; i++) {
    for (int j=0; j<nFMBins; j++) {
      float Q1frac = (float) nEventsQ1MatchFlavour[i][j] / (float) nEventsQ1Total[i][j];
      hst_flavourMatchEffQ1->Fill((float)(i+1)/10.0,(float)(j+1)/10.0,Q1frac);
      float Q2frac = (float) nEventsQ2MatchFlavour[i][j] / (float) nEventsQ2Total[i][j];
      hst_flavourMatchEffQ2->Fill((float)(i+1)/10.0,(float)(j+1)/10.0,Q2frac);
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
  hst_closestJetInPTRes_ptres_ToQ1FromWFromH->SetLineColor(kRed);
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
  hst_flavourMatchEffQ1->SetTitle("Fraction of Events where Jet matched to Q1 also matches Q1 Flavour");
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
  hst_flavourMatchEffQ2->SetTitle("Fraction of Events where Jet matched to Q2 also matches Q2 Flavour");
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
}

