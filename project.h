#include<iostream>
#include<string>
#include<fstream>
#include<filesystem>

using namespace std;


class student {
    public:
        void read_grade_from_file(string lesson_name, string teacher_name, string full_name);
        void read_takalif_from_file(string lesson_name, string teacher_name, string full_name, string number_of_taklif);

};

class teacher: public student{
    public: 
        void creat_new_file_for_grade(string lesson_name, string teacher_name);

};

void login();