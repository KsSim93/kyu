#include <stdlib.h>
#include <stdio.h>


FILE *fp ;
void INPUT_creat_other(){

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

void OUTPUT_creat_other(){

	int in;
	char IP[18];
	char PORT[18];
	char result[BUFSIZ];
	char interface[16];
	int leng = 0;
	char syn[]="iptables -A OUTPUT -syn -p TCP -d ! ";
	char ping_1[]="iptables -A OUTPUT -s ";
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
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ACK,FIN -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ALL NONE -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ALL PSH,FIN FIN -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ALL URG,PSH,FIN -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ALL SYN,ACK,FIN -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ALL SYN,FIN,PSH -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ALL SYN,FIN,RST -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ALL SYN,FIN,RST,PSH -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ALL SYN,FIN,ACK,RST -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ALL SYN,ACK,FIN,RST,PSH -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags FIN,RST FIN,RST -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags SYN,FIN SYN,FIN -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ACK,PSH PSH -j DROP\n");
			fprintf(fp,"iptables -A OUTPUT -p TCP --tcp-flags ACK,URG URG -j DROP\n");
			fclose(fp);


			
		default:
			system("clear");
			printf("잘못된 입력입니다.\n");
			menu();
	}


}

void FORWARD_creat_other(){

	int in;
	char IP[18];
	char PORT[18];
	char result[BUFSIZ];
	char interface[16];
	int leng = 0;
	char syn[]="iptables -A FORWARD -syn -p TCP -d ! ";
	char ping_1[]="iptables -A FORWARD -s ";
	char ping_2[]=" -p ICMP --icmp-type echo-request -j ACCEPT";

	char cre_6[]="iptables -A FORWARD ";
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
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ACK,FIN -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ALL NONE -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ALL PSH,FIN FIN -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ALL URG,PSH,FIN -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ALL SYN,ACK,FIN -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ALL SYN,FIN,PSH -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ALL SYN,FIN,RST -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ALL SYN,FIN,RST,PSH -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ALL SYN,FIN,ACK,RST -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ALL SYN,ACK,FIN,RST,PSH -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags FIN,RST FIN,RST -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags SYN,FIN SYN,FIN -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ACK,PSH PSH -j DROP\n");
			fprintf(fp,"iptables -A FORWARD -p TCP --tcp-flags ACK,URG URG -j DROP\n");
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
	int P;
	system("clear");

	printf("	====================================\n");
	printf("	\n");		
	printf("	서버로 들어오는 기본 정책(Chain INPUT)\n");
	printf("	\n");		
	printf("	--1. DROP\n");
	printf("	--2. ACCEPT\n");
	printf("	--3. 기본정책 변경\n");
	printf("	--4. 기타\n");
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
		case 3: 
			printf("1. 기본정책 허용(ACCEPT)");
			printf("2. 기본정책 거부(DROP)");
			scanf("%d",&P);
			if(P==1){
				fp=fopen("myRules","a");
				fprintf(fp,"iptables -P INPUT ACCEPT\n");
				fclose(fp);
			}
			else if(P==2){
				fp=fopen("myRules","a");
				fprintf(fp,"iptables -P INPUT DROP\n");
				fclose(fp);					
			}
			else{printf("잘못된 입력입니다. \n");}
			break;
		case 4:
			INPUT_creat_other();
			break;

		default:
			system("clear");
			printf("잘못된 입력입니다.\n");
			menu();
	}


}

void creat_FORWARD_menu(){
	int in;
	int P;
	system("clear");

	printf("	===========================================\n");
	printf("	\n");		
	printf("	서버에서 forwarding 기본 정책(Chain FORWARD)\n");
	printf("	\n");		
	printf("	--1. DROP\n");
	printf("	--2. ACCEPT\n");
	printf("	--3. 기본정책 변경\n");
	printf("	--4. 기타\n");
	printf("	\n");	
	printf("	===========================================\n");

	scanf("%d",&in);

	switch(in){

		case 1:	
			creat_FORWARD_DROP();
			
			break;
		case 2:
			creat_FORWARD_ACCEPT();
			break;
		case 3: 
			printf("1. 기본정책 허용(ACCEPT)");
			printf("2. 기본정책 거부(DROP)");
			scanf("%d",&P);
			if(P==1){
				fp=fopen("myRules","a");
				fprintf(fp,"iptables -P FORWARD ACCEPT\n");
				fclose(fp);
			}
			else if(P==2){
				fp=fopen("myRules","a");
				fprintf(fp,"iptables -P FORWARD DROP\n");
				fclose(fp);					
			}
			else{printf("잘못된 입력입니다. \n");}
			break;
		case 4:
			FORWARD_creat_other();
			break;

		default:
			system("clear");
			printf("잘못된 입력입니다.\n");
			menu();
	}


}


void creat_OUTPUT_menu(){
	int in;
	int P;
	system("clear");

	printf("	====================================\n");
	printf("	\n");		
	printf("	서버에서 나가는 기본 정책(Chain OUTPUT)\n");
	printf("	\n");		
	printf("	--1. DROP\n");
	printf("	--2. ACCEPT\n");
	printf("	--3. 기본정책 변경\n");
	printf("	--4. 기타\n");
	printf("	\n");	
	printf("	=====================================\n");

	scanf("%d",&in);

	switch(in){

		case 1:	
			creat_OUTPUT_DROP();
			
			break;
		case 2:
			creat_OUTPUT_ACCEPT();
			break;
		case 3: 
			printf("1. 기본정책 허용(ACCEPT)");
			printf("2. 기본정책 거부(DROP)");
			scanf("%d",&P);
			if(P==1){
				fp=fopen("myRules","a");
				fprintf(fp,"iptables -P OUTPUT ACCEPT\n");
				fclose(fp);
			}
			else if(P==2){
				fp=fopen("myRules","a");
				fprintf(fp,"iptables -P OUTPUT DROP\n");
				fclose(fp);					
			}
			else{printf("잘못된 입력입니다. \n");}
			break;
		case 4:
			OUTPUT_creat_other();
			break;

		default:
			system("clear");
			printf("잘못된 입력입니다.\n");
			menu();
	}


}


void creat_INPUT_DROP(){
	char drop_1[]="iptables -A INPUT -s ";
	//char drop_2[]=" -p ";
	//char drop_3[]=" -j DROP";
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
	strcat(result, " -p ");
	strcat(result, protocol);
	strcat(result, " -j DROP");

	fp=fopen("myRules","a");
	fprintf(fp,"%s\n",result);
	fclose(fp);

	//system(result);

}

void creat_OUTPUT_DROP(){
	
	char drop_1[]="iptables -A OUTPUT -s ";
	//char drop_2[]=" -p ";
	//char drop_3[]=" -j DROP";
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
	strcat(result, " -p ");
	strcat(result, protocol);
	strcat(result, " -j DROP");


	fp=fopen("myRules","a");
	fprintf(fp,"%s\n",result);
	fclose(fp);


}

void creat_FORWARD_DROP(){
	
	char drop_1[]="iptables -A FORWARD -s ";
	//char drop_2[]=" -p ";
	//char drop_3[]=" -j DROP";
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
	strcat(result, " -p ");
	strcat(result, protocol);
	strcat(result, " -j DROP");


	fp=fopen("myRules","a");
	fprintf(fp,"%s\n",result);
	fclose(fp);


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

void creat_OUTPUT_ACCEPT(){

	char drop_1[]="iptables -A OUTPUT -s ";
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
		fprintf(fp,"iptables -A OUTPUT -j ACCEPT\n");
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

void creat_FORWARD_ACCEPT(){

	char drop_1[]="iptables -A FORWARD -s ";
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
		fprintf(fp,"iptables -A FORWARD -j ACCEPT\n");
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



void Port_control(){
	int n;
	char yorn;
	int td;
	int Po_1;
	int Po_2;
	char IP[14];

	IP[0]='\0';

	system("clear");

	printf("	===========================================\n");
	printf("	\n");		

	printf("	        	포트  제어\n");
	printf("	\n");		
	
	printf("	--1. 포트 막기\n");
	printf("	--2. 포트 열기\n");

	printf("	\n");	
	printf("	===========================================\n");

	scanf("%d",&n);

	switch(n){

		case 1:	
			printf("모든 포트를 막으시겠습니까? Y/N ");
			scanf("%s",&yorn);
			if(yorn=='Y'||yorn=='y'){
				printf("1. TCP 포트\n2.UDP 포트\n3.TCP/UDP 포트");
				scanf("%d",&td);
				if(td==1){
					fp=fopen("myRules","a");
					fprintf(fp,"iptables -A INPUT -p tcp --dport 1:65526 -j DROP\n");
					fclose(fp);
				}else if(td==2){
					fp=fopen("myRules","a");
					fprintf(fp,"iptables -A INPUT -p udp --dport 1:65526 -j DROP\n");
					fclose(fp);
				}else if(td==3){
					fp=fopen("myRules","a");
					fprintf(fp,"iptables -A INPUT -p tcp --dport 1:65526 -j DROP\n");
					fprintf(fp,"iptables -A INPUT -p udp --dport 1:65526 -j DROP\n");
					fclose(fp);
				}else printf("잘못된 입력입니다. \n");

			}
			else if(yorn=='N'||yorn=='n'){
				fp=fopen("myRules","a");				
				printf("차단하고자하는 포트 범위는 :");
				scanf("%d",&Po_1);				
				printf("부터");
				scanf("%d",&Po_2);
				printf("까지\n");
				fprintf(fp,"iptables -A INPUT -p tcp --dport %d:%d -j DROP\n",Po_1,Po_2);
				fclose(fp);
			}
			
			break;
		case 2:
			printf("1.모든 포트 열기\n");
			printf("2.특정 포트만 열기\n");
			printf("3.범위지정 포트 열기 \n");
			printf("4.특정 아이피에게 특정 포트만 열어주기\n");

			scanf("%d",&td);
			if(td==1){
					printf("1. TCP 포트\n2.UDP 포트\n3.TCP/UDP 포트");
					scanf("%d",&td);
					if(td==1){
						fp=fopen("myRules","a");
						fprintf(fp,"iptables -A INPUT -p tcp --dport 1:65526 -j ACCEPT\n");
						fclose(fp);
					}else if(td==2){
						fp=fopen("myRules","a");
						fprintf(fp,"iptables -A INPUT -p udp --dport 1:65526 -j ACCEPT\n");
						fclose(fp);
					}else if(td==3){
						fp=fopen("myRules","a");
						fprintf(fp,"iptables -A INPUT -p tcp --dport 1:65526 -j ACCEPT\n");
						fprintf(fp,"iptables -A INPUT -p udp --dport 1:65526 -j ACCEPT\n");
						fclose(fp);
					}else printf("잘못된 입력입니다. \n");

				}else if(td==2){
					printf("1. TCP 포트\n2.UDP 포트\n3.TCP/UDP 포트");
					scanf("%d",&td);
						if(td==1){
							printf("어느 포트를 여시겠습니까? : ");
							scanf("%d",&Po_1);
							fp=fopen("myRules","a");
							fprintf(fp,"iptables -I INPUT -p tcp --dport %d -j ACCEPT\n",Po_1);
							fclose(fp);	
						}else if(td==2){
							printf("어느 포트를 여시겠습니까? : ");
							scanf("%d",&Po_1);
							fp=fopen("myRules","a");
							fprintf(fp,"iptables -I INPUT -p udp --dport %d -j ACCEPT\n",Po_1);
							fclose(fp);
						}else if(td==3){
							printf("어느 포트를 여시겠습니까? : ");
							scanf("%d",&Po_1);
							fp=fopen("myRules","a");
							fprintf(fp,"iptables -I INPUT -p tcp --dport %d -j ACCEPT\n",Po_1);
							fprintf(fp,"iptables -I INPUT -p udp --dport %d -j ACCEPT\n",Po_1);
							fclose(fp);
						}else printf("잘못된 입력입니다. \n");					
					
				}else if(td==3){
					printf("1. TCP 포트\n2.UDP 포트\n3.TCP/UDP 포트");
					scanf("%d",&td);
						if(td==1){
							printf("열고자하는 포트 범위는 :");
							scanf("%d",&Po_1);				
							printf("부터");
							scanf("%d",&Po_2);
							printf("까지\n");
							fprintf(fp,"iptables -I INPUT -p tcp --dport %d:%d -j ACCEPT\n",Po_1,Po_2);
							fclose(fp);	
						}else if(td==2){
							printf("열고자하는 포트 범위는 :");
							scanf("%d",&Po_1);				
							printf("부터");
							scanf("%d",&Po_2);
							printf("까지\n");
							fprintf(fp,"iptables -I INPUT -p udp --dport %d:%d -j ACCEPT\n",Po_1,Po_2);
							fclose(fp);
						}else if(td==3){
							printf("열고자하는 포트 범위는 :");
							scanf("%d",&Po_1);				
							printf("부터");
							scanf("%d",&Po_2);
							printf("까지\n");
							fprintf(fp,"iptables -I INPUT -p tcp --dport %d:%d -j ACCEPT\n",Po_1,Po_2);
							fprintf(fp,"iptables -I INPUT -p udp --dport %d:%d -j ACCEPT\n",Po_1,Po_2);
							fclose(fp);
						}else printf("잘못된 입력입니다. \n");			
					/*fp=fopen("myRules","a");				
					printf("열고자하는 포트 범위는 :");
					scanf("%d",&Po_1);				
					printf("부터");
					scanf("%d",&Po_2);
					printf("까지\n");
					fprintf(fp,"iptables -I INPUT -p tcp --dport %d:%d -j ACCEPT\n",Po_1,Po_2);
					fclose(fp);*/
				}else if(td==4){
					printf("IP를 입력하세요 : ");
					scanf("%s",IP);
					/*fp=fopen("myRules","a");				
					printf("열고자하는 포트 범위는 :");
					scanf("%d",&Po_1);				
					printf("부터");
					scanf("%d",&Po_2);
					printf("까지\n");
					fprintf(fp,"iptables -I INPUT -p tcp --dport %d:%d -j ACCEPT\n",Po_1,Po_2);
					fclose(fp);*/
					printf("1. TCP 포트\n2.UDP 포트\n3.TCP/UDP 포트");
					scanf("%d",&td);
						if(td==1){
							printf("어느 포트를 여시겠습니까? : ");
							scanf("%d",&Po_1);
							fp=fopen("myRules","a");
							fprintf(fp,"iptables -I INPUT -p tcp --dport %d -s %s-j ACCEPT\n",Po_1,IP);
							fprintf(fp,"iptables -I OUTPUT -p tcp --dport %d -d %s-j ACCEPT\n",Po_1,IP);
							fclose(fp);	
						}else if(td==2){
							printf("어느 포트를 여시겠습니까? : ");
							scanf("%d",&Po_1);
							fp=fopen("myRules","a");
							fprintf(fp,"iptables -I INPUT -p udp --dport %d -s %s-j ACCEPT\n",Po_1,IP);
							fprintf(fp,"iptables -I OUTPUT -p udp --dport %d -d %s-j ACCEPT\n",Po_1,IP);
							fclose(fp);
						}else if(td==3){
							printf("어느 포트를 여시겠습니까? : ");
							scanf("%d",&Po_1);
							fp=fopen("myRules","a");
							fprintf(fp,"iptables -I INPUT -p tcp --dport %d -s %s-j ACCEPT\n",Po_1,IP);
							fprintf(fp,"iptables -I OUTPUT -p tcp --dport %d -d %s-j ACCEPT\n",Po_1,IP);
							fprintf(fp,"iptables -I INPUT -p udp --dport %d -s %s-j ACCEPT\n",Po_1,IP);
							fprintf(fp,"iptables -I OUTPUT -p udp --dport %d -d %s-j ACCEPT\n",Po_1,IP);
							fclose(fp);
						}else printf("잘못된 입력입니다. \n");
				}else printf("잘못된 입력입니다. \n");
			break;
		
		
		default:
			system("clear");
			printf("잘못된 입력입니다.\n");
			menu();
	}
	

}


void creat_menu(){

	int n;
	system("clear");

	printf("	==================================================\n");
	printf("	\n");		

	printf("	         	     규칙 생성\n");
	printf("	\n");		
	
	printf("	--1. 서버로 들어오는 기본 정책(Chain INPUT)\n");
	printf("	--2. 서버에서 forwarding 기본 정책(Chain FORWARD)\n");
	printf("	--3. 서버에서 나가는 기본 정책(Chain OUTPUT)\n");
	printf("	--4. 포트 제어\n");


	printf("	\n");	
	printf("	===================================================\n");

	scanf("%d",&n);

	switch(n){

		case 1:	
			creat_INPUT_menu();
			
			break;
		case 2:
			creat_FORWARD_menu();
			break;
		case 3:
			creat_OUTPUT_menu();
			break;
		case 4: 
			Port_control();
			break;
		
		default:
			system("clear");
			printf("잘못된 입력입니다.\n");
			menu();
	}
}
