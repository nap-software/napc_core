#if defined(__cplusplus)
	#error This source file must not be compiled by a C++ compiler.
#endif

#include "internal.h"

static bool _debugEnabled = false;

void nap_set_debug(bool debug) {
	_debugEnabled = debug;
}

void _nap_debug(
	const char *file, int line, const char *fn,
	const char *fmt, ...
) {
	if (!_debugEnabled) return;

	va_list args;
	unsigned long time = nap_hal0__time();

	va_start(args, fmt);
	nap_internal__print(
		fmt, args,
		"(debug +%010lu) [%30s] ", time, fn
	);
	va_end(args);

	nap_hal0__puts("\n");
}

