# napc_core@0.0.1

This library provides core functionality for C applications written by nap.software.

It internally relies on `nap_hal0` to make it so that programs can be run on different platforms (at the moment this is `linux` and `arduino`).

## API

### `const char *nap_version(void)`

Returns the version of the module.

---


### `void nap_init(void)`

Initializes the core module.

Call this function *once* and before calling any other core functions.

---

### `void nap_panic(const char *fmt, ...)`

Terminates the program. Supports `printf()` like string format.

---

### `NAP_ERROR(fmt, ...)`

Prints an error message to the console.

---

### `NAP_DEBUG(fmt, ...)`

Prints a debug message to the console.

This is a NOP when debugging is not enabled.

---

### `void nap_set_debug(bool debug)`

Turns debugging on or off.

---

### `NAP_TRACE(fmt, ...)`

Prints a trace message to the console.

This is a NOP when tracing is not enabled.

---

### `void nap_set_trace(bool trace)`

Turns tracing on or off.

---


### `void *nap_safe_malloc(size_t size)`

Wrapper around `malloc()` that calls `nap_panic()` when memory could not be allocated.

---

### `NAP_SAFE_ALLOC(t, n)`

Convenience macro that calculates the number of bytes needed for type `t` with `n` elements.

Calls and casts the result of `nap_safe_malloc()`.

---

### `char *nap_safe_strdup(const char *string)`

Wrapper around `strdup()` that calls `nap_panic()` when memory could not be allocated.

---

### `void nap_safe_strncpy(char *destination, const char *source, size_t num)`

Safer version of `strncpy()`. This version always terminates `destination`.
