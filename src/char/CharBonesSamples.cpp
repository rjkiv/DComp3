#include "CharBonesSamples.h"
#include "CharBones.h"

void CharBonesSamples::Save(BinStream& bs){
    bs << 16;
    bs << mBones;
    for(int i = 0; i < NUM_TYPES; i++){
        bs << mCounts[i];
    }
    bs << mCompression;
    bs << mNumSamples;
    bs << mFrames;
    bool hasDelta;
    if(!bs.Cached() || (bs.GetPlatform() != kPlatformPS3 && bs.GetPlatform() != kPlatformXbox)){
        hasDelta = false;
    }
    else hasDelta = true;
    int delta = 0;
    if(hasDelta){
        delta = mOffsets[6] - mOffsets[0];
        delta = (delta + 0xfU & 0xfffffff0) - delta; // what on earth is this operation?
        MILO_ASSERT(delta >= 0 && delta < 16, 0x24C);
    }

    for(int i = 0; i < mNumSamples; i++){
        mStart = &mRawData[mTotalSize * i];

        if(mCompression >= kCompressVects){
            // write shorts
            for(Vector3* p = (Vector3*)mStart; p < (Vector3*)QuatOffset(); p++){
                bs << (short)p->x;
                bs << (short)p->y;
                bs << (short)p->z;
            }
        }
        else {
            // write vectors
            for(Vector3* p = (Vector3*)mStart; p < (Vector3*)QuatOffset(); p++){
                bs << *p;
                if(hasDelta) bs << 0.0f; // does this have something to do with Vector3's being 0x10 instead of 0xc?
            }
        }

        if(mCompression >= kCompressQuats){
            for(Hmx::Quat* p = (Hmx::Quat*)QuatOffset(); p < (Hmx::Quat*)RotXOffset(); p++){
                bs << (char)p->x;
                bs << (char)p->y;
                bs << (char)p->z;
                bs << (char)p->w;
            }
        }
        else if(mCompression != kCompressNone){
            for(Hmx::Quat* p = (Hmx::Quat*)QuatOffset(); p < (Hmx::Quat*)RotXOffset(); p++){
                bs << (short)p->x;
                bs << (short)p->y;
                bs << (short)p->z;
                bs << (short)p->w;
            }
        }
        else {
            for(Hmx::Quat* p = (Hmx::Quat*)QuatOffset(); p < (Hmx::Quat*)RotXOffset(); p++){
                bs << *p;
            }
        }

        if(mCompression != kCompressionNone){
            for(float* p = (float*)RotXOffset(); p < (float*)EndOffset(); p++){
                bs << (short)*p;
            }
        }
        else {
            for(float* p = (float*)RotXOffset(); p < (float*)EndOffset(); p++){
                bs << *p;
            }
        }

        if(hasDelta){
            int zeroes[4] = { 0, 0, 0, 0 };
            bs.Write(zeroes, delta);
        }
        if(bs.GetPlatform() == kPlatformWii && (i & 0x7F) == 0x7F){
            MarkChunk(bs);
        }
    }
}