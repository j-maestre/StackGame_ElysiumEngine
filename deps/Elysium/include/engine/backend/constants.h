#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__ 1

enum class Type {
    kType_None = 0x0,
    kT_Float1,
    kT_Float2,
    kT_Float3,
    kT_Float4,

    kT_Double1,
    kT_Double2,
    kT_Double3,
    kT_Double4,

    kT_Int1,
    kT_Int2,
    kT_Int3,
    kT_Int4,

    kT_Uint1,
    kT_Uint2,
    kT_Uint3,
    kT_Uint4,

    kT_Byte1,
    kT_Byte2,
    kT_Byte3,
    kT_Byte4,

    kT_UByte1,
    kT_UByte2,
    kT_UByte3,
    kT_UByte4,

    kT_Short1,
    kT_Short2,
    kT_Short3,
    kT_Short4,

    kT_UShort1,
    kT_UShort2,
    kT_UShort3,
    kT_UShort4,

    kT_Mat4x4,
    kT_Mat3x3,
    kT_Mat2x2,

    kT_Sampler1D,
    kT_Sampler2D,
    kT_Sampler3D,

};

#endif
