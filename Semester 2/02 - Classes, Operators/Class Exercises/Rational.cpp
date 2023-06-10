#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational(int num, int den) : num_(num) { // initializes num_ field with num value
    if (den) {
        den_ = den;
    } else {
        den_ = 1;
    }
}

void Rational::set(int num, int den) {
    num_ = num;
    if (den) {
        den_ = den;
    }
}

int Rational::num() const {
    return num_;
}

int Rational::den() const {
    return den_;
}

void Rational::set_num(int num) {
    num_ = num;
}

void Rational::set_den(int den) {
    if (den) {
        den_ = den;
    }
}

Rational Rational::add(const Rational &other) const {
    return Rational(num_ * other.den_ + other.num_ * den_,
                    den_ * other.den_);
}

Rational Rational::subtract(const Rational &other) const {
    return Rational(num_ * other.den_ - other.num_ * den_,
                    den_ * other.den_);
}

void Rational::print() const {
    if (den_ == 1) {
        std::cout << num_;
    } else {
        std::cout << num_ << "/" << den_;
    }
}