#pragma endian big

#include <common>
#include <enums>

struct MoveCandidate {
    u32 revision;
    u32 adjacencyFlag;
    Symbol variantName;
    Symbol clipName;
    Symbol unk;
};

struct MoveVariant {
    u32 revision;
    Vector3 posOffset;
    Symbol clipName;
    Symbol moveName;
    Symbol moveMiloname;
    Symbol genre;
    Symbol era;
    Symbol songName;
    float avgBeatsPerSec;
    u32 flags;
    bool hasLinksTo;
    if (hasLinksTo) {
        Symbol linksTo;
    }
    bool hasLinksFrom;
    if (hasLinksFrom) {
        Symbol linksFrom;
    }
    u32 prevCandidatesLen;
    MoveCandidate prevCandidates[prevCandidatesLen];
    u32 nextCandidatesLen;
    MoveCandidate nextCandidates[nextCandidatesLen];
};

struct MoveParent {
    u32 revision;
    Symbol name;
    Difficulty difficulty;
    u32 genreFlagsLen;
    Symbol genreFlags[genreFlagsLen];
    u32 eraFlagsLen;
    Symbol eraFlags[eraFlagsLen];
    bool unkc;
    Symbol displayName;
    u32 variantsLen;
    MoveVariant variants[variantsLen];
    
};

struct MoveGraph {
    u32 graphRev;
    HmxObject superObject;
    u32 numMoveParents;
    MoveParent moveParent[numMoveParents];
    DataArray moveArray;
};

MoveGraph graph @ 0;