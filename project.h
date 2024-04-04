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

class teacher: public student {
    protected:
        int num_of_students;
        struct student_and_grade {
            string name_of_student;
            string last_name_of_student;
            float grade;
        };
        student_and_grade* student_mark_array;
   
    public: 
        std::filesystem::path homework_of_final(string teacher_name);
        int open_file(std::filesystem::path file_path);

        void creat_new_file_for_grade(string teacher_name);
        void creat_new_file_for_homework(string teacher_name);
        void add_grade(string teacher_name);
        void remove_student(string teacher_name);

};

class admin: public teacher {
    private:
        int num_of_users;
        struct login_request {
            string name_login;
            string last_name_login;
            string role_login;
        };
        login_request* login_request_array;

    public:
        void delete_lesson();
        void update_grade();
        void delete_account();
        void restore_account();
};

void login();