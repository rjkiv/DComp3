#pragma endian big

#include <common>
#include <enums>

struct CharLipSync {
    Revs lipSyncRevs;
    HmxObject superObject;
    u32 numVisemes;
    String mVisemes[numVisemes];
    u32 numKeyFrames;
    u32 numData;
    u8 data[numData];
};

CharLipSync lipSync @ 0;