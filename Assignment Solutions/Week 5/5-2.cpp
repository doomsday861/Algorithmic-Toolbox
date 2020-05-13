  /**
 * PRIMITIVE CALCULATOR
 * Kartikeya (doomsday861)
**/
#include<bits/stdc++.h>
#include<time.h>
#define ll long long
#define testcase ll t;cin>>t;while(t--)
#define timeb  auto start = high_resolution_clock::now(); 
#define timee auto stop = high_resolution_clock::now();auto duration = duration_cast<seconds>(stop - start);cout << "Time taken by function: "<<duration.count() << "seconds" << endl; 
using namespace std;
int main()
{
// #ifndef ONLINE_JUDGE 
// freopen("in.txt", "r", stdin); 
// freopen("output.ans", "w", stdout); 
// #endif 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
using namespace std::chrono;
//timeb
ll n;
cin >>n;
if(n==1)
{
    cout<<0<<'\n'<<1;
}
else if(n==2)
{
    cout<<1<<'\n'<<"1 2";
}
else if(n==3)
{
    cout<<1<<'\n'<<"1 3";
}
else
{
vector<ll> steps(n+1);
vector<ll>prev(n+1);
for(ll i=2;i<=n;i++)
{
  steps[i] = steps[i-1]+1;
  prev[i]=i-1;
  if(i%3==0)
  {
    if(steps[i/3]<steps[i])
    {
      steps[i]= steps[i/3] + 1;
      prev[i] = i/3;
    }
  }
  if(i%2==0)
  {
    if(steps[i/2]<steps[i])
    {
      steps[i]=steps[i/2] + 1;
      prev[i] = i/2;
    }
  }
}
cout<<steps[n]<<endl;
list<ll> ans;
for(ll i = n; i!=0; i = prev[i])
{
  ans.push_front(i);
}
for(auto it = ans.begin(); it!= ans.end();it++)
{
  cout<<*it<<' ';
}
}
//timee
    return 0; 
} 