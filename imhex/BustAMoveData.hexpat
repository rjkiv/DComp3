#pragma endian big

#include <common>
#include <enums>

struct BAMPhrase {
    u32 count;
    u32 bars;
};

struct BustAMoveData {
    Revs bamDataRevs;
    HmxObject superObject;
    u32 numPhrases;
    BAMPhrase phrases[numPhrases];
};

BustAMoveData bamData @ 0;