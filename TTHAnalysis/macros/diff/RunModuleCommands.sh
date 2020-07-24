#Gen
python ../prepareEventVariablesFriendTree.py -t NanoAOD -d TTHnobb_fxfx ../../macros/diff/skimmedTrees_16/ 2lss_diff/ -I CMGTools.TTHAnalysis.tools.nanoAOD.ttH_modules higgsDiffGenTTH -F Friends ../../macros/diff/skimmedTrees_16/0_jmeUnc_v1/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/2_scalefactors/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/3_tauCount/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/1_recl/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/5_BDThtt_reco/{cname}_Friend.root --env uclouvain

#Reco
#python ../prepareEventVariablesFriendTree.py -t NanoAOD -d TTHnobb_fxfx ../../macros/diff/skimmedTrees_16/ 2lss_diff/ -I CMGTools.TTHAnalysis.tools.nanoAOD.ttH_modules higgsDiffRecoTTH -F Friends ../../macros/diff/skimmedTrees_16/0_jmeUnc_v1/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/2_scalefactors/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/3_tauCount/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/1_recl/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/5_BDThtt_reco/{cname}_Friend.root --env uclouvain

#Reco_NoMassConstraint
#python ../prepareEventVariablesFriendTree.py -t NanoAOD -d TTHnobb_fxfx ../../macros/diff/skimmedTrees_16/ 2lss_diff/ -I CMGTools.TTHAnalysis.tools.nanoAOD.ttH_modules higgsDiffRecoTTH_noWmassConstraint -F Friends ../../macros/diff/skimmedTrees_16/0_jmeUnc_v1/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/2_scalefactors/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/3_tauCount/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/1_recl/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/5_BDThtt_reco/{cname}_Friend.root --env uclouvain

#Comp
#python ../prepareEventVariablesFriendTree.py -t NanoAOD -d TTHnobb_fxfx ../../macros/diff/skimmedTrees_16/ 2lss_diff/ -I CMGTools.TTHAnalysis.tools.nanoAOD.ttH_modules higgsDiffCompTTH -F Friends ../../macros/diff/2lss_diff/{cname}_Gen_Friend.root -F Friends ../../macros/diff/2lss_diff/{cname}_Reco_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/0_jmeUnc_v1/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/2_scalefactors/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/3_tauCount/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/1_recl/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/5_BDThtt_reco/{cname}_Friend.root --env uclouvain

#Reference
#python ../prepareEventVariablesFriendTree.py -t NanoAOD -d TTHnobb_fxfx ../../macros/diff/skimmedTrees_16/ 2lss_diff/ -I CMGTools.TTHAnalysis.tools.nanoAOD.ttH_modules higgsRecoTTH_NoTopMediumBottom -F Friends ../../macros/diff/skimmedTrees_16/0_jmeUnc_v1/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/2_scalefactors/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/3_tauCount/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/1_recl/{cname}_Friend.root -F Friends ../../macros/diff/skimmedTrees_16/5_BDThtt_reco/{cname}_Friend.root --env uclouvain
