#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    /* Question number 1, Listing prime numbers*/
    cout << "Please enter minimum and maximum numbers respectively to get the list of prime numbers in between" << endl;
    /*Declare integers*/
    int minN = 0, maxN = 0, e, f, d;
    cin >> minN >> maxN;
    /*first loop, fist minimum integer increases by one until maximum integer is reached*/
    for (e = minN; e <= maxN; e++) {
    /*1 and 0 are neither prime nor composite*/
        if (e == 1 || e == 0)
            continue;
    /*second loop, initializing the divisor that increases by one until the maximum integer is reached*/
        for (f = 2; f <= e / 2; ++f) {
    /*If the remainder is 0, the code stops and re-runs by adding one to the integer*/
            if (e % f == 0) {
                d = 0;
                break;
    /*If the remainder is different from 0, Print that number*/
            }
            else if (e % f != 0){
                d = 1;
            }
        }
        if (d == 1){
            cout << e << " " << endl;
        }
    }

    /*Question number 2, Factorial of a number*/
    /*Declare integers*/

   // Enter any key to continue
    cin.ignore();
    cout << "Enter any key to continue to Question number 2" << endl;
    cin.get();

    // Factorial limit for unsigned short int
    unsigned short int usia = 1, usib = 1;
    do {
        usib++;
        usia *= usib;
        if (usia == 0){
        }
    }while (usia);
    cout << "The limit of factorial for unsigned short int is " << usib <<  endl;

    // Factorial limit for unsigned int
    unsigned int uia = 1, uib = 1;
    do {
        uib++;
        uia *= uib;
        if (uia == 0){
        }
    }while (uia);
    cout << "The limit of factorial for unsigned int is " << uib <<  endl;
    //cout << "With a factorial value of " << a << endl;

    // Factorial limit for unsigned long
    unsigned long ula = 1, ulb = 1;
    do {
        ulb++;
        ula *= ulb;
        if (ula == 0){
        }
    }while (ula);
    cout << "The limit of factorial for unsigned long is " << ulb <<  endl;

    // Factorial limit for unsigned long long
    unsigned long long ulla = 1, ullb = 1;
    do {
        ullb++;
        ulla *= ullb;
        if (ulla == 0){
        }
    }while (ulla);
    cout << "The limit of factorial for unsigned long long is " << ullb <<  endl;

    /*Question number 3,*/

    //LCM for two numbers
    cout << "Please enter two numbers to get their LCM " << endl;

    //Declare integers
    int s, r, t;
    cin >> s >> r;

    // Loop that prints the integer that divides both numbers with no remainder
    for (t = 1; t <= (s*r); t++){
        if (t % s == 0 && t % r == 0){
            cout << t << endl;
            break;
        }
    }

    /*Question number 4*/
    cout << "Please enter the value of z" << endl;

    // Declare integers and float numbers
    int z, k, factorialk;
    float kat, sum = 0;
    cin >> z;

    // Input number of iterations
    cout << "Please the number of iteration" << endl;
    cin >> k;
    int acc = 1;

    //Loop for the factorial for k
    for (factorialk = 1; factorialk <= k ;++factorialk){
        acc *= factorialk;

        //Given equation
        kat = (pow(z,factorialk))/acc;

        //Summation
        sum += kat;
    }
    cout << "The value of the given equation is " << sum << endl;

    // Given formula of e^z
    float naturale = exp(z);
    cout << "The value of the e^(z) is " << naturale << endl;

    //The error of the given formula to the e^z in percent
    cout << "The error is " << ((naturale - sum)/naturale)*100 << "%"<< endl;

    return 0;
}
