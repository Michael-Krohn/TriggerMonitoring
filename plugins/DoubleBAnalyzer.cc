// -*- C++ -*-
//
// Package:    Analyzer/DoubleBAnalyzer
// Class:      DoubleBAnalyzer
// 
/**\class DoubleBAnalyzer DoubleBAnalyzer.cc Analyzer/DoubleBAnalyzer/plugins/DoubleBAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Swagata Mukherjee
//         Created:  Mon, 26 Jun 2017 09:38:37 GMT
//
//


#include <memory>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/Scouting/interface/ScoutingMuon.h"
#include "DataFormats/Scouting/interface/ScoutingPFJet.h"
#include "DataFormats/Scouting/interface/ScoutingCaloJet.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include <TLorentzVector.h>
#include "TH1.h"
#include "TVector3.h"
#include "TMath.h"

class DoubleBAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit DoubleBAnalyzer(const edm::ParameterSet&);
      ~DoubleBAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

  // ----------member data ---------------------------
  edm::EDGetTokenT<edm::TriggerResults>            trgResultsLabel_;
//  edm::EDGetTokenT<ScoutingCaloJetCollection>      caloJetLabel_;
//  edm::EDGetTokenT<ScoutingPFJetCollection>        pfJetLabel_;
//  edm::InputTag recoJetLabel_;
  edm::EDGetToken             recoJetLabel_;
//  edm::EDGetTokenT<std::vector<pat::Jet>>             recoJetLabel_;
//  edm::EDGetTokenT<ScoutingMuonCollection>         muonLabel_;
  edm::Service<TFileService> fs;

  const std::vector<std::string> bDiscriminators_;


  int passDoubleBTrig_np4;
  int passDoubleBTrig_np2;
  int passCSVTrig_p17;
  int passMonitorAK8200Trig;
  int passMonitorAK8360Trig;
  int passMonitorAK8420Trig;
  int passMonitorAK8jetTrig;
  int passMonitorMuTrig;

  int failingModule;

  double recoAK8pT;
  double recoAK8eta;
  double recoAK8SDmass;
  double recoAK8DoubleB;
  double maxRecoAK8DoubleB;

  TH1F *h1_recoAK8pT_DoubleBTrig_np4_Mumonitoring;

  TH1F *h1_recoAK8pT_DoubleBTrig_np4_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np2_monitoring;

  TH1F *h1_recoAK8pT_DoubleBTrig_np4_DB00_SD40_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np2_DB00_SD40_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np4_DB03_SD40_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np2_DB03_SD40_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np4_DB06_SD40_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np2_DB06_SD40_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np4_DB09_SD40_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np2_DB09_SD40_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np4_DB03Inv_SD40_monitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np2_DB03Inv_SD40_monitoring;

  TH1F *h1_recoAK8pT_DoubleBTrig_np4_DB00_SD40_Mumonitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np2_DB00_SD40_Mumonitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np4_DB09_SD40_Mumonitoring;
  TH1F *h1_recoAK8pT_DoubleBTrig_np2_DB09_SD40_Mumonitoring;

  TH1F *h1_recoAK8pT_420JetTrigORDoubleB_DB00_SD40_monitoring;
  TH1F *h1_recoAK8pT_420JetTrigORDoubleB_DB09_SD40_monitoring;
  TH1F *h1_recoAK8pT_420JetTrigORDoubleB_DB00_SD40_Mumonitoring;
  TH1F *h1_recoAK8pT_420JetTrigORDoubleB_DB09_SD40_Mumonitoring;

  TH1F *h1_recoAK8pT_420JetTrig_DB00_SD40_monitoring;
  TH1F *h1_recoAK8pT_420JetTrig_DB09_SD40_monitoring;
  TH1F *h1_recoAK8pT_420JetTrig_DB00_SD40_Mumonitoring;
  TH1F *h1_recoAK8pT_420JetTrig_DB09_SD40_Mumonitoring;

  TH1F *h1_recoAK8eta_DoubleBTrig_np4_monitoring;
  TH1F *h1_recoAK8eta_DoubleBTrig_np2_monitoring;

  TH1F *h1_recoAK8eta_DoubleBTrig_np4_DB09_SD40_monitoring;
  TH1F *h1_recoAK8eta_DoubleBTrig_np2_DB09_SD40_monitoring;

  TH1F *h1_recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450_monitoring;
  TH1F *h1_recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450_monitoring;

  TH1F *h1_recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450_Mumonitoring;
  TH1F *h1_recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450_Mumonitoring;

  TH1F *h1_recoAK8phi_DoubleBTrig_np4_monitoring;
  TH1F *h1_recoAK8phi_DoubleBTrig_np2_monitoring;

  TH1F *h1_recoAK8phi_DoubleBTrig_np4_DB09_SD40_monitoring;
  TH1F *h1_recoAK8phi_DoubleBTrig_np2_DB09_SD40_monitoring;

  TH1F *h1_recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450_monitoring;
  TH1F *h1_recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450_monitoring;

  TH1F *h1_recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450_Mumonitoring;
  TH1F *h1_recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450_Mumonitoring;

  TH1F *h1_recoAK8mass_DoubleBTrig_np4_monitoring;
  TH1F *h1_recoAK8mass_DoubleBTrig_np2_monitoring;

  TH1F *h1_recoAK8DoubleB_DoubleBTrig_np4_SD40_monitoring;
  TH1F *h1_recoAK8DoubleB_DoubleBTrig_np2_SD40_monitoring;
  TH1F *h1_recoAK8MaxDoubleB_DoubleBTrig_np4_SD40_monitoring;
  TH1F *h1_recoAK8MaxDoubleB_DoubleBTrig_np2_SD40_monitoring;

  TH1F *h1_recoAK8DoubleB_DoubleBTrig_np4_monitoring;
  TH1F *h1_recoAK8DoubleB_DoubleBTrig_np2_monitoring;
  TH1F *h1_recoAK8MaxDoubleB_DoubleBTrig_np4_monitoring;
  TH1F *h1_recoAK8MaxDoubleB_DoubleBTrig_np2_monitoring;

  TH1F *h1_recoAK8DoubleB_DoubleBTrig_np4_pT450_monitoring;
  TH1F *h1_recoAK8DoubleB_DoubleBTrig_np2_pT450_monitoring;

  TH1F *h1_recoAK8DoubleB_CSVTrig_p17_monitoring;

  TH1F *h1_recoAK8pT_monitoring;
  TH1F *h1_recoAK8eta_monitoring;
  TH1F *h1_recoAK8phi_monitoring;
  TH1F *h1_recoAK8mass_monitoring;

  TH1F *h1_recoAK8eta_DB09_SD40_monitoring;
  TH1F *h1_recoAK8phi_DB09_SD40_monitoring;

  TH1F *h1_recoAK8eta_DB09_SD40_pT450_monitoring;
  TH1F *h1_recoAK8phi_DB09_SD40_pT450_monitoring;

  TH1F *h1_recoAK8eta_DB09_SD40_pT450_Mumonitoring;
  TH1F *h1_recoAK8phi_DB09_SD40_pT450_Mumonitoring;

  TH1F *h1_recoAK8pT_DB00_SD40_monitoring;
  TH1F *h1_recoAK8pT_DB03_SD40_monitoring;
  TH1F *h1_recoAK8pT_DB06_SD40_monitoring;
  TH1F *h1_recoAK8pT_DB09_SD40_monitoring;
  TH1F *h1_recoAK8pT_DB03Inv_SD40_monitoring;

  TH1F *h1_recoAK8pT_DB00_SD40_Mumonitoring;
  TH1F *h1_recoAK8pT_DB09_SD40_Mumonitoring;

  TH1F *h1_recoAK8DoubleB_monitoring;
  TH1F *h1_recoAK8MaxDoubleB_monitoring;

  TH1F *h1_recoAK8DoubleB_SD40_monitoring;
  TH1F *h1_recoAK8MaxDoubleB_SD40_monitoring;

  TH1F *h1_recoAK8DoubleB_pT450_monitoring;

  TH1F* h1_recoAK8DoubleB_CSVTrig_p17_pT450_monitoring;

  TH1F* h1_failingModule_DB09_SD40;
  TH1F* h1_failingModule_DB00_SD40;
  TH1F* h1_failingModule_DB09_SD40_Mu;
  TH1F* h1_failingModule_DB00_SD40_Mu;
  TH1F* h1_failingModule_DB09_SD40_pT450;
  TH1F* h1_failingModule_DB09_SD40_pT450_Mu;
  TH1F* h1_failingModule;
  TH1F* h1_failingModule_Mu;

};


DoubleBAnalyzer::DoubleBAnalyzer(const edm::ParameterSet& iConfig):
  bDiscriminators_(iConfig.getParameter<std::vector<std::string> >("bDiscriminators"))

{
  trgResultsLabel_         = consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("triggerResults"));
  recoJetLabel_            = consumes<std::vector<pat::Jet>>(iConfig.getParameter<edm::InputTag>("recoAK8Jets"));
  usesResource("TFileService");

  const Int_t NBINS = 12;
  Double_t pT_edges[NBINS + 1] = {275,300,325,350,375,400,425,450,500,550,600,675,800};

  const Int_t NBINS_eta = 16;
  Double_t eta_edges[NBINS_eta + 1] = {-2.4, -1.68, -1.44, -1.2, -0.96, -0.72, -0.48, -0.24, 0.0, 0.24, 0.48, 0.72, 0.96, 1.2, 1.44, 1.68, 2.4};

  TFileDirectory histoDir = fs->mkdir("histoDir");

  h1_recoAK8pT_DoubleBTrig_np4_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np4_Mu", "recoAK8pT_DoubleBTrig_np4_Mu", 100, 0, 1000);

  h1_recoAK8pT_DoubleBTrig_np4_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np4", "recoAK8pT_DoubleBTrig_np4", 100, 0, 1000);

  h1_recoAK8pT_DoubleBTrig_np2_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np2", "recoAK8pT_DoubleBTrig_np2", 100, 0, 1000);


  h1_recoAK8pT_DoubleBTrig_np4_DB00_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np4_DB00_SD40", "recoAK8pT_DoubleBTrig_np4_DB00_SD40", NBINS, pT_edges);
  h1_recoAK8pT_DoubleBTrig_np2_DB00_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np2_DB00_SD40", "recoAK8pT_DoubleBTrig_np2_DB00_SD40", NBINS, pT_edges);
  h1_recoAK8pT_DoubleBTrig_np4_DB03_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np4_DB03_SD40", "recoAK8pT_DoubleBTrig_np4_DB03_SD40", 100, 0, 1000);
  h1_recoAK8pT_DoubleBTrig_np2_DB03_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np2_DB03_SD40", "recoAK8pT_DoubleBTrig_np2_DB03_SD40", 100, 0, 1000);
  h1_recoAK8pT_DoubleBTrig_np4_DB06_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np4_DB06_SD40", "recoAK8pT_DoubleBTrig_np4_DB06_SD40", 100, 0, 1000);
  h1_recoAK8pT_DoubleBTrig_np2_DB06_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np2_DB06_SD40", "recoAK8pT_DoubleBTrig_np2_DB06_SD40", 100, 0, 1000);
  h1_recoAK8pT_DoubleBTrig_np4_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np4_DB09_SD40", "recoAK8pT_DoubleBTrig_np4_DB09_SD40", NBINS, pT_edges);
  h1_recoAK8pT_DoubleBTrig_np2_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np2_DB09_SD40", "recoAK8pT_DoubleBTrig_np2_DB09_SD40", NBINS, pT_edges);
  h1_recoAK8pT_DoubleBTrig_np4_DB03Inv_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np4_DB03Inv_SD40", "recoAK8pT_DoubleBTrig_np4_DB03Inv_SD40", 100, 0, 1000);
  h1_recoAK8pT_DoubleBTrig_np2_DB03Inv_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np2_DB03Inv_SD40", "recoAK8pT_DoubleBTrig_np2_DB03Inv_SD40", 100, 0, 1000);

  h1_recoAK8pT_DoubleBTrig_np4_DB00_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np4_DB00_SD40_Mu", "recoAK8pT_DoubleBTrig_np4_DB00_SD40_Mu", NBINS, pT_edges);
  h1_recoAK8pT_DoubleBTrig_np2_DB00_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np2_DB00_SD40_Mu", "recoAK8pT_DoubleBTrig_np2_DB00_SD40_Mu", NBINS, pT_edges);
  h1_recoAK8pT_DoubleBTrig_np4_DB09_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np4_DB09_SD40_Mu", "recoAK8pT_DoubleBTrig_np4_DB09_SD40_Mu", NBINS, pT_edges);
  h1_recoAK8pT_DoubleBTrig_np2_DB09_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_DoubleBTrig_np2_DB09_SD40_Mu", "recoAK8pT_DoubleBTrig_np2_DB09_SD40_Mu", NBINS, pT_edges);

  h1_recoAK8pT_420JetTrigORDoubleB_DB00_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_420JetTrigORDoubleB_DB00_SD40", "recoAK8pT_420JetTrigORDoubleB_DB00_SD40", NBINS, pT_edges);
  h1_recoAK8pT_420JetTrigORDoubleB_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_420JetTrigORDoubleB_DB09_SD40", "recoAK8pT_420JetTrigORDoubleB_DB09_SD40", NBINS, pT_edges);
  h1_recoAK8pT_420JetTrigORDoubleB_DB00_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_420JetTrigORDoubleB_DB00_SD40_Mu", "recoAK8pT_420JetTrigORDoubleB_DB00_SD40_Mu", NBINS, pT_edges);
  h1_recoAK8pT_420JetTrigORDoubleB_DB09_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_420JetTrigORDoubleB_DB09_SD40_Mu", "recoAK8pT_420JetTrigORDoubleB_DB09_SD40_Mu", NBINS, pT_edges);


  h1_recoAK8pT_420JetTrig_DB00_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_420JetTrig_DB00_SD40", "recoAK8pT_420JetTrig_DB00_SD40", NBINS, pT_edges);
  h1_recoAK8pT_420JetTrig_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_420JetTrig_DB09_SD40", "recoAK8pT_420JetTrig_DB09_SD40", NBINS, pT_edges);
  h1_recoAK8pT_420JetTrig_DB00_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_420JetTrig_DB00_SD40_Mu", "recoAK8pT_420JetTrig_DB00_SD40_Mu", NBINS, pT_edges);
  h1_recoAK8pT_420JetTrig_DB09_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_420JetTrig_DB09_SD40_Mu", "recoAK8pT_420JetTrig_DB09_SD40_Mu", NBINS, pT_edges);


  h1_recoAK8eta_DoubleBTrig_np4_monitoring = histoDir.make<TH1F>("recoAK8eta_DoubleBTrig_np4", "recoAK8eta_DoubleBTrig_np4", NBINS_eta, eta_edges);
  h1_recoAK8eta_DoubleBTrig_np2_monitoring = histoDir.make<TH1F>("recoAK8eta_DoubleBTrig_np2", "recoAK8eta_DoubleBTrig_np2", NBINS_eta, eta_edges);

  h1_recoAK8eta_DoubleBTrig_np4_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8eta_DoubleBTrig_np4_DB09_SD40", "recoAK8eta_DoubleBTrig_np4_DB09_SD40", NBINS_eta, eta_edges);
  h1_recoAK8eta_DoubleBTrig_np2_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8eta_DoubleBTrig_np2_DB09_SD40", "recoAK8eta_DoubleBTrig_np2_DB09_SD40", NBINS_eta, eta_edges);

  h1_recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450_monitoring = histoDir.make<TH1F>("recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450", "recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450", NBINS_eta, eta_edges);
  h1_recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450_monitoring = histoDir.make<TH1F>("recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450", "recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450", NBINS_eta, eta_edges);

  h1_recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450_Mumonitoring = histoDir.make<TH1F>("recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450_Mu", "recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450_Mu", NBINS_eta, eta_edges);
  h1_recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450_Mumonitoring = histoDir.make<TH1F>("recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450_Mu", "recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450_Mu", NBINS_eta, eta_edges);

  h1_recoAK8phi_DoubleBTrig_np4_monitoring = histoDir.make<TH1F>("recoAK8phi_DoubleBTrig_np4", "recoAK8phi_DoubleBTrig_np4", 12, -TMath::Pi(), TMath::Pi());
  h1_recoAK8phi_DoubleBTrig_np2_monitoring = histoDir.make<TH1F>("recoAK8phi_DoubleBTrig_np2", "recoAK8phi_DoubleBTrig_np2", 12, -TMath::Pi(), TMath::Pi());

  h1_recoAK8phi_DoubleBTrig_np4_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8phi_DoubleBTrig_np4_DB09_SD40", "recoAK8phi_DoubleBTrig_np4_DB09_SD40", 12, -TMath::Pi(), TMath::Pi());
  h1_recoAK8phi_DoubleBTrig_np2_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8phi_DoubleBTrig_np2_DB09_SD40", "recoAK8phi_DoubleBTrig_np2_DB09_SD40", 12, -TMath::Pi(), TMath::Pi());

  h1_recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450_monitoring = histoDir.make<TH1F>("recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450", "recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450", 12, -TMath::Pi(), TMath::Pi());
  h1_recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450_monitoring = histoDir.make<TH1F>("recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450", "recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450", 12, -TMath::Pi(), TMath::Pi());

  h1_recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450_Mumonitoring = histoDir.make<TH1F>("recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450_Mu", "recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450_Mu", 12, -TMath::Pi(), TMath::Pi());
  h1_recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450_Mumonitoring = histoDir.make<TH1F>("recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450_Mu", "recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450_Mu", 12, -TMath::Pi(), TMath::Pi());

  h1_recoAK8mass_DoubleBTrig_np4_monitoring = histoDir.make<TH1F>("recoAK8mass_DoubleBTrig_np4", "recoAK8mass_DoubleBTrig_np4", 150, 0, 500);
  h1_recoAK8mass_DoubleBTrig_np2_monitoring = histoDir.make<TH1F>("recoAK8mass_DoubleBTrig_np2", "recoAK8mass_DoubleBTrig_np2", 150, 0, 500);

  h1_recoAK8DoubleB_DoubleBTrig_np4_SD40_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_DoubleBTrig_np4_SD40", "recoAK8DoubleB_DoubleBTrig_np4_SD40", 50, -1, 1);
  h1_recoAK8DoubleB_DoubleBTrig_np2_SD40_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_DoubleBTrig_np2_SD40", "recoAK8DoubleB_DoubleBTrig_np2_SD40", 50, -1, 1);
  h1_recoAK8MaxDoubleB_DoubleBTrig_np4_SD40_monitoring = histoDir.make<TH1F>("recoAK8MaxDoubleB_DoubleBTrig_np4_SD40", "recoAK8MaxDoubleB_DoubleBTrig_np4_SD40", 50, -1, 1);
  h1_recoAK8MaxDoubleB_DoubleBTrig_np2_SD40_monitoring = histoDir.make<TH1F>("recoAK8MaxDoubleB_DoubleBTrig_np2_SD40", "recoAK8MaxDoubleB_DoubleBTrig_np2_SD40", 50, -1, 1);

  h1_recoAK8DoubleB_CSVTrig_p17_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_CSVTrig_p17", "recoAK8DoubleB_CSVTrig_p17", 50, -1, 1);

  h1_recoAK8DoubleB_DoubleBTrig_np4_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_DoubleBTrig_np4", "recoAK8DoubleB_DoubleBTrig_np4", 50, -1, 1);
  h1_recoAK8DoubleB_DoubleBTrig_np2_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_DoubleBTrig_np2", "recoAK8DoubleB_DoubleBTrig_np2", 50, -1, 1);
  h1_recoAK8MaxDoubleB_DoubleBTrig_np4_monitoring = histoDir.make<TH1F>("recoAK8MaxDoubleB_DoubleBTrig_np4", "recoAK8MaxDoubleB_DoubleBTrig_np4", 50, -1, 1);
  h1_recoAK8MaxDoubleB_DoubleBTrig_np2_monitoring = histoDir.make<TH1F>("recoAK8MaxDoubleB_DoubleBTrig_np2", "recoAK8MaxDoubleB_DoubleBTrig_np2", 50, -1, 1);

  h1_recoAK8DoubleB_DoubleBTrig_np4_pT450_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_DoubleBTrig_np4_pT450", "recoAK8DoubleB_DoubleBTrig_np4_pT450", 50, -1, 1);
  h1_recoAK8DoubleB_DoubleBTrig_np2_pT450_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_DoubleBTrig_np2_pT450", "recoAK8DoubleB_DoubleBTrig_np2_pT450", 50, -1, 1);

  h1_recoAK8pT_monitoring = histoDir.make<TH1F>("recoAK8pT", "recoAK8pT", 100, 0, 1000);
  h1_recoAK8eta_monitoring = histoDir.make<TH1F>("recoAK8eta", "recoAK8eta", NBINS_eta, eta_edges);
  h1_recoAK8phi_monitoring = histoDir.make<TH1F>("recoAK8phi", "recoAK8phi", 12, -TMath::Pi(), TMath::Pi());
  h1_recoAK8mass_monitoring = histoDir.make<TH1F>("recoAK8mass", "recoAK8mass", 150, 0, 500);

  h1_recoAK8eta_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8eta_DB09_SD40", "recoAK8eta_DB09_SD40", NBINS_eta, eta_edges);
  h1_recoAK8phi_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8phi_DB09_SD40", "recoAK8phi_DB09_SD40", 12, -TMath::Pi(), TMath::Pi());

  h1_recoAK8eta_DB09_SD40_pT450_monitoring = histoDir.make<TH1F>("recoAK8eta_DB09_SD40_pT450", "recoAK8eta_DB09_SD40_pT450", NBINS_eta, eta_edges);
  h1_recoAK8phi_DB09_SD40_pT450_monitoring = histoDir.make<TH1F>("recoAK8phi_DB09_SD40_pT450", "recoAK8phi_DB09_SD40_pT450", 12, -TMath::Pi(), TMath::Pi());

  h1_recoAK8eta_DB09_SD40_pT450_Mumonitoring = histoDir.make<TH1F>("recoAK8eta_DB09_SD40_pT450_Mu", "recoAK8eta_DB09_SD40_pT450_Mu", NBINS_eta, eta_edges);
  h1_recoAK8phi_DB09_SD40_pT450_Mumonitoring = histoDir.make<TH1F>("recoAK8phi_DB09_SD40_pT450_Mu", "recoAK8phi_DB09_SD40_pT450_Mu", 12, -TMath::Pi(), TMath::Pi());

  h1_recoAK8pT_DB00_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DB00_SD40", "recoAK8pT_DB00_SD40", NBINS, pT_edges);
  h1_recoAK8pT_DB03_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DB03_SD40", "recoAK8pT_DB03_SD40", 100, 0, 1000);
  h1_recoAK8pT_DB06_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DB06_SD40", "recoAK8pT_DB06_SD40", 100, 0, 1000);
  h1_recoAK8pT_DB09_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DB09_SD40", "recoAK8pT_DB09_SD40", NBINS, pT_edges);
  h1_recoAK8pT_DB03Inv_SD40_monitoring = histoDir.make<TH1F>("recoAK8pT_DB03Inv_SD40", "recoAK8pT_DB03Inv_SD40", 100, 0, 1000);

  h1_recoAK8pT_DB00_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_DB00_SD40_Mu", "recoAK8pT_DB00_SD40_Mu", NBINS, pT_edges);
  h1_recoAK8pT_DB09_SD40_Mumonitoring = histoDir.make<TH1F>("recoAK8pT_DB09_SD40_Mu", "recoAK8pT_DB09_SD40_Mu", NBINS, pT_edges);


  h1_recoAK8DoubleB_SD40_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_SD40", "recoAK8DoubleB_SD40", 50, -1, 1);
  h1_recoAK8MaxDoubleB_SD40_monitoring = histoDir.make<TH1F>("recoAK8MaxDoubleB_SD40", "recoAK8MaxDoubleB_SD40", 50, -1, 1);

  h1_recoAK8DoubleB_monitoring = histoDir.make<TH1F>("recoAK8DoubleB", "recoAK8DoubleB", 50, -1, 1);
  h1_recoAK8MaxDoubleB_monitoring = histoDir.make<TH1F>("recoAK8MaxDoubleB", "recoAK8MaxDoubleB", 50, -1, 1);

  h1_recoAK8DoubleB_pT450_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_pT450", "recoAK8DoubleB_pT450", 50, -1, 1);

  h1_recoAK8DoubleB_CSVTrig_p17_pT450_monitoring = histoDir.make<TH1F>("recoAK8DoubleB_CSVTrig_pT450", "recoAK8DoubleB_CSVTrig_pT450", 50, -1, 1);

  h1_failingModule_DB09_SD40 = histoDir.make<TH1F>("failingModule_DB09_SD40", "failingModule_DB09_SD40", 290, -0.5, 289.5); 
  h1_failingModule_DB00_SD40 = histoDir.make<TH1F>("failingModule_DB00_SD40", "failingModule_DB00_SD40", 290, -0.5, 289.5);
  h1_failingModule_DB09_SD40_Mu = histoDir.make<TH1F>("failingModule_DB09_SD40_Mu", "failingModule_DB09_SD40_Mu", 290, -0.5, 289.5);
  h1_failingModule_DB00_SD40_Mu = histoDir.make<TH1F>("failingModule_DB00_SD40_Mu", "failingModule_DB00_SD40_Mu", 290, -0.5, 289.5);
  h1_failingModule_DB09_SD40_pT450 = histoDir.make<TH1F>("failingModule_DB09_SD40_pT450", "failingModule_DB09_SD40_pT450", 290, -0.5, 289.5);
  h1_failingModule_DB09_SD40_pT450_Mu = histoDir.make<TH1F>("failingModule_DB09_SD40_pT450_Mu", "failingModule_DB09_SD40_pT450_Mu", 290, -0.5, 289.5);
  h1_failingModule = histoDir.make<TH1F>("failingModule", "failingModule", 290, -0.5, 289.5);
  h1_failingModule_Mu = histoDir.make<TH1F>("failingModule_Mu", "failingModule_Mu", 290, -0.5, 289.5);

}


DoubleBAnalyzer::~DoubleBAnalyzer()
{
}


// ------------ method called for each event  ------------
void
DoubleBAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  //std::cout << "\nEVT" << std::endl;
   using namespace edm;
   passDoubleBTrig_np4=99;
   passDoubleBTrig_np2=99;
   passCSVTrig_p17=99;
   passMonitorAK8200Trig=99;
   passMonitorAK8360Trig=99;
   passMonitorAK8420Trig=99;
   passMonitorAK8jetTrig=99;
   passMonitorMuTrig=99;

   failingModule=-99;

   recoAK8pT=0.0;
   recoAK8eta=-5.;
   recoAK8SDmass=0.0;
   recoAK8DoubleB=-10;
   maxRecoAK8DoubleB=-10;

   edm::Handle<edm::TriggerResults> trgResultsHandle;
   iEvent.getByToken(trgResultsLabel_, trgResultsHandle);

   if (!trgResultsHandle.isValid()) {
     std::cout << "Error in getting trgResultsHandle product from Event!" << std::endl;
     return;
   }
   
   const edm::TriggerNames &trgNames = iEvent.triggerNames(*trgResultsHandle);
//   std::cout << "trgNames.size(): " << trgNames.size() << std::endl;

   for (size_t i = 0; i < trgNames.size(); ++i) {
     const std::string &name = trgNames.triggerName(i);
//     std::cout << "trigger name: " << name << std::endl;
   
     if ( (name.find("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4_v") != std::string::npos )) {
       passDoubleBTrig_np4=trgResultsHandle->accept(i);
	 std::cout << "i: " << i << std::endl;
	 std::cout << "trgResultsHandle->accept(i): " << trgResultsHandle->accept(i) << std::endl;
       if(!passDoubleBTrig_np4){
	 failingModule=trgResultsHandle->index(i); 
       }
     }
     if ( (name.find("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2_v") != std::string::npos )) {
       passDoubleBTrig_np2=trgResultsHandle->accept(i);
     }
     if ( (name.find("HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17_v") != std::string::npos )) {
       passCSVTrig_p17=trgResultsHandle->accept(i);
     }
     if ( (name.find("HLT_AK8PFJet200_v") != std::string::npos )) {
       passMonitorAK8200Trig=trgResultsHandle->accept(i);
     }
     if ( (name.find("HLT_IsoMu30_v") != std::string::npos )) {
       passMonitorMuTrig=trgResultsHandle->accept(i);
     }
     if ( (name.find("HLT_AK8PFJet360_TrimMass30_v") != std::string::npos ) || (name.find("HLT_AK8PFJet380_TrimMass30_v") != std::string::npos ) || (name.find("HLT_AK8PFJet400_TrimMass30_v") != std::string::npos ) || (name.find("HLT_AK8PFJet420_TrimMass30_v") != std::string::npos )) {
       if (passMonitorAK8jetTrig == 99){
	passMonitorAK8jetTrig=trgResultsHandle->accept(i);
       }else if(passMonitorAK8jetTrig == 0){
        passMonitorAK8jetTrig=trgResultsHandle->accept(i);
       }
     }
     if ( (name.find("HLT_AK8PFJet420_TrimMass30_v") != std::string::npos ) ){
	passMonitorAK8420Trig=trgResultsHandle->accept(i);
     }
     
   }
   passMonitorAK8360Trig=passMonitorAK8jetTrig;
   
   
//   edm::Handle<pat::JetCollection> recoJetHandle;
//   iEvent.getByToken(recoJetLabel_, recoJetHandle);
   edm::Handle<std::vector<pat::Jet>> recoJetHandle;
   iEvent.getByToken(recoJetLabel_, recoJetHandle);
   if (!recoJetHandle.isValid()) {
     std::cout << "Error in getting slimmedJetsAK8 product from Event!" << std::endl;
     return;
   }
   
   std::vector<TLorentzVector> AK8jets;
   std::vector<double> recoAK8DoubleBs;
   std::vector<double> recoAK8SDmasses;

   for (const pat::Jet &jet : *recoJetHandle){
//   for (pat::Jet jet : *recoJetHandle){
//     std::cout << "jet.pt(): " << jet.pt() << std::endl;
//     std::cout << "ak8PFJetsPuppiSoftDropMass: " << jet.userFloat("ak8PFJetsPuppiSoftDropMass") << std::endl;
     recoAK8SDmasses.push_back(jet.userFloat("ak8PFJetsPuppiSoftDropMass"));
     TLorentzVector AK8jet(0., 0., 0., 0.);
     AK8jet.SetPtEtaPhiM(jet.pt(), jet.eta(), jet.phi(), jet.mass());
     AK8jets.push_back(AK8jet);
//     std::cout << "jet.pt(): " << jet.pt() << std::endl;
     for( const std::string &bDiscr : bDiscriminators_ ){
//      std::cout << "bDiscriminator: " << bDiscr << " "  << jet.bDiscriminator(bDiscr) << std::endl;
      if(bDiscr == "pfBoostedDoubleSecondaryVertexAK8BJetTags"){
	recoAK8DoubleBs.push_back(jet.bDiscriminator(bDiscr));
        recoAK8DoubleB = jet.bDiscriminator(bDiscr);
      }
      if (recoAK8DoubleB > maxRecoAK8DoubleB){
        maxRecoAK8DoubleB = recoAK8DoubleB;
      }
     }
   }

   if (AK8jets.size() > 0){   
     if (passDoubleBTrig_np4 && passMonitorMuTrig) {
       h1_recoAK8pT_DoubleBTrig_np4_Mumonitoring->Fill(AK8jets.at(0).Pt());
     }

     if (passDoubleBTrig_np4 && passMonitorAK8200Trig) {
       h1_recoAK8pT_DoubleBTrig_np4_monitoring->Fill(AK8jets.at(0).Pt());
       h1_recoAK8mass_DoubleBTrig_np4_monitoring->Fill(recoAK8SDmasses.at(0));
     }
     if (passDoubleBTrig_np2 && passMonitorAK8200Trig) {
       h1_recoAK8pT_DoubleBTrig_np2_monitoring->Fill(AK8jets.at(0).Pt());
       h1_recoAK8eta_DoubleBTrig_np2_monitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DoubleBTrig_np2_monitoring->Fill(AK8jets.at(0).Phi());
       h1_recoAK8mass_DoubleBTrig_np2_monitoring->Fill(recoAK8SDmasses.at(0));
     }

     if (passDoubleBTrig_np4 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np4_DB00_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np2 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np2_DB00_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np4 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.3 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np4_DB03_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np2 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.3 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np2_DB03_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np4 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.6 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np4_DB06_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np2 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.6 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np2_DB06_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np4 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np4_DB09_SD40_monitoring->Fill(AK8jets.at(0).Pt());
       h1_recoAK8eta_DoubleBTrig_np4_DB09_SD40_monitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DoubleBTrig_np4_DB09_SD40_monitoring->Fill(AK8jets.at(0).Phi());
     }
     if (passDoubleBTrig_np2 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np2_DB09_SD40_monitoring->Fill(AK8jets.at(0).Pt());
       h1_recoAK8eta_DoubleBTrig_np2_DB09_SD40_monitoring->Fill(AK8jets.at(0).Phi());
       h1_recoAK8phi_DoubleBTrig_np2_DB09_SD40_monitoring->Fill(AK8jets.at(0).Eta());
     }



     if (passDoubleBTrig_np4 && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np4_DB00_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np2 && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np2_DB00_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np4 && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np4_DB09_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np2 && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np2_DB09_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
     }


     if ((passMonitorAK8420Trig||passDoubleBTrig_np4) && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_420JetTrigORDoubleB_DB00_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if ((passMonitorAK8420Trig||passDoubleBTrig_np4) && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_420JetTrigORDoubleB_DB09_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if ((passMonitorAK8420Trig||passDoubleBTrig_np4) && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_420JetTrigORDoubleB_DB00_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
     }
     if ((passMonitorAK8420Trig||passDoubleBTrig_np4) && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_420JetTrigORDoubleB_DB09_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
     }


     if (passMonitorAK8420Trig && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_420JetTrig_DB00_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passMonitorAK8420Trig && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_420JetTrig_DB09_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passMonitorAK8420Trig && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_420JetTrig_DB00_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passMonitorAK8420Trig && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_420JetTrig_DB09_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
     }



     if (passDoubleBTrig_np4 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40 && AK8jets.at(0).Pt() > 450) {
       h1_recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450_monitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450_monitoring->Fill(AK8jets.at(0).Phi());
     }
     if (passDoubleBTrig_np2 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40 && AK8jets.at(0).Pt() > 450) {
       h1_recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450_monitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450_monitoring->Fill(AK8jets.at(0).Phi());
     }


     if (passDoubleBTrig_np4 && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40 && AK8jets.at(0).Pt() > 450) {
       h1_recoAK8eta_DoubleBTrig_np4_DB09_SD40_pT450_Mumonitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DoubleBTrig_np4_DB09_SD40_pT450_Mumonitoring->Fill(AK8jets.at(0).Phi());
     }
     if (passDoubleBTrig_np2 && passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0)>40 && AK8jets.at(0).Pt() > 450) {
       h1_recoAK8eta_DoubleBTrig_np2_DB09_SD40_pT450_Mumonitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DoubleBTrig_np2_DB09_SD40_pT450_Mumonitoring->Fill(AK8jets.at(0).Phi());
     }



     if (passDoubleBTrig_np4 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)<0.3 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np4_DB03Inv_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passDoubleBTrig_np2 && passMonitorAK8200Trig && recoAK8DoubleBs.at(0)<0.3 && recoAK8SDmasses.at(0)>40) {
       h1_recoAK8pT_DoubleBTrig_np2_DB03Inv_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }

     if (passMonitorAK8200Trig) {
       h1_failingModule->Fill(failingModule);
       h1_recoAK8pT_monitoring->Fill(AK8jets.at(0).Pt());
       h1_recoAK8mass_monitoring->Fill(recoAK8SDmasses.at(0));
     }

     if (passMonitorMuTrig) {
       h1_failingModule_Mu->Fill(failingModule);
     }


     if (passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0) > 40) {
       h1_failingModule_DB00_SD40->Fill(failingModule);
       h1_recoAK8pT_DB00_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.3 && recoAK8SDmasses.at(0) > 40) {
       h1_recoAK8pT_DB03_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.6 && recoAK8SDmasses.at(0) > 40) {
       h1_recoAK8pT_DB06_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }
     if (passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0) > 40) {
       h1_failingModule_DB09_SD40->Fill(failingModule);
       h1_recoAK8pT_DB09_SD40_monitoring->Fill(AK8jets.at(0).Pt());
       h1_recoAK8eta_DB09_SD40_monitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DB09_SD40_monitoring->Fill(AK8jets.at(0).Phi());
     }
     if (passMonitorAK8200Trig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0) > 40 && AK8jets.at(0).Pt() > 450) {
       h1_failingModule_DB09_SD40_pT450->Fill(failingModule);
       h1_recoAK8eta_DB09_SD40_pT450_monitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DB09_SD40_pT450_monitoring->Fill(AK8jets.at(0).Phi());
     }


     if (passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.0 && recoAK8SDmasses.at(0) > 40) {
       h1_recoAK8pT_DB00_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
       h1_failingModule_DB00_SD40_Mu->Fill(failingModule);
     }
     if (passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0) > 40) {
       h1_recoAK8pT_DB09_SD40_Mumonitoring->Fill(AK8jets.at(0).Pt());
       h1_failingModule_DB09_SD40_Mu->Fill(failingModule);
     }
     if (passMonitorMuTrig && recoAK8DoubleBs.at(0)>0.9 && recoAK8SDmasses.at(0) > 40 && AK8jets.at(0).Pt() > 450) {
       h1_failingModule_DB09_SD40_pT450_Mu->Fill(failingModule);
       h1_recoAK8eta_DB09_SD40_pT450_Mumonitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DB09_SD40_pT450_Mumonitoring->Fill(AK8jets.at(0).Phi());
     }


     if (passMonitorAK8200Trig && recoAK8DoubleBs.at(0)<0.3 && recoAK8SDmasses.at(0) > 40) {
       h1_recoAK8pT_DB03Inv_SD40_monitoring->Fill(AK8jets.at(0).Pt());
     }


     if (passDoubleBTrig_np4 && passMonitorAK8360Trig && recoAK8SDmasses.at(0) > 40) {
       h1_recoAK8DoubleB_DoubleBTrig_np4_SD40_monitoring->Fill(recoAK8DoubleBs.at(0));
       h1_recoAK8MaxDoubleB_DoubleBTrig_np4_SD40_monitoring->Fill(maxRecoAK8DoubleB);
     }
     if (passDoubleBTrig_np2 && passMonitorAK8360Trig && recoAK8SDmasses.at(0) > 40) {
       h1_recoAK8DoubleB_DoubleBTrig_np2_SD40_monitoring->Fill(recoAK8DoubleBs.at(0));
       h1_recoAK8MaxDoubleB_DoubleBTrig_np2_SD40_monitoring->Fill(maxRecoAK8DoubleB);
     }

     if (passCSVTrig_p17 && passMonitorAK8360Trig && AK8jets.at(0).Pt() > 450) {
       h1_recoAK8DoubleB_CSVTrig_p17_pT450_monitoring->Fill(recoAK8DoubleBs.at(0));
     }
     if (passDoubleBTrig_np4 && passMonitorAK8360Trig) {
       h1_recoAK8eta_DoubleBTrig_np4_monitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DoubleBTrig_np4_monitoring->Fill(AK8jets.at(0).Phi());
       h1_recoAK8DoubleB_DoubleBTrig_np4_monitoring->Fill(recoAK8DoubleBs.at(0));     
       h1_recoAK8MaxDoubleB_DoubleBTrig_np4_monitoring->Fill(maxRecoAK8DoubleB);
     }
     if (passDoubleBTrig_np2 && passMonitorAK8360Trig) {
       h1_recoAK8eta_DoubleBTrig_np2_monitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_DoubleBTrig_np2_monitoring->Fill(AK8jets.at(0).Phi());
       h1_recoAK8DoubleB_DoubleBTrig_np2_monitoring->Fill(recoAK8DoubleBs.at(0));
       h1_recoAK8MaxDoubleB_DoubleBTrig_np2_monitoring->Fill(maxRecoAK8DoubleB); 
     }


     if (passDoubleBTrig_np4 && passMonitorAK8360Trig && AK8jets.at(0).Pt() > 450) {
       h1_recoAK8DoubleB_DoubleBTrig_np4_pT450_monitoring->Fill(recoAK8DoubleBs.at(0));
     }
     if (passDoubleBTrig_np2 && passMonitorAK8360Trig && AK8jets.at(0).Pt() > 450) {
       h1_recoAK8DoubleB_DoubleBTrig_np2_pT450_monitoring->Fill(recoAK8DoubleBs.at(0));
     }


     if (passMonitorAK8360Trig) {
       h1_recoAK8eta_monitoring->Fill(AK8jets.at(0).Eta());
       h1_recoAK8phi_monitoring->Fill(AK8jets.at(0).Phi());
       h1_recoAK8DoubleB_monitoring->Fill(recoAK8DoubleBs.at(0));
       h1_recoAK8MaxDoubleB_monitoring->Fill(maxRecoAK8DoubleB);
     }
     if (passMonitorAK8360Trig && recoAK8SDmasses.at(0) > 40) {
       h1_recoAK8DoubleB_SD40_monitoring->Fill(recoAK8DoubleBs.at(0));
       h1_recoAK8MaxDoubleB_SD40_monitoring->Fill(maxRecoAK8DoubleB);
     }
     if (passMonitorAK8360Trig && AK8jets.at(0).Pt() > 450) {
       h1_recoAK8DoubleB_pT450_monitoring->Fill(recoAK8DoubleBs.at(0));
     }


   }


#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
DoubleBAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
DoubleBAnalyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
DoubleBAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(DoubleBAnalyzer);
