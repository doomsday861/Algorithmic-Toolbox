#include<bits/stdc++.h>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int x= a.size()+1;
  int y= b.size()+1;
  int z =c.size() + 1;
  int dp[x][y][z];
  for(int i=0; i < x; i++)
  {
    for(int j=0; j < y; j++)
    {
      for(int k=0; k < z; k++)
      {
        if(i==0 || j==0 || k==0)
          dp[i][j][k]=0;
        else if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
        {
          dp[i][j][k] = dp[i-1][j-1][k-1]+1;
        }
        else
        {
          dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
        }
      }
    }
  }
  return dp[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
