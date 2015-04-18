//
//  generator.c
//  
//
//  Created by Ryan Alex on 11/22/14.
//
//

#include "generator.h"
#include "dataGen.h"

int count;
int an;
int main (int argc, char *argv[]) {
    
    printf("This tool generates websites!\n.\n.\n.\n");
    printf("Enter number of sites to generate: ");
    scanf("%d", &count);
    printf("Run in dev mode? 0=NO, 1=YES: ");
    scanf("%d", &an);
    if (an) {
        DEV=1;
    }
    printf("Processing...\n");
    generateData(count);
    
  	return 0;
}
