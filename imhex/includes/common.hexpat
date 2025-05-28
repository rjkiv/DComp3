#pragma endian big

import std.io;

struct Symbol {
    u32 symLen;
    char sym[symLen];
};

struct String {
    u32 strLen;
    char cStr[strLen];
};

struct Glob {
    u32 length;
    u8 data[length];
};

using DataArray;

struct DataNode {
    u32 type;
    match (type) {
        (0): s32 integer;
        (1): float real;
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

struct Vector3 {
    float x;
    float y;
    float z;
};

struct TypeProps {
    bool hasTypeProps;
    if (hasTypeProps) {
        DataArray mMap;
    }
};

struct HmxObject {
    u32 objRev;
    Symbol objType;
    TypeProps typeProps;
    String objName;
};