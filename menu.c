#include "menu.h"
#include <string.h>
int ask_menu(int is_login){
// 파라미터 : 로그인여부 (0 No, 1Yes)
// 리턴값 : 선택한 메뉴번호
// 메뉴번호 : 1. Sign up 2. Log in 3. Log out 0. Exit
 #ifdef DEBUG_MODE
	printf("DEBUG : ask_menu()\n");
 #endif
  int menu;
  char command[16];
  printf(">");
  scanf("%s", command);
  if((strcmp(command, "join")==0))
    menu = 1;
  else if((strcmp(command, "login")==0)) 
    menu = 2;
  else if((strcmp(command, "logout")==0) && is_login==1)
    menu = 3;
  else if(strcmp(command, "list")==0)
    menu = 4;
  else if(strcmp(command, "exit") == 0)
    menu =5;
  else
    menu =6;
 // if(is_login==0)
   // printf("Choose menu : 1. Sign up 2. Log in 0. Exit >> ");
 // else
   // printf("Choose menu : 3. Log out 0. Exit >> ");
 // scanf("%d", &menu);
  return menu;
}
