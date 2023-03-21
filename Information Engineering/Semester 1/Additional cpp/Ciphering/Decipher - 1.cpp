/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    string cypher_string = "abcdefghi zxcvb";
    //for (int j = 0; j < 26; j++){
        for (int i = 0; i < cypher_string.length(); i++){
            if (cypher_string[i] != ' '){
                char a = char(int(cypher_string[i] + 25 - 97)%26 + 97);
                cout << a;
            }else{
                cout << ' ';
            }
        }
        //cout << endl;
    //}

    return 0;
}

