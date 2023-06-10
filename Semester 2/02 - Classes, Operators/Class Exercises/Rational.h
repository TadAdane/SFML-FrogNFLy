#pragma once
#include <iostream>

class Rational {
public:
    Rational(int num = 0, int den = 1); // default constructor

    void set(int num, int den); // sets numerator and denominator
    int num() const; // gets numerator
    int den() const; // gets denominator
    void set_num(int num); // sets numerator
    void set_den(int den); // sets denominator
    Rational add(const Rational &other) const; // adds second rational number, returns result
    Rational subtract(const Rational &other) const; // subtracts second rational number, returns result
    void print() const; // prints number to console

private:
    int num_, den_;
};