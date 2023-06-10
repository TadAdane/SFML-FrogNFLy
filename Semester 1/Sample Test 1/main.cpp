/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

char change_to_undersores(char* arr){
    for (int i = 0; i < 25; i++){
        if ((arr[i] < 'a' || arr[i] > 'z') && (arr[i] < 'A' || arr[i] > 'Z') && (arr[i] < '0' || arr[i] > '9')){
        arr[i] = '_';
        }
    }
    return *arr;
}
void run_task1(){
    char text[] = "Text#with@weird^signs@()-";
    change_to_undersores(text);
    //cout << "Text#with@weird^signs@()-\n";
    cout << text << endl;
}

int factorial(int n){
    if (n <= 1){
        return 1;
    }
    return n*factorial(n - 1);
}

void calculate_trig_from_series(double x, int n, double &sin_val, double &cos_val){
    sin_val = 0;
    cos_val = 0;
    for (int i = 0; i < n; i++){
        sin_val = sin_val + pow(-1,i)*pow(x,2*i+1)/factorial(2*i+1);
        cos_val= cos_val+pow(-1,i)*pow(x,2*i)/factorial(2*i);

    }
}

void run_task2(){
    double sin_val, cos_val;
    calculate_trig_from_series(0.52, 9, sin_val, cos_val);
    cout << "The sin value is: " << sin_val << endl;
    cout << "The cos value is: " << cos_val;
}


int polynomial(double* a, int n, double x){
    double result;
    for (int i = n - 1; i >= 0; i--){
        //cout << a[i];
        result = result + a[i]*pow(x, i);
    }
    return result;
}

void run_task3(){
// f(x) = -3x^3 + 2x^2 – 3x + 5 // f(2) = - 17
double coefs[4] = {-3, 2, -3, 5}; 
reverse (coefs, coefs + 4);
int n = 4;
double x = 2;
double result = polynomial(coefs, n, x);
cout << result;
}

double mean (int* arr_, int x){
    //x = 100;
    double arr_sum = 0;
    for (int i = 0; i < 100; i++){
        arr_sum += arr_[i];
    }
    return arr_sum/100;
}

void run_task4(){
    int arr[100];
    srand(time(nullptr));
    for (int i = 0; i < 100; i++){
        arr[i] = rand()%101 + 50;
        //cout << arr[i] << " ";
    }

     double mean_val = mean(arr, 100);
     cout << "\nThe mean value is: " << mean_val;
}

int main()
{
    int task;
    while (task != 0){
        cout << "\nPlease choose the number of task\n";
        cout << "1 - for task 1\n";
        cout << "2 - for task 2\n";
        cout << "3 - for task 3\n";
        cout << "4 - for task 4\n";
        cout << "0 - for exit\n";
        
        cin >> task;
        switch(task){
            case 1:
            run_task1();
            break;
            case 2:
            run_task2();
            break;
            case 3:
            run_task3();
            break;
            case 4:
            run_task4();
            break;
        }
    }

    return 0;
}



