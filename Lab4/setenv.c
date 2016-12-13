#include <stdlib.h>
#include <stdio.h>

int main() {
	setenv("TEST_ENV", "1234", 1);
	printf("TEST_ENV = %s\n", getenv("TEST_ENV"));

	exit(0);
}
