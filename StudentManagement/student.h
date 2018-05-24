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
	int studentCount;
}COURSE;

int CompareID(const void *elem1, const void *elem2);
int SearchID(COURSE* course);
void SystemSet();
void WriteFile(COURSE *course);
void ReadFile(COURSE *course);
void SystemSet();
void PrintCourseMenu();
void PrintManagementMenu();
void PrintScoreMenu();
void PrintAssignmentMenu();
void PrintStudentMenu();
void PrintNoticeMenu();
void InitCourse(COURSE *course);
void PrintCourseList(COURSE **course, int *courseCount);
void CourseMenu(COURSE **course, int *courseCount);
void RegisterCourse(COURSE **course, int *courseCount);
void ModifyCourse(COURSE **course, int *courseCount);
void DeleteCourse(COURSE **course, int *courseCount);
void SelectCourse(COURSE **course, int *courseCount);
void ManagementMenu(COURSE *course);
void ScoreMenu(COURSE *course);
void RegisterScore(COURSE *course);
void ModifyScore(COURSE *course);
void DeleteScore(COURSE *course);
void PrintScore(COURSE *course, int printType, int studentIndex);
void AverageCourseScore(COURSE *course);
void AssignmentMenu(COURSE *course);
void RegisterAssignment(COURSE *course);
void ModifyAssignment(COURSE *course);
void DeleteAssignment(COURSE *course);
void PrintAssignment(COURSE *course);
void StudentMenu(COURSE *course);
void RegisterStudent(COURSE *course);
void ModifyStudent(COURSE *course);
void DeleteStudent(COURSE *course);
void PrintStudent(COURSE *course);
void NoticeMenu(COURSE *course);
void RegisterNotice(COURSE *course);
void ModifyNotice(COURSE *course);
void DeleteNotice(COURSE *course);
void PrintNotice(COURSE *course);
void PrintRegisterCourse();
void PrintModifyCourse();
void PrintModifyCourseName();
void PrintDeleteCourse();
void PrintSelectCourse();
void PrintRegisterScoreID();
void PrintRegisterMidtermScore();
void PrintRegisterFinalScore();
void PrintModifyScoreID();
void PrintModifyMidtermScore();
void PrintModifyFinalScore();
void PrintDeleteScoreID();
void PrintRegisterAssignment();
void PrintModifyAssignment();
void PrintModifyAssignmentComments();
void PrintDeleteAssignment();
void PrintRegisterStudent();
void PrintRegisterStudentName();
void PrintModifyStudentName();
void PrintDeleteStudent();
void PrintRegisterNotice();

#endif // STUDENT_H_INCLUDED
