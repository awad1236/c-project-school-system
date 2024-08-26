typedef struct {
    char Student_Name[100];
    int id;
    double degree;

} student;
typedef struct {
    char Teacher_Name[200];
    char Teacher_Pass[200];

} Teacher;
typedef struct {
    char Admin_Name[200];
    char Admin_Pass[200];

} Admin;
int search(student a[2000],int x);
void AddTeacher(void);
void RemoveTeacher(void);
void EditStudentDegree(void);
void student_Search(void);
void Dispaly(void);
void DisplyAll(void);
void Error(void) ;
void WrongPass(void);
void AddStudent(void);
void Remove(void);
void EditStudentInfo(void);
int checkPassAdmin(void);
int checkPassTeacher(void) ;
