//
//  dataGen.c
//  
//
//  Created by Ryan Alex on 11/30/14.
//
//

#include "dataGen.h"

#define LENGTH(x) (sizeof(x)/sizeof(*(x)))

void genMeta();

char *keys1[] = {"Free", "Chat", "NoSignup"};
char *keys2[] = {"Webcams", "Cams"};
char *keys3[] = {"teens", "babes", "sluts", "freaks", "hotties", "sexy", "naughty", "amateur", "horny", "fuckable", "bbw"};
char *keys4[] = {"live", "online", "new", "happening", "broadcasting", "available", "ready", "now"};
char *keys5[] = {"anal", "creampie", "masturbate", "swallow", "biting", "sucking", "tease", "play"};
char *cntry[]  = {"US", "RU", "IN"};
char title[100], description[100], keywords[200], url[100], country[10], keyword[40];

void generateData() {
    srand(time(NULL));

    FILE *data = fopen("data.txt", "w");
    int i;
    
    for (i=0; i<dataCount; i++) {
        
        genMeta(); //generate new data
        /*
            creates a file where each set of 6 lines is a dataset
                            -------------
                                url
                            -------------
                               title
                            -------------
                             *descriptionription
                            -------------
                              keywords
                            -------------
                               country
                            -------------
                                story
                            -------------
                               keyword
                            -------------
        */
        fprintf(data, "%s\n%s\n%s\n%s\n%s\n%s\n", url, title, description, keywords, country, keyword);
                
    }
    if (i >= dataCount) {
        fclose(data);
        printf("Created data. %d# of sites ready to be generated\n", dataCount);
        i=0;
        didCreateData=1; //assumes the data was created
    }
}
void genMeta() {
    
    strcpy(title, keys1[rand() % LENGTH(keys1)]);
    strcat(title, " ");
    strcat(title, keys2[rand() % LENGTH(keys2)]);
    strcat(title, " - ");
    strcat(title, keys3[rand() % LENGTH(keys3)]);
    strcat(title, " ");
    strcat(title, keys4[rand() % LENGTH(keys4)]);
    strcat(title, " ");
    strcat(title, keys5[rand() % LENGTH(keys5)]);
    //printf("The finished title :%s\n", title);
    
    strcpy(keywords, keys1[rand() % LENGTH(keys1)]);
    strcat(keywords, " ");
    strcat(keywords, keys2[rand() % LENGTH(keys2)]);
    strcat(keywords, " ");
    strcat(keywords, keys3[rand() % LENGTH(keys3)]);
    strcat(keywords, " ");
    strcat(keywords, keys4[rand() % LENGTH(keys4)]);
    strcat(keywords, " ");
    strcat(keywords, keys5[rand() % LENGTH(keys5)]);
    strcat(keywords, " ");
    strcat(keywords, keys2[rand() % LENGTH(keys4)]);
    strcat(keywords, " ");
    strcat(keywords, keys3[rand() % LENGTH(keys3)]);
    strcat(keywords, " ");
    strcat(keywords, keys4[rand() % LENGTH(keys1)]);
    strcat(keywords, " ");
    strcat(keywords, keys5[rand() % LENGTH(keys5)]);
    strcat(keywords, " ");
    strcat(keywords, keys2[rand() % LENGTH(keys2)]);
    strcat(keywords, " ");
    strcat(keywords, keys3[rand() % LENGTH(keys5)]);
    strcat(keywords, " ");
    strcat(keywords, keys4[rand() % LENGTH(keys3)]);
    strcat(keywords, " ");
    strcat(keywords, keys5[rand() % LENGTH(keys1)]);
    strcat(keywords, " ");
    strcat(keywords, keys2[rand() % LENGTH(keys2)]);
    strcat(keywords, " ");
    strcat(keywords, keys3[rand() % LENGTH(keys4)]);
    strcat(keywords, " ");
    strcat(keywords, keys4[rand() % LENGTH(keys5)]);
    strcat(keywords, " ");
    strcat(keywords, keys5[rand() % LENGTH(keys2)]);
    //printf("The finished keywords :%s\n", keywords);
    
    strcpy(description, keys1[rand() % LENGTH(keys1)]);
    strcat(description, " ");
    strcat(description, keys2[rand() % LENGTH(keys2)]);
    strcat(description, " ");
    strcat(description, keys3[rand() % LENGTH(keys3)]);
    strcat(description, " ");
    strcat(description, keys4[rand() % LENGTH(keys4)]);
    strcat(description, " ");
    strcat(description, keys5[rand() % LENGTH(keys5)]);
    strcat(description, " ");
    strcat(description, keys2[rand() % LENGTH(keys3)]);
    strcat(description, " ");
    strcat(description, keys3[rand() % LENGTH(keys1)]);
    strcat(description, " ");
    strcat(description, keys4[rand() % LENGTH(keys4)]);
    strcat(description, " ");
    strcat(description, keys5[rand() % LENGTH(keys3)]);
    //printf("The finished description :%s\n", *description);
    
    strcpy(url, keys1[rand() % LENGTH(keys1)]);
    strcat(url, "-");
    strcat(url, keys2[rand() % LENGTH(keys2)]);
    strcat(url, "-");
    strcat(url, keys3[rand() % LENGTH(keys3)]);
    strcat(url, "-");
    strcat(url, keys4[rand() % LENGTH(keys4)]);
    strcat(url, "-");
    strcat(url, keys5[rand() % LENGTH(keys5)]);
    //printf("The finished url :%s\n", url);
    
    strcpy(country, cntry[rand() % LENGTH(cntry)]);
    //printf("The finished country :%s\n", country);
    strcpy(keyword, keys5[rand() % LENGTH(keys5)]);
}