#include <iostream>
#include <ctime>

int get_last_naive(int n){
	if (n<=1)
		return n;
		
	int previous = 0;
	int current = 1;
	
	for (int i=0; i<n-1 ; ++i){
		int tmp = previous;
		previous = current;
		current = tmp + current;
	}
	
	return current % 10;
}

int get_last_fast(int n){
	if(n>60)
		n %= 60 ;
	if(n<=1)
		return n;
	int prev = 0;
	int curr = 1;
	for(int i=0;i<n-1;++i){
		int tmp = prev;
		prev = curr;
		curr = tmp + prev;
		curr = curr%10;
	}
	return curr;
}
int get_last_test(int n){
	if(n<=1)
		return n;
	int prev = 0;
	int curr = 1;
	for(int i=0;i<n-1;++i){
		int tmp = prev;
		prev = curr;
		curr = tmp + prev;
		curr = curr%10;
	}
	return curr;
}

int main(){
	int n;
	std::cin >> n;
	int start_s=clock();
	for(int i=0;i<n;++i){
		if(get_last_test(i)!=get_last_fast(i)){
			std::cout <<"Error : "<<i<<"\n";
			std::cout << "test : "<<get_last_test(i)<<", ";
			std::cout << "fast : "<<get_last_fast(i);
			break;
		}
		std::cout << i<<"\n";
		std::cout << "test : "<<get_last_test(i)<<"\n";
		std::cout << "fast : "<<get_last_fast(i)<<"\n";
	}
	int stop_s=clock();
	std::cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 ;

	
}
