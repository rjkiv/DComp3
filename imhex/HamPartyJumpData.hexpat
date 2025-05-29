#pragma endian big

#include <common>
#include <enums>

struct JumpPair {
    u32 fromMeasure;
    u32 toMeasure;
};

struct HamPartyJumpData {
    Revs jumpDataRevs;
    HmxObject superObject;
    u32 numJumps;
    JumpPair jumps[numJumps];
};

HamPartyJumpData jumpData @ 0;