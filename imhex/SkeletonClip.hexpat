#pragma endian big

#include <common>
#include <enums>

struct SkeletonClipMoveRating {
    String name;
    Symbol expected;
    u32 unkc;
};

struct SkeletonClip {
    Revs skelClipRevs;
    RndAnimatable superAnim;
    HmxObject superObject;
    String filePath;
    u32 numMoveRatings;
    SkeletonClipMoveRating moveRatings[numMoveRatings];
    u32 unk1240;
    bool autoPlay;
    Symbol defaultRating;
    // TODO: there's a slightly different thing that happens if gAltRev is 0 - maybe some DC3 DLC files will do this?
    u32 weighted;
};

SkeletonClip skelClip @ 0;