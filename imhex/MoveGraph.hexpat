#pragma endian big

import std.io;

struct Symbol {
    u32 len;
    char value[len];
};

struct Glob {
    u32 length;
    u8 data[length];
};

enum Difficulty: u32 {
    easy,
    medium,
    expert,
    beginner
};

struct MoveCandidate {
    u32 revision;
    u32 adjacencyFlag;
    Symbol variantName;
    Symbol clipName;
    Symbol unk;
};

struct MoveVariant {
    u32 revision;
    u32 idkWhatThatIs[3];
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

using DataArray;

struct DataNode {
    u32 type;
    match (type) {
        (0): s32 integer;
        (1): float integer;
        (2): Symbol variable;
        (3): Symbol function;
        (4): Symbol object;
        (5): Symbol symbol;
        (6): s32 unhandled;

        (7): Symbol ifdef_directive;
        (8): s32 else_directive;
        (9): s32 endif_directive;

        (16): DataArray array;
        (17): DataArray command;
        (18): Symbol string;
        (19): DataArray property;
        (20): Glob glob;
        
        (32): Symbol define_directive;
        (33): Symbol include_directive;
        (34): Symbol merge_directive;
        (35): Symbol ifndef_directive;
        (36): s32 autorun_directive;
        (37): Symbol undefine_directive;

        (_): {
            std::error(std::format("Invalid DataNode type value {}", type));
            return;
        }
    }
};

struct DataArray {
    u16 length;
    u16 line;
    u16 deprecated;
    DataNode nodes[length];
};

struct MoveGraph {
    u32 num;
    MoveParent moveParent[num];
    DataArray moveArray;
};

struct MoveGraphFile {
    u32 graphRevision;
    u32 objectRevision;
    u8 typePropsStuff[9];
    MoveGraph moveGraph;
};

MoveGraphFile file @ 0;
