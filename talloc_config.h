#ifndef TALLOC_CONFIG_H_
#define TALLOC_CONFIG_H_

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
#  define _CRT_NONSTDC_NO_DEPRECATE 1
#  define _CRT_NONSTDC_NO_WARNINGS  1
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
#  include <windows.h>
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

#ifdef HAVE_SYS_AUXV_H
# include <sys/auxv.h>
# ifndef HAVE_GETAUXVAL
#  define HAVE_GETAUXVAL 1
# endif
#endif

//#if (!defined(HAVE_SYS_AUXV_H) || !defined(AT_RANDOM)) && !defined(HAVE_ARC4RANDOM) && defined(HAVE_BSD_STDLIB_H)
//#  include "bsd/stdlib.h"
//#  define HAVE_ARC4RANDOM
//#endif

#if defined HAVE_LIBBSD
extern uint32_t arc4random(void);
#endif

#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#include <time.h>

#if defined __MINGW32__ || defined __MINGW64__ || defined __GNU_LIBRARY__ || defined __FreeBSD__
# define HAVE_BOOL
# define HAVE_CONSTRUCTOR_ATTRIBUTE
# define HAVE_DECL_EWOULDBLOCK
# define HAVE_ERRNO_DECL
# define HAVE_INTPTR_T
# define HAVE_MEMMOVE
# define HAVE_PTRDIFF_T
# define HAVE_SETENV
# define HAVE_STDBOOL_H
# define HAVE_STRDUP
# define HAVE_STRERROR
# define HAVE_STRING_H
# define HAVE_STRNDUP
# define HAVE_STRNLEN
# define HAVE_STRTOLL
# define HAVE_UINTPTR_T
# define HAVE_USLEEP
# define HAVE_VA_COPY
# define STDC_HEADERS 1
#elif defined _MSC_VER
# ifdef __clang__
#  define HAVE_STDATOMIC_H
# endif
# define HAVE_BOOL
# define HAVE_DECL_EWOULDBLOCK
# define HAVE_ERRNO_DECL
# define HAVE_INTPTR_T
# define HAVE_MEMMOVE
# define HAVE_PTRDIFF_T
# define HAVE_SETENV
# define HAVE_STDBOOL_H
# define HAVE_STRDUP
# define HAVE_STRERROR
# define HAVE_STRING_H
# define HAVE_STRNDUP
# define HAVE_STRNLEN
# define HAVE_STRTOLL
# define HAVE_UINTPTR_T
# define HAVE_VA_COPY
# define STDC_HEADERS 1
#endif

#define TALLOC_BUILD_VERSION_MAJOR 2
#define TALLOC_BUILD_VERSION_MINOR 4
#define TALLOC_BUILD_VERSION_RELEASE 1

//#define _PUBLIC_ __attribute__((visibility("default")))
//#define _PRIVATE_ __attribute__((visibility("hidden")))

#ifndef MIN
#  ifdef __GNUC__
#    define MIN(IA, IB) __extension__({__auto_type ia=(IA); __auto_type ib=(IB); (ia<ib)?ia:ib;})
#  else
#    define MIN(a,b) ((a)<(b)?(a):(b))
#  endif
#endif

#ifndef MAX
#  ifdef __GNUC__
#    define MAX(IA, IB) __extension__({__auto_type ia=(IA); __auto_type ib=(IB); (ia>ib)?ia:ib;})
#  else
#    define MAX(a,b) ((a)>(b)?(a):(b))
#  endif
#endif

#ifdef USE_JEMALLOC
#  define JEMALLOC_MANGLE
#  include <jemalloc/jemalloc.h>
#endif

#if __has_include("valgrind/memcheck.h")
#  define HAVE_VALGRIND_MEMCHECK_H 1
#endif

#endif /* talloc_config.h */
