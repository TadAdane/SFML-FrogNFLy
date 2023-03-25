#pragma once

#include <iostream>

using namespace std;

class Time{
    public:
    
    Time(int hour, int min, int sec);
    
    Time(int sec);
    
    Time();
    
    void print();
    Time operator-(const Time &other) const;
    
    operator int();
    
    friend std::ostream &operator<<(std::ostream &str, Time &rhs);
    
    friend std::istream &operator>>(std::istream &in, Time &rhs);


    
    private:
    int hour_ = 0;
    int min_ = 0;
    int sec_ = 0;
    
};