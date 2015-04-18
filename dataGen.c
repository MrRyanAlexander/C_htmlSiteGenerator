//
//  dataGen.c
//
//
//  Created by Ryan Alex on 11/30/14.
//
//

#include "dataGen.h"
#include "chat_four_mod_temp.h"
#include "four_mod_temp.h"
#include "six_mod_temp.h"

char buf[100];

void generateSite(SITE site) {
    int j = rand()%3;
    if (j==0) {
        genChatFourTemp(site);
        DEV ? printf("Generated chat_four_mod_template\n"):0;
    }else if(j==1) {
        genFourTemp(site);
        DEV ? printf("Generated four_mod_template\n"):0;
    }else{
        genSixTemp(site);
        DEV ? printf("Generated six_mod_template\n"):0;
    }
}
#pragma mark Generate Random Sites
void generateData() {
    int i=1; int k=0;
    SITE site;
    
    FILE *sdata = fopen("sdata.txt", "r");
    while (fgets (buf, sizeof(buf), sdata)!= NULL) {
        DEV ? printf("%s\n",buf):0;
        switch (i) {
            case 1:
                strcpy(site.keyword, buf);
                i++;
                break;
            case 2:
                strcpy(site.ethnicity, buf);
                i++;
                break;
            case 3:
                strcpy(site.sexPref, buf);
                i++;
                break;
            case 4:
                strcpy(site.gender, buf);
                i++;
                break;
            case 5:
                strcpy(site.bodyType, buf);
                i++;
                break;
            case 6:
                strcpy(site.title, buf);
                i++;
                break;
            case 7:
                strcpy(site.keywords, buf);
                i++;
                break;
            case 8:
                strcpy(site.description, buf);
                i++;
                break;
            case 9:
                strcpy(site.url, buf);
                i++;
                break;
            case 10:
                strcpy(site.urlTitle, buf);
                i++;
                break;
            case 11:
                strcpy(site.urls[0], buf);
                i++;
                break;
            case 12:
                strcpy(site.urlsTitles[0], buf);
                i++;
                break;
            case 13:
                strcpy(site.urls[1], buf);
                i++;
                break;
            case 14:
                strcpy(site.urlsTitles[1], buf);
                i++;
                break;
            case 15:
                strcpy(site.urls[2], buf);
                i++;
                break;
            case 16:
                strcpy(site.urlsTitles[2], buf);
                i++;
                break;
            case 17:
                strcpy(site.urls[3], buf);
                i++;
                break;
            case 18:
                strcpy(site.urlsTitles[3], buf);
                i++;
                break;
            case 19:
                strcpy(site.urls[4], buf);
                i++;
                break;
            case 20:
                strcpy(site.urlsTitles[4], buf);
                i++;
                break;
            case 21:
                strcpy(site.urls[5], buf);
                i++;
                break;
            case 22:
                strcpy(site.urlsTitles[5], buf);
                generateSite(site);
                i=1;
                k++;
                break;
            default:
                break;
        }
        
    };
    fclose(sdata);
    DEV ? printf("Finished at:%d...\n",k):0;
}