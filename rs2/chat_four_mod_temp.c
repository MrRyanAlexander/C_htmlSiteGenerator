//
//  chat_four_mod_temp.c
//  
//
//  Created by Ryan Alex on 12/1/14.
//
//

#include "chat_four_mod_temp.h"

void genChatFourTemp(SITE *site) {
    char *url = malloc(100 *sizeof(char*));
    strcpy(url, (*site).url);
    mkdir(url, 0700); 				//make a new directory using the new name
    strcat(url, "/index.php");      //concat the new directory name with the prefix
    FILE *file = fopen(url, "w");   //create a new file in the new directory
    
    fprintf(file,
    
        "<?php\n"
        "$curlData = '<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<SMLQuery>\n"
        "<Options MaxResults=\"5\"/>\n"
        "<AvailablePerformers Exact=\"false\" PageNum=\"1\" CountTotalResults=\"true\">\n"
        "<Include>\n"
        "      <Country/>\n"
        "      <Headline/>\n"
        "      <Descriptions/>\n"
        "      <Rating/>\n"
        "      <Media>biopic</Media>\n"
        "      <FreeChatSort/>\n"
        "      <PerformanceSort/>\n"
        "      <HDSort/>\n"
        "</Include>\n"
        "<Constraints>\n"
        "      <StreamType>live,recorded, offline</StreamType>\n"
        "      <PublicProfile/>\n"
        "      <Name></Name>\n"
        "      <RelativeURLs/>\n"
        "      <Keyword>%s</Keyword>\n"
        "      <Country>%s</Country>\n"
        "      <Ethnicity></Ethnicity>\n"
        "      <Fetishes></Fetishes>\n"
        "      <SexPref></SexPref>\n"
        "      <Gender></Gender>\n"
        "</Constraints>\n"
        "</AvailablePerformers>\n"
        "</SMLQuery>';\n"
        "$url='http://affiliate.streamate.com/SMLive/SMLResult.xml';\n"
        "$curl = curl_init();\n"
        "curl_setopt ($curl, CURLOPT_URL, $url);\n"
        "curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);\n"
        "curl_setopt($curl,CURLOPT_TIMEOUT,120);\n"
        "curl_setopt($curl,CURLOPT_HTTPHEADER,array (\n"
        "    'Content-Type: text/xml; charset=utf-8'\n"
        "));\n"
        "curl_setopt ($curl, CURLOPT_POST, 1);\n"
        "curl_setopt ($curl, CURLOPT_POSTFIELDS, $curlData);\n"
        "$result = curl_exec($curl);\n"
        "curl_close ($curl);\n"
        "$xml = simplexml_load_string ($result);\n"
        "$perfs = array();\n"
        "foreach ($xml->AvailablePerformers->Performer as $perf) {\n"
        "    array_push($perfs, $perf);\n"
        "}; \n"
        "?>\n"
        "<!DOCTYPE html>\n"
        "<html>\n"
        "<head>\n"
        "<title>%s</title>\n"
        "<meta name=\"Description\" content=\"%s\">\n"
        "<meta name=\"Keywords\" content=\"%s\">\n"
        "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n"
        "</head>\n"
        "<body>\n"
        "    <h1>%s</h1>\n"
        "    <div class=\"tcenter\">\n"
        "        <?php echo '<a href=\"#'.$perfs[0]->attributes()->Name.'\" ><img class=\"xm  me md5\" src=\"featCam.gif\" xl=\"'.$perfs[0]->attributes()->Name.'\"></a>'; ?>\n"
        "    </div>\n"
        "    <table class=\"bd1 itb\">\n"
        "        <tbody>\n"
        "            <tr>\n"
        "                <td>\n"
        "                    <table>\n"
        "                        <tbody>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <table class=\"tbl320\">\n"
        "                                        <tbody>\n"
        "                                            <tr>\n"
        "                                                <td>\n"
        "                                                    <?php echo '<a href=\"#'.$perfs[0]->attributes()->Name.'\" ><img class=\"xm im mc me\" src=\"http://streamate.com'.$perfs[0]->Media->Pic->Full->attributes()->Src.'\" xl=\"'.$perfs[0]->attributes()->Name.'\" ></a>'; ?>\n"
        "                                                </td>\n"
        "                                            </tr>\n"
        "                                            <tr>\n"
        "                                                <td>\n"
        "                                                    <?php echo ' '.$perfs[0]->attributes()->Name.'<a href=\"#'.$perfs[0]->attributes()->Name.'\" ><img class=\"xm me\" src=\"live.gif\" xl=\"'.$perfs[0]->attributes()->Name.'\"></a>'; ?>\n"
        "                                                </td>\n"
        "                                            </tr>\n"
        "                                        </tbody>\n"
        "                                    </table>\n"
        "                                </td>\n"
        "                                <td >\n"
        "                                    <table class=\"bd1 md15 tbl320 wtb cp10\" >\n"
        "                                        <tbody>\n"
        "                                            <tr>\n"
        "                                                <td valign=\"top\" class=\"tleft\" >\n"
        "                                                    <?php echo '<strong>'.$perfs[0]->attributes()->Name.'</strong>';?> I love it when you stroke it for me.<br/><br/>\n"
        "                                                    <strong>Guest:</strong> I playing with myself for you sexy.<br/><br/>\n"
        "                                                    <strong>Guest:</strong> You are gorgeous baby!<br/>\n"
        "                                                </td>\n"
        "                                            </tr>\n"
        "                                            <tr>\n"
        "                                                <td>\n"
        "                                                    <?php echo '<a href=\"#'.$perfs[0]->attributes()->Name.'\" ><img class=\"xm  md30 me\" src=\"chatNow.gif\" xl=\"'.$perfs[0]->attributes()->Name.'\"></a>'; ?>\n"
        "                                            </tr>\n"
        "                                        </tbody>\n"
        "                                    </table>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                        </tbody>\n"
        "                    </table>\n"
        "                </td>\n"
        "            </tr>\n"
        "        </tbody>\n"
        "    </table>\n"
        "    \n"
        "    <table class=\"tbl304 bs40\">\n"
        "        <tbody>\n"
        "            <tr>\n"
        "                <td>\n"
        "                    <table class=\"bd1 itb\">\n"
        "                        <tbody>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo '<a href=\"#'.$perfs[1]->attributes()->Name.'\" ><img class=\"xm im me mi\" src=\"http://streamate.com'.$perfs[1]->Media->Pic->Full->attributes()->Src.'\" xl=\"'.$perfs[1]->attributes()->Name.'\" ></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo ' '.$perfs[1]->attributes()->Name.'<a href=\"#'.$perfs[1]->attributes()->Name.'\" ><img class=\"xm me\" src=\"live.gif\" xl=\"'.$perfs[1]->attributes()->Name.'\"></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo '<a href=\"#'.$perfs[1]->attributes()->Name.'\" ><img class=\"xm  me md27\" src=\"c.gif\" xl=\"'.$perfs[1]->attributes()->Name.'\"></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                        </tbody>\n"
        "                    </table>\n"
        "                </td>\n"
        "                <td>\n"
        "                    <table class=\"bd1 itb\">\n"
        "                        <tbody>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo '<a href=\"#'.$perfs[2]->attributes()->Name.'\" ><img class=\"xm im me mi\" src=\"http://streamate.com'.$perfs[2]->Media->Pic->Full->attributes()->Src.'\" xl=\"'.$perfs[2]->attributes()->Name.'\" ></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo ' '.$perfs[2]->attributes()->Name.'<a href=\"#'.$perfs[2]->attributes()->Name.'\" ><img class=\"xm me\" src=\"live.gif\" xl=\"'.$perfs[2]->attributes()->Name.'\"></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo '<a href=\"#'.$perfs[2]->attributes()->Name.'\" ><img class=\"xm  me md27\" src=\"c.gif\" xl=\"'.$perfs[2]->attributes()->Name.'\"></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                        </tbody>\n"
        "                    </table>\n"
        "                </td>\n"
        "            </tr>\n"
        "        </tbody>\n"
        "    </table>\n"
        "    \n"
        "    <table class=\"tbl304\">\n"
        "        <tbody>\n"
        "            <tr>\n"
        "                <td>\n"
        "                    <?php echo '<a href=\"#'.$perfs[1]->attributes()->Name.'\" ><img class=\"xm me\" src=\"lifeMem.jpg\" xl=\"'.$perfs[1]->attributes()->Name.'\"></a>'; ?>\n"
        "                </td>\n"
        "            </tr>\n"
        "        </tbody>\n"
        "    </table>\n"
        "    \n"
        "    <table class=\"tbl304 bs40\">\n"
        "        <tbody>\n"
        "            <tr>\n"
        "                <td>\n"
        "                    <table class=\"bd1 itb\">\n"
        "                        <tbody>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo '<a href=\"#'.$perfs[3]->attributes()->Name.'\" ><img class=\"xm im me mi\" src=\"http://streamate.com'.$perfs[3]->Media->Pic->Full->attributes()->Src.'\" xl=\"'.$perfs[3]->attributes()->Name.'\" ></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo ' '.$perfs[3]->attributes()->Name.'<a href=\"#'.$perfs[3]->attributes()->Name.'\" ><img class=\"xm me\" src=\"live.gif\" xl=\"'.$perfs[3]->attributes()->Name.'\"></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo '<a href=\"#'.$perfs[3]->attributes()->Name.'\" ><img class=\"xm  me md27\" src=\"c.gif\" xl=\"'.$perfs[3]->attributes()->Name.'\"></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                        </tbody>\n"
        "                    </table>\n"
        "                </td>\n"
        "                <td>\n"
        "                    <table class=\"bd1 itb\">\n"
        "                        <tbody>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo '<a href=\"#'.$perfs[4]->attributes()->Name.'\" ><img class=\"xm im me mi\" src=\"http://streamate.com'.$perfs[4]->Media->Pic->Full->attributes()->Src.'\" xl=\"'.$perfs[4]->attributes()->Name.'\" ></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo ' '.$perfs[4]->attributes()->Name.'<a href=\"#'.$perfs[4]->attributes()->Name.'\" ><img class=\"xm me\" src=\"live.gif\" xl=\"'.$perfs[4]->attributes()->Name.'\"></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                            <tr>\n"
        "                                <td>\n"
        "                                    <?php echo '<a href=\"#'.$perfs[4]->attributes()->Name.'\" ><img class=\"xm  me md27\" src=\"c.gif\" xl=\"'.$perfs[4]->attributes()->Name.'\"></a>'; ?>\n"
        "                                </td>\n"
        "                            </tr>\n"
        "                        </tbody>\n"
        "                    </table>\n"
        "                </td>\n"
        "            </tr>\n"
        "        </tbody>\n"
        "    </table>\n"
        "    \n"
        "    <table class=\"tbl608\">\n"
        "        <tbody>\n"
        "            <tr>\n"
        "                <td class=\"tleft\">\n"
        "                    <?php echo '<strong>'.$perfs[3]->attributes()->Name.'</strong>  :'.$perfs[3]->Descriptions->About.'.'; ?>\n"
        "                </td>\n"
        "            </tr>\n"
        "        </tbody>\n"
        "    </table>\n"
        "    \n"
        "    <table class=\"tbl304 bs20\">\n"
        "        <tbody>\n"
        "            <tr>\n"
        "                <td>\n"
        "                    <?php echo '<a href=\"#'.$perfs[3]->attributes()->Name.'\" ><img class=\"xm  me\" src=\"enter.gif\" xl=\"'.$perfs[3]->attributes()->Name.'\"><a/>'; ?>\n"
        "            </tr>\n"
        "        </tbody>\n"
        "    </table>\n"
        "    \n"
        "</body>\n"
        "<script src=\"script.js\" type=\"text/javascript\"></script>\n"
        "<script>\n"
        "    function tran(el) {\n"
        "    console.log(el.getAttribute(\"xl\"));\n"
        "    window.location = \"http://google.com\";\n"
        "}\n"
        "</script>\n"
        "<script>\n"
        "  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){\n"
        "  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),\n"
        "  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)\n"
        "  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');\n"
        
        "  ga('create', 'UA-45365588-5', 'auto');\n"
        "  ga('send', 'pageview');\n"
        
        "</script>\n"
        "</html>", (*site).keyword, (*site).country, (*site).title, (*site).description, (*site).keywords, (*site).title);
        
    fclose(file);
    free(url);
    didGenSite=1;
}