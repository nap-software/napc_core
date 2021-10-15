#if defined(__cplusplus)
	#error This source file must not be compiled by a C++ compiler.
#endif

#include "internal.h"

static bool _traceEnabled = false;

void nap_set_trace(bool trace) {
	_traceEnabled = trace;
}

void _nap_trace(
	const char *file, int line, const char *fn,
	const char *fmt, ...
) {
	if (!_traceEnabled) return;

	va_list args;
	unsigned long time = nap_hal0__time();

	va_start(args, fmt);
	nap_internal__print(
		fmt, args,
		"(trace +%010lu) [%30s] ", time, fn
	);
	va_end(args);

	nap_hal0__puts("\n");
}

