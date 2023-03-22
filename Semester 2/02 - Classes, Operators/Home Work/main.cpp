#include <iostream>

#include "time.h"
using namespace std;

int main()
{
    Time t1(200);
    t1.print();
    cout << endl;
    // Time t2(36721);
    // t2.print();
    
    Time t2;
    cin >> t2;
    cout << t2;
    
    cout << endl;
    
    Time t3(3002);
    t3.print();
    
    cout << endl;
    Time sub;
    
    sub.print();
    cout << endl;
    sub = t2 - t1;
    
    sub.print();

    return 0;
}
