#include <iostream>
#include <vector>
using namespace std;
using std::vector;
#define ll long long

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;
    from %=60;
    to %=60;
    if(to<from)
    	to+=60;
    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
ll mysol(ll n, ll m)
{
	n = (n+2)%60;
	ll fib[n+1];
	fib[0]=0;
	fib[1]=1;
	for(ll i = 2; i <=n;i++)
	{
		fib[i] = ((fib[i-1]%10)+ (fib[i-2]%10))%10;
	}
	ll nr = fib[n]==0?9:(fib[n]%10-1);
	 m = (m+2)%60;
	 ll fibc[m+1];
	 fibc[0]=0;
	 fibc[1]=1;
	for(ll i = 2; i <=m;i++)
	{
		fibc[i] = ((fibc[i-1]%10)+ (fibc[i-2]%10))%10;
	}
	cout<<fibc[m]<<" dasd"<<endl;
	ll mr = fibc[m]==0?9:(fibc[m]%10-1);
	cout<<nr<<" "<<mr<<endl;
	return 0;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
