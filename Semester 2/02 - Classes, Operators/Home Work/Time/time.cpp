#include <iostream>


#include "time.h"

using namespace std;

Time::Time(int hour, int min, int sec ){

    hour_ = hour;
    min_ = min;
    sec_ = sec;
   
    }
    
Time::Time(int sec){
   
    if (sec/60.0 >= 60.0){
        hour_ = sec/3600.0;
        min_ = (sec/3600.0 - hour_)*60.0;
        sec_ = ((sec/3600.0 - hour_)*60.0 - min_)*60.0;
    }
    else if (sec/60.0 < 60.0 && sec/60.0 >= 1.0){
        min_ = sec/60.0;
        sec_ = (sec/60.0 - min_)*60;
        hour_ = 0.0;
    }
    else {
        sec_ = sec;
        min_ = 0.0;
        hour_ = 0.0;
        }
    }
    
Time::Time(){
    //
}

    
// void Time::print(){
//     cout << hour_ << "h:" << min_ << "m:" << sec_ << "s";
//     }

Time Time::operator-(const Time &other) const {
    
    int value = hour_*3600 + min_*60 + sec_;
    int value1 = other.hour_*3600 + other.min_*60 + other.sec_;
    
    if (value >= value1){
        return Time(value - value1);
    }
    else {
        cout <<"Input can't be less than '3m 20s!";
        return 0;
    }
    }

std::ostream &operator<<(std::ostream &str, Time &rhs){
    
    if (rhs.hour_ == 0 && rhs.min_ == 0){
        str << rhs.sec_ << "s";
    }
    else if (rhs.hour_ == 0 ){
        str << rhs.min_ << "m:" << rhs.sec_ << "s";
    }
    else {
        str << rhs.hour_ << "h:" << rhs.min_ << "m:" << rhs.sec_ << "s";
    }

    return str;

    }    

std::istream &operator>>(std::istream &in, Time &rhs){
    
        cout << "Enter hour ";
        in >> rhs.hour_;
        
        cout << "Enter minute ";
        in >> rhs.min_;
        
        cout << "Enter second ";
        in >> rhs.sec_;
        
    return in;
    
    }

Time::operator int(){
    
    return hour_*3600 + min_*60 + sec_;
    
}