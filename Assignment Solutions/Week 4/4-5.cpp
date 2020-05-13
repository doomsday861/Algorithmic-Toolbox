#include<bits/stdc++.h>
using namespace std;
bool lol(pair<int,int> a, pair<int,int> b)
{	
	// if(a.first==b.first)
	// {
	// 	if(a.second==0 && b.second==1)
	// 		return true;
	// 	if(a.second==0 && b.second==)
	// }
	return b.first>a.first;
}

unordered_map<int,int> fast_count_segments(vector<pair<int,int>> v,vector<int>points)
{	unordered_map<int,int> umap;
	int l=0;
	int r=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i].second==0)
			l++;
		if(v[i].second==2)
			r++;
		if(v[i].second==1)
			umap.insert({v[i].first,l-r});
	}
	return umap;
	// for(int i=0;i<(int)points.size();i++)
	// {
	// 	int x = points[i];
	// 	int low =0;
	// 	int high = v.size()-1;
	// 	int mid=0;
	// 	while(high>=low)
	// 	{
	// 		 mid = low + (high-low)/2;
	// 		if(v[mid].first< x)
	// 		{
	// 			low = mid+1;
	// 		}
	// 		if(v[mid].first > x)
	// 		{
	// 			high = mid-1;
	// 		}
	// 		if(v[mid].first==x)
	// 			{
	// 				if(v[mid].second == 0)
	// 					low = mid+1;
	// 				if(v[mid].second == 2)
	// 					high = mid-1;
	// 				if(v[mid].second== 1 )
	// 					{
	// 						break;
	// 					}
	// 			} 
	// 	}
	// 	int ansi=0;
	// 	if(v[mid].first==x && v[mid].second==1)
	// 		ansi = mid;
	// 	if(v[low].first==x && v[low].second==1)
	// 		ansi = low;
	// 	if(v[high].first==x && v[high].second==1)
	// 		ansi = high;
	// 	// int ansi=0;
	// 	// for(int i=0; i <(int)v.size();i++)
	// 	// {
	// 	// 	if(v[i].first == x && v[i].second == 1)
	// 	// 		{
	// 	// 			ansi =i;
	// 	// 			break;
	// 	// 		}
	// 	// }
	// 	int l =0;
	// 	int r= 0;
	// 	// for(int i=0;i<(int)v.size();i++)
	// 	// {
	// 	// 	cout<<v[i].first<<" "<<v[i].second<<endl;
	// 	// }
	// 	// cout<<endl; 
	// 	// cout<<endl<<ansi<<endl<<endl;
	// 	for(int j=ansi; j>=0;j--)
	// 	{
	// 		if(v[j].second==0)
	// 			l++;
	// 		if(v[j].second==2)
	// 			r++;
	// 	}
	// 	cnt.push_back(l-r);
	// }
	//return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
// 	srand(time(NULL));
// 	while(1)
// 	{
// 		int n = rand()%100;
// 		int m = rand()%100;
// 		  vector<pair<int,int>> v;
//  		 vector<int> starts(n), ends(n);
//   		for (size_t i = 0; i < starts.size(); i++) {
//  			starts[i] = rand()%1000;
//  			ends[i] = rand()%10000;
//  		cin >> starts[i] >> ends[i];
//  		v.push_back(make_pair(starts[i],0));
//  		v.push_back(make_pair(ends[i],2));
//   }
//   vector<int> points(m);
//   for (size_t i = 0; i < points.size(); i++) {
//     std::cin >> points[i];
//     v.push_back(make_pair(points[i],1));
//   }  
//   sort(v.begin(),v.end());
//   vector<int> ans1 = naive_count_segments(starts,ends,points);
//   vector<int>ans2 = fast_count_segments(v,points);
//   for(int i=0; i<ans1.size();i++)
//   {
//   	if(ans1[i]!=ans2[i])
//   	{
//   		cout<<" W A ";
//   		return 0;
//   	}
//   }
//   cout<<"O K  "<<n<<"    "<<m<<endl;
// }
  int n, m;
  std::cin >> n >> m;
  vector<pair<int,int>> v;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
 	std::cin >> starts[i] >> ends[i];
 		v.push_back(make_pair(starts[i],0));
 		v.push_back(make_pair(ends[i],2));
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
    v.push_back(make_pair(points[i],1));
  }  
  sort(v.begin(),v.end());
  unordered_map<int,int> cnt = fast_count_segments(v,points);
  for (size_t i = 0; i < points.size(); i++) {
   		{
   			auto it =cnt.find(points[i]);
   			cout<<it->second<<' ';
   		}
  }
}
