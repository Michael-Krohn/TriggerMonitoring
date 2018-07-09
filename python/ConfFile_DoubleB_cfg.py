import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
#process.MessageLogger.cerr.FwkReport.reportEvery = 1000

#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )


#process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
 #   fileNames = cms.untracked.vstring(
#        'file:/eos/user/a/amarini/ZeroBiasScouting_Run2017_v2/JetHT/JetHT_1/170624_222405/0000/outputScoutingCalo_9.root',
  #  )
#)


import FWCore.Utilities.FileUtils as FileUtils
mylist = FileUtils.loadListFromFile ('infile.txt') 
readFiles = cms.untracked.vstring( *mylist)

#myParentlist = FileUtils.loadListFromFile ('infile6_parent.txt')
#readParentFiles = cms.untracked.vstring( *myParentlist)

process.source = cms.Source('PoolSource', 
                            fileNames = readFiles
#                            secondaryFileNames = readParentFiles)
)

import FWCore.PythonUtilities.LumiList as LumiList
#process.source.lumisToProcess = LumiList.LumiList(filename = 'Cert_314472-317696_13TeV_PromptReco_Collisions18_JSON.txt').getVLuminosityBlockRange()

#import FWCore.PythonUtilities.LumiList as LumiList
#process.source.lumisToProcess = LumiList.LumiList(filename = 'json_DCSONLY.txt').getVLuminosityBlockRange()

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string('AnalysisOutput_DoubleB.root'),
 #                                  closeFileFast = cms.untracked.bool(True)
)

## process.demo = cms.EDAnalyzer('DimuonScoutingAnalyzer',
##      triggerResults  = cms.InputTag("TriggerResults", "", "TEST"),
##      muons           = cms.InputTag("hltScoutingMuonPackerCalo", "", "TEST"),
## )

process.demo = cms.EDAnalyzer('DoubleBAnalyzer',
     triggerResults  = cms.InputTag("TriggerResults", "", "HLT"),
#     caloJets        = cms.InputTag("hltScoutingCaloPacker", "", "HLT"),
#     pfJets          = cms.InputTag("hltScoutingPFPacker", "", "HLT"),
     recoAK8Jets        = cms.InputTag("slimmedJetsAK8", "", "RECO"),
#     recoAK8Jets        = cms.untracked.InputTag("slimmedJetsAK8", "", "RECO"),
#     muons           = cms.InputTag("hltScoutingMuonPacker", "", "HLT"),
     bDiscriminators = cms.vstring(      # list of b-tag discriminators to access
#        'pfTrackCountingHighEffBJetTags',
#        'pfTrackCountingHighPurBJetTags',
#        'pfJetProbabilityBJetTags',
#        'pfJetBProbabilityBJetTags',
#        'pfSimpleSecondaryVertexHighEffBJetTags',
#        'pfSimpleSecondaryVertexHighPurBJetTags',
#        'pfCombinedSecondaryVertexV2BJetTags',
#        'pfCombinedInclusiveSecondaryVertexV2BJetTags',
	'pfBoostedDoubleSecondaryVertexAK8BJetTags'
#        'pfCombinedMVABJetTags'
    )

)


process.p = cms.Path(process.demo)
