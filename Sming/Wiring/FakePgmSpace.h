#ifndef __FAKE_PGMSPACE_H_
#define __FAKE_PGMSPACE_H_

#include "WiringFrameworkDependencies.h"

#define PGM_P  const char *
#define PSTR(str) (str)

typedef void prog_void;
typedef char prog_char;
typedef unsigned char prog_uchar;
typedef int8_t prog_int8_t;
typedef uint8_t prog_uint8_t;
typedef int16_t prog_int16_t;
typedef uint16_t prog_uint16_t;
typedef int32_t prog_int32_t;
typedef uint32_t prog_uint32_t;

#ifdef ICACHE_FLASH

#define PROGMEM STORE_ATTR ICACHE_RODATA_ATTR

#define memcpy_P(dest, src, num) ets_memcpy((dest), (src), (num))
#define strcpy_P(dest, src) ets_strcpy((dest), (src))
#define strlen_P(a) ets_strlen((a))

uint8_t pgm_read_byte(const void* pgm_addr);
uint16_t pgm_read_word(const void* pgm_addr);
uint32_t pgm_read_dword(const void* pgm_addr);
float pgm_read_float(const void* pgm_addr);

#else

#define PROGMEM

#define memcpy_P(dest, src, num) memcpy((dest), (src), (num))
#define strcpy_P(dest, src) strcpy((dest), (src))
#define strcat_P(dest, src) strcat((dest), (src))
#define strcmp_P(a, b) strcmp((a), (b))
#define strstr_P(a, b) strstr((a), (b))
#define strlen_P(a) strlen((a))
#define sprintf_P(s, f, ...) sprintf((s), (f), __VA_ARGS__)

#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#define pgm_read_word(addr) (*(const unsigned short *)(addr))
#define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#define pgm_read_float(addr) (*(const float *)(addr))

#endif

#define pgm_read_byte_near(addr) pgm_read_byte(addr)
#define pgm_read_word_near(addr) pgm_read_word(addr)
#define pgm_read_dword_near(addr) pgm_read_dword(addr)
#define pgm_read_float_near(addr) pgm_read_float(addr)
#define pgm_read_byte_far(addr) pgm_read_byte(addr)
#define pgm_read_word_far(addr) pgm_read_word(addr)
#define pgm_read_dword_far(addr) pgm_read_dword(addr)
#define pgm_read_float_far(addr) pgm_read_float(addr)

#endif
