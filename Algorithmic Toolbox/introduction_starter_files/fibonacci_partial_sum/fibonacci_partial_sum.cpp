#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int get_last_digit_of_partialSum(long long from,long long to){
	from%=60;
	to%=60;
	if(to<from<0){
		std::cout<<"Error : Wrong input";
		return 1;
	}
	if(to<=1)
		return to;
	
	int to_n = 0;
	int to_n1 = 1;
	int from_m = 0;
	int from_m1 = 1;
	for(int i=0;i<from-2;++i){
		int tmp = from_m;
		from_m = from_m1;
		from_m1 = tmp + from_m1+1;
		from_m1 %= 10;
	}
	for(int i=0;i<to-1;++i){
		int tmp=to_n;
		to_n = to_n1;
		to_n1 = tmp + to_n1 + 1;
		to_n1 %= 10;
	}
	return (to_n1 - from_m1+10)%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_last_digit_of_partialSum(from, to) << '\n';
}
