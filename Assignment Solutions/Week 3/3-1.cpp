#include <iostream>

int get_change(int m) {
 int count=0;
  while(m!=0)
  {
  	while(m>=10)
  		{
  			m -=10;
  			count++;
  		}
  		while(m>=5)
  		{
  			m -=5;
  			count++;
  		}
  		count +=m;
  		m=0;
  }
  return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
