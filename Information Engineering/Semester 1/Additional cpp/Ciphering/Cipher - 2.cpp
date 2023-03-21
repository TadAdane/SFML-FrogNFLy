/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

void Question4 (char* arr, int x){
    int i = 0;
    int j = 25;
    do{ 
        int e = (int)arr[i];
        int c = (e - 97)*2;
        int d = (122 - e)*2;
        for (j; j > 0; j--){
            
            if (e <= 109){
                if (e == 32){
                cout << " ";
                }else{
                int a = e + (j - c);
                cout << (char)a;
                }
                i++;
                //j -= 2;
                //--j;
                break;
               
            }else if (e >= 109){
                int a = e - (j - d);
                cout << (char)a;
                i++;
                // j -= 2;
                break;
            }
        }
    }while(i < x);

}

int main()
{
    // string cypher_string = "abcdefghi zxcvb";
    // //for (int j = 0; j < 26; j++){
    //     for (int i = 0; i < cypher_string.length(); i++){
    //         if (cypher_string[i] != ' '){
    //             char a = char(int(cypher_string[i] + 25 - 97)%26 + 97);
    //             cout << a;
    //         }else{
    //             cout << ' ';
    //         }
    //     }
        //cout << endl;
    //}
    string cypher_string;
    getline (cin, cypher_string); // must always be immediately after the declared string... has some complications!
    
    int n = cypher_string.length();
    
    char cypher_input[n + 1];
    
    
    
    strcpy(cypher_input, cypher_string.c_str());
    //int i;
    // for (i = 0; i < sizeof(cypher_input); i++) {
    //     cypher_input[i] = cypher_string[i];
    //     cout << cypher_input[i];
    // }
    
    // for (int i = 0; i < n; i++){
    //     cout << cypher_input[i] << " ";
    // }
    //cout << cypher_input[2];
    
    Question4(cypher_input, n);
     return 0;
}


