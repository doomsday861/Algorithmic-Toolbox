#include <iostream>
#define ll long long
using namespace std;
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
long long fibfast(ll n)
{
	n = (n+2)%60;
	ll fib[n+1];
	fib[0]=0;
	fib[1]=1;
	for(ll i = 2; i <=n;i++)
	{
		fib[i] = ((fib[i-1]%10)+ (fib[i-2]%10))%10;
	}
	if(fib[n]==0)
		return 9;
	return(fib[n]%10-1);
}

int main() {
    long long n = 0;
    std::cin >> n;
    cout<<fibfast(n);
}
