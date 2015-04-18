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

void generateSite(SITE *site) {
    srand(time(NULL));
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

