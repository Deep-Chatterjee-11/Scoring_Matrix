#include <iostream>
using namespace std;

void solve(vector<vector<int> >& matrix, string str1, string str2, int m, int n){
  int match;
  int misMatch;
  int gapPenalty;

  cout << "Enter Match Score:" << endl;
  cin >> match;

  cout << "Enter MisMatch Score:" << endl;
  cin >> misMatch;

  cout << "Enter Gap Penalty Score:" << endl;
  cin >> gapPenalty;

  for(int i = 0; i <= 1; i++){
    for(int j = 0; j <= 1; j++){
      matrix[i][j] = 0;
    }
  }
  for(int i = 2; i < n; i++){
    matrix[i][0] = str2[i - 2];
  }
  for(int j = 2; j < m; j++){
    matrix[0][j] = str1[j - 2];
  }

  for(int i = 2; i < n; i++){
    matrix[i][1] = matrix[i - 1][1] + gapPenalty;
  }
  for(int j = 2; j < m; j++){
    matrix[1][j] = matrix[1][j - 1] + gapPenalty;
  }
  
  for(int i = 2; i < n; i++){
    for(int j = 2; j < m; j++){
      int vertical = matrix[i - 1][j] + gapPenalty;
      int horizontal = matrix[i][j - 1] + gapPenalty;
      int diagonal;

      if(matrix[i][0] == matrix[0][j]){
        diagonal = matrix[i - 1][j - 1] + match;
      }
      else{
        diagonal = matrix[i - 1][j - 1] + misMatch;
      }
      matrix[i][j] = max(horizontal, max(vertical, diagonal)); 
    }
  }

  for(int i = 1; i < n; i++){
    for(int j = 1; j < m; j++){
      cout << matrix[i][j] << "       ";
    }
    cout << endl;
  }
}

int main(){

  string str1 = "";
  string str2 = "";

  cout << "Enter the 1st sequence" << endl;
  cin >> str1;

  cout << "Enter the 2nd sequence" << endl;
  cin >> str2;

  int m = str1.length() + 2;
  int n = str2.length() + 2;

  vector<vector<int> > matrix(m, vector<int>(n, -1));

  solve(matrix, str1, str2, m, n);
  return 0;
}

