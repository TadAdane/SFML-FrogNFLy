#include <iostream>
#include <cstring>

using namespace std;

// void menu (){
//     cout << "Exercise - 1" << endl;
//     cout << "Exercise - 2" << endl;
//     cout << "Exercise - 3" << endl;
//     cout << "x - exit" << endl;
// }

int Exercise1(){

    cout << "PLease enter string" << endl;

    string input_word;
    cin.ignore();
    getline (cin, input_word); // can't use cin >> because it reads spaces as termintors

    int i = input_word.length(); // get string character length

    char input_word_char[i]; // declare new character for to change string to character; must be +1 because

    strcpy(input_word_char, input_word.c_str()); //Copying the string to the character arrray

    for (int j = 0; j < i; j++){ // Loop for reading each character and updating them to be a capital letter ( in range of 65 - 90)
        int k = (int)input_word_char[j] - 32;

        if (k >= 65 && k <= 90){ // Condition for when a character other than small letters is inputed.
            cout << (char)k;
        }
        else if (k == 32){
            cout << (char)k;
        }
        else {
            cout << input_word_char[j];
        }
    }
    return 0;
}

void Exercise2(){
    cout << "Please enter number of values you want to input\n";
    int input_number, size_number;
    double sum_array = 0;
   // double count = 0;
    double average_array;

    cin >> size_number;

    cout << "Please enter values" << endl;

    int array_number[size_number];
    for (input_number = 0; input_number < size_number; ++input_number){
        cin >> array_number[input_number];
    //    cout << array_number[input_number];
    }

    cout <<  "The array is ";

    //int sum;
    for (int output_number = 0; output_number < size_number; ++output_number){
        cout << array_number[output_number] << " ";

       sum_array += array_number[output_number];

    //     for (const double &n : array_number) {
    //   // cout << array_number[output_number] << "  ";

    // //  calculate the sum
    //     sum += array_number[output_number];

    // // count the 2. of array elements
    //     ++count;
    //     }

     //   cout << array_number[input_number];
    }


    cout << "\nTheir Sum = " << sum_array << endl;
   //find the average
    average_array = sum_array / size_number;
    cout << "Their Average = " << average_array << endl;

    cout << "\nThe minimal value is " << array_number[0] << endl;
    cout << "The maximal value is " << array_number[size_number - 1] << endl;


    // cout << array_number[3];
    // get line only uses strings
    // getline (cin , input_number);
    // int length_number = input_number.length();
    // cout << length_number << endl;
    // while (){
    // cin >> input_number;
    // int q2[j] = {input_number};
    // int size = sizeof(q2)/sizeof(q2[0]);
    // cout << q2[j];
    // j++;
    // }

  //  return 0;
}

void Exercise3(){
    cout << "Please enter a string\n";
    string input_word;
    cin.ignore();
    getline (cin, input_word); // can't use cin >> because it reads spaces as termintors

    int i = input_word.length(); // get string character length

    char input_word_char[i]; // declare new character for to change string to character; must be +1 because
    int sort_array[i];

    cout << "Please enter value to get number of occurance\n";

    char occurance;
    cin >> occurance;
    int count = 0;
  //  cout << (int)occurance <<endl;


    strcpy(input_word_char, input_word.c_str()); //Copying the string to the character arrray
    //cout << input_word_char[3];
    for (int j = 0; j < i; j++){ // Loop for reading each character and updating them to be a capital letter ( in range of 65 - 90)
        int k = (int)input_word_char[j];

        if (k == (int)occurance){ // Condition for when a character other than small letters is inputed.
            count++;
        }
                // for (int n = 65; n <= 122; n++){
        //             if (k == n){
        //                 count++;
        //                 break;
        //             }
        sort_array[j] = (int)input_word_char[j] ;




        //cout << k << endl;
        // for (int x = 0; x < i; x++){
        //     int sort_array[x] = {k};
        //     cout << sort_array[x] << " ";
        // }

        // int sort_array[j] = {k};

    }
        // for (int x = 0; x < 5; x++){
        //     for (int y = 0; y < 5 ; y++){
        //         if (array[y] > array[y + 1]){
        //             swap(array[y], array[y + 1];
        //         }

        //     }
        // }


    cout << "The letter " << occurance << " occurs "<< count <<" times"<< endl;
    // int sort_array[i];
    //     for (int j = 0; j < i; j++){
    //     sort_array[j] = {(int)input_word[j]};

    //         for (int i = 0; i < 5; i++){ // first loop for running more than one binary search

    //             for (int y = 0; y < 5 ; y++){ // second loop for running one binary search

    //                 if (sort_array[y] > sort_array[y + 1]){ // Conditional for elements of array to swap when previous is less than the later.
    //                      swap(sort_array[y], sort_array[y + 1]);
    //                 }
    //     // if (array[i] > array[i + 1]){
    //     //     swap(array[i], array[i + 1]);
    //     // }

    //             }
    //   // cout << array[i];
    //         }

    //     }


    for (int x = 0; x < i; x++){
        for (int j = 0; j < i ; j++){
            if (sort_array[j] > sort_array[j + 1]){
                swap(sort_array[j], sort_array[j + 1]);
            }

        }
    }
 // redeclaretion of i, doesn't matter because i isn't declared outside of the loop.
    cout << "The alphabetical order of the string is: ";
    for (int n = 0; n < 5; n++){ // Standard loop for output of array
        cout << (char)sort_array[n] << " ";
    }
   // return 0;
}

int main()
{
    char Exercise, intx;
    char x;

    do
        {
    cout << "\nChoose an option:" << endl;
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
