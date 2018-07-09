from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'TriggerMonitoring_DoubleBTriggers_Run2018B_v2'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

#config.JobType.numCores = 4
config.JobType.maxMemoryMB = 16000
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ConfFile_DoubleB_cfg.py'
#import os
#os.system("tar czf python.tar.gz --dereference --directory $CMSSW_BASE python")
#os.system("voms-proxy-info -path | xargs -i  cp {}  .")
config.JobType.inputFiles = [
                             'Cert_314472-317696_13TeV_PromptReco_Collisions18_JSON.txt',
                             'infile.txt',
                             '../plugins/DoubleBAnalyzer.cc',
]
#config.JobType.allowUndistributedCMSSW = True 

#config.Data.outputPrimaryDataset = 'T5gg'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
#config.Data.totalUnits = 70
config.Data.lumiMask = 'Cert_314472-317696_13TeV_PromptReco_Collisions18_JSON.txt'
#config.Data.runRange = '318872'
config.Data.outLFNDirBase = '/store/user/mkrohn/TriggerMonitoring_DoubleBTriggers'
config.Data.inputDataset = '/JetHT/Run2018B-PromptReco-v2/MINIAOD'
config.Data.publication = False
#config.Data.outputDatasetTag = 'GMSB_analysis'
config.Data.outputDatasetTag = 'TriggerMonitoring_DoubleBTriggers'
config.Data.allowNonValidInputDataset = True
config.Site.blacklist = ['T0_*']

config.Site.storageSite = "T3_US_FNALLPC"

