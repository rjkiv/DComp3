#include "CharBonesSamples.h"

void CharBonesSamples::Save(BinStream& bs){
    bs << 16;
    bs << mBones;
    int* ptr = (int*)mStart;
    for(int i = 0; i < NUM_TYPES; i++){
        ptr++;
        bs << *ptr;
    }
    bs << mCompression;
    bs << mNumSamples;
    bs << mFrames;
    bool b2;
    if(!bs.Cached() || (bs.GetPlatform() != kPlatformPS3 && bs.GetPlatform() != kPlatformXbox)){
        b2 = false;
    }
    else b2 = true;
    int delta = 0;
    if(b2){
        delta = mOffsets[6] - mOffsets[0];
        MILO_ASSERT(delta >= 0 && delta < 16, 0x24C);
    }

    // TODO: fill out this loop
    for(int i = 0; i < mNumSamples; i++){

    }
}