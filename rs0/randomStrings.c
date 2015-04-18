//
//  randomStrings.c
//  
//
//  Created by Ryan Alex on 11/22/14.
//
//

#include "randomStrings.h"

int currentKeyCount; //track the number of keys in current array

//FILE *site = fopen("site.txt", "r");
#define LENGTH(x) (sizeof(x)/sizeof(*(x)))

FILE *keys1 = fopen("keys1.txt", "r"); // 
FILE *keys2 = fopen("keys2.txt", "r"); //
FILE *keys3 = fopen("keys3.txt", "r"); //  lists of keyword keys
FILE *keys4 = fopen("keys4.txt", "r"); //
FILE *keys5 = fopen("keys5.txt", "r"); //

char keys1[100];
char keys2[100];
char keys3[100];
char keys4[100];
char keys5[100];



void show(int *data, size_t count);

int arr[] = { 1,2,3,4,5 };

show(arr, sizeof arr / sizeof *arr);

char *foo(void)
{
    static char str[10];
    strcpy(str, "Hello");
    return str;
}
 char *randomTitle(void) {
 	
 	while (fgets (buf, sizeof(buf), syt)) { 

 	}
 	static char title[20];
 	strcpy(title, )
 }
int randNum(void) {

	srand(time(NULL));
    int randomnumber;
    randomnumber = rand() % currentKeyCount +1;
    return randomnumber;
}