std::string next(std::string &line) {
    std::string name = line.substr(0, line.find(';'));
    line = line.substr(line.find(';') + 1);
    return name;
}
Student make_student(std::string line) {
    std::string name = next(line);
    std::string group = next(line);
    std::vector<Course> courses;
    Student student = Student();
    student.name = name;
    student.group = group;
    while (line.length()!=1){
        std::string subject = next(line);
        int semester = std::stoi(next(line));
        bool finished = std::stoi(next(line));
        student.courses.push_back(Course{ name = subject, semester = semester, finished = finished });
    }
    return student;
}
bool is_upper(Student left, Student right) {
    if (left.group < right.group) {
        return true;
    }
    else if (left.group > right.group) {
        return false;
    }
    else if (left.name < right.name) {
        return true;
    }
    else {
        return false;
    }
}

bool is_debtor(Student student, int cur_semester, int max_debt){
    int debt_count = 0;
    std::vector<Course> all_course = student.courses;
    for (auto& info : all_course) {
        int semester = info.semester;
        bool finished = info.finished;
        if (semester < cur_semester && finished == false) {
            debt_count++;
        }
    }
    return debt_count > max_debt;
}


void print(std::vector<Student> students) {
    if (students.empty())std::cout << "Empty list!";

    else {
        Student prev = students[0];
        std::cout << prev.group + "\n";
        int k = 0;
        for (auto& student : students) {

            if (k == 0) {
                k += 1;
                continue;
            }
            std::cout << "- " << prev.name + "\n";
            if (prev.group != student.group) {
                std::cout << student.group << "\n";

            }
            if (prev.name == students[students.size() - 2].name && prev.group == students[students.size() - 2].group) {

                std::cout << "- " << students[students.size() - 1].name + "\n";

            }
            prev = student;
            k += 1;

        }

    }
}