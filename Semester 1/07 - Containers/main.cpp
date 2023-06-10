/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <unistd.h>

using namespace std;
using namespace
  std::chrono;

//exercise 1
void vec_back ()
{
  auto start = steady_clock::now ();
  int product = 1;


  cout << "Vector (emplace_back): ";
  vector <int> rand_vecb;
  srand (time (NULL));
  for (int i = 0; i < 100000; i++)
    {
      int input = rand () % 100001;
      rand_vecb.emplace_back (input);
    }



  auto end = steady_clock::now ();

  auto diff = end - start;
  cout << duration <double, milli> (diff).count () << " ms" << endl;
}

void vec_front ()
{
  auto start = steady_clock::now ();
  int product = 1;


  cout << "Vector (emplace_front): ";
  vector <int> rand_vecf;
  srand (time (NULL));
  for (int i = 0; i < 100000; i++)
    {
      int input = rand () % 100001;
      rand_vecf.insert (rand_vecf.begin (), input);
    }


  auto end = steady_clock::now ();

  auto diff = end - start;
  cout << duration <double, milli> (diff).count () << " ms" << endl;
}


void list_back ()
{
  auto start = steady_clock::now ();
  int product = 1;


  cout << "List (emplace_back): ";
  list <int> rand_listb;
  srand (time (NULL));
  for (int i = 0; i < 100000; i++)
    {
      int input = rand () % 100001;
      rand_listb.emplace_back (input);
    }

  auto end = steady_clock::now ();

  auto diff = end - start;
  cout << duration <double, milli> (diff).count () << " ms" << endl;
}

void list_front ()
{
  auto start = steady_clock::now ();
  int product = 1;


  cout << "List (emplace_front): ";
  list <int> rand_listf;
  srand (time (NULL));
  for (int i = 0; i < 100000; i++)
    {
      int input = rand () % 100001;
      rand_listf.emplace_front (input);
    }

  auto end = steady_clock::now ();

  auto diff = end - start;
  cout << duration <double, milli> (diff).count () << " ms" << endl;
}

void run_ass_q1(){
        vec_back ();
        vec_front ();
        list_back ();
        list_front ();
}


//exercise 2

float vec_average(vector <float> &x){
    float sum;
    sum = accumulate(x.begin(), x.end(), 0.0);
    float mean = sum/x.size();
    return mean;
}

void run_ass_q2(){
        vector <float> number;
    
        srand(time(NULL));
    
        for (int i = 0; i < 10; i++){
            float input = static_cast<float>(rand())/static_cast<float>(RAND_MAX / (10.0)) - 5.0;
            //cout << input;
            number.emplace_back(input);
            }
            
        cout << "The elements stored in the vector are: "<< endl;
    
        for (auto value : number){
            cout << value << " ";
            }
            
        cout << "\n" << "The averege of the elements stored in the vector is: " << vec_average(number) << endl;
    
}



//exercise 3
bool divide_5(int x){
    if (x%5 == 0){
        return true;
    }
    else{
        return false;
    }
} 
void run_ass_q3(){
    
    vector <int> divisible;
    
    srand(time(NULL));
    for (int i = 0; i < 10; i++){
        int input_ = rand()%100;
        divisible.emplace_back(input_);
    }
    
    cout << "The given members of the vector are: ";
    for (auto value : divisible){
        cout << value <<" ";
    }
    cout << "\n";
    int no_divisible = count_if(divisible.begin(), divisible.end(), divide_5);
    
    cout << "The number of divisible numbers by 5 is: " << no_divisible << endl;
}


//HomeWork
//Question 1

void run_question1(){
    vector <int> numbers;
    vector <int> non_prime;
    for (int i = 1; i < 11; i++){
        numbers.emplace_back(i);
    }
    
    for (int i = 0; i < numbers.size(); i++){
        if (numbers[i] < 2){
            continue;
        }
        else{
        for (int j = 2; j < numbers[i]; j++){
            if (numbers[i]%j == 0){
                non_prime.emplace_back(numbers[i]);
                break;
            }
        }
        }
    }
    
    cout << "The non_prime values between 1 and 10 are: ";
    for (auto input : non_prime){
        cout << input << " ";
    }
    
    cout << "\n";
}





// Question 2 
void sort_100(){
        vector <int> input_sort;
    
    srand(time(NULL));
    for (int i = 0; i < 100; i++){
        int input = rand()%100;
        input_sort.emplace_back(input);
    }
    auto start = steady_clock::now();
    
    for (int i = 0; i < input_sort.size(); i++){
       for (int j = 0; j < input_sort.size(); j++){
            if (input_sort[j] > input_sort[j + 1]){
                swap(input_sort[j], input_sort[j + 1]);
        }
       }
    }
    
    auto end = steady_clock::now();
    
    auto diff = end - start;
    cout << "The time it takes for bubble sort for 100 elements is: ";
    cout << duration <double, milli> (diff).count () << " ms" << endl;
}

void sort_1000(){
        vector <int> input_sort;
    
    srand(time(NULL));
    for (int i = 0; i < 1000; i++){
        int input = rand()%1000;
        input_sort.emplace_back(input);
    }
    auto start = steady_clock::now();
    
    for (int i = 0; i < input_sort.size(); i++){
       for (int j = 0; j < input_sort.size(); j++){
            if (input_sort[j] > input_sort[j + 1]){
                swap(input_sort[j], input_sort[j + 1]);
        }
       }
    }
    
    auto end = steady_clock::now();
    
    auto diff = end - start;
    cout << "The time it takes for bubble sort for 1000 elements is: ";
    cout << duration <double, milli> (diff).count () << " ms" << endl;
}

void sort_10000(){
        vector <int> input_sort;
    
    srand(time(NULL));
    for (int i = 0; i < 10000; i++){
        int input = rand()%10000;
        input_sort.emplace_back(input);
    }
    auto start = steady_clock::now();
    
    for (int i = 0; i < input_sort.size(); i++){
       for (int j = 0; j < input_sort.size(); j++){
            if (input_sort[j] > input_sort[j + 1]){
                swap(input_sort[j], input_sort[j + 1]);
        }
       }
    }
    
    auto end = steady_clock::now();
    
    auto diff = end - start;
    cout << "The time it takes for bubble sort for 10000 elements is: ";
    cout << duration <double, milli> (diff).count () << " ms" << endl;
}


void run_question2(){
    sort_100();
    sort_1000();
    sort_10000();
    sleep(2);
    cout <<"Conclusion: Yes, time grows linearly for bubble sort as number of elements grows." << endl;
}



void run_ass(){
    char type;
    while (type != 'x'){
        cout << "Please enter\n1 - for exercise 1\n2 - for exercise 2\n3 - for exercise 3\nx - back\n";
        cin >> type;
        switch(type){
            case '1':
              run_ass_q1();
              break;
            
            case '2':
              run_ass_q2();
              break;
              
            case '3':
              run_ass_q3();
              break;
        }
    }
}

void run_homework(){
    char type;
    while (type != 'x'){
        cout << "Please enter\n1 - for exercise 1\n2 - for exercise 2\nx - back\n";
        cin >> type;
        switch(type){
            case '1':
              run_question1();
              break;
              
            case '2':
              run_question2();
              break;
        }
    }
}

int main ()
{
    char type;
    while (type != 'x'){
        cout << "Please Enter\n1 - Assignment\n2 - HomeWork\nx - exit" << endl;
        cin >> type;
        switch(type){
            case '1':
            run_ass();
            break;
            
            case '2':
            run_homework();
            break;
        }
    }

  return 0;
}

// How do u run release mode in compilers otherthan QTcreator.


