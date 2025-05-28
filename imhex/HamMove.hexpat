#pragma endian big

#include <common>
#include <enums>
#include <RndPropAnim_base>
#include <MoveFrame>

struct LocalizedName {
    Symbol language;
    String name;
};

struct MoveDataPair {
    float threshold;
    float override;
};

struct Confusability {
    u32 CRC;
    float value;
};

struct HamMove {
    u32 moveRev;
    RndPropAnim superPropAnim;
    String mirror;
    String texture;
    bool scored;
    bool finalPose;
    u32 numNames;
    LocalizedName localizedNames[numNames];
    u32 texState;
    u32 numMoveFrames;
    MoveFrame moveFrame[numMoveFrames];
    bool paradiddle;
    bool suppressGuide;
    bool suppressPracticeOptions;
    bool omitMinigame;
    u32 numRatingStates;
    float ratingStates[numRatingStates];
    bool shoulderDisplacements;
    MoveDataPair moveDataPairs[MoveRating::kNumMoveRatings];
    u32 numConfusabilities;
    Confusability confusabilities[numConfusabilities];
    u32 unk94;
    String dancerSequence;
    u32 confusabilityID;
};

HamMove move @ 0;