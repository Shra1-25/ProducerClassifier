import FWCore.ParameterSet.Config as cms 

ProducerFrames = cms.EDProducer('ProducerTest'
    , reducedEBRecHitCollection = cms.InputTag('reducedEcalRecHitsEB')
    , photonCollection = cms.InputTag('slimmedPhotons'))
