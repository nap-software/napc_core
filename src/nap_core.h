#if !defined(NAP_CORE_h)
	#define NAP_CORE_h

	#include <stdbool.h> // bool
	#include <stddef.h> // size_t
	#include <stdlib.h> // free(), NULL (in C++)

	#define _NAP_PRINTFLIKE(_1, _2) __attribute__((format(printf, _1, _2)))

	const char *nap_version(void);
	void nap_init(void);

	void nap_panic(const char *fmt, ...) _NAP_PRINTFLIKE(1, 2);

	// Debugging
	void _nap_error(
		const char *file, int line, const char *fn,
		const char *fmt, ...
	) _NAP_PRINTFLIKE(4, 5);

	#define NAP_ERROR(fmt, ...) \
		_nap_error(__FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)

	void nap_set_debug(bool debug);

	void _nap_debug(
		const char *file, int line, const char *fn,
		const char *fmt, ...
	) _NAP_PRINTFLIKE(4,5 );

	#define NAP_DEBUG(fmt, ...) \
		_nap_debug(__FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)

	void nap_set_trace(bool trace);

	void _nap_trace(
		const char *file, int line, const char *fn,
		const char *fmt, ...
	) _NAP_PRINTFLIKE(4,5 );

	#define NAP_TRACE(fmt, ...) \
		_nap_trace(__FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
	//

	void nap_printf(const char *fmt, ...) _NAP_PRINTFLIKE(1, 2);
	void nap_println(const char *fmt, ...) _NAP_PRINTFLIKE(1, 2);

	void *nap_safe_malloc(size_t size);
	#define NAP_SAFE_ALLOC(t, n) (t *)nap_safe_malloc(sizeof(t) * (n))

	char *nap_safe_strdup(const char *string);
	void nap_safe_strncpy(char *destination, const char *source, size_t num);
#endif
