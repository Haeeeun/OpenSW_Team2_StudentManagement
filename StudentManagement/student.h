#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#define ESC 27

#include <stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct student
{
	char id[10];
	char name[20];
	double examScore[2];
	double assignmentScore[5];
}STUDENT;

typedef struct course
{
	char name[40];
	STUDENT student[100];
	char notice[10][50];
	char assignment[5][50];
	int studentNumber;
}COURSE;

//������������
void readDate(STUDENT *student,int *studentNumber,int *subjectNumber);
void returnUserFace();
void sumAndAveSubjectSore(STUDENT *student,int *studenNumber,int *subjectNumber);
void sumAndAveStudentSore(STUDENT *student,int *studenNumber,int *subjectNumber);
int orderBig(const void *a,const void *b);
int orderSmall(const void *a,const void *b);
void Print(STUDENT *student,int *studenNumber,int *subjectNumber);
int CompareID(const void *elem1, const void *elem2);
int orderName(const void *a,const void *b);
void nameSearch(STUDENT *student,int *studentNumber,int *subjectNumber);
int SearchID(COURSE* course);
void SortScore(STUDENT *student,int *studentNumber,int *subjectNumber);
void Print2(STUDENT *student,int *studentNumber,int *subjectNumber);
void sumAndAveStudentSore2(STUDENT *student,int *studenNumber,int *subjectNumber);
void SystemSet();
int ScanfSet();
void WriteFile(STUDENT *student,int *studentNumber,int *subjectNumber);
void ReadFile(STUDENT *student,int *studentNumber,int *subjectNumber);
void SystemSet();
void PrintCourseMenu();
void PrintManagementMenu();
void PrintScoreMenu();
void PrintAssignmentMenu();
void PrintStudentMenu();
void PrintNoticeMenu();
void initAssignment(COURSE *course);
void initNotice(COURSE *course);
void PrintCourseList(COURSE **course, int *subjectNumber);
void CourseMenu(COURSE **course, int *subjectNumber);
void RegisterCourse(COURSE **course, int *subjectNumber);
void ModifyCourse(COURSE **course, int *subjectNumber);
void DeleteCourse(COURSE **course, int *subjectNumber);
void SelectCourse(COURSE **course, int *subjectNumber);
void ManagementMenu(COURSE *course);
void ScoreMenu(COURSE *course);
void RegisterScore(COURSE *course);
void ModifyScore(COURSE *course);
void DeleteScore(COURSE *course);
void PrintScore(COURSE *course, int printType, int studentIndex);
void AverageCourseScore(COURSE *course);
void AssignmentMenu(COURSE *course);
void WriteScoreFile();
void RegisterAssignment();
void ModifyAssignment();
void DeleteAssignment();
void PrintAssignment();
void StudentMenu(COURSE *course);
void RegisterStudent(COURSE *course);
void ModifyStudent(COURSE *course);
void DeleteStudent(COURSE *course);
void PrintStudent(COURSE *course);
void ReadStudentFile();
void WriteStudentFile();
void NoticeMenu(COURSE *course);
void RegisterNotice();
void ModifyNotice();
void DeleteNotice();
void PrintNotice();

#endif // STUDENT_H_INCLUDED
