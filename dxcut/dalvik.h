/*
Copyright (C) 2010 Mark Gordon

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*! \file dalvik.h
 */
#ifndef __DXCUT_DALVIK_H
#define __DXCUT_DALVIK_H
#include <dxcut/dex.h>
#ifdef __cplusplus
extern "C" {
#endif

/** \enum DexOpCode
 *  The dalvik opcodes.  Opcodes index right into the dex_opcode_formats array
 *  to get formatting information for the given opcode.
 *
 *  Opcode list comes from libdex/OpCode.h
 */
typedef enum DexOpCode {
  OP_PSUEDO                       = 0x00,
  OP_NOP                          = 0x00,
  OP_MOVE                         = 0x01,
  OP_MOVE_FROM16                  = 0x02,
  OP_MOVE_16                      = 0x03,
  OP_MOVE_WIDE                    = 0x04,
  OP_MOVE_WIDE_FROM16             = 0x05,
  OP_MOVE_WIDE_16                 = 0x06,
  OP_MOVE_OBJECT                  = 0x07,
  OP_MOVE_OBJECT_FROM16           = 0x08,
  OP_MOVE_OBJECT_16               = 0x09,
  OP_MOVE_RESULT                  = 0x0a,
  OP_MOVE_RESULT_WIDE             = 0x0b,
  OP_MOVE_RESULT_OBJECT           = 0x0c,
  OP_MOVE_EXCEPTION               = 0x0d,
  OP_RETURN_VOID                  = 0x0e,
  OP_RETURN                       = 0x0f,
  OP_RETURN_WIDE                  = 0x10,
  OP_RETURN_OBJECT                = 0x11,
  OP_CONST_4                      = 0x12,
  OP_CONST_16                     = 0x13,
  OP_CONST                        = 0x14,
  OP_CONST_HIGH16                 = 0x15,
  OP_CONST_WIDE_16                = 0x16,
  OP_CONST_WIDE_32                = 0x17,
  OP_CONST_WIDE                   = 0x18,
  OP_CONST_WIDE_HIGH16            = 0x19,
  OP_CONST_STRING                 = 0x1a,
  OP_CONST_STRING_JUMBO           = 0x1b,
  OP_CONST_CLASS                  = 0x1c,
  OP_MONITOR_ENTER                = 0x1d,
  OP_MONITOR_EXIT                 = 0x1e,
  OP_CHECK_CAST                   = 0x1f,
  OP_INSTANCE_OF                  = 0x20,
  OP_ARRAY_LENGTH                 = 0x21,
  OP_NEW_INSTANCE                 = 0x22,
  OP_NEW_ARRAY                    = 0x23,
  OP_FILLED_NEW_ARRAY             = 0x24,
  OP_FILLED_NEW_ARRAY_RANGE       = 0x25,
  OP_FILL_ARRAY_DATA              = 0x26,
  OP_THROW                        = 0x27,
  OP_GOTO                         = 0x28,
  OP_GOTO_16                      = 0x29,
  OP_GOTO_32                      = 0x2a,
  OP_PACKED_SWITCH                = 0x2b,
  OP_SPARSE_SWITCH                = 0x2c,
  OP_CMPL_FLOAT                   = 0x2d,
  OP_CMPG_FLOAT                   = 0x2e,
  OP_CMPL_DOUBLE                  = 0x2f,
  OP_CMPG_DOUBLE                  = 0x30,
  OP_CMP_LONG                     = 0x31,
  OP_IF_EQ                        = 0x32,
  OP_IF_NE                        = 0x33,
  OP_IF_LT                        = 0x34,
  OP_IF_GE                        = 0x35,
  OP_IF_GT                        = 0x36,
  OP_IF_LE                        = 0x37,
  OP_IF_EQZ                       = 0x38,
  OP_IF_NEZ                       = 0x39,
  OP_IF_LTZ                       = 0x3a,
  OP_IF_GEZ                       = 0x3b,
  OP_IF_GTZ                       = 0x3c,
  OP_IF_LEZ                       = 0x3d,
  OP_UNUSED_3E                    = 0x3e,
  OP_UNUSED_3F                    = 0x3f,
  OP_UNUSED_40                    = 0x40,
  OP_UNUSED_41                    = 0x41,
  OP_UNUSED_42                    = 0x42,
  OP_UNUSED_43                    = 0x43,
  OP_AGET                         = 0x44,
  OP_AGET_WIDE                    = 0x45,
  OP_AGET_OBJECT                  = 0x46,
  OP_AGET_BOOLEAN                 = 0x47,
  OP_AGET_BYTE                    = 0x48,
  OP_AGET_CHAR                    = 0x49,
  OP_AGET_SHORT                   = 0x4a,
  OP_APUT                         = 0x4b,
  OP_APUT_WIDE                    = 0x4c,
  OP_APUT_OBJECT                  = 0x4d,
  OP_APUT_BOOLEAN                 = 0x4e,
  OP_APUT_BYTE                    = 0x4f,
  OP_APUT_CHAR                    = 0x50,
  OP_APUT_SHORT                   = 0x51,
  OP_IGET                         = 0x52,
  OP_IGET_WIDE                    = 0x53,
  OP_IGET_OBJECT                  = 0x54,
  OP_IGET_BOOLEAN                 = 0x55,
  OP_IGET_BYTE                    = 0x56,
  OP_IGET_CHAR                    = 0x57,
  OP_IGET_SHORT                   = 0x58,
  OP_IPUT                         = 0x59,
  OP_IPUT_WIDE                    = 0x5a,
  OP_IPUT_OBJECT                  = 0x5b,
  OP_IPUT_BOOLEAN                 = 0x5c,
  OP_IPUT_BYTE                    = 0x5d,
  OP_IPUT_CHAR                    = 0x5e,
  OP_IPUT_SHORT                   = 0x5f,
  OP_SGET                         = 0x60,
  OP_SGET_WIDE                    = 0x61,
  OP_SGET_OBJECT                  = 0x62,
  OP_SGET_BOOLEAN                 = 0x63,
  OP_SGET_BYTE                    = 0x64,
  OP_SGET_CHAR                    = 0x65,
  OP_SGET_SHORT                   = 0x66,
  OP_SPUT                         = 0x67,
  OP_SPUT_WIDE                    = 0x68,
  OP_SPUT_OBJECT                  = 0x69,
  OP_SPUT_BOOLEAN                 = 0x6a,
  OP_SPUT_BYTE                    = 0x6b,
  OP_SPUT_CHAR                    = 0x6c,
  OP_SPUT_SHORT                   = 0x6d,
  OP_INVOKE_VIRTUAL               = 0x6e,
  OP_INVOKE_SUPER                 = 0x6f,
  OP_INVOKE_DIRECT                = 0x70,
  OP_INVOKE_STATIC                = 0x71,
  OP_INVOKE_INTERFACE             = 0x72,
  OP_UNUSED_73                    = 0x73,
  OP_INVOKE_VIRTUAL_RANGE         = 0x74,
  OP_INVOKE_SUPER_RANGE           = 0x75,
  OP_INVOKE_DIRECT_RANGE          = 0x76,
  OP_INVOKE_STATIC_RANGE          = 0x77,
  OP_INVOKE_INTERFACE_RANGE       = 0x78,
  OP_UNUSED_79                    = 0x79,
  OP_UNUSED_7A                    = 0x7a,
  OP_NEG_INT                      = 0x7b,
  OP_NOT_INT                      = 0x7c,
  OP_NEG_LONG                     = 0x7d,
  OP_NOT_LONG                     = 0x7e,
  OP_NEG_FLOAT                    = 0x7f,
  OP_NEG_DOUBLE                   = 0x80,
  OP_INT_TO_LONG                  = 0x81,
  OP_INT_TO_FLOAT                 = 0x82,
  OP_INT_TO_DOUBLE                = 0x83,
  OP_LONG_TO_INT                  = 0x84,
  OP_LONG_TO_FLOAT                = 0x85,
  OP_LONG_TO_DOUBLE               = 0x86,
  OP_FLOAT_TO_INT                 = 0x87,
  OP_FLOAT_TO_LONG                = 0x88,
  OP_FLOAT_TO_DOUBLE              = 0x89,
  OP_DOUBLE_TO_INT                = 0x8a,
  OP_DOUBLE_TO_LONG               = 0x8b,
  OP_DOUBLE_TO_FLOAT              = 0x8c,
  OP_INT_TO_BYTE                  = 0x8d,
  OP_INT_TO_CHAR                  = 0x8e,
  OP_INT_TO_SHORT                 = 0x8f,
  OP_ADD_INT                      = 0x90,
  OP_SUB_INT                      = 0x91,
  OP_MUL_INT                      = 0x92,
  OP_DIV_INT                      = 0x93,
  OP_REM_INT                      = 0x94,
  OP_AND_INT                      = 0x95,
  OP_OR_INT                       = 0x96,
  OP_XOR_INT                      = 0x97,
  OP_SHL_INT                      = 0x98,
  OP_SHR_INT                      = 0x99,
  OP_USHR_INT                     = 0x9a,
  OP_ADD_LONG                     = 0x9b,
  OP_SUB_LONG                     = 0x9c,
  OP_MUL_LONG                     = 0x9d,
  OP_DIV_LONG                     = 0x9e,
  OP_REM_LONG                     = 0x9f,
  OP_AND_LONG                     = 0xa0,
  OP_OR_LONG                      = 0xa1,
  OP_XOR_LONG                     = 0xa2,
  OP_SHL_LONG                     = 0xa3,
  OP_SHR_LONG                     = 0xa4,
  OP_USHR_LONG                    = 0xa5,
  OP_ADD_FLOAT                    = 0xa6,
  OP_SUB_FLOAT                    = 0xa7,
  OP_MUL_FLOAT                    = 0xa8,
  OP_DIV_FLOAT                    = 0xa9,
  OP_REM_FLOAT                    = 0xaa,
  OP_ADD_DOUBLE                   = 0xab,
  OP_SUB_DOUBLE                   = 0xac,
  OP_MUL_DOUBLE                   = 0xad,
  OP_DIV_DOUBLE                   = 0xae,
  OP_REM_DOUBLE                   = 0xaf,
  OP_ADD_INT_2ADDR                = 0xb0,
  OP_SUB_INT_2ADDR                = 0xb1,
  OP_MUL_INT_2ADDR                = 0xb2,
  OP_DIV_INT_2ADDR                = 0xb3,
  OP_REM_INT_2ADDR                = 0xb4,
  OP_AND_INT_2ADDR                = 0xb5,
  OP_OR_INT_2ADDR                 = 0xb6,
  OP_XOR_INT_2ADDR                = 0xb7,
  OP_SHL_INT_2ADDR                = 0xb8,
  OP_SHR_INT_2ADDR                = 0xb9,
  OP_USHR_INT_2ADDR               = 0xba,
  OP_ADD_LONG_2ADDR               = 0xbb,
  OP_SUB_LONG_2ADDR               = 0xbc,
  OP_MUL_LONG_2ADDR               = 0xbd,
  OP_DIV_LONG_2ADDR               = 0xbe,
  OP_REM_LONG_2ADDR               = 0xbf,
  OP_AND_LONG_2ADDR               = 0xc0,
  OP_OR_LONG_2ADDR                = 0xc1,
  OP_XOR_LONG_2ADDR               = 0xc2,
  OP_SHL_LONG_2ADDR               = 0xc3,
  OP_SHR_LONG_2ADDR               = 0xc4,
  OP_USHR_LONG_2ADDR              = 0xc5,
  OP_ADD_FLOAT_2ADDR              = 0xc6,
  OP_SUB_FLOAT_2ADDR              = 0xc7,
  OP_MUL_FLOAT_2ADDR              = 0xc8,
  OP_DIV_FLOAT_2ADDR              = 0xc9,
  OP_REM_FLOAT_2ADDR              = 0xca,
  OP_ADD_DOUBLE_2ADDR             = 0xcb,
  OP_SUB_DOUBLE_2ADDR             = 0xcc,
  OP_MUL_DOUBLE_2ADDR             = 0xcd,
  OP_DIV_DOUBLE_2ADDR             = 0xce,
  OP_REM_DOUBLE_2ADDR             = 0xcf,
  OP_ADD_INT_LIT16                = 0xd0,
  OP_RSUB_INT                     = 0xd1,
  OP_MUL_INT_LIT16                = 0xd2,
  OP_DIV_INT_LIT16                = 0xd3,
  OP_REM_INT_LIT16                = 0xd4,
  OP_AND_INT_LIT16                = 0xd5,
  OP_OR_INT_LIT16                 = 0xd6,
  OP_XOR_INT_LIT16                = 0xd7,
  OP_ADD_INT_LIT8                 = 0xd8,
  OP_RSUB_INT_LIT8                = 0xd9,
  OP_MUL_INT_LIT8                 = 0xda,
  OP_DIV_INT_LIT8                 = 0xdb,
  OP_REM_INT_LIT8                 = 0xdc,
  OP_AND_INT_LIT8                 = 0xdd,
  OP_OR_INT_LIT8                  = 0xde,
  OP_XOR_INT_LIT8                 = 0xdf,
  OP_SHL_INT_LIT8                 = 0xe0,
  OP_SHR_INT_LIT8                 = 0xe1,
  OP_USHR_INT_LIT8                = 0xe2,
  OP_IGET_VOLATILE                = 0xe3,
  OP_IPUT_VOLATILE                = 0xe4,
  OP_SGET_VOLATILE                = 0xe5,
  OP_SPUT_VOLATILE                = 0xe6,
  OP_IGET_OBJECT_VOLATILE         = 0xe7,
  OP_IGET_WIDE_VOLATILE           = 0xe8,
  OP_IPUT_WIDE_VOLATILE           = 0xe9,
  OP_SGET_WIDE_VOLATILE           = 0xea,
  OP_SPUT_WIDE_VOLATILE           = 0xeb,
  OP_BREAKPOINT                   = 0xec,
  OP_THROW_VERIFICATION_ERROR     = 0xed,
  OP_EXECUTE_INLINE               = 0xee,
  OP_EXECUTE_INLINE_RANGE         = 0xef,
  OP_INVOKE_DIRECT_EMPTY          = 0xf0,
  OP_UNUSED_F1                    = 0xf1,
  OP_IGET_QUICK                   = 0xf2,
  OP_IGET_WIDE_QUICK              = 0xf3,
  OP_IGET_OBJECT_QUICK            = 0xf4,
  OP_IPUT_QUICK                   = 0xf5,
  OP_IPUT_WIDE_QUICK              = 0xf6,
  OP_IPUT_OBJECT_QUICK            = 0xf7,
  OP_INVOKE_VIRTUAL_QUICK         = 0xf8,
  OP_INVOKE_VIRTUAL_QUICK_RANGE   = 0xf9,
  OP_INVOKE_SUPER_QUICK           = 0xfa,
  OP_INVOKE_SUPER_QUICK_RANGE     = 0xfb,
  OP_IPUT_OBJECT_VOLATILE         = 0xfc,
  OP_SGET_OBJECT_VOLATILE         = 0xfd,
  OP_SPUT_OBJECT_VOLATILE         = 0xfe,
  OP_UNUSED_FF                    = 0xff,
} DexOpCode;

/** \enum DexPsuedoOpCode
 *
 * These are psuedo opcodes to be observed when the opcode is OPCODE_PSUEDO.  In
 * general a psuedo opcode of PSUEDO_OP_NOP should be treated as a normal
 * opcode.
 */
typedef enum DexPsuedoOpCode {
  PSUEDO_OP_NOP = 0x00,
  PSUEDO_OP_PACKED_SWITCH = 0x01,
  PSUEDO_OP_SPARSE_SWITCH = 0x02,
  PSUEDO_OP_FILL_DATA_ARRAY = 0x03
} DexPsuedoOpCode;

/** \enum DexOpSpecialType
 *
 * Some opcodes carry special information embedded into the operation. When
 * adding instructions to existing bytecode be mindful of instructions carrying
 * a relative target.
 *
 * There are no dalvik opcodes that carry more than one type of special
 * information.
 */
typedef enum DexOpSpecialType {
  /// The opcode carries no special information.
  SPECIAL_NONE = 0x00,
  /// The opcode carries a signed numeric constant.  You can access/modify the
  /// constant information through ::DexInstruction .special.constant.
  SPECIAL_CONSTANT = 0x01,
  /// The opcode carries a relative offset into the bytecode.  This could point
  /// to a table or it could be a branch offset.  Also note that PACKED_SWITCH
  /// and SPARSE_SWITCH tables contain branch offsets relative to the invoking
  /// instruction as well.
  ///
  /// You can access/modify the target value through
  /// ::DexInstruction .special.target.
  SPECIAL_TARGET = 0x02,
  /// The opcode carries string information.  You can access/modify the string
  /// information through ::DexInstruction .special.str.
  SPECIAL_STRING = 0x03,
  /// The opcode carries type information.  You can access/modify the string
  /// information through ::DexInstruction .special.type.
  SPECIAL_TYPE = 0x04,
  /// The opcode carries field information.  You can access/modify the string
  /// information through ::DexInstruction .special.field.
  SPECIAL_FIELD = 0x05,
  /// The opcode carries method information.  You can access/modify the string
  /// information through ::DexInstruction .special.method.
  SPECIAL_METHOD = 0x06,
  /// The opcode carries an inline method index.  This should only be found
  /// in optimized dex files.  You can access/modify the inline index through
  /// ::DexInstruction .special.inline_ind.
  SPECIAL_INLINE = 0x07,
  /// The opcode carries an object offset.  This should only be found in
  /// optimized dex files.  You can access/modify this offset through
  /// ::DexInstruction .special.object_off.
  SPECIAL_OBJECT = 0x08,
  /// The opcode carries a virtual table index.  This should only be found in
  /// optimized dex files.  You can access/modify this offset through
  /// ::DexInstruction .special.vtable_ind.
  SPECIAL_VTABLE = 0x09
} DexOpSpecialType;

typedef enum DexInstrFlag {
  DEX_INSTR_FLAG_CONTINUE = 1 << 0,
  DEX_INSTR_FLAG_THROW = 1 << 1,
  DEX_INSTR_FLAG_INVOKE = 1 << 2,
  DEX_INSTR_FLAG_RETURN = 1 << 3,
  DEX_INSTR_FLAG_SWITCH = 1 << 4,
  DEX_INSTR_FLAG_BRANCH = 1 << 5,
  DEX_INSTR_FLAG_WRITE_REG = 1 << 6,
  DEX_INSTR_FLAG_WIDE_R1 = 1 << 7,
  DEX_INSTR_FLAG_WIDE_R2 = 1 << 8,
  DEX_INSTR_FLAG_WIDE_R3 = 1 << 9,
} DexInstrFlag;

typedef struct {
  /// The string name of this opcode.
  const char* name;
  /// The format id of this opcode.  See
  /// http://www.netmite.com/android/mydroid/dalvik/docs/dalvik-bytecode.html
  /// for more information.
  const char* format_id;
  /// The number of code units (dx_ushorts) in this instruction.
  int size;
  /// The type of special information carried by this instruction.
  DexOpSpecialType specialType;
  /// The position in nibbles from the first short.  Currently the dalvik byte
  /// code has all special arguments starting in the second short.
  int specialPos;
  /// Number of nibbles in the value.  Currently the dalvik byte code has this
  /// at 4 or 8 nibbles (1 or 2 shorts).
  int specialSize;
  /// The sum of some of the DexInstrFlag values.
  int flags;
} DexOpFormat;

/*! \var const DexOpFormat dex_opcode_formats[256]
 *  \brief Gives the opcode formats for each opcode.
 *
 * If you plan on modifying bytecode you probably will make use of this array.
 * It includes formatting information for each byte code.  Index into this array
 * with the opcode value of the instruction in question.
 */
extern
const DexOpFormat dex_opcode_formats[256];

typedef struct {
  /// The opcode for this instruction.
  dx_ubyte opcode;
  /// The high byte in the leading byte of the instruction.
  dx_ubyte hi_byte;
  /// Represents bytes 1 and 2 for the instruction.  Note that if the bytes
  /// represent a special value they will automatically be ignored in this array
  /// and instead the value in the special union will be used.
  dx_ushort param[2];
  /// See ::DexOpSpecialType for details on what fields are used.
  union {
  dx_long constant;
  dx_int target;
  ref_str* str;
  ref_str* type;
  ref_field field;
  ref_method method;
  dx_uint inline_ind;
  dx_uint object_off;
  dx_uint vtable_ind;
  /// Present when the opcode is OP_PSUEDO and the psuedo opcode is
  /// PSUEDO_OP_PACKED_SWITCH.
  struct {
    /// The number of targets in this switch.
    dx_ushort size;
    /// The first and smallest key.
    dx_int first_key;
    /// The branch targets relative to the invoking instruction.
    dx_int* targets;
  } packed_switch;
  /// Present when the opcode is OP_PSUEDO and the psuedo opcode is
  /// PSUEDO_OP_SPARSE_SWITCH.
  struct {
    /// The number of targets in this switch.
    dx_ushort size;
    /// The keys in this switch.  These should be sorted in ascending order.
    dx_int* keys;
    /// The branch targets relative to the invoking instruction.
    dx_int* targets;
  } sparse_switch;
  /// Present when the opcode is OP_PSUEDO and the psuedo opcode is
  /// PSUEDO_OP_FILL_DATA_ARRAY.
  struct {
    /// The width of the elements in the data array.
    dx_ushort element_width;
    /// The number of elements in this table.
    dx_uint size;
    /// A buffer of element_width * size bytes representing the data to be
    /// filled in.
    dx_ubyte* data;
  } fill_data_array;
  } special;
} DexInstruction;

/*! \fn dx_uint dxc_insn_width(DexInstruction* insn)
 *  \brief Returns the encoded width in code units of the instruction.
 */
dx_uint dxc_insn_width(const DexInstruction* insn);

/*! \fn dx_uint dxc_num_registers(DexInstruction* insn)
 *  \brief Returns the number of registers for this instruction.
 */
dx_ubyte dxc_num_registers(const DexInstruction* insn);

/*! \fn dx_uint dxc_set_num_registers(DexInstruction* insn);
 *  \brief Sets the number of registers used by this instruction.  Returns the
 *  number the previous number or registers used on success.  If the new number
 *  of registers is not valid returns -1.
 */
dx_int dxc_set_num_registers(DexInstruction* insn, dx_ubyte regs);

/*! \fn dx_int dxc_register_width(DexInstruction* insn, dx_uint index)
 *  \brief Returns the width in nibbles (4 bits) of the encoded register.
 *  Returns -1 if the register index is not valid.
 */
dx_int dxc_register_width(const DexInstruction* insn, dx_uint index);

/*! \fn dx_ushort dxc_get_register(DexInstruction* insn, dx_uint index)
 *  \brief Returns the index'th register used by this instruction.
 *  Returns -1 if the index is not valid.
 */
dx_int dxc_get_register(const DexInstruction* insn, dx_uint index);

/*! \fn dx_ushort dxc_set_register(DexInstruction* insn, dx_uint index,
 *                                 dx_ushort reg)
 *  \brief Sets the index'th register used by this instruction.
 *  Returns the value of the previous register at this index.  Returns -1 on
 *  error.  Will result in an error if called with non-zero index on a range
 *  instruction.
 */
dx_int dxc_set_register(DexInstruction* insn, dx_uint index, dx_ushort reg);

/*! \fn void dxc_free_instruction(DexInstruction* insn)
 *  \brief Frees all data associated with this instruction. Does not attempt to
 *  free the passed pointer.
 */
extern
void dxc_free_instruction(DexInstruction* insn);


#ifdef __cplusplus
}
#endif
#endif // __DXCUT_DALVIK_H
