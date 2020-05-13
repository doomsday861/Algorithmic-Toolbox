#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int dis=0;
    // for(int i =1 ; i < stops.size() ; i++)
    // {
    // 	dis = max(stops[i]-stops[i-1],dis);
    // }
    // if(dis>tank)
    // return -1;
	int i=0;
	int c=0;
	int last=0;
	while(i<stops.size())
	{
		last = i;
		while(i<stops.size() && stops[i+1]-stops[last]<=tank)
			i++;
		if(last==i)
			return -1;
		if(i<=stops.size())
			c++;
	}
	 return (c-1);
	}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops;
    stops.push_back(0);
    for (size_t i = 0; i < n; ++i)
        {	int x;

        	cin >>x;
        	stops.push_back(x);
        }
    stops.push_back(d);
    if(m>d)
    	{
    		cout<<0<<"\n";
    		return 0;
    	}
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
