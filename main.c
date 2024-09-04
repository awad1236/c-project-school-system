#include <stdio.h>
#include <string.h>
#include "main.h"
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

student students[20000];
Teacher Teachers[20000];
Admin Admins[20000] = {{"admin", "admin"}};
int NumberOfStudents = 0;
int NumberOfTeachers = 0;

void printLoadingBar() {
    printf(CYAN);
    for(int i = 0; i < 20; i++) {
        printf("=");
        Sleep(100);
    }
    printf(RESET "\n");
}

void AddTeacher(void) {
    printf(YELLOW "Enter Username Of The Teacher: " RESET);
    scanf(" %[^\n]%*c", Teachers[NumberOfTeachers].Teacher_Name);

    printf(YELLOW "Enter Password Of The Teacher: " RESET);
    fflush(stdin);
    scanf("%s", Teachers[NumberOfTeachers].Teacher_Pass);
    NumberOfTeachers++;
    printLoadingBar();
    system("cls");
    printf(GREEN "===================\nTeacher %s has been added successfully :D \n===================\n" RESET, Teachers[NumberOfTeachers - 1].Teacher_Name);
}

void RemoveTeacher(void) {
    char x[100];
    printf(YELLOW "\nEnter the Teacher Name to remove: " RESET);
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
        printLoadingBar();
        system("cls");
        printf(GREEN "===================\nTeacher %s has been removed successfully\n===================\n" RESET, Teachers[idx].Teacher_Name);
        for (int j = idx; j < NumberOfTeachers - 1; j++) {
            Teachers[j] = Teachers[j + 1];
        }
        NumberOfTeachers--;
    } else {
        printf(RED "There is no teacher with this name\n" RESET);
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
    printf(YELLOW "\nEnter the student ID: " RESET);
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
        printf(GREEN "==================\nStudent: %s\nID: %d\nDegree: %lf\n=====================\n" RESET, students[idx].Student_Name, students[idx].id,
               students[idx].degree);
        printf(YELLOW "New degree: " RESET);
        scanf("%lf", &students[idx].degree);
        printLoadingBar();
        system("cls");
        printf(GREEN "===================\nChanges have been successfully applied\n===================\n" RESET);
    } else {
        printf(RED "There is no student with this ID\n" RESET);
    }
}

void student_Search(void) {
    printf(YELLOW "\nEnter the student ID: " RESET);
    int x = 0;
    scanf("%i", &x);
    int idx = -1;
    for (int j = 0; j < NumberOfStudents; j++) {
        printLoadingBar();
        if (x == students[j].id) {
            idx = j;
            break;
        }
    }
    if (idx >= 0) {
        system("cls");
        printf(GREEN "======================================\n" RESET);
        printf(GREEN "Student: %s\nID: %d\nDegree: %lf\n" RESET, students[idx].Student_Name, students[idx].id, students[idx].degree);
        printf(GREEN "======================================\n" RESET);
    } else {
        printf(RED "===================\nThere is no student with this ID\n===================\n" RESET);
    }
}

void Dispaly(void) {
    printf(YELLOW "\nEnter the student ID: " RESET);
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
        printf(GREEN "======================================\n" RESET);
        printf(GREEN "Student: %s\nID: %d\nDegree: %lf\n" RESET, students[idx].Student_Name, students[idx].id, students[idx].degree);
        printf(GREEN "======================================\n" RESET);
    } else {
        printf(RED "===================\nThere is no student with this ID\n===================\n" RESET);
    }
}

void DisplyAll(void) {
    if (NumberOfStudents == 0) {
        printf(RED "No students to display.\n" RESET);
    } else {
        system("cls");
        printf(CYAN "===========================================================================\n" RESET);
        printf(CYAN "| %-20s | %-10s | %-10s |\n" RESET, "Name", "ID", "Grade");
        printf(CYAN "===========================================================================\n" RESET);
        for (int j = 0; j < NumberOfStudents; j++) {
            printf(CYAN "| %-20s | %-10d | %-10.2lf |\n" RESET, students[j].Student_Name, students[j].id, students[j].degree);
        }
        printf(CYAN "===========================================================================\n" RESET);
    }
}

void Error(void) {
    printf(RED "\nInvalid input\n" RESET);
}

void WrongPass(void) {
    printf(RED "\nWrong password or username\n" RESET);
}

void AddStudent(void) {
    printf(YELLOW "Enter student name: " RESET);
    scanf(" %[^\n]%*c", students[NumberOfStudents].Student_Name);
    int p;
    printf(YELLOW "Enter student ID: " RESET);
    scanf("%d", &p);
    while (search(students, p)) {
        printf(RED "\nThis ID has been taken before\n" RESET);
        printf(YELLOW "Enter student ID: " RESET);
        scanf("%d", &p);
    }
    students[NumberOfStudents].id = p;
    printf(YELLOW "Enter student degree: " RESET);
    scanf("%lf", &students[NumberOfStudents].degree);
    printLoadingBar();
    system("cls");
    printf(GREEN "===================\nStudent has been added\n===================\n" RESET);
    NumberOfStudents++;
}

void Remove(void) {
    printf(YELLOW "\nEnter the student ID to remove: " RESET);
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
        printLoadingBar();
        system("cls");
        printf(GREEN "===================\nStudent %s has been removed successfully\n===================\n" RESET, students[idx].Student_Name);
        for (int j = idx; j < NumberOfStudents - 1; j++) {
            students[j] = students[j + 1];
        }
        NumberOfStudents--;
    } else {
        printf(RED "There is no student with this ID\n" RESET);
    }
}

void EditStudentInfo(void) {
    printf(YELLOW "\nEnter the student ID: " RESET);
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
        printf(GREEN "Student: %s\nID: %d\nDegree: %lf" RESET, students[idx].Student_Name, students[idx].id, students[idx].degree);
        printf(YELLOW "\nNew username: " RESET);
        scanf(" %[^\n]%*c", students[idx].Student_Name);
        printf(YELLOW "New ID: " RESET);
        scanf("%d", &students[idx].id);
        printf(YELLOW "New degree: " RESET);
        scanf("%lf", &students[idx].degree);
        printLoadingBar();
        system("cls");
        printf(GREEN "===================\nChanges have been successfully applied\n===================\n" RESET);
    } else {
        printf(RED "There is no student with this ID\n" RESET);
    }
}

int checkPassAdmin(void) {
    char user[100];
    char pass[100];
    printf(YELLOW "Username: " RESET);
    scanf("%s", user);
    printf(YELLOW "Password: " RESET);
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

    printf(YELLOW "Username: " RESET);
    scanf(" %[^\n]%*c", user);
    printf(YELLOW "Password: " RESET);
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
        printf(CYAN "\n1- Admin   [A]\n2- Teacher [T]\n3- Student [S]\n==========\nEnter your role: " RESET);
        char a;
        scanf(" %c", &a);

        if (a == 'S') {
            student_Search();

        } else if (a == 'T') {

            if (checkPassTeacher()) {
                system("cls");
                while (1) {
                    printf(CYAN "\n1- Edit Grade [E]\n2- Display [D]\n3- Display All [X]\n4- Exit [Q]\nEnter the process: " RESET);
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
            } else {
                WrongPass();
            }

        } else if (a == 'A') {

            if (checkPassAdmin()) {
                system("cls");
                while (1) {
                    printf(CYAN "\n1- Edit [E]\n2- Remove [R]\n3- Add Student [A]\n4- Display [D]\n5- Display All [X]\n"
                           "6- Add Teacher [M]\n7- Remove Teacher [N]\n8- Exit [Q]\nEnter the process: " RESET);
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
                    } else if (h == 'Q') {
                        printf("\n");
                        system("cls");
                        break;
                    } else {
                        Error();
                    }
                }
            } else {
                WrongPass();
            }
        } else {
            Error();
        }
    }
}
