/* ANSI C namespace clean utility typedefs */

/* This file defines various typedefs needed by the system calls that support
   the C library.  Basically, they're just the POSIX versions with an '_'
   prepended.  This file lives in the `sys' directory so targets can provide
   their own if desired (or they can put target dependant conditionals here).
*/

#ifndef	_SYS__TYPES_H
#define _SYS__TYPES_H

#include <machine/_types.h>
#include <sys/lock.h>

typedef long _off_t;
__extension__ typedef long long _off64_t;

/*
 * We need fpos_t for the following, but it doesn't have a leading "_",
 * so we use _fpos_t instead.
 */
#ifndef __FPOS_T_DEFINED
typedef long _fpos_t;		/* XXX must match off_t in <sys/types.h> */
				/* (and must be `long' for now) */
#endif

#ifdef __LARGE64_FILES
#ifndef __FPOS64_T_DEFINED
typedef _off64_t _fpos64_t;
#endif
#endif

#if defined(__INT_MAX__) && __INT_MAX__ == 2147483647
typedef int _ssize_t;
#else
typedef long _ssize_t;
#endif

#define __need_wint_t
#include <stddef.h>

/* Conversion state information.  */
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;		/* Value so far.  */
} _mbstate_t;

typedef _LOCK_RECURSIVE_T _flock_t;

/* Iconv descriptor type */
typedef void *_iconv_t;

#endif	/* _SYS__TYPES_H */
