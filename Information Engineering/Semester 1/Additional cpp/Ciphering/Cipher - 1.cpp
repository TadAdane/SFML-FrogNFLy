/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int arr[] = {97, 98, 99, 100, 112, 110, 119, 120, 121, 122};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    int j = 25;
    do{ 
        int c = (arr[i] - 97)*2;
        int d = (122 - arr[i])*2;
        for (j; j > 0; j--){
            if (arr[i] <= 109){
                int a = arr[i] + (j - c);
                cout << a <<" ";
                i++;
                //j -= 2;
                //--j;
                break;
               
            }else if (arr[i] >= 109){
                int a = arr[i] - (j - d);
                cout << a <<" ";
                i++;
                // j -= 2;
                break;
            }
        }
    }while(i < n);

    return 0;
}

