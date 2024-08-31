
#include <stdio.h>
#include <string.h>
#include "main.h"
#include <conio.h>
#include<stdlib.h>

student students[20000];
Teacher Teachers[20000];
Admin Admins[20000] = {{"admin", "admin"}};
int NumberOfStudents = 0;
int NumberOfTeachers = 0;

void AddTeacher(void) {
    printf("Enter Username Of The Teacher: ");
    scanf(" %[^\n]%*c", Teachers[NumberOfTeachers].Teacher_Name);

    printf("Enter Password Of The Teacher: ");
    fflush(stdin);
    scanf("%s", Teachers[NumberOfTeachers].Teacher_Pass);
    NumberOfTeachers++;
    system("cls");
    printf("===================\nTeacher %s has been added successfully\n===================\n", Teachers[NumberOfTeachers - 1].Teacher_Name);
}

void RemoveTeacher(void) {
    char x[100];
    printf("\nEnter the Teacher Name to remove: ");
    fflush(stdin);
    scanf(" %[^\n]%*c", x);

    int idx = -1;
    for (int j = 0; j < NumberOfTeachers; j++) {
        if (strcmp(x, Teachers[j].Teacher_Name) == 0) {
            idx = j;
            break;
        }
    }

    if (idx >= 0) {
        system("cls");
        printf("===================\nTeacher %s has been removed successfully\n===================\n", Teachers[idx].Teacher_Name);
        for (int j = idx; j < NumberOfTeachers - 1; j++) {
            Teachers[j] = Teachers[j + 1];
        }
        NumberOfTeachers--;
    } else {
        printf("There is no teacher with this name\n");
    }
}

int search(student a[20000], int x) {
    for (int o = 0; o < NumberOfStudents; o++) {
        if (x == a[o].id) {
            return 1;
        }
    }
    return 0;
}

void EditStudentDegree(void) {
    printf("\nEnter the student ID: ");
    int x = 0;
    scanf("%i", &x);
    int idx = -1;
    for (int j = 0; j < NumberOfStudents; j++) {
        if (x == students[j].id) {
            idx = j;
            break;
        }
    }
    if (idx >= 0) {
        printf("==================\nStudent: %s\nID: %d\nDegree: %lf\n=====================\n", students[idx].Student_Name, students[idx].id,
               students[idx].degree);
        printf("New degree: ");
        scanf("%lf", &students[idx].degree);
        system("cls");
        printf("===================\nChanges have been successfully applied\n===================\n");
    } else {
        printf("There is no student with this ID\n");
    }
}

void student_Search(void) {
    printf("\nEnter the student ID: ");
    int x = 0;
    scanf("%i", &x);
    int idx = -1;
    for (int j = 0; j < NumberOfStudents; j++) {
        if (x == students[j].id) {
            idx = j;
            break;
        }
    }
    if (idx >= 0) {
        system("cls");
        printf("======================================\n");
        printf("Student: %s\nID: %d\nDegree: %lf\n======================================\n", students[idx].Student_Name, students[idx].id, students[idx].degree);
    } else {
        printf("===================\nThere is no student with this ID\n===================\n");
    }
}

void Dispaly(void) {
    printf("\nEnter the student ID: ");
    int x = 0;
    scanf("%i", &x);
    int idx = -1;
    for (int j = 0; j < NumberOfStudents; j++) {
        if (x == students[j].id) {
            idx = j;
            break;
        }
    }
    if (idx >= 0) {
        printf("======================================\n");
        printf("Student: %s\nID: %d\nDegree: %lf\n======================================\n", students[idx].Student_Name, students[idx].id, students[idx].degree);
    } else {
        printf("===================\nThere is no student with this ID\n===================\n");
    }
}

void DisplyAll(void) {
    if (NumberOfStudents == 0) {
        printf("No students to display.\n");
    } else {
        system("cls");
        printf("===========================================================================\n");
        printf("| %-20s | %-10s | %-10s |\n", "Name", "ID", "Grade");
        printf("===========================================================================\n");
        for (int j = 0; j < NumberOfStudents; j++) {
            printf("| %-20s | %-10d | %-10.2lf |\n", students[j].Student_Name, students[j].id, students[j].degree);
        }
        printf("===========================================================================\n");
    }
}

void Error(void) {
    printf("\nInvalid input\n");
}

void WrongPass(void) {
    printf("\nWrong password or username\n");
}

void AddStudent(void) {
    printf("Enter student name: ");
    scanf(" %[^\n]%*c", students[NumberOfStudents].Student_Name);
    int p;
    printf("Enter student ID: ");
    scanf("%d", &p);
    while (search(students, p)) {
        printf("\nThis ID has been taken before\n");
        printf("Enter student ID: ");
        scanf("%d", &p);
    }
    students[NumberOfStudents].id = p;
    printf("Enter student degree: ");
    scanf("%lf", &students[NumberOfStudents].degree);
    system("cls");
    printf("===================\nStudent has been added\n===================\n");
    NumberOfStudents++;
}

void Remove(void) {
    printf("\nEnter the student ID to remove: ");
    int x = 0;
    scanf("%i", &x);
    int idx = -1;
    for (int j = 0; j < NumberOfStudents; j++) {
        if (x == students[j].id) {
            idx = j;
            break;
        }
    }

    if (idx >= 0) {
        system("cls");
        printf("===================\nStudent %s has been removed successfully\n===================\n", students[idx].Student_Name);
        for (int j = idx; j < NumberOfStudents - 1; j++) {
            students[j] = students[j + 1];
        }
        NumberOfStudents--;
    } else {
        printf("There is no student with this ID\n");
    }
}

void EditStudentInfo(void) {
    printf("\nEnter the student ID: ");
    int x = 0;
    scanf("%i", &x);
    int idx = -1;
    for (int j = 0; j < NumberOfStudents; j++) {
        if (x == students[j].id) {
            idx = j;
            break;
        }
    }
    if (idx >= 0) {
        printf("Student: %s\nID: %d\nDegree: %lf", students[idx].Student_Name, students[idx].id, students[idx].degree);
        printf("\nNew username: ");
        scanf(" %[^\n]%*c", students[idx].Student_Name);
        printf("New ID: ");
        scanf("%d", &students[idx].id);
        printf("New degree: ");
        scanf("%lf", &students[idx].degree);
        printf("===================\nChanges have been successfully applied\n===================\n");
    } else {
        printf("There is no student with this ID\n");
    }
}

int checkPassAdmin(void) {
    char user[100];
    char pass[100];
    printf("username: ");
    scanf("%s", user);
    printf("password: ");
    scanf("%s", pass);

    for (int i = 0; i < 2000; i++) {
        if (strcmp(Admins[i].Admin_Name, user) == 0 && strcmp(Admins[i].Admin_Pass, pass) == 0) {
            return 1; // Credentials match
        }
    }
    return 0; // No match found
}

int checkPassTeacher(void) {
    char user[100];
    char pass[100];

    printf("username: ");
    scanf(" %[^\n]%*c", user);
    printf("password: ");
    scanf("%s", pass);

    for (int i = 0; i < NumberOfTeachers; i++) {
        if (strcmp(Teachers[i].Teacher_Name, user) == 0 && strcmp(Teachers[i].Teacher_Pass, pass) == 0) {
            return 1; // Credentials match
        }
    }

    return 0; // No match found
}

int main(void) {
    while (1) {
        printf("\n1- Admin   [A]\n2- teacher [T]\n3- Student [S]\n==========\nEnter your role: ");
        char a;
        scanf(" %c", &a);

        if (a == 'S') {
            student_Search();

        }
        else if (a == 'T') {

               if (checkPassTeacher()) {
                   system("cls");
                   while(1) {
                       printf("\n1- Edit Grade [E]\n2- Display [D]\n3- Display All [X]\n4- Exit [Q]\nEnter the process: ");
                   char h;
                   getchar(); // Remove newline character from input buffer
                   scanf("%c", &h);

                   if (h == 'E') {
                       EditStudentDegree();
                   } else if (h == 'D') {
                       Dispaly();
                   } else if (h == 'X') {
                       DisplyAll();
                   } else if (h == 'Q') {
                       printf("\n");
                       system("cls");
                       break;
                   } else {
                       Error();
                   }
               }
           }else {
                    WrongPass();
                }

        }
        else if (a == 'A') {

            if (checkPassAdmin()) {
                system("cls");
                while(1) {
                    printf("\n1- Edit [E]\n2- Remove [R]\n3- Add Student [A]\n4- Display [D]\n5- Display All [X]\n"
                           "6- Add Teacher [M]\n7- Remove Teacher [N]\n8- Exit [Q]\nEnter the process: ");
                    char h;
                    scanf(" %c", &h);

                    if (h == 'E') {
                        EditStudentInfo();
                    } else if (h == 'R') {
                        Remove();
                    } else if (h == 'A') {
                        AddStudent();
                    } else if (h == 'D') {
                        Dispaly();
                    } else if (h == 'X') {
                        DisplyAll();
                    } else if (h == 'M') {
                        AddTeacher();

                    } else if (h == 'N') {
                        RemoveTeacher();
                    }else if (h == 'Q') {
                        printf("\n");
                        system("cls");
                        break;
                    }
                    else {
                        Error();
                    }
                }
            }
            else {
                WrongPass();
            }
        }
        else {
            Error();
        }
    }
}
