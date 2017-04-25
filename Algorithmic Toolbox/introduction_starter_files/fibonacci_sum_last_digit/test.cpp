#include <iostream>

int main(){
	int n=2;
	int s_prev=0;
	int s_curr=1;
	while(n){
		int tmp = s_prev;
		s_prev=s_curr;
		s_curr = tmp + s_curr +1;
		s_curr%=10;
		if(s_prev==0&&s_curr==1){
			std::cout<<n;
			break;
		}
		n++;
	}
	return 0;
}
