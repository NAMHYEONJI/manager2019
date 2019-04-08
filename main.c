#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  int menu_id;
  char echo[32];
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  int count = load_file(userlist, argv[1]);
  if(count ==-1) return 0;
  while(1){
  //  if(is_login==0) is_login = login(userlist, count);
    menu_id = ask_menu(is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
    if(menu_id==1) join(userlist, &count);
    else if(menu_id==2){
      is_login = login(userlist, count);
      if(is_login == 1){ 
        while(1){
          printf("# "); 
          fgets(echo, 99, stdin);
          
          if(strncmp(echo, "logout\0", 6) == 0){
            logout(&is_login); 
            break; 
          }
          //printf("# ");
          //fgets(echo, 100, stdin);
          printf("%s", echo);
        }
      }
    }
    else if(menu_id==3) logout(&is_login);
    else if(menu_id==4) {
      printf("User list (id/password)\n");
      if(count > 0){  
	for(int i = 0 ; i < count ; i++){
          printf("[%d] %s / %s\n",i+1,userlist[i]->id,userlist[i]->password);
        }
      }
    }
    else if(menu_id==5){ 
      save_file(userlist,count,argv[1]);  
      break;
    }
    else if(menu_id==6) printf("No such command!\n");
    else break;
    
  }
    return 0;
}
