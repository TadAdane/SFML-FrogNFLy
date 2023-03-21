	
//------------- main.cpp ---------- //





#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <numeric>
#include "student.hpp"
#include <algorithm>

using namespace std;



int main()

{


    std::vector<Student> students;

    fill_Student_Vector(students);

    for (auto &student: students){
        double sum = 0;
        sum = accumulate(student.grades.begin(), student.grades.end(), 0);
        double final_grade = calculate_grades(sum);
        student.final_grade = final_grade;
        cout << student.name << " " << student.surname << " " << final_grade << endl;
    }

    cout << "\n";
    for (int i = 0; i < students.size(); i++){

             students[i].maximum_grade = *std::max_element(students[i].grades.begin(), students[i].grades.end()) << '\n';



    }
    sort_students_by_grade(students);

    for (auto &student : students){
        cout << student.name << " " << student.surname << " " << student.final_grade << " ------ Maximum Grade: " << student.maximum_grade << endl;
    }

    return 0;


}