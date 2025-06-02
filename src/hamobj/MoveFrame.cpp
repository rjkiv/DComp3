#include "MoveFrame.h"

BinStream& operator<<(BinStream& bs, Ham1NodeWeight& obj){
    bs << obj.unk4 << obj.unk8 << obj.unkc << obj.unk10 << obj.unk0;
}

BinStream& operator<<(BinStream& bs, Ham2FrameWeight& obj){
    bs << obj.unk0;
    for(int i = 0; i < 4; i++){
        bs << obj.unk4[i] << obj.unk14[i];
    }
}

void MoveFrame::Save(BinStream& bs){
    bs << unk0 << unk4 << 16;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){ // num mirrors?
            for(int k = 0; k < 16; k++){
                bs << mHam1NodeWeights[k][i + j];
            }
        }
    }

    for(int i = 0; i < kNumMoveMirrored; i++){
        bs << mFrameWeights[i];
    }

    bs << FilterVersion::sNumHam2Nodes; // gets set in FilterVersion's ctor

    for(int i = 0; i < 2; i++){ // num mirrors?
        for(int j = 0; j < FilterVersion::sNumHam2Nodes; j++){
            bs << mNodeWeights[j][i];
            bs << mNodeScales[j][i];
        }
    }
}