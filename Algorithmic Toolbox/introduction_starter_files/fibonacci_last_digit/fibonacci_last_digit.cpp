#include <iostream>
#include <ctime>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
// It is a seq. So figure out what the length of seq is!
int get_fibonacci_last_digit_fast(int n) {
	n %= 60;
	if(n<=1)
		return n;
	int prev = 0;
	int curr = 1;
	for(int i=0;i<n-1;++i){
		int tmp_prev=prev;
		prev = curr;
		curr = tmp_prev + prev;
		curr = curr%10;
	}

	return curr;


}
int find_length(){
	int i=2;
	int fn,fn_1;
	while(1){
		fn=get_fibonacci_last_digit_fast(i);
		fn_1=get_fibonacci_last_digit_fast(i+1);
		if(fn==0 && fn_1==1){
			break;
		}
		i++;
	}
	return i;
}

int main() {
	int n;
    std::cin >> n;
    int start_s=clock();
    //int c = get_fibonacci_last_digit_naive(n);
    //while(n<100){
    int c = get_fibonacci_last_digit_fast(n);
    int stop_s = clock();
    std::cout << "F"<<n<<"= " << c<<"\n";
    std::cout << "Time : "<< (stop_s-start_s)/static_cast<double>(CLOCKS_PER_SEC)*1000;
    //n++;
//	}
    //std::cout<<n;
    }
