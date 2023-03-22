#pragma once

#include <iostream>

using namespace std;

class Time{
    public:
    
    Time(float sec = 0.0);
    
    void print();
    Time operator-(const Time &other) const;
    
    friend std::ostream &operator<<(std::ostream &str, Time &rhs);
    
    friend std::istream &operator>>(std::istream &in, Time &rhs);

    // int convert(){

    // }
    
    private:
    int hour_ = 0;
    int min_ = 0;
    int sec_ = 0;
    float value_;
    
};