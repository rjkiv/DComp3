#pragma endian big

#include <common>
#include <enums>

struct Range {
    u32 start;
    u32 end;
};

enum PlayerFlags: u32 {
    kHamPlayer0 = 0,
    kHamPlayer1 = 1,
    kHamPlayerBoth = 2,
    kHamPlayerOff = 3,
    kHamPlayer0SoloInOut = 4,
    kHamPlayer1SoloInOut = 5
};

struct BattleStep {
    u32 mPlayers;
    Range mMusicRange;
    Range mPlayRange;
    Symbol mCam;
    Symbol mNonplayAction;
    Symbol mState;
};

struct HamBattleData {
    Revs hamBattleDataRevs;
    HmxObject superObject;
    u32 numBattleSteps;
    BattleStep battleSteps[numBattleSteps];
};

HamBattleData hbd @ 0;