#include "CharClip.h"

void CharClip::Save(BinStream& bs){
    bs << 22;
    SAVE_SUPERCLASS(Hmx::Object);
    bs << mFramesPerSec;
    bs << mFlags;
    bs << mPlayFlags;
    bs << mRange;
    bs << mRelative;
    bs << mTransitionVersion;
    bs << mDoNotCompress;
    mTransitions.Save(bs);
    bs << mBeatEvents.size();
    for(int i = 0; i < mBeatEvents.size(); i++){
        mBeatEvents[i].Save(bs);
    }
    mFull.Save(bs);
    mOne.Save(bs);
    bs << unk180;
    bs << mBeatTrack;
    bs << mSyncAnim;
    bs << unk18c;
    bs << unk198;
}

void CharClip::Transitions::Save(BinStream& bs){
    int size = 0;
    int numNodes = 0;
    for(NodeVector* it = mNodeStart; it < mNodeEnd; it = (NodeVector *)(nodes + size)){
        numNodes++;
        size += it->size;
    }
    bs << size;
    bs << numNodes;
    for(NodeVector* it = mNodeStart; it < mNodeEnd; it = (NodeVector *)(nodes + size)){
        bs << it->clip->Name();
        bs << it->size;
        for(int i = 0; i < it->size; i++){
            bs << it->nodes[i].curBeat;
            bs << it->nodes[i].nextBeat;
        }
    }
}

void CharClip::BeatEvent::Save(BinStream& bs){
    bs << event;
    bs << beat;
}