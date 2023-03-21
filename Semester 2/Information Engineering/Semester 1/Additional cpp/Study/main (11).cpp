// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

    
void run_task1(){
    cout << "please enter number of iterations\n";
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum = sum + pow(-1, i)/(2*i + 1);
    }
    cout << "the sum value is: " << 4*sum << endl;
}

void run_task2(){
    cout << "please enter number of iterations\n";
    int n;
    cin >> n;
    double product = 1.0;
    for (double i = 1; i < n; i++){
        product = product*((2*i)/((2*i) - 1))*((2*i)/((2*i) + 1));
    }
    cout << "the value of pi is: " << 2*product << endl;
}

void run_task3(){
    for (int i = 0; i < 255; i++){
        cout << (char)i << " - " << i << endl;
    }
}

void run_task4(){
    int n;
    cin >> n;
    int product = 1;
    if (n <= 0){
        product = 1;
    }else{
    for (int i = 1; i <= n; i++){
        product = product*i;
        if (product == 0){
            cout << "Reached limit: " << i;
            break;
        }
        }
        }
    if (product != 0){
    cout << "Factorial is: "<< product << endl;
    }
}

void run_task5(){
    cout << "please enter two numbers\n" << endl;
    int a, b, c, d;
    cin >> a>> b;
    d = a*b;
    for (c = 1; c <= d; c++){
        if (c%a == 0 && c%b == 0){
            cout << "Thier LCM is: " << c;
            break;
        }
    }
    
}

void run_task6(){
    int min, max;
    //bool e = 1;
    cin >> min >> max;
    for (int c = min; c < max; c++){
        if (c == 0 || c == 1){
            continue;
        } else {
            for (int d = 2; d <= c; d++){
                if (c%d == 0){
                    //e = 0;
                    break;
                } else {
                    cout << c << " ";
                    break;
                }
            }
        }
    }
}

void run_task7(){
    
    int arr[] = {1, 3, 7, 4, 2, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // loop for running the main loop for every character
    for (int x = 0; x < n - 1; x++ ){
    // main loop for sorting
    for (int i = 0; i < n; i++){
        if (arr[i] > arr[i + 1]){
            swap(arr[i], arr[i + 1]);
        }
    }
    }
    for (int j = 0; j < n; j++){
        cout << arr[j] << " ";
    }
}

void run_task8(){
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Choose the value you want from the array: ";
    
    for (int j = 0; j < n; j++){
        cout << arr[j] <<", ";
    }
    cout << "\n";
    
    int number;
    //cout << "Please enter the value you're looking for\n";
    cin >> number;
    int max = n;
    int min = 0;
    
    
    for (int i = 0; i < n; i++){
        int mid = (max + min)/2;
        if (arr[mid] == number){
            cout << "Value is present at index: "<< mid;
            break;
        }
        if (arr[mid] > number){
            max = mid;
            continue;
        }else if (arr[mid] < number){
            min = mid + 1;
            continue;
        }
    }
}

void run_task9(){
    cout << "PLease enter string to get capital letters\n";
    string smallLetters;
    getline(cin, smallLetters);
    
    int n = smallLetters.length();
    char smallLetters_char[n];
    
    strcpy(smallLetters_char, smallLetters.c_str());
    
    for (int i = 0; i < n; i++){
        if (smallLetters_char[i] == ' '){
            cout << ' ';
        }
        else if (smallLetters_char[i]> 'a' && smallLetters_char[i] < 'z'){
            int k = (int)smallLetters_char[i] - 32;
            cout << (char)k;
        } else {
            cout << smallLetters_char[i];
        }
    }
}

int main()
{
    
    // Write C++ code here
    // char exercise;
    
    // do{
    //     cin >> exercise;
    //     switch (exercise){
    //         case '1':
    //         cout << "Question one" << endl;
    //         break;
    //         case '2':
    //         cout << "Question two" << endl;
    //         break;
    //         case '3':
    //         cout << "Question three" << endl;
    //         break;
    //         // default:
    //         // cout << "Invalid Option" << endl;
    //         // break;
    //     }
    // } while(exercise != 'x');


    // cout << sqrt(4) << endl;
    // cout << pow(2, 4) << endl;
    // cout << cos(M_PI/3)<< endl;
    // cout << acos(0.5)<< endl;
    
    // int i = 4;
    // int j = 4;
    // int k = 4;
    // int l = 4;
    // cout << ++i << endl;
    // cout << j++ << endl;
    // cout << --k << endl;
    // cout << l-- << endl;
    
    
    // run_task1();
    // run_task2();
    // run_task3();
    //run_task4();
    //run_task5();
    //run_task6();
    //run_task7();
    //run_task8();
    run_task9();
    return 0;
}


