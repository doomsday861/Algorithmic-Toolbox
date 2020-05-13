#include <bits/stdc++.h>
using namespace std;
long long int ar[1001];
int get_change(int m) {

  return m / 4;
}

int main() {
	ar[0]=0;
	for(int i=1; i <1001;i++)
		ar[i] = INT_MAX;
	int coin[3]={1,3,4};
	ar[1]=1;
	ar[2]=2;
	ar[3]=1;
	ar[4]=1;
	for(int i=5;i<=1000;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(coin[j]<=i)
			{
				long long int sub = ar[i-coin[j]];
				if(sub!=INT_MAX && sub+1<=ar[i] )
				{
					ar[i] =sub+1;
				} 
			}
		}
	}
	int m;
  std::cin >> m;
  if(m==1||m==3||m==4)
  	std::cout<<1<<'\n';
  else
  std::cout << ar[m] << '\n';
}
