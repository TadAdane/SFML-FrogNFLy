#include <iostream>

#include "invoice.h"
using namespace std;

Item::Item(string name, double price, char tax, int amount){
        name_ = name;
        price_ = price;
        tax_ = tax;
        amount_ = amount;
    }

string Item::get_name(){
        return name_;
    }

double Item::get_price(){
        return price_;
    }
    
char Item::get_tax(){
        return tax_;
    }
    
int Item::get_amount(){
        return amount_;
    }
    

Invoice::Invoice(long unsigned int seller, long unsigned int buyer){
        buyer_ = buyer;
        seller_ = seller;
    }
    
void Invoice::add_item(Item item){
        //for (auto value: item_){
            item_.emplace_back(item);
            // item_.emplace_back(item.get_amount());
            // item_.emplace_back(item.get_price());
            // item_.emplace_back(item.get_tax());
        //}
    }
std::ostream &operator<<(std::ostream &str, Invoice &rhs){
        str << "------------------VAT invoice------------------" << endl;
        str << "===============================================" << endl; 
        str << "Seller: " << rhs.seller_;
        str << "             Buyer: 0" << rhs.buyer_ << endl;
        str << "                  c.j.  VAT   il.   net   total" << endl;
        
        // string name;
        // double price;
        // char tax;
        // int amount;
        int no = 1;
        double sum_net = 0, sum_tot = 0;
        for (Item value : rhs.item_){
            
            //name = item_
            str << no << ". " << value.get_name() << " | " << value.get_price() << " | " << value.get_tax() << " | " << value.get_amount() << " | " << value.get_amount() * value.get_price() << " | ";
        
            if (value.get_tax() == 'A'){
                sum_tot = 0.23*value.get_price()*value.get_amount() + value.get_price()*value.get_amount();
                str << 0.23*value.get_price()*value.get_amount() + value.get_price()*value.get_amount() << endl;
            }
            else if (value.get_tax() == 'B'){
                sum_tot += 0.08*value.get_price()*value.get_amount() + value.get_price()*value.get_amount();
                str << 0.08*value.get_price()*value.get_amount() + value.get_price()*value.get_amount() << endl;
            }
            else if (value.get_tax() == 'C'){
                sum_tot = value.get_price()*value.get_amount();
                str << value.get_price()*value.get_amount() << endl;
            }
        no++;
        
        sum_net += value.get_amount() * value.get_price();
        
        
 
        }
        // for (auto value : rhs.item_){
        //     str << value.get_name();
        // }
        
        str << "------------------------------------ TOTAL ----" << endl;
        str << "                                  " << sum_net << "|" << sum_tot;
        return str;
    }