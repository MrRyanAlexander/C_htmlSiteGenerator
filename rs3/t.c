#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct man {
	char name[20];
}MAN;
char guy(char *name[20]) {
	strcpy(name, "Ryan");
	strcat(name, " Alex!");
}
int main(void) {
	MAN dudes[2];
	guy(&dudes[0].name);
	strcpy(dudes[1].name, "Mr Brown!");
	printf("The first dudes name is %s\n", dudes[0].name);
	printf("The second dudes name is %s\n", dudes[1].name);
	return 0;
}


