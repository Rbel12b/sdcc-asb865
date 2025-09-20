#include "asxxxx.h"
#include "b865.h"

/*
 * Mnemonic Structure
 */
struct mne mne[] = {

    /* assembler */

    {NULL, "CON", S_ATYP, 0, A_CON},
    {NULL, "OVR", S_ATYP, 0, A_OVR},
    {NULL, "REL", S_ATYP, 0, A_REL},
    {NULL, "ABS", S_ATYP, 0, A_ABS},
    {NULL, "NOPAG", S_ATYP, 0, A_NOPAG},
    {NULL, "PAG", S_ATYP, 0, A_PAG},

    {NULL, "CODE", S_ATYP, 0, A_CODE},
    {NULL, "DATA", S_ATYP, 0, A_DATA},
    {NULL, "LOAD", S_ATYP, 0, A_LOAD},
    {NULL, "NOLOAD", S_ATYP, 0, A_NOLOAD},

    {NULL, ".page", S_PAGE, 0, 0},
    {NULL, ".title", S_HEADER, 0, O_TITLE},
    {NULL, ".sbttl", S_HEADER, 0, O_SBTTL},
    {NULL, ".module", S_MODUL, 0, 0},
    {NULL, ".include", S_INCL, 0, I_CODE},
    {NULL, ".incbin", S_INCL, 0, I_BNRY},
    {NULL, ".area", S_AREA, 0, 0},
    //    {	NULL,	".psharea",	S_AREA,		0,	O_PSH	},
    //    {	NULL,	".poparea",	S_AREA,		0,	O_POP	},
    //    {	NULL,	".bank",	S_BANK,		0,	0	},
    {NULL, ".org", S_ORG, 0, 0},
    {NULL, ".radix", S_RADIX, 0, 0},
    {NULL, ".globl", S_GLOBL, 0, 0},
    {NULL, ".local", S_LOCAL, 0, 0},
    {NULL, ".if", S_CONDITIONAL, 0, O_IF},
    {NULL, ".iff", S_CONDITIONAL, 0, O_IFF},
    {NULL, ".ift", S_CONDITIONAL, 0, O_IFT},
    {NULL, ".iftf", S_CONDITIONAL, 0, O_IFTF},
    {NULL, ".ifdef", S_CONDITIONAL, 0, O_IFDEF},
    {NULL, ".ifndef", S_CONDITIONAL, 0, O_IFNDEF},
    {NULL, ".ifgt", S_CONDITIONAL, 0, O_IFGT},
    {NULL, ".iflt", S_CONDITIONAL, 0, O_IFLT},
    {NULL, ".ifge", S_CONDITIONAL, 0, O_IFGE},
    {NULL, ".ifle", S_CONDITIONAL, 0, O_IFLE},
    {NULL, ".ifeq", S_CONDITIONAL, 0, O_IFEQ},
    {NULL, ".ifne", S_CONDITIONAL, 0, O_IFNE},
    {NULL, ".ifb", S_CONDITIONAL, 0, O_IFB},
    {NULL, ".ifnb", S_CONDITIONAL, 0, O_IFNB},
    {NULL, ".ifidn", S_CONDITIONAL, 0, O_IFIDN},
    {NULL, ".ifdif", S_CONDITIONAL, 0, O_IFDIF},
    {NULL, ".iif", S_CONDITIONAL, 0, O_IIF},
    {NULL, ".iiff", S_CONDITIONAL, 0, O_IIFF},
    {NULL, ".iift", S_CONDITIONAL, 0, O_IIFT},
    {NULL, ".iiftf", S_CONDITIONAL, 0, O_IIFTF},
    {NULL, ".iifdef", S_CONDITIONAL, 0, O_IIFDEF},
    {NULL, ".iifndef", S_CONDITIONAL, 0, O_IIFNDEF},
    {NULL, ".iifgt", S_CONDITIONAL, 0, O_IIFGT},
    {NULL, ".iiflt", S_CONDITIONAL, 0, O_IIFLT},
    {NULL, ".iifge", S_CONDITIONAL, 0, O_IIFGE},
    {NULL, ".iifle", S_CONDITIONAL, 0, O_IIFLE},
    {NULL, ".iifeq", S_CONDITIONAL, 0, O_IIFEQ},
    {NULL, ".iifne", S_CONDITIONAL, 0, O_IIFNE},
    {NULL, ".iifb", S_CONDITIONAL, 0, O_IIFB},
    {NULL, ".iifnb", S_CONDITIONAL, 0, O_IIFNB},
    {NULL, ".iifidn", S_CONDITIONAL, 0, O_IIFIDN},
    {NULL, ".iifdif", S_CONDITIONAL, 0, O_IIFDIF},
    {NULL, ".else", S_CONDITIONAL, 0, O_ELSE},
    {NULL, ".endif", S_CONDITIONAL, 0, O_ENDIF},
    {NULL, ".list", S_LISTING, 0, O_LIST},
    {NULL, ".nlist", S_LISTING, 0, O_NLIST},
    {NULL, ".uleb128", S_ULEB128, 0, 0},
    {NULL, ".sleb128", S_SLEB128, 0, 0},
    {NULL, ".equ", S_EQU, 0, O_EQU},
    {NULL, ".gblequ", S_EQU, 0, O_GBLEQU},
    {NULL, ".lclequ", S_EQU, 0, O_LCLEQU},
    {NULL, ".byte", S_DATA, 0, O_1BYTE},
    {NULL, ".db", S_DATA, 0, O_1BYTE},
    {NULL, ".fcb", S_DATA, 0, O_1BYTE},
    {NULL, ".word", S_DATA, 0, O_2BYTE},
    {NULL, ".dw", S_DATA, 0, O_2BYTE},
    {NULL, ".fdb", S_DATA, 0, O_2BYTE},
    /*    { NULL,   ".3byte",       S_DATA,         0,      O_3BYTE },      */
    /*    { NULL,   ".triple",      S_DATA,         0,      O_3BYTE },      */
    /*    {	NULL,	".dl",		S_DATA,		0,	O_4BYTE	},	*/
    /*    { NULL,   ".4byte",       S_DATA,         0,      O_4BYTE },      */
    /*    { NULL,   ".quad",        S_DATA,         0,      O_4BYTE },      */
    /*    {	NULL,	".long",	S_DATA,		0,	O_4BYTE	},	*/
    {NULL, ".blkb", S_BLK, 0, O_1BYTE},
    {NULL, ".ds", S_BLK, 0, O_1BYTE},
    {NULL, ".rmb", S_BLK, 0, O_1BYTE},
    {NULL, ".rs", S_BLK, 0, O_1BYTE},
    {NULL, ".blkw", S_BLK, 0, O_2BYTE},
    /*    { NULL,   ".blk3",        S_BLK,          0,      O_3BYTE },      */
    /*    { NULL,   ".blk4",        S_BLK,          0,      O_4BYTE },      */
    /*    {	NULL,	".blkl",	S_BLK,		0,	O_4BYTE	},	*/
    {NULL, ".ascii", S_ASCIX, 0, O_ASCII},
    {NULL, ".ascis", S_ASCIX, 0, O_ASCIS},
    {NULL, ".asciz", S_ASCIX, 0, O_ASCIZ},
    {NULL, ".str", S_ASCIX, 0, O_ASCII},
    {NULL, ".strs", S_ASCIX, 0, O_ASCIS},
    {NULL, ".strz", S_ASCIX, 0, O_ASCIZ},
    {NULL, ".fcc", S_ASCIX, 0, O_ASCII},
    {NULL, ".define", S_DEFINE, 0, O_DEF},
    {NULL, ".undefine", S_DEFINE, 0, O_UNDEF},
    {NULL, ".even", S_BOUNDARY, 0, O_EVEN},
    {NULL, ".odd", S_BOUNDARY, 0, O_ODD},
    {NULL, ".bndry", S_BOUNDARY, 0, O_BNDRY},
    {NULL, ".msg", S_MSG, 0, 0},
    {NULL, ".assume", S_ERROR, 0, O_ASSUME},
    {NULL, ".error", S_ERROR, 0, O_ERROR},
    /*    {	NULL,	".msb",		S_MSB,		0,	0	},	*/
    /*    {	NULL,	".lohi",	S_MSB,		0,	O_LOHI	},	*/
    /*    {	NULL,	".hilo",	S_MSB,		0,	O_HILO	},	*/
    /*    {	NULL,	".8bit",	S_BITS,		0,	O_1BYTE	},	*/
    /*    {	NULL,	".16bit",	S_BITS,		0,	O_2BYTE	},	*/
    /*    {	NULL,	".24bit",	S_BITS,		0,	O_3BYTE	},	*/
    /*    {	NULL,	".32bit",	S_BITS,		0,	O_4BYTE	},	*/
    //    {	NULL,	".trace",	S_TRACE,	0,	O_TRC	},
    //    {	NULL,	".ntrace",	S_TRACE,	0,	O_NTRC	},
    /*    {	NULL,	"_______",	S_CONST,	0,	VALUE	},	*/
    //    {	NULL,	".end",		S_END,		0,	0	},

    /* Macro Processor */

    {NULL, ".macro", S_MACRO, 0, O_MACRO},
    {NULL, ".endm", S_MACRO, 0, O_ENDM},
    {NULL, ".mexit", S_MACRO, 0, O_MEXIT},

    {NULL, ".narg", S_MACRO, 0, O_NARG},
    {NULL, ".nchr", S_MACRO, 0, O_NCHR},
    {NULL, ".ntyp", S_MACRO, 0, O_NTYP},

    {NULL, ".irp", S_MACRO, 0, O_IRP},
    {NULL, ".irpc", S_MACRO, 0, O_IRPC},
    {NULL, ".rept", S_MACRO, 0, O_REPT},

    {NULL, ".nval", S_MACRO, 0, O_NVAL},

    {NULL, ".mdelete", S_MACRO, 0, O_MDEL},

    {NULL, ".b865", S_B865, 0, 0},


/* sdas specific */
    {   NULL,   ".optsdcc",     S_OPTSDCC,      0,      0       },
/* end sdas specific */

    /* b865 Instructions */

    {NULL, "adc", S_ADD, 0, 0x18},
    {NULL, "add", S_2ROP, 0, 0x10},
    {NULL, "and", S_2ROP, 0, 0x17},
    {NULL, "cmp", S_2ROP, 0, 0x1D},
    {NULL, "nand", S_2ROP, 0, 0x16},
    {NULL, "nor", S_2ROP, 0, 0x15},
    {NULL, "or", S_2ROP, 0, 0x14},
    {NULL, "sbc", S_ADD, 0, 0x1A},
    {NULL, "sub", S_2ROP, 0, 0x12},
    {NULL, "xnor", S_2ROP, 0, 0x11},
    {NULL, "xor", S_2ROP, 0, 0x13},

    {NULL, "bcc", S_BRA, 0, 0x05},
    {NULL, "bcs", S_BRA, 1, 0x05},
    {NULL, "beq", S_BRA, 2, 0x05},
    {NULL, "bmi", S_BRA, 4, 0x05},
    {NULL, "bne", S_BRA, 0, 0x05},
    {NULL, "bpl", S_BRA, 0, 0x05},

    {NULL, "clc", S_INH, 0, 0x23},
    {NULL, "stc", S_INH, 0, 0x26},
    {NULL, "hlt", S_INH, 0, 0x2B},
    {NULL, "nop", S_INH, 0, 0x0B},
    {NULL, "dex", S_INH, 0, 0x09},
    {NULL, "inx", S_INH, 0, 0x0A},
    {NULL, "rts", S_INH, 0, 0x3C},

    {NULL, "jmp", S_JMP, 0, 0x20},
    {NULL, "jsr", S_JMP, 0, 0x1C},

    {NULL, "mov", S_MOV, 0, 0x01},

    {NULL, "dec", S_1ROP, 0, 0x1E},
    {NULL, "inc", S_1ROP, 0, 0x1F},
    {NULL, "phr", S_1ROP, 0, 0x19},
    {NULL, "plr", S_1ROP, 0, 0x1B},
    {NULL, "rol", S_1ROP, 0, 0x0F},
    {NULL, "ror", S_1ROP, 0, 0x0E},
    {NULL, "rsh", S_1ROP, 0, 0x0C},
    {NULL, "lsh", S_1ROP, S_EOL, 0x0D},
};
