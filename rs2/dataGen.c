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

#define LENGTH(x) (sizeof(x)/sizeof(*(x)))
#define BYTE 30
#define LEN 5
int fkey,rkey,skey;

typedef struct keys {
    char **promoVerbs;
    char **promoNouns;
    char **nouns;
    char **adjs;
    char **verbs;
    char **countries;
    int pVCount;
    int pNCount;
    int nCount;
    int aCount;
    int vCount;
    int cCount;
}KEY;
//KEY *key;

typedef struct rData {
    char **nouns;
    char **adjs;
    char **verbs;
    char *pVerb;
    char *pNoun;
    char *country;
    int  count;
}RDATA;
//RDATA *rData;

#pragma mark Read File Data to KEY
KEY *keyDataObject() {
    int i, line=0; char buf[100];

    KEY *key = (KEY*)malloc(sizeof(KEY));
    
    (*key).promoVerbs = malloc(3 *sizeof(char*));
    for (i=0; i<3; i++) {
        (*key).promoVerbs[i] = malloc((20+1) *sizeof(char));
        switch (i){
            case 0:
                strcpy((*key).promoVerbs[i], "Webcams");
                break;
            case 1:
                strcpy((*key).promoVerbs[i], "Cams");
                break;
            default:
                break;
        }
    }
    (*key).pVCount = 2;
  
    (*key).promoNouns = malloc(3 *sizeof(char*));
    for (i=0; i<3; i++) {
        (*key).promoNouns[i] = malloc((20+1) *sizeof(char));
        switch (i){
            case 0:
                strcpy((*key).promoNouns[i], "Free");
                break;
            case 1:
                strcpy((*key).promoNouns[i], "NoSignup");
                break;
            case 2:
                strcpy((*key).promoNouns[i], "Chat");
                break;
            default:
                break;
        }
    }
    (*key).pNCount = 3;
    
    FILE *fnouns = fopen("nouns.txt", "r");
    (*key).nouns = malloc(20 *sizeof(char*));
    line=0;
    while (fgets (buf, sizeof(buf), fnouns)!= NULL) {
        (*key).nouns[line] = malloc((20+1) *sizeof(char));
        strcpy((*key).nouns[line], buf);
        line++;
    };
    fclose(fnouns);
    (*key).nCount = line;
    
    line=0;
    FILE *fadjs = fopen("adjetives.txt", "r");
    (*key).adjs = malloc(20 *sizeof(char*));
    line=0;
    while (fgets (buf, sizeof(buf), fadjs)!= NULL) {
        (*key).adjs[line] = malloc((20+1) *sizeof(char));
        strcpy((*key).adjs[line], buf);
        line++;
    };
    fclose(fadjs);
    (*key).aCount = line;
    
    line=0;
    FILE *fverbs = fopen("verbs.txt", "r");
    (*key).verbs = malloc(20 *sizeof(char*));
    line=0;
    while (fgets (buf, sizeof(buf), fverbs)!= NULL) {
        (*key).verbs[line] = malloc((20+1) *sizeof(char));
        strcpy((*key).verbs[line], buf);
        line++;
    };
    fclose(fverbs);
    (*key).vCount = line;
    line=0;
    
    FILE *fcountries = fopen("countries.txt", "r");
    (*key).countries = malloc(20 *sizeof(char*));
    line=0;
    while (fgets (buf, sizeof(buf), fcountries)!= NULL) {
        (*key).countries[line] = malloc((20+1) *sizeof(char));
        strcpy((*key).countries[line], buf);
        line++;
    };
    fclose(fcountries);
    (*key).cCount = line;
    line=0;
    
    return key;
}

#pragma mark Generate Random Data
RDATA *rdataObject(KEY *key) {
    int i=0,j=5;
    int nCount = (*key).nCount;
    int aCount = (*key).aCount;
    int vCount = (*key).vCount;
    int cCount = (*key).cCount;
    
    RDATA *rData = (RDATA*)malloc(sizeof(RDATA));
    (*rData).pVerb = malloc((20+1) *sizeof(char));
    strcpy((*rData).pVerb,(*key).promoVerbs[rand() % 1]);
    (*rData).pNoun = malloc((20+1) *sizeof(char));
    strcpy((*rData).pNoun,(*key).promoNouns[rand() % 2]);
    (*rData).nouns = malloc(100 *sizeof(char*));
    while (i<j) {
        (*rData).nouns[i] = malloc((20+1) *sizeof(char));
        strcpy((*rData).nouns[i], (*key).nouns[rand() % nCount]);
        i++;
    }
    i=0;
    (*rData).adjs  = malloc(100 *sizeof(char*));
    while (i<j) {
        (*rData).adjs[i] = malloc((20+1) *sizeof(char));
        strcpy((*rData).adjs[i], (*key).adjs[rand() % aCount]);
        i++;
    }
    i=0;
    (*rData).verbs = malloc(100 *sizeof(char*));
    while (i<j) {
        (*rData).verbs[i] = malloc((20+1) *sizeof(char));
        strcpy((*rData).verbs[i], (*key).verbs[rand() % vCount]);
        i++;
    }
    (*rData).count = j;
    (*rData).country = malloc((10+1) *sizeof(char));
    strcpy((*rData).country, (*key).countries[rand() % cCount]);
    return rData;
}


#pragma mark Generate Title
char *genTitle(RDATA *rData) {
    char *str = (char *) malloc(sizeof(char) * BYTE);
    strcpy(str, (*rData).pVerb);
    strcat(str, " ");
    strcat(str, (*rData).pNoun);
    strcat(str, " - ");
    strcat(str, (*rData).nouns[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).verbs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).adjs[rand() % LEN]);
    return str;
}

#pragma mark Generate Keywords
char *genKeywords(RDATA *rData) {
    char *str = (char *) malloc(sizeof(char) * BYTE);
    strcpy(str, (*rData).pVerb);
    strcat(str, " ");
    strcat(str, (*rData).pNoun);
    strcat(str, " ");
    strcat(str, (*rData).nouns[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).verbs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).adjs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).nouns[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).verbs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).adjs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).nouns[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).verbs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).adjs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).nouns[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).verbs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).adjs[rand() % LEN]);
    return str;
}

#pragma mark Generate Keyword
char *genKeyword(RDATA *rData) {
    char *str = (char *) malloc(sizeof(char) * BYTE);
    strcpy(str, (*rData).verbs[rand() % LEN]);
    return str;
}

#pragma mark Generate Description
char *genDescription(RDATA *rData) {
    char *str = (char *) malloc(sizeof(char) * BYTE);
    strcpy(str, (*rData).pVerb);
    strcat(str, " ");
    strcat(str, (*rData).pNoun);
    strcat(str, " ");
    strcat(str, (*rData).nouns[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).verbs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).adjs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).pNoun);
    strcat(str, " ");
    strcat(str, (*rData).nouns[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).verbs[rand() % LEN]);
    strcat(str, " ");
    strcat(str, (*rData).adjs[rand() % LEN]);
    return str;
}

#pragma mark Generate URL
char *genUrl(RDATA *rData) {
    char *str = (char *) malloc(sizeof(char) * BYTE);
    strcpy(str, (*rData).pVerb);
    strcat(str, "-");
    strcat(str, (*rData).pNoun);
    strcat(str, "-");
    strcat(str, (*rData).nouns[rand() % LEN]);
    strcat(str, "-");
    strcat(str, (*rData).verbs[rand() % LEN]);
    strcat(str, "-");
    strcat(str, (*rData).adjs[rand() % LEN]);
    return str;
}

void generateSite(SITE *site) {
    int j = rand()%3;
    if (j==1) {
        genChatFourTemp(site);
        printf("Generated chat_four_mod_template\n");
    }else if(j==2) {
        genFourTemp(site);
        printf("Generated four_mod_template\n");
    }else{
        genSixTemp(site);
        printf("Generated six_mod_template\n");
    }
}

#pragma mark Generate Random Sites
void generateData(int dataCount) {
    srand(time(NULL)); int i,j,k,line;
    
    SITE sites[dataCount];
    char urls[dataCount][20];
    
    KEY key;
    strcpy(key.promoVerbs[0], "WebCams");
    strcpy(key.promoVerbs[1], "Cams");
    strcpy(key.promoNouns[0], "Free");
    strcpy(key.promoNouns[1], "NoSignup");
    strcpy(key.promoNouns[2], "Chat");
    line=0;
    FILE *nouns = fopen("nouns.txt", "r");)
    while (fgets (buf, sizeof(buf), nouns)!= NULL) {
        strcpy(key.nouns[line], buf);
        line++;
    };
    fclose(nouns);
    line=0;
    FILE *adjs = fopen("adjetives.txt", "r");)
    while (fgets (buf, sizeof(buf), adjs)!= NULL) {
        strcpy(key.adjs[line], buf);
        line++;
    };
    fclose(adjs);
    line=0;
    FILE *verbs = fopen("verbs.txt", "r");)
    while (fgets (buf, sizeof(buf), verbs)!= NULL) {
        strcpy(key.verbs[line], buf);
        line++;
    };
    fclose(verbs);
    line=0;
    FILE *countries = fopen("countries.txt", "r");)
    while (fgets (buf, sizeof(buf), countries)!= NULL) {
        strcpy(key.country[line], buf);
        line++;
    };
    fclose(countries);
    
    for (i=0; i<dataCount; i++) {
        //gen rand data
        RDATA rdata;
        strcpy(rdata.pVerb, key.promoVerbs[rand()%2]);
        strcpy(rdata.pNoun, key.promoNouns[rand()%3]);
        while (j<5) {
            strcpy(rdata.nouns[j], key.nouns[rand()%5]);
            strcpy(rdata.adjs[j], key.adjs[rand()%5]);
            strcpy(rdata.verbs[j], key.verbs[rand()%5]);
        }
        strcpy(rdata.country, key.countries[rand()%10]);

        //gen rand site w/rand data
        SITE site;
        site.url = genUrl(&rdata);
        site.title = genTitle(&rdata);
        site.description = genDescription(&rdata);
        site.keywords = genKeywords(&rdata);
        site.keyword = genKeyword(&rdata);
        strcpy(site.country, rdata.country);
        
        //add site to sites array
        sites[i] = &site;
        
        if (i==dataCount) {
            //iterate sites for urls
            for (i=0; i<dataCount; i++) {
                
                //add each url to urls array
                strcpy(urls[i], sites[i].url);
                
                if (i==dataCount) {
                    
                    //iterate sites to create template
                    for (i=0; i<dataCount; i++) {
                        k=0;
                        //gen ten random urls
                        while (k<10) {
                            //random number between 0-len(urls)
                            int random = rand() % dataCount;
                            
                            //compare url[random] to current url
                            if ( strcmp(sites[i].url, urls[random])==0) {
                                printf("Skipped existing url");
                            }else{
                                strcpy(sites[i].urls[k], urls[random]);
                                j++;
                            }
                        }
                        if (i==dataCount) {
                            
                            generateSite(&sites[i]);
                        }
                    }
                }
            }
        }
    }
}