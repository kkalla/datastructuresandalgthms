#include <iostream>

int main(){
  int a = 0;
  int b = 0;
  int sum = 0;
  std::cin >> a;
  std::cin >> b;
  if(a<0 | b>9){
  	std::cout << "Constraints : 0<=a,b<=9";
  	return 1;
  }
  sum = a + b;
  std::cout << sum;
  return 0;
}
