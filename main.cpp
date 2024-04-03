#include"project.h"

extern string name , role;

int main(){

    login();
    if(role == "student"){
        student daneshjo;
    
    // daneshjo.read_grade_from_file(name);
    // daneshjo.read_homework_from_file(name);

    } else if(role == "teacher"){
        teacher master;

        // master.creat_new_file_for_grade(name);
        // master.creat_new_file_for_homework(name);
        // master.add_grade(name);
        master.remove_student(name);
    }
    


}