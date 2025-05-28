#pragma endian big
#pragma once

#include <common>
#include <enums>

struct CamJointPair {
    Vector3 pos;
    Vector3 displacement;
};

struct DancerFrame {
    u16 unk0;
    u16 unk2;
    CamJointPair camJointPairs[SkeletonJoint::kNumJoints];
    u32 elapsedMs;
};

struct DancerSequence {
    u32 seqRev;
    HmxObject superObject;
    RndAnimatable superAnim;
    u32 numDancerFrames;
    DancerFrame dancerFrames[numDancerFrames];
};