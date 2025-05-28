#pragma endian big

#include <common>
#include <enums>

struct HamSupereasyMeasure {
    Symbol first;
    Symbol second;
    Symbol preferred;
};

struct HamSupereasyData {
    Revs superEZDataRev;
    HmxObject superObject;
    u32 numMeasures;
    HamSupereasyMeasure measures[numMeasures];
};

HamSupereasyData super_ez_data @ 0;