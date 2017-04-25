#include <iostream>

int main(){
	int n=0;
	std::cin>>n;
	int prev = 0;
	int curr = 1;
	std::cout<<prev<<", "<<curr;
	while(n){
		int tmp = prev;
		prev = curr;
		curr = tmp+curr;
		curr %= 30524;
		std::cout <<", "<<curr<<", n="<<n;
		if(prev==0&&curr==1){
			std::cout <<", n = "<<n;
			break;
		}
			
		n++;
	}
	/*
	unsigned long int n=2816213588;
	int m = 30524;
	std::cout<<n%1176<<"\n";
	*/
	return 0;
}
