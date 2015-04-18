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


typedef struct site {
    char urls[10][20];
    char url[20];
    char title[20];
    char description[50];
    char keywords[50];
    char keyword[20];
    char country[2];
    //char story[500];
}SITE;

void generateData(int dataCount);
int didGenSite;

#endif /* defined(____dataGen__) */
