#include<bits/stdc++.h>
using namespace std;
using std::vector;
using std::string;
#define ll long long
bool duh(string a, string b)
{
  string ab = a.append(b);
  string ba = b.append(a);
  return ab.compare(ba)>0?1:0;
}
string largest_number(vector<string> a) {
  sort(a.begin(),a.end(),duh);
  string ans ="";
  for(ll i=0;i<a.size();i++)
    ans +=a[i];
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
