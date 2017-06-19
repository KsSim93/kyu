//미완

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

del_menu(){
	FILE *fp ;
	FILE *ffpp;
	char wstring[1024]; //write 할 문자열
	int iChangePos;//파일의 변경될 위치
	char* posFind = NULL;//비교할 문자의 포인터

	system("iptables -L>delList");

	fp=fopen("delList","rt");
	ffpp=fopen("del","a");

	if(fp&&ffpp){

		while(!feof(fp)){

			fgets(wstring,1024,fp);

			if(NULL != strstr(wstring,"Chain INPUT (policy ACCEPT)")){}

			else if (NULL != strstr(wstring,"Chain FORWARD (policy ACCEPT)")){}

			else if(NULL != strstr(wstring,"Chain OUTPUT (policy ACCEPT)")){}
				
			else if(NULL != strstr(wstring,"target     prot opt source               destination")){}
				 

			else			
				fprintf(ffpp,"%s",wstring);	
				
			
			
		}

		fclose(fp);
		fclose(ffpp);
	}
	system("rm delList");
	

	system("sudo iptables -F");
	printf("저장 기록까지 삭제 하시겠습니까? Y/N    ");
	char yorn;
	scanf("%s",&yorn);
	
	if(yorn=='Y'||yorn=='y'){

		system("rm myRules");
	}
	else if(yorn=='N'||yorn=='n'){}

	else printf("잘못된 입력입니다.");


}
