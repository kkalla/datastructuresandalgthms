#include <iostream>
#include <stack>
#include <string>

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

int main() {
    std::string text;
    getline(std::cin, text);
    int last_position;


    std::stack <Bracket> opening_brackets_stack;
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
    

    return 0;
}
