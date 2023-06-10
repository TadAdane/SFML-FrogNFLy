#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Item{
    public:
    Item (string name, double price, char tax, int amount);
    
    string get_name();
    
    double get_price();
    
    char get_tax();
    
    int get_amount();
    
    private:
    string name_;
    double price_;
    char tax_;
    int amount_;
};

class Invoice{
    public:
    Invoice(long unsigned int seller, long unsigned int buyer);
    void add_item(Item item);
    friend std::ostream &operator<<(std::ostream &str, Invoice &rhs);
    
    private:
    long unsigned int buyer_;
    long unsigned int seller_;
    vector<Item> item_;
};

