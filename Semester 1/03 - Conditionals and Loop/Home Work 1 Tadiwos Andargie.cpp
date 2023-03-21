#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    /*Question number 1, Area and Perimeter of Rectangle*/
    int width = 0, length = 0;
    cout << "Please insert the width and length of the rectangle" << endl;
    cin >> width >> length;
    cout << "Area is equals to " << width*length << "" << endl;
    cout << "Perimeter is equal to " << 2*width + 2*length << endl;

    /* Area, Perimeter and Angles of Triangle*/
    float sideA = 0.0, sideB = 0.0, sideC = 0.0;
    cout << "Please insert the lengths of the 3 sides of the triangle" << endl;
    cin >> sideA >> sideB >> sideC;
    int p = sideA + sideB + sideC;
    cout << "Perimeter is equal to " << p << endl;
    cout << "Area is equals to " << sqrt(p*(p-sideA)*(p-sideB)*(p-sideC)) << "" << endl;
    cout << "The angles of the triangles are " << endl;
    float m = ((((sideA*sideA) + (sideB*sideB)) - (sideC*sideC)))/(2*sideA*sideB);
    float n = ((((sideC*sideC) + (sideB*sideB)) - (sideA*sideA)))/(2*sideC*sideB);
    float o = ((((sideA*sideA) + (sideC*sideC)) - (sideB*sideB)))/(2*sideA*sideC);
    int t = (acos(m)/3.1415)*180, s = (acos(n)/3.1415)*180, r = (acos(o)/3.1415)*180;
    cout << t << " degrees" << endl;
    cout << s << " degrees" << endl;
    cout << r << " degrees" << endl;

    /*Question number 2, Perform Addition, Substraction, Multiplication, Division*/
    /*Integer type*/
    int numx = 0, numy = 0;
    cout << "Please enter two numbers /for integer types/ " << endl;
    cin >> numx >> numy;
    cout << "sum " << numx + numy << endl;
    cout << "difference " << numx - numy << endl;
    cout << "Product " << numx*numy << endl;
    cout << "Quotient " << numx/numy << endl;

    /*Float type*/
    float num1 = 0.0, num2 = 0.0;
    cout << "Please enter two numbers /for float types/ " << endl;
    cin >> num1 >> num2;
    cout << "Sum " << num1 + num2 << endl;
    cout << "Difference " << num1 - num2 << endl;
    cout << "Product " << num1*num2 << endl;
    cout << "Quotient " << num1/num2 << endl;

    /*Question number 3, Perform pre and post incrementation*/
    int numA = 0;
    cout << "Please enter one number" << endl;
    cin >> numA;
    cout << "pre-incrementation " << ++numA << endl;
    cout << "pre-decrementation " << --numA << endl;
    cout << "post-incrementation " << numA++ << endl;
    cout << "post-decrementation " << numA-- << endl;

    /*Question number 4*/
    /*Current date is considered to be 12.10.2015*/
    /*There's some problem with the example provided in the question number 4. Jan was born in 1970 but he was born 30 years ago???*/
    string firstName, secondName, fathersName, mothersName, mothersFamily, birthPlace;
    int birthYear = 0, birthMonth = 0, birthDay = 0;
    float fatherAge = 0.0, motherAge = 0.0;
    cout << "Please enter your First name and Second name respectively" << endl;
    cin >> firstName >> secondName;
    cout << "Please enter your Father's name and Father's age respectively" << endl;
    cin >> fathersName >> fatherAge;
    cout << "Please enter your Mother's name, Mother's Family name and Mother's age respectively" << endl;
    cin >> mothersName >> mothersFamily >> motherAge;
    cout << "Please enter your Birth place, Birth year, month and day respectively" << endl;
    cin >> birthPlace >> birthYear >> birthMonth >> birthDay;
    cout << "Citizen " << firstName << " " << secondName << " was born in " << birthPlace << " " << 2015 - birthYear << " years ago. ";
    cout << "His mother, Mrs " << mothersName << " (of " << mothersFamily << ")" << " was " << birthYear - (2015 - motherAge);
    cout << " years old then and his father " << birthYear - (2015 - fatherAge) << " years old." <<  endl;

    cout << secondName << " " << firstName << " till 12.10.2015 lived approximately " << (2015 - birthYear)*365 + birthMonth*30 + birthDay << "days." << endl;
    cout << "His father is " << fatherAge/(2015 - birthYear) << " times older than him and mother " << motherAge/(2015 - birthYear) << " times." << endl;
    cout << "It's is and old family, because together they have " << (2022 - birthYear) + fatherAge + motherAge << " years." << endl;

    return 0;
}
