#ifndef TALLOC_CONFIG_H_
#define TALLOC_CONFIG_H_

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
#  if defined __MINGW32__ || defined __MINGW64__
#    define __USE_MINGW_ANSI_STDIO 1
#    ifdef fprintf
#      undef fprintf
#    endif
#    ifdef vsnprintf
#      undef vsnprintf
#    endif
#    define fprintf   __mingw_fprintf
#    define vsnprintf __mingw_vsnprintf
#  elif defined _MSC_VER
#    define HAVE_PRAGMA_INIT
#  endif
#  include <Windows.h>
#  include <io.h>
#endif

#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define LOOOOO

#if (!defined(HAVE_SYS_AUXV_H) || !defined(AT_RANDOM)) && !defined(HAVE_ARC4RANDOM) && defined(HAVE_BSD_STDLIB_H)
#  include "bsd/stdlib.h"
#  define HAVE_ARC4RANDOM
#endif

#define HAVE_CONSTRUCTOR_ATTRIBUTE
#define HAVE_INTPTR_T
#define HAVE_STRING_H
#define STDC_HEADERS 1
#define HAVE_STRERROR
#define HAVE_ERRNO_DECL
#define HAVE_STRDUP
#define HAVE_MEMMOVE
#define HAVE_STRNLEN
#define HAVE_STRNDUP
#define HAVE_SETENV
#define HAVE_STRTOLL
#define HAVE_STDBOOL_H
#define HAVE_BOOL
#define HAVE_UINTPTR_T
#define HAVE_PTRDIFF_T
#define HAVE_USLEEP
#define HAVE_DECL_EWOULDBLOCK
#define HAVE_VA_COPY

#define TALLOC_BUILD_VERSION_MAJOR 2
#define TALLOC_BUILD_VERSION_MINOR 3
#define TALLOC_BUILD_VERSION_RELEASE 2

//#define _PUBLIC_ __attribute__((visibility("default")))
//#define _PRIVATE_ __attribute__((visibility("hidden")))


#define MAX(IA, IB)    __extension__({__auto_type ia=(IA); __auto_type ib=(IB); (ia>ib)?ia:ib;})
#define MIN(IA, IB)    __extension__({__auto_type ia=(IA); __auto_type ib=(IB); (ia<ib)?ia:ib;})

#ifndef MIN
#  define MIN(a,b) ((a)<(b)?(a):(b))
#endif

#ifndef MAX
#  define MAX(a,b) ((a)>(b)?(a):(b))
#endif

#endif /* talloc_config.h */
