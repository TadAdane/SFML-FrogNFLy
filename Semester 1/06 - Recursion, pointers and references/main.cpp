/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

float question1(float* arr, int x){ //Recursion for harmonic mean
    
    if (x < 0){ //base case 
        return 0;
    } else {
        return 1.0/arr[x] + question1(arr, x - 1); // returns the harmonic sum
    }
    
}

void run_question1(){ //Code for Harmonic mean
    int harmonic_size = 2;
    float harmonic_array[harmonic_size];
           
    cout <<"Please enter 3 values to get their harmonic mean" << endl;
    for (int j = 0; j <= harmonic_size; j++){ // loop for user input
        cin >> harmonic_array[j];
        }
    
           cout << (harmonic_size + 1)/question1(harmonic_array, harmonic_size); // outputs the harmonic mean by dividing harmonic size by harmonic sum.
}

void question2 (char* arr, int x){ //Cypher recursion
    int i = 0;
    int j = 25;
    do{ //Loop for accessing each value of the small letter string input
        int e = (int)arr[i];
        int c = (e - 97)*2;
        int d = (122 - e)*2;
        for (j; j > 0; j--){// loop for exchanging each value of string input and decrease value ascii code.
            
            if (e <= 109){// Condition for when the letter is below the middle letter(m or n)
                if (e == 32){// Condition for space
                cout << " ";
                }else{
                int a = e + (j - c); //Add value of 25 minus the value of how much the current value is farther from 'a'.
                cout << (char)a; //Print the cyphered key
                }
                i++; // Increment i to access every key after each run.
                break;
               
            }else if (e >= 110){// Condition for when the letter is above the middle letter(m or n)
                int a = e - (j - d); //substract value of 25 minus the value of how much the current value is farther from 'z'.
                cout << (char)a; //Print the cyphered key
                i++; // Increment i to access every key after each run.
                break;
            }
        }
    }while(i < x);
}

void run_question2(){ //Code for Cypher
           
           string cypher_string;
           cout << "Please enter string with small letters to get encrypted form"<< endl;
           cin.ignore();
           getline (cin, cypher_string); // must always be immediately after the declared string... has some complications!
    
           int cypher_length = cypher_string.length();
    
           char cypher_input[cypher_length + 1];
    
           strcpy(cypher_input, cypher_string.c_str()); //Copy String to Character array.
    
           question2(cypher_input, cypher_length);
}

int Exercise1(char* arr, int x){ // recursion for getting capital letters


     // Loop for reading each character and updating them to be a capital letter ( in range of 65 - 90)
    
        int k = (int)arr[x] - 32;
        
        if (k >= 65 && k <= 90){ // Condition for when a character other than small letters is inputed.
            cout << (char)k;
        }
        else if (k == 32){ //Condition for spaces
            cout << (char)k;
        }
        else {
            cout << arr[x];
        }
            if (x == 0){ // Base Case
            return 0;
        } else {
            return Exercise1(arr, x - 1);
        }
}

void run_exercise1(){ // Code for getting capital letters
         cout << "PLease enter string to get capital letters" << endl;

            string input_word;
            cin.ignore();
            getline (cin, input_word); // can't use cin >> because it reads spaces as termintors

            int input_length = input_word.length(); // get string character length

            char input_word_char[input_length]; // declare new character for to change string to character; must be +1 because

            strcpy(input_word_char, input_word.c_str()); // Copying the string to the character arrray
    
            reverse(input_word_char, input_word_char + input_length); // Reverse Array cause recursion works backward
    
            Exercise1(input_word_char, input_length);
}

void print_array(int* arr, int x){ //Function for printing sorted array
    cout << "\nThe sorted array is: \n";
    
    for (int j = 0; j < x; j++){
        cout << arr[j] << " ";
    }
}

int swap_array(int* arr, int x){ //Recursion for swap in values of array
    
    for (int j = 0; j < x; j++){
        if (arr[j] > arr[j + 1]){
            swap(arr[j], arr[j + 1]);
        }
    }
    
    if (x == 1) // Base Case
        return 1;
    
    return swap_array(arr, x - 1);
}

void Exercise2(){ //Code for swapping array
    int array_sort[] = {78, 53, 38, 67, 673, 78, 7, 9, 13};
    int i = sizeof(array_sort)/sizeof(array_sort[0]);
    
    cout << "The array is: " <<endl;;
     for (int j = 0; j < i; j++){
        cout << array_sort[j] << " ";
    }
    swap_array(array_sort, i);
    print_array(array_sort, i);
}


int letter_occurance (char* arr, int x){ //Recursion for getting letter of occurance
    
    
    int count = 0;
    
    for (int j = 0; j <= x; j++){
        if (arr[x] == ' '){ // Condition for spaces
            return letter_occurance(arr, x - 1);
        }
        else if(arr[x] == arr[j]){ // Increment count for when same letter is detected.
            count++;
        }
    }
    cout << arr[x] << ":"<< count << endl;// Print character and occurance
    
    if (x == 0){// Base Case
         return 0;
    }else {
         return letter_occurance(arr, x - 1);
     }
    
}

void Exercise3(){ //Code for getting letter of occurance
    cout << "Please enter a string to get letter of occurance\n";
    string input_word;
    cin.ignore();
    getline (cin, input_word); // can't use cin >> because it reads spaces as termintors

    int i = input_word.length(); // get string character length

    char input_word_char[i]; // declare new character for to change string to character; must be +1 because
    int sort_array[i];

    strcpy(input_word_char, input_word.c_str()); //Copying the string to the character arrray

    reverse(input_word_char, input_word_char + i);
    letter_occurance(input_word_char, i - 1);
}

void HomeWork(){ //Switch Case for HomeWork
    int intx;
    char x, Exercise;
    intx = (int)x;
    

    do
        {
    cout << "\nChoose an option:" << endl;
    cout << "Press 1 for Exercise 1" << endl;
    cout << "Press 2 for Exercise 2" << endl;
    cout << "Press x for Exit" << endl;
    cin >> Exercise;

    switch (Exercise){
        
        case '1':
           run_question1();
           break;
        case '2':
           run_question2();
           break;
        case 'x':
           goto exit_loop;
           break;
        default:
           cout << "Invalid option";
           break;
    }
    }while (Exercise);
    exit_loop: ;
}

void Assignment(){ //Switch case for Assignment
    int intx;
    char x, Exercise;
    intx = (int)x;
    

    do
        {
    cout << "\nChoose an option:" << endl;
    cout << "Press 1 for Exercise 1" << endl;
    cout << "Press 2 for Exercise 2" << endl;
    cout << "Press 3 for Exercise 3" << endl;
    cout << "Press x for Exit" << endl;
    cin >> Exercise;

    switch (Exercise){
        case '1':
            run_exercise1();
            break;
        case '2':
            Exercise2();
            break;
        case '3':
            Exercise3();
            break;
        case 'x':
            goto exit_loop; //Skip line code to exit_loop;
            break;
        default:
            cout << "Invalid option";
    }
    }while (Exercise);
    exit_loop: ;
}


int main()
{

    
    char type;
    
    do{
    cout << "1 - For HomeWork\n2 - For Assignment\nX - exit"<< endl;
    cin >> type;

    switch(type){
        case '1':
           HomeWork();
           break;
        case '2':
           Assignment();
           break;
        case 'x':
        goto exit_loop; //Skip line to exit_loop to exit the switch case
           break;
    }
  
    }while(type);
    exit_loop: ;
    

    return 0;
}



