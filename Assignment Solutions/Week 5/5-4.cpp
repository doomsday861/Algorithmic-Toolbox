#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
    ll dp[a.size()+1][b.size()+1];
 
  for(ll i=0; i <=(ll)a.size(); i++)
  {
    for(ll j=0; j<=(ll)b.size() ; j++)
    {
      if(i==0||j==0)
        dp[i][j]=0;
      
      else if(a[i-1]==b[j-1])
     {
      dp[i][j] = dp[i-1][j-1]+1;
      }
      else
    {
      dp[i][j] =max(dp[i-1][j],dp[i][j-1]);
    }
    }
  }
return dp[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
