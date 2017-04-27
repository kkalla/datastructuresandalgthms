#include <iostream>

int get_change(int m) {
  int coins[3]={10,5,1};
  int n=0;
  while(m){
	  
  if(m/coins[0]){
	  n=m/coins[0];
	  m%=coins[0];
  }else if(m/coins[1]){
	  n+=m/coins[1];
	  m%=coins[1];
  }else{
	  n+=m/coins[2];
	  m%=coins[2];
  }
  }
  if(m!= 0)
	  std::cout<<"Error";
  else
	  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
