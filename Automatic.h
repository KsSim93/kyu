#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>







void Auto_apply(){



	char *pathname = "./myRules";
	int mode = R_OK;

	if( access( pathname, mode ) == 0 ){
	
		system("iptables -F");
	
		FILE *fp ;
		
		char wstring[1024]; //write 할 문자열
		fp=fopen("myRules","rt");
		
		


		while(fgets(wstring,1024,fp)!=NULL){

				system(wstring);	

		}

		fclose(fp);

	}



	else{
		
	}
				






}
