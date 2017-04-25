#include <iostream>
#include <ctime>
#include <cstdlib>

//Insert function here
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

int main(){
	//number of test cases
	int n;
	std::cin >> n;
	for(int i=0; i<n ;++i){
		//Input format and constraints
		long long input=rand()%100000000;
		long long input2=rand()%10000+input;
		int start_s = clock();
		int result = get_last_digit_of_partialSum(input,input2);
		int stop_s = clock();
		int sec = (stop_s-start_s)/(CLOCKS_PER_SEC);
		if(sec>1||result<0){
			std::cout <<"Error: exceed time limit. sec : "<<sec;
			break;
		}
		//Print result
		std::cout <<"case "<<i<<"= "<<input<<", "<<input2<<"\n";
		std::cout <<"result = "<<result<<", sec : "<<sec<<"\n";
	}
}
