#include "studentinfo.h"

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

