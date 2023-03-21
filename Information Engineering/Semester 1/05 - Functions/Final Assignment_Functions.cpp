#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int Exercise1(int x, int y){
  int min_value = min(x, y);
  cout << "Minimum is: ";
  return min_value;
}

int Exercise2(int x, int y, int z, int w){

  int result_1 = min(x, y);
  int result_2 = min(result_1, z);
  int result_3 = min(result_2, w);
  cout << "Minimum is: " << endl;
  return result_3;
}

int Exercise3(int x, int y, int z){

  float product = x*y*z;

  float Geometric_mean = pow(product, (float)1/3);
  cout << Geometric_mean;
}

void Exercise4(int x){

    cout << round(x) << endl;

}

void Exercise5(int x){

    /*Declare integers*/
    int minN = 0, maxN = 100, e, f, d;

    //cin >> minN >> maxN;
    /*first loop, fist minimum integer increases by one until maximum integer is reached*/
    for (e = minN; e <= maxN; e++) {
    /*1 and 0 are neither prime nor composite*/
        if (e == 1 || e == 0)
            continue;
    /*second loop, initializing the divisor that increases by one until the maximum integer is reached*/
        for (f = 2; f <= e / 2; ++f) {
    /*If the remainder is 0, the code stops and re-runs by adding one to the integer*/
            if (e % f == 0) {
                d = 0;
                break;
    /*If the remainder is different from 0, Print that number*/
            }
            else if (e % f != 0){
                d = 1;
            }
        }
        if (d == 1){
            if (x == e){
                cout << "True\n";
            }
        }

        }
}
void Exercise6(int x){


    float pi = 3.14159;

    float volume;
    volume = (float(4) / float(3))*pi*x*x*x;
    cout << volume << endl;

    float area;
    area = 4*pi*x*x;
    cout << area;
}
int main()
{

    int num1, num2, num3, num4;

    char Exercise;
    char x;
//    intx = (int)x;

    do
        {
    cout << "\nChoose an option:" << endl;
    cout << "Press 1 for Exercise 1" << endl;
    cout << "Press 2 for Exercise 2" << endl;
    cout << "Press 3 for Exercise 3" << endl;
    cout << "Press 4 for Exercise 4" << endl;
    cout << "Press 5 for Exercise 5" << endl;
    cout << "Press 6 for Exercise 6" << endl;
    cout << "Press x for Exit" << endl;
    cin >> Exercise;

    switch (Exercise){

    case '1':
            cout << "Please inter two numbers to get minimum number"<< endl;
            cin >> num1;
            cin >> num2;
            cout << Exercise1(num1, num2);
            break;
      case '2':
          cout << "Please inter four numbers to get minimum number"<< endl;
        cin >> num1;
        cin >> num2;
        cin >> num3;
        cin >> num4;
        cout << Exercise2(num1, num2, num3, num4);
        break;
     case '3':
        cout << "Please enter three numbers to get their Geometric Sum"<< endl;
        int num7, num8, num9;
        cin >> num7;
        cin >> num8;
        cin >> num9;
        Exercise3(num7, num8, num9);
        break;
     case '4':
        cout << "Please enter the number to round it"<<endl;
        float round_number;
        cin >> round_number;
        Exercise4(round_number);
        break;
     case '5':
        int is_prime;
        cout << "Please enter number to know if it's a prime or not" << endl;
        cin >> is_prime;
        Exercise5(is_prime);
        break;
     case '6':
        cout << "Please enter the radius of the sphere to get area and volume\n";
        int r;
        cin >> r;
        Exercise6(r);
        break;
     case 'x':
           goto exit_loop;
           break;
     default:
           cout << "Invalid option";
           break;
    }
    }while (Exercise);

    exit_loop:;
    return 0;
}
