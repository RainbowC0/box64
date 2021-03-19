#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <pthread.h>
#include <errno.h>

#include "debug.h"
#include "box64context.h"
#include "dynarec.h"
#include "emu/x64emu_private.h"
#include "emu/x64run_private.h"
#include "x64run.h"
#include "x64emu.h"
#include "box64stack.h"
#include "callback.h"
#include "emu/x64run_private.h"
#include "x64trace.h"
#include "dynarec_arm64.h"
#include "dynarec_arm64_private.h"
#include "arm64_printer.h"
#include "my_cpuid.h"
#include "emu/x87emu_private.h"

#include "dynarec_arm64_functions.h"
#include "dynarec_arm64_helper.h"

#define GETGX(a)    \
    gd = ((nextop&0x38)>>3)+(rex.r<<3);  \
    a = sse_get_reg(dyn, ninst, x1, gd)
#define GETEX(a)    \
    if(MODREG) { \
        a = sse_get_reg(dyn, ninst, x1, nextop&7+(rex.b<<3)); \
    } else {    \
        addr = geted(dyn, addr, ninst, nextop, &ed, x1, &fixedaddress, 0, 0); \
        a = fpu_get_scratch_quad(dyn); \
        VLD1Q_64(a, ed);    \
    }
#define GETGM(a)    \
    gd = (nextop&0x38)>>3;  \
    a = mmx_get_reg(dyn, ninst, x1, gd)
#define GETEM(a)    \
    if(MODREG) { \
        a = mmx_get_reg(dyn, ninst, x1, nextop&7); \
    } else {    \
        addr = geted(dyn, addr, ninst, nextop, &ed, x1, &fixedaddress, 0, 0); \
        a = fpu_get_scratch_double(dyn); \
        VLD1_64(a, ed);    \
    }
#define PUTEM(a)    \
    if(!MODREG) { \
        VST1_64(a, ed);    \
    }

uintptr_t dynarec64_0F(dynarec_arm_t* dyn, uintptr_t addr, uintptr_t ip, int ninst, rex_t rex, int* ok, int* need_epilog)
{
    uint8_t opcode = F8;
    uint8_t nextop, u8;
    int32_t i32, i32_, j32;
    uint8_t gd, ed;
    uint8_t wback, wb1, wb2;
    uint8_t eb1, eb2;
    uint8_t gb1, gb2;
    int v0, v1, v2;
    int q0, q1;
    int d0, d1;
    int s0;
    int fixedaddress;
    int parity;
    MAYUSE(s0);
    MAYUSE(q1);
    MAYUSE(v2);
    MAYUSE(gb2);
    MAYUSE(gb1);
    MAYUSE(eb2);
    MAYUSE(eb1);
    MAYUSE(wb2);
    MAYUSE(j32);
    #if STEP == 3
    //static const int8_t mask_shift8[] = { -7, -6, -5, -4, -3, -2, -1, 0 };
    #endif

    switch(opcode) {



        case 0x1F:
            INST_NAME("NOP (multibyte)");
            nextop = F8;
            FAKEED;
            break;

        #define GO(GETFLAGS, NO, YES, F)            \
            READFLAGS(F);                           \
            GETFLAGS;                               \
            nextop=F8;                              \
            GETGD;                                  \
            if((nextop&0xC0)==0xC0) {               \
                ed = xRAX+(nextop&7)+(rex.b<<3);    \
                CSELxw(gd, ed, gd, YES);            \
            } else { \
                addr = geted(dyn, addr, ninst, nextop, &ed, x2, &fixedaddress, 0xfff<<(2+rex.w), (1<<(2+rex.w))-1, rex, 0, 0); \
                Bcond(NO, +8);                      \
                LDRxw_U12(gd, ed, fixedaddress);    \
                if(!rex.w) {MOVw_REG(gd, gd);}      \
            }

        case 0x40:
            INST_NAME("CMOVO Gd, Ed");
            GO( TSTw_mask(xFlags, 0b010101, 0)
                , cEQ, cNE, X_OF)
            break;
        case 0x41:
            INST_NAME("CMOVNO Gd, Ed");
            GO( TSTw_mask(xFlags, 0b010101, 0)
                , cNE, cEQ, X_OF)
            break;
        case 0x42:
            INST_NAME("CMOVC Gd, Ed");
            GO( TSTw_mask(xFlags, 0, 0)
                , cEQ, cNE, X_CF)
            break;
        case 0x43:
            INST_NAME("CMOVNC Gd, Ed");
            GO( TSTw_mask(xFlags, 0, 0)
                , cNE, cEQ, X_CF)
            break;
        case 0x44:
            INST_NAME("CMOVZ Gd, Ed");
            GO( TSTw_mask(xFlags, 0b011010, 0)
                , cEQ, cNE, X_ZF)
            break;
        case 0x45:
            INST_NAME("CMOVNZ Gd, Ed");
            GO( TSTw_mask(xFlags, 0b011010, 0)
                , cNE, cEQ, X_ZF)
            break;
        case 0x46:
            INST_NAME("CMOVBE Gd, Ed");
            GO( MOV32w(x1, (1<<F_CF)|(1<<F_ZF));
                TSTw_REG(xFlags, x1)
                , cEQ, cNE, X_CF|X_ZF)
            break;
        case 0x47:
            INST_NAME("CMOVNBE Gd, Ed");
            GO( MOV32w(x1, (1<<F_CF)|(1<<F_ZF));
                TSTw_REG(xFlags, x1)
                , cNE, cEQ, X_CF|X_ZF)
            break;
        case 0x48:
            INST_NAME("CMOVS Gd, Ed");
            GO( TSTw_mask(xFlags, 0b011001, 0)  // 0X80
                , cEQ, cNE, X_SF)
            break;
        case 0x49:
            INST_NAME("CMOVNS Gd, Ed");
            GO( TSTw_mask(xFlags, 0b011001, 0)
                , cNE, cEQ, X_SF)
            break;
        case 0x4A:
            INST_NAME("CMOVP Gd, Ed");
            GO( TSTw_mask(xFlags, 0b011110, 0)
                , cEQ, cNE, X_PF)
            break;
        case 0x4B:
            INST_NAME("CMOVNP Gd, Ed");
            GO( TSTw_mask(xFlags, 0b011110, 0)
                , cNE, cEQ, X_PF)
            break;
        case 0x4C:
            INST_NAME("CMOVL Gd, Ed");
            GO( EORw_REG_LSL(x1, xFlags, xFlags, F_OF-F_SF);
                TSTw_mask(x1, 0b010101, 0)
                , cEQ, cNE, X_SF|X_OF)
            break;
        case 0x4D:
            INST_NAME("CMOVGE Gd, Ed");
            GO( EORw_REG_LSL(x1, xFlags, xFlags, F_OF-F_SF);
                TSTw_mask(x1, 0b010101, 0)
                , cNE, cEQ, X_SF|X_OF)
            break;
        case 0x4E:
            INST_NAME("CMOVLE Gd, Ed");
            GO( EORw_REG_LSL(x1, xFlags, xFlags, F_OF-F_SF);
                ORRw_REG_LSL(x1, x1, xFlags, F_OF-F_ZF);
                TSTw_mask(x1, 0b010101, 0)
                , cEQ, cNE, X_SF|X_OF|X_ZF)
            break;
        case 0x4F:
            INST_NAME("CMOVG Gd, Ed");
            GO( EORw_REG_LSL(x1, xFlags, xFlags, F_OF-F_SF);
                ORRw_REG_LSL(x1, x1, xFlags, F_OF-F_ZF);
                TSTw_mask(x1, 0b010101, 0)
                , cNE, cEQ, X_SF|X_OF|X_ZF)
            break;
        #undef GO
        
        case 0xBB:
            INST_NAME("BTC Ed, Gd");
            SETFLAGS(X_CF, SF_SET);
            nextop = F8;
            GETGD;
            if(MODREG) {
                ed = xRAX+(nextop&7)+(rex.b<<3);
                wback = 0;
            } else {
                addr = geted(dyn, addr, ninst, nextop, &wback, x3, &fixedaddress, 0xfff<<(2+rex.w), (1<<(2+rex.w))-1, rex, 0, 0);
                UBFXw(x1, gd, 5+rex.w, 3-rex.w); // r1 = (gd>>5);
                ADDx_REG_LSL(x3, wback, x1, 2); //(&ed)+=r1*4;
                LDRxw_U12(x1, x3, fixedaddress);
                ed = x1;
                wback = x3;
            }
            if(rex.w) {
                ANDx_mask(x2, gd, 1, 0, 0b00101);  //mask=0x000000000000003f
            } else {
                ANDw_mask(x2, gd, 0, 0b00100);  //mask=0x00000001f
            }
            LSRxw_REG(x4, ed, x2);
            BFIw(xFlags, x4, F_CF, 1);
            MOV32w(x4, 1);
            LSLxw_REG(x4, x4, x2);
            EORxw_REG(ed, ed, x4);
            if(wback) {
                STRxw_U12(ed, wback, fixedaddress);
            }
            break;

        default:
            DEFAULT;
    }
    return addr;
}
