#include <iostream>


#include "time.h"

using namespace std;

Time::Time(float sec, float hour, float min ){
        //value_ = sec;
        //cout << value_ << endl;
        if (sec/60.0 >= 60.0){
            if (hour == 0.0){
                hour = sec/3600.0;
                hour_ = hour;
            }
            else{
                hour_ = hour;
            }
            
            if (min == 0.0){
                min = (sec/3600.0 - hour_)*60.0;
                min_ = min;
            }
            else{
                min_ = min;
            }
            //if (sec == 0.0){
               sec_ = ((sec/3600.0 - hour_)*60.0 - min_)*60.0; 
            //}
            // else {
            //     sec_ = sec;
            // }
        }
        else if (sec/60.0 < 60.0 && sec/60.0 >= 1.0){
            if (min == 0.0){
                min = sec/60.0;
                min_ = min;
            }
            else {
                min_ = min;
            }
            //if (sec == 0.0){
                sec_ = (sec/60.0 - min_)*60;
            //}
      //      else {
               // sec_ = sec;
    //        }
        }
        else {
            sec_ = sec;
        }
    }
    
void Time::print(){
        cout << hour_ << "h:" << min_ << "m:" << sec_ << "s";
    }

Time Time::operator-(const Time &other) const {
    return Time(hour_ - other.hour_, min_ - other.min_, sec_ - other.sec_);
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