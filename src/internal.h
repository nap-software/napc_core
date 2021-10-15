#include "nap_core.h"
#include "../include/nap_hal0.h"
#include <stdarg.h> // va_list, va_start(), va_end()
#include <stdio.h> // vsnprintf()
#include <string.h> // memset()

void nap_internal__print(
	const char *fmt1, va_list args1,
	const char *fmt2, ...
) _NAP_PRINTFLIKE(3, 4);
