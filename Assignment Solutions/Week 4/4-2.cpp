#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  sort(a.begin(),a.end());
  for(int i=0; i<=(right/2);i++)
  {
  	if(a[i]==a[i+(right/2)])
  		return 1;
  }
  return 0;
}
int linear(vector<int> &a, int left, int right)
{
	for(int i=0; i<right;i++)
	{	int count=0;
		for(int j=0; j <right;j++)
		{
			if(a[i]==a[j])
				count++;
		}
		if(count>a.size()/2)
			return 1;
	}
	return 0;
}
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size())) << '\n';

}
