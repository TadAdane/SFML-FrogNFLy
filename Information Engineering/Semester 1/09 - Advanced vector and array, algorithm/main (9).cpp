#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void times_2(vector<vector<int>> &x){
    int no_row = x.size();
    for (int i = 0; i < no_row; i++){
        for (int j = 0; j < no_row; j++){
            x[i][j] = 2*x[i][j];
        }
    }

   
}


int main()
{
    const int no_col = 5;
    const int no_row = 5;
    
    vector <vector<int>> d_vec;
    for (int i = 0; i < no_row; i++){
        vector <int> row;
        for (int j = 0; j < no_col; j++){
            row.emplace_back(10*i + j);
        }
        d_vec.emplace_back(row);
    }
    // cout << d_vec[3][4];
  //  cout<<"Hello World";
  for (int i = 0; i < no_row; i++){
      for(int j = 0; j < no_col; j++){
          cout << d_vec[i][j] << "\t";
      }
      cout << "\n";
  }
  
  cout << "\n";
  const int no_col2 = 3;
  const int no_row2 = 3;
  
  srand(time(NULL));
  vector <vector<int>> e_vec;
  for (int i = 0; i < no_row2; i++){
      vector <int> row;
      int rand_num;
      for (int j = 0; j < no_col2; j++){
          rand_num= rand()%10;
          row.emplace_back(rand_num);
      }
      e_vec.emplace_back(row);
  }
  
//   cout << e_vec.size();

  for (int i = 0; i < no_row2; i++){
      for (int j = 0; j < no_col2; j++){
          cout << e_vec[i][j] <<"\t";
      }
      cout << "\n";
  }
  
  cout << "\n";
  
  times_2(e_vec);
  
  for (int i = 0; i < no_row2; i++){
      for (int j = 0; j < no_col2; j++){
          cout << e_vec[i][j] <<"\t";
      }
      cout << "\n";
  }
  

  return 0;
}


