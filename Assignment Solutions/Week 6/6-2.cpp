#include<bits/stdc++.h>
using namespace std;
#define ll long long
using std::vector;
bool ans(vector<int> &A, ll subsum[],bool vis[], ll s,ll N,ll cur, ll lim)
{
	if(subsum[cur]==s)
		{
			if(cur == 1)
				return true;

			return ans(A,subsum,vis,s,N,cur+1,N-1);
		}
	for(ll i =lim;i >=0;i--)
	{
		if(vis[i])
			continue;
		ll tmp = subsum[cur] + A[i];

		if(tmp <= s)
		{
			vis[i]= 1;
			subsum[cur] +=A[i];
			bool n = ans(A,subsum,vis,s,N,cur,i-1);
			vis[i]=0;
			subsum[cur] -=A[i];
			if(n)
			{
				return true;
			}
		}
	}

	return false;

}
bool partition3(vector<int> &A) {
  int sum=0;
  int s=0;
  for (int i = 0; i <(int) A.size(); ++i)
  {
  	sum +=A[i];
  }
  if(sum%3!=0)
  	return 0;
  bool vis[A.size()+1];
  ll N = A.size();
  memset(vis,0,sizeof(vis));
  s = sum/3;
  ll subsum[3]={0};
  subsum[0] = A[N-1];
  vis[N-1]=1;
  return ans(A,subsum,vis,s,N,0,N-1);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
