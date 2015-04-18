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

char buf[20];

typedef struct keys {
    char promoVerbs[2][WORD];
    char promoNouns[3][WORD];
    char nouns[20][WORD];
    char adjs[20][WORD];
    char verbs[20][WORD];
    char countries[10][4];
}KEY;
//KEY *key;

typedef struct rData {
    char nouns[5][WORD];
    char adjs[5][WORD];
    char verbs[5][WORD];
    char pVerb[WORD];
    char pNoun[WORD];
    char country[4];
}RDATA;
//RDATA *rData;

#pragma mark Generate Title
char genTitle(char *title[LWORD], RDATA rData) {
    strcpy(title, rData.pVerb);
    strcat(title, " ");
    strcat(title, rData.pNoun);
    strcat(title, " - ");
    int ints[LEN];
    randomInts(ints,LEN,LEN);
    strcat(title, rData.nouns[ints[0]]);
    strcat(title, " ");
    strcat(title, rData.verbs[ints[1]]);
    strcat(title, " ");
    strcat(title, rData.adjs[ints[2]]);
}

#pragma mark Generate Keywords
char genKeywords(char *keywords[LWORD], RDATA rData) {
    strcpy(keywords, rData.pVerb);
    strcat(keywords, " ");
    strcat(keywords, rData.pNoun);
    strcat(keywords, " ");
    int ints[LEN];
    randomInts(ints,LEN,LEN);
    strcat(keywords, rData.nouns[ints[0]]);
    strcat(keywords, " ");
    strcat(keywords, rData.verbs[ints[1]]);
    strcat(keywords, " ");
    strcat(keywords, rData.adjs[ints[2]]);
    strcat(keywords, " ");
    strcat(keywords, rData.nouns[ints[3]]);
    strcat(keywords, " ");
    strcat(keywords, rData.verbs[ints[4]]);
    strcat(keywords, " ");
    randomInts(ints,LEN,LEN);
    strcat(keywords, rData.adjs[ints[0]]);
    strcat(keywords, " ");
    strcat(keywords, rData.nouns[ints[1]]);
    strcat(keywords, " ");
    strcat(keywords, rData.verbs[ints[2]]);
    strcat(keywords, " ");
    strcat(keywords, rData.adjs[ints[3]]);
    strcat(keywords, " ");
    strcat(keywords, rData.nouns[ints[4]]);
    strcat(keywords, " ");
    randomInts(ints,LEN,LEN);
    strcat(keywords, rData.verbs[ints[0]]);
    strcat(keywords, " ");
    strcat(keywords, rData.adjs[ints[1]]);
}

#pragma mark Generate Keyword
char genKeyword(char *keyword[WORD], RDATA rData) {
    strcpy(keyword, rData.verbs[rand() % LEN]);
}

#pragma mark Generate Description
char genDescription(char *desc[LWORD], RDATA rData) {
    strcpy(desc, rData.pVerb);
    strcat(desc, " ");
    strcat(desc, rData.pNoun);
    strcat(desc, " ");
    int ints[LEN];
    randomInts(ints,LEN,LEN);
    strcat(desc, rData.nouns[ints[0]]);
    strcat(desc, " ");
    strcat(desc, rData.verbs[ints[1]]);
    strcat(desc, " ");
    strcat(desc, rData.adjs[ints[2]]);
    strcat(desc, " ");
    strcat(desc, rData.pNoun);
    strcat(desc, " ");
    randomInts(ints,LEN,LEN);
    strcat(desc, rData.nouns[ints[3]]);
    strcat(desc, " ");
    strcat(desc, rData.verbs[ints[4]]);
    strcat(desc, " ");
    strcat(desc, rData.adjs[ints[0]]);
}

#pragma mark Generate URL
char genUrl(char *url[LWORD], RDATA rData) {
    strcpy(url, rData.pVerb);
    strcat(url, "-");
    strcat(url, rData.pNoun);
    strcat(url, "-");
    int ints[LEN];
    randomInts(ints,LEN,LEN);
    strcat(url, rData.nouns[ints[0]]);
    strcat(url, "-");
    strcat(url, rData.verbs[ints[1]]);
    strcat(url, "-");
    strcat(url, rData.adjs[ints[2]]);
}

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
int randomInts(int randInts[LEN], int randTotal, int iterateTotal) {
    //int randInts[totalToInsert];			//array of ints
    int randInt = rand()%randTotal;		//current random int
    int currentTotal = 1;					//total number of ints
    randInts[0] = randInt;					//first random int
    int i,j; 								//iterators
    for(i=1; i<iterateTotal; i++) {
        randInt = rand()%randTotal;
        for (j=0; j<currentTotal; j++) {
            //DEV ? printf("Comparing %d to %d\n", randInt,randInts[j]):0;
            if(randInt==randInts[j]){
                //DEV ? printf("Match found %d=%d\n",randInt,randInts[j]):0;
                randInt=rand()%randTotal;
                j=0;
            }
        }
        randInts[i] = randInt;
        //DEV ? printf("Added %d to index:%d\n",randInt,i):0;
        currentTotal++;
        //DEV ? printf("Increment total:%d\n",currentTotal):0;
    }
    //DEV ? printf("Complete\n"):0;
}
#pragma mark Generate Random Sites
void generateData(int dataCount) {
    srand(time(NULL)); int i,j,k,l,line;
    
    SITE sites[dataCount];
    char urls[dataCount][LWORD];
    
    KEY key;
    strcpy(key.promoVerbs[0], "WebCams");
    strcpy(key.promoVerbs[1], "Cams");
    strcpy(key.promoNouns[0], "Free");
    strcpy(key.promoNouns[1], "NoSignup");
    strcpy(key.promoNouns[2], "Chat");
    line=0;
    FILE *nouns = fopen("nouns.txt", "r");
    while (fgets (buf, sizeof(buf), nouns)!= NULL) {
        strcpy(key.nouns[line], buf);
        line++;
    };
    fclose(nouns);
    line=0;
    FILE *adjs = fopen("adjetives.txt", "r");
    while (fgets (buf, sizeof(buf), adjs)!= NULL) {
        strcpy(key.adjs[line], buf);
        line++;
    };
    fclose(adjs);
    line=0;
    FILE *verbs = fopen("verbs.txt", "r");
    while (fgets (buf, sizeof(buf), verbs)!= NULL) {
        strcpy(key.verbs[line], buf);
        line++;
    };
    fclose(verbs);
    line=0;
    FILE *countries = fopen("countries.txt", "r");
    while (fgets (buf, sizeof(buf), countries)!= NULL) {
        strcpy(key.countries[line], buf);
        line++;
    };
    fclose(countries);
    DEV ? printf("Generated KEY\n"):0;
    
    int ints[5];

    for (i=0; i<dataCount; i++) {
        //gen rand data
        RDATA rdata;
        strcpy(rdata.pVerb, key.promoVerbs[rand()%PV]);
        strcpy(rdata.pNoun, key.promoNouns[rand()%PN]);
        j=0; k=0; l=0;
        
        randomInts(ints,KLEN,LEN);
        
        while (j<LEN) {
            strcpy(rdata.nouns[j], key.nouns[ints[j]]);
            j++;
            //DEV ? printf("generating noun for rdata\n"):0;
        }
        randomInts(ints,KLEN,LEN);
        while (k<LEN) {
            strcpy(rdata.adjs[k], key.adjs[ints[k]]);
            k++;
            //DEV ? printf("generating adj for rdata\n"):0;
        }
        randomInts(ints,KLEN,LEN);
        while (l<LEN) {
            strcpy(rdata.verbs[l], key.verbs[ints[l]]);
            l++;
            //DEV ? printf("generating verb for rdata\n"):0;
        }
        
        
        strcpy(rdata.country, key.countries[rand()%CNTRY]);
        DEV ? printf("%d:Generated RDATA\n",i):0;
        
        //gen rand site w/rand data
        genUrl(&sites[i].url, rdata);
        //check if url already exists
        if (i>0) {
            for (j=0; j<i; j++) {
                //printf("Comparing \n%s\n%s\n",sites[i].url,sites[j].url);
                if ( strcmp(sites[i].url, sites[j].url) == 0) {
                    genUrl(&sites[i].url, rdata);
                    j=0;
                    DEV ? printf("Url exists. Reginerating\n"):0;
                }else{
                    //printf("not match url\n");
                }
            }
        }

        genTitle(&sites[i].title, rdata);
        genDescription(&sites[i].description, rdata);
        genKeywords(&sites[i].keywords, rdata);
        genKeyword(&sites[i].keyword, rdata);
        strcpy(sites[i].country, rdata.country);
        DEV ? printf("%d:Created site.url object with address:%p\n",i, sites[i].url):0;
        
        
        //DEV ? printf("%d:Generated Template\n",i):0;
        
        //if (i==dataCount-1) {
            //iterate sites for urls
            //for (i=0; i<dataCount; i++) {
            //    generateSite(sites[i]);
                //add each url to urls array
                //strcpy(urls[i], sites[i].url);
                //DEV ? printf("%d:Added url to urls\n",i):0;
                /*
                if (i==dataCount-1) {
                    int ready=0;
                    //iterate sites to create template
                    for (i=0; i<dataCount; i++) {
                        k=0;
                        DEV ? printf("%d:Generating..template\n",i):0;
                        //gen ten random urls
                        while (k<10) {
                            //random number between 0-len(urls)
                            int random = rand() % dataCount;
                            
                            //compare url[random] to current url
                            if ( strcmp(sites[i].url, urls[random])==0) {
                                DEV ? printf("%d:Skipped existing url\n",k):0;
                            }else{
                                DEV ? printf("%d:New URL detected\n",k):0;
                                strcpy(sites[i].urls[k], urls[random]);
                                k++;
                                if (k>9) {
                                    generateSite(sites[i]);
                                    DEV ? printf("%d:Generated Template\n",i):0;
                                }
                            }
                        }
                    }
                }*/
            //}
        //}
        //DEV ? printf("Created object:%d\n",i):0;
    }
    for (i=0; i<dataCount; i++) {
        generateSite(sites[i]);
        DEV ? printf("Created site:%d\n",i):0;
    }
    DEV ? printf("Finished at:%d...\n",i):0;
}