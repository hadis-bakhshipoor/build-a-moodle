#include"project.h"

string name , role;

void login() {
    
    cout<<"Enter your full name"<<endl;
    getline(cin, name);
    cout<<"Enter your role"<<endl;
    cin >> role;
}

void student::read_grade_from_file(string student_name) {

    string student_full_name = "nothing";
    string file_name, student_grade;

    string lesson_name, teacher_name;
    cout << "Please enter the name of lessone\n";
    cin >> lesson_name;
    cout << "Please enter the name of teacher\n";
    cin >> teacher_name;

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name = lesson_name + "_" + teacher_name + ".txt";
    std::filesystem::path file_path = cwd / "final" / file_name;
    
    ifstream file(file_path, ios::in);
    if(!file) cout<<"your lesson name or teacher name is wrong";

    while(!file.eof()) {
        string name, last_name;
        file >> name >> last_name >> student_grade;
        student_full_name = name + " " + last_name; 

        if(student_full_name == (student_name + ":")) {
            cout << student_name << ", your grade is: " << student_grade;
            break;
        }   
    }

    if(student_full_name != (student_name + ":"))
        cout<<"Your name is wrong or your name dose not found";

}

void student::read_homework_from_file(string student_name) {
    
    string lesson_name, teacher_name, number_of_homework;
    cout << "Please enter the name of lessone\n";
    cin >> lesson_name;
    cout << "Please enter the name of teacher\n";
    cin >> teacher_name;
    cout << "Please enter the number of homework\n";
    cin >> number_of_homework;

    string student_full_name = "nothing";
    string file_name, student_grade;

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name = lesson_name + "_" + "homework" + number_of_homework + "_" + teacher_name + ".txt";
    std::filesystem::path file_path = cwd / "homeworks" / file_name;

    ifstream file(file_path, ios::in);
    if(!file) cout<<"your lesson name or teacher name is wrong";

    while(!file.eof()) {
        string name, last_name;
        file >> name >> last_name >> student_grade;
        student_full_name = name + " " + last_name; 

        if(student_full_name == (student_name + ":")) {
            cout << student_name << ", your grade for: " << number_of_homework << " is: "<< student_grade;
            break;
        }   
    }

    if(student_full_name != (student_name + ":"))
        cout<<"Your name is wrong or your name dose not found";
}

void teacher::creat_new_file_for_grade(string teacher_name) {
    string lesson_name, file_name;

    cout << "Please enter your lesson to creat a file\n";
    cin >> lesson_name;

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name = lesson_name + "_" + teacher_name + ".txt";
    std::filesystem::path file_path = cwd / "final" / file_name;
    ofstream file_grade(file_path);

    cout << "Please enter number of students\n";
    cin >> num_of_students;
    student_mark_array = new student_and_grade[num_of_students];

    cout << "Please enter students' full names one by one\n";

    for(int i=0; i<num_of_students; i++) {
        cin >> student_mark_array[i].name_of_student >> student_mark_array[i].last_name_of_student;
        file_grade << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student << endl;
    }

    file_grade.close();
}

void teacher::creat_new_file_for_homework(string teacher_name) {

    string file_name_, file_name, lesson_name, homework_num;

    cout << "Please enter your lesson to creat a file\n";
    cin >> lesson_name;
    cout << "Please enter the homework number\n";
    cin >> homework_num;
    

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name_ = lesson_name + "_" + teacher_name + ".txt";
    std::filesystem::path file_path_ = cwd / "final"     / file_name_;
    ifstream file_grade(file_path_, ios::in);

    file_name  = lesson_name + "_" + "homework" + homework_num + "_" + teacher_name + ".txt";
    std::filesystem::path file_path  = cwd / "homeworks" / file_name;
    ofstream file_homework(file_path);

    num_of_students = 0;
    std::string line;
    while(std::getline(file_grade, line)) {
        num_of_students++;
    }
    
    file_grade.close();
    ifstream file_grade_(file_path_, ios::in);

    student_mark_array = new student_and_grade[num_of_students];
    for(int i=0; i<num_of_students; i++) {
        file_grade_   >> student_mark_array[i].name_of_student >> student_mark_array[i].last_name_of_student;
        file_homework << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student << endl;
    }

    file_grade_.close();
    file_homework.close();
}

