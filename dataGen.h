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
#define WORD 100
#define LWORD 200
#define CNTRY 3
#define PV 2
#define PN 3
#define KLEN 13

typedef struct site {
    
    char keyword[WORD];
    char ethnicity[WORD];
    char sexPref[WORD];
    char gender[WORD];
    char bodyType[WORD];
    char title[LWORD];
    char keywords[LWORD];
    char description[LWORD];
    char url[LWORD];
    char urlTitle[LWORD];
    char urls[10][100];
    char urlsTitles[6][100];
}SITE;


void generateData();
int didGenSite;

int DEV;
#endif /* defined(____dataGen__) */
