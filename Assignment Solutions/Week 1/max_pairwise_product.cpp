#include<bits/stdc++.h>
#include<time.h>
#define ll long long
#define testcase ll t;cin>>t;while(t--)
#define timeb  auto start = high_resolution_clock::now(); 
#define timee auto stop = high_resolution_clock::now();auto duration = duration_cast<seconds>(stop - start);cout << "Time taken by function: "<<duration.count() << "seconds" << endl; 
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
using namespace std::chrono;
//timeb
 ll n;
 cin>>n;
 vector<ll> v;
 ll m = 0;
 ll m2 = 0;
 for(ll i =0;i<n;i++)
 {
 	ll x;
 	cin >> x;
 	v.push_back(x);
 }
 sort(v.begin(),v.end());
 cout<<v[n-1]*v[n-2]<<endl;
//timee
    return 0; 
} 