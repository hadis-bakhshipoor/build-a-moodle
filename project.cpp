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

void teacher::add_grade(string teacher_name) {

    string file_name, lesson_name, homework_num, homework_or_final;

    cout << "Please enter your lesson to creat a file\n";
    cin >> lesson_name;

    cout<<"Do you want to enter the homework grade or the final grade?\n(homework or final)\n";
    cin >> homework_or_final;

    if(homework_or_final == "homework") {
        cout << "Which homework do you want to grade?\n" ;
        cin >> homework_num;


        file_name = lesson_name + "_" + homework_or_final + homework_num + "_" + teacher_name + ".txt";
        homework_or_final = "homeworks";
    }
    else if(homework_or_final == "final") {
        file_name = lesson_name + "_" + teacher_name + ".txt";
        homework_or_final = "final";
    }
    else cout << "Your answer is wrong (enter: homework or final)\n";

    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path file_path = cwd / homework_or_final / file_name;
    ifstream file(file_path, ios::in);

    num_of_students = 0;
    std::string line;
    while(std::getline(file, line)) {
        num_of_students++;
    }
    
    file.close();
    ifstream file_(file_path, ios::in);

    student_mark_array = new student_and_grade[num_of_students];
    for(int i=0; i<num_of_students; i++) {
        file_ >> student_mark_array[i].name_of_student >> student_mark_array[i].last_name_of_student;
        
        cout << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student <<"\t";
        cin >> student_mark_array[i].grade;
    }

    file_.close();

    ofstream file__(file_path);

    for(int i=0; i<num_of_students; i++) {
        file__ << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student << " " << student_mark_array[i].grade << endl;
 
    }

    file__.close();
    
}

void teacher::remove_student(string teacher_name) {

    string file_name_, file_name, lesson_name, homework_num, name_student;

    cout << "Please enter your lesson\n";
    cin >> lesson_name;
    cin.ignore();
    cout << "Please enter the name_student want to remove\n";
    getline(cin, name_student);

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name_ = lesson_name + "_" + teacher_name + ".txt";
    std::filesystem::path file_path_ = cwd / "final" / file_name_;
    ifstream file(file_path_, ios::in);

    num_of_students = 0;
    std::string line;
    while(std::getline(file, line)) {
        num_of_students++;
    }
    
    file.close();
    ifstream file_(file_path_, ios::in);

    student_mark_array = new student_and_grade[num_of_students];
    for(int i=0; i<num_of_students; i++) {
        file_ >> student_mark_array[i].name_of_student >> student_mark_array[i].last_name_of_student;
    }

    file_.close();

    ofstream file__(file_path_);
    int j = 0;
    for(int i=0; i<num_of_students-1; i++) {
        string fullname = student_mark_array[i].name_of_student + " " + student_mark_array[i].last_name_of_student;

            if(fullname == name_student + ":") {j=i+1;}

        student_mark_array[i].name_of_student      = student_mark_array[j].name_of_student;
        student_mark_array[i].last_name_of_student = student_mark_array[j].last_name_of_student;
        j++;

        file__ << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student << endl;

    }
    file__.close();
}

