import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load('Configuration.StandardSequences.Services_cff')
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
from Configuration.AlCa.autoCond import autoCond
process.GlobalTag = GlobalTag(process.GlobalTag, '101X_dataRun2_Prompt_v11') #


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )
#process.MessageLogger.cerr.FwkReport.reportEvery = 1000

#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )


#process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
 #   fileNames = cms.untracked.vstring(
#        'file:/eos/user/a/amarini/ZeroBiasScouting_Run2017_v2/JetHT/JetHT_1/170624_222405/0000/outputScoutingCalo_9.root',
  #  )
#)


import FWCore.Utilities.FileUtils as FileUtils
mylist = FileUtils.loadListFromFile ('infile_Run2018B_v1.txt') 
readFiles = cms.untracked.vstring( *mylist)

#myParentlist = FileUtils.loadListFromFile ('infile6_parent.txt')
#readParentFiles = cms.untracked.vstring( *myParentlist)

process.source = cms.Source('PoolSource', 
#          fileNames = cms.untracked.vstring ('root://cmsxrootd.fnal.gov//store/data/Run2018B/JetHT/MINIAOD/PromptReco-v1/000/317/930/00000/000B0765-D573-E811-AAA2-FA163E5B9703.root'),
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
from JMEAnalysis.JetToolbox.jetToolbox_cff import jetToolbox
jetToolbox( process, 'ak8', 'jetSequence', 'out', PUMethod='Puppi', miniAOD=True, runOnMC=False, addSoftDrop=True)
#jetToolbox( process, 'ak8', 'jetSequence', 'out', PUMethod='Puppi', miniAOD=True, runOnMC=False, bTagDiscriminators='pfBoostedDoubleSecondaryVertexAK8BJetTags', addSoftDrop=True)

process.demo = cms.EDAnalyzer('DoubleBAnalyzer',
     triggerResults  = cms.InputTag("TriggerResults", "", "HLT"),
#     caloJets        = cms.InputTag("hltScoutingCaloPacker", "", "HLT"),
#     pfJets          = cms.InputTag("hltScoutingPFPacker", "", "HLT"),
     recoAK8Jets        = cms.InputTag("selectedPatJetsAK8PFPuppi"),
#     recoAK8Jets        = cms.InputTag("slimmedJetsAK8", "", "RECO"),
     bDiscriminators = cms.vstring(      # list of b-tag discriminators to access
#        'pfTrackCountingHighEffBJetTags',
#        'pfTrackCountingHighPurBJetTags',
#        'pfJetProbabilityBJetTags',
#        'pfJetBProbabilityBJetTags',
#        'pfSimpleSecondaryVertexHighEffBJetTags',
#        'pfSimpleSecondaryVertexHighPurBJetTags',
#        'pfCombinedSecondaryVertexV2BJetTags_test',
#        'pfCombinedInclusiveSecondaryVertexV2BJetTags',
	'pfBoostedDoubleSecondaryVertexAK8BJetTags'
#        'pfCombinedMVABJetTags'
    )

)


process.p = cms.Path(process.demo)
