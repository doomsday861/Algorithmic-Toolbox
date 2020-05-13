#include <iostream>
#include <string>
#define ll long long
using namespace std;

int edit_distance(const string &str1, const string &str2) {

	int dp[str1.length() + 1][str2.length() + 1] = {0};
	ll i =str1.length();
	ll j = str2.length();
	for(ll a=0; a <=i;a++)
	{
		for(ll b=0; b<=j;b++)
		{
			if(a==0)
			{
				dp[a][b] = b;
			}
			else if(b==0)
			{
				dp[a][b] = a;
			}
			else if(str1[a-1]==str2[b-1])
			{
				dp[a][b] = dp[a-1][b-1];
			}
			else
			{
				dp[a][b] = 1 + min(dp[a][b-1],min(dp[a-1][b],dp[a-1][b-1]));
			}
		}
	}
	// for(ll a=0; a <=i;a++)
	// {
	// 	for(ll b=0; b<=j;b++)
	// 	{
	// 		cout<<dp[a][b]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return dp[i][j];

  return 0;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
