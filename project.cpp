#include"project.h"

string name , role;

void login() {
    
    cout<<"Enter your full name"<<endl;
    getline(cin, name);
    cout<<"Enter ypur rull"<<endl;
    cin >> role;
}

void student::read_grade_from_file(string lesson_name, string teacher_name, string full_name) {

    string student_full_name = "nothing";
    string file_name, student_grade;

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name = lesson_name + "_" + teacher_name + ".txt";
    std::filesystem::path file_path = cwd / "grade" / file_name;
    
    ifstream file(file_path, ios::in);
    if(!file) cout<<"your lesson name or teacher name is wrong";

    while(!file.eof()) {
        string student_name, student_last_name;
        file >> student_name >> student_last_name >> student_grade;
        student_full_name = student_name + " " + student_last_name; 

        if(student_full_name == (full_name + ":")) {
            cout << full_name << ", your grade is: " << student_grade;
            break;
        }   
    }

    if(student_full_name != (full_name + ":"))
        cout<<"Your name is wrong or your name dose not found";

}

void student::read_takalif_from_file(string lesson_name, string teacher_name, string full_name, string number_of_taklif) {
    
    string student_full_name = "nothing";
    string file_name, student_grade;

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name = lesson_name + "_" + number_of_taklif + "_" + teacher_name + ".txt";
    std::filesystem::path file_path = cwd / "takalif" / file_name;

    ifstream file(file_path, ios::in);
    if(!file) cout<<"your lesson name or teacher name is wrong";

    while(!file.eof()) {
        string student_name, student_last_name;
        file >> student_name >> student_last_name >> student_grade;
        student_full_name = student_name + " " + student_last_name; 

        if(student_full_name == (full_name + ":")) {
            cout << full_name << ", your grade for: " << number_of_taklif << " is: "<< student_grade;
            break;
        }   
    }

    if(student_full_name != (full_name + ":"))
        cout<<"Your name is wrong or your name dose not found";
}