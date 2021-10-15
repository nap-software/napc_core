#if !defined(NAP_HAL0_h)
	#define NAP_HAL0_h

	#define _NAP_HAL0_PRINTFLIKE(_1, _2) __attribute__((format(printf, _1, _2)))

	const char *nap_hal0__version(void);
	const char *nap_hal0__platform(void);

	void nap_hal0__init(void);
	void nap_hal0__abort(void);
	void nap_hal0__puts(const char *string);
	void nap_hal0__printf(const char *fmt, ...) _NAP_HAL0_PRINTFLIKE(1, 2);
	void nap_hal0__delay(unsigned amount);
	unsigned long nap_hal0__time(void);
#endif
