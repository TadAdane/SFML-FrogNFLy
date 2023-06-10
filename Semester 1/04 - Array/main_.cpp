#include <iostream>
#include <cstring>

using namespace std;

int Exercise1(){

    cout << "PLease enter string to get capital letters" << endl;

    string input_word;
    cin.ignore();
    getline (cin, input_word);

    int i = input_word.length(); //get string character length

    char input_word_char[i];

    //Copying the string to the character array
    strcpy(input_word_char, input_word.c_str());

    for (int j = 0; j < i; j++){ // Loop for reading each character and updating them to be a capital letter ( in range of 65 - 90)
        int k = (int)input_word_char[j] - 32;

        if (k >= 65 && k <= 90){ // Condition for when a character other than small letters is inputed.
            cout << (char)k;
        }
        else if (k == 32){ // Condition for character " "
            cout << (char)k;
        }
        else {
            cout << input_word_char[j];
        }
    }
    return 0;
}

void Exercise2(){
    cin.ignore();
    cout << "Please enter number of values you want to input\n(for declaration of size of array)\n"; // Couldn't declare an array with variable size
    int input_number, size_number;
    double sum_array = 0;
    double average_array;

    cin >> size_number; // size of array given by user

    cout << "Please enter values to get minimal, maximal and mean of the values" << endl;

    int array_number[size_number]; // Declare array
    for (input_number = 0; input_number < size_number; ++input_number){ //loop to fill array
        cin >> array_number[input_number];
    }

    cout <<  "The array is ";

    for (int output_number = 0; output_number < size_number; ++output_number){ // loop to print array
        cout << array_number[output_number] << " ";

       sum_array += array_number[output_number]; // Sumation of values of array
    }


    cout << "\nSum = " << sum_array << endl;

    average_array = sum_array / size_number; // Average of values of array
    cout << "Average = " << average_array << endl;

// Bubble sorting to get maximal and minimal value of array
    for (int x = 0; x < size_number; x++){
        for (int j = 0; j < size_number ; j++){
            if (array_number[j] > array_number[j + 1]){
                swap(array_number[j], array_number[j + 1]);
            }

        }
    }

    cout << "\nThe minimal value is " << array_number[0] << endl;
    cout << "The maximal value is " << array_number[size_number - 1] << endl;

}

void Exercise3(){
    cout << "Please enter a string\n";
    string input_word;
    cin.ignore();
    getline (cin, input_word);

    int i = input_word.length();

    char input_word_char[i];
    int sort_array[i];

    cout << "Please enter the letter you want to get number of occurance\n";

    char occurance;
    cin >> occurance; // User input the letter desired to get occurance value
    int count = 0;


    strcpy(input_word_char, input_word.c_str()); //Copying the string to the character array

    for (int j = 0; j < i; j++){
        int k = (int)input_word_char[j];

        if (k == (int)occurance){ // increase count by 1 is the desired letter is detected in the array
           count++;
        }
        sort_array[j] = (int)input_word_char[j];


    }


    cout << "The letter " << occurance << " occurs "<< count <<" times"<< endl;

    //Bubble sorting in ASCII order for alphabetical order.

    for (int x = 0; x < i; x++){
        for (int j = 0; j < i ; j++){
            if (sort_array[j] > sort_array[j + 1]){
                swap(sort_array[j], sort_array[j + 1]);
            }

        }


    }

    cout << "The alphabetical order of the letters in the string is: ";
    for (int n = 0; n < i+1; n++){ // Standard loop for output of array
        cout << (char)sort_array[n] << " ";
    }

}

int main()
{
    int Exercise, intx;
    char x;
    intx = (int)x;

    do
        {
    cout << "\nChoose an option:" << endl;
    cout << "Press 1 for Exercise 1" << endl;
    cout << "Press 2 for Exercise 2" << endl;
    cout << "Press 3 for Exercise 3" << endl;
    cout << "Press x for Exit" << endl;
    cin >> Exercise;

    if (Exercise == 1){
            Exercise1();
    } else if (Exercise == 2){
        Exercise2();
    } else if (Exercise == 3){
        Exercise3();
    } else if (Exercise == intx){
        break;
    } else {
        cout << "Invalid option" << endl;
        break;
    }
    }while (Exercise);

    return 0;
}
// Exercise 2 doesn't have specified size

