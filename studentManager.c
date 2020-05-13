#include "studentinfo.h"
#define ADD 1
#define READ 2
#define UPDATE 3
#define DELETE 4
#define SEARCH 6
#define SAVE 5 
#define QUIT 0

info slist[100];
    
    
int main(void){

    
    count = loadData(slist);
    curcount = count;

    while (1){
        menu = selectMenu();
        if (menu == QUIT) break;
        
        if (menu == ADD){
            count += addInfo(&slist[curcount++]);
        }
        else if (menu == READ){
            if (count > 0){
                listInfo(slist,curcount);
            }
            else{ printf("데이터가 없습니다\n");
            }
        }
        else if (menu == UPDATE){
            int no = selectDataNo(slist, curcount);
            if(no ==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateInfo(&slist[no-1]);
        }
        else if (menu == DELETE){
            int no = selectDataNo(slist, curcount);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제:1) ");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteInfo(&slist[no-1])){
                count --;}
            }
        }
        
        else if (menu == SEARCH){
		int searchType = 0;
		printf("\n1. 학생이름으로 검색 \n");
		printf("\n2. 학생학번으로 검색 \n");
		printf("\n3. 학생전공으로 검색 \n");
		printf(".    번호를 고르시오(취소:0) ");
		scanf("%d", &searchType);
		if (searchType == 0) {
			printf("취소됨!\n");
			continue;
		}
		if (searchType == 1) {
			searchByName(slist, curcount);
		}
		if (searchType == 2) {
			searchByNum(slist, curcount);
		}
		if (searchType == 3) {
			searchByMajor(slist, curcount);
		}
		
        }
	else if (menu == SAVE){
            if(count ==0){
                printf("데이터가 없습니다\n");
            }
            else{
                saveData(slist, curcount);
            }
        }
    }
	
    printf("종료됨!\n");
    return 0;
}

