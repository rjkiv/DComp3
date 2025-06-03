#pragma once

class CharBones {
public:    
    enum Type {
        TYPE_POS = 0,
        TYPE_SCALE = 1,
        TYPE_QUAT = 2,
        TYPE_ROTX = 3,
        TYPE_ROTY = 4,
        TYPE_ROTZ = 5,
        TYPE_END = 6,
        NUM_TYPES = 7,
    };

    enum CompressionType {
        kCompressNone,
        kCompressRots,
        kCompressVects,
        kCompressQuats,
        kCompressAll
    };

    struct Bone {
        Symbol name;
        float weight;

        // BinStream saving is just << name << weight
    };

    CharBones();
    virtual ~CharBones() {}
    virtual void ScaleAdd(CharClip *, float, float, float);
    virtual void Print();
protected:
    virtual void ReallocateInternal(){}

    CompressionType mCompression; // 0x4
    std::vector<Bone> mBones; // 0x8
    char* mStart; // 0x14
    int mCounts[NUM_TYPES]; // 0x18
    int mOffsets[NUM_TYPES]; // 0x34
    int mTotalSize; // 0x50
};