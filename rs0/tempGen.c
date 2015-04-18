	//for (int i = 0; i< sizeof(files); i++) {

		FILE *keywords = fopen("keywords.txt", "r");

		//FILE *syt = fopen("site.txt", "r");


		while (fgets (buf, sizeof(buf), keywords)) {
			//fprintf(copy_syt, "%s%s\n", buf,"\\n\");");
			//if(buf[strlen(buf) -1] == '\n') {
			//	buf[strlen(buf) - 1] = '\0';
			//}
			//fprintf(copy_syt, "fprintf(site,\"%s\\n\");\n", buf);
			// fprint(file, "some_string\n"); <--desired line result
    		//printf("%s", buf);

    		//printf("string1 before the buffer. The buffer: %s And add this on the same line?\n", buf);
  		}
  		//fprintf(copy_syt, "}");
  		//fclose(copy_syt);
  		//fclose(syt);
  		//system("gcc -Wall siteGen.c template_one.c");

  		//pubM();
		//template_one(site);
  		//fclose(site);

	//}
  	
  	//template_one();