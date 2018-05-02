#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct student
{
    char number[15];
    char name[60];
    float score[10],sumScore,avescore;
} STU;

//������������
void userInterFace();
void readDate(STU *student,int *studentNumber,int *subjectNumber);
void returnUserFace();
void sumAndAveSubjectSore(STU *student,int *studenNumber,int *subjectNumber);
void sumAndAveStudentSore(STU *student,int *studenNumber,int *subjectNumber);
int orderBig(const void *a,const void *b);
int orderSmall(const void *a,const void *b);
void Print(STU *student,int *studenNumber,int *subjectNumber);
int orderNumber(const void *a,const void *b);
int orderName(const void *a,const void *b);
void nameSearch(STU *student,int *studentNumber,int *subjectNumber);
void numberSearch(STU *student,int *studentNumber,int *subjectNumber);
void SortScore(STU *student,int *studentNumber,int *subjectNumber);
void Print2(STU *student,int *studentNumber,int *subjectNumber);
void sumAndAveStudentSore2(STU *student,int *studenNumber,int *subjectNumber);
void SystemSet();
int ScanfSet();
void WriteFile(STU *student,int *studentNumber,int *subjectNumber);
void ReadFile(STU *student,int *studentNumber,int *subjectNumber);
void SystemSet();

//��������
//ϵͳ����
void SystemSet()
{
    system("title  ѧ������ϵͳ6.0 --by���1501����");//���ñ���
   // system("mode con cols=40 lines=35");//���ô��ڴ�С
    //system("color F0");
}
//��ȡѡ�
int ScanfSet()
{
    int n;
    scanf("%d",&n);
    return n;
}
//�û�����
void userInterFace()
{
    printf("1.Input record\n");
    printf("2.Caculate total and average score of course\n");
    printf("3.Caculate total and average score of student\n");
    printf("4.Sort in descending order by score of every student\n");
    printf("5.Sort in ascending order by score of every student\n");
    printf("6.Sort in ascending order by order\n");
    printf("7.Sort in dictionary order by name\n");
    printf("8.Search by number\n");
    printf("9.Search by name\n");
    printf("10.Statistic analysis for every course\n");
    printf("11.List record\n");
    printf("12.Write to a file\n");
    printf("13.Read from a file\n");
    printf("0.Exit\n");
    printf("please enter your choice:\n");
}
//��ȡ����
void readDate(STU *student,int *studentNumber,int *subjectNumber)
{
    int i,j;//���ƶ�ȡ��ѧ�����Ϳ�Ŀ��
    //FILE *p = freopen("test.txt","r",stdin);
    printf("������ѧ������Ŀ\n");
    scanf("%d",studentNumber);
    printf("�������Ŀ��\n");
    scanf("%d",subjectNumber);
    getchar();
    for(i=0; i<*studentNumber; i++)
    {
        printf("������ѧ�š����֡����� �м��Կո����\n");
        scanf("%s%s",student[i].number,student[i].name);
        for(j=0; j<*subjectNumber; j++)
        {
            scanf("%f",&student[i].score[j]);
        }
    }
    //fclose(p);
    returnUserFace();

}
//�����û�����
void returnUserFace()
{
    while(getchar()!='\n');
    system("pause");
    system("cls");
    userInterFace();
}
void sumAndAveSubjectSore(STU *student,int *studenNumber,int *subjectNumber)
{
    int i,j;
    float sum;
    for(i=0; i<*subjectNumber; i++)
    {
        sum=0;
        for(j=0; j<*studenNumber; j++)
        {
            sum+=student[j].score[i];
        }
        printf("ѧ��%d ���ܷ��� %-8.2f ",i+1,1.0*sum);
        printf("ƽ������ %-8.2f\n",1.0*sum/(*studenNumber));
    }
    returnUserFace();
}

void sumAndAveStudentSore(STU *student,int *studenNumber,int *subjectNumber)
{
    int i,j;
    float sum=0;
    for(i=0; i<*studenNumber; i++)
    {
        sum=0;
        for(j=0; j<*subjectNumber; j++)
        {
            sum+=student[i].score[j];
        }
        student[i].sumScore=sum;
        printf("%-12s%-10s ",student[i].number,student[i].name);
        printf("�ܷ��� %-8.2f ƽ������ %-8.2f\n",1.0*sum,1.0*sum/(*subjectNumber));
    }
    returnUserFace();

}
int orderBig(const void *a,const void *b)
{
    STU *p1=(STU*)a;
    STU *p2=(STU*)b;
    return (int)((p1->sumScore)-(p2->sumScore));
}
int orderSmall(const void *a,const void *b)
{
    STU *p1=(STU*)a;
    STU *p2=(STU*)b;
    return (int)((p2->sumScore)-(p1->sumScore));
}
int orderNumber(const void *a,const void *b)
{
    STU *p1=(STU*)a;
    STU *p2=(STU*)b;
    return (p2->number)-(p1->number);
}
int orderName(const void *a,const void *b)
{
    STU *p1=(STU*)a;
    STU *p2=(STU*)b;
    return strcmp((p1->name),(p2->name));
}
void Print(STU *student,int *studentNumber,int *subjectNumber)
{
    int i,j;//���ƶ�ȡ��ѧ�����Ϳ�Ŀ��
    for(i=0; i<*studentNumber; i++)
    {
        printf("%-12s%-10s ",student[i].number,student[i].name);
        for(j=0; j<*subjectNumber; j++)
        {
            printf("%-8.2f ",student[i].score[j]);
        }
        printf("\n");
    }
    returnUserFace();
}
//�����ֲ���
void nameSearch(STU *student,int *studentNumber,int *subjectNumber)
{
    int i=0,j,k=0;
    char c;
    char name[30];
E:
    printf("������ѧ��������\n"); //ѭ������
    //getchar();
    k=0;
    scanf("%s",name);
    for(i=0; i<*studentNumber; i++)
    {
        if(strcmp(name,student[i].name)==0)
        {
            printf("%-12s%-10s",student[i].number,student[i].name);
            for(j=0; j<*subjectNumber; j++)
                printf("%-8.2f",student[i].score[j]);
            k=1;
        }

    }
    if(k==1)
        putchar(10);
    else printf("û�ҵ�ѧ��\n");
    getchar();
E1:
    printf("��\"n\"������������\"y\"����\n");

    scanf("%c",&c);
    if(c=='y')
        goto E;
    else if(c=='n')
        returnUserFace();
    else
    {
        while(getchar()!='\n');
        goto E1;
    }


}
//��ѧ�Ų���
void numberSearch(STU *student,int *studentNumber,int *subjectNumber)
{
    int i=0,j,k=0;
    char c,number[10];
E:
    printf("������ѧ��\n");//ѭ������
    //getchar();
    k=0;
    scanf("%s",number);
    for(i=0; i<*studentNumber; i++)
    {
        if(strcmp(student[i].number,number)==0)
        {
            printf("%-12s%-10s ",student[i].number,student[i].name);
            for(j=0; j<*subjectNumber; j++)
                printf("%-8.2f",student[i].score[j]);
            k=1;
        }

    }
    if(k==1)
        putchar(10);
    else printf("û�ҵ�ѧ��\n");
    getchar();
E1:
    printf("��\"n\"������������\"y\"����\n");

    scanf("%c",&c);
    if(c=='y')
        goto E;
    else if(c=='n')
        returnUserFace();
    else
    {
        while(getchar()!='\n');
        goto E1;
    }

}
int Excellente=0,Fine=0,Medium=0,Pass=0,Fail=0;
//����ɼ�
void SortScore(STU *student,int *studentNumber,int *subjectNumber)
{
    Excellente=0,Fine=0,Medium=0,Pass=0,Fail=0;
    int i,j;
    for(i=0; i<*subjectNumber; ++i)
    {
        for(j=0; j<*studentNumber; ++j)
        {
            if(student[j].score[i]>=90) Excellente++;
            else if(student[j].score[i]>=80) Fine++;
            else if(student[j].score[i]>=70) Medium++;
            else if(student[j].score[i]>=60) Pass++;
            else Fail++;
        }
        printf("��Ŀ %d\n",i+1);
        printf("����(90-100) %2d %-5.2f%%\n",Excellente,1.0*Excellente/(*studentNumber)*100);
        printf("����(80-89)  %2d %-5.2f%%\n",Fine,1.0*Fine/(*studentNumber)*100);
        printf("�е�(70-79)  %2d %-5.2f%%\n",Medium,1.0*Medium/(*studentNumber)*100);
        printf("����(60-69)  %2d %-5.2f%%\n",Pass,1.0*Pass/(*studentNumber)*100);
        printf("������(0-59) %2d %-5.2f%%\n",Fail,1.0*Fail/(*studentNumber)*100);
        Excellente=0,Fine=0,Medium=0,Pass=0,Fail=0;
    }
    returnUserFace();
}
//��ӡû�ųɼ����ܷ�ƽ����
void Print2(STU *student,int *studentNumber,int *subjectNumber)
{
    int i,j;//���ƶ�ȡ��ѧ�����Ϳ�Ŀ��
    for(i=0; i<*studentNumber; i++)
    {
        printf("%-12s%-10s������ ",student[i].number,student[i].name);
        for(j=0; j<*subjectNumber; j++)
        {
            printf("%-8.2f",student[i].score[j]);
        }
        printf("�ܷ��� %-8.2fƽ������ %-8.2f",student[i].sumScore,student[i].sumScore/(*subjectNumber));
        printf("\n");
    }
    returnUserFace();
}
//���������ܷ�
void sumAndAveStudentSore2(STU *student,int *studentNumber,int *subjectNumber)
{
    int i,j;
    float sum=0;
    for(i=0; i<*studentNumber; i++)
    {
        sum=0;
        for(j=0; j<*subjectNumber; j++)
        {
            sum+=student[i].score[j];
        }
        student[i].sumScore=sum;

    }

}
//д�ļ�����
void WriteFile(STU *student,int *studentNumber,int *subjectNumber)
{
    FILE *p;
    int i,j;//���ƶ�ȡ��ѧ�����Ϳ�Ŀ��
    if((p=fopen("student.txt","w"))==NULL)
    {
        printf("���ļ�ʧ��\n");
        exit(0);
    }
    else
    {
        //fwrite(student,sizeof(STU),*studentNumber,p); //��ģ���
        fprintf(p,"%d %d\n",*studentNumber,*subjectNumber);
        for(i=0; i<*studentNumber; i++)
        {
            fprintf(p,"%-12s%-10s ",student[i].number,student[i].name);
            for(j=0; j<*subjectNumber; j++)
            {
                fprintf(p,"%-8.2f",student[i].score[j]);
            }
            fprintf(p," %-8.2f %-8.2f",student[i].sumScore,student[i].sumScore/(*subjectNumber));
            fprintf(p,"\n");
        }
    }
    fclose(p);
    printf("д��ɹ�\n");
    returnUserFace();
}
//��ȡ�ļ�1
void ReadFile(STU *student,int *studentNumber,int *subjectNumber)
{
    FILE *p;
    int i,j;//���ƶ�ȡ��ѧ�����Ϳ�Ŀ��
    if((p=fopen("student.txt","r"))==NULL)
    {
        printf("���ļ�ʧ��\n");
        exit(0);
    }
    else
    {
        //fread(student,sizeof(STU),*studentNumber,p);//��ģ����ȡ
        fscanf(p,"%d%d",studentNumber,subjectNumber);
        for(i=0; i<*studentNumber; i++)
        {
            fscanf(p,"%s%s",student[i].number,student[i].name);
            for(j=0; j<*subjectNumber; j++)
            {
                fscanf(p,"%f",&student[i].score[j]);
            }
            fscanf(p,"%f%f",&student[i].sumScore,&student[i].avescore);
            fscanf(p,"\n");
        }
    }
    fclose(p);



}


//��ȡ�ļ�2
//void ReadFile(STU *student,int *studentNumber,int *subjectNumber)
//{
//    int i,j;//���ƶ�ȡ��ѧ�����Ϳ�Ŀ��
//    scanf("%d%d",studentNumber,subjectNumber);
//        for(i=0; i<*studentNumber; i++)
//        {
//            scanf("%s%s",student[i].number,student[i].name);
//            for(j=0; j<*subjectNumber; j++)
//            {
//                scanf("%f",&student[i].score[j]);
//            }
//            scanf("%f%f",&student[i].sumScore,&student[i].avescore);
//        }
//}


#endif // STUDENT_H_INCLUDED
