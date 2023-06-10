#include <iostream>
#include <string>

class Vehicle {

public:
    std::string name() { return name_; }
    int number_of_wheels() { return number_of_wheels_; }
    std::string propulsion_type() { return propulsion_type_; }
    double max_speed() { return max_speed_; }


protected:
//private:
    Vehicle(const std::string &name, int number_of_wheels,
            const std::string &propulsion_type, double max_speed)
      : name_(name), number_of_wheels_(number_of_wheels),
        propulsion_type_(propulsion_type), max_speed_(max_speed) {
        std::cout << "Vehicle was created" << std::endl;
    }

    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;

};

class Bike : public Vehicle{
public:
    Bike(std::string color, int handle_part, double max_speed): Vehicle("Mountain", 4, "Mechanical", 25), handle_part_(handle_part), color_ (color){
        max_speed_ = max_speed;

        std::cout << "Bike was created" << std::endl;
    }


    std::string color(){return color_;}
    int handle_part(){return handle_part_;}
    //double max_speed(){return max_speed_;}

private:
    std::string color_;
    int handle_part_;
};


int main()
{
//    Vehicle my_car("BMW", 4, "Petrol", 300);
//    std::cout << "Name is: " << my_car.name() << std::endl;
    Bike bike1("Red", 2, 50);
//    bike1.

    std::cout << "Name is: " << bike1.name() << std::endl;
    std::cout << "Color is: " << bike1.color() << std::endl;
    std::cout << "No of handle is: " << bike1.handle_part() << std::endl;

    std::cout << "Max speed is: " << bike1.max_speed() << std::endl;

}
