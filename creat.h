#include <stdlib.h>
#include <stdio.h>


FILE *fp ;
void creat_other(){

	int in;
	char IP[18];
	char PORT[18];
	char result[BUFSIZ];
	char interface[16];
	int leng = 0;
	char syn[]="iptables -A INPUT -syn -p TCP -d ! ";
	char ping_1[]="iptables -A INPUT -s ";
	char ping_2[]=" -p ICMP --icmp-type echo-request -j ACCEPT";

	char cre_6[]="iptables -A INPUT ";
	char cre_6_1[]="-i ";
	char cre_6_2[]=" -p TCP -d ! ";
	char yorn;



	system("clear");

	printf("	====================================\n");
	printf("	\n");		
	printf("	        기타\n");
	printf("	\n");		
	printf("	--1. 들어오지않는 패킷(A를 제외한 나머지)\n");
	printf("	--2. TCP 접속을 한 방향으로만 가능\n");
	printf("	--3. ping 허용\n");
	printf("	--4. 목적지 주소로 가는 모든 컴퓨터의 TCP 패킷을 ACCEPT\n");
	printf("        --5. 비정상적 패킷 차단\n");
	printf("	\n");	
	printf("	=====================================\n");

	scanf("%d",&in);

	switch(in){

		case 1:	
			creat_INPUT_other();
			
			break;
		case 2:
			IP[0]='\0';
			PORT[0]='\0';
			printf("IP를 입력하시오.  ");
			scanf("%s",IP);
			printf("PORT를 입력하시오.  ");
			scanf("%s",PORT);
			
			result[0]='\0';
			while (IP[leng] != '\0')
			      leng++;
			IP[leng]=' ';
			IP[leng+1]='\0';


			
			strcat(result, syn);
			strcat(result, IP);
			strcat(result, PORT);	
			
			fp=fopen("myRules","a");
			fprintf(fp,"%s \n",result);
			fclose(fp);
			break;
		case 3:
			IP[0]='\0';
			PORT[0]='\0';
			printf("IP를 입력하시오.  ");
			scanf("%s",IP);
			printf("PORT를 입력하시오.  ");
			scanf("%s",PORT);
			
			
			
			while (IP[leng] != '\0')
			      leng++;
			IP[leng]=' ';
			IP[leng+1]='\0';



			result[0]='\0';
			strcat(result, ping_1);
			strcat(result, IP);
			strcat(result, ping_2);	
			
			fp=fopen("myRules","a");
			fprintf(fp,"%s \n",result);
			fclose(fp);
			break;
		case 4:

			IP[0]='\0';
			PORT[0]='\0';
			interface[0]='\0';
			result[0]='\0';

			
			printf("IP를 입력하시오.  ");
			scanf("%s",IP);
			printf("PORT를 입력하시오.  ");
			scanf("%s",PORT);
			

			
			printf("인터페이스를 적용하시겠습니까 ? : Y/N ");
			
			scanf("%s",&yorn);
			
			while (IP[leng] != '\0')
			      leng++;
			IP[leng]=' ';
			IP[leng+1]='\0';

			if(yorn=='Y'||yorn=='y'){
				printf("인터페이스를 입력하시오.  ");
				scanf("%s",interface);

				strcat(result, cre_6);
				strcat(result, cre_6_1);
				strcat(result, interface);
				strcat(result, cre_6_2);
				strcat(result, IP);
				strcat(result, PORT);	
			
				fp=fopen("myRules","a");
				fprintf(fp,"%s \n",result);
				fclose(fp);
				break;

			}
			else if(yorn=='N'||yorn=='n'){

				strcat(result, cre_6);
				strcat(result, cre_6_2);
				strcat(result, IP);
				strcat(result, PORT);	
			
				fp=fopen("myRules","a");
				fprintf(fp,"%s \n",result);
				fclose(fp);
				break;
			}
		case 5:
			fp=fopen("myRules","a");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ACK,FIN -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ALL NONE -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ALL PSH,FIN FIN -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ALL URG,PSH,FIN -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ALL SYN,ACK,FIN -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ALL SYN,FIN,PSH -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ALL SYN,FIN,RST -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ALL SYN,FIN,RST,PSH -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ALL SYN,FIN,ACK,RST -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ALL SYN,ACK,FIN,RST,PSH -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags FIN,RST FIN,RST -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags SYN,FIN SYN,FIN -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ACK,PSH PSH -j DROP\n");
			fprintf(fp,"iptables -A INPUT -p TCP --tcp-flags ACK,URG URG -j DROP\n");
			fclose(fp);

			
			
		default:
			system("clear");
			printf("잘못된 입력입니다.\n");
			menu();
	}


}

void creat_INPUT_other(){

	int in;
	
	system("clear");

	printf("	====================================\n");
	printf("	\n");		
	printf("	   들어오지않는 패킷(A를 제외한 나머지)\n");
	printf("	\n");		
	printf("	--1. DROP\n");
	printf("	--2. ACCEPT\n");
	printf("	\n");	
	printf("	=====================================\n");

	scanf("%d",&in);


	char drop_1[]="iptables -A INPUT -s ! ";
	char drop_2[]=" -p ";
	char drop_3[]=" -j DROP\n";
	char drop_4[]=" -j ACCEPT\n";
	char IP[18];
	char protocol[30];
	char result[BUFSIZ];	
	
	printf("IP를 입력하세요:  "); 
	scanf("%s",IP);
	printf("프로토콜을 입력하세요(없을시 \"-\" 입력) : ");
	scanf("%s",protocol);

	strcat(result, drop_1);
	strcat(result, IP);

	if(strcmp(protocol,"-")){
		strcat(result, drop_2);
		strcat(result, protocol);
	}
	if(in==1){
		strcat(result, drop_3);
		}
	else if(in==2){
		strcat(result, drop_4);
	}

	fp=fopen("myRules","a");
	fprintf(fp,"%s\n",result);
	fclose(fp);

	//system(result);


}
void creat_INPUT_menu(){
	int in;
	
	system("clear");

	printf("	====================================\n");
	printf("	\n");		
	printf("	        서버로 들어오는 기본 정책\n");
	printf("	\n");		
	printf("	--1. DROP\n");
	printf("	--2. ACCEPT\n");
	printf("	\n");	
	printf("	=====================================\n");

	scanf("%d",&in);

	switch(in){

		case 1:	
			creat_INPUT_DROP();
			
			break;
		case 2:
			creat_INPUT_ACCEPT();
			break;

		default:
			system("clear");
			printf("잘못된 입력입니다.\n");
			menu();
	}


}
void creat_INPUT_DROP(){
	char drop_1[]="iptables -A INPUT -s ";
	char drop_2[]=" -p ";
	char drop_3[]=" -j DROP";
	char IP[18];
	char protocol[30];
	char result[BUFSIZ];	
	
	result[0]='\0';
	IP[0]='\0';
	protocol[0]='\0';
	printf("IP를 입력하세요:  "); 
	scanf("%s",IP);
	printf("프로토콜을 입력하세요: ");
	scanf("%s",protocol);

	strcat(result, drop_1);
	strcat(result, IP);
	strcat(result, drop_2);
	strcat(result, protocol);
	strcat(result, drop_3);

	fp=fopen("myRules","a");
	fprintf(fp,"%s\n",result);
	fclose(fp);

	//system(result);

}

void creat_INPUT_ACCEPT(){

	char drop_1[]="iptables -A INPUT -s ";
	//char drop_2[]=" -p ";
	char drop_3[]=" -j ACCEPT";
	char IP[18];
	char protocol[30];
	char result[BUFSIZ];	
	char yorn;
	
	result[0]='\0';
	IP[0]='\0';
	protocol[0]='\0';

	printf("모든 패킷을 허용하겠습니까 ? : Y/N ");
	
	scanf("%s",&yorn);
	
	if(yorn=='Y'||yorn=='y'){

		fp=fopen("myRules","a");
		fprintf(fp,"iptables -A INPUT -j ACCEPT\n");
		fclose(fp);
		//system("iptables -A INPUT -j ACCEPT");
	}
	else if(yorn=='N'||yorn=='n'){
		printf("IP를 입력하세요:  "); 
		scanf("%s",IP);
		printf("프로토콜을 입력하세요: ");
		scanf("%s",protocol);

		strcat(result, drop_1);
		strcat(result, IP);

		strcat(result," -p ");

		strcat(result, protocol);
		strcat(result, drop_3);


		fp=fopen("myRules","a");
		fprintf(fp,"%s\n",result);
		fclose(fp);


	//	system(result);
	}
	else printf("잘못된 입력입니다.\n");
}







void creat_menu(){

	int n;
	system("clear");

	printf("	====================================\n");
	printf("	\n");		

	printf("	              규칙 생성\n");
	printf("	\n");		
	
	printf("	--1. 서버로 들어오는 기본 정책\n");
	printf("	--2. 서버에서 forwarding 기본 정책\n");
	printf("	--3. 서버에서 나가는 기본 정책\n");
	printf("	--4. 기타\n");
	printf("	\n");	
	printf("	=====================================\n");

	scanf("%d",&n);

	switch(n){

		case 1:	
			creat_INPUT_menu();
			
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			creat_other();
			break;

		default:
			system("clear");
			printf("잘못된 입력입니다.\n");
			menu();
	}
}
