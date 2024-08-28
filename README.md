<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>School Management System</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            background-color: #f4f4f4;
            margin: 0;
            padding: 0;
        }
        .container {
            width: 80%;
            margin: auto;
            overflow: hidden;
            padding: 20px;
            background: #fff;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
        }
        h1, h2, h3 {
            color: #333;
        }
        pre {
            background: #f4f4f4;
            padding: 10px;
            border: 1px solid #ddd;
            overflow-x: auto;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>School Management System</h1>
        
        <h2>Overview</h2>
        <p>
            This project is a simple console-based School Management System written in C. It allows administrators and teachers to manage student and teacher records, including adding, removing, and editing information such as student grades and teacher credentials. The program provides different functionalities based on the user's role: Admin, Teacher, or Student.
        </p>
        
        <h2>Features</h2>

        <h3>Admin Features</h3>
        <ul>
            <li><strong>Add Student:</strong> Add a new student to the system with a unique ID.</li>
            <li><strong>Remove Student:</strong> Remove an existing student from the system using their ID.</li>
            <li><strong>Edit Student Information:</strong> Modify student details like name, ID, and grade.</li>
            <li><strong>Display Student:</strong> Display the details of a student using their ID.</li>
            <li><strong>Display All Students:</strong> Show a list of all students in the system.</li>
            <li><strong>Add Teacher:</strong> Add a new teacher to the system.</li>
            <li><strong>Remove Teacher:</strong> Remove a teacher from the system using their username.</li>
        </ul>

        <h3>Teacher Features</h3>
        <ul>
            <li><strong>Edit Student Grade:</strong> Update the grade of a student using their ID.</li>
            <li><strong>Display Student:</strong> Display the details of a student using their ID.</li>
            <li><strong>Display All Students:</strong> Show a list of all students in the system.</li>
        </ul>

        <h3>Student Features</h3>
        <ul>
            <li><strong>Search Student:</strong> Search for a student using their ID and display their details.</li>
        </ul>

        

        <h2>How to Use</h2>
        <ol>
            <li><strong>Role Selection:</strong> After running the program, you will be prompted to select your role:
                <ul>
                    <li>Admin [A]</li>
                    <li>Teacher [T]</li>
                    <li>Student [S]</li>
                </ul>
            </li>
            <li><strong>Authentication:</strong>
                <ul>
                    <li>Admin and Teacher roles require a username and password to access the system.</li>
                    <li>Default Admin credentials: <code>admin</code> / <code>admin</code>.</li>
                </ul>
            </li>
            <li><strong>Function Selection:</strong> Once authenticated, you will be prompted to select a function based on your role.</li>
        </ol>

        <h2>Code Structure</h2>
        <ul>
            <li><strong>main.c:</strong> Contains the main function and other functions related to different user roles.</li>
            <li><strong>main.h:</strong> Header file defining the data structures for students, teachers, and admins.</li>
        </ul>

        <h2>Data Structures</h2>
        <ul>
            <li><strong>student:</strong> Represents a student with attributes like name, ID, and grade.</li>
            <li><strong>Teacher:</strong> Represents a teacher with attributes like name and password.</li>
            <li><strong>Admin:</strong> Represents an admin with attributes like name and password.</li>
        </ul>

      
</body>
</html>
