//-------------- student.cpp --------

//#include "student.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <numeric>
#include "student.hpp"
#include <algorithm>

void fill_Student_Vector(std::vector<Student> &students){

    std::fstream file;

    file.open("grades.txt", std::ios::in);



    std::string line;

    while(getline(file, line)){

        Student a;

        size_t pos;

        pos = line.find(',');

        a.name = line.substr(0, pos);

        line = line.substr(pos+1);

        pos = line.find(',');

        a.surname = line.substr(0, pos);

        line = line.substr(pos+1);

        for(int i = 0; i < 7; i++){

            pos = line.find(',');

            int b = std::stoi(line.substr(0, pos));

            a.grades.emplace_back(b);

            line = line.substr(pos+1);

        }

        students.emplace_back(a);

    }

}

double calculate_grades(double x){
    double percentage = (x/70.0)*100.0;
    double final_grade;
    if (percentage >= 91 && percentage <= 100){
        final_grade = 5.0;
    }
    else if (percentage >= 81& percentage <= 90){
        final_grade = 4.5;
    }
    else if (percentage >= 71 & percentage <= 80){
        final_grade = 4.25;
    }
    else if (percentage >= 61 && percentage <= 70){
        final_grade = 3.5;
    }
    else if (percentage >= 51 && percentage <= 60){
        final_grade = 3.25;
    }
    else if (percentage >= 0 && percentage <= 50){
        final_grade = 2.25;
    }
    return final_grade;
}

//void final_grade(vector <Student> &student_container){


//}

bool by_grade(Student &x1, Student &x2){
return x1.final_grade> x2.final_grade;
}

void sort_students_by_grade(vector <Student> &x){
    sort(x.begin(), x.end(), by_grade);
}
