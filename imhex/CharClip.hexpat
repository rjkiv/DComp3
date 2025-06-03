#pragma endian big

#include <common>
#include <enums>

struct CharGraphNode {
    float curBeat;
    float nextBeat;
};

struct NodeVector {
    String clip;
    u32 size;
    CharGraphNode nodes[size];
};

struct Transitions {
    u32 size;
    u32 numNodes;
    NodeVector nodeVector[numNodes];
};

struct BeatEvent {
    Symbol event;
    float beat;
};

enum CharBonesType: u32 {
    TYPE_POS = 0,
    TYPE_SCALE = 1,
    TYPE_QUAT = 2,
    TYPE_ROTX = 3,
    TYPE_ROTY = 4,
    TYPE_ROTZ = 5,
    TYPE_END = 6,
    NUM_TYPES = 7
};

enum CompressionType: u32 {
    kCompressNone,
    kCompressRots,
    kCompressVects,
    kCompressQuats,
    kCompressAll
};

struct Bone {
    Symbol name;
    float weight;
};

struct Counts {
    u32 counts[CharBonesType::NUM_TYPES];
};

fn TypeSize(CharBonesType bType, CompressionType cType){
    if(bType == CharBonesType::TYPE_POS || bType == CharBonesType::TYPE_SCALE){
        if(cType >= CompressionType::kCompressVects) return 6;
        else return 12;
    }
    else if(bType == CharBonesType::TYPE_QUAT){
        if(cType >= CompressionType::kCompressQuats) return 4;
        else if(cType != CompressionType::kCompressNone) return 8;
        else return 16;
    }
    else if(cType != CompressionType::kCompressNone){
        return 2;
    }
    else return 4;
};

u32 mOffsets[CharBonesType::NUM_TYPES];
u32 mEndOffset;

fn RecomputeSizes(Counts cnts, CompressionType cType){
    // FIXME: the original RecomputeSizes doesn't iterate up to NUM_TYPES - 1, but rather NUM_TYPES
    for(u32 i = 0, i < CharBonesType::NUM_TYPES - 1, i += 1){
        mOffsets[i + 1] = (cnts.counts[i + 1] - cnts.counts[i]) * TypeSize(i, cType);
        std::print("Set mOffsets[{}] to {} = ({} - {}) * type size {}", i,
            mOffsets[i+1], cnts.counts[i+1], cnts.counts[i], TypeSize(i, cType));
    }
};

struct CharBonesSamples {
    Revs charBoneSamplesRevs;
    u32 numBones;
    Bone bones[numBones];
    Counts counts;
    CompressionType compression;
    u32 numSamples;
    u32 numFrames;
    float frames[numFrames];
    RecomputeSizes(counts, compression);
};

struct CharClip {
    Revs charClipRevs;
    HmxObject superObject;
    float framesPerSec;
    u32 flags;
    u32 playFlags;
    float range;
    String relative;
    u32 transitionVersion;
    bool doNotCompress;
    Transitions transitions;
    u32 numBeatEvents;
    BeatEvent beatEvents[numBeatEvents];
    CharBonesSamples full;
};

CharClip charClip @ 0;