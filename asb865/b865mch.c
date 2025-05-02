#include "asxxxx.h"
#include "b865.h"

char *cpu = "Breadboard 865";
char *dsft = "asm";

struct area *zpg;


VOID outAddr(struct expr* exp, int mode)
{
	if(mode >= S_ABS && mode <= S_ABSY)
	{
		outrw(exp, 0);
	}
	else
	{
		outab(exp->e_addr);
	}
}

/*
 * Process a machine op.
 */
VOID machine(struct mne *mp)
{
	int op;
	struct expr e1, e2;
	int v1, v2;

	clrexpr(&e1);
	clrexpr(&e2);
	op = (int)mp->m_valu;
	switch (mp->m_type)
	{
	case S_MOV:
		v1 = addr(&e1);
		v2 = addr(&e2);
		if(v1 == S_IMMED)
		{
			aerr();
			break;
		}
		if(v1 == v2)
		{
			if(v1 == S_REG)
			{
				outab(1 | (e2.e_addr << 5));
				outab(e1.e_addr); // reverse order e2: source, e1: destination
			}
			else
			{
				outab(3);
				outab((v2 - S_ABS) | ((v1 - S_ABS) << 4));
				outAddr(&e1, v1);
				outAddr(&e2, v2);
			}
		}
		else if(v1 == S_REG)
		{
			outab(2 | (e1.e_addr << 5));
			outab(v2 - S_ABS);
			outAddr(&e2, v2);
		}
		else
		{
			outab(4 | (e2.e_addr << 5));
			outab(v1 - S_ABS);
			outAddr(&e1, v1);
		}
		break;

	case S_ADD:
		if(addr(&e1) != S_REG)
		{
			aerr();
		}
		v2 = addr(&e2);
		if(v2 == S_REG)
		{
			outab(op | (e1.e_addr << 5));
			outab(e2.e_addr);
		}
		else
		{
			outab((op == 0x18 ? 8 : 9) | (e1.e_addr << 5));
			outab(v2 - S_ABS);
			outAddr(&e2, v2);
		}
		break;

	case S_2ROP:
		if(addr(&e1) != S_REG)
		{
			aerr();
		}
		outab(op | (e1.e_addr << 5));
		if(addr(&e2) != S_REG)
		{
			aerr();
		}
		outab(e2.e_addr);
		break;

	case S_1ROP:
		if(addr(&e1) != S_REG)
		{
			aerr();
		}
		outab(op | (e1.e_addr << 5));
		break;

	case S_JMP:
		expr(&e1, 0);
		outab(op);
		outrw(&e1, 0);
		break;

	case S_BRA:
		expr(&e1, 0);
		outab(op | mp->m_flag);
		outrw(&e1, 0);
		break;

	case S_INH:
		outab(op);
		break;

	case S_B865:
		break;

	default:
		break;
	}
}

/*
 * Machine dependent initialization
 */
VOID minit()
{
	/*
	 * Byte Order
	 */
	hilo = 0;

	/*
	 * Address Space
	 */
	exprmasks(2);

	/*
	 * Zero Page Area Pointer
	 */
	zpg = NULL;
}
