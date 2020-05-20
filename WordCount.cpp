#include <stdio.h>
#include <stdlib.h>

int main()
{
 int charcount(char *filename);
 int wordcount(char *filename);
 FILE *fp;
 int c_count,w_count;
 char ch[3],filename[100];
 printf("输入用户命令.exe ");
 scanf("%s %s",ch,filename);
 if((fp=fopen(filename,"r"))==NULL)
 {
     printf("filenull.\n");
     exit(-1);
 }
 //获取命令和输出
 if(ch[1]=='c')
 {
    c_count=charcount(filename);
    printf("字符数=%d\n",c_count);
 }
 if(ch[1]=='w')
 {
    w_count=wordcount(filename);
    printf("单词数=%d\n",w_count);
 }
    return 0;
}
int charcount(char *filename)//统计字符数
{
    int n1=0;
    char ch;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL)
    {
        exit(-1);
    }
    ch=fgetc(fp);
    while(!feof(fp))
    {
        ch=fgetc(fp);
        n1++;
    }
    fclose(fp);
    return n1;
}
int wordcount(char *filename)//统计单词数
{
    int n2=0,word=0;
    char ch;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL)
    {
        exit(-1);
    }
    ch=fgetc(fp);
    while(!feof(fp))
    {
        ch=fgetc(fp);
        if(ch<'A'||(ch>'Z'&&ch<'a')||ch>'z')
            word=0;
        else if(word==0)
        {
            word=1;
            n2++;
        }
    }
    fclose(fp);
    return n2;
}


