#pragma once
#include "ErrorNode.h"

// see examples in config/scoring.dta

// FilterVersion size: 0x9c
class FilterVersion {
protected:
    FilterVersion(FilterVersionType, const DataArray*);

    Symbol mFilterVersionSym; // 0x4 - i've seen it be either ham1 or ham2
    FilterVersionType mType; // 0x8
    ScaleOp mScaleOp; // 0xc
    ErrorNode* mErrorNodes[kMaxNumErrorNodes]; // 0x18

    static int sNumHam2Nodes;
public:
    virtual ~FilterVersion(){}
    virtual void NodeInput(int, const DetectFrame*, MoveMode, ErrorNodeInput&) const = 0;
    virtual int NumNodes() const = 0;

    static FilterVersion* Create(const DataArray*);
    static void operator delete(void*);
};

// Ham1FilterVersion size: 0x9c
class Ham1FilterVersion : public FilterVersion {
public:
    Ham1FilterVersion(FilterVersionType, const DataArray*);
    virtual ~Ham1FilterVersion(){}
    virtual void NodeInput(int, const DetectFrame*, MoveMode, ErrorNodeInput&) const;
    // Ham1 era error nodes:
    // Euclidean (4): l_elbow, l_hand, r_elbow, r_hand
    // Displacement (12): l_shoulder_disp, l_elbow_disp, l_hand_disp, r_shoulder_disp, r_elbow_disp, r_hand_disp, l_knee_disp, l_foot_disp, r_knee_disp, r_foot_disp, hip_disp, head_disp
    virtual int NumNodes() const { return 16; }
};

// Ham2FilterVersion size: 0x9c
class Ham2FilterVersion : public FilterVersion {
public:
    Ham2FilterVersion(FilterVersionType, const DataArray*);
    virtual ~Ham2FilterVersion(){}
    virtual void NodeInput(int, const DetectFrame*, MoveMode, ErrorNodeInput&) const;
    // Ham2 era error nodes:
    // Displacement (17):
    //      l_shoulder_vdisp, l_elbow_vdisp, l_wrist_vdisp, l_hand_vdisp, r_shoulder_vdisp, r_elbow_vdisp,
    //      r_wrist_vdisp, r_hand_vdisp, l_knee_vdisp, l_ankle_vdisp, l_foot_vdisp, r_knee_vdisp,
    //      r_ankle_vdisp, r_foot_vdisp, hip_vdisp, shoulder_vdisp, head_vdisp
    // Position (16):
    //      l_shoulder_vpos, l_elbow_vpos, l_wrist_vpos, l_hand_vpos, r_shoulder_vpos, r_elbow_vpos, r_wrist_vpos, r_hand_vpos
    //      l_knee_vpos, l_ankle_vpos, l_foot_vpos, r_knee_vpos, r_ankle_vpos, r_foot_vpos, shoulder_vpos, head_vpos
    virtual int NumNodes() const { return sNumHam2Nodes; }
};