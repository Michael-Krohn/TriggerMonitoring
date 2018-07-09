# TriggerMonitoring

To setup the code:
'''
cmsrel 10_1_7
cd CMSSW_10_1_7/src
cmsenv
git cms-init

git remote add cms-l1t-offline git@github.com:cms-l1t-offline/cmssw.git
git fetch cms-l1t-offline

git cms-addpkg L1Trigger/L1TCommon
git cms-addpkg L1Trigger/L1TMuon
git cms-addpkg L1Trigger/L1TGlobal
git cms-addpkg HLTrigger/Configuration

git cms-checkdeps -A -a
scram b -j 8

git clone https://github.com/Michael-Krohn/TriggerMonitoring.git
scram b -j 8
'''
