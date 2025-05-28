#pragma endian big

#include <common>
#include <enums>
#include <RndPropAnim_base>

struct HamMove {
    u32 moveRev;
    RndPropAnim superPropAnim;
};

HamMove move @ 0;