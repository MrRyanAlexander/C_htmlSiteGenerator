//
//  htmlTest.c
//  
//
//  Created by Ryan Alex on 11/3/14.
//
//

#include "htmlTest.h"

void functionTest();

int main( void )
{
    functionTest();

}

void functionTest ()
{
    
    FILE *myhtmlfile = fopen("new.html", "w"); // open the file
    fprintf(myhtmlfile,"<HTML><BODY>\n");
    fprintf(myhtmlfile,"<font size=\"5\">Hello, world</font></body></html>");
    fclose(myhtmlfile); // close the file
    fopen("new.html", "r");
}