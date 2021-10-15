#if defined(__cplusplus)
	#error This source file must not be compiled by a C++ compiler.
#endif

#include "internal.h"

void nap_printf(const char *fmt, ...) {
	va_list args;

	va_start(args, fmt);
	nap_internal__print(
		fmt, args,
		"%s", ""
	);
	va_end(args);
}

void nap_println(const char *fmt, ...) {
	va_list args;

	va_start(args, fmt);
	nap_internal__print(
		fmt, args,
		"%s", ""
	);
	va_end(args);
	nap_hal0__puts("\n");
}
