#pragma once

struct CharGraphNode {
    float curBeat;
    float nextBeat;
};

// CharClip size: 0x19c
class CharClip : public Hmx::Object {
public:
    // NodeVector size: 0x20(?)
    class NodeVector {
    public:
        ObjPtr<CharClip> clip; // 0x0
        int size; // 0x14
        CharGraphNode nodes[1]; // 0x18
    };

    // Transitions size: 0x10
    class Transitions : public ObjRefOwner {
    public:
        Transitions(){}
        virtual ~Transitions(){}
        virtual Hmx::Object* RefOwner() const { return mOwner; }
        virtual bool Replace(ObjRef*, Hmx::Object*);

        NodeVector* mNodeStart; // 0x4
        NodeVector* mNodeEnd; // 0x8
        Hmx::Object* mOwner; // 0xc
    };

    class BeatEvent {
    public:
        Symbol event;
        float beat;
    };

    // FacingSet size: 0x10
    class FacingSet {
    public:
        struct FacingBones {

        };

        int mFullRot; // 0x0
        int mFullPos; // 0x4
        FacingBones* mFacingBones; // 0x8
        float mWeight; // 0xc
    };

    Transitions mTransitions; // 0x2c
    float mFramesPerSec; // 0x3c
    Keys<float, float> mBeatTrack; // 0x40
    int mFlags; // 0x4c
    int mPlayFlags; // 0x50
    float mRange; // 0x54
    ObjPtr<CharClip> mRelative; // 0x58
    std::vector<BeatEvent> mBeatEvents; // 0x6c
    bool mDirty; // 0x78
    int mTransitionVersion; // 0x7c
    bool mDoNotCompress; // 0x80
    ObjPtr<RndAnimatable> mSyncAnim; // 0x84
    CharBonesSamples mFull; // 0x98
    CharBonesSamples mOne; // 0x104
    FacingSet mFacing; // 0x170
    std::vector<CharBones::Bone> unk180; // 0x180
    std::vector<std::map<int, float> > unk18c; // 0x18c
    int unk198; // 0x198
};