/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    string crypt_text = "zkdw zrxog eh d";
    for (int j = 0; j < 26; j++){
        for (int i = 0; i < crypt_text.length(); i++){
            if (crypt_text[i] != ' '){
                char a = char(int(crypt_text[i] + j - 97)%26 + 97);
                cout << a;
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}

