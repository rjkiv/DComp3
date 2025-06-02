#pragma once
#include "../math/Vec.h"
#include "HamEnums.h"

// Ham1NodeWeight size: 0x14
struct Ham1NodeWeight {
    bool unk0;
    float unk4; // seen this assigned to ScaleOp's mPerfectDist
    float unk8; // seen this assigned to ScaleOp's mRate
    float unkc; // seen this assigned to ScaleOp's mPerfectDist
    float unk10; // seen this assigned to ScaleOp's mRate
};

// Ham2FrameWeight size: 0x24
struct Ham2FrameWeight {
    float unk0;
    float unk4[4];
    float unk14[4];
};

// MoveFrame size: 0x11b0
class MoveFrame {
public:
    enum NodeCounts {
        // for DC1
        kNumHam1Nodes = 16
    };

    float QuantizedSeconds(float) const;
    const Ham1NodeWeight& NodeWeightHam1(int, MoveMode, MoveMirrored) const;
    Vector3const& NodeWeight(int, MoveMirrored) const;
    Vector3const& NodeInverseScale(int, MoveMirrored) const;
    const Ham2FrameWeight& FrameWeight(MoveMirrored) const;
    void Save(BinStream&) const;
    void SetNodeScale(int, MoveMirrored, Vector3const&);
    void Load(BinStreamRev&);
private:
    float unk0; // 0x0 - beat?
    int unk4; // 0x4
    Ham1NodeWeight mHam1NodeWeights[kNumHam1Nodes][4]; // 0x8
    Vector3const mNodeWeights[kMaxNumErrorNodes][kNumMoveMirrored]; // 0x508
    Vector3const mNodeScales[kMaxNumErrorNodes][kNumMoveMirrored]; // 0x928
    Vector3const mNodesInverseScale[kMaxNumErrorNodes][kNumMoveMirrored]; // 0xd48
    Ham2FrameWeight mFrameWeights[kNumMoveMirrored]; // 0x1168
};