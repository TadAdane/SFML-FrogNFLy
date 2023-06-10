#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

class Student{
    public:
    
    void set_student(string name, string surname, string album_number, vector <float> grade){
        name_ = name;
        surname_ = surname;
        if (album_number.size() >= 6){
            cout << "\n****ERROR: Invalid album_number\n";
        }else {
            album_number_ = album_number;
            
            for (auto value : grade){
            add_grade(value);
        }
        }
    }
    
    float calculate_grade(){
        float sum = accumulate(grades_.begin(), grades_.end(), 0.0f);
        return sum/grades_.size();
    }
    
    bool add_grade (float grade){
        if (grade >= 2.0 && grade <= 5.0){
            grades_.push_back(grade);
            return true;
        }
        return false;
    }
    
    void pass_fail(){
        int count = 0;
        for (int i = 0; i < grades_.size(); i++){
            if (grades_[i] == 2){
                count++;
            }
        }
        if (count >= 2){
            cout << "FAIL\n" << endl;
        }
        else if (count == 0){
            cout << "INVALID\n" << endl;
        }
        else{
            cout << "PASS\n" << endl;
        }
    }
    
    void print_class(){
        cout << name_ << " " << surname_ << "\n  Album number: " << album_number_ << "\n  Grades: ";
        for (auto value : grades_){
            cout << value << ", ";
        }
        cout << "\n  Average: " << calculate_grade() << "\n  ";
        pass_fail();
    }
    
    private:
    vector <float> grades_; 
    string name_;
    string surname_;
    string album_number_;
    
};

class Complex{
    public:
    Complex(float real_num, float imaginary_num){
        real_num_ = real_num;
        imaginary_num_ = imaginary_num;
    }
    Complex(float real_num){
        real_num_ = real_num;
    }

    Complex(){
        //
    }
    void set_im(float imaginary_num){
        imaginary_num_ = imaginary_num;
    }
    
    void set_rl(float real_num){
        real_num_ = real_num;
    }
    
    Complex add(Complex a){
        Complex c;
        c.imaginary_num_ = imaginary_num_ + a.imaginary_num_;
        c.real_num_ = real_num_ + a.real_num_;
        return c;
    }
    void print(){
        cout << real_num_;
        if (imaginary_num_ >= 0){
            cout << "+";
        }
        
        cout << imaginary_num_ << "i";
    }
    
    private:
    float imaginary_num_;
    float real_num_;
};


int main()
{
    Student student1;
    student1.set_student("John", "Watson", "13435", {3.0, 4.5, 4.0, 2.0, 2.0});
    student1.print_class();
    
    Student student2;
    student2.set_student("Abebe", "Bekele", "5634464", {2.0, 4.0, 5.0, 5.0, 3.5});
    student2.print_class();
    
    Student student3;
    student3.set_student("Begeta", "Lentebo", "56486", {3.5, 5.0, 3.5, 4.0, 2.0});
    student3.print_class();
    
    
    Complex a(1.0, -2.0); // creates 1-2i
    a.print();
    cout << "\n";
    
    Complex b(3.14); // creates 3.14
    b.print();
    
    b.set_im(-5);
    cout << "\n";
    b.print();
    
    Complex c = a.add(b);
    cout << "\n";
    c.print(); // prints 4.14-7


    return 0;
}
//Loop for main funciton not working
//When code for q2 is relocated to a new void function, b with set_im not working.