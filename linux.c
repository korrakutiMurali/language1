#include<stdio.h>
struct employee
{
    char id[4];
    char company[10];
};
typedef struct employee emp;
int main()
{
emp e1;
strcpy(e1.id,"1");   // without pointers and static allocation
strcpy(e1.company,"cds");
printf("[%s,",e1.id);
printf("%s]\n",e1.company);
emp *e2=(emp*)malloc(sizeof(emp));   //with pointers and 
strcpy(e2->id,"2");
strcpy(e2->company,"abc");
printf("[%s,",e2->id);
printf("%s]\n",e2->company);
emp *e3=(emp*)malloc(sizeof(emp)*2);  //increasing the memory size 
strcpy(e3->id,"3");
strcpy(e3->company,"xyz");
printf("[%s,",e3->id);
printf("%s]\n",e3->company);
return 0;
}
