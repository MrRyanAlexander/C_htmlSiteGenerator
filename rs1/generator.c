//
//  generator.c
//  
//
//  Created by Ryan Alex on 11/22/14.
//
//

#include "generator.h"
#include "dataGen.h"
#include "websiteGen.h"

int count;
char input[10];
char y[10];
char Y[10];

int main (void) {
	
    strcpy(y, "y");
    strcpy(Y, "Y");
    
    printf("This tool generates websites!\n.\n.\n.\n");
    printf("Enter total number to generate: ");
    scanf("%d", &count);
    
    printf("Preparing to generate %d sets of data...\n", count);
    
    dataCount = count;
    generateData();
    
    if (didCreateData) {
        printf("Finished generating data!\n.\n.\n.\n");
        printf("Continue generating sites? (Y/N): ");
        scanf("%s", input);
        
        if (strcmp(Y,input) == 0 || strcmp(y,input) == 0) {
            generateSites();
            printf("\nSuccess. %d new sites created!\n", count);

        }else{
            printf("Quit without generating.\n");
        }
    }
  	return 0;
}
