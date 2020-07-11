import FWCore.ParameterSet.Config as cms 

ProducerFrames = cms.EDProducer('ProducerClassifier'
    , frames_ = cms.InputTag('photon_frames'))
