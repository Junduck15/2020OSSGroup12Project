#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];;
    int num;
    char major[20];
} info;

int curcount, count, menu;

int selectmenu();
void readinfo(info s);
int addinfo(info *s);
int updateinfo(info *s);
int deleteinfo(info *s);
void listsinfo(info *s, int count);
int selectdatano(info *s, int count);
void savedata(info *s, int count);
int loaddata(info s[]);
void searchByName(info *s, int count);
void searchByNum(info *s, int count);
void searchByMajor(info *s, int count);
