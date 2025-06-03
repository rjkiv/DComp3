#pragma endian big
#pragma once

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

struct Revs {
    u16 altRev;
    u16 rev;
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

struct ShortVector3 {
    s16 x, y, z;
};

struct Vector3 {
    float x, y, z;
};

struct ByteQuat {
    s8 x, y, z, w;
};

struct ShortQuat {
    s16 x, y, z, w;
};

struct Quat {
    float x, y, z, w;
};

struct Color {
    float r, g, b, a;
};

struct TypeProps {
    bool hasTypeProps;
    if (hasTypeProps) {
        DataArray mMap;
    }
};

struct HmxObject {
    Revs objRev;
    Symbol objType;
    TypeProps typeProps;
    String objName;
};

enum AnimRate: u32 {
    k30_fps = 0,
    k480_fpb = 1,
    k30_fps_ui = 2,
    k1_fpb = 3,
    k30_fps_tutorial = 4
};

struct RndAnimatable {
    Revs animRev;
    float frame;
    AnimRate rate;
};