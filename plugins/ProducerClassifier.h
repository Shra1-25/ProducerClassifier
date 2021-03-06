#ifndef ProducerClassifier_h
#define ProducerClassifier_h

#include <memory>
//#include <iostream>
//#include <fstream>
//#include <sstream>
#include <vector>
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/stream/EDProducer.h"
//#include "FWCore/Framework/interface/one/EDAnalyzer.h"
//#include "FWCore/Framework/src/one/implementorsMethods.h"

/*#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"

#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/TrackerGeometryBuilder/interface/StripGeomDetUnit.h"

#include "Calibration/IsolatedParticles/interface/DetIdFromEtaPhi.h"

#include "DQM/HcalCommon/interface/Constants.h"*/

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/Utilities/interface/StreamID.h"

/*#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h" // reco::PhotonCollection defined here
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHitFwd.h"*/
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TProfile2D.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TFrame.h"
#include "TBenchmark.h"
#include "TRandom.h"
#include "TSystem.h"
/*#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"*/
#include <iostream>
using namespace std;
//using pat::PhotonCollection;
//using pat::PhotonRef;

static const int vEB_frame_height=32;
static const int vEB_frame_width=32;

class ProducerClassifier : public edm::stream::EDProducer<> {
   public:
      
      explicit ProducerClassifier(const edm::ParameterSet&);
      ~ProducerClassifier();
      
      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginStream(edm::StreamID) override;
      virtual void produce(edm::Event&, const edm::EventSetup&) override;
      virtual void endStream() override;

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
      // Tokens 
      //edm::EDGetTokenT<PhotonCollection> photonCollectionT_;
      //edm::EDGetTokenT<std::vector<std::vector<float>>> frames_;
      static const int nPhotons = 2;
   
      std::vector<std::vector<float>> vEB_photon_frames;
   
      /*TTree* RHTree;
      unsigned int nPho;
      
      void branchesEB             ( TTree*, edm::Service<TFileService>& );
      void branchesPhotonSel      ( TTree*, edm::Service<TFileService>& );*/
      void fill_photons             ( const edm::Event&, const edm::EventSetup& );
      void predict_tf         ();
      
      std::vector<float> vIphi_Emax_;
      std::vector<float> vIeta_Emax_;
      std::vector<float> vSC_eta_;
      std::vector<float> vSC_phi_;
      //std::vector<int> vPreselPhoIdxs_;
      int nTotal, nPassed;
};

/*static const int EB_IPHI_MIN = EBDetId::MIN_IPHI;//1;
static const int EB_IPHI_MAX = EBDetId::MAX_IPHI;//360;
static const int EB_IETA_MIN = EBDetId::MIN_IETA;//1;
static const int EB_IETA_MAX = EBDetId::MAX_IETA;//85;
static const float zs = 0.;*/
#endif
//DEFINE_FWK_MODULE(ProducerClassifier);
