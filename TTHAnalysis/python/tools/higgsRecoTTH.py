from __future__ import division
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module 
from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection as NanoAODCollection
from CMGTools.TTHAnalysis.tools.nanoAOD.friendVariableProducerTools import declareOutput, writeOutput
from CMGTools.TTHAnalysis.treeReAnalyzer import Collection as CMGCollection
import ROOT, itertools
from math import *
import sys
from PhysicsTools.Heppy.physicsobjects.Jet import _btagWPs as HiggsRecoTTHbtagwps

class HiggsRecoTTH(Module):
    def __init__(self,label="_Recl",cut_BDT_rTT_score = 0.0, cuts_mW_had = (50.,110.), cuts_mH_vis = (90.,130.), btagDeepCSVveto = 'L', doSystJEC=False, useTopTagger=True, debug=False):
        self.debug = debug
        self.useTopTagger = useTopTagger
        self.label = label
        self.branches = []
        self.systsJEC = {0:"", 1:"_jesTotalCorrUp", -1:"_jesTotalCorrDown"} if doSystJEC else {0:""}
        for var in self.systsJEC: self.branches.extend(["Hreco_%s%s"%(x,self.systsJEC[var]) for x in [
            #reconstruction loop dependent vars
            "minDRlj","delR_H_j1j2","visHmass","Wmass","lepIdx","j1Idx","j2Idx",
            "pTVisPlusNu","pTHvis","pTVis_jets_match","MVis_jets_match","M_jets_match",
            "nmatchedleptons","nmatchedpartons","nmismatchedtoptaggedjets","delR_H_j1l_reco",
            "delR_H_j2l_reco","maxdR","mindR","maxdRW","mindRW","PtTop_recohtt","MTop_recohtt","PtWFromTop_recohtt","MWFromTop_recohtt","WFromTop_rightlep_delr","WFromTop_wronglep_delr",
            "minDRlj_correct","delR_H_j1j2_correct","visHmass_correct","Wmass_correct","lepIdx_correct","j1Idx_correct","j2Idx_correct",
            "pTVisPlusNu_correct","pTHvis_correct","delR_H_j1l_reco_correct","delR_H_j2l_reco_correct","maxdR_correct","mindR_correct","maxdRW_correct","mindRW_correct",
            #delR and closest jet vars
            "delR_H_partons","delR_H_q1l","delR_H_q2l",
            "closestJetInDelR_pt_ToQ1FromWFromH","closestJetInDelR_pt_ToQ2FromWFromH",
            "closestJetInDelR_ptres_ToQ1FromWFromH","closestJetInDelR_ptres_ToQ2FromWFromH",
            "closestJetInDelR_delR_ToQ1FromWFromH","closestJetInDelR_delR_ToQ2FromWFromH",
            "closestJetInDelR_flavour_ToQ1FromWFromH","closestJetInDelR_flavour_ToQ2FromWFromH",
            "closestJetInPTRes_pt_ToQ1FromWFromH","closestJetInPTRes_pt_ToQ2FromWFromH",
            "closestJetInPTRes_ptres_ToQ1FromWFromH","closestJetInPTRes_ptres_ToQ2FromWFromH",
            "closestJetInPTRes_delR_ToQ1FromWFromH","closestJetInPTRes_delR_ToQ2FromWFromH",
            "closestJetInPTRes_flavour_ToQ1FromWFromH","closestJetInPTRes_flavour_ToQ2FromWFromH",
            #lists from gen loop
            "nWFromH","nQFromWFromH","nLFromWFromH","nQFromWFromT","nLFromWFromT",
            "nNuFromWFromH","nNuFromWFromT","nZFromH","nQFromZFromH","nLFromZFromH","nNuFromZFromH",
            "nTauFromH","nPiFromTauFromH","nLFromTauFromH","nNuFromTauFromH","nTNuFromTauFromH","nKaFromTauFromH",
            "nLFromTauFromWFromH","nhFromTauFromWFromH","nTauFromWFromH","nFO","nLeptonicTops","nHadTop","nJetsInCollection",
            #kinematics of gen-level objects and matched objects
            "pTTrueGen","MTrueGen","pTTrueGenPlusNu","pTGenQuarks","dRGenQuarks","MGenQuarks",
            "pTtgen","pTHgen","quark1pT","quark2pT","quark1Eta","quark2Eta","quark1Flavour","quark2Flavour",
            "jet_matches_quark1_delr","jet_matches_quark2_delr",
            "jet_matches_quark1_ptres","jet_matches_quark2_ptres",
            "bestRank","matchRank","mHRightLepton","mHWrongLepton",
            "HadTopPt","HadTopM","WFromHadTopPt","WFromHadTopM","WFromHiggsPt","WFromHiggsM"]])

        for mylep in [0, 1]:
            for var in self.systsJEC: self.branches.extend(["Hreco_%s%s"%(x,self.systsJEC[var]) for x in [
                "l%s_fj_deltaR"%mylep, "l%s_fj_lepIsFromH"%mylep,"l%s_fj_pt"%mylep,"l%s_fj_eta"%mylep,
                                                                                                          
                "l%s_fj_phi"%mylep,"l%s_fj_mass"%mylep,"l%s_fj_msoftdrop"%mylep,"l%s_fj_tau1"%mylep,
                                                                                                          
                "l%s_fj_tau2"%mylep,"l%s_fj_tau3"%mylep,"l%s_fj_tau4"%mylep]])

        self.cut_BDT_rTT_score = cut_BDT_rTT_score
        self.cuts_mW_had = cuts_mW_had
        self.cuts_mH_vis = cuts_mH_vis
        self.btagDeepCSVveto = btagDeepCSVveto


    # old interface
    def listBranches(self):
        return self.branches
    def __call__(self,event):
        return self.run(event,CMGCollection)

    # new interface
    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        declareOutput(self,wrappedOutputTree, self.branches)
    def analyze(self, event):
        writeOutput(self, self.run(event, NanoAODCollection))
        return True
    # code
    def run(self,event,Collection):

        year=getattr(event,"year")
        if (self.btagDeepCSVveto != 99) : 
            btagvetoval = HiggsRecoTTHbtagwps["DeepFlav_%d_%s"%(year,self.btagDeepCSVveto)][1]
        else :
            btagvetoval = self.btagDeepCSVveto
#        btagvetoval = HiggsRecoTTHbtagwps["DeepFlav_%d_%s"%(year,'T')][1]
#        print ("btagvetoval: " + str(btagvetoval))
        # L = 0.0614
        # M = 0.3093
        # T = 0.7221
        statusFlagsMap = {
          # Comments taken from:
          # DataFormats/HepMCCandidate/interface/GenParticle.h
          # PhysicsTools/HepMCCandAlgos/interface/MCTruthHelper.h
          #
          # Nomenclature taken from:
          # PhysicsTools/NanoAOD/python/genparticles_cff.py
          #
          #TODO: use this map in other gen-lvl particle selectors as well:
          # GenLepFromTauFromTop -> isDirectPromptTauDecayProduct &&
          #                         isDirectHardProcessTauDecayProduct &&
          #                         isLastCopy &&
          #                         ! isDirectHadronDecayProduct
          # GenLepFromTau -> isDirectTauDecayProduct (or isDirectPromptTauDecayProduct?) &&
          #                  isLastCopy &&
          #                  ! isDirectHadronDecayProduct
          #                  (&& maybe isHardProcessTauDecayProduct?)
          # GenLepFromTop -> isPrompt &&
          #                  isHardProcess &&
          #                  (isLastCopy || isLastCopyBeforeFSR) &&
          #                  ! isDirectHadronDecayProduct
          #
          # Not sure whether to choose (isLastCopy or isLastCopyBeforeFSR) or just isFirstCopy:
          # GenWZQuark, GenHiggsDaughters, GenVbosons
          #
          # Not sure what to require from GenTau
          'isPrompt'                           : 0,  # any decay product NOT coming from hadron, muon or tau decay
          'isDecayedLeptonHadron'              : 1,  # a particle coming from hadron, muon, or tau decay
                                                     # (does not include resonance decays like W,Z,Higgs,top,etc)
                                                     # equivalent to status 2 in the current HepMC standard
          'isTauDecayProduct'                  : 2,  # a direct or indirect tau decay product
          'isPromptTauDecayProduct'            : 3,  # a direct or indirect decay product of a prompt tau
          'isDirectTauDecayProduct'            : 4,  # a direct tau decay product
          'isDirectPromptTauDecayProduct'      : 5,  # a direct decay product from a prompt tau
          'isDirectHadronDecayProduct'         : 6,  # a direct decay product from a hadron
          'isHardProcess'                      : 7,  # part of the hard process
          'fromHardProcess'                    : 8,  # the direct descendant of a hard process particle of the same pdg id
          'isHardProcessTauDecayProduct'       : 9,  # a direct or indirect decay product of a tau from the hard process
          'isDirectHardProcessTauDecayProduct' : 10, # a direct decay product of a tau from the hard process
          'fromHardProcessBeforeFSR'           : 11, # the direct descendant of a hard process particle of the same pdg id
                                                     # for outgoing particles the kinematics are those before QCD or QED FSR
          'isFirstCopy'                        : 12, # the first copy of the particle in the chain with the same pdg id
          'isLastCopy'                         : 13, # the last copy of the particle in the chain with the same pdg id
                                                     # (and therefore is more likely, but not guaranteed,
                                                     # to carry the final physical momentum)
          'isLastCopyBeforeFSR'                : 14, # the last copy of the particle in the chain with the same pdg id
                                                     # before QED or QCD FSR (and therefore is more likely,
                                                     # but not guaranteed, to carry the momentum after ISR;
                                                     # only really makes sense for outgoing particles
        }
        # Return dictionary 
        ret      = {} 
        genpar = Collection(event,"GenPart","nGenPart") 
        closestFatJetToLeptonVars = []
        Higgses=[]
        QFromW=[]
        LFromW=[]
        tauFromW=[]
        WFromH=[]
        ZFromH=[]
        TauFromH=[]
        PiFromTauFromH=[]
        LFromTauFromH=[]
        NuFromTauFromH=[]
        TNuFromTauFromH=[]
        KaFromTauFromH=[]
        LFromTauFromWFromH=[]
        hFromTauFromWFromH=[]
        WFromT=[]
        QFromWFromH  = [] 
        LFromWFromH  = [] 
        QFromZFromH  = [] 
        LFromZFromH  = [] 
        QFromWFromT  = [] 
        LFromWFromT  = [] 
        NuFromWFromH = [] 
        NuFromWFromT = [] 
        TauFromWFromH = [] 
        NuFromZFromH = [] 
        genlep=[]
        #closestJetInDelRToQFromWFromH=[]
        tfromhardprocess=[]
        leptonictops=[]
        nmatchedpartons           = -99
        nbothmatchedpartons       = -99 
        nmismatchedtoptaggedjets  = -99
        nmatchedleptons           = -99
        pTH              = -99
        pTHgen           = -99
        pTtgen           = -99
        pTVisPlusNu      = -99
        pTTrueGen        = -99
        MTrueGen         = -99
        pTTrueGenplusNu  = -99
        pTGenQuarks      = -99
        dRGenQuarks      = -99
        MGenQuarks       = -99
        pTVis_jets_match = -99
        MVis_jets_match  = -99
        M_jets_match     = -99
        closestJetInDelR_pt_ToQFromWFromH       =   [-99    ,-99]
        closestJetInDelR_ptres_ToQFromWFromH    =   [-99    ,-99]
        closestJetInDelR_delR_ToQFromWFromH     =   [-99    ,-99]
        closestJetInDelR_flavour_ToQFromWFromH  =   [-99    ,-99]
        closestJetInPTRes_pt_ToQFromWFromH      =   [-99    ,-99]
        closestJetInPTRes_ptres_ToQFromWFromH   =   [-99    ,-99]
        closestJetInPTRes_delR_ToQFromWFromH    =   [-99    ,-99]
        closestJetInPTRes_flavour_ToQFromWFromH =   [-99    ,-99]
        quarkpTinQFromWFromH                    =   [-99    ,-99]
        quarkEtainQFromWFromH                   =   [-99    ,-99]
        quarkFlavourinQFromWFromH               =   [-99    ,-99]
        jets_match_quarks_delr                  =   [-99    ,-99]
        jets_match_quarks_ptres                 =   [-99    ,-99]
        #massHgen = 0
        #deltaM_trueGen_H = 0
        delR_H_partons      = -99
        delR_H_j1j2         = -99
        delR_H_q1l          = -99
        delR_H_q2l          = -99
        delR_H_j1l_reco     = -99
        delR_H_j2l_reco     = -99
        delpT_recovis_genvis = -99
        
        # higgs
        for part in genpar:
            if part.pdgId == 25 and part.statusFlags &(1 << statusFlagsMap['isHardProcess']):
                Higgses.append(part)
                #TODO: consider the pt of the stxs higgs
                pTH = part.p4()
                pTHgen = part.p4().Pt() 
        #if len(Higgses)>1:
            #sys.exit("error: more than one higgs!")
        # tops
        for part in genpar:
             if abs(part.pdgId) == 6 and part.statusFlags &(1 << statusFlagsMap['isHardProcess']):
                 tfromhardprocess.append(part)
                 pTtgen = part.p4().Pt()
        #if len(tfromhardprocess)!=2:
            #sys.exit("error: not only two hard tops!")

        if False:        
            # W from higgs
            for part in genpar:
                if (abs(part.pdgId) == 24 and part.statusFlags &(1 << statusFlagsMap['isHardProcess'])
                        and part.genPartIdxMother >= 0 and  genpar[part.genPartIdxMother].pdgId == 25 ):
                    if self.debug: print "it is a hard W coming from a Higgs"
                    WFromH.append(part)
        if False:
            # Z from higgs
            for part in genpar:
                if (abs(part.pdgId) == 23 and part.statusFlags &(1 << statusFlagsMap['isHardProcess'])
                        and part.genPartIdxMother >= 0 and  genpar[part.genPartIdxMother].pdgId == 25 ):
                    if self.debug: print "it is a hard Z coming from a Higgs"
                    ZFromH.append(part)
        if False:
            # Tau from higgs
            for part in genpar:
                if (abs(part.pdgId) == 15 and part.statusFlags &(1 << statusFlagsMap['isHardProcess'])
                        and part.genPartIdxMother >= 0 and  genpar[part.genPartIdxMother].pdgId == 25 ):
                    if self.debug: print "it is a hard Tau coming from a Higgs"
                    TauFromH.append(part)
        if True:    
            # W from tops 
            for part in genpar:
                if (abs(part.pdgId) == 24 and part.statusFlags &(1 << statusFlagsMap['isHardProcess'])
                        and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 6):
                    if self.debug: print "it is a hard W coming from a top"
                    WFromT.append(part)
            #if len(tfromhardprocess) == 2 and len(WFromT) != 2:
                #sys.exit("error: you don't have exactly two W's from the two hard tops!")
        if False:    
            # W decays to quarks
            for part in genpar:
                if (abs(part.pdgId) in [1,2,3,4,5,6] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24): 
                    if self.debug: print "it is a quark coming from a W"
                    QFromW.append(part)
        if False:    
            # gen leptons
            for part in genpar:
                if (abs(part.pdgId) in [11,13] and part.status == 1 and part.statusFlags &(1 << statusFlagsMap['isLastCopy']) and not part.statusFlags &(1 << statusFlagsMap['isDirectHadronDecayProduct'])):
                    if part.statusFlags &(1 << statusFlagsMap['isPrompt']) or part.statusFlags &(1 << statusFlagsMap['isDirectPromptTauDecayProduct']):
                        #print (genpar[part.genPartIdxMother].pdgId)
                        if self.debug: print "it is a prompt lepton"
                        genlep.append(part)
        if False:    
            # gen leptons from W
            for part in genpar:
                if (abs(part.pdgId) in [11,13] and part.status == 1 and part.statusFlags &(1 << statusFlagsMap['isLastCopy']) and not part.statusFlags &(1 << statusFlagsMap['isDirectHadronDecayProduct'])):
                    if part.statusFlags &(1 << statusFlagsMap['isPrompt']) or part.statusFlags &(1 << statusFlagsMap['isDirectPromptTauDecayProduct']):
                        if part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24: 
                            if self.debug: print "it is a prompt lepton"
                            LFromW.append(part)
    
        if True:    
            # neutrinos from W from H
            for part in genpar:
                if abs(part.pdgId) in [12, 14]:
                    if self.debug: print "it is a neutrino"
                    #print ("mother of neutrino is " + str(genpar[part.genPartIdxMother].pdgId))
                    #print ("grand mother is " + str(abs(genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId)))
                    if part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24: 
                        if self.debug: print "the mother of this neutrino is W+ or W-"
                        if abs(genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId) == 25:
                            if self.debug: print "the mother of this W is a Higgs"
                            NuFromWFromH.append(part)

        if False:
            # neutrinos from Z from H
            for part in genpar:
                if abs(part.pdgId) in [12, 14]:
                    if self.debug: print "it is a neutrino"
                    #print ("mother of neutrino is " + str(genpar[part.genPartIdxMother].pdgId))
                    #print ("grand mother is " + str(abs(genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId)))
                    if part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 23:
                        if self.debug: print "the mother of this neutrino is Z"
                        if abs(genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId) == 25:
                            if self.debug: print "the mother of this Z is a Higgs"
                            NuFromZFromH.append(part)

        if False:    
            for part in genpar:
                if abs(part.pdgId) in [12, 14]:
                    if self.debug: print "it is a neutrino"
                    if part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24: 
                        if self.debug: print "the mother of this neutrino is W+ or W-"
                        if abs(genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId) == 6:
                            if self.debug: print "the mother of this W is a top"
                            NuFromWFromT.append(part)

        if True:            
            # quarks from W from H
            for part in genpar:
                if (abs(part.pdgId) in [1,2,3,4,5,6] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24
                         and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                    if self.debug: print "it is a quark coming from a hard W"
                    if (genpar[genpar[part.genPartIdxMother].genPartIdxMother].genPartIdxMother >= 0 and genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId == 25
                            and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                        if self.debug: print "the mother of this hard W is a hard Higgs"
                        QFromWFromH.append(part)

        if False:
            # quarks from Z from H
            for part in genpar:
                if (abs(part.pdgId) in [1,2,3,4,5,6] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 23
                         and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                    if self.debug: print "it is a quark coming from a hard Z"
                    if (genpar[genpar[part.genPartIdxMother].genPartIdxMother].genPartIdxMother >= 0 and genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId == 25
                            and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                        if self.debug: print "the mother of this hard Z is a hard Higgs"
                        QFromZFromH.append(part)

        if False:
            # quarks from W from T 
            for part in genpar:
                if (abs(part.pdgId) in [1,2,3,4,5,6] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24 
                         and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                    if self.debug: print "it is a quark coming from a hard W"
                    if (genpar[genpar[part.genPartIdxMother].genPartIdxMother].genPartIdxMother >= 0 and abs(genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId) == 6
                            and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                        if self.debug: print "the mother of this hard W is a hard top"
                        QFromWFromT.append(part)

        if True:
            # leptons (excl. taus) from W from H 
            for part in genpar:
                if (abs(part.pdgId) in [11,13] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24 
                         and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                    if self.debug: print "it is a lepton coming from a hard W"
                    if (genpar[genpar[part.genPartIdxMother].genPartIdxMother].genPartIdxMother >= 0 and genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId == 25 
                            and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                        if self.debug: print "the mother of this hard W is a hard Higgs"
                        LFromWFromH.append(part)

        if True:
            # taus from W from H
            for part in genpar:
                if (abs(part.pdgId) in [15] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24):
                    if self.debug: print "it is a tau coming from a hard W"
                    if (genpar[part.genPartIdxMother].genPartIdxMother >= 0 and genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId == 25):
                        if self.debug: print "the mother of this hard W is a hard Higgs"
                        TauFromWFromH.append(part)

        if False:
            # leptons (excl. taus) from Z from H
            for part in genpar:
                if (abs(part.pdgId) in [11,13] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 23
                         and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                    if self.debug: print "it is a lepton coming from a hard Z"
                    if (genpar[genpar[part.genPartIdxMother].genPartIdxMother].genPartIdxMother >= 0 and genpar[genpar[part.genPartIdxMother].genPartIdxMother].pdgId == 25
                            and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                        if self.debug: print "the mother of this hard Z is a hard Higgs"
                        LFromZFromH.append(part)

        if True:
            # leptons (excl. taus) from W from top
            for part in genpar:
                if (abs(part.pdgId) in [11,13] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24):
                    mpart = genpar[part.genPartIdxMother]
                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 24):
                        mpart = genpar[mpart.genPartIdxMother]
                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 6):
                        mpart = genpar[mpart.genPartIdxMother]
                    if abs(mpart.pdgId) == 6:
                        LFromWFromT.append(part)
                        leptonictops.append(mpart)

        if False:
            # pions from Tau from H
            for part in genpar:
                if (abs(part.pdgId) in [111,211] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 15):
                    mpart = genpar[part.genPartIdxMother]
                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 15):
                        mpart = genpar[mpart.genPartIdxMother]
                    if (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 25):
                        PiFromTauFromH.append(part)

        if False:
            # leptons from Tau from H
            for part in genpar:
                if (abs(part.pdgId) in [11,13] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 15):
                    mpart = genpar[part.genPartIdxMother]
                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 15): mpart = genpar[mpart.genPartIdxMother]
                    if (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 25):
                        LFromTauFromH.append(part)

        if False:
            # m/e neutrinos from Tau from H
            for part in genpar:
                if (abs(part.pdgId) in [12,14] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 15):
                    mpart = genpar[part.genPartIdxMother]
                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 15): mpart = genpar[mpart.genPartIdxMother]
                    if (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 25):
                        NuFromTauFromH.append(part)

        if False:
            # tau neutrinos from Tau from H
            for part in genpar:
                if (abs(part.pdgId) in [16] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 15):
                    mpart = genpar[part.genPartIdxMother]
                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 15): mpart = genpar[mpart.genPartIdxMother]
                    if (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 25):
                        TNuFromTauFromH.append(part)

        if False:
            # kaons from Tau from H
            for part in genpar:
                if (abs(part.pdgId) in [311,321] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 15):
                    mpart = genpar[part.genPartIdxMother]
                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 15): mpart = genpar[mpart.genPartIdxMother]
                    if (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 25):
                        KaFromTauFromH.append(part)

        if True:
            # leptons from tau from W from H
            for part in genpar:
                if (abs(part.pdgId) in [11,13] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 15):
                    mpart = genpar[part.genPartIdxMother]
                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 15): mpart = genpar[mpart.genPartIdxMother]
                    if (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 24
                            and genpar[mpart.genPartIdxMother].genPartIdxMother >= 0
                            and abs(genpar[genpar[mpart.genPartIdxMother].genPartIdxMother].pdgId) == 25):
                        LFromTauFromWFromH.append(part)

        if True:
            # pions / kaons from tau from W from H
            for part in genpar:
                if (abs(part.pdgId) in [111,211,311,321] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 15):
                    mpart = genpar[part.genPartIdxMother]
                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 15): mpart = genpar[mpart.genPartIdxMother]
                    if (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 24
                            and genpar[mpart.genPartIdxMother].genPartIdxMother >= 0
                            and abs(genpar[genpar[mpart.genPartIdxMother].genPartIdxMother].pdgId) == 25):
                        hFromTauFromWFromH.append(part)

#        if True:
#            # pions / kaons from tau from W from H
#            for part in genpar:
#                if (part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 15):
#                    mpart = genpar[part.genPartIdxMother]
#                    while (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 15): mpart = genpar[mpart.genPartIdxMother]
#                    if (mpart.genPartIdxMother >= 0 and abs(genpar[mpart.genPartIdxMother].pdgId) == 24
#                            and genpar[mpart.genPartIdxMother].genPartIdxMother >= 0
#                            and abs(genpar[genpar[mpart.genPartIdxMother].genPartIdxMother].pdgId) == 25):
#                        print("pdgId: " + str(part.pdgId))

        #TODO revise this sanity check  
        #if len(LFromWFromH) + len(LFromWFromT) != len(LFromW):
            #sys.exit("something is going wrong with leptons")
        
        #TODO revise this sanity check since there might be another W's from which quarks might arise than the W's from top and the W's from Higgs 
        #if len(QFromWFromH) + len(QFromWFromT) != len(QFromW):
            #sys.exit("error: quarks from W from H plus quarks from W from top are not equal total quarks from W's")
        
        #TODO sanity check on neutrinos but should be checked against leptons from W from tops and higgs only 
        #if len(NuFromWFromH) + len(NuFromWFromT) != len(LFromW):
            #print("from higgs " + str(len(NuFromWFromH)) + " neutrinos and from top " + str(len(NuFromWFromT)) + " while total leptons are " + str(len(LFromW)))
            #sys.exit("error: you don't have matching number of nu's to leptons!")
        
        #TODO all block commented below 
        '''
        # taus
        for part in genpar:
            if (abs(part.pdgId) in [15] and part.genPartIdxMother >= 0 and abs(genpar[part.genPartIdxMother].pdgId) == 24):
                     and genpar[part.genPartIdxMother].statusFlags &(1 << statusFlagsMap['isHardProcess'])):
                if self.debug: print "it is a tau coming from a hard W"
                tauFromW.append(part)
        
        # leptons from top as recommended by gen particle producer
        for part in genpar:
            if (abs(part.pdgId) in [11,13] 
                     and part.statusFlags &(1 << statusFlagsMap['isPrompt'])
                     and part.statusFlags &(1 << statusFlagsMap['isHardProcess'])
                     and part.statusFlags &(1 << statusFlagsMap['isFirstCopy'])
                     and not part.statusFlags &(1 << statusFlagsMap['isDirectHadronDecayProduct'])):
                if self.debug: print "it should be a  lepton coming from top"
                LFromWFromT.append(part)
        
        '''
        '''
        print (" >> in this event: "  
                + " \n higgses              = " + str(len(Higgses)) 
                + " \n W from Higgs         = " + str(len(WFromH))
                + " \n hard tops            = " + str(len(tfromhardprocess))
                + " \n W from tops          = " + str(len(WFromT))
                + " \n leptons              = " + str(len(genlep)) 
                + " \n QFromWFromH          = " + str(len(QFromWFromH))
                + " \n QFromWFromT          = " + str(len(QFromWFromT)) 
                + " \n LFromWFromH          = " + str(len(LFromWFromH)) 
                + " \n LFromWFromT          = " + str(len(LFromWFromT)) 
                + " \n NuFromWFromH         = " + str(len(NuFromWFromH)) 
                + " \n NuFromWFromT         = " + str(len(NuFromWFromT))
                + " \n quarks from W's      = " + str(len(QFromW))
                + " \n leptons from W's     = " + str(len(LFromW))
             #   + " \n taus from W's        = " + str(len(tauFromW))
                + " \n <<")
        '''
        HadTopPt = -99
        HadTopM  = -99
        WFromHadTopPt = -99
        WFromHadTopM  = -99
        WFromHiggsPt  = -99
        WFromHiggsM   = -99
        nHadTop  = 0
        for top in tfromhardprocess:
            if top not in leptonictops:
                HadTopPt = top.p4().Pt()
                HadTopM  = top.p4().M()
                nHadTop = nHadTop + 1
        for w in WFromT:
            if genpar[w.genPartIdxMother] not in leptonictops:
                WFromHadTopPt = w.p4().Pt()
                WFromHadTopM  = w.p4().M()
        for q in QFromWFromH:
            WFromHiggsPt = genpar[q.genPartIdxMother].p4().Pt()
            WFromHiggsM = genpar[q.genPartIdxMother].p4().M()
#        print("nHadTop: "+str(nHadTop))
#        print("nLepTop: "+str(len(leptonictops)))

        #for jet in genjet:
            #if not jet.partonFlavour == 5 and not jet.partonFlavour == -5: that excludes b-jets but it is not necessary
            #if jet.p4().Pt() > 30 and abs(jet.p4().Eta()) < 2.5:  # bit extreme cuts, I think supposed to be 24 and 2.4
               #gengoodJets.append(jet)
               #print "jet flavour = " + str(jet.partonFlavour) + " and mass = " + str(jet.p4().M()) + " GeV and pT = " + str(jet.p4().Pt())
        #MET_pt   = getattr(event,"MET_pt")
        #mhtJet25 = getattr(event,"mhtJet25_Recl")
        nleps    = getattr(event,"nLepGood")
        nFO      = getattr(event,"nLepFO"+self.label)
        ileps    = getattr(event,"iLepFO"+self.label)
        leps     = Collection(event,"LepGood","nLepGood")
        lepsFO   = [leps[ileps[i]] for i in xrange(nFO)]
        jets     = [x for x in Collection(event,"JetSel"+self.label,"nJetSel"+self.label)]
        jetsMore = [x for x in Collection(event,"Jet")]
        fatjets  = [x for x in Collection(event,"FatJet","nFatJet")]
        
        for var in self.systsJEC:
            score = getattr(event,"BDThttTT_eventReco_mvaValue%s"%self.systsJEC[var])
            candidateMinimizers=[];
            candidateBranchValues=[];
            testing_list=[] 
            fatjetsNoB   = [b for b in fatjets if b.btagDeepB<btagvetoval] # I think we want already to exclude bjets, possibly remove the requirement.
            jetsTopNoB=None
            jetsNoTopNoB=None

            ### *............................................................................*
            ### *Br    9 :Muon_genPartFlav :                                                 *
            ### *         | UChar_t Flavour of genParticle for MC matching to status==1 muons:*
            ### *         |  1 = prompt muon (including gamma*->mu mu), 15 = muon from prompt tau, 5 = muon from b, 4 = muon from c, 3 = muon from light or unknown, 0 = unmatched*
            ### *Entries :   295099 : Total  Size=    1789156 bytes  File Size  =     875839 *

            # Delicate: here the logic is built such that if one does not use the top tagger then 
            # some variables are left empty to suppress code into "if variable:" blocks
#            self.useTopTagger = False;
            if self.useTopTagger:
                j1top = getattr(event,"BDThttTT_eventReco_iJetSel1%s"%self.systsJEC[var])
                j2top = getattr(event,"BDThttTT_eventReco_iJetSel2%s"%self.systsJEC[var])
                j3top = getattr(event,"BDThttTT_eventReco_iJetSel3%s"%self.systsJEC[var])
                jetsTopNoB   = [b for a,b in enumerate(jets) if a in [j1top,j2top,j3top] and b.btagDeepB<btagvetoval] #it is a jet coming from top and not a b-jet
                if score>self.cut_BDT_rTT_score:
                    jetsNoTopNoB = [j for i,j in enumerate(jets) if i not in [j1top,j2top,j3top] and j.btagDeepB<btagvetoval]
                else:
                    jetsNoTopNoB = []
            else:
                jetsNoTopNoB = [j for j in jets if j.btagDeepB<btagvetoval]

            # HACK !!! FIX THIS
            jetsNoTopNoBPhis = [j.phi for j in jetsNoTopNoB]
            jetsNoTopNoBMore = [j for j in jetsMore if j.phi in jetsNoTopNoBPhis]
            jetsNoTopNoBMorePhis = [j.phi for j in jetsNoTopNoBMore]

############### Reconstruction Algorithm ###############
#            jBscore = -1000
#            _jBscore = -1
#            bjlist = []
#            for _j,j in [(ix,x.p4()) for ix,x in enumerate(jetsNoTopNoB)]:
#                if jetsNoTopNoB[_j].btagDeepB > jBscore:
#                    jBscore = jetsNoTopNoB[_j].btagDeepB
#                    _jBscore = _j
#                if jetsNoTopNoB[_j].btagDeepB > 0.7221:
#                    bjlist.append(_j)
#            if len(bjlist)==0: bjlist.append(_jBscore)
#            delrlist = []
#            for _lep,lep in [(ix,x.p4()) for ix,x in enumerate(lepsFO)]:
#                closestjetMT = 1000
#                for _j in bjlist:
#                    if abs((jetsNoTopNoB[_j].p4()+lep).M()-173.0) < closestjetMT and (jetsNoTopNoB[_j].p4()+lep).M() < 175.0 and (jetsNoTopNoB[_j].p4()+lep).M() > 100.0:
#                        closestjetMT = abs((jetsNoTopNoB[_j].p4()+lep).M()-173.0)
#                delrlist.append(closestjetMT)
#                closestjetdelr = 99
#                for _j in bjlist:
#                    if jetsNoTopNoB[_j].p4().DeltaR(lep) < closestjetdelr: closestjetdelr = jetsNoTopNoB[_j].p4().DeltaR(lep)
#                if closestjetdelr != 99: delrlist.append(closestjetdelr)

#            ilist = [i[0] for i in sorted(enumerate(delrlist), key=lambda x:x[1])]
#            notop = True
#            for d in delrlist:
#                if d != 1000: notop=False
#            if notop :
#                goodlepidx = -1
#            else:
#                goodlepidx = ilist[len(ilist)-1]
            goodlepidx = 1
#            mindr0 = 1000
#            mindr1 = 1000
#            for _j,j in [(ix,x.p4()) for ix,x in enumerate(jetsNoTopNoB)]:
#                if jetsNoTopNoB[_j].btagDeepB > 0.0614 : continue
#                if lepsFO[0].p4().DeltaR(j) < mindr0: mindr0 = lepsFO[0].p4().DeltaR(j)
#                if lepsFO[1].p4().DeltaR(j) < mindr1: mindr1 = lepsFO[1].p4().DeltaR(j)
#            if mindr0 < mindr1 and mindr0 < 2.0: goodlepidx=0
#            for _j in bjlist:
#                if (lepsFO[1].p4()+jetsNoTopNoB[_j].p4()).M() < 175 and (lepsFO[1].p4()+jetsNoTopNoB[_j].p4()).M() > 80 and (lepsFO[1].p4().DeltaR(jetsNoTopNoB[_j].p4())) < 1.5:
#                    goodlepidx = 0
#            print("goodlepidx: "+str(goodlepidx))
            rightlepnow = -1
            if (len(QFromWFromH)==2 and len(LFromWFromH)==1):
                ilist=[i[0] for i in sorted(enumerate(lepsFO),key=lambda x:x[1].p4().DeltaR(LFromWFromH[0].p4()))]
                rightlepnow = ilist[0]

            mHRightLepton = -99
            mHWrongLepton = -99
            if len(QFromWFromH)==2 and len(LFromWFromH)==1 and len(lepsFO)==2:
                wronglepnow = 0 if rightlepnow == 1 else 1
                mHRightLepton = (lepsFO[rightlepnow].p4()+QFromWFromH[0].p4()+QFromWFromH[1].p4()).M()
                mHWrongLepton = (lepsFO[wronglepnow].p4()+QFromWFromH[0].p4()+QFromWFromH[1].p4()).M()

#            print("New Event")
            closesttriptotop = 9999
            PtTop_recohtt = -99
            MTop_recohtt = -99
            PtWFromTop_recohtt = -99
            MWFromTop_recohtt = -99
            WFromTop_rightlep_delr = -99;
            WFromTop_wronglep_delr = -99;

            score = getattr(event,"BDThttTT_eventReco_mvaValue%s"%self.systsJEC[var])
#            print(score)
            j1top = getattr(event,"BDThttTT_eventReco_iJetSel1%s"%self.systsJEC[var])
            j2top = getattr(event,"BDThttTT_eventReco_iJetSel2%s"%self.systsJEC[var])
            j3top = getattr(event,"BDThttTT_eventReco_iJetSel3%s"%self.systsJEC[var])
            j1 = jets[int(j1top)]
            j2 = jets[int(j2top)]
            j3 = jets[int(j3top)]
#            print("Js: "+str(jets[int(j1top)].btagDeepB)+"  "+str(jets[int(j2top)].btagDeepB)+"  "+str(jets[int(j3top)].btagDeepB))
            if score>self.cut_BDT_rTT_score:
                bscores = [jets[int(j1top)].btagDeepB, jets[int(j2top)].btagDeepB, jets[int(j3top)].btagDeepB]
                bindex = bscores.index(max(bscores))
                PtTop_recohtt = (j1.p4()+j2.p4()+j3.p4()).Pt()
                MTop_recohtt = (j1.p4()+j2.p4()+j3.p4()).M()
                PtWFromTop_recohtt = (j1.p4()*(bindex!=0)+j2.p4()*(bindex!=1)+j3.p4()*(bindex!=2)).Pt()
                MWFromTop_recohtt = (j1.p4()*(bindex!=0)+j2.p4()*(bindex!=1)+j3.p4()*(bindex!=2)).M()
                if len(QFromWFromH)==2 and len(LFromWFromH)==1 and len(lepsFO)==2:
                    WFromTop_rightlep_delr = (j1.p4()+j2.p4()+j3.p4()).DeltaR(lepsFO[rightlepnow].p4())
                    WFromTop_wronglep_delr = (j1.p4()+j2.p4()+j3.p4()).DeltaR(lepsFO[wronglepnow].p4())
                
                
#                print(str(PtTop_recohtt)+"  "+str(MTop_recohtt)+"  "+str(PtWFromTop_recohtt)+"  "+str(MWFromTop_recohtt))
#            print(WFromHadTopPt)
#            print(WFromHadTopM)
#            print(WFromHiggsPt)
#            print(WFromHiggsM)
#            print(PtWFromTop_recohtt)
#            print(MWFromTop_recohtt)
#            print("")
#            for _j1,_j2,_j3,j1,j2,j3 in [(jetsNoTopNoB.index(x1),jetsNoTopNoB.index(x2),jetsNoTopNoB.index(x3),x1.p4(),x2.p4(),x3.p4()) for x1,x2,x3 in itertools.combinations(jetsNoTopNoB,3)]:
#                if (len(QFromWFromH)!=2 or len(LFromWFromH)!=1): break
#                a1 = jetsNoTopNoB[_j1].btagDeepB > 0.7221 and jetsNoTopNoB[_j2].btagDeepB < 0.3093 and jetsNoTopNoB[_j3].btagDeepB < 0.3093
#                a2 = jetsNoTopNoB[_j1].btagDeepB < 0.3093 and jetsNoTopNoB[_j2].btagDeepB > 0.7221 and jetsNoTopNoB[_j3].btagDeepB < 0.3093
#                a3 = jetsNoTopNoB[_j1].btagDeepB < 0.3093 and jetsNoTopNoB[_j2].btagDeepB < 0.3093 and jetsNoTopNoB[_j3].btagDeepB > 0.7221
#                if a1 or a2 or a3:
#                    closesttriptotop = abs((j1+j2+j3).M()-173)
#                    PtTop_reco = (j1+j2+j3).Pt()
#                    MTop_reco = (j1+j2+j3).M()
#                    goodlepidx = 1 if (j1+j2+j3).DeltaR(lepsFO[0].p4()) < (j1+j2+j3).DeltaR(lepsFO[1].p4()) else 0
#                    print("J1BScore: "+str(jetsNoTopNoB[_j1].btagDeepB)+"  J1Eta: "+str(j1.Eta()))
#                    print("J2BScore: "+str(jetsNoTopNoB[_j2].btagDeepB)+"  J1Eta: "+str(j2.Eta()))
#                    print("J3BScore: "+str(jetsNoTopNoB[_j3].btagDeepB)+"  J1Eta: "+str(j3.Eta()))
#                    print("M():      "+str((j1+j2+j3).M()))
#                    print("")
                
#                print("RightM: "+str(mHRightLepton)+"  WrongM: "+str(mHWrongLepton))

            for _lep,lep in [(ix,x.p4()) for ix,x in enumerate(lepsFO)]:
#                if (len(QFromWFromH)!=2 or len(LFromWFromH)!=1): break
#                break
#                for _j,j in [(ix,x.p4()) for ix,x in enumerate(jetsNoTopNoB)]:
#                    print("Lepton Index: "+str(_lep)+"  B Score: "+str(jetsNoTopNoB[_j].btagDeepB)+"  M(l,j): "+str((lep+j).M())+"  DelR(l,j): "+str(lep.DeltaR(j))+"  pT(lep): " + \
#                    str(lep.Pt())+"  pT(jet): "+str(j.Pt()))
                lep.SetPtEtaPhiM(getattr(lepsFO[_lep],'conePt'),lep.Eta(), lep.Phi(), lep.M())
                iClosestFatJetToLep = -99
                minDeltaRfatJetLep = 999
                for _j, j in [(ix,x.p4()) for ix,x in enumerate(fatjetsNoB)]: # Find the fat jet closest to the lepton
                    if j.DeltaR(lep) < minDeltaRfatJetLep:
                        iClosestFatJetToLep=_j
                        minDeltaRfatJetLep = j.DeltaR(lep)
                if iClosestFatJetToLep >-1: # Otherwise there are no fat jets
                    fj = fatjetsNoB[iClosestFatJetToLep]
                    closestFat_deltaR = fj.p4().DeltaR(lep)
                    closestFat_lepIsFromH = -99 # -99 if no lepton from H; 0 if this reco lepton is not the correct lepton; 1 if this reco lepton is the correct lepton
                    if len(LFromWFromH) == 1:
                        closestFat_lepIsFromH = 1 if (lep.DeltaR(LFromWFromH[0].p4()) < 0.1) else 0
                    # Must probably add some ID (FatJet_jetId)
                    closestFatJetToLeptonVars.append([closestFat_deltaR, closestFat_lepIsFromH, fj.pt, fj.eta, fj.phi, fj.mass, fj.msoftdrop, fj.tau1, fj.tau2, fj.tau3, fj.tau4])
                for _j1,_j2,j1,j2 in [(jetsNoTopNoB.index(x1),jetsNoTopNoB.index(x2),x1.p4(),x2.p4()) for x1,x2 in itertools.combinations(jetsNoTopNoB,2)]:
                    j1.SetPtEtaPhiM(getattr(jetsNoTopNoB[_j1],'pt%s'%self.systsJEC[var]),j1.Eta(), j1.Phi(), j1.M())
                    j2.SetPtEtaPhiM(getattr(jetsNoTopNoB[_j2],'pt%s'%self.systsJEC[var]),j2.Eta(), j2.Phi(), j2.M())
                    W = j1+j2
                    mW = W.M()
                    Wconstr = ROOT.TLorentzVector()
                    Wconstr.SetPtEtaPhiM(W.Pt(),W.Eta(),W.Phi(),80.4)
                    Wconstr = W
                    Hvisconstr = lep+Wconstr
                    mHvisconstr = Hvisconstr.M()
                    pTHvisconstr = Hvisconstr.Pt()
                    #TODO print("I am just before the warning. QFromWFromH is " + str(len(QFromWFromH)))
                    #if (len(NuFromWFromH)>1):
                        #print("WARNING! we have not one but " + str(len(NuFromWFromH)) + " neutrinos from W from H. I am in reconstruction loop. QFromWFromH is " + str(len(QFromWFromH)))
                    for neutrino in NuFromWFromH:
                        VisPlusNu = Hvisconstr+neutrino.p4() 
                        pTVisPlusNu = VisPlusNu.Pt()
                        MVisPlusNu = VisPlusNu.M()
                    if len(NuFromWFromH) == 0 : 
                        pTVisPlusNu = pTHvisconstr
                        MVisPlusNu = mHvisconstr
                    cj = j1 if lep.DeltaR(j1) < lep.DeltaR(j2) else j2
                    fj = j2 if lep.DeltaR(j1) < lep.DeltaR(j2) else j1
                    _cj = _j1 if lep.DeltaR(j1) < lep.DeltaR(j2) else _j2
                    _fj = _j2 if lep.DeltaR(j1) < lep.DeltaR(j2) else _j1
                    mindR = lep.DeltaR(cj)
                    maxdR = lep.DeltaR(fj)
                    mindRW = W.DeltaR(cj)
                    maxdRW = W.DeltaR(fj)
                    cjBScore = jetsNoTopNoB[_cj].btagDeepB
                    delR_H_j1j2 = j1.DeltaR(j2)
                    delpT_recovis_genvis = abs((pTVisPlusNu-pTHgen)/pTHgen)
                    delR_j2W = abs((pTVisPlusNu-pTHgen)/pTHgen)
                    inWindow = 0 if mW > 20 and mW < 130 else 1
                    mindlW = W.DeltaR(lep)
                    rightlep = 0 if len(LFromWFromH)==1 and len(QFromWFromH)==2 and LFromWFromH[0].p4().DeltaR(lep) < 0.25 else 1
#                    goodchoicelep = 0 if _lep==goodlepidx else 1
                    goodchoicelep = 0 if _lep==rightlepnow else 1
                    hasnomedb = 0 if jetsNoTopNoB[_cj].btagDeepB < 0.0614 and jetsNoTopNoB[_fj].btagDeepB < 0.0614 else 1
#                    rightlep = 0
#                    delR_j2W = abs((j1.Pt()-j2.Pt())/(j1.Pt()+j2.Pt()))
#                    delR_j2W = delpT_recovis_genvis
#                    delR_j2W = abs(MVisPlusNu-125.0)
#                    delR_j2W = min(abs(mW-80.4),abs(mW-40.2))
#                    delR_j2W = j1.DeltaR(j2)
#                    delR_j2W = jetsNoTopNoB[_j2].btagDeepB
#                    delR_j2W = max(lep.DeltaR(j1),lep.DeltaR(j2))
#                    if (mW<self.cuts_mW_had[0] or mW>self.cuts_mW_had[1]): continue
#                    if mHvisconstr<self.cuts_mH_vis[0] or mHvisconstr>self.cuts_mH_vis[1]: continue
                    candidateMinimizers.append((goodchoicelep,mindR,abs(mHvisconstr-125.0),abs(mW-80.4),delR_H_j1j2,_lep,_j1,_j2,pTVisPlusNu,pTHvisconstr,delpT_recovis_genvis))
                    candidateBranchValues.append((mindR,mHvisconstr,mW,delR_H_j1j2,_lep,_j1,_j2,pTVisPlusNu,pTHvisconstr,delpT_recovis_genvis,maxdR,mindR,maxdRW,rightlep,cjBScore))

            nmismatchedtoptaggedjets = 0
            if self.useTopTagger:
                for topjet in jetsTopNoB:
                    for gentopquark in QFromWFromT:
                        if topjet.p4().DeltaR(gentopquark.p4()) > 0.5:
                            #jets tagged as coming from top didn't match with true partons coming from top"
                            nmismatchedtoptaggedjets +=1 #only with respect to the hadronic top where W -> qq, this is what being matched here
            sortedCandidateBranchValues = [x for _,x in sorted(zip(candidateMinimizers,candidateBranchValues))]
            curbest = -99
            if not len(candidateMinimizers):
                best = None
                correct = None
            else:
                curbest = 0
                for i in range(len(sortedCandidateBranchValues)):
                    if sortedCandidateBranchValues[i][9] < sortedCandidateBranchValues[curbest][9] : curbest = i
                l2 = 0
#                while sortedCandidateBranchValues[l2][4] == sortedCandidateBranchValues[0][4]: l2 = l2 + 1
#                i = 0 if sortedCandidateBranchValues[0][14] < sortedCandidateBranchValues[l2][14] else l2
#                best    = sortedCandidateBranchValues[i]
                best    = sortedCandidateBranchValues[0]
                correct = sortedCandidateBranchValues[curbest]
#            if (len(QFromWFromH)==2 and len(LFromWFromH)==1) :
#                print("right lep now: " + str(rightlepnow))
#                print("good lep     : " + str(goodlepidx))
#                if goodlepidx == -1: matchstr = "Null"
#                else: matchstr = str(goodlepidx==rightlepnow)
#                print("theymatched: " +str(rightlepnow)+str(goodlepidx)+matchstr)
#                print("DeltaR: "+str(LFromWFromH[0].p4().DeltaR( lepsFO[rightlepnow].p4())))
            
            # function for sorting lists
            #def ExtractIndex(lst):
                #return [item[1] for item in lst]
            #def ExtractpT(lst):
                #return [item[0] for item in lst]

############# Kinematics of Gen-Level objects #############
            #TODO should I add if len(QFromWFromH)==2 here? 
            if len(QFromWFromH)==2 and len(LFromWFromH)==1 and len(LFromWFromT)==1 and var==0:
                for q1,q2 in itertools.combinations(QFromWFromH,2):
                    delR_H_partons = q1.p4().DeltaR(q2.p4())
                    trueGenQuarkSum = q1.p4()+q2.p4()
                    MGenQuarks = trueGenQuarkSum.M();
                    pTGenQuarks = trueGenQuarkSum.Pt();
                    dRGenQuarks = q1.p4().DeltaR(q2.p4());
                    #TODO if (len(LFromWFromH)>1):
                        #print("WARNING: we have not one but ",len(LFromWFromH), "leptons from W from H. I am in the if best")
                    #TODO should I add a cut conditon here?
                    for lepton in LFromWFromH:
                        delR_H_q1l = q1.p4().DeltaR(lepton.p4())  
                        delR_H_q2l = q2.p4().DeltaR(lepton.p4()) 
                        trueGenSum = lepton.p4()+q1.p4()+q2.p4()
                        MTrueGen   = trueGenSum.M()
                        pTTrueGen  = trueGenSum.Pt()
                        #massTrueGen= trueGenSum.M()
                        #deltaM_trueGen_H = massTrueGen-massHgen
                        #TODO if (len(NuFromWFromH)>1):
                            #print("WARNING: we have not one but ",len(NuFromWFromH), "neutrinos from W from H. I am in the if best")
                        #TODO should I add a cut condition here?
                        for nu in NuFromWFromH:
                            TrueGenplusNu = trueGenSum+nu.p4() 
                            pTTrueGenplusNu = TrueGenplusNu.Pt()
                #TODO if (len(QFromWFromH)>2):
                    #TODO print("WARNING: we have not two but ",len(QFromWFromH), "quarks from W from H. I am in the if best")

################# Quark-Jet matching variables #################
                closestJetInDelRToQFromWFromH = [-99 for i in QFromWFromH]
                closestJetInPTResToQFromWFromH = [-99 for i in QFromWFromH]
                quark1pT=QFromWFromH[0].p4().Pt()
                quark2pT=QFromWFromH[1].p4().Pt()
                #print("the whole quarks list = " + str(QFromWFromH))
                for quark_idx, quark in enumerate(QFromWFromH):
                    minDeltaR=99
                    jet_idx_DeltaR=-99
                    minDeltaPT=99
                    jet_idx_DeltaPT=-99
                    for jet in jetsNoTopNoB:
                        deltaRqj=quark.p4().DeltaR(jet.p4())
                        if deltaRqj < minDeltaR:
                            minDeltaR=deltaRqj
                            jet_idx_DeltaR=jetsNoTopNoB.index(jet)
                        deltaPTqj=(jet.p4().Pt()-quark.p4().Pt())/quark.p4().Pt()
                        if abs(deltaPTqj) < abs(minDeltaPT):
                            minDeltaPT=deltaPTqj
                            jet_idx_DeltaPT=jetsNoTopNoB.index(jet)
                    closestJetInDelRToQFromWFromH[quark_idx]=jet_idx_DeltaR
                    closestJetInPTResToQFromWFromH[quark_idx]=jet_idx_DeltaPT
                    quarkpTinQFromWFromH[quark_idx] = QFromWFromH[quark_idx].p4().Pt()
                    quarkEtainQFromWFromH[quark_idx] = QFromWFromH[quark_idx].p4().Eta()
                    quarkFlavourinQFromWFromH[quark_idx] = QFromWFromH[quark_idx].pdgId
                    #print("the closest jets list before = " + str(closestJetInDelRToQFromWFromH)) #why does this sometimes print jets with indicies -1,-1
                if -99 not in closestJetInDelRToQFromWFromH:
                    #print(" you have a selected jet with an index of -1!")
                    #sys.exit("you have a selected with an index of -1!")

                    #print("the closest jets list after = " + str(closestJetInDelRToQFromWFromH)) #why does this sometimes print jets with indicies -1,-1
                    closestJetInDelR_pt_ToQFromWFromH         = [-99 for i in QFromWFromH]
                    closestJetInDelR_ptres_ToQFromWFromH      = [-99 for i in QFromWFromH]
                    closestJetInDelR_delR_ToQFromWFromH       = [-99 for i in QFromWFromH]
                    closestJetInDelR_flavour_ToQFromWFromH    = [-99 for i in QFromWFromH]
                    jets_match_quarks_delr                    = [-99 for i in QFromWFromH]
                    for idx in range(len(QFromWFromH)):
                        quarkpT                 =   QFromWFromH[idx].p4().Pt()
                        closestjetindelrpT      =   jetsNoTopNoB[closestJetInDelRToQFromWFromH[idx]].p4().Pt()
                        # HACK
                        closestjetindelrflavour  = -99
                        phitofind = jetsNoTopNoB[closestJetInDelRToQFromWFromH[idx]].phi
                        for _j,j in enumerate(jetsNoTopNoBMore):
                            if j.phi==phitofind:
                                closestjetindelrflavour = jetsNoTopNoBMore[_j].partonFlavour
                                break
                        if closestjetindelrflavour  == -99 : print("Warning: Parton flavour not found")
                        ptres_delr              =   (closestjetindelrpT-quarkpT)/quarkpT
                        delRqj_delr             =   QFromWFromH[idx].p4().DeltaR(jetsNoTopNoB[closestJetInDelRToQFromWFromH[idx]].p4())
                        # filling
                        closestJetInDelR_pt_ToQFromWFromH[idx]       = closestjetindelrpT
                        closestJetInDelR_ptres_ToQFromWFromH[idx]    = ptres_delr
                        closestJetInDelR_delR_ToQFromWFromH[idx]     = delRqj_delr
                        closestJetInDelR_flavour_ToQFromWFromH[idx]  = closestjetindelrflavour
                        if delRqj_delr < 0.3 and abs(ptres_delr) < 0.6: #this is a matched quark
                            jets_match_quarks_delr[idx]=closestJetInDelRToQFromWFromH[idx]
                    if -99 not in jets_match_quarks_delr and len(QFromWFromH)==2 and var==0:
                        j1 = jetsNoTopNoB[jets_match_quarks_delr[0]]
                        j2 = jetsNoTopNoB[jets_match_quarks_delr[1]]
                        M_jets_match=(j1.p4()+j2.p4()).M()

                if -99 not in closestJetInPTResToQFromWFromH:
                    #print(" you have a selected jet with an index of -1!")
                    #sys.exit("you have a selected with an index of -1!")

                    #print("the closest jets list after = " + str(closestJetInDelRToQFromWFromH)) #why does this sometimes print jets with indicies -1,-1
                    closestJetInPTRes_pt_ToQFromWFromH        = [-99 for i in QFromWFromH]
                    closestJetInPTRes_ptres_ToQFromWFromH     = [-99 for i in QFromWFromH]
                    closestJetInPTRes_delR_ToQFromWFromH      = [-99 for i in QFromWFromH]
                    closestJetInPTRes_flavour_ToQFromWFromH   = [-99 for i in QFromWFromH]
                    jets_match_quarks_ptres                   = [-99 for i in QFromWFromH]
                    for idx in range(len(QFromWFromH)):
                        quarkpT                 =   QFromWFromH[idx].p4().Pt()
                        closestjetinptrespT     =   jetsNoTopNoB[closestJetInPTResToQFromWFromH[idx]].p4().Pt()
                        # HACK
                        closestjetinptresflavour = -99
                        phitofind = jetsNoTopNoB[closestJetInPTResToQFromWFromH[idx]].phi
                        for _j,j in enumerate(jetsNoTopNoBMore):
                            if j.phi==phitofind:
                                closestjetinptresflavour = jetsNoTopNoBMore[_j].partonFlavour
                                break
                        if closestjetinptresflavour == -99 : print("Warning: Parton flavour not found")
                        ptres_ptres             =   (closestjetinptrespT-quarkpT)/quarkpT
                        delRqj_ptres            =   QFromWFromH[idx].p4().DeltaR(jetsNoTopNoB[closestJetInPTResToQFromWFromH[idx]].p4())
                        # filling
                        closestJetInPTRes_pt_ToQFromWFromH[idx]      = closestjetinptrespT
                        closestJetInPTRes_ptres_ToQFromWFromH[idx]   = ptres_ptres
                        closestJetInPTRes_delR_ToQFromWFromH[idx]    = delRqj_ptres
                        closestJetInPTRes_flavour_ToQFromWFromH[idx] = closestjetinptresflavour
                        if delRqj_ptres < 0.3 and abs(ptres_ptres) < 0.6: #this is a matched quark
                            jets_match_quarks_ptres[idx]=closestJetInPTResToQFromWFromH[idx]

############# Variables that are only calculable if Reco is successful #############
            matchRank = -99
            if best: #TODO: what does that actually do compared to "if best else -99"
                mindRlj     = best[0]
                mHvisconstr = best[1]
                WMass       = best[2]
                delR_H_j1j2 = best[3]
                lepIdx      = best[4]
                j1Idx       = best[5]
                j2Idx       = best[6]
                pTVisPlusNu = best[7]
                pTHVis      = best[8]
                jetreco1    = jetsNoTopNoB[best[5]] 
                jetreco2    = jetsNoTopNoB[best[6]]
                delR_H_j1l_reco = lepsFO[best[4]].p4().DeltaR(jetreco1.p4())
                delR_H_j2l_reco = lepsFO[best[4]].p4().DeltaR(jetreco2.p4())
                maxdR       = best[10]
                mindR       = best[11]
                maxdRW      = best[12]
                mindRW      = best[13]
                #testing_list.extend(([jetreco1.p4().Pt(),best[5]],[jetreco2.p4().Pt(),best[6]]))
                #lst=sorted(testing_list,reverse=True)
                #print(ExtractIndex(lst))
                #print(ExtractpT(lst))

                mindRlj_correct     = correct[0]
                mHvisconstr_correct = correct[1]
                WMass_correct       = correct[2]
                delR_H_j1j2_correct = correct[3]
                lepIdx_correct      = correct[4]
                j1Idx_correct       = correct[5]
                j2Idx_correct       = correct[6]
                pTVisPlusNu_correct = correct[7]
                pTHVis_correct      = correct[8]
                jetreco1_correct    = jetsNoTopNoB[correct[5]]
                jetreco2_correct    = jetsNoTopNoB[correct[6]]
                delR_H_j1l_reco_correct = lepsFO[correct[4]].p4().DeltaR(jetreco1_correct.p4())
                delR_H_j2l_reco_correct = lepsFO[correct[4]].p4().DeltaR(jetreco2_correct.p4())
                maxdR_correct       = correct[10]
                mindR_correct       = correct[11]
                maxdRW_correct      = correct[12]
                mindRW_correct      = correct[13]
                
                if len(QFromWFromH)==2 and var==0:
                    if -99 not in jets_match_quarks_delr:
                        pTVis_jets_match=(jetsNoTopNoB[jets_match_quarks_delr[0]].p4()+jetsNoTopNoB[jets_match_quarks_delr[1]].p4()+lepsFO[best[4]].p4()).Pt()
                        MVis_jets_match=(jetsNoTopNoB[jets_match_quarks_delr[0]].p4()+jetsNoTopNoB[jets_match_quarks_delr[1]].p4()+lepsFO[best[4]].p4()).M()
                        for cidx, cands in enumerate(sortedCandidateBranchValues):
                            match1 = jets_match_quarks_delr[0] == cands[5] and jets_match_quarks_delr[1] == cands[6]
                            match2 = jets_match_quarks_delr[1] == cands[5] and jets_match_quarks_delr[0] == cands[6]
                            if (match1 or match2):
                                matchRank = cidx
                                break
                
                # TODO full-fledged matching but we are studying it first
                # TODO: iterate over both quarks and fill nbothmatchedpartons
                nmatchedpartons = 0
                for quark in QFromWFromH: 
                    if quark.p4().DeltaR(jetreco1.p4()) < 0.1 or quark.p4().DeltaR(jetreco2.p4()) < 0.1:
                        nmatchedpartons +=1
                
                #TODO if (len(LFromWFromH)>1):
                    #print("WARNING: we have not one but ",len(LFromWFromH), "leptons from W from H. I am in the if best")
                nmatchedleptons = 0
                for l in LFromWFromH:
                    if l.p4().DeltaR(lepsFO[best[4]].p4()) < 0.1 or l.p4().DeltaR(lepsFO[best[4]].p4()) < 0.1:
                        nmatchedleptons +=1
            
            else: pass  
            # Sort gen quark by pt
            aa = 0 if quarkpTinQFromWFromH[0] > quarkpTinQFromWFromH[1] else 1
            bb = 1 if quarkpTinQFromWFromH[0] > quarkpTinQFromWFromH[1] else 0
            #reconstruction loop dependent vars
            ret["Hreco_minDRlj%s"                     %self.systsJEC[var]] = mindRlj                    if best else -99
            ret["Hreco_delR_H_j1j2%s"                 %self.systsJEC[var]] = delR_H_j1j2                if best else -99
            ret["Hreco_visHmass%s"                    %self.systsJEC[var]] = mHvisconstr                if best else -99
            ret["Hreco_Wmass%s"                       %self.systsJEC[var]] = WMass                      if best else -99
            ret["Hreco_lepIdx%s"                      %self.systsJEC[var]] = lepIdx                     if best else -99
            ret["Hreco_j1Idx%s"                       %self.systsJEC[var]] = j1Idx                      if best else -99
            ret["Hreco_j2Idx%s"                       %self.systsJEC[var]] = j2Idx                      if best else -99
            ret["Hreco_pTVisPlusNu%s"                 %self.systsJEC[var]] = pTVisPlusNu                if best else -99 
            ret["Hreco_pTHvis%s"                      %self.systsJEC[var]] = pTHVis                     if best else -99
            ret["Hreco_pTVis_jets_match%s"            %self.systsJEC[var]] = pTVis_jets_match           if best else -99
            ret["Hreco_MVis_jets_match%s"             %self.systsJEC[var]] = MVis_jets_match            if best else -99
            ret["Hreco_nmatchedleptons%s"             %self.systsJEC[var]] = nmatchedleptons            if best else -99 
            ret["Hreco_nmatchedpartons%s"             %self.systsJEC[var]] = nmatchedpartons            if best else -99 
            ret["Hreco_nmismatchedtoptaggedjets%s"    %self.systsJEC[var]] = nmismatchedtoptaggedjets   if best else -99
            ret["Hreco_delR_H_j1l_reco%s"             %self.systsJEC[var]] = delR_H_j1l_reco            if best else -99 
            ret["Hreco_delR_H_j2l_reco%s"             %self.systsJEC[var]] = delR_H_j2l_reco            if best else -99
            ret["Hreco_maxdR%s"                       %self.systsJEC[var]] = maxdR                      if best else -99
            ret["Hreco_mindR%s"                       %self.systsJEC[var]] = mindR                      if best else -99
            ret["Hreco_maxdRW%s"                      %self.systsJEC[var]] = maxdRW                     if best else -99
            ret["Hreco_mindRW%s"                      %self.systsJEC[var]] = mindRW                     if best else -99
            ret["Hreco_PtTop_recohtt%s"               %self.systsJEC[var]] = PtTop_recohtt
            ret["Hreco_MTop_recohtt%s"                %self.systsJEC[var]] = MTop_recohtt
            ret["Hreco_PtWFromTop_recohtt%s"          %self.systsJEC[var]] = PtWFromTop_recohtt
            ret["Hreco_MWFromTop_recohtt%s"           %self.systsJEC[var]] = MWFromTop_recohtt
            ret["Hreco_WFromTop_rightlep_delr%s"      %self.systsJEC[var]] = WFromTop_rightlep_delr
            ret["Hreco_WFromTop_wronglep_delr%s"      %self.systsJEC[var]] = WFromTop_wronglep_delr

            ret["Hreco_minDRlj_correct%s"                     %self.systsJEC[var]] = mindRlj_correct                    if best else -99
            ret["Hreco_delR_H_j1j2_correct%s"                 %self.systsJEC[var]] = delR_H_j1j2_correct                if best else -99
            ret["Hreco_visHmass_correct%s"                    %self.systsJEC[var]] = mHvisconstr_correct                if best else -99
            ret["Hreco_Wmass_correct%s"                       %self.systsJEC[var]] = WMass_correct                      if best else -99
            ret["Hreco_lepIdx_correct%s"                      %self.systsJEC[var]] = lepIdx_correct                     if best else -99
            ret["Hreco_j1Idx_correct%s"                       %self.systsJEC[var]] = j1Idx_correct                      if best else -99
            ret["Hreco_j2Idx_correct%s"                       %self.systsJEC[var]] = j2Idx_correct                      if best else -99
            ret["Hreco_pTVisPlusNu_correct%s"                 %self.systsJEC[var]] = pTVisPlusNu_correct                if best else -99
            ret["Hreco_pTHvis_correct%s"                      %self.systsJEC[var]] = pTHVis_correct                     if best else -99
            ret["Hreco_delR_H_j1l_reco_correct%s"             %self.systsJEC[var]] = delR_H_j1l_reco_correct            if best else -99
            ret["Hreco_delR_H_j2l_reco_correct%s"             %self.systsJEC[var]] = delR_H_j2l_reco_correct            if best else -99
            ret["Hreco_maxdR_correct%s"                       %self.systsJEC[var]] = maxdR_correct                      if best else -99
            ret["Hreco_mindR_correct%s"                       %self.systsJEC[var]] = mindR_correct                      if best else -99
            ret["Hreco_maxdRW_correct%s"                      %self.systsJEC[var]] = maxdRW_correct                     if best else -99
            ret["Hreco_mindRW_correct%s"                      %self.systsJEC[var]] = mindRW_correct                     if best else -99

            #delR and closest jet vars
            ret["Hreco_delR_H_partons%s"                                      %self.systsJEC[var]] = delR_H_partons
            ret["Hreco_delR_H_q1l%s"                                          %self.systsJEC[var]] = delR_H_q1l
            ret["Hreco_delR_H_q2l%s"                                          %self.systsJEC[var]] = delR_H_q2l
            ret["Hreco_closestJetInDelR_pt_ToQ1FromWFromH%s"                  %self.systsJEC[var]] = closestJetInDelR_pt_ToQFromWFromH[aa]
            ret["Hreco_closestJetInDelR_pt_ToQ2FromWFromH%s"                  %self.systsJEC[var]] = closestJetInDelR_pt_ToQFromWFromH[bb]
            ret["Hreco_closestJetInDelR_ptres_ToQ1FromWFromH%s"               %self.systsJEC[var]] = closestJetInDelR_ptres_ToQFromWFromH[aa]
            ret["Hreco_closestJetInDelR_ptres_ToQ2FromWFromH%s"               %self.systsJEC[var]] = closestJetInDelR_ptres_ToQFromWFromH[bb]
            ret["Hreco_closestJetInDelR_delR_ToQ1FromWFromH%s"                %self.systsJEC[var]] = closestJetInDelR_delR_ToQFromWFromH[aa]
            ret["Hreco_closestJetInDelR_delR_ToQ2FromWFromH%s"                %self.systsJEC[var]] = closestJetInDelR_delR_ToQFromWFromH[bb]
            ret["Hreco_closestJetInDelR_flavour_ToQ1FromWFromH%s"             %self.systsJEC[var]] = closestJetInDelR_flavour_ToQFromWFromH[aa]
            ret["Hreco_closestJetInDelR_flavour_ToQ2FromWFromH%s"             %self.systsJEC[var]] = closestJetInDelR_flavour_ToQFromWFromH[bb]
            ret["Hreco_closestJetInPTRes_pt_ToQ1FromWFromH%s"                 %self.systsJEC[var]] = closestJetInPTRes_pt_ToQFromWFromH[aa]
            ret["Hreco_closestJetInPTRes_pt_ToQ2FromWFromH%s"                 %self.systsJEC[var]] = closestJetInPTRes_pt_ToQFromWFromH[bb]
            ret["Hreco_closestJetInPTRes_ptres_ToQ1FromWFromH%s"              %self.systsJEC[var]] = closestJetInPTRes_ptres_ToQFromWFromH[aa]
            ret["Hreco_closestJetInPTRes_ptres_ToQ2FromWFromH%s"              %self.systsJEC[var]] = closestJetInPTRes_ptres_ToQFromWFromH[bb]
            ret["Hreco_closestJetInPTRes_delR_ToQ1FromWFromH%s"               %self.systsJEC[var]] = closestJetInPTRes_delR_ToQFromWFromH[aa]
            ret["Hreco_closestJetInPTRes_delR_ToQ2FromWFromH%s"               %self.systsJEC[var]] = closestJetInPTRes_delR_ToQFromWFromH[bb]
            ret["Hreco_closestJetInPTRes_flavour_ToQ1FromWFromH%s"            %self.systsJEC[var]] = closestJetInPTRes_flavour_ToQFromWFromH[aa]
            ret["Hreco_closestJetInPTRes_flavour_ToQ2FromWFromH%s"            %self.systsJEC[var]] = closestJetInPTRes_flavour_ToQFromWFromH[bb]

            #lists from gen loop
            ret["Hreco_nWFromH%s"                     %self.systsJEC[var]] = len(WFromH)
            ret["Hreco_nQFromWFromH%s"                %self.systsJEC[var]] = len(QFromWFromH)
            ret["Hreco_nLFromWFromH%s"                %self.systsJEC[var]] = len(LFromWFromH)
            ret["Hreco_nQFromWFromT%s"                %self.systsJEC[var]] = len(QFromWFromT)
            ret["Hreco_nLFromWFromT%s"                %self.systsJEC[var]] = len(LFromWFromT)
            ret["Hreco_nNuFromWFromH%s"               %self.systsJEC[var]] = len(NuFromWFromH)
            ret["Hreco_nNuFromWFromT%s"               %self.systsJEC[var]] = len(NuFromWFromT)
            ret["Hreco_nZFromH%s"                     %self.systsJEC[var]] = len(ZFromH)
            ret["Hreco_nQFromZFromH%s"                %self.systsJEC[var]] = len(QFromZFromH)
            ret["Hreco_nLFromZFromH%s"                %self.systsJEC[var]] = len(LFromZFromH)
            ret["Hreco_nNuFromZFromH%s"               %self.systsJEC[var]] = len(NuFromZFromH)
            ret["Hreco_nTauFromH%s"                   %self.systsJEC[var]] = len(TauFromH)
            ret["Hreco_nPiFromTauFromH%s"             %self.systsJEC[var]] = len(PiFromTauFromH)
            ret["Hreco_nLFromTauFromH%s"              %self.systsJEC[var]] = len(LFromTauFromH)
            ret["Hreco_nNuFromTauFromH%s"             %self.systsJEC[var]] = len(NuFromTauFromH)
            ret["Hreco_nTNuFromTauFromH%s"            %self.systsJEC[var]] = len(TNuFromTauFromH)
            ret["Hreco_nKaFromTauFromH%s"             %self.systsJEC[var]] = len(KaFromTauFromH)
            ret["Hreco_nLFromTauFromWFromH%s"         %self.systsJEC[var]] = len(LFromTauFromWFromH)
            ret["Hreco_nhFromTauFromWFromH%s"         %self.systsJEC[var]] = len(hFromTauFromWFromH)
            ret["Hreco_nTauFromWFromH%s"              %self.systsJEC[var]] = len(TauFromWFromH)
            ret["Hreco_nFO%s"                         %self.systsJEC[var]] = nFO
            ret["Hreco_nLeptonicTops%s"               %self.systsJEC[var]] = len(leptonictops)
            ret["Hreco_nHadTop%s"                     %self.systsJEC[var]] = nHadTop
            ret["Hreco_nJetsInCollection%s"           %self.systsJEC[var]] = len(jetsNoTopNoB)

            #kinematics of gen-level objects and matched objects
            ret["Hreco_pTTrueGen%s"                                            %self.systsJEC[var]] = pTTrueGen
            ret["Hreco_MTrueGen%s"                                             %self.systsJEC[var]] = MTrueGen
            ret["Hreco_pTTrueGenPlusNu%s"                                      %self.systsJEC[var]] = pTTrueGenplusNu
            ret["Hreco_pTGenQuarks%s"                                          %self.systsJEC[var]] = pTGenQuarks
            ret["Hreco_dRGenQuarks%s"                                          %self.systsJEC[var]] = dRGenQuarks
            ret["Hreco_MGenQuarks%s"                                           %self.systsJEC[var]] = MGenQuarks
            ret["Hreco_pTtgen%s"                                               %self.systsJEC[var]] = pTtgen
            ret["Hreco_pTHgen%s"                                               %self.systsJEC[var]] = pTHgen
            ret["Hreco_quark1pT%s"                                             %self.systsJEC[var]] = quarkpTinQFromWFromH[aa]
            ret["Hreco_quark2pT%s"                                             %self.systsJEC[var]] = quarkpTinQFromWFromH[bb]
            ret["Hreco_quark1Eta%s"                                            %self.systsJEC[var]] = quarkEtainQFromWFromH[aa]
            ret["Hreco_quark2Eta%s"                                            %self.systsJEC[var]] = quarkEtainQFromWFromH[bb]
            ret["Hreco_quark1Flavour%s"                                        %self.systsJEC[var]] = quarkFlavourinQFromWFromH[aa]
            ret["Hreco_quark2Flavour%s"                                        %self.systsJEC[var]] = quarkFlavourinQFromWFromH[bb]
            ret["Hreco_jet_matches_quark1_delr%s"                              %self.systsJEC[var]] = jets_match_quarks_delr[aa]
            ret["Hreco_jet_matches_quark2_delr%s"                              %self.systsJEC[var]] = jets_match_quarks_delr[bb]
            ret["Hreco_jet_matches_quark1_ptres%s"                             %self.systsJEC[var]] = jets_match_quarks_ptres[aa]
            ret["Hreco_jet_matches_quark2_ptres%s"                             %self.systsJEC[var]] = jets_match_quarks_ptres[bb]
            ret["Hreco_M_jets_match%s"                                         %self.systsJEC[var]] = M_jets_match
            ret["Hreco_matchRank%s"                                            %self.systsJEC[var]] = matchRank
            ret["Hreco_bestRank%s"                                             %self.systsJEC[var]] = curbest
            ret["Hreco_mHRightLepton%s"                                        %self.systsJEC[var]] = mHRightLepton
            ret["Hreco_mHWrongLepton%s"                                        %self.systsJEC[var]] = mHWrongLepton
            ret["Hreco_HadTopPt%s"                                             %self.systsJEC[var]] = HadTopPt
            ret["Hreco_HadTopM%s"                                              %self.systsJEC[var]] = HadTopM
            ret["Hreco_WFromHadTopPt%s"                                        %self.systsJEC[var]] = WFromHadTopPt
            ret["Hreco_WFromHadTopM%s"                                         %self.systsJEC[var]] = WFromHadTopM
            ret["Hreco_WFromHiggsPt%s"                                         %self.systsJEC[var]] = WFromHiggsPt
            ret["Hreco_WFromHiggsM%s"                                          %self.systsJEC[var]] = WFromHiggsM

            # other vars
            #TODO ret["Hreco_deltaM_trueGen_H%s"            %self.systsJEC[var]] = deltaM_trueGen_H           if best else -99 
            #TODO ret["Hreco_nbothmatchedpartons%s"         %self.systsJEC[var]] = nbothmatchedpartons        if best else -99 
            #TODO ret["Hreco_BDThttTT_eventReco_mvaValue%s" %self.systsJEC[var]] = score # if best?
            
            #for mylep in [0, 1]:
                #ret["Hreco_l%s_fj_deltaR%s"      %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][0] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_lepIsFromH%s"  %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][1] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_pt%s"          %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][2] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_eta%s"         %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][3] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_phi%s"         %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][4] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_mass%s"        %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][5] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_msoftdrop%s"   %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][6] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_tau1%s"        %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][7] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_tau2%s"        %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][8] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_tau3%s"        %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][9] if len(closestFatJetToLeptonVars) == 2 else -99
                #ret["Hreco_l%s_fj_tau4%s"        %(mylep,self.systsJEC[var])] = closestFatJetToLeptonVars[mylep][10] if len(closestFatJetToLeptonVars) == 2 else -99
        return ret
