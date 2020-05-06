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
}

int addInfo(info *s){
	printf("\n 학생의 이름은? ");
	scanf("%s", s->name);
	getchar();
	
	printf("\n 학생의 학번은? ");
	scanf("%d", &s->studentID);

	printf("\n 학생의 전공은? ");
	scanf("\n%[^\n]s", s->major);
	
	printf("=> 추가됨!\n");
	return 1; 

}
void listInfo(info *s,int count){

    printf("\nNo. Name    StudentID   Major\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if( s[i].studentID == -1) continue;
        printf("%2d.", i+1);
        readInfo(s[i]);
    }
    printf("\n");
}

int selectDataNo(info *s, int count){
    int no;
    listInfo(s,count);
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
printf("%s %3d %s\n", s.name, s.studentID, s.major);
}

int updateInfo(info *s){
    printf("\n 학생의 이름은? ");
	scanf("%s", s->name);
	
	printf("\n 학생의 학번은? ");
	scanf("%d", &s->studentID);

	printf("\n 학생의 전공은? ");
	scanf("%[^\n]s", s->major);
    
    printf("=> 수정성공!\n");
    return 1;
}
	
int deleteInfo(info *s){
    s->studentID = -1;
    return 1;
}

void saveData(info *s, int count){
    FILE *fp;
    fp = fopen("studentinfo.txt", "wt");
    for(int i=0;i<count; i++){
        if(s[i].studentID == -1 ) continue;
        fprintf(fp, "%s %d %s\n", s[i].name, s[i].studentID, s[i].major);
    }
    fclose(fp);
    printf("저장됨!\n");
}

int loadData(info s[]){
    FILE *fp;
    fp = fopen("studentinfo.txt", "rt");
    if(fp ==NULL){
        printf("=> 파일 없음\n");
        return 0;
    }
    for(; ; count++){
        fscanf(fp,"%s %d %[^\n]s", s[count].name, &s[count].studentID, s[count].major);
        if(feof(fp)){ break;}
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return count;
}

void searchByName(info *s, int count){
    int scount =0;
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);

    printf("\nNo. Name    StudentID   Major\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if(s[i].studentID != -1){
            if(strstr(s[i].name, search)){
                printf("%2d ", i+1);
                readInfo(s[i]);
                scount++;
            }
        }
    }

    if(scount == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
	
void searchByNum(info *s, int count){
    int scount =0;
    int search;

    printf("검색할 학번? ");
    scanf("%d", &search);

    printf("\nNo. Name    StudentID   Major\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if(s[i].studentID != -1){
            if(s[i].studentID == search){
                printf("%2d ", i+1);
                readInfo(s[i]);
                scount++;
            }
        }
    }

    if(scount == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
	
void searchByMajor(info *s, int count){
    int scount =0;
    char search[20];

    printf("검색할 전공? ");
    getchar();
    scanf("%[^\n]s", search);

    printf("\nNo. Name    StudentID   Major\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if(s[i].studentID != -1){
            if(strstr(s[i].major, search)){
                printf("%2d ", i+1);
                readInfo(s[i]);
                scount++;
            }
        }
    }

    if(scount == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
	
