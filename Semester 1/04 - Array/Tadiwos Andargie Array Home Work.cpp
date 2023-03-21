#include <iostream>
#include <cmath>
#include <iomanip> // for setprecision
#include <string> // for substr() substring
using namespace std;

void Exercise1(){

     float random_integer;
     float random_array [20];

     srand(time(NULL));  // for random_integer to generate different integers at every run

     cout << "The array is: ";
     for (int i = 0; i < 20; i++){ // Loop for filling up integers

         //static_cast: for declaring type (to change from int to float)
         random_integer = 10.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(100.0-10.0))); // Generate random random integer

         random_array[i] = {random_integer};
         cout << setprecision(3) << random_array[i]<<" "; // set precision (3): 3 significant numbers
       }


// Loop for insertion sorting
 for (int i = 1; i < 20; i++) {

    float k = random_array[i]; // Get each array value as k
    int j = i - 1;

    for (j; k < random_array[j] && j >= 0; --j) { // Loop for sorting, run when k (random_array[i]) is less than random_array[j]
         random_array[j + 1] = random_array[j]; // exchange array
        }
    random_array[j + 1] = k; // random_array[j + 1] becomes the random_array[j] in loop
  }

 cout << "\nThe sorted array is: ";

 for (int i = 0; i < 20; i++) // Loop for printing array
    cout << random_array[i] << " " ;


}

void Exercise2(){
    int binary_array[19];
    int random_integer;

    srand(time(NULL));
    cout << "The array is: ";
    for (int i = 0; i < 20; i++){ // Loop for filling up integers


         random_integer = 10.0 + rand() % 100; // Generate random random integer

         binary_array[i] = {random_integer};

      }

      // Bubble sort for array

    for (int x = 0; x < 20; x++){
        for (int j = 0; j < 20 ; j++){
            if (binary_array[j] > binary_array[j + 1]){
                swap(binary_array[j], binary_array[j + 1]);
            }

        }
    }
    // print array
    for (int x = 1; x < 20; x++){
        cout << binary_array[x] <<" ";
    }

    int low = 0;
    int high = 19;

    cout << "\nPlease enter number you want find" <<endl;
    int binary_number;
    cin >> binary_number;

    //Loop for Binary sort
     while (high - low > 1) {
		int mid = (high + low) / 2;
		if (binary_array[mid] < binary_number) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
    // Condition for binary sorting
	}
	if (binary_array[low] == binary_number) {
		cout << "Is located at array: " << low << endl;
	}
	else if (binary_array[high] == binary_number) {
		cout << "Is located at array: "<< high << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
}
void Exercise3(){

    int reverse_size;
    string reverse_output = "";

    cout << "Input string\n";

    string reverse_array;
    cin.ignore(); //Ignore previous input characters
    getline (cin, reverse_array);

    reverse_size = reverse_array.length();
    int j, k = reverse_size + 1;


    while(reverse_size >= 0){ // Loop for detecting " " character.
        if (reverse_array[reverse_size] == ' '){
            j = reverse_size + 1;

            while (j != k){ //Loop for exchanging words back to forward
            reverse_output += reverse_array[j++];
            }

            reverse_output += ' ';
            k = reverse_size;
        }
        --reverse_size;
    }
 	j = 0; // For re use of J

 	while (j != k) // Standard loop for output
 		reverse_output += reverse_array[j++];

 	cout << reverse_output << endl;
}
void Exercise4(){

    cout << "Please enter string" << endl;

    string occurance_string;
    cin.ignore();
    getline(cin, occurance_string);

    cout << "Enter word to get occurance" << endl;
	string occurance_word;

	cin >> occurance_word;

    bool flag = false;
	for (int i = 0; i < occurance_string.length(); i++) { // Loop for declaring substrings and count occurance of substring
		if (occurance_string.substr(i, occurance_word.length()) == occurance_word) {
			cout << i << " ";
			flag = true;
		}
	}

	if (flag == false) //Condition if the desired word isn't present
		cout << "Not Found";
}
void Exercise5(){

    cout << "Please Enter string\n";
    string replace_array;
    cin.ignore();
    getline(cin , replace_array);

    cout << "Enter word you want to replace\n";

    string old_word;
    cin >> old_word;
    int i = old_word.length();// Length of old word, to be replaced

    cout << "Please enter new word\n";

    string new_word;// User entered word for replacement
    cin >> new_word;

    size_t pos = replace_array.find(old_word);// Locate old word position
    string new_array = replace_array.replace(pos, i, new_word);

    cout << new_array << endl;
}

int main()
{
    int Exercise, intx;
    char x;
    intx = (int)x;

    do
        {
    cout << "\nChoose an option:" << endl;
    cout << "Press 1 for Exercise 1" << endl;
    cout << "Press 2 for Exercise 2" << endl;
    cout << "Press 3 for Exercise 3" << endl;
    cout << "Press 4 for Exercise 4" << endl;
    cout << "Press 5 for Exercise 5" << endl;
    cout << "Press x for Exit" << endl;
    cin >> Exercise;

    if (Exercise == 1){
            Exercise1();
    } else if (Exercise == 2){
        Exercise2();
    } else if (Exercise == 3){
        Exercise3();
    } else if (Exercise == 4){
        Exercise4();
    } else if (Exercise == 5){
        Exercise5();
    } else if (Exercise == intx){
        break;
    } else {
        cout << "Invalid option" << endl;
        break;
    }
    }while (Exercise);

    return 0;
}
