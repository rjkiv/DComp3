#pragma endian big
#pragma once

#include <common>
#include <enums>

struct Ham1NodeWeight {
    float unkFloat1, unkFloat2, unkFloat3, unkFloat4;
    bool unkBool;
};

struct Ham2FloatPair {
    float first, second;
};

struct Ham2FrameWeight {
    float unkFloat1;
    Ham2FloatPair pairs[4];
};

struct MoveFrame {
    float unk0; // beat?
    u32 unk4;
    u32 always16;
    Ham1NodeWeight mHam1NodeWeights[64];
    Ham2FrameWeight mFrameWeights;
    Ham2FrameWeight mFrameWeightsMirrored;
    u32 numHam2Nodes;
    Vector3 nodeWeights[numHam2Nodes];
    Vector3 nodeWeightsMirrored[numHam2Nodes];
    Vector3 nodeScales[numHam2Nodes];
    Vector3 nodeScalesMirrored[numHam2Nodes];
};