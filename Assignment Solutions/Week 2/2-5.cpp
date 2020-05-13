#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
ll fibfast(ll n, ll m)
{	
	ll fib[10001];
	fib[0]=0;
	fib[1]=1;
	ll len=0;
	//cout <<"0 1 ";
	for(ll i =2 ; i <=m*m;i++)
	{
		fib[i]= ((fib[i-1]%m) + (fib[i-2]%m))%m;
		len++;
//		cout<<fib[i]<<" ";
		if(fib[i]==1 && fib[i-1]==0)
		{
			break;
		}
		
	}
	// cout<<'\n';
	 //cout<<len<<endl;
	ll x = n%len;
	// cout<<x<<endl;
	// if(x<len)
	cout<<fib[x]%m<<'\n';
	
	return 0;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
   // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    fibfast(n,m);
}
