#pragma endian big
#pragma once

enum MoveRating: u32 {
    kMoveRatingSuperPerfect = 0,
    kMoveRatingPerfect = 1,
    kMoveRatingAwesome = 2,
    kMoveRatingOk = 3,
    kNumMoveRatings = 4
};

enum Difficulty: u32 {
    kDifficultyEasy = 0,
    kDifficultyMedium = 1,
    kDifficultyExpert = 2,
    kDifficultyBeginner = 3,
    kNumDifficulties = 4
};

enum SkeletonJoint: u32 {
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

enum SkeletonCoordSys: u32 {
    kCoordCamera = 0,
    kCoordLeftArm = 1,
    kCoordRightArm = 2,
    kCoordLeftLeg = 3,
    kCoordRightLeg = 4
};

enum SkeletonBone: u32 {
    kBoneHead = 0,
    kBoneCollarRight = 1,
    kBoneArmUpperRight = 2,
    kBoneArmUpperLeft = 3,
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

enum MoveMirrored: u32 {
    kMirroredNo = 0,
    kMirroredYes = 1,
    kNumMoveMirrored = 2
};