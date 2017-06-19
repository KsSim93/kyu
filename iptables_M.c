#include <stdlib.h>
#include <stdio.h>
#include "rules.h"
#include "creat.h"
#include "del.h"
#include "apply.h"
#include "Automatic.h"

void menu(){


	printf("	====================================\n");
	printf("	              방 화 벽\n");
	printf("	\n");
	printf("	--1. 규칙 생성\n");
	printf("	--2. 규칙 확인\n");
	printf("	--3. 규칙 적용\n");
	printf("	--4. 규칙 삭제\n");
	printf("	--5. 종료 \n");
	printf("	\n");
	printf("	=====================================\n");


}

void menu_1(){


}

int main(){
	int n; // 메뉴 입력 
	
	//Auto_apply();
	system("clear");
	while(1){
			
		menu();
		scanf("%d",&n);
	
		switch(n){

			case 1:
				creat_menu();
				system("clear");
				break;
			case 2:
				show_rules();
				break;
			case 3:
				apply_rules();
				system("clear");
				break;
			case 4:
				del_menu();
				system("clear");
				break;
			case 5: 
				return 0;

			default:
				system("clear");
				printf("잘못된 입력입니다.\n");
				break;
			
		}


	}
	
}
