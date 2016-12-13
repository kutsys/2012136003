#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	char block[1024];
	int nread;
	FILE *in, *out;

	if(argc != 3) {
		printf("Error! Please write right name.\n");
		exit(1);
	}

	if((in = fopen(argv[1], "r")) == NULL) {
		printf("Not Found!\n");
		exit(1);
	}
	
	out = fopen(argv[2], "w");

	while(fgets(block, 1024, in) != NULL) {
		fputs(block, out);
		printf("*");
	}

	fclose(in);
	fclose(out);
	printf("\n~Finished~\n");
	return 0;
}
