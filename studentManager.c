#include "studentinfo.h"

info slist[100];
    
    
int main(void){

    
    count = loadData(slist);
    curcount = count;

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        
        if (menu == 1){
            count += addInfo(&slist[curcount++]);
        }
        else if (menu == 2){
            if (count > 0){
                listInfo(slist,curcount);
            }
            else{ printf("데이터가 없습니다\n");
            }
        }
        else if (menu == 3){
            int no = selectDataNo(slist, curcount);
            if(no ==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateInfo(&slist[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(slist, curcount);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            getchar();
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteInfo(&slist[no-1])){
                count --;}
            }
        }
        else if (menu ==5){
            if(count ==0){
                printf("데이터가 없습니다\n");
            }
            else{
                saveData(slist, curcount);
            }
        }
        else if (menu == 6){
            searchByName(slist, curcount);
        }
        else if (menu == 7){
            searchByNum(slist, curcount);
        }
        else if (menu == 8){
            searchByMajor(slist, curcount);
        }
    }
    printf("종료됨!\n");
    return 0;
}

