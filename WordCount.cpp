#include <stdio.h>
#include <stdlib.h>

int main()
{
 int charcount(char *filename);
 int wordcount(char *filename);
 FILE *fp;
 int c_count,w_count;
 char ch[3],filename[100];
 printf("�����û�����.exe ");
 scanf("%s %s",ch,filename);
 if((fp=fopen(filename,"r"))==NULL)
 {
     printf("filenull.\n");
     exit(-1);
 }
 //��ȡ��������
 if(ch[1]=='c')
 {
    c_count=charcount(filename);
    printf("�ַ���=%d\n",c_count);
 }
 if(ch[1]=='w')
 {
    w_count=wordcount(filename);
    printf("������=%d\n",w_count);
 }
    return 0;
}
int charcount(char *filename)//ͳ���ַ���
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
int wordcount(char *filename)//ͳ�Ƶ�����
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


