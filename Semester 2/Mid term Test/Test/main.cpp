#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//TASK 2

class Vector2D{
public:
    Vector2D(double x = 0.0, double y = 0.0): x(x), y(y) {
        //
    }

    friend std::ostream &operator<<(std::ostream &str, Vector2D &rhs){

        str << rhs.x << " " << rhs.y;

        return str;

        }


    Vector2D operator+(const Vector2D &other) const  {
        return Vector2D(x + other.x,
                        y + other.y);
    }

    Vector2D operator-(const Vector2D &other) const  {
        return Vector2D(x - other.x,
                        y - other.y);
    }

    double operator*(const Vector2D &other) const  {
        return x * other.x +
                        y * other.y;
    }

    bool operator==(const Vector2D &other) const  {
        if (x == other.x && y == other.y){
            return true;
        }
        return false;
    }



private:
    double x, y;
};


//TASK1

class Animal{
public:
    Animal(string name, int age, double weight) : name_(name), age_(age), weight_(weight){
        //
    }

    void display(){
        cout << name_ << "\n" << age_ << " \n" << "\n " << weight_;
    }

protected:
    string name_;
    int age_;
    double weight_;
};


class Mammal : public Animal{
public:
    Mammal(string name, int age, double weight, bool isHerbivore) : Animal (name, age, weight) , isHerbivore_(isHerbivore){

    }

    void display(){
        std::cout << "Is Herbivore? " << (isHerbivore_ ? "Yes" : "No") << std::endl;
    }
protected:
    bool isHerbivore_;
};


class CarnivoreMammal : public Mammal{
public:
    CarnivoreMammal(string name, int age, double weight, bool isPredetor) : Mammal (name, age, weight, false), isPredetor_(isPredetor){

    }
    void display(){
        std::cout << "Is Predetor? " << (isPredetor_ ? "Yes" : "No") << std::endl;
    }

protected:
    bool isPredetor_;
};

class Reptile : public Animal{
public:
    Reptile(string name, int age, double weight, bool isVenomous) : Animal (name, age, weight) , isVenomous_(isVenomous){

    }

    void display(){
        std::cout << "Is Venomous? " << (isVenomous_ ? "Yes" : "No") << std::endl;
    }
protected:
    bool isVenomous_;
};


class Zoo{
public:

    void addAnimal (std::unique_ptr<Animal> animal){
       animals.emplace_back(std::move(animal));
    }

    void displayAnimals (){
        for (auto &value : animals){
                    value->display();
        }
    }

private:
    std::vector<std::unique_ptr<Animal>> animals;
};


int main()
{

    // TASK 1

    Zoo zoo;
    auto mammal = std::make_unique<Mammal>("Elephant", 30, 50, false);
    auto mammal2 = std::make_unique<Mammal>("Giraffe", 30, 50, false);
    auto carnivoremammal = std::make_unique<CarnivoreMammal>("Giraffe", 30, 50, true);
    auto reptile = std::make_unique<Reptile>("Snake", 30, 50, false);

    zoo.addAnimal(std::move(mammal));
    zoo.addAnimal(std::move(mammal2));
    zoo.addAnimal(std::move(carnivoremammal));
    zoo.addAnimal(std::move(reptile));

    zoo.displayAnimals();

    //TASK 2
    Vector2D vec1(3.0, 4.0);
    Vector2D vec2(1.0, 2.0);

    std::cout << "Vector 1: " << vec1 << std::endl;
        std::cout << "Vector 2: " << vec2 << std::endl;


    Vector2D sum = vec1 + vec2;
        std::cout << "Sum: " << sum << std::endl;

    Vector2D difference = vec1 - vec2;
        std::cout << "Difference: " << difference << std::endl;

//    double dotProduct = vec1 * vec2;
//        std::cout << "Dot Product: " << dotProduct << std::endl;

    bool areEqual = vec1 == vec2;
    std::cout << "Are equal? " << (areEqual ? "Yes" : "No") << std::endl;

    return 0;
}