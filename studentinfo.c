#include "studentinfo.h"

int selectMenu() {
	int menu;
	printf("\n*** CRUD 반 관리 시스템 ***\n");
   	printf("1. 학생정보 추가\n");
    	printf("2. 학생정보 읽기\n");
    	printf("3. 학생정보 수정\n");
    	printf("4. 학생정보 삭제\n");
    	printf("5. 학생정보 검색\n");
	printf("6. 파일 저장\n");
    	printf("0. 종료\n\n");
    	printf("=> 원하는 메뉴는? ");
    	scanf("%d", &menu);
    	return menu;

int addInfo(info *s){
	printf("\n 학생의 이름은? ");
	scanf("%s", s->name);
	
	printf("\n 학생의 학번은? ");
	scanf("%d", &s->studentID);

	printf("\n 학생의 전공은? ");
	scanf("%[^\n]s", s->major);
	
	printf("=> 추가됨!\n");
	return 1; 

}
void listIroduct(info *s,int count){

    printf("\nNo. Name    StudentID   Major\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if( s[i].studentID == -1) continue;
        printf("%2d.", i+1);
        readProduct(s[i]);
    }
    printf("\n");
}

int selectDataNo(info *s, int count){
    int no;
    listProduct(s,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

void readInfo (info s) {
if (s.studentID == -1){
printf ("학생 정보가 없음\n");
return;
}
printf("%s %3d %[^\n]\n", s.name, &s.studentID, s.major);
}

