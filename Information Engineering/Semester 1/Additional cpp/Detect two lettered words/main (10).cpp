/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    // Declare string
    string example;
    
    // Declare subString
    string example_sub = "";
    getline(cin, example);
    
    //String length
    int n = example.length();
    
    //Declare character 
    char example_char[n];
    
    //copy string into character array
    strcpy(example_char, example.c_str());
    
    int d = 0;
    int c = 0;
    int count = 0;
    
    //loop for reading string
    for (int i = 0; i < n + 1; i++){
        
        //if blank space is detected or end of line create a subString.
        if ((example[i] == ' ') || (example[i] == '\0')){
            int e = i - c;
            example_sub = example.substr(d, e);
            d = i + 1;
            c = i;
            
            //if length of subString is 2 or 3(including spaces) increment count
            if (e == 2 || e == 3){
                count = count + 1;
            }
            cout << example_sub << endl;
        }
    }
    cout << "The number of words with two letters is: " << count;

    return 0;
}

