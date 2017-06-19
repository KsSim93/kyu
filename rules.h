#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void show_rules(){
	FILE *fp ;
	FILE *ffpp;
	char wstring[1024]; //write 할 문자열
	int iChangePos;//파일의 변경될 위치
	char* posFind = NULL;//비교할 문자의 포인터

	system("iptables -L>RuleList");

	fp=fopen("RuleList","rt");
	ffpp=fopen("rule","a");
	
	wstring[0]='\0';
	if(fp&&ffpp){

		while(fgets(wstring,1024,fp)!=NULL){

			if( NULL != (posFind = strstr(wstring,"Chain INPUT (policy ACCEPT)"))){

				iChangePos =(int)(posFind - wstring);

				strncpy(wstring+iChangePos,"서버로 들어오는 기본 정책\n",38);

			}

			if( NULL != (posFind = strstr(wstring,"Chain FORWARD (policy ACCEPT)"))){

				iChangePos =(int)(posFind - wstring);

				strncpy(wstring+iChangePos,"서버에서 forwarding 기본 정책\n",39);

			}			

			if( NULL != (posFind = strstr(wstring,"Chain OUTPUT (policy ACCEPT)"))){

				iChangePos =(int)(posFind - wstring);

				strncpy(wstring+iChangePos,"서버에서 나가는 기본 정책\n",38);

			}
			fprintf(ffpp,"%s",wstring);
		}

		fclose(fp);
		fclose(ffpp);
	}
	
	printRules();

}
void printRules(){

	FILE *fp;
	fp=fopen("rule","r");
	char wstring[1024];
	wstring[0]='\0';
	while(fgets(wstring,1024,fp)!=NULL){
		
		printf("%s",wstring);
		
	}
	fclose(fp);
	system("rm rule");
	system("rm RuleList");

}
