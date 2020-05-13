#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  // vector<ll> v;
  // vector<char> opr;
  // string tmp="";
  ll len = exp.length();
  len = (len+1)/2;
    ll dp[len][len];
  ll dp2[len][len];
 for (int i = 0; i < len; i++)
  {
    //The values on the main diagonal is just the number themselves
    dp[i][i] = std::stoll(exp.substr(2*i,1));
    dp2[i][i] = std::stoll(exp.substr(2*i,1));
  }

for(ll L = 0; L < len-1; L++)
{
  for(ll i=0; i < len-L-1; i++)
  {
    ll j = i+L+1;
    ll mi = LLONG_MAX;
    ll mx = LLONG_MIN;
    for(ll k = i; k< j; k++)
    {
      ll a = eval(dp[i][k],dp[k+1][j],exp[2*k+1]);
      ll b = eval(dp[i][k],dp2[k+1][j],exp[2*k+1]);
      ll c = eval(dp2[i][k],dp[k+1][j],exp[2*k+1]);
      ll d = eval(dp2[i][k],dp2[k+1][j],exp[2*k+1]);
      mi = min(mi,min(a,min(b,min(c,d))));
      mx = max(mx,max(a,max(b,max(c,d))));
    }
    dp[i][j] = mi;
    dp2[i][j]= mx;
  }
}
return dp2[0][len-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
