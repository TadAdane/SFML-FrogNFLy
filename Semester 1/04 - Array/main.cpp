#include <iostream>
#include <cmath>
#include <iomanip> // for setprecision

using namespace std;

void Exercise1(){
   float random_integer;
//int lowest=1, highest=10;
//int range=(highest-lowest)+1;
float random_array [20];
srand(time(NULL));  // for random_integer to generate different integers at every run
cout << "The array is: ";
for (int i = 0; i < 20; i++){

random_integer = 10.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(100.0-10.0))); //static_cast: for declaring type

random_array[i] = {random_integer};
cout << setprecision(3) << random_array[i]<<" "; // set precision (3): 3 significant numbers
}

//cout<<1.2 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(3.4-1.2)));


 for (int i = 1; i < 20; i++) {
    float key = random_array[i];
    int j = i - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < random_array[j] && j >= 0) {
      random_array[j + 1] = random_array[j];
      --j;
    }
    random_array[j + 1] = key;
  }


  cout << "\nTHe sorted array is: ";
    for (int i = 0; i < 20; i++)
        cout << random_array[i] << " " ;

//return 0;
}

void Exercise2(){

}
void Exercise3(){
        cout << "Please enter string\n";

    string str;
    cin.ignore();
    getline(cin, str);
    int i = str.length() - 1; // because counting array starts from zero.
	//cout << i;
	int start, end = i + 1;
	string result = "";

	while (i >= 0) { // i = 10
		if (str[i] == ' ') { // so i = 10,9,8,7,..5,..3,2,..0 is jumped, code runs on i = 6, 4, 1
			start = i + 1; // start equals 7, 5 ,2
			while (start != end) // str[7,8,9,10],
				result += str[start++]; // Geek

			result += ' ';

			end = i;// end = 6
		}
		i--;
	}
	//cout << end << endl;
	start = 0;
 	while (start != end)
 		result += str[start++];

	cout << result << endl;
}
void Exercise4(){
    cout << "Please enter string\n" << endl;
    string str1;
    cin.ignore();
    getline(cin, str1);
    cout << "Enter word to get occurance\n" << endl;
	string str2;


	getline(cin,str2);
    bool flag = false;
	for (int i = 0; i < str1.length(); i++) {
		if (str1.substr(i, str2.length()) == str2) {
			cout << i << " ";
			flag = true;
		}
	}

	if (flag == false)
		cout << "NONE";
}
int main()
{
     char Exercise, intx;
    char x;

    do
        {
    cout << "Choose an option:" << endl;
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
    } else if (Exercise == '4'){
        Exercise4();
    } else if (Exercise == 'x'){
        break;
    } else {
        cout << "Invalid option" << endl;
    }
    }while (Exercise);
    return 0;
}
