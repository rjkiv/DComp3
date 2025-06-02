#include "DancerSkeleton.h"

void DancerSkeleton::Write(BinStream& bs){
    for(int i = 0; i < kNumJoints; i++){
        bs << mCamJointPositions[i];
        bs << mCamJointDisplacements[i];
    }
    bs << mElapsedMs;
    bs << mTracked;
}

void DancerSkeleton::Read(BinStream& bs){
    for(int i = 0; i < kNumJoints; i++){
        bs >> mCamJointPositions[i];
        bs >> mCamJointDisplacements[i];
    }
    bs >> mElapsedMs;
    bs >> mTracked;
}