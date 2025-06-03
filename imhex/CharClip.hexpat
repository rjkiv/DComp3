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
u32 numVectors;
u32 numQuats;
u32 numRots;
CompressionType theTypeWereUsing;

fn RecomputeSizes(Counts cnts, CompressionType cType){
    for(u32 i = 0, i < CharBonesType::NUM_TYPES, i += 1){
        mOffsets[i] = 0;
    }
    // FIXME: the original RecomputeSizes doesn't iterate up to NUM_TYPES - 1, but rather NUM_TYPES
    // maybe that was a bug on HMX's part? either way, this func isn't 1:1
    for(u32 i = 0, i < CharBonesType::NUM_TYPES - 1, i += 1){
        mOffsets[i + 1] = mOffsets[i] + (cnts.counts[i + 1] - cnts.counts[i]) * TypeSize(i, cType);
        std::print("Set mOffsets[{}] to {} = {} + ({} - {}) * type size {}", i+1,
            mOffsets[i+1], mOffsets[i], cnts.counts[i+1], cnts.counts[i], TypeSize(i, cType));
    }
    //std::print("Total size: {}", mOffsets[6] + 0xFU & 0xFFFFFFF0);
    theTypeWereUsing = cType;
    numVectors = (mOffsets[2] - mOffsets[0]) / TypeSize(CharBonesType::TYPE_SCALE, theTypeWereUsing);
    //std::print("number of vectors: ({} - {}) / {} = {}",
    //    mOffsets[2], mOffsets[0], TypeSize(CharBonesType::TYPE_SCALE, theTypeWereUsing), numVectors);
       
    numQuats = (mOffsets[3] - mOffsets[2]) / TypeSize(CharBonesType::TYPE_QUAT, theTypeWereUsing);
    //std::print("number of quats: ({} - {}) / {} = {}",
    //    mOffsets[3], mOffsets[2], TypeSize(CharBonesType::TYPE_QUAT, theTypeWereUsing), numQuats);
    numRots = (mOffsets[6] - mOffsets[3]) / TypeSize(CharBonesType::TYPE_ROTX, theTypeWereUsing);
    //std::print("number of rots: ({} - {}) / {} = {}",
    //    mOffsets[6], mOffsets[3], TypeSize(CharBonesType::TYPE_ROTX, theTypeWereUsing), numRots);
};

struct SampleData {
    // the vectors
    if(theTypeWereUsing >= CompressionType::kCompressVects){
        ShortVector3 vectors[numVectors];
    }
    else {
        Vector3 vectors[numVectors];
    }
    
    // the quats
    if(theTypeWereUsing >= CompressionType::kCompressQuats){
        ByteQuat quats[numQuats];
    }
    else if(theTypeWereUsing != CompressionType::kCompressNone){
        ShortQuat quats[numQuats];
    }
    else {
        Quat quats[numQuats];
    }
    
    // finally, the rots
    if(theTypeWereUsing != CompressionType::kCompressNone){
        s16 rots[numRots];
    }
    else {
        float rots[numRots];
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
    SampleData sampleData[numSamples];
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
    //CharBonesSamples one;
};

CharClip charClip @ 0;