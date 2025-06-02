#pragma once
#include "../obj/Data.h"

enum SkeletonBone {
    kBoneHead = 0,
    kBoneCollarRight = 1,
    kBoneArmUpperRight = 2,
    kBoneArmLowerRight = 3,
    kBoneHandRight = 4,
    kBoneCollarLeft = 5,
    kBoneArmUpperLeft = 6,
    kBoneArmLowerLeft = 7,
    kBoneHandLeft = 8,
    kBoneLegUpperRight = 9,
    kBoneLegLowerRight = 10,
    kBoneLegUpperLeft = 11,
    kBoneLegLowerLeft = 12,
    kBoneBackUpper = 13,
    kBoneBackLower = 14,
    kBoneHipRight = 15,
    kBoneHipLeft = 16,
    kBoneFootLeft = 17,
    kBoneFootRight = 18,
    kNumBones = 19
};

enum ErrorNodeType {
    kErrorJointHipCenter = 1,
    kErrorJointSpine = 2,
    kErrorJointShoulderCenter = 4,
    kErrorJointHead = 8,
    kErrorJointShoulderLeft = 0x10,
    kErrorJointElbowLeft = 0x20,
    kErrorJointWristLeft = 0x40,
    kErrorJointHandLeft = 0x80,
    kErrorJointShoulderRight = 0x100,
    kErrorJointElbowRight = 0x200,
    kErrorJointWristRight = 0x400,
    kErrorJointHandRight = 0x800,
    kErrorJointHipLeft = 0x1000,
    kErrorJointKneeLeft = 0x2000,
    kErrorJointAnkleLeft = 0x4000,
    kErrorJointHipRight = 0x8000,
    kErrorJointKneeRight = 0x10000,
    kErrorJointAnkleRight = 0x20000,
    kErrorJointFootLeft = 0x40000,
    kErrorJointFootRight = 0x80000,
    kErrorHam1Euclidean = 0x100000,
    kErrorHam1Displacement = 0x200000,
    kErrorDisplacement = 0x400000,
    kErrorPosition = 0x800000
};

enum FeedbackLimbs {
    kFeedbackLeftArm = 1,
    kFeedbackRightArm = 2,
    kFeedbackLeftLeg = 4,
    kFeedbackRightLeg = 8
};

enum SkeletonJoint {
    kJointHipCenter = 0,
    kJointSpine = 1,
    kJointShoulderCenter = 2,
    kJointHead = 3,
    kJointShoulderLeft = 4,
    kJointElbowLeft = 5,
    kJointWristLeft = 6,
    kJointHandLeft = 7,
    kJointShoulderRight = 8,
    kJointElbowRight = 9,
    kJointWristRight = 10,
    kJointHandRight = 11,
    kJointHipLeft = 12,
    kJointKneeLeft = 13,
    kJointAnkleLeft = 14,
    kJointHipRight = 15,
    kJointKneeRight = 16,
    kJointAnkleRight = 17,
    kJointFootLeft = 18,
    kJointFootRight = 19,
    kNumJoints = 20
};

enum SkeletonCoordSys {
    kCoordCamera = 0,
    kCoordLeftArm = 1,
    kCoordRightArm = 2,
    kCoordLeftLeg = 3,
    kCoordRightLeg = 4
};

enum NormBones {
    kMaxNumNormBones = 3
};

enum ErrorScaleType {
    kErrorScaleDist = 0,
    kErrorScaleDistSq = 1
};