#include <stdlib.h>
#include <stdio.h>



void apply_rules(){

	char wstring[1024];

	FILE *fp ;
	fp=fopen("myRules","r");
	
	while(fgets(wstring,1024,fp)!=NULL){

		system(wstring);	

	}
	fclose(fp);
}
