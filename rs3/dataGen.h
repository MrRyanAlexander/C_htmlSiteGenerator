//
//  dataGen.h
//  
//
//  Created by Ryan Alex on 11/30/14.
//
//

#ifndef ____dataGen__
#define ____dataGen__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <memory.h>
#include <string.h>

#define LEN 5
#define WORD 20
#define LWORD 200
#define CNTRY 3
#define PV 2
#define PN 3
#define KLEN 13

typedef struct site {
    char urls[10][LWORD];
    char url[LWORD];
    char title[LWORD];
    char description[LWORD];
    char keywords[LWORD];
    char keyword[WORD];
    char country[CNTRY];
    //char story[500];
}SITE;


void generateData(int dataCount);
int didGenSite;

int DEV;
#endif /* defined(____dataGen__) */
