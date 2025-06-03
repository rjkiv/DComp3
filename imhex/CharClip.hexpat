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

struct CharBonesSamples {
    Revs charBoneSamplesRevs;
    u32 numBones;
    Bone bones[numBones];
    u32 counts[CharBonesType::NUM_TYPES];
    CompressionType compression;
    u32 numSamples;
    u32 numFrames;
    float frames[numFrames];
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