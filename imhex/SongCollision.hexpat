#pragma endian big

#include <common>
#include <enums>

struct BeatCollisionData {
    float minX, maxX;
    Vector3 offset;
};

struct BeatCollisionDataVector {
    u32 numDatas;
    BeatCollisionData datas[numDatas];
};

struct SongCollision {
    Revs songCollRev;
    HmxObject superObject;
    BeatCollisionDataVector dataVectors[Difficulty::kNumDifficulties];
};

SongCollision collision @ 0;