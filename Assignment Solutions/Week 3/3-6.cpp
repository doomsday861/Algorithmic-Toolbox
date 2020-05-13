#include<bits/stdc++.h>
using namespace std;
using std::vector;
#define ll long long
vector<int> optimal_summands(int n) {
  vector<int> summands;
  ll i =1;
  while((i*(i+1)/2)<=n)
  {
  	i++;
  }
  i--;
  ll s=0;
  for(ll j = 1; j <=i;j++)
  {
  	if(j==i)
  	{
  		summands.push_back(n-s);
  		continue;
  	}
  	s+=j;
  	summands.push_back(j);
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
