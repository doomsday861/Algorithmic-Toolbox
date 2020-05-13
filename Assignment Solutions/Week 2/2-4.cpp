#include <iostream>
#define ll long long
using namespace std;
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
ll gcd(ll a, ll b)
{
	if(!a)
		return b;
	gcd(b%a,a);
}
int main() {
  ll a, b;
  std::cin >> a >> b;
 // std::cout << lcm_naive(a, b) << std::endl;
  ll g = gcd(a,b);
  ll l = (a*b)/g;
  cout<<l<<endl;
  return 0;
}
