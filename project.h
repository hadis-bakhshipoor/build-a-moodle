#include<iostream>
#include<string>
#include<fstream>
#include<filesystem>

using namespace std;


class student {
    public:
        void read_grade_from_file(string student_name);
        void read_homework_from_file(string student_name);

};

class teacher: public student{
    protected:
        int num_of_students;
        struct student_and_grade {
            string name_of_student;
            string last_name_of_student;
            float grade;
        };
        student_and_grade* student_mark_array;
   
    public: 
        void creat_new_file_for_grade(string teacher_name);
        void creat_new_file_for_homework(string teacher_name);
        void add_grade(string teacher_name);
        void remove_student(string teacher_name);

};

void login();