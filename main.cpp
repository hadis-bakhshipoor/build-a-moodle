#include"project.h"

extern string name, lastname, role;

int main(){
    int choice;
    string full_name;

    login();
    if(role == "student"){
        student daneshjo;

        cout << "You are logged in as a student. You can only see the final score or your practice, to see your score...\n";
        daneshjo.read_grade_from_file(name + " " + lastname);

    } else if(role == "teacher"){
        teacher master;
        cout << "Press \n1 to create a new lesson, \n2 to create a new assignment, \n3 to add a grade,";
        cout << "\n4 to delete a student, \n5 to see the student's grade.\n";
        cin >> choice;
        switch (choice) {
        case 1:
            master.creat_new_file_for_grade(lastname);
            break;
        case 2:
            master.creat_new_file_for_homework(lastname);
            break;
        case 3:
            master.add_grade(lastname);
            break;
        case 4:
            master.remove_student(lastname);
            break;
        case 5:
            cout << "the full name of student:\n";
            cin.ignore();
            getline(cin ,full_name);
            master.read_grade_from_file(full_name);
            break;
        default: cout << "Your answer is wrong!"; }
    }

    else if (role == "admin") {
        admin manager;
        cout << "press number 1 to delete the lesson, \npress number 2 to update the score,\n";
        cout << "press number 3 to delete the account, \npress number 4 to restore the deleted account.\n";
        cout << "press number 5 to create a new lesson, \npress number 6 to create a new assignment, \npress number 7 to add a grade,\n"; 
        cout << "press number 8 to delete a student, \npress number 9 to see the student's grade,\n";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.delete_lesson();
            break;
        case 2:
            manager.update_grade();
            break;
        case 3:
            manager.delete_account();
            break;
        case 4:
            manager.restore_account();
            break;
        case 5:
            cout << "the last name of teacher:\n";
            cin.ignore();
            getline(cin ,full_name);
            manager.creat_new_file_for_grade(full_name);
            break;
        case 6:
            cout << "the last name of teacher:\n";
            cin.ignore();
            getline(cin ,full_name);
            manager.creat_new_file_for_homework(full_name);
            break;
        case 7:
            cout << "the last name of teacher:\n";
            cin.ignore();
            getline(cin ,full_name);
            manager.add_grade(full_name);
            break;
        case 8:
            cout << "the last name of teacher:\n";
            cin.ignore();
            getline(cin ,full_name);
            manager.remove_student(full_name);
            break;
        case 9:
            cout << "the full name of student:\n";
            cin.ignore();
            getline(cin ,full_name);
            manager.read_grade_from_file(full_name);
            break;
        default: cout << "Your answer is wrong!"; }
    }
}