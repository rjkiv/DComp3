#pragma endian big

#include <common>
#include <enums>

enum PropKeysAnimType: u32 {
    kFloat,
    kColor,
    kObject,
    kBool,
    kQuat,
    kVector3,
    kSymbol
};

struct PropKeys {
    PropKeysAnimType keysType;
    String target;
    bool hasDataArray;
    if(hasDataArray){
        DataArray prop;
    }
    u32 interpolation;
    Symbol interpHandler;
    u32 exceptionID;
    bool unk34;
};

struct FloatKey {
    float value;
    float frame;
};

struct FloatKeys {
    PropKeys super_PropKeys;
    u32 numKeys;
    FloatKey keys[numKeys];
};

struct ColorKey {
    Color value;
    float frame;
};

struct ColorKeys {
    PropKeys super_PropKeys;
    u32 numKeys;
    ColorKey keys[numKeys];
};

struct ObjectKey {
    String value1;
    String value2;
    float frame;
};

struct ObjectKeys {
    PropKeys super_PropKeys;
    u32 numKeys;
    ObjectKey keys[numKeys];
};

struct BoolKey {
    bool value;
    float frame;
};

struct BoolKeys {
    PropKeys super_PropKeys;
    u32 numKeys;
    BoolKey keys[numKeys];
};

struct QuatKey {
    Quat value;
    float frame;
};

struct QuatKeys {
    PropKeys super_PropKeys;
    u32 numKeys;
    QuatKey keys[numKeys];
};

struct Vector3Key {
    Vector3 value;
    float frame;
};

struct Vector3Keys {
    PropKeys super_PropKeys;
    u32 numKeys;
    Vector3Key keys[numKeys];
};

struct SymbolKey {
    Symbol value;
    float frame;
};

struct SymbolKeys {
    PropKeys super_PropKeys;
    u32 numKeys;
    SymbolKey keys[numKeys];
};

struct PropKeysPair {
    u32 type;
    match (type) {
        (0): FloatKeys floatKeys;
        (1): ColorKeys colorKeys;
        (2): ObjectKeys objKeys;
        (3): BoolKeys boolKeys;
        (4): QuatKeys quatKeys;
        (5): Vector3Keys vec3Keys;
        (6): SymbolKeys symKeys;

        (_): {
            std::error(std::format("Invalid PropKeys type value {}", type));
            return;
        }
    }
};

struct RndPropAnim {
    u32 propAnimRev;
    HmxObject superObject;
    RndAnimatable superAnimatable;
    u32 numPropKeys;
    PropKeysPair propKeys[numPropKeys];
    bool loop;
    u32 numFlowLabels;
    String flowLabels[numFlowLabels];
    float intensity;
};