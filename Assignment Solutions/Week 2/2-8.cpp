#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;
    n = n%60;
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 2; i <=n; ++i) {
        int x = (previous+current)%10;
        previous = current;
        current = x;
    }

    return current % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
  	int x = fibonacci_sum_squares_naive(n%60);
  	int y = fibonacci_sum_squares_naive((n+1)%60);
  	int ans = (x*y)%10;
    std::cout <<ans;
}
