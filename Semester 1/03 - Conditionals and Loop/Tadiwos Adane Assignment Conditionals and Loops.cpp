#include <iostream>
#include <cmath>

using namespace std;

/*Exercise number 1*/
// Function for calling Exercise one.
void Exercise1(){

    //Declare integers and truth values
    int Numofiter;
    bool mode;
    long double pi = 0;

    // Input declare pi approximation mode
    cout << "Enter 0 for Leibniz pi approximation or 1 for Wallis pi approximation " << endl;
    cin >> mode;
    cout << "Approximation mode: " << mode << endl;

    //Input number of iterations, no of times loop runs
    cout << "Enter number of iterations "<< endl;
    cin >> Numofiter;

    //Run code for Leibniz mode of pi approximation
    if(mode == 0){
        for(int i=0; i < Numofiter; i++){
            long double num = pow(-1, i) / ((2*i) + 1);
            pi += num;
        }
        pi *= 4;
    }

    //Run code for Wallis mode of pi approximation
    else if (mode == 1){
        pi = 1;
        for(int i = 1; i < Numofiter; i++){
            long double num2 = 4*pow(i, 2) / (4*pow(i, 2) - 1);
            pi *= num2;
        }
        pi *= 2;
    }

    //Print the value of pi
    cout << "Approximated pi = " << pi << endl;

}

//Exercise number 2

void Exercise2(){

    //Ignore any previous inputs
    cin.ignore();

    //Declare integers
	int ascii;

	//Loop for printing ASCII values
	for(ascii = 0; ascii <= 255; ascii++)
	{
		cout << "The ASCII value of " << (char)ascii << " = " << ascii << endl;

		//Input any value to continue after 40 lines of code
		if (ascii == 40 || ascii == 80 || ascii == 120 || ascii == 160 || ascii == 200 || ascii == 240){
	        cout << "Press any key to continue " << endl;

	        //Break until any value input
	        cin.get();
	        cin.ignore();
	    }
	}
}

/*Exercise number 3*/
void Exercise3(){

    //Declare integers
    int intmin = 1, intmax = 1;
    int a, b, c;

    //Determine the factorial limit for int
    do {
        intmax++;
        intmin *= intmax;
        if (intmin == 0){
        }
    }while (intmin);

    //Enter values between 0 and int limit
    cout << "Since the factorial limit for int is " << intmax <<  endl;
    cout << "Please enter values between 0 and " << intmax << endl;

    cin >> a;

    //Code for 0!
    if (a == 0){
        c = 1;

        //Code for negative numbers factorial
        }else if (a < 0){
        cout << "Negative numbers don't have a factorial" << endl;
        }else if (a >= 34){
        cout << "The value limit for int is " << intmax << endl;
        return;
        }

    /*loop, input number is multiplied to an integer less than 1 until zero is reached*/
    for (b = a - 1; b > 0; --b){
        c = a *= b;
    }
    cout << c << endl;


}

//Main function for calling up functions of Excercises
int main()
{
    char Exercise, intx;
    char x;

    do
        {
    cout << "Choose an option:" << endl;
    cout << "Press 1 for Exercise 1" << endl;
    cout << "Press 2 for Exercise 2" << endl;
    cout << "Press 3 for Exercise 3" << endl;
    cout << "Press x for Exit" << endl;
    cin >> Exercise;

    if (Exercise == '1'){
            Exercise1();
    } else if (Exercise == '2'){
        Exercise2();
    } else if (Exercise == '3'){
        Exercise3();
    } else if (Exercise == 'x'){
        break;
    } else {
        cout << "Invalid option" << endl;
    }
    }while (Exercise);

    return 0;
}
