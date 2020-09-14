void computeCorrelation (TTree *ft, float &x, float &y, double &corr, double &slope, double &intercept, int &cut1, int cut1val, int &cut2, int cut2val, int &cut3, int cut3val, int &cut4, int cut4val) {
  double NN;
  double xx;
  double yy;
  double xxxx;
  double xxyy;
  double yyyy;
  NN = 0;
  xx = 0;
  yy = 0;
  xxxx = 0;
  xxyy = 0;
  yyyy = 0;
  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    if (cut1 != cut1val || cut2 != cut2val || cut3 != cut3val || cut4 != cut4val) continue;
    if (x < 0 || y < 0) continue;
    NN ++;
    xx += x;
    yy += y;
    xxxx += x*x;
    xxyy += x*y;
    yyyy += y*y;
  }
  corr  = (NN*xxyy - xx*yy)/sqrt((NN*xxxx-xx*xx)*(NN*yyyy-yy*yy));
  slope = (NN*xxyy - xx*yy)/(NN*xxxx - xx*xx);
  intercept = yy/NN - (slope*xx)/(corr*NN);
}

void producePlots() {
  // *** Constants ***
  const int nBins = 100;
  const double Offset = 1.2;
  const TString TVet = "NoTop";
  const TString BVet = "MediumBottom";
  const TString fileName = "2lss_diff/TTHnobb_fxfx_Friend_"+TVet+BVet+"Veto.root";

  // *** Files ***
  //  TFile f(fileName);
  TFile fgen ("2lss_diff/Gen/TTHnobb_fxfx_Friend.root");
  TFile freco("2lss_diff/Reco_NoMassConstraint/TTHnobb_fxfx_Friend.root");
//  TFile freco("2lss_diff/Reco/TTHnobb_fxfx_Friend.root");
  TFile fcomp("2lss_diff/Comp/TTHnobb_fxfx_Friend.root");
  TTree *ft     = (TTree*) fgen.Get("Friends");
  TTree *ftreco = (TTree*) freco.Get("Friends");
  TTree *ftcomp = (TTree*) fcomp.Get("Friends");
  ft->AddFriend(ftreco);
  ft->AddFriend(ftcomp);

  // *** Calculate decay paths of Higgs ***
  // *** Declare variables ***
  int Hreco_nHiggses;
  int Hreco_nTfromhardprocess;
  int Hreco_nHadT;
  int Hreco_nLepT;
  int Hreco_nWFromH;
  int Hreco_nWFromT;
  int Hreco_nQFromW;
  int Hreco_nGenLep;
  int Hreco_nLFromW;
  int Hreco_nNuFromWFromH;
  int Hreco_nNuFromWFromT;
  int Hreco_nQFromWFromH;
  int Hreco_nQFromWFromT;
  int Hreco_nLFromWFromH;
  int Hreco_nLFromWFromT;
  int Hreco_nTauFromH;
  int Hreco_nhFromTauFromH;
  int Hreco_nLFromTauFromH;
  int Hreco_nNuFromTauFromH;
  int Hreco_nTNuFromTauFromH;
  int Hreco_nZFromH;
  int Hreco_nQFromZFromH;
  int Hreco_nLFromZFromH;
  int Hreco_nNuFromZFromH;
  int Hreco_nTauFromWFromH;
  int Hreco_nLFromTauFromWFromH;
  int Hreco_nNuFromTauFromWFromH;
  int Hreco_nhFromTauFromWFromH;

  ft->SetBranchAddress("Hreco_nHiggses",&Hreco_nHiggses);
  ft->SetBranchAddress("Hreco_nTfromhardprocess",&Hreco_nTfromhardprocess);
  ft->SetBranchAddress("Hreco_nHadT",&Hreco_nHadT);
  ft->SetBranchAddress("Hreco_nLepT",&Hreco_nLepT);
  ft->SetBranchAddress("Hreco_nWFromH",&Hreco_nWFromH);
  ft->SetBranchAddress("Hreco_nWFromT",&Hreco_nWFromT);
  ft->SetBranchAddress("Hreco_nQFromW",&Hreco_nQFromW);
  ft->SetBranchAddress("Hreco_nGenLep",&Hreco_nGenLep);
  ft->SetBranchAddress("Hreco_nLFromW",&Hreco_nLFromW);
  ft->SetBranchAddress("Hreco_nNuFromWFromH",&Hreco_nNuFromWFromH);
  ft->SetBranchAddress("Hreco_nNuFromWFromT",&Hreco_nNuFromWFromT);
  ft->SetBranchAddress("Hreco_nQFromWFromH",&Hreco_nQFromWFromH);
  ft->SetBranchAddress("Hreco_nQFromWFromT",&Hreco_nQFromWFromT);
  ft->SetBranchAddress("Hreco_nLFromWFromH",&Hreco_nLFromWFromH);
  ft->SetBranchAddress("Hreco_nLFromWFromT",&Hreco_nLFromWFromT);
  ft->SetBranchAddress("Hreco_nTauFromH",&Hreco_nTauFromH);
  ft->SetBranchAddress("Hreco_nhFromTauFromH",&Hreco_nhFromTauFromH);
  ft->SetBranchAddress("Hreco_nLFromTauFromH",&Hreco_nLFromTauFromH);
  ft->SetBranchAddress("Hreco_nNuFromTauFromH",&Hreco_nNuFromTauFromH);
  ft->SetBranchAddress("Hreco_nTNuFromTauFromH",&Hreco_nTNuFromTauFromH);
  ft->SetBranchAddress("Hreco_nZFromH",&Hreco_nZFromH);
  ft->SetBranchAddress("Hreco_nQFromZFromH",&Hreco_nQFromZFromH);
  ft->SetBranchAddress("Hreco_nLFromZFromH",&Hreco_nLFromZFromH);
  ft->SetBranchAddress("Hreco_nNuFromZFromH",&Hreco_nNuFromZFromH);
  ft->SetBranchAddress("Hreco_nTauFromWFromH",&Hreco_nTauFromWFromH);
  ft->SetBranchAddress("Hreco_nLFromTauFromWFromH",&Hreco_nLFromTauFromWFromH);
  ft->SetBranchAddress("Hreco_nNuFromTauFromWFromH",&Hreco_nNuFromTauFromWFromH);
  ft->SetBranchAddress("Hreco_nhFromTauFromWFromH",&Hreco_nhFromTauFromWFromH);

  int nHWW       = 0;
  int nHWWqqqq   = 0;
  int nHWWlvlv   = 0;
  int nHWWtvtv   = 0;
  int nHWWqqlv   = 0;
  int nHWWlvtv   = 0;
  int nHWWlvtvlv = 0;
  int nHWWlvtvnh = 0;
  int nHWWqqtv   = 0;
  int nHWWqqtvlv = 0;
  int nHWWqqtvnh = 0;
  int nHtt       = 0;
  int nHttlvlv   = 0;
  int nHttlvhs   = 0;
  int nHtths     = 0;
  int nHZs       = 0;
  int nT[4]      = {0,0,0,0};
  int nHT[4]     = {0,0,0,0};
  int nLT[4]     = {0,0,0,0};

  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    if (Hreco_nWFromH == 2)
      nHWW ++;
    if (Hreco_nQFromWFromH == 4)
      nHWWqqqq ++;
    if (Hreco_nLFromWFromH == 2 && Hreco_nNuFromWFromH == 2)
      nHWWlvlv ++;
    if (Hreco_nTauFromWFromH == 2)
      nHWWtvtv ++;
    if (Hreco_nQFromWFromH == 2 && Hreco_nLFromWFromH == 1 && Hreco_nNuFromWFromH == 1)
      nHWWqqlv ++;
    if (Hreco_nLFromWFromH == 1 && Hreco_nTauFromWFromH == 1)
      nHWWlvtv ++;
    if (Hreco_nLFromWFromH == 1 && Hreco_nTauFromWFromH == 1 && Hreco_nLFromTauFromWFromH == 1)
      nHWWlvtvlv ++;
    if (Hreco_nLFromWFromH == 1 && Hreco_nTauFromWFromH == 1 && Hreco_nhFromTauFromWFromH >= 1)
      nHWWlvtvnh ++;
    if (Hreco_nQFromWFromH == 2 && Hreco_nTauFromWFromH == 1)
      nHWWqqtv ++;
    if (Hreco_nQFromWFromH == 2 && Hreco_nTauFromWFromH == 1 && Hreco_nLFromTauFromWFromH == 1)
      nHWWqqtvlv ++;
    if (Hreco_nQFromWFromH == 2 && Hreco_nTauFromWFromH == 1 && Hreco_nhFromTauFromWFromH >= 1)
      nHWWqqtvnh ++;
    if (Hreco_nTauFromH == 2)
      nHtt ++;
    if (Hreco_nTauFromH == 2 && Hreco_nLFromTauFromH == 2 && Hreco_nNuFromTauFromH == 2)
      nHttlvlv ++;
    if (Hreco_nTauFromH == 2 && Hreco_nLFromTauFromH == 1 && Hreco_nhFromTauFromH >= 1)
      nHttlvhs ++;
    if (Hreco_nTauFromH == 2 && Hreco_nLFromTauFromH == 0 && Hreco_nhFromTauFromH >= 2)
      nHtths ++;
    if (Hreco_nZFromH >= 1)
      nHZs ++;
    nT[Hreco_nTfromhardprocess]++;
    nHT[Hreco_nHadT]++;
    nLT[Hreco_nLepT]++;
  }

  // *** Print decay paths of Higgs ***
  cout << "nHWW:       " << nHWW << endl;
  cout << "nHWWqqqq:   " << nHWWqqqq << endl;
  cout << "nHWWlvlv:   " << nHWWlvlv << endl;
  cout << "nHWWtvtv:   " << nHWWtvtv << endl;
  cout << "nHWWqqlv:   " << nHWWqqlv << endl;
  cout << "nHWWlvtv:   " << nHWWlvtv << endl;
  cout << "nHWWlvtvlv: " << nHWWlvtvlv << endl;
  cout << "nHWWlvtvnh: " << nHWWlvtvnh << endl;
  cout << "nHWWqqtv:   " << nHWWqqtv << endl;
  cout << "nHWWqqtvlv: " << nHWWqqtvlv << endl;
  cout << "nHWWqqtvnh: " << nHWWqqtvnh << endl;
  cout << "nHtt:       " << nHtt << endl;
  cout << "nHttlvlv:   " << nHttlvlv << endl;
  cout << "nHttlvhs:   " << nHttlvhs << endl;
  cout << "nHtths:     " << nHtths << endl;
  cout << "nHZs:       " << nHZs << endl;
  cout << "nT:         {" << nT[0] << "," << nT[1] << "," << nT[2] << "," << nT[3] << "}" << endl;
  cout << "nHT:        {" << nHT[0] << "," << nHT[1] << "," << nHT[2] << "," << nHT[3] << "}" << endl;
  cout << "nLT:        {" << nLT[0] << "," << nLT[1] << "," << nLT[2] << "," << nLT[3] << "}" << endl;

  // *** Declare more variables ***
  // reconstruction loop dependent vars
  float Hreco_minDRlj;
  float Hreco_DRj1j2;
  float Hreco_visHmass;
  float Hreco_Wmass;
  float Hreco_lepIdx;
  float Hreco_j1Idx;
  float Hreco_j2Idx;
  float Hreco_pTVisPlusNu;
  float Hreco_pTHvis;
  float Hreco_pTVisCrossCheck;
  float Hreco_pTVis_jets_match;
  float Hreco_htt_PtTop;
  float Hreco_htt_MTop;
  float Hreco_htt_PtWFromTop;
  float Hreco_htt_MWFromTop;
  float Hreco_htt_HadTop_rightlep_delr;
  float Hreco_htt_HadTop_wronglep_delr;
  float Hreco_FirstLepPt;
  float Hreco_SecondLepPt;

  // delR and closest jet vars
  float Hreco_delR_H_q1l;
  float Hreco_delR_H_q2l;
  float Hreco_closestJet_pt_ToQ1FromWFromH;
  float Hreco_closestJet_pt_ToQ2FromWFromH;
  float Hreco_closestJet_ptres_ToQ1FromWFromH;
  float Hreco_closestJet_ptres_ToQ2FromWFromH;
  float Hreco_closestJet_delR_ToQ1FromWFromH;
  float Hreco_closestJet_delR_ToQ2FromWFromH;
  float Hreco_closestJet_flavour_ToQ1FromWFromH;
  float Hreco_closestJet_flavour_ToQ2FromWFromH;
  
  // lists from gen loop
  int Hreco_nFO;
  int Hreco_nJetsAfterCuts;
  
  // kinematics of gen-level objects and matched objects
  float Hreco_pTTrueGen;
  float Hreco_MTrueGen;
  float Hreco_pTTrueGenPlusNu;
  float Hreco_pt_partonsFromH;
  float Hreco_delR_partonsFromH;
  float Hreco_inv_mass_q1_q2;
  float Hreco_pTHgen;
  float Hreco_quark1pT;
  float Hreco_quark2pT;
  float Hreco_quark1Eta;
  float Hreco_quark2Eta;
  float Hreco_quark1Flavour;
  float Hreco_quark2Flavour;
  int   Hreco_both_selected_jets_matched;
  float Hreco_inv_mass_jm1jm2;
  int   Hreco_rightlepidx;
  int   Hreco_wronglepidx;
  float Hreco_mHrightlep;
  float Hreco_mHwronglep;
  float Hreco_minDRrightlep;
  float Hreco_minDRwronglep;
  int   Hreco_closelepidx;
  int   Hreco_farlepidx;

  // kinematics of hadronic tops
  float Hreco_HadT_pt[4];
  float Hreco_HadT_mass[4];
  float Hreco_WFromHadT_pt[4];
  float Hreco_WFromHadT_mass[4];
  float Hreco_HadWFromH_pt[4];
  float Hreco_HadWFromH_mass[4];

  // reconstruction loop dependent vars
  ft->SetBranchAddress("Hreco_minDRlj",&Hreco_minDRlj);
  ft->SetBranchAddress("Hreco_DRj1j2",&Hreco_DRj1j2);
  ft->SetBranchAddress("Hreco_visHmass",&Hreco_visHmass);
  ft->SetBranchAddress("Hreco_Wmass",&Hreco_Wmass);
  ft->SetBranchAddress("Hreco_lepIdx",&Hreco_lepIdx);
  ft->SetBranchAddress("Hreco_j1Idx",&Hreco_j1Idx);
  ft->SetBranchAddress("Hreco_j2Idx",&Hreco_j2Idx);
  ft->SetBranchAddress("Hreco_pTVisPlusNu",&Hreco_pTVisPlusNu);
  ft->SetBranchAddress("Hreco_pTHvis",&Hreco_pTHvis);
  ft->SetBranchAddress("Hreco_pTVisCrossCheck",&Hreco_pTVisCrossCheck);
  ft->SetBranchAddress("Hreco_pTVis_jets_match",&Hreco_pTVis_jets_match);
  ft->SetBranchAddress("Hreco_htt_PtTop",&Hreco_htt_PtTop);
  ft->SetBranchAddress("Hreco_htt_MTop",&Hreco_htt_MTop);
  ft->SetBranchAddress("Hreco_htt_PtWFromTop",&Hreco_htt_PtWFromTop);
  ft->SetBranchAddress("Hreco_htt_MWFromTop",&Hreco_htt_MWFromTop);
  ft->SetBranchAddress("Hreco_htt_HadTop_rightlep_delr",&Hreco_htt_HadTop_rightlep_delr);
  ft->SetBranchAddress("Hreco_htt_HadTop_wronglep_delr",&Hreco_htt_HadTop_wronglep_delr);
  ft->SetBranchAddress("Hreco_FirstLepPt",&Hreco_FirstLepPt);
  ft->SetBranchAddress("Hreco_SecondLepPt",&Hreco_SecondLepPt);

  // delR and closest jet vars
  ft->SetBranchAddress("Hreco_delR_H_q1l",&Hreco_delR_H_q1l);
  ft->SetBranchAddress("Hreco_delR_H_q2l",&Hreco_delR_H_q2l);
  ft->SetBranchAddress("Hreco_closestJet_pt_ToQ1FromWFromH",&Hreco_closestJet_pt_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJet_pt_ToQ2FromWFromH",&Hreco_closestJet_pt_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJet_ptres_ToQ1FromWFromH",&Hreco_closestJet_ptres_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJet_ptres_ToQ2FromWFromH",&Hreco_closestJet_ptres_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJet_delR_ToQ1FromWFromH",&Hreco_closestJet_delR_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJet_delR_ToQ2FromWFromH",&Hreco_closestJet_delR_ToQ2FromWFromH);
  ft->SetBranchAddress("Hreco_closestJet_flavour_ToQ1FromWFromH",&Hreco_closestJet_flavour_ToQ1FromWFromH);
  ft->SetBranchAddress("Hreco_closestJet_flavour_ToQ2FromWFromH",&Hreco_closestJet_flavour_ToQ2FromWFromH);
  
  // lists from gen loop
  ft->SetBranchAddress("Hreco_nFO",&Hreco_nFO);
  ft->SetBranchAddress("Hreco_nJetsAfterCuts",&Hreco_nJetsAfterCuts);
  
  // kinematics of gen-level objects and matched objects
  ft->SetBranchAddress("Hreco_pTTrueGen",&Hreco_pTTrueGen);
  ft->SetBranchAddress("Hreco_MTrueGen",&Hreco_MTrueGen);
  ft->SetBranchAddress("Hreco_pTTrueGenPlusNu",&Hreco_pTTrueGenPlusNu);
  ft->SetBranchAddress("Hreco_pt_partonsFromH",&Hreco_pt_partonsFromH);
  ft->SetBranchAddress("Hreco_delR_partonsFromH",&Hreco_delR_partonsFromH);
  ft->SetBranchAddress("Hreco_inv_mass_q1_q2",&Hreco_inv_mass_q1_q2);
  ft->SetBranchAddress("Hreco_pTHgen",&Hreco_pTHgen);
  ft->SetBranchAddress("Hreco_quark1pT",&Hreco_quark1pT);
  ft->SetBranchAddress("Hreco_quark2pT",&Hreco_quark2pT);
  ft->SetBranchAddress("Hreco_quark1Eta",&Hreco_quark1Eta);
  ft->SetBranchAddress("Hreco_quark2Eta",&Hreco_quark2Eta);  
  ft->SetBranchAddress("Hreco_quark1Flavour",&Hreco_quark1Flavour);
  ft->SetBranchAddress("Hreco_quark2Flavour",&Hreco_quark2Flavour);
  ft->SetBranchAddress("Hreco_both_selected_jets_matched",&Hreco_both_selected_jets_matched);
  ft->SetBranchAddress("Hreco_inv_mass_jm1jm2",&Hreco_inv_mass_jm1jm2);
  ft->SetBranchAddress("Hreco_rightlepidx",&Hreco_rightlepidx);
  ft->SetBranchAddress("Hreco_wronglepidx",&Hreco_wronglepidx);
  ft->SetBranchAddress("Hreco_mHrightlep",&Hreco_mHrightlep);
  ft->SetBranchAddress("Hreco_mHwronglep",&Hreco_mHwronglep);
  ft->SetBranchAddress("Hreco_minDRrightlep",&Hreco_minDRrightlep);
  ft->SetBranchAddress("Hreco_minDRwronglep",&Hreco_minDRwronglep);
  ft->SetBranchAddress("Hreco_closelepidx",&Hreco_closelepidx);
  ft->SetBranchAddress("Hreco_farlepidx",&Hreco_farlepidx);

  ft->SetBranchAddress("Hreco_HadT_pt",&Hreco_HadT_pt);
  ft->SetBranchAddress("Hreco_HadT_mass",&Hreco_HadT_mass);
  ft->SetBranchAddress("Hreco_WFromHadT_pt",&Hreco_WFromHadT_pt);
  ft->SetBranchAddress("Hreco_WFromHadT_mass",&Hreco_WFromHadT_mass);
  ft->SetBranchAddress("Hreco_HadWFromH_pt",&Hreco_HadWFromH_pt);
  ft->SetBranchAddress("Hreco_HadWFromH_mass",&Hreco_HadWFromH_mass);  

// *** Declare histograms *** 
  TH1D *hst_pTHvis = new TH1D("hst_pTHvis","hst_pTHvis",nBins,-0.5,599.5);
  TH1D *hst_pTVisCrossCheck = new TH1D("pTVisCrossCheck","pTVisCrossCheck",nBins,-0.5,599.5);
  TH1D *hst_pTVisPlusNu = new TH1D("pTVisPlusNu","pTVisPlusNu",nBins,-0.5,599.5);
  TH1D *hst_pTHgen = new TH1D("hst_pTHgen","hst_pTHgen",nBins,-0.5,599.5);
  TH1D *hst_pTTrueGen = new TH1D("hst_pTTrueGen","hst_pTTrueGen",nBins,-0.5,599.5);
  TH1D *hst_pTTrueGenPlusNu = new TH1D("pTTrueGenPlusNu","pTTrueGenPlusNu",nBins,-0.5,599.5);
  TH1D *hst_MTrueGen = new TH1D("hst_MTrueGen","hst_MTrueGen",nBins,-0.5,299.5);
  TH1D *hst_pt_partonsFromH = new TH1D("hst_pt_partonsFromH","hst_pt_partonsFromH",nBins,-0.5,599.5);
  TH1D *hst_inv_mass_q1_q2 = new TH1D("hst_inv_mass_q1_q2","hst_inv_mass_q1_q2",nBins,-0.5,299.5);
  TH1D *hst_pTVis_jets_match = new TH1D("hst_pTVis_jets_match","hst_pTVis_jets_match",nBins,-0.5,599.5);

  TH1D *hst_closestJet_delR_ToQ1FromWFromH   = new TH1D("hst_closestJet_delR_Q1","hst_closestJet_delR_Q1",nBins,0,3);
  TH1D *hst_closestJet_ptres_ToQ1FromWFromH  = new TH1D("hst_closestJet_ptres_Q1","hst_closestJet_ptres_Q1",nBins,-2,3);

  TH1D *hst_closestJet_delR_ToQ2FromWFromH   = new TH1D("hst_closestJet_delR_Q2","hst_closestJet_delR_Q2",nBins,0,3);
  TH1D *hst_closestJet_ptres_ToQ2FromWFromH  = new TH1D("hst_closestJet_ptres_Q2","hst_closestJet_ptres_Q2",nBins,-2,3);

  TH1D *hst_Wmass = new TH1D("hst_Wmass","hst_Wmass",nBins,0,299.5);
  TH1D *hst_inv_mass_jm1jm2 = new TH1D("hst_inv_mass_jm1jm2","hst_inv_mass_jm1jm2",nBins,0,130);
  TH1D *hst_mHrightlep = new TH1D("hst_mHrightlep","hst_mHrightlep",nBins,0,400);
  TH1D *hst_mHwronglep = new TH1D("hst_mHwronglep","hst_mHwronglep",nBins,0,400);
  TH1D *hst_HadTopPt = new TH1D("hst_HadTopPt","hst_HadTopPt",nBins,0,500);
  TH1D *hst_HadTopM = new TH1D("hst_HadTopM","hst_HadTopM",nBins,130,220);
  TH1D *hst_WFromHadTopPt = new TH1D("hst_WFromHadTopPt","hst_WFromHadTopPt",nBins,0,500);
  TH1D *hst_WFromHadTopM = new TH1D("hst_WFromHadTopM","hst_WFromHadTopM",nBins,0,220);
  TH1D *hst_HadWFromHPt = new TH1D("hst_HadWFromHPt","hst_HadWFromHPt",nBins,0,500);
  TH1D *hst_HadWFromHM = new TH1D("hst_HadWFromHM","hst_HadWFromHM",nBins,0,220);
  TH1D *hst_htt_PtTop = new TH1D("hst_htt_PtTop","hst_htt_PtTop",nBins,0,500);
  TH1D *hst_htt_MTop = new TH1D("hst_htt_MTop","hst_htt_MTop",nBins,130,220);
  TH1D *hst_htt_PtWFromTop = new TH1D("hst_htt_PtWFromTop","hst_htt_PtWFromTop",nBins,0,500);
  TH1D *hst_htt_MWFromTop = new TH1D("hst_htt_MWFromTop","hst_htt_MWFromTop",nBins,0,220);

  TH2D *hst_HadTop_2leps_delr = new TH2D("hst_HadTop_2leps_delr","hst_HadTop_2leps_delr",40,0,6,40,0,6);

  TH2D *hst_recogen_PtTop = new TH2D("hst_recogen_PtTop","hst_recogen_PtTop",10,0,500,10,0,500);

  TH1D *hst_nFO = new TH1D("hst_nFO","hst_nFO",6,-0.5,5.5);
  TH1D *hst_nJetsAfterCuts = new TH1D("hst_nJetsAfterCuts","hst_nJetsAfterCuts",20,-0.5,19.5);
  
  TH1D *hst_NSelectedMatchesVsNJet = new TH1D("hst_NSelectedMatchesVsNJet","hst_NSelectedMatchesVsNJet",20,-0.5,19.5);
  TH1D *hst_NMatchesVsNJet = new TH1D("hst_NMatchesVsNJet","hst_NMatchesVsNJet",20,-0.5,19.5);
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

  TH2D *hst_visRecoVsGen = new TH2D("hst_visRecoVsGen","hst_visRecoVsGen",25,-0.5,499.5,25,-0.5,499.5);

  TH1D *hst_lepDeltaPtRight = new TH1D("hst_lepDeltaPtRight","hst_lepDeltaPtRight",100,-0.5,199.5);
  TH1D *hst_lepDeltaPtWrong = new TH1D("hst_lepDeltaPtWrong","hst_lepDeltaPtWrong",100,-0.5,199.5);
  TH1D *hst_lepPtResRight = new TH1D("hst_lepPtResRight","hst_lepPtResRight",100,0,3);
  TH1D *hst_lepPtResWrong = new TH1D("hst_lepPtResWrong","hst_lepPtResWrong",100,0,3);
  TH1D *hst_LJDeltaRRight = new TH1D("hst_LJDeltaRRight","hst_LJDeltaRRight",100,0,3.2);
  TH1D *hst_LJDeltaRWrong = new TH1D("hst_LJDeltaRWrong","hst_LJDeltaRWrong",100,0,3.2);

  TH1D *hst_lepDeltaPtRight_Conflict = new TH1D("hst_lepDeltaPtRight_Conflict","hst_lepDeltaPtRight_Conflict",100,-0.5,199.5);
  TH1D *hst_lepDeltaPtWrong_Conflict = new TH1D("hst_lepDeltaPtWrong_Conflict","hst_lepDeltaPtWrong_Conflict",100,-0.5,199.5);
  TH1D *hst_lepPtResRight_Conflict = new TH1D("hst_lepPtResRight_Conflict","hst_lepPtResRight_Conflict",100,0,3);
  TH1D *hst_lepPtResWrong_Conflict = new TH1D("hst_lepPtResWrong_Conflict","hst_lepPtResWrong_Conflict",100,0,3);
  TH1D *hst_LJDeltaRRight_Conflict = new TH1D("hst_LJDeltaRRight_Conflict","hst_LJDeltaRRight_Conflict",100,0,3.2);
  TH1D *hst_LJDeltaRWrong_Conflict = new TH1D("hst_LJDeltaRWrong_Conflict","hst_LJDeltaRWrong_Conflict",100,0,3.2);

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
  int nRightLepChosen = 0;
  int nWrongLepChosen = 0;
  int nLepChosen = 0;
  for (int i=0; i<ft->GetEntries(); i++)
  {
    ft->GetEntry(i);
    // Calculate Counts
    if (Hreco_nQFromWFromH != 2 || Hreco_nLFromWFromH != 1) continue;
    if (Hreco_nFO != 2) continue;
//    if (Hreco_nHadT != 1 || Hreco_nLepT != 1) continue;
    bool Q1Match = Hreco_closestJet_delR_ToQ1FromWFromH != -99 && Hreco_closestJet_delR_ToQ1FromWFromH < 0.3 && abs(Hreco_closestJet_ptres_ToQ1FromWFromH) < 0.6;
    bool Q2Match = Hreco_closestJet_delR_ToQ2FromWFromH != -99 && Hreco_closestJet_delR_ToQ2FromWFromH < 0.3 && abs(Hreco_closestJet_ptres_ToQ2FromWFromH) < 0.6;
    bool uniqueJetMatch = Q1Match && Q2Match && Hreco_closestJet_pt_ToQ1FromWFromH != Hreco_closestJet_pt_ToQ2FromWFromH;
    if (Q1Match) nEventsJetMatchesQ1NoCond ++;
    if (Q2Match) nEventsJetMatchesQ2NoCond ++;
    if (uniqueJetMatch) nEvents2UniqueMatchedJetsNoCond ++;
    if (Q1Match && Hreco_pTHvis != -99) nEventsJetMatchesQ1 ++;
    if (Q2Match && Hreco_pTHvis != -99) nEventsJetMatchesQ2 ++;
    if (uniqueJetMatch && Hreco_pTHvis != -99) nEvents2UniqueMatchedJets ++;
    if (Hreco_rightlepidx != -99 && Hreco_rightlepidx == Hreco_lepIdx) nRightLepChosen ++;
    if (Hreco_wronglepidx != -99 && Hreco_wronglepidx == Hreco_lepIdx) nWrongLepChosen ++;
    nLepChosen ++;

    // Plot matching efficiency vs quark pt & eta
    if (Hreco_quark1pT != -99) hst_Q1VsPt->Fill(Hreco_quark1pT);
    if (Hreco_quark1pT != -99 && Q1Match) hst_Q1MatchVsPt->Fill(Hreco_quark1pT);
    if (Hreco_quark2pT != -99) hst_Q2VsPt->Fill(Hreco_quark2pT);
    if (Hreco_quark2pT != -99 && Q2Match) hst_Q2MatchVsPt->Fill(Hreco_quark2pT);
    if (Hreco_quark1Eta != -99) hst_Q1VsEta->Fill(Hreco_quark1Eta);
    if (Hreco_quark1Eta != -99 && Q1Match) hst_Q1MatchVsEta->Fill(Hreco_quark1Eta);
    if (Hreco_quark2Eta != -99) hst_Q2VsEta->Fill(Hreco_quark2Eta);
    if (Hreco_quark2Eta != -99 && Q2Match) hst_Q2MatchVsEta->Fill(Hreco_quark2Eta);

    // Plot matching efficiency vs NJet in event
    if (Hreco_both_selected_jets_matched) hst_NSelectedMatchesVsNJet->Fill(Hreco_nJetsAfterCuts);
    if (Q1Match && Q2Match) hst_NMatchesVsNJet->Fill(Hreco_nJetsAfterCuts);

    // Calculate flavour matching plot
    for (int i=0; i<nFMBins; i++) {
      for (int j=0; j<nFMBins; j++) {
        if ((Hreco_closestJet_delR_ToQ1FromWFromH < (float)(i+1)*((float)dRMax/(float)nFMBins)) && (abs(Hreco_closestJet_ptres_ToQ1FromWFromH) < (float)(j+1)*((float)dPtMax/(float)nFMBins))) {
          if (Hreco_closestJet_delR_ToQ1FromWFromH != -99 && abs(Hreco_closestJet_ptres_ToQ1FromWFromH) != -99) {
            nEventsQ1Total[i][j] ++;
            nEventsQ1MatchFlavour[i][j] += (Hreco_closestJet_flavour_ToQ1FromWFromH == Hreco_quark1Flavour);
          }
        }
        if ((Hreco_closestJet_delR_ToQ2FromWFromH < (float)(i+1)*((float)dRMax/(float)nFMBins)) && (abs(Hreco_closestJet_ptres_ToQ2FromWFromH) < (float)(j+1)*((float)dPtMax/(float)nFMBins))) {
          if (Hreco_closestJet_delR_ToQ2FromWFromH != -99 && abs(Hreco_closestJet_ptres_ToQ2FromWFromH) != -99) {
            nEventsQ2Total[i][j] ++;
            nEventsQ2MatchFlavour[i][j] += (Hreco_closestJet_flavour_ToQ2FromWFromH == Hreco_quark2Flavour);
          }
        }
      }
    }
      
    // Fill mHRight and mHWrong
    if (Hreco_mHrightlep != -99) hst_mHrightlep->Fill(Hreco_mHrightlep);
    if (Hreco_mHwronglep != -99) hst_mHwronglep->Fill(Hreco_mHwronglep);

    // Fill Had Top histos
    if (Hreco_HadT_pt[0] != -99 && Hreco_htt_PtTop != -99 && Hreco_WFromHadT_pt[0] != -99 && Hreco_HadWFromH_pt[0] != -99 && Hreco_htt_PtWFromTop != -99 && Hreco_nHadT == 1) {
      hst_HadTopPt->Fill(Hreco_HadT_pt[0]);
      hst_HadTopM->Fill(Hreco_HadT_mass[0]);
      hst_WFromHadTopPt->Fill(Hreco_WFromHadT_pt[0]);
      hst_WFromHadTopM->Fill(Hreco_WFromHadT_mass[0]);
      hst_HadWFromHPt->Fill(Hreco_HadWFromH_pt[0]);
      hst_HadWFromHM->Fill(Hreco_HadWFromH_mass[0]);
      hst_htt_PtTop->Fill(Hreco_htt_PtTop);
      hst_htt_MTop->Fill(Hreco_htt_MTop);
      hst_htt_PtWFromTop->Fill(Hreco_htt_PtWFromTop);
      hst_htt_MWFromTop->Fill(Hreco_htt_MWFromTop);
      hst_recogen_PtTop->Fill(Hreco_htt_PtTop,Hreco_HadT_pt[0]);
    }

    if (Hreco_htt_HadTop_rightlep_delr != -99 and Hreco_htt_HadTop_wronglep_delr != -99) {
      hst_HadTop_2leps_delr->Fill(Hreco_htt_HadTop_rightlep_delr, Hreco_htt_HadTop_wronglep_delr);
    }

    // Plot 2D m_jj distributions
    if (uniqueJetMatch) hst_mjjVsdRjj->Fill(Hreco_inv_mass_jm1jm2,Hreco_DRj1j2);
    if (Hreco_delR_partonsFromH != -99) hst_mqqVsdRqq->Fill(Hreco_inv_mass_q1_q2,Hreco_delR_partonsFromH);

    // Plot delR and PTRes distributions
    if (Hreco_closestJet_delR_ToQ1FromWFromH != -99) hst_closestJet_delR_ToQ1FromWFromH->Fill(Hreco_closestJet_delR_ToQ1FromWFromH);
    if (Hreco_closestJet_ptres_ToQ1FromWFromH != -99) hst_closestJet_ptres_ToQ1FromWFromH->Fill(Hreco_closestJet_ptres_ToQ1FromWFromH);

    if (Hreco_closestJet_delR_ToQ2FromWFromH != -99) hst_closestJet_delR_ToQ2FromWFromH->Fill(Hreco_closestJet_delR_ToQ2FromWFromH);
    if (Hreco_closestJet_ptres_ToQ2FromWFromH != -99) hst_closestJet_ptres_ToQ2FromWFromH->Fill(Hreco_closestJet_ptres_ToQ2FromWFromH);

    if (Hreco_closestJet_delR_ToQ1FromWFromH != -99) hst_closest2DPTResVsDr->Fill(Hreco_closestJet_ptres_ToQ1FromWFromH,Hreco_closestJet_delR_ToQ1FromWFromH);
    if (Hreco_closestJet_delR_ToQ2FromWFromH != -99) hst_closest2DPTResVsDr->Fill(Hreco_closestJet_ptres_ToQ2FromWFromH,Hreco_closestJet_delR_ToQ2FromWFromH);
    
    // Plot pT dists if entry != -99
    if (Hreco_pTHvis != -99) hst_pTHvis->Fill(Hreco_pTHvis);
    if (Hreco_pTVisCrossCheck != -99) hst_pTVisCrossCheck->Fill(Hreco_pTVisCrossCheck);
    if (Hreco_pTVisPlusNu != -99 && Hreco_nQFromWFromH == 2 && Hreco_nLFromWFromH == 1 && Hreco_nNuFromWFromH == 1) hst_pTVisPlusNu->Fill(Hreco_pTVisPlusNu);
    if (Hreco_pTHgen != -99) hst_pTHgen->Fill(Hreco_pTHgen);
    if (Hreco_pTTrueGen != -99) hst_pTTrueGen->Fill(Hreco_pTTrueGen);
    if (Hreco_pTTrueGenPlusNu != -99) hst_pTTrueGenPlusNu->Fill(Hreco_pTTrueGenPlusNu);
    if (Hreco_pt_partonsFromH != -99) hst_pt_partonsFromH->Fill(Hreco_pt_partonsFromH);
    if (Hreco_pTVis_jets_match != -99) hst_pTVis_jets_match->Fill(Hreco_pTVis_jets_match);

    // Plot M dists if entry != -99
    if (Hreco_MTrueGen != -99) hst_MTrueGen->Fill(Hreco_MTrueGen);
    if (Hreco_inv_mass_q1_q2 != -99) hst_inv_mass_q1_q2->Fill(Hreco_inv_mass_q1_q2);
    if (Hreco_Wmass != -99) hst_Wmass->Fill(Hreco_Wmass);
    if (Hreco_inv_mass_jm1jm2 != -99) hst_inv_mass_jm1jm2->Fill(Hreco_inv_mass_jm1jm2);

    // Plot number of objects
    hst_nFO->Fill(Hreco_nFO);
    hst_nJetsAfterCuts->Fill(Hreco_nJetsAfterCuts);

    // Plot 2D reco vs gen histogram
    if (Hreco_pTHvis != -99 && Hreco_pTTrueGen != -99) hst_visRecoVsGen->Fill(Hreco_pTHvis,Hreco_pTTrueGen);

    // Plot DeltaPt between leptons
    int softidx = 1;
    int hardidx = 0;
    if (Hreco_FirstLepPt < Hreco_SecondLepPt) {
        softidx = 0;
        hardidx = 1;
    }
    if (Hreco_rightlepidx == softidx) hst_lepDeltaPtRight->Fill(abs(Hreco_FirstLepPt-Hreco_SecondLepPt));
    if (Hreco_rightlepidx == hardidx) hst_lepDeltaPtWrong->Fill(abs(Hreco_FirstLepPt-Hreco_SecondLepPt));
    if (Hreco_rightlepidx == softidx) hst_lepPtResRight->Fill(2*abs(Hreco_FirstLepPt-Hreco_SecondLepPt)/(Hreco_FirstLepPt+Hreco_SecondLepPt));
    if (Hreco_rightlepidx == hardidx) hst_lepPtResWrong->Fill(2*abs(Hreco_FirstLepPt-Hreco_SecondLepPt)/(Hreco_FirstLepPt+Hreco_SecondLepPt));
    if (Hreco_rightlepidx == Hreco_closelepidx) hst_LJDeltaRRight->Fill(min(Hreco_minDRrightlep,Hreco_minDRwronglep));
    if (Hreco_rightlepidx != Hreco_closelepidx) hst_LJDeltaRWrong->Fill(min(Hreco_minDRrightlep,Hreco_minDRwronglep));

    if ((Hreco_rightlepidx == softidx && Hreco_rightlepidx != Hreco_closelepidx) || (Hreco_rightlepidx == hardidx && Hreco_rightlepidx == Hreco_closelepidx)) {
      if (Hreco_rightlepidx == softidx) hst_lepDeltaPtRight_Conflict->Fill(abs(Hreco_FirstLepPt-Hreco_SecondLepPt));
      if (Hreco_rightlepidx == hardidx) hst_lepDeltaPtWrong_Conflict->Fill(abs(Hreco_FirstLepPt-Hreco_SecondLepPt));
      if (Hreco_rightlepidx == softidx) hst_lepPtResRight_Conflict->Fill(2*abs(Hreco_FirstLepPt-Hreco_SecondLepPt)/(Hreco_FirstLepPt+Hreco_SecondLepPt));
      if (Hreco_rightlepidx == hardidx) hst_lepPtResWrong_Conflict->Fill(2*abs(Hreco_FirstLepPt-Hreco_SecondLepPt)/(Hreco_FirstLepPt+Hreco_SecondLepPt));
      if (Hreco_rightlepidx == Hreco_closelepidx) hst_LJDeltaRRight_Conflict->Fill(min(Hreco_minDRrightlep,Hreco_minDRwronglep));
      if (Hreco_rightlepidx != Hreco_closelepidx) hst_LJDeltaRWrong_Conflict->Fill(min(Hreco_minDRrightlep,Hreco_minDRwronglep));
    }

  }

  // Compute correlations 
  int nocut = 0;
  double recogencorr, recogenslope, recogenintercept;
  computeCorrelation(ft,Hreco_pTHvis,Hreco_pTTrueGen,recogencorr,recogenslope,recogenintercept,
                        Hreco_nQFromWFromH,2,
                        Hreco_nLFromWFromH,1,
                        Hreco_nFO,2, //nocut,nocut, //Hreco_nHadT,1,
                        nocut,nocut //Hreco_nLepT,1
                        );
  double visfullcorr, visfullslope, visfullintercept;
  computeCorrelation(ft,Hreco_pTTrueGen,Hreco_pTHgen,visfullcorr,visfullslope,visfullintercept,
                        Hreco_nQFromWFromH,2,
                        Hreco_nLFromWFromH,1,
                        Hreco_nFO,2, //nocut,nocut, //Hreco_nHadT,1,
                        nocut,nocut //Hreco_nLepT,1
                        );
  double totalcorr, totalslope, totalintercept;
  computeCorrelation(ft,Hreco_pTHvis,Hreco_pTHgen,totalcorr,totalslope,totalintercept,
                        Hreco_nQFromWFromH,2,
                        Hreco_nLFromWFromH,1,
                        Hreco_nFO,2, //nocut,nocut, //Hreco_nHadT,1,
                        nocut,nocut  //Hreco_nLepT,1
                        );
  double totalcorrnocuts, totalslopenocuts, totalinterceptnocuts;
  computeCorrelation(ft,Hreco_pTHvis,Hreco_pTHgen,totalcorrnocuts,totalslopenocuts,totalinterceptnocuts,
                        nocut,nocut,
                        nocut,nocut,
                        nocut,nocut,
                        nocut,nocut
                        );
  double TopPtCorr, TopPtSlope, TopPtIntercept;
  computeCorrelation(ft,Hreco_htt_PtTop,Hreco_HadT_pt[0],TopPtCorr,TopPtSlope,TopPtIntercept,
                        nocut,nocut,
                        nocut,nocut,
                        nocut,nocut,
                        nocut,nocut
                        ); 
  
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
    float Den = hst_NMatchesVsNJet->GetBinContent(i);
    float sf = 1; //(i-1)*(i-2)/2.0 for histogram scaled by NJet choose 2
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

  // Scale all distributions
  hst_pTHvis->Scale(1/hst_pTHvis->GetEntries());
  hst_pTVisCrossCheck->Scale(1/hst_pTVisCrossCheck->GetEntries());
  hst_pTVisPlusNu->Scale(1/hst_pTVisPlusNu->GetEntries());
  hst_pTHgen->Scale(1/hst_pTHgen->GetEntries());
  hst_pTTrueGen->Scale(1/hst_pTTrueGen->GetEntries());
  hst_pTTrueGenPlusNu->Scale(1/hst_pTTrueGenPlusNu->GetEntries());
  hst_pt_partonsFromH->Scale(1/hst_pt_partonsFromH->GetEntries());
  hst_pTVis_jets_match->Scale(1/hst_pTVis_jets_match->GetEntries());

  // *** Print Counts ***
  cout << endl << "*** Print Counts For Chart***" << endl;
  cout << "No cuts:                                                 " << ft->GetEntries() << endl;
  cout << "Is H->WW->qqlvH:                                         " << nHWWqqlv << endl;
  cout << "Has a jet that matches quark 1:                          " << nEventsJetMatchesQ1NoCond << endl;
  cout << "Has a jet that matches quark 2:                          " << nEventsJetMatchesQ2NoCond << endl;
  cout << "Has two jets, one of each matches quark 1 & 2:           " << nEvents2UniqueMatchedJetsNoCond << endl;
  cout << "Passes default reconstruction algorithm (*):             " << hst_pTHvis->GetEntries() << endl;
  cout << "(*) + Is H->WW->qqlvH:                                   " << hst_pTVisPlusNu->GetEntries() << endl;
  cout << "(*) + Has a jet that matches quark 1:                    " << nEventsJetMatchesQ1 << endl;
  cout << "(*) + Has a jet that matches quark 2:                    " << nEventsJetMatchesQ2 << endl;
  cout << "(*) + Has two jets, one of each matches quark 1 & 2:     " << nEvents2UniqueMatchedJets << endl;
  cout << "(*) + Has two jets, one of each matches quark 1 & 2 and" << endl;
  cout << "both jets are correctly selected by the algo:            " << hst_NSelectedMatchesVsNJet->GetEntries() << endl;
  cout << endl << "*** Correlations ***" << endl;
  cout << "recogencorr:     " << recogencorr     << "\trecogenslope:      " << recogenslope
       << "\tm/r: "           << recogenslope/recogencorr                   << "\trecogenintercept:     " << recogenintercept     << endl;
  cout << "visfullcorr:     " << visfullcorr     << "\tvisfullslope:      " << visfullslope
       << "\tm/r: "           << visfullslope/visfullcorr                   << "\tvisfullintercept:     " << visfullintercept     << endl;
  cout << "totalcorr:       " << totalcorr       << "\ttotalslope:        " << totalslope
       << "\tm/r: "           << totalslope/totalcorr                       << "\ttotalintercept:       " << totalintercept       << endl;
  cout << "totalcorrnocuts: " << totalcorrnocuts << "\ttotalslopenocuts:  " << totalslopenocuts
       << "\tm/r: "           << totalslopenocuts/totalcorrnocuts           << "\ttotalinterceptnocuts: " << totalinterceptnocuts << endl;
  cout << "TopPtCorr:       " << TopPtCorr       << "\tTopPtSlope:        " << TopPtSlope
       << "\tm/r: "           << TopPtSlope/TopPtCorr                       << "\tTopPtIntercept:       " << TopPtIntercept       << endl;
  cout << endl << "*** Match Counts ***" << endl;
  cout << "nRightLepChosen: " << nRightLepChosen << "/" << nLepChosen << endl;
  cout << "nWrongLepChosen: " << nWrongLepChosen << "/" << nLepChosen << endl; 

  gSystem->Exec("mkdir 1DDistPlots");
  TString VetoString = TVet+BVet+"Veto";

  TCanvas *can1 = new TCanvas();
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
  TLatex tex1(.4,.85,VetoString);
  tex1.SetTextSize(0.03);
  tex1.SetNDC(kTRUE);
  tex1.Draw();

  TLegend *leg1 = new TLegend(0.65,0.65,0.85,0.85);
  leg1->AddEntry(hst_pTHvis,"Reco");
  leg1->AddEntry(hst_pTHgen,"Gen");
  leg1->AddEntry(hst_pTVisPlusNu,"RecoPlusNu");
  leg1->AddEntry(hst_pTTrueGen,"Gen(q1) + Gen(q2) + Gen(l)");
  leg1->AddEntry(hst_pTTrueGenPlusNu,"Gen(q1) + Gen(q2) + Gen(l) + Gen(nu)");
//  leg2->AddEntry(hst_pTVis_jets_match,"Reco with Matched Jets");
  leg1->Draw();
  can1->SaveAs("1DDistPlots/plot_PTDists.png");

  TCanvas *can2 = new TCanvas();
  hst_Wmass->GetXaxis()->SetTitle("W pT");
  hst_Wmass->GetYaxis()->SetTitle("a.u.");
  hst_Wmass->GetXaxis()->CenterTitle();
  hst_Wmass->GetYaxis()->CenterTitle();
  hst_Wmass->GetXaxis()->SetTitleOffset(Offset);
  hst_Wmass->GetYaxis()->SetTitleOffset(Offset);
  hst_Wmass->SetTitle("Mass Selected Jet Pair");
  hst_Wmass->Draw();
  TLatex tex2(.4,.85,VetoString);
  tex2.SetTextSize(0.03);
  tex2.SetNDC(kTRUE);
  tex2.Draw();
  can2->SaveAs("1DDistPlots/plot_WMass.png");

  TCanvas *can3 = new TCanvas();
  hst_closestJet_delR_ToQ1FromWFromH->GetXaxis()->SetTitle("Minimum #DeltaR");
  hst_closestJet_delR_ToQ1FromWFromH->GetYaxis()->SetTitle("N Events");
  hst_closestJet_delR_ToQ1FromWFromH->SetTitle("Quark 1 #DeltaR");
  hst_closestJet_delR_ToQ1FromWFromH->SetLineColor(kRed);
  hst_closestJet_delR_ToQ1FromWFromH->Draw();
  TLatex tex3(.4,.85,VetoString);
  tex3.SetTextSize(0.03);
  tex3.SetNDC(kTRUE);
  tex3.Draw();

  TLegend *leg3 = new TLegend(0.65,0.65,0.85,0.85);
  leg3->AddEntry(hst_closestJet_delR_ToQ1FromWFromH,"Min #DeltaR");
  leg3->Draw();
  can3->SaveAs("1DDistPlots/plot_Q1dR.png");

  TCanvas *can4 = new TCanvas();
  hst_closestJet_ptres_ToQ1FromWFromH->GetXaxis()->SetTitle("Minimum pT_res");
  hst_closestJet_ptres_ToQ1FromWFromH->GetYaxis()->SetTitle("N Events");
  hst_closestJet_ptres_ToQ1FromWFromH->SetTitle("Quark 1 pT_res");
  hst_closestJet_ptres_ToQ1FromWFromH->SetLineColor(kRed);
  hst_closestJet_ptres_ToQ1FromWFromH->Draw();
  TLatex tex4(.4,.85,VetoString);
  tex4.SetTextSize(0.03);
  tex4.SetNDC(kTRUE);
  tex4.Draw();

  TLegend *leg4 = new TLegend(0.65,0.65,0.85,0.85);
  leg4->AddEntry(hst_closestJet_ptres_ToQ1FromWFromH,"Min #DeltaR");
  leg4->Draw();
  can4->SaveAs("1DDistPlots/plot_Q1DPtOPt.png");

  TCanvas *can5 = new TCanvas();
  hst_closestJet_delR_ToQ2FromWFromH->GetXaxis()->SetTitle("Minimum #DeltaR");
  hst_closestJet_delR_ToQ2FromWFromH->GetYaxis()->SetTitle("N Events");
  hst_closestJet_delR_ToQ2FromWFromH->SetTitle("Quark 2 #DeltaR");
  hst_closestJet_delR_ToQ2FromWFromH->SetLineColor(kRed);
  hst_closestJet_delR_ToQ2FromWFromH->Draw();
  TLatex tex5(.4,.85,VetoString);
  tex5.SetTextSize(0.03);
  tex5.SetNDC(kTRUE);
  tex5.Draw();

  TLegend *leg5 = new TLegend(0.65,0.65,0.85,0.85);
  leg5->AddEntry(hst_closestJet_delR_ToQ2FromWFromH,"Min #DeltaR");
  leg5->Draw();
  can5->SaveAs("1DDistPlots/plot_Q2dR.png");

  TCanvas *can6 = new TCanvas();
  hst_closestJet_ptres_ToQ2FromWFromH->GetXaxis()->SetTitle("Minimum pT_res");
  hst_closestJet_ptres_ToQ2FromWFromH->GetYaxis()->SetTitle("N Events");
  hst_closestJet_ptres_ToQ2FromWFromH->SetTitle("Quark 2 pT_res");
  hst_closestJet_ptres_ToQ2FromWFromH->SetLineColor(kRed);
  hst_closestJet_ptres_ToQ2FromWFromH->Draw();
  TLatex tex6(.4,.85,VetoString);
  tex6.SetTextSize(0.03);
  tex6.SetNDC(kTRUE);
  tex6.Draw();

  TLegend *leg6 = new TLegend(0.65,0.65,0.85,0.85);
  leg6->AddEntry(hst_closestJet_ptres_ToQ2FromWFromH,"Min #DeltaR");
  leg6->Draw();
  can6->SaveAs("1DDistPlots/plot_Q2DPtOPt.png");

  TCanvas *can7 = new TCanvas();
  hst_nJetsAfterCuts->GetXaxis()->SetTitle("N Jets");
  hst_nJetsAfterCuts->GetYaxis()->SetTitle("N Events");
  hst_nJetsAfterCuts->SetTitle("N Jets that pass vetos (No T + Medium B)");
  hst_nJetsAfterCuts->Draw("HIST");
  TLatex tex7(.4,.85,VetoString);
  tex7.SetTextSize(0.03);
  tex7.SetNDC(kTRUE);
  tex7.Draw();
  can7->SaveAs("1DDistPlots/plot_nJetsNoTopNoB.png");

  TCanvas *can8 = new TCanvas();
  hst_NSelectedMatchesVsNJet->GetXaxis()->SetTitle("N Jets");
  hst_NSelectedMatchesVsNJet->GetYaxis()->SetTitle("N Events");
  hst_NSelectedMatchesVsNJet->SetTitle("N Events where algo chooses closest matched jets");
  hst_NSelectedMatchesVsNJet->Draw();
  TLatex tex8(.4,.85,VetoString);
  tex8.SetTextSize(0.03);
  tex8.SetNDC(kTRUE);
  tex8.Draw();
  can8->SaveAs("1DDistPlots/plot_NSelectedMatchesVsNJet.png");

  TCanvas *can9 = new TCanvas();
  hst_flavourMatchEffQ1->SetStats(0);
  hst_flavourMatchEffQ1->GetXaxis()->SetTitle("delR Match Criteria");
  hst_flavourMatchEffQ1->GetYaxis()->SetTitle("ptres Match Criteria");
  hst_flavourMatchEffQ1->GetZaxis()->SetRangeUser(0.5,1);
  hst_flavourMatchEffQ1->SetTitle("Fraction of Events where jet matched to leading Q also matches parton flavour");
  hst_flavourMatchEffQ1->Draw("colz");
  TLatex tex9(.4,.85,VetoString);
  tex9.SetTextSize(0.03);
  tex9.SetNDC(kTRUE);
  tex9.Draw();
  can9->SaveAs("1DDistPlots/plot_MatchEfficiency_Q1.png");

  TCanvas *can10 = new TCanvas();
  hst_flavourMatchEffQ2->SetStats(0);
  hst_flavourMatchEffQ2->GetXaxis()->SetTitle("delR Match Criteria");
  hst_flavourMatchEffQ2->GetYaxis()->SetTitle("ptres Match Criteria");
  hst_flavourMatchEffQ2->GetZaxis()->SetRangeUser(0.5,1);
  hst_flavourMatchEffQ2->SetTitle("Fraction of Events where jet matched to sub-leading Q also matches parton flavour");
  hst_flavourMatchEffQ2->Draw("colz");
  TLatex tex10(.4,.85,VetoString);
  tex10.SetTextSize(0.03);
  tex10.SetNDC(kTRUE);
  tex10.Draw();
  can10->SaveAs("1DDistPlots/plot_MatchEfficiency_Q2.png");

  TCanvas *can11 = new TCanvas();
  hst_MTrueGen->GetXaxis()->SetTitle("M Visible");
  hst_MTrueGen->GetYaxis()->SetTitle("N Events");
  hst_MTrueGen->SetTitle("M Visible");
  hst_MTrueGen->Draw();
  TLatex tex11(.4,.85,VetoString);
  tex11.SetTextSize(0.03);
  tex11.SetNDC(kTRUE);
  tex11.Draw();
  can11->SaveAs("1DDistPlots/plot_GenM.png");

  TCanvas *can12 = new TCanvas();
  hst_inv_mass_q1_q2->GetXaxis()->SetTitle("M Generator Quarks from W from H");
  hst_inv_mass_q1_q2->GetYaxis()->SetTitle("N Events");
  hst_inv_mass_q1_q2->SetTitle("M Quarks");
  hst_inv_mass_q1_q2->Draw();
  TLatex tex12(.4,.85,VetoString);
  tex12.SetTextSize(0.03);
  tex12.SetNDC(kTRUE);
  tex12.Draw();
  can12->SaveAs("1DDistPlots/plot_GenMQuark.png");

  TCanvas *can13 = new TCanvas();
  hst_inv_mass_jm1jm2->SetLineColor(kBlue);
  hst_inv_mass_jm1jm2->GetXaxis()->SetTitle("M Matched Jets");
  hst_inv_mass_jm1jm2->GetYaxis()->SetTitle("N Events");
  hst_inv_mass_jm1jm2->SetTitle("M Matched Jets");
  hst_inv_mass_jm1jm2->Draw();
  TLatex tex13(.4,.85,VetoString);
  tex13.SetTextSize(0.03);
  tex13.SetNDC(kTRUE);
  tex13.Draw();
  can13->SaveAs("1DDistPlots/plot_MatchedJetsM.png");

  TCanvas *can14 = new TCanvas();
  hst_Q1VsPt->SetLineColor(kBlue);
  hst_Q1MatchVsPt->SetLineColor(kRed);
  hst_Q1VsPt->GetXaxis()->SetTitle("Quark Pt");
  hst_Q1VsPt->GetYaxis()->SetTitle("N Events");
  hst_Q1VsPt->SetTitle("Leading Gen Quark Pt Distribution");
  hst_Q1VsPt->Draw();
  hst_Q1MatchVsPt->Draw("SAME");

  TLegend *leg14 = new TLegend(0.65,0.65,0.85,0.85);
  leg14->AddEntry(hst_Q1VsPt,"All Gen Quarks");
  leg14->AddEntry(hst_Q1MatchVsPt,"Matched Gen Quarks");
  leg14->Draw();
  can14->SaveAs("1DDistPlots/plot_Q1MatchesVsPt.png");

  TCanvas *can15 = new TCanvas();
  hst_Q2VsPt->SetLineColor(kBlue);
  hst_Q2MatchVsPt->SetLineColor(kRed);
  hst_Q2VsPt->GetXaxis()->SetTitle("Quark Pt");
  hst_Q2VsPt->GetYaxis()->SetTitle("N Events");
  hst_Q2VsPt->SetTitle("Sub-leading Gen Quark Pt Distribution");
  hst_Q2VsPt->Draw();
  hst_Q2MatchVsPt->Draw("SAME");

  TLegend *leg15 = new TLegend(0.65,0.65,0.85,0.85);
  leg15->AddEntry(hst_Q2VsPt,"All Gen Quarks");
  leg15->AddEntry(hst_Q2MatchVsPt,"Matched Gen Quarks");
  leg15->Draw();
  can15->SaveAs("1DDistPlots/plot_Q2MatchesVsPt.png");

  TCanvas *can16 = new TCanvas();
  hst_Q1EffVsPt->SetLineColor(kBlue);
  hst_Q2EffVsPt->SetLineColor(kRed);
  hst_Q1EffVsPt->GetXaxis()->SetTitle("Quark Pt");
  hst_Q1EffVsPt->GetYaxis()->SetTitle("Matching Efficiency");
  hst_Q1EffVsPt->GetYaxis()->SetRangeUser(0,1);
  hst_Q1EffVsPt->SetTitle("Quark Matching Efficiency");
  hst_Q1EffVsPt->Draw();
  hst_Q2EffVsPt->Draw("SAME");

  TLegend *leg16 = new TLegend(0.65,0.65,0.85,0.85);
  leg16->AddEntry(hst_Q1EffVsPt,"Leading Quark");
  leg16->AddEntry(hst_Q2EffVsPt,"Sub-leading Quark");
  leg16->Draw();
  can16->SaveAs("1DDistPlots/plot_QMatchEffVsPt.png");

  TCanvas *can17 = new TCanvas();
  hst_Q1VsEta->SetLineColor(kBlue);
  hst_Q1MatchVsEta->SetLineColor(kRed);
  hst_Q1VsEta->GetXaxis()->SetTitle("Quark Eta");
  hst_Q1VsEta->GetYaxis()->SetTitle("N Events");
  hst_Q1VsEta->SetTitle("Leading Gen Quark Eta Distribution");
  hst_Q1VsEta->Draw();
  hst_Q1MatchVsEta->Draw("SAME");

  TLegend *leg17 = new TLegend(0.65,0.65,0.85,0.85);
  leg17->AddEntry(hst_Q1VsEta,"All Gen Quarks");
  leg17->AddEntry(hst_Q1MatchVsEta,"Matched Gen Quarks");
  leg17->Draw();
  can17->SaveAs("1DDistPlots/plot_Q1MatchesVsEta.png");

  TCanvas *can18 = new TCanvas();
  hst_Q2VsEta->SetLineColor(kBlue);
  hst_Q2MatchVsEta->SetLineColor(kRed);
  hst_Q2VsEta->GetXaxis()->SetTitle("Quark Eta");
  hst_Q2VsEta->GetYaxis()->SetTitle("N Events");
  hst_Q2VsEta->SetTitle("Sub-leading Gen Quark Eta Distribution");
  hst_Q2VsEta->Draw();
  hst_Q2MatchVsEta->Draw("SAME");

  TLegend *leg18 = new TLegend(0.65,0.65,0.85,0.85);
  leg18->AddEntry(hst_Q2VsEta,"All Gen Quarks");
  leg18->AddEntry(hst_Q2MatchVsEta,"Matched Gen Quarks");
  leg18->Draw();
  can18->SaveAs("1DDistPlots/plot_Q2MatchesVsEta.png");

  TCanvas *can19 = new TCanvas();
  hst_Q1EffVsEta->SetLineColor(kBlue);
  hst_Q2EffVsEta->SetLineColor(kRed);
  hst_Q1EffVsEta->GetXaxis()->SetTitle("Quark Eta");
  hst_Q1EffVsEta->GetYaxis()->SetTitle("Matching Efficiency");
  hst_Q1EffVsEta->GetYaxis()->SetRangeUser(0,1);
  hst_Q1EffVsEta->SetTitle("Quark Matching Efficiency");
  hst_Q1EffVsEta->Draw();
  hst_Q2EffVsEta->Draw("SAME");

  TLegend *leg19 = new TLegend(0.65,0.65,0.85,0.85);
  leg19->AddEntry(hst_Q1EffVsEta,"Leading Quark");
  leg19->AddEntry(hst_Q2EffVsEta,"Sub-leading Quark");
  leg19->Draw();
  can19->SaveAs("1DDistPlots/plot_QMatchEffVsEta.png");

  TCanvas *can20 = new TCanvas();
  hst_closest2DPTResVsDr->SetStats(0);
  hst_closest2DPTResVsDr->GetXaxis()->SetTitle("PT Resolution");
  hst_closest2DPTResVsDr->GetYaxis()->SetTitle("Delta R");
  hst_closest2DPTResVsDr->SetTitle("Closest Jet");
  hst_closest2DPTResVsDr->Draw("colz");
  can20->SaveAs("1DDistPlots/plot_closest2DPTResVsDr.png");

  TCanvas *can21 = new TCanvas();
  hst_mjjVsdRjj->SetStats(0);
  hst_mjjVsdRjj->GetXaxis()->SetTitle("M_{jj}");
  hst_mjjVsdRjj->GetYaxis()->SetTitle("dR_{jj}");
  hst_mjjVsdRjj->SetTitle("Matched Jets");
  hst_mjjVsdRjj->Draw("colz");
  can21->SaveAs("1DDistPlots/plot_mjjVsdRjj.png");

  TCanvas *can22 = new TCanvas();
  hst_mqqVsdRqq->SetStats(0);
  hst_mqqVsdRqq->GetXaxis()->SetTitle("M_{qq}");
  hst_mqqVsdRqq->GetYaxis()->SetTitle("dR_{qq}");
  hst_mqqVsdRqq->SetTitle("Gen Quarks");
  hst_mqqVsdRqq->Draw("colz");
  can22->SaveAs("1DDistPlots/plot_mqqVsdRqq.png");

  TCanvas *can23 = new TCanvas();
  hst_mHrightlep->GetXaxis()->SetTitle("M(q,q,l)");
  hst_mHrightlep->GetYaxis()->SetTitle("N Events");
  hst_mHrightlep->SetTitle("Visible M for Right & Wrong Lepton");
  hst_mHwronglep->SetLineColor(kRed);
  hst_mHrightlep->Draw();
  hst_mHwronglep->Draw("SAME");

  TLegend *leg23 = new TLegend(0.65,0.65,0.85,0.85);
  leg23->AddEntry(hst_mHrightlep,"Gen Quarks + Correct Lepton");
  leg23->AddEntry(hst_mHwronglep,"Gen Quarks + Wrong Lepton");
  leg23->Draw();
  can23->SaveAs("1DDistPlots/plot_mHRightWrongLepton.png");

  TCanvas *can24 = new TCanvas();
  hst_HadTopPt->GetXaxis()->SetTitle("Pt");
  hst_HadTopPt->GetYaxis()->SetTitle("N Events");
  hst_HadTopPt->SetTitle("Hadronic Top Pt");
  hst_HadTopPt->GetYaxis()->SetRangeUser(0,1500);
  hst_HadTopPt->SetLineColor(kRed);
  hst_HadTopPt->Draw();
  hst_htt_PtTop->Draw("SAME");

  TLegend *leg24 = new TLegend(0.65,0.65,0.85,0.85);
  leg24->AddEntry(hst_htt_PtTop,"Reco");
  leg24->AddEntry(hst_HadTopPt,"Gen");
  leg24->Draw();
  can24->SaveAs("1DDistPlots/plot_zzHadTopPtRecoGen.png");

  TCanvas *can25 = new TCanvas();
  hst_HadTopM->GetXaxis()->SetTitle("M");
  hst_HadTopM->GetYaxis()->SetTitle("N Events");
  hst_HadTopM->SetTitle("Hadronic Top M");
  hst_HadTopM->SetLineColor(kRed);
  hst_HadTopM->Draw();
  hst_htt_MTop->Draw("SAME");

  TLegend *leg25 = new TLegend(0.65,0.65,0.85,0.85);
  leg25->AddEntry(hst_htt_MTop,"Reco");
  leg25->AddEntry(hst_HadTopM,"Gen");
  leg25->Draw();
  can25->SaveAs("1DDistPlots/plot_zzHadTopMRecoGen.png");

  TCanvas *can26 = new TCanvas();
  hst_recogen_PtTop->GetXaxis()->SetTitle("Reco");
  hst_recogen_PtTop->GetYaxis()->SetTitle("Gen");
  hst_recogen_PtTop->SetTitle("HTT Reconstructed vs Generator Hadronic Top Pt");
  hst_recogen_PtTop->Draw("colz");
  can26->SaveAs("1DDistPlots/plot_zzrecogen_PtTop_2D.png");

  TCanvas *can27 = new TCanvas();
  hst_htt_PtWFromTop->GetXaxis()->SetTitle("Pt");
  hst_htt_PtWFromTop->GetYaxis()->SetTitle("N Events");
  hst_htt_PtWFromTop->SetTitle("W From Hadronic Top Pt");
  hst_htt_PtWFromTop->GetYaxis()->SetRangeUser(0,3000);
  hst_WFromHadTopPt->SetLineColor(kRed);
  hst_HadWFromHPt->SetLineColor(kGreen+2);
  hst_htt_PtWFromTop->Draw();
  hst_WFromHadTopPt->Draw("SAME");
  hst_HadWFromHPt->Draw("SAME");

  TLegend *leg27 = new TLegend(0.65,0.65,0.85,0.85);
  leg27->AddEntry(hst_htt_PtWFromTop,"Pt From non-B HTT Jets");
  leg27->AddEntry(hst_WFromHadTopPt,"W From Hadronic Top");
  leg27->AddEntry(hst_HadWFromHPt,"Hadronic W From Higgs");
  leg27->Draw();
  can27->SaveAs("1DDistPlots/plot_zzWFromHadTopPt.png");

  TCanvas *can28 = new TCanvas();
  hst_htt_MWFromTop->GetXaxis()->SetTitle("M");
  hst_htt_MWFromTop->GetYaxis()->SetTitle("N Events");
  hst_htt_MWFromTop->SetTitle("W From Hadronic Top M");
  hst_htt_MWFromTop->GetYaxis()->SetRangeUser(0,7000);
  hst_WFromHadTopM->SetLineColor(kRed);
  hst_HadWFromHM->SetLineColor(kGreen+2);
  hst_htt_MWFromTop->Draw();
  hst_WFromHadTopM->Draw("SAME");
  hst_HadWFromHM->Draw("SAME");

  TLegend *leg28 = new TLegend(0.65,0.65,0.85,0.85);
  leg28->AddEntry(hst_htt_MWFromTop,"M From non-B HTT Jets");
  leg28->AddEntry(hst_WFromHadTopM,"W From Hadronic Top");
  leg28->AddEntry(hst_HadWFromHM,"Hadronic W From Higgs");
  leg28->Draw();
  can28->SaveAs("1DDistPlots/plot_zzWFromHadTopM.png");

  TCanvas *can29 = new TCanvas();
  hst_NSelectedMatchesVsNJetFrac->GetXaxis()->SetTitle("N Jets");
  hst_NSelectedMatchesVsNJetFrac->GetYaxis()->SetTitle("Fraction");
  hst_NSelectedMatchesVsNJetFrac->SetTitle("(H->WW->qqlnu NEvents w/ 2 quarks matched)/(H->WW->qqlnu NEvents)");
  hst_NSelectedMatchesVsNJetFrac->GetYaxis()->SetRangeUser(0,1.2);
  hst_NSelectedMatchesVsNJetFrac->SetLineColor(kRed);
  hst_NSelectedMatchesVsNJetFrac->Draw();
  can29->SaveAs("1DDistPlots/plot_NSelectedMatchesVsNJetFrac.png");

  TCanvas *can30 = new TCanvas();
  hst_HadTop_2leps_delr->GetXaxis()->SetTitle("DelR(RightLepton,HadronicTop");
  hst_HadTop_2leps_delr->GetYaxis()->SetTitle("DelR(WrongLepton,HadronicTop");
  hst_HadTop_2leps_delr->SetTitle("DelR Hadronic Tops & Lepton");
  hst_HadTop_2leps_delr->Draw("colz");
  can30->SaveAs("1DDistPlots/plot_HadTop_2leps_delr.png");

  TCanvas *can31 = new TCanvas();
  hst_visRecoVsGen->GetXaxis()->SetTitle("Visible Reco Pt");
  hst_visRecoVsGen->GetYaxis()->SetTitle("Visible Gen Pt");
  hst_visRecoVsGen->SetTitle("Reco Vs Gen Visible Pt");
  hst_visRecoVsGen->Draw("colz");
  can31->SaveAs("1DDistPlots/plot_visRecoVsGen.png");

  TCanvas *can32 = new TCanvas();
  hst_lepDeltaPtRight->SetLineColor(kBlue);
  hst_lepDeltaPtWrong->SetLineColor(kRed);
  hst_lepDeltaPtRight->GetXaxis()->SetTitle("Delta Pt");
  hst_lepDeltaPtRight->GetYaxis()->SetTitle("Event Fraction");
  hst_lepDeltaPtRight->SetTitle("Delta Pt in Leptons");
  hst_lepDeltaPtRight->Draw("HIST");
  hst_lepDeltaPtWrong->Draw("HIST SAME");

  TLegend *leg32 = new TLegend(0.65,0.65,0.85,0.85);
  leg32->AddEntry(hst_lepDeltaPtRight,"Closest Lepton is Right");
  leg32->AddEntry(hst_lepDeltaPtWrong,"Closest Lepton is Wrong");
  leg32->Draw();
  can32->SaveAs("1DDistPlots/plot_lepDeltaPt.png");
  cout << "hst_lepDeltaPtRight: " << hst_lepDeltaPtRight->GetEntries() << endl;
  cout << "hst_lepDeltaPtWrong: " << hst_lepDeltaPtWrong->GetEntries() << endl;

  TCanvas *can33 = new TCanvas();
  hst_lepPtResRight->SetLineColor(kBlue);
  hst_lepPtResWrong->SetLineColor(kRed);
  hst_lepPtResRight->GetXaxis()->SetTitle("Delta Pt / Mean Pt");
  hst_lepPtResRight->GetYaxis()->SetTitle("Event Fraction");
  hst_lepPtResRight->SetTitle("PtRes in Leptons");
  hst_lepPtResRight->Draw("HIST");
  hst_lepPtResWrong->Draw("HIST SAME");

  TLegend *leg33 = new TLegend(0.65,0.65,0.85,0.85);
  leg33->AddEntry(hst_lepPtResRight,"Softest Lepton is Right");
  leg33->AddEntry(hst_lepPtResWrong,"Softest Lepton is Wrong");
  leg33->Draw();
  can33->SaveAs("1DDistPlots/plot_lepPtRes.png");
  
  TCanvas *can34 = new TCanvas();
  hst_LJDeltaRRight->SetLineColor(kBlue);
  hst_LJDeltaRWrong->SetLineColor(kRed);
  hst_LJDeltaRRight->GetXaxis()->SetTitle("Delta R Jet-Lep");
  hst_LJDeltaRRight->GetYaxis()->SetTitle("Event Fraction");
  hst_LJDeltaRRight->SetTitle("DelR(l,j)");
  hst_LJDeltaRRight->Draw("HIST");
  hst_LJDeltaRWrong->Draw("HIST SAME");

  TLegend *leg34 = new TLegend(0.65,0.65,0.85,0.85);
  leg34->AddEntry(hst_LJDeltaRRight,"Closest Lepton is Right");
  leg34->AddEntry(hst_LJDeltaRWrong,"Closest Lepton is Wrong");
  leg34->Draw();
  can34->SaveAs("1DDistPlots/plot_LJDeltaR.png");
  cout << "hst_LJDeltaRRight: " << hst_LJDeltaRRight->GetEntries() << endl;
  cout << "hst_LJDeltaRWrong: " << hst_LJDeltaRWrong->GetEntries() << endl;

  TCanvas *can35 = new TCanvas();
  hst_lepDeltaPtRight_Conflict->SetLineColor(kBlue);
  hst_lepDeltaPtWrong_Conflict->SetLineColor(kRed);
  hst_lepDeltaPtRight_Conflict->GetXaxis()->SetTitle("Delta Pt");
  hst_lepDeltaPtRight_Conflict->GetYaxis()->SetTitle("Event Fraction");
  hst_lepDeltaPtRight_Conflict->SetTitle("Delta Pt in Leptons (Conflict)");
  hst_lepDeltaPtRight_Conflict->Draw("HIST");
  hst_lepDeltaPtWrong_Conflict->Draw("HIST SAME");

  TLegend *leg35 = new TLegend(0.65,0.65,0.85,0.85);
  leg35->AddEntry(hst_lepDeltaPtRight_Conflict,"Closest Lepton is Right");
  leg35->AddEntry(hst_lepDeltaPtWrong_Conflict,"Closest Lepton is Wrong");
  leg35->Draw();
  can35->SaveAs("1DDistPlots/plot_lepDeltaPt_Conflict.png");
  cout << "hst_lepDeltaPtRight_Conflict: " << hst_lepDeltaPtRight_Conflict->GetEntries() << endl;
  cout << "hst_lepDeltaPtWrong_Conflict: " << hst_lepDeltaPtWrong_Conflict->GetEntries() << endl;

  TCanvas *can36 = new TCanvas();
  hst_lepPtResRight_Conflict->SetLineColor(kBlue);
  hst_lepPtResWrong_Conflict->SetLineColor(kRed);
  hst_lepPtResRight_Conflict->GetXaxis()->SetTitle("Delta Pt / Mean Pt");
  hst_lepPtResRight_Conflict->GetYaxis()->SetTitle("Event Fraction");
  hst_lepPtResRight_Conflict->SetTitle("PtRes in Leptons (Conflict)");
  hst_lepPtResRight_Conflict->GetYaxis()->SetRangeUser(0,500);
  hst_lepPtResRight_Conflict->Draw("HIST");
  hst_lepPtResWrong_Conflict->Draw("HIST SAME");

  TLegend *leg36 = new TLegend(0.65,0.65,0.85,0.85);
  leg36->AddEntry(hst_lepPtResRight_Conflict,"Softest Lepton is Right");
  leg36->AddEntry(hst_lepPtResWrong_Conflict,"Softest Lepton is Wrong");
  leg36->Draw();
  can36->SaveAs("1DDistPlots/plot_lepPtRes_Conflict.png");
  
  TCanvas *can37 = new TCanvas();
  hst_LJDeltaRRight_Conflict->SetLineColor(kBlue);
  hst_LJDeltaRWrong_Conflict->SetLineColor(kRed);
  hst_LJDeltaRRight_Conflict->GetXaxis()->SetTitle("Delta R Jet-Lep");
  hst_LJDeltaRRight_Conflict->GetYaxis()->SetTitle("Event Fraction");
  hst_LJDeltaRRight_Conflict->SetTitle("DelR(l,j) (Conflict)");
  hst_LJDeltaRRight_Conflict->Draw("HIST");
  hst_LJDeltaRWrong_Conflict->Draw("HIST SAME");

  TLegend *leg37 = new TLegend(0.65,0.65,0.85,0.85);
  leg37->AddEntry(hst_LJDeltaRRight_Conflict,"Closest Lepton is Right");
  leg37->AddEntry(hst_LJDeltaRWrong_Conflict,"Closest Lepton is Wrong");
  leg37->Draw();
  can37->SaveAs("1DDistPlots/plot_LJDeltaR_Conflict.png");
  cout << "hst_LJDeltaRRight_Conflict: " << hst_LJDeltaRRight_Conflict->GetEntries() << endl;
  cout << "hst_LJDeltaRWrong_Conflict: " << hst_LJDeltaRWrong_Conflict->GetEntries() << endl;
}
