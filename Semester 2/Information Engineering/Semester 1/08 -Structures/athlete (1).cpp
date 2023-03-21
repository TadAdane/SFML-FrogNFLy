
#include <iostream>
#include "athlete.h"
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <string>

using namespace std;

void print_struct(const vector <Athlete> &x){
    
    cout << "    Name         bench_press    deadlift" <<endl;
    for (auto value : x){
        cout << value.first_name << " ";
        cout << value.last_name << "        ";
        cout << value.bench_press << "lb"<< "          ";
        cout << value.deadlift << "lb" << endl;
    }
}

void input_struct(Athlete &x){
    cin >> x.first_name >> x.last_name >> x.bench_press >> x.deadlift;
    
}

void best_bench_press(vector <Athlete> &x, int Athlete::*bench_press){
   
    vector <int> bench_;
    for(Athlete &value : x){
        bench_.emplace_back(value.*bench_press);
    }
    
    sort(bench_.begin(), bench_.end());
    
    cout << bench_[bench_.size() - 1];
    
}

void best_deadlift(vector <Athlete> &x, int Athlete::*deadlift){
    
    vector <int> deadlift_;
    for(Athlete &value : x){
        deadlift_.emplace_back(value.*deadlift);
    }
    
    sort(deadlift_.begin(), deadlift_.end());
    
    cout << deadlift_[deadlift_.size() - 1];
}

bool potential(Athlete &x1, Athlete &x2){
    return (x1.bench_press + x1.deadlift > x2.bench_press + x2.deadlift);
}
// void personal_best_recored(vector <Athlete> &x, int Athlete::*deadlift, int Athlete::*bench_press){
//     int sum = 0;
    
//     // for (auto i = x.begin(); i != x.end(); i++);{
//     //     cout << *i <<" ";
//     // }
//     vector <int> best_record;
//     for(Athlete &value : x){
//         best_record.emplace_back(value.*deadlift + value.*bench_press);
//         //cout << value.*bench_press << " ";
//     }
//     sort(best_record.begin(), best_record.end(), potential);
//     //print_struct(x)
//     cout << best_record[best_record.size() - 1];
// }

void sort_potential(vector <Athlete> &x){
    sort(x.begin(), x.end(), potential);
}

void run_task1(){
    //The fist Athlete
    Athlete athelte1;
    athelte1.first_name = "Abebe";
    athelte1.last_name = "Natan";
    athelte1.bench_press = 150;
    athelte1.deadlift = 290;
    
    //The Second Athlete
    Athlete athelte2;
    athelte2.first_name = "James";
    athelte2.last_name = "Labro";
    athelte2.bench_press = 175;
    athelte2.deadlift = 330;
    
    //The third Athlete
    Athlete athelte3;
    athelte3.first_name = "Felix";
    athelte3.last_name = "Jonas";
    athelte3.bench_press = 225;
    athelte3.deadlift = 375;
    
    //The fourth Athlete
    
    cout << "Please enter a first name, last name, bench_press, deadlift respectively" << endl;
    Athlete athelte4;
    input_struct(athelte4);
    
    vector <Athlete> athelet = {athelte1, athelte2, athelte3, athelte4};
    
    print_struct(athelet);
    cout <<"\n";
    
    sleep(2);
    
    cout << "the best personal best record in bench press is: ";
    best_bench_press(athelet, &Athlete::bench_press);
    cout <<"\n";
    
    sleep(1);
    
    cout << "the average personal best records in deadlift is: ";
    best_deadlift(athelet, &Athlete::deadlift);
    cout <<"\n";
    
    sleep(1);
    
    cout << "Information about athelets starting from greatest potential:" << endl;
    sort_potential(athelet);
    print_struct(athelet);
    // personal_best_recored(athelet, &Athlete::deadlift, &Athlete::bench_press);
    //personal_best_recored(athelet, &Athlete:bench_press);
    
    
}
