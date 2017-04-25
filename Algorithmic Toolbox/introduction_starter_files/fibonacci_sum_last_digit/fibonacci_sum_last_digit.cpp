#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int get_last_digit(long long int n){
	n%=60;
	if (n<=1)
		return n;
	int s_prev = 0;
	int s_curr = 1;
	for(int i=0;i<n-1;++i){
		int tmp = s_prev;
		s_prev = s_curr;
		s_curr = tmp + s_curr + 1;
		s_curr %= 10;
	}
	return s_curr;

}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    std::cout << get_last_digit(n);
}
