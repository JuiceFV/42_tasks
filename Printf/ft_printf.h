#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
*internal flag definitions
*/
//'0'
#define FLAGS_ZEROPAD   (1U <<  0U)
//'-''
#define FLAGS_LEFT      (1U <<  1U)
//'+''
#define FLAGS_PLUS      (1U <<  2U)
//' '
#define FLAGS_SPACE     (1U <<  3U)
//'#'
#define FLAGS_HASH      (1U <<  4U)
#define FLAGS_UPPERCASE (1U <<  5U)
#define FLAGS_CHAR      (1U <<  6U)
#define FLAGS_SHORT     (1U <<  7U)
//'l'
#define FLAGS_LONG      (1U <<  8U)
#define FLAGS_LONG_LONG (1U <<  9U)
//'.'
#define FLAGS_PRECISION (1U << 10U)
#define FLAGS_ADAPT_EXP (1U << 11U)

//output function type
typedef void (*out_func_type)(char character,
								void* buffer, size_t idx, size_t maxlen);

// wrapper (used as buffer) for output function type
typedef struct {
  void  (*fct)(char character, void* arg);
  void* arg;
} out_func_wrap_type;

// internal buffer output
static inline void _out_buffer(char character,
								void* buffer, size_t index, size_t maxlen);
/*
** colors for bonus
*/
# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[36m"

#ifdef __cplusplus
}
#endif

# endif