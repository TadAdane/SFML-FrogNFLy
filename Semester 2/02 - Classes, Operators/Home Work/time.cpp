#include <iostream>


#include "time.h"

using namespace std;

Time::Time(float sec){
        value_ = sec;
        cout << value_ << endl;
        if (sec/60.0 >= 60.0){
            hour_ = sec/3600.0;
            min_ = (sec/3600.0 - hour_)*60.0;
            sec_ = ((sec/3600.0 - hour_)*60.0 - min_)*60.0;
        }
        else if (sec/60.0 < 60.0 && sec/60.0 >= 1.0){
            min_ = sec/60.0;
            sec_ = (sec/60.0 - min_)*60;
        }
        else {
            sec_ = sec;
        }
    }
    
void Time::print(){
        cout << hour_ << "h:" << min_ << "m:" << sec_ << "s";
    }

Time Time::operator-(const Time &other) const {
    return Time(value_ - other.value_);
    }

std::ostream &operator<<(std::ostream &str, Time &rhs){
        str << rhs.hour_ << "h:" << rhs.min_ << "m:" << rhs.sec_ << "s";

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