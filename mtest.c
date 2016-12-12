#include <stdio.h>
extern int InFoo(), InBoo(), InBar();

void main() {
	InFoo();
	InBoo();
	InBar();

	printf("test mtest\n");
}