#include <iostream>
#include <ctime>
#include <cstdlib>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int EclidGCD(int a, int b){
	if(b==0)
		return a;
	if(a>b){
		int a_r = a%b;
		return EclidGCD(b,a_r);
	} else {
		int b_r = b%a;
		return EclidGCD(a,b_r);
	
	}
}

long long lcm_fast(int a, int b){
	int gcd = EclidGCD(a,b);
	long long lcm = a*b/gcd;
	return lcm;
}


int main() {
	int a;
	int b;
	while(1){
		a = rand()%1000000000+1;
		b = rand()%1000000000+1;
		int start_s = clock();
		long long lcm = lcm_naive(a,b);
		int stop_s = clock();
		int exe_time = (stop_s - start_s)/(double)(CLOCKS_PER_SEC);
		if(exe_time >1)
			break;
	}
	std::cout <<"exceed time : " << "lcm("<<a<<", "<<b<<")";

  //int a, b;
  //std::cin >> a >> b;
  //std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
