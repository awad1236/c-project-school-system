# Student Management System
<hr/>

## Overview

This C program is a simple student management system that allows administrators and teachers to manage student records. The program includes features for adding, removing, and editing student and teacher records, as well as displaying student information. 

## Features

### 1. **User Roles**
   - **Admin**: Has full access to the system, including the ability to manage both students and teachers.
   - **Teacher**: Can access and modify student grades and view student information.
   - **Student**: Can search for their own information.

### 2. **Admin Functions**
   - **Add Student**: Allows the admin to add a new student to the system.
   - **Remove Student**: Allows the admin to remove a student from the system.
   - **Edit Student Information**: Allows the admin to edit a student's information (name, ID, and degree).
   - **Display Student Information**: Displays information for a specific student.
   - **Display All Students**: Displays information for all students in the system.
   - **Add Teacher**: Allows the admin to add a new teacher to the system.
   - **Remove Teacher**: Allows the admin to remove a teacher from the system.

### 3. **Teacher Functions**
   - **Edit Student Degree**: Allows teachers to update a student's grade.
   - **Display Student Information**: Displays information for a specific student.
   - **Display All Students**: Displays information for all students in the system.

### 4. **Student Functions**
   - **Search Student Information**: Allows students to search for their own information by ID.

## Files Included

- `main.c`: The main program file containing the implementation of the student management system.
- `main.h`: Header file containing structure definitions and function prototypes.


## Usage Instructions

1. **Start the Program**:<br/>
- run the program on the cmd of the windows or you will be have to edit the commend "cls" to "clear" or what is equal it on your OS in the lines(22,41,77,96,127,160,178,261,276,290,314)<br/><br/>
- When you run the program, you will be prompted to select your role (Admin, Teacher, or Student).
   
3. **Admin Role**:
   - Log in using the default credentials:
     - Username: `admin`
     - Password: `admin`
   - After logging in, choose from the available options to manage students or teachers.

4. **Teacher Role**:
   - Log in with the username and password provided by the admin.
   - After logging in, you can modify student grades and view student information.

5. **Student Role**:
   - Enter your ID to search for your information.

