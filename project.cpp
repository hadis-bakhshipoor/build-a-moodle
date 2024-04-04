#include"project.h"

string name, lastname, role;

void login() {
    string name_, role_;

    cout<<"Enter your full name"<<endl;
    getline(cin, name_);
    cout<<"Enter your role"<<endl;
    cin >> role_;

    struct login_request {
        string name_login;
        string last_name_login;
        string role_login;
    };
    login_request* login_request_array;

    ifstream file_login("login_file.txt", ios::in);

    int num_of_users = 0;
    std::string line;
    while(std::getline(file_login, line)) num_of_users++;
    file_login.close();

    ifstream file_login_("login_file.txt", ios::in);
    login_request_array = new login_request[num_of_users];
    for(int i=0; i<num_of_users; i++) {
        file_login_ >> login_request_array[i].name_login >> login_request_array[i].last_name_login >> login_request_array[i].role_login;
        
        name = "nothing";
        if((login_request_array[i].name_login + " " + login_request_array[i].last_name_login) == name_ && login_request_array[i].role_login == role_)
            {name = login_request_array[i].name_login; 
            lastname = login_request_array[i].last_name_login; 
            role = login_request_array[i].role_login; 
            cout << "Your login was successful\n";
            break;}

    }
    
    if(name == "nothing") cout << "There is no one with this name and role\n";

    file_login_.close();
    delete []login_request_array;
}

std::filesystem::path student::homework_or_final(string teacher_name) {

    string lesson_name, homework_final, homework_num, file_name;

    cout << "please enter lesson name\t";
    cin >> lesson_name;
    cout<<"Do you want to enter the homework grade or the final grade?\n(homework or final)\t";
    cin >> homework_final;

    if(homework_final == "homework") {
        cout << "Which homework do you want to grade?\t" ;
        cin >> homework_num;

        file_name = lesson_name + "_" + teacher_name + "_" + homework_final + homework_num + ".txt";
        homework_final = "homeworks";
    }
    else if(homework_final == "final") {
        file_name = lesson_name + "_" + teacher_name + ".txt";
        homework_final = "final";
    }
    else cout << "Your answer is wrong (enter: homework or final)\n";

    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path file_path = cwd / homework_final / file_name;

    return file_path;

}

void student::read_grade_from_file(string student_name) {

    string student_full_name = "nothing";
    string teacher_name, student_grade;

    cout << "Please enter the teacher last name.\t";
    cin >> teacher_name;
    std::filesystem::path file_path = homework_or_final(teacher_name);
    
    ifstream file(file_path, ios::in);
    if(!file) cout<<"Your lesson name or teacher name is wrong!\n";

    while(!file.eof()) {
        string name, last_name;
        file >> name >> last_name >> student_grade;
        student_full_name = name + " " + last_name; 

        if(student_full_name == student_name) {
            cout << student_name << ", your grade is: " << student_grade;
            break;
        }   
    }

    if(student_full_name != student_name)
        cout<<"Your name is wrong or your name dose not found";

}


int teacher::open_file(std::filesystem::path file_path) {
    ifstream file(file_path, ios::in);

    int num_of_lines = 0;
    std::string line;
    while(std::getline(file, line)) num_of_lines++;
    file.close();
    
    return num_of_lines;
}

void teacher::creat_new_file_for_grade(string teacher_name) {
    string lesson_name, file_name;

    cout << "Please enter your lesson to creat a file\t";
    cin >> lesson_name;

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name = lesson_name + "_" + teacher_name + ".txt";
    std::filesystem::path file_path = cwd / "final" / file_name;
    ofstream file_grade(file_path);

    cout << "Please enter number of students\t";
    cin >> num_of_students;
    student_mark_array = new student_and_grade[num_of_students];

    cout << "Please enter students' full names one by one\n";

    for(int i=0; i<num_of_students; i++) {
        cin >> student_mark_array[i].name_of_student >> student_mark_array[i].last_name_of_student;
        file_grade << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student << endl;
    }

    file_grade.close();
    delete []student_mark_array;
}

void teacher::creat_new_file_for_homework(string teacher_name) {

    string file_name_, file_name, lesson_name, homework_num;

    cout << "Please enter your lesson to creat a file\t";
    cin >> lesson_name;
    cout << "Please enter the homework number\t";
    cin >> homework_num;
    

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name_ = lesson_name + "_" + teacher_name + ".txt";
    file_name  = lesson_name + "_" + teacher_name + "_" + "homework" + homework_num + ".txt";
    std::filesystem::path file_path_ = cwd / "final" / file_name_;
    std::filesystem::path file_path  = cwd / "homeworks" / file_name;

    ofstream file_homework(file_path);
    ifstream file_grade(file_path_, ios::in);

    num_of_students = open_file(file_path_);
    student_mark_array = new student_and_grade[num_of_students];

    for(int i=0; i<num_of_students; i++) {
        file_grade    >> student_mark_array[i].name_of_student >> student_mark_array[i].last_name_of_student;
        file_homework << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student << endl;
    }

    file_grade.close();
    file_homework.close();
    delete []student_mark_array;
}

void teacher::add_grade(string teacher_name) {

    std::filesystem::path file_path = homework_or_final(teacher_name);

    num_of_students = open_file(file_path);
    student_mark_array = new student_and_grade[num_of_students];
    
    ifstream file (file_path, ios::in);
    if(!file) cout<<"Your lesson name is wrong!";
    else {
        for(int i=0; i<num_of_students; i++) {
            file >> student_mark_array[i].name_of_student >> student_mark_array[i].last_name_of_student;
            
            cout << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student <<"\t";
            cin >> student_mark_array[i].grade;
        }

        file.close();
        ofstream file_(file_path);
        for(int i=0; i<num_of_students; i++)
            file_ << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student << " " << student_mark_array[i].grade << endl;
    
        file_.close();
        delete []student_mark_array;
    }
}

void teacher::remove_student(string teacher_name) {

    string file_name, lesson_name, name_student;

    cout << "Please enter your lesson\t";
    cin >> lesson_name;
    cin.ignore();
    cout << "Please enter the name_student want to remove\t";
    getline(cin, name_student);

    std::filesystem::path cwd = std::filesystem::current_path();
    file_name = lesson_name + "_" + teacher_name + ".txt";
    std::filesystem::path file_path = cwd / "final" / file_name;
    
    num_of_students = open_file(file_path);
    student_mark_array = new student_and_grade[num_of_students];
    ifstream file(file_path, ios::in);
    if(!file) cout<<"Your lesson name is wrong!";
    else{
        for(int i=0; i<num_of_students; i++)
            file >> student_mark_array[i].name_of_student >> student_mark_array[i].last_name_of_student;

        file.close();
        ofstream file_(file_path);
        
        int j = 0;
        for(int i=0; i<num_of_students-1; i++) {
            string fullname = student_mark_array[i].name_of_student + " " + student_mark_array[i].last_name_of_student;

                if(fullname == name_student) {j=i+1;}

            student_mark_array[i].name_of_student      = student_mark_array[j].name_of_student;
            student_mark_array[i].last_name_of_student = student_mark_array[j].last_name_of_student;
            j++;

            file_ << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student << endl;

        }
        file_.close();
        delete []student_mark_array;
    }
}


void admin::delete_lesson() {

    string file_name, lesson_name, teacher_name;

    cout << "Please enter your lesson to delete\t";
    cin >> lesson_name;
    cout << "Please enter your teacher name\t";
    cin >> teacher_name;


    std::filesystem::path cwd = std::filesystem::current_path();
    file_name = lesson_name + "_" + teacher_name;
    std::filesystem::path file_path_final    = cwd / "final";
    std::filesystem::path file_path_homework = cwd / "homeworks";

    ifstream file(file_path_final);
    if(!file) cout << "Your Input (lesson name or teacher name) is wrong!\n";
    file.close();

	namespace fs = std::filesystem;	
    for (const auto& entry : fs::directory_iterator(file_path_final)) {
    	if (entry.is_regular_file()) {
       		std::string filename = entry.path().filename().string();
        	if (filename.rfind(file_name, 0) == 0) {  
            	fs::remove(entry.path()); 
        	}
    	}
	}
    for (const auto& entry : fs::directory_iterator(file_path_homework)) {
    	if (entry.is_regular_file()) {
       		std::string filename = entry.path().filename().string();
        	if (filename.rfind(file_name, 0) == 0) {  
            	fs::remove(entry.path()); 
        	}
    	}
	}

}

void admin::update_grade() { 

    string student_name, teacher_name, right_grade;

    cout << "please enter teacher last name\t";
    cin >> teacher_name;
    std::filesystem::path file_path = homework_or_final(teacher_name);

    cout << "please enter student name\t";
    cin.ignore();
    getline(cin, student_name);
    cout << "please enter the right grade\t";
    cin >> right_grade;

    num_of_students = open_file(file_path);
    student_mark_array = new student_and_grade[num_of_students];
    ifstream file(file_path, ios::in);
    if(!file) cout<<"Your lesson name or teacher name is wrong";
    else{
        bool flag = 0;
        for(int i=0; i<num_of_students; i++) {
            file >> student_mark_array[i].name_of_student >> student_mark_array[i].last_name_of_student >> student_mark_array[i].grade;

            string fullname = student_mark_array[i].name_of_student + " " + student_mark_array[i].last_name_of_student;
            if(fullname == student_name){ 
                student_mark_array[i].grade = stof(right_grade); 
                flag = 1;
            }
        }

        if(flag == 0 ) cout << "Your student name you entered is incorrect! \n";

        file.close();
        ofstream file_(file_path);
        for(int i=0; i<num_of_students; i++) 
            file_ << student_mark_array[i].name_of_student << " " << student_mark_array[i].last_name_of_student << 
                " " << student_mark_array[i].grade << endl;

        file_.close();
        delete []student_mark_array;
        }

}

void admin::delete_account() {

    string name_person, last_name_person, role_person;

    cout << "enter the first name to remove\t";
    cin >> name_person;

    cout << "enter the last name to remove\t";
    cin >> last_name_person;

    cout << "enter the role of person\t";
    cin >> role_person;

    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path file_path = cwd / "login_file.txt";

    num_of_users = open_file(file_path);
    login_request_array = new login_request[num_of_users];

    ifstream file_login("login_file.txt", ios::in);
    bool flag = 0;
    for(int i=0; i<num_of_users; i++) {
        file_login >> login_request_array[i].name_login >> login_request_array[i].last_name_login >> login_request_array[i].role_login;

        if((login_request_array[i].name_login + login_request_array[i].last_name_login + login_request_array[i].role_login) 
            == name_person + last_name_person + role_person) {
                login_request_array[i].name_login = "*" + login_request_array[i].name_login; 
                flag = 1;
            }
    }

    if(flag == 0) cout << "The first name, last name, or role you entered does not exist in the list of people, please check again\n";

    file_login.close();
    ofstream file_login__("login_file.txt");

    for(int i=0; i<num_of_users; i++) 
        file_login__ << login_request_array[i].name_login << " " << login_request_array[i].last_name_login 
                     << " " << login_request_array[i].role_login << endl;
    
    file_login__.close();
    delete []login_request_array;
}

void admin::restore_account() {

    string name_person, last_name_person, role_person;

    cout << "enter the first name to restore\t";
    cin >> name_person;

    cout << "enter the last name to restore\t";
    cin >> last_name_person;

    cout << "enter the role of person\t";
    cin >> role_person;

    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path file_path = cwd / "login_file.txt";

    num_of_users = open_file(file_path);
    login_request_array = new login_request[num_of_users];

    ifstream file_login("login_file.txt", ios::in);
    bool flag = 0;
    for(int i=0; i<num_of_users; i++) {
        file_login >> login_request_array[i].name_login >> login_request_array[i].last_name_login >> login_request_array[i].role_login;

        if((login_request_array[i].name_login + login_request_array[i].last_name_login + login_request_array[i].role_login) 
            == ("*" + name_person + last_name_person + role_person)){
                login_request_array[i].name_login = name_person;
                flag = 1;
            }
    }
    if(flag == 0) cout << "The first name, last name, or role you entered does not exist in the list of people, please check again\n";

    file_login.close();
    ofstream file_login__("login_file.txt");

    for(int i=0; i<num_of_users; i++) 
        file_login__ << login_request_array[i].name_login << " " << login_request_array[i].last_name_login 
                     << " " << login_request_array[i].role_login << endl;
    
    file_login__.close();
    delete []login_request_array;

}
