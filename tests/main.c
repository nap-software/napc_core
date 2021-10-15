#include "../src/nap_core.h"

int main() {
	nap_init();

	nap_set_debug(true);
	nap_set_trace(true);

	nap_println("This is a line %d", 10);
	nap_printf("This is a line %d", 0);
	nap_printf("\n");

	nap_safe_strdup("aas");

	NAP_DEBUG("debug");
	NAP_TRACE("trace %d", 10);
	NAP_ERROR("bla");
	nap_panic("abcdef %d", 10);
}
