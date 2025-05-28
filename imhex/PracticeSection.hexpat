#pragma endian big

#include <common>
#include <enums>
#include <DancerSequence_base>

struct PracticeStep {
    Symbol type;
    Symbol start;
    Symbol end;
    bool boundary;
    String nameOverride;
};

struct PracticeSection {
    Revs pracSectRevs;
    HmxObject superObject;
    RndAnimatable superAnim;
    Symbol displayName;
    Difficulty difficulty;
    u32 numSteps;
    PracticeStep steps[numSteps];
    u32 numDancerSeqs;
    DancerSequence dancerSeqs[numDancerSeqs];
    u32 testStepSequence;
};

PracticeSection pracSect @ 0;