#include "asxxxx.h"
#include "b865.h"

int addr(struct expr *esp)
{
    int c;
    char *p, *endpos = 0;
    int iflag;
    char ldlm, rdlm;

    if((c = admode(regs)))
    {
        esp->e_addr = c - 1;
        esp->e_mode = S_REG;
        return S_REG;
    }

    /* fix order of '<', '>', and '#' */
    p = ip;
    if (((c = getnb()) == '<') || (c == '>'))
    {
        p = ip - 1;
        if (getnb() == '#')
        {
            *p = *(ip - 1);
            *(ip - 1) = c;
        }
    }
    ip = p;

    /*
     * Before ','
     *	Scan for '[' delimiter character
     *	and set the delimiter pair.
     * After ','
     *	Scan for 'rdlm' and set indexed mode.
     */
    ldlm = '('; /* Default Delimiters */
    rdlm = ')';
    iflag = 0; /* Default Non Indexed */
    p = ip;
    while (more())
    {
        if ((c = getnb()) == '[')
        {
            ldlm = '['; /* Bracket Delimiters */
            rdlm = ']';
        }
        while (more())
        {
            if (getnb() == rdlm)
            {
                if ((c = getnb()) == ',')
                {
                    iflag = 1;
                }
                else if(c == rdlm)
                {
                    continue;
                }
                break;
            }
        }
    }
    ip = p;

    int dlmcount = 0;
    c = get();

    while (c != '\0' && c != ';')
    {
        if((c = get()) == '(' || c == '[')
        {
            dlmcount++;
        }
        else if(c == ')' || c == ']')
        {
            if(dlmcount > 0)
            {
                dlmcount--;
            }
        }
        else if((dlmcount == 0) && c == ' ')
        {
            if (*ip != ' ')
            {
                ip--;
            }
            endpos = ip;
            *endpos = '\0';
            break;
        }
    }

    ip = p;

    if ((c = getnb()) == '#')
    {
        expr(esp, 0);
        esp->e_mode = S_IMMED;
    }
    else if ((c == ldlm) && iflag)
    {
        expr(esp, 0);
        esp->e_mode = S_IND;
        if((c = get()) != rdlm)
        {
            unget(c);
        }
        if (more())
        {
            if(comma(0))
            {
                switch (admode(regs))
                {
                case S_X:
                    esp->e_mode = S_INDX;
                    break;
                case S_Y:
                    esp->e_mode = S_INDY;
                    break;
                default:
                    aerr();
                    break;
                }
            }
        }
    }
    else if ((c == ldlm) && (c != '*'))
    {
        expr(esp, 0);
        esp->e_mode = S_IND;
        if((c = get()) != rdlm)
        {
            unget(c);
        }
        if (more())
        {
            if(comma(0))
            {
                switch (admode(regs))
                {
                case S_X:
                    esp->e_mode = S_DINDX;
                    break;
                case S_Y:
                    esp->e_mode = S_DINDY;
                    break;
                default:
                    aerr();
                    break;
                }
            }
        }
    }
    else
    {
        if(c != '*')
        {
            unget(c);
        }
        if((c = get()) != ldlm)
        {
            unget(c);
        }
        expr(esp, 0);
        esp->e_mode = S_ABS;
        if (more())
        {
            if(comma(0))
            {
                switch (admode(regs))
                {
                case S_X:
                    esp->e_mode = S_ABSX;
                    break;
                case S_Y:
                    esp->e_mode = S_ABSY;
                    break;
                default:
                    aerr();
                    break;
                }
            }
        }
    }
    if((c = getnb()) != rdlm)
    {
        unget(c);
    }
    if(endpos)
    {
        *endpos = ' ';
    }
    return (esp->e_mode);
}

/*
 * When building a table that has variations of a common
 * symbol always start with the most complex symbol first.
 * for example if x, x+, and x++ are in the same table
 * the order should be x++, x+, and then x.  The search
 * order is then most to least complex.
 */

/*
 * When searching symbol tables that contain characters
 * not of type LTR16, eg with '-' or '+', always search
 * the more complex symbol tables first. For example:
 * searching for x+ will match the first part of x++,
 * a false match if the table with x+ is searched
 * before the table with x++.
 */

/*
 * Enter admode() to search a specific addressing mode table
 * for a match. Return the addressing value on a match or
 * zero for no match.
 */
int admode(struct adsym *sp)
{
    char *ptr;
    int i;
    char *ips;

    ips = ip;
    unget(getnb());

    i = 0;
    while (*(ptr = &sp[i].a_str[0]))
    {
        if (srch(ptr))
        {
            return (sp[i].a_val);
        }
        i++;
    }
    ip = ips;
    return (0);
}

/*
 *      srch --- does string match ?
 */
int srch(char *str)
{
    char *ptr;
    ptr = ip;

    while (*ptr && *str)
    {
        if (ccase[*ptr & 0x007F] != ccase[*str & 0x007F])
            break;
        ptr++;
        str++;
    }
    if (ccase[*ptr & 0x007F] == ccase[*str & 0x007F])
    {
        ip = ptr;
        return (1);
    }

    if (!*str)
        if (!(ctype[*ptr & 0x007F] & LTR16))
        {
            ip = ptr;
            return (1);
        }
    return (0);
}

struct adsym regs[] = {/* registers */
    {"a", S_A},
    {"x", S_X},
    {"y", S_Y},
    {"sp", S_SP},
    {"r0", S_R0},
    {"r1", S_R1},
    {"r2", S_R2},
    {"r3", S_R3},
    {"", 0x00},
};
