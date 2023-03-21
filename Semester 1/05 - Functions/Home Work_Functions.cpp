#include <iostream>

using namespace std;

int Question1(int x, int y, int z){
    int n = 3;
    float sum = 0;
    float arr[3] = {x, y, z};
    for (int i = 0; i < n; i++)
    sum = sum + (float)1 / arr[i];
	float mean = n / sum;
	return mean;
}
int Question2(int x, int y){
    int c;
    c = x%y;
    x = y;
    y = c;
    if (y == 0)
        return x;
    return Question2(x, y);
}
int Question3(int x, int y, int z){
    int d, e, f;
    d = x%y;
    x = y;
    y = d;
    if (y == 0){
        f = x;
        return x;
        }
        e = z%f;
        z = f;
        f = e;
        if (f == 0){
        return z;
        }
        //else{
          //  cout << 1 << endl;
        //}
    return Question3(x, y, z);
}
Question4 (char array_string){

//   cout << "Enter key: ";
//   cin >> key;
int array_key = 0;
int i, key = 4;
  for(i = 0; array_string[i] != '\0'; ++i){ // Loop runs until the String end is reached, '\0'

        input_char = array_string[i];

        if(input_char >= 'a' && input_char <= 'z'){
           array_key = input_char - 'a';
           cout << array_key << " ";
           new_char = input_char + (key - array_key);

           if(input_char > 'z'){
           new_char = input_char - 'z' + 'a' - 1;
           }

           array_string[i] = input_char;
        }
        else if(input_char >= 'A' && input_char <= 'Z'){
        new_char = input_char + (key - array_key);

        if(input_char > 'Z'){
        new_char = input_char - 'Z' + 'A' - 1;
        }

        array_string[i] = new_char;

        }
        }



}
int main()
{
    float arr[3];
	int n;
    int num1, num2, num3, num4;

       int intx;
    char x, Exercise;
    intx = (int)x;


    do
        {
    cout << "\nChoose an option:" << endl;
    cout << "Press 1 for Exercise 1" << endl;
    cout << "Press 2 for Exercise 2" << endl;
    cout << "Press 3 for Exercise 3" << endl;
    cout << "Press x for Exit" << endl;
    cin >> Exercise;

    switch (Exercise){

        case '1':
            cout << "Please enter 3 numbers to get their harmonic mean\n";
            cin >> num1 >> num2 >> num3;
            cout << "There harmonic mean is: " << Question1(num1, num2, num3);
        break;

        case '2':
            cout << "Please Enter two numbers to get GCD values of the numbers\n";
            cin >> num1;
            cin >> num2;
            cout << "GCD = " << Question2(num1, num2);
            break;

        case '3':
            cout << "Please enter 3 numbers to get GCD values of the numbers\n";
            cin >> num1 >> num2 >> num3;
            cout << "GCD = " << Question3(num1, num2, num3);
            break;

        case '4':
        char array_string[100], input_char, new_char;
        cout << "Enter a text to encrypt\n";
        cin.ignore();
        cin.getline(array_string, 100);
        cout << "Encrypted text is: " << Question4(array_string);
        case 'x':
        goto exit_loop; //Skip line code to exit_loop;
        break;
        default:
        cout << "Invalid option";
    }
    }while (Exercise);
    exit_loop: ;
    return 0;
}
