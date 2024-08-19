
#include <stdio.h>
#include <string.h>
#include "main.h"

student students[20000];
int i = 0;
int search(student a[2000],int x)
{
    for(int o = 0; o < 2000; o++)
    {
       if(x == a[o].id)
       {
           return 1;
       }
    }
    return 0;
}
int main(void) {
    while (1) {
        printf("\n1- Admin   [A]\n2- teacher [T]\n3- Student [S]\n==========\nenter your role: ");
        char a;
        scanf(" %c", &a);

        if (a == 'S') {
            printf("\nEnter the student ID: ");
            int x = 0;
            scanf("%i", &x);
            int idx = -1;
            for (int j = 0; j < 20000; j++) {
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
        else if (a == 'T') {
            char user[100];
            char pass[100];
            printf("username: ");
            scanf("%s", user);
            printf("password: ");
            scanf("%s", pass);

            const char password[] = "teacher";
            const char username[] = "teacher";

            if (strcmp(pass, password) == 0 && strcmp(user, username) == 0) {
                printf("\n1- Edit Grade [E]\n4- Display [D]3- Display All [X]\nEnter the process: ");

                char h;
                scanf(" %c", &h);
                if (h == 'E') {
                    printf("\nEnter the student ID: ");
                    int x = 0;
                    scanf("%i", &x);
                    int idx = -1;
                    for (int j = 0; j < 20000; j++) {
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
                        printf("===================\nChanges have been successfully applied\n===================\n");
                    } else {
                        printf("There is no student with this ID\n");
                    }
                }
                else if (h == 'D') {
                    printf("\nEnter the student ID: ");
                    int x = 0;
                    scanf("%i", &x);
                    int idx = -1;
                    for (int j = 0; j < 20000; j++) {
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
                else if(h == 'X')
                {
                    if (i == 0) {
                        printf("No students to display.\n");
                    } else {
                        printf("===========================================================================\n");
                        printf("| %-20s | %-10s | %-10s |\n", "Name", "ID", "Grade");
                        printf("===========================================================================\n");
                        for (int j = 0; j < i; j++) {
                            printf("| %-20s | %-10d | %-10.2lf |\n", students[j].Student_Name, students[j].id, students[j].degree);
                        }
                        printf("===========================================================================\n");
                    }
                }
                else
                {
                    printf("\nInvalid input\n");
                }
            }
            else {
                printf("\nWrong password or username\n");
            }

        }

        else if (a == 'A') {
            char user[100];
            char pass[100];
            printf("username: ");
            scanf("%s", user);
            printf("password: ");
            scanf("%s", pass);

            const char password[] = "admin";
            const char username[] = "admin";

            if (strcmp(pass, password) == 0 && strcmp(user, username) == 0) {
                printf("\n1- Edit [E]\n2- Remove [R]\n3- Add [A]\n4- Display [D]\n5- Display All [X]\nEnter the process: ");
                char h;
                scanf(" %c", &h);

                if (h == 'E') {
                    printf("\nEnter the student ID: ");
                    int x = 0;
                    scanf("%i", &x);
                    int idx = -1;
                    for (int j = 0; j < 20000; j++) {
                        if (x == students[j].id) {
                            idx = j;
                            break;
                        }
                    }
                    if (idx >= 0) {
                        printf("Student: %s\nID: %d\nDegree: %lf", students[idx].Student_Name, students[idx].id, students[idx].degree);
                        printf("\nNew username: ");
                        scanf(" %[^\n]%*c", students[i].Student_Name);
                        printf("New ID: ");
                        scanf("%d", &students[idx].id);
                        printf("New degree: ");
                        scanf("%lf", &students[idx].degree);
                        printf("===================\nChanges have been successfully applied\n===================\n");
                    } else {
                        printf("There is no student with this ID\n");
                    }
                }
                else if (h == 'R') {
                    printf("\nEnter the student ID to remove: ");
                    int x = 0;
                    scanf("%i", &x);
                    int idx = -1;
                    for (int j = 0; j < i; j++) {
                        if (x == students[j].id) {
                            idx = j;
                            break;
                        }
                    }

                    if (idx >= 0) {
                        printf("===================\nStudent %s has been removed successfully\n===================\n", students[idx].Student_Name);
                        for (int j = idx; j <= i ; j++) {
                            students[j] = students[j + 1];
                        }
                        i--;

                    } else {
                        printf("There is no student with this ID\n");
                    }
                }
                else if (h == 'A') {
                    printf("Enter student name: ");
                    scanf(" %[^\n]%*c", students[i].Student_Name);
                    int p;
                    printf("Enter student ID: ");
                    scanf("%d", &p);
                    while(search(students,p))
                    {
                        printf("\nthis ID has been taken before\n");
                        printf("Enter student ID: ");
                        scanf("%d", &p);
                    }
                    students[i].id = p;
                    printf("Enter student degree: ");
                    scanf("%lf", &students[i].degree);
                    printf("===================\nStudent has been added\n===================\n");
                    i++;
                }
                else if (h == 'D') {
                    printf("\nEnter the student ID: ");
                    int x = 0;
                    scanf("%i", &x);
                    int idx = -1;
                    for (int j = 0; j < 20000; j++) {
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
                else if (h == 'X') {
                    if (i == 0) {
                        printf("No students to display.\n");
                    } else {
                        printf("===========================================================================\n");
                        printf("| %-20s | %-10s | %-10s |\n", "Name", "ID", "Grade");
                        printf("===========================================================================\n");
                        for (int j = 0; j < i; j++) {
                            printf("| %-20s | %-10d | %-10.2lf |\n", students[j].Student_Name, students[j].id, students[j].degree);
                        }
                        printf("===========================================================================\n");
                    }
                }

                else {
                    printf("\nInvalid input\n");
                }
            } else {
                printf("\nWrong password or username\n");
            }
        }
        else {
            printf("\nInvalid input\n");
        }
    }
    return 0;
}
