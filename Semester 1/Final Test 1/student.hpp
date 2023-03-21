//-------------- student.hpp -------------//

#pragma once
#ifndef STUDENT_HPP
#define STUDENT_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <numeric>
//#include "student.hpp"
#include <algorithm>

using namespace std;

struct Student{

     string name;

     string surname;
     vector <int> grades;
     double final_grade;
     double maximum_grade;



};

void fill_Student_Vector(std::vector<Student> &students);
double calculate_grades(double x);
bool by_grade(Student &x1, Student &x2);
void sort_students_by_grade(vector <Student> &x);

#endif // STUDENT_HPP
