/* ----------------------------------------------------------------------- *
 *   
 *   Copyright 1996-2009 The NASM Authors - All Rights Reserved
 *   See the file AUTHORS included with the NASM distribution for
 *   the specific copyright holders.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following
 *   conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *     
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *     CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *     INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *     CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *     SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *     NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *     OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *     EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ----------------------------------------------------------------------- */

/*
 * Internal definitions common to outelf32 and outelf64
 */
#ifndef OUTPUT_OUTELF_H
#define OUTPUT_OUTELF_H

#define SYM_GLOBAL 0x10

#define GLOBAL_TEMP_BASE  0x40000000 /* bigger than any sane symbol index */

#define SEG_ALIGN 16            /* alignment of sections in file */
#define SEG_ALIGN_1 (SEG_ALIGN-1)

/* this stuff is needed for the stabs debugging format */
#define N_SO 0x64               /* ID for main source file */
#define N_SOL 0x84              /* ID for sub-source file */
#define N_BINCL 0x82
#define N_EINCL 0xA2
#define N_SLINE 0x44
#define TY_STABSSYMLIN 0x40     /* ouch */

/* this stuff is needed for the dwarf debugging format */
#define TY_DEBUGSYMLIN 0x40     /* internal call to debug_out */

/* Known sections with nonstandard defaults */
struct elf_known_section {
    const char *name;		/* Name of section */
    int type;			/* Section type (SHT_) */
    uint32_t flags;		/* Section flags (SHF_) */
    uint32_t align;		/* Section alignment */
};
extern const struct elf_known_section elf_known_sections[];

/*
 * Special ELF sections (after the real sections but before debugging ones)
 */
#define sec_shstrtab		(nsects + 1)
#define sec_symtab		(nsects + 2)
#define sec_strtab		(nsects + 3)
#define sec_numspecial  	3

/*
 * Debugging ELF sections (last in the file)
 */

/* stabs */
#define sec_stab		(nsections-3)
#define sec_stabstr		(nsections-2)
#define sec_rel_stab		(nsections-1)

/* dwarf */
#define sec_debug_aranges	(nsections-10)
#define sec_rela_debug_aranges	(nsections-9)
#define sec_debug_pubnames	(nsections-8)
#define sec_debug_info		(nsections-7)
#define sec_rela_debug_info	(nsections-6)
#define sec_debug_abbrev	(nsections-5)
#define sec_debug_line		(nsections-4)
#define sec_rela_debug_line	(nsections-3)
#define sec_debug_frame		(nsections-2)
#define sec_debug_loc		(nsections-1)

#endif /* OUTPUT_OUTELF_H */
