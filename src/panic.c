#if defined(__cplusplus)
	#error This source file must not be compiled by a C++ compiler.
#endif

#include "internal.h"

void nap_panic(const char *fmt, ...) {
	va_list args;
	unsigned long time = nap_hal0__time();

	va_start(args, fmt);
	nap_internal__print(
		fmt, args,
		"\n\n(panic +%010lu) ", time
	);
	va_end(args);

	nap_hal0__printf(
		"\n\n"
		"(panic +%010lu) The application has experienced a fatal error.\n"
		"(panic +%010lu) There's likely log output above.\n"
		"(panic +%010lu) Application will be terminated.\n",
		time, time, time
	);

	nap_hal0__abort();
}
