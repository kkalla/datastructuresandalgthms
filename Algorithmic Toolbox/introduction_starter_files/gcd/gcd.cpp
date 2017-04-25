#include <iostream>
#include <ctime>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int EuclidGCD(int a, int b){
	if(b==0)
		return a;
	if(a>b){
		int a_r = a%b;
		return EuclidGCD(b,a_r);
	} else {
		int b_r = b%a;
		return EuclidGCD(a,b_r);
	}
}

int main() {
  int a, b;
  std::cin >> a >> b;
  int start_s = clock();
  std::cout << EuclidGCD(a, b) << std::endl;
  int stop_s = clock();
  std::cout << (stop_s - start_s)/static_cast<double>(CLOCKS_PER_SEC)*1000;
  return 0;
}
