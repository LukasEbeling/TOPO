# TOPO
Repository for topological trigger hls4ml models. As of now, only model v5 makes use of proper namespaces. Use older versions for testing only. 

##Versioning

**V1**
First model trained on di-Higgs production events (single muon + b jets final state). 

**V2**
Revised model after including `hwQual` feature for muons.

**V3**
Model with fewer layers (but with sigmoid) to meet latency requirements

**V4**
Retrained model after exlcuding final sigmoid application. Work in Progress.

**V5**
- starting with same python model as v3
- triggerflow was used to convert the model
- second-to-last layer (before sigmoid) used as final output, i.e. bypass of sigmoid layer
- scaling uses ap_fixed<32,23> internally to allow bitshift 
