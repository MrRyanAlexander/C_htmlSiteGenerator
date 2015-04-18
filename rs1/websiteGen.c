//
//  websiteGen.c
//  
//
//  Created by Ryan Alex on 11/30/14.
//
//

#include "websiteGen.h"
#include "chat_four_mod_temp.h"
#include "four_mod_temp.h"
#include "six_mod_temp.h"

void generateTemplate();

//struct stat st = {0};
char title[100], description[100], keywords[200], url[100], country[10], keyword[40];
char buf[1046];

void generateSites() {
    srand(time(NULL));

    FILE *data = fopen("data.txt", "r");
    int i=1;
    int j;
    int *urls;
    while (fgets (buf, sizeof(buf), data)) {
        
        if (i==1) {
            strcpy(url, buf);
            //urls = (int*) calloc (a,sizeof(int));
            i++;
        }else if(i==2) {
            strcpy(title, buf);
            i++;
        }else if(i==3) {
            strcpy(description, buf);
            i++;
        }else if(i==4) {
            strcpy(keywords, buf);
            i++;
        }else if(i==5) {
            strcpy(country, buf);
            i++;
            //remove i++ throws error trap6 <<<<<
            //always make sure functions complete
        }else {
            strcpy(keyword, buf);
            
            j=rand() % 3;
            
            if (j==0) {
                genChatFourTemp(title, description, keywords, url, country, keyword);
            }else if(j==1) {
                genFourTemp(title, description, keywords, url, country, keyword);
            }else{
                genSixTemp(title, description, keywords, url, country, keyword);
            }
            i=1;
        //}else if(i==6) {
            //strcpy(story, buf);
        //}else {
            
        }
    }
    fclose(data);
}

