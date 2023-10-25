Student make_student(std::string info){
    std::string name = info.substr(0, info.find(";"));
    std::string group = info.substr(info.find(";")+1);
    Student student = Student{ name = name, group = group };
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

void print(std::vector<Student> students){
    if (students.empty() )std::cout << "Empty list!";

    else {
        Student prev = students[0];
        std::cout << prev.group+"\n";
        int k = 0;
        for (auto& student : students) {
        
            if (k==0) {
                k += 1;
                continue;
            }
            std::cout << "- " << prev.name+"\n";
            if (prev.group != student.group) {
                std::cout << student.group << "\n";

            }
            if (prev.name == students[students.size() - 2].name && prev.group == students[students.size() - 2].group ) {
                
                std::cout << "- " << students[students.size() - 1].name+"\n";

            }
            prev = student;
            k += 1;
             
        }
     
    }
}