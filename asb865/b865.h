struct adsym
{
    char a_str[3]; /* addressing string */
    int a_val;     /* addressing mode value */
};

#define S_A 1
#define S_X 2
#define S_Y 3
#define S_SP 4
#define S_R0 5
#define S_R1 6
#define S_R2 7
#define S_R3 8

/*
 * Addressing types
 */
#define S_ABS 35
#define S_ABSX 36
#define S_ABSY 37
#define S_ZP 38
#define S_ZPX 39
#define S_ZPY 40
#define S_IMMED 41
#define S_DINDX 42
#define S_DINDY 43
#define S_INDX 44
#define S_INDY 45
#define S_IND 46
#define S_REG 47

#define S_2ROP 50
#define S_1ROP 51
#define S_BRA 52
#define S_INH 53
#define S_JMP 54
#define S_MOV 55
#define S_B865 56
#define S_ADD 57

/* b865adr.c */
extern struct adsym regs[];
extern int addr(struct expr *esp);
extern int admode(struct adsym *sp);
extern int srch(char *str);

/* b865mch.c */
extern struct area *zpg;
extern VOID machine(struct mne *mp);
extern VOID mcherr(int c, char *str);
extern VOID mchwrn(char *str);
extern VOID minit(void);
