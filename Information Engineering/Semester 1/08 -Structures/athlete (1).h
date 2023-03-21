#pragma once

#include <vector>
#include <string>

using namespace std;

struct Athlete{
    string first_name;
    string last_name;
    int bench_press;
    int deadlift;
};


void print_struct(const vector <Athlete> &x);
void input_struct(Athlete &x);
void best_bench_press(vector <Athlete> &x, int Athlete::*bench_press);
void best_deadlift(vector <Athlete> &x, int Athlete::*deadlift);
void sort_potential(vector <Athlete> &x);
void run_task1();