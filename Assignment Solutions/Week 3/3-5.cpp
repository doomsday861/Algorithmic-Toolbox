#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Segment {
  int start, end;
};
bool com(Segment a, Segment b)
{
  return b.end>a.end;
}
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
    sort(segments.begin(),segments.end(),com);
    points.push_back(segments[0].end);
    int cur = segments[0].end;
  for(int i =1; i <(int)segments.size();i++)
  {
    if((cur<segments[i].start) || (cur>segments[i].end))
    {
      cur = segments[i].end;
      points.push_back(cur);
    }
  }
  
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
 for (size_t i = 0; i < points.size(); ++i) {
   std::cout << points[i] << " ";
  }
}
