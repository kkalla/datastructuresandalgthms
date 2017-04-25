#include <iostream>
#include <stack>
#include <string>
#include <ctime>
#include <cstdlib>
typedef unsigned int uint;


struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};
std::stack <Bracket> opening_brackets_stack;
 
  std::string randomString(uint l = 15, std::string charIndex = "abcdefghijklmnaoqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890[]{}()"){
		    // l and charIndex can be customized, but I've also initialized them.
			
			uint length = rand() % l + 1;
			// length of the string is a random value that can be up to 'l' characters.
			
			             uint ri[15];
			//                 /* array of random values that will be used to iterate through random
			//                       indexes of 'charIndex' */
			//
	          for (uint i = 0; i < length; ++i)
			  ri[i] = rand() % charIndex.length();
		 // assigns a random number to each index of "ri"	
		 std::string rs = "";
		 // random string that will be returned by this function
		 for (uint i = 0; i < length; ++i)
			 rs += charIndex[ri[i]];
		 // appends a random amount of random characters to "rs"
		 if (rs.empty()) randomString(l, charIndex);
		 // if the outcome is empty, then redo the generation (this doesn't work, help?)
		 else return rs;
	    }
	    
	void solve(std::string text) {

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket *open_bracket = new Bracket(next,position);
            opening_brackets_stack.push(*open_bracket);
        }

        if (next == ')' || next == ']' || next == '}') {
        	//closing_bracket appears before opening bracket
        	if(opening_brackets_stack.empty()){
        		std::cout<<"Stack is empty. Position: " <<position;
        		break;
			}
			
		//Wrong bracket-pair
        	Bracket last = opening_brackets_stack.top();
		opening_brackets_stack.pop();  
		if(last.Matchc(next)){
            	
			} else{
				std::cout<<"Unmatch pair. Position: "<< position;
				break;
			}		
        }

    }
    if(!opening_brackets_stack.empty()){
	    std::cout<<"stack is not empty. Position : "<<opening_brackets_stack.top().position;
	} else if (opening_brackets_stack.empty()){
		std::cout<<"Success";
	}
    }
int main() {
	int n;
    
	while(n<10){
		std::string text;
    getline(std::cin, text);
    int last_position;
   


    
   
		std::string test = randomString();
		solve(test);
		n++;

	}

    
 
    return 0;
}
