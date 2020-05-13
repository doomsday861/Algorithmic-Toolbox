#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp(int W, vector<int> w)
{
ll n = w.size();
vector<vector<ll>>value((n+1),vector<ll>(W+1));
for(ll i=0; i <=n;i++)
{
  for(ll j=0; j<=W;j++)
  {
    if(i==0||j==0)
      {
        value[i][j]=0;
      }
   else if(w[i-1]<=j)
    {
      value[i][j] = max(w[i-1]+value[i-1][j-w[i-1]],value[i-1][j]);
    }
    else
       value[i][j] = value[i-1][j];

  }
}
// for(ll i=0 ; i <=n;i++)
// {
//     for(ll j=0; j <=W;j++)
//     {
//         cout<<value[i][j]<<" ";
//     }
//     cout<<endl;
// }

return value[n][W];
}
int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
//  std::cout << optimal_weight(W, w) << '\n';
  cout<<dp(W,w)<<'\n';
}
