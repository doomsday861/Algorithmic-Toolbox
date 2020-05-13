#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> binary_search(const vector<ll> &a, vector<ll> b) {
  vector<ll> ans;
  for(ll i=0; i <(ll)b.size();i++)
    { 
  ll x = b[i];
  ll left = 0, right = (ll)a.size(); 
  ll mid = 0;
  while(left<=right)
  {
    mid = left+(right-left)/2;
    if(x>a[mid])
    {
      left = mid+1;
    }
    if(x<a[mid])
      right = mid-1;
    if(x==a[mid])
      break;
  }
  if(a[mid]==x)
    ans.push_back(mid);
  else
    ans.push_back(-1);
}
return ans;
}

vector<ll> linear_search(const vector<int> &a, vector<int> &b) {
  vector<ll> ans;
  for(int i=0; i<(int)b.size();i++)
  {
    int x = b[i];
    bool f=1;
    for (size_t i = 0; i < a.size(); ++i) {
      if (a[i] == x) {
        ans.push_back(i);
        f=0;
        break;
      }
  }
  if(f)
  ans.push_back(-1);
}
return ans;
}

int main() {
  // while(1)
  // { 
  //   srand(time(NULL));
  //   int n = rand()%10000;
  //   vector<int> a(n);
  // for (size_t i = 0; i < a.size(); i++) {
  //     int x =rand()%10000;
  //     a[i] = x ;
  // }
  // int m = rand()%100000;
  // vector<int> b(m);
  // for(int i=0; i<(int)b.size();i++)
  // {
  //   int x = rand()%10000;
  //   b[i] =x;
  // }
  // vector<int> v1 = linear_search(a,b);
  // vector<int> v2 = linear_search(a,b);
  // for(int i=0; i < (int)v1.size();i++)
  // {
  //   if(v1[i]!=v2[i])
  //   {
  //     cout<<"NO WA DUMB FUCK"<<endl;
  //     return 0;
  //   }
  // }
  // cout<<"OK "<<n<<endl;
  // }
  ll n;
  std::cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  ll m;
  std::cin >> m;
  vector<ll> b(m);
  for (ll i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  sort(a.begin(),a.end());
  vector<ll> v = binary_search(a,b);
  for (ll i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << v[i]<< ' ';
  }
  return 0;
}
