#include "internal.h"

void nap_internal__print(
	const char *fmt1, va_list args1,
	const char *fmt2, ...
) {
	char buffer[1024];
	va_list args2;
	memset(buffer, 0, sizeof(buffer));

	va_start(args2, fmt2);
	vsnprintf(buffer, sizeof(buffer), fmt2, args2);
	va_end(args2);

	nap_hal0__puts(buffer);

	memset(buffer, 0, sizeof(buffer));
	vsnprintf(buffer, sizeof(buffer), fmt1, args1);

	nap_hal0__puts(buffer);
}

const char *nap_version(void) {
	return "0.0.1";
}

void nap_init(void) {
	nap_hal0__init();
	nap_hal0__printf(
		"Core initialized. Version: %s\n",
		nap_version()
	);
}

void nap_delay(unsigned int amount) {
	nap_hal0__delay(amount);
}

unsigned long nap_uptime(void) {
	return nap_hal0__time();
}

void *nap_safe_malloc(size_t size) {
	void *mem = malloc(size);

	if (!mem) {
		nap_panic(
			"Tried to allocate %lu bytes but failed: system is out of memory.",
			(unsigned long)size
		);
	}

	return mem;
}

char *nap_safe_strdup(const char *string) {
	char *copy = strdup(string);

	if (!copy) {
		nap_panic(
			"Tried to duplicate string of length %lu but failed: system is out of memory.",
			(unsigned long)strlen(string)
		);
	}

	return copy;
}

void nap_safe_strncpy(char *destination, const char *source, size_t num) {
	strncpy(destination, source, num);
	destination[num - 1] = 0;
}
