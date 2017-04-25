#include <iostream>
#include <ctime>


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_fibonacci_huge(unsigned long int n, int m){
	if(n<=1)
		return static_cast<int> (n);
	int len=2;
	int prev = 0;
	int curr = 1;
	while(1){
		int tmp1=prev;
		prev = curr;
		curr = tmp1 + curr;
		curr %= m;
		if(len!=2&&prev==0&&curr==1)
			break;
		if(len>n)
			break;
		len++;
	}
	int mod;
	if(len>n){
		return prev;
	} else{
		mod  = static_cast<int>(n%static_cast<unsigned long int>(len-1));
		prev = 0;
		curr = 1;
		if(mod<=1)
			return mod;
		for(int i=0;i<mod-1;++i){
			int tmp=prev;
			prev = curr;
			curr = tmp+curr;
			curr %= m;
		}
		return curr;
	}

		



}


int main() {
    unsigned long int n;
    int m;
    std::cin >> n >> m;
    int start_s=clock();
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    int stop_s=clock();
    std::cout<<"time = "<<(stop_s-start_s)/CLOCKS_PER_SEC;
}
