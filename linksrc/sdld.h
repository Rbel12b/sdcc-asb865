/* sdld.h

   Copyright (C) 2009 Borut Razem

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3, or (at your option) any
later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef __SDLD_H
#define __SDLD_H

enum sdld_target_e {
  TARGET_ID_UNKNOWN,
  TARGET_ID_GB,
  TARGET_ID_Z80,
  TARGET_ID_Z180,
  TARGET_ID_8051,
  TARGET_ID_6808,
  TARGET_ID_STM8,
  TARGET_ID_PDK,
  TARGET_ID_PDK13,
  TARGET_ID_PDK14,
  TARGET_ID_PDK15,
};

void sdld_init (char *path);
int is_sdld(void);
void set_sdld_target(enum sdld_target_e trgt);
enum sdld_target_e get_sdld_target(void);
int is_sdld_target_z80_like(void);
int is_sdld_target_8051_like(void);

#define TARGET_IS_GB	(get_sdld_target() == TARGET_ID_GB)
#define TARGET_IS_Z80   (get_sdld_target() == TARGET_ID_Z80)
#define TARGET_IS_Z180  (get_sdld_target() == TARGET_ID_Z180)
#define TARGET_IS_8051  (get_sdld_target() == TARGET_ID_8051)
#define TARGET_IS_6808  (get_sdld_target() == TARGET_ID_6808)
#define TARGET_IS_STM8  (get_sdld_target() == TARGET_ID_STM8)
#define TARGET_IS_PDK                      \
  (get_sdld_target() == TARGET_ID_PDK ||   \
   get_sdld_target() == TARGET_ID_PDK13 || \
   get_sdld_target() == TARGET_ID_PDK14 || \
   get_sdld_target() == TARGET_ID_PDK15)

//char *strndup(char *str, unsigned long long chars);

#endif  /* __SDLD_H */
