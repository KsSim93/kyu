#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>







void Auto_apply(){



	char *pathname = "./myRules";
	int mode = R_OK;

	if( access( pathname, mode ) == 0 ){
	
		
		system("iptables -L>AutoRule");

	
		FILE *fp ;
		FILE *ffpp;
		char wstring[1024]; //write 할 문자열
		int iChangePos;//파일의 변경될 위치
		char* posFind = NULL;//비교할 문자의 포인터

		fp=fopen("myRules","rt");
		ffpp=fopen("AutoRule","a");


		if(fp&&ffpp){

		while(fgets(wstring,1024,ffpp)!=NULL){

			if( NULL != (posFind = strstr(wstring,"Chain INPUT (policy ACCEPT)"))){

				iChangePos =(int)(posFind - wstring);

				strncpy(wstring+iChangePos,"\n",37);

			}

			if( NULL != (posFind = strstr(wstring,"Chain FORWARD (policy ACCEPT)"))){

				iChangePos =(int)(posFind - wstring);

				strncpy(wstring+iChangePos,"\n",39);

			}			

			if( NULL != (posFind = strstr(wstring,"Chain OUTPUT (policy ACCEPT)"))){

				iChangePos =(int)(posFind - wstring);

				strncpy(wstring+iChangePos,"\n",38);

			}
			fprintf(ffpp,"%s",wstring);
		}

		fclose(fp);
		fclose(ffpp);
	}
	
	/*	char wstring[1024];

		FILE *fp ;
		fp=fopen("myRules","r");

			while(fgets(wstring,1024,fp)!=NULL){

				system(wstring);	

			}

		fclose(fp);*/

	}

	else{
		
	}
				






}
