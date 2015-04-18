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
int main (int argc, char *argv[]) {
    
    printf("This tool generates websites!\n.\n.\n.\n");
    printf("Enter number of sites to generate: ");
    scanf("%d", &count);
    
    printf("Processing...\n");
    generateData(count);
    
  	return 0;
}
