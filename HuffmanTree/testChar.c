#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void tfun(char ** t)
{
    t[2]="4567";
}

char* addChar(char * origin,int tag)
{
    if(origin==NULL) origin = (char*)malloc(sizeof(char));
    if(tag==0)
        origin[strlen(origin)]='0';
    else
        origin[strlen(origin)] = '1';
    return origin;
}

int main()
{
    char *t = (char*)malloc(sizeof(char));
    t = "123";
    t = addChar(t,1);
    printf("%s",t);
    return 0;
}