#pragma once

#include <iostream>

using namespace std;

class Invoice{
    public:
    Invoice(long unsigned int seller, long unsigned int buyer){
        buyer_ = buyer;
        seller_ = seller;
    }
    friend std::ostream &operator<<(std::ostream &str, Invoice &rhs){
        str << "------------------VAT invoice------------------" << endl;
        str << "===============================================" << endl; 
        str << "Seller: " << rhs.seller_;
        str << "                      Buyer: " << rhs.buyer_ << endl;
        str << "                  c.j.  VAT   il.   net   total" << endl;
        str << rhs.name_ << " | " << rhs.price_ << " | " << rhs.tax_ << " | " << rhs.amount_ << " | " << rhs.amount_ * rhs.price_ << " | ";
        if (rhs.tax_ = 'A'){
            str << 0.23*rhs.price_*rhs.amount_ + rhs.price_*rhs.amount_ << endl;
        }
        else if (rhs.tax_ = 'B'){
            str << 0.8*rhs.price_*rhs.amount_ + rhs.price_*rhs.amount_ << endl;
        }
        else if (rhs.tax_ = 'C'){
            str << rhs.price_*rhs.amount_ << endl;
        }
        str << "------------------------------------ TOTAL ----";
        //str << "                                 "
        return str;
    }
    
    void add_item(string name, double price, char tax, int amount){
        name_= name;
        price_ = price;
        tax_ = tax;
        amount_ = amount;
    }
    
    private:
    long unsigned int buyer_;
    long unsigned int seller_;
    string name_;
    double price_;
    char tax_;
    int amount_;
};