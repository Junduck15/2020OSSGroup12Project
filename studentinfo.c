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
