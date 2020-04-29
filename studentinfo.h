#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];
    int studentId;
    char major[20];
} info;

int curcount, count, menu;

int selectMenu();
void readInfo(info s);
int addInfo(info *s);
int updateInfo(info *s);
int deleteInfo(info *s);
void listsInfo(info *s, int count);
int selectDataNo(info *s, int count);
void saveData(info *s, int count);
int loadDta(info s[]);
void searchByName(info *s, int count);
void searchByNum(info *s, int count);
void searchByMajor(info *s, int count);
