#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(int type, int position):
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
    getline(std::cin, text);   // get the input string

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {  // store the left bracket in the stack
            Bracket parenStart(next, position);
			opening_brackets_stack.push(parenStart);
        }
        else if (next == ')' || next == ']' || next == '}') {  // if right bracket is detected
			if (opening_brackets_stack.empty())   // if the stack is empty, which means no left bracket is stored
			{
				std::cout << (position + 1) << std::endl;  // output the position of this right bracket, break loop
				break;
			}
			else
			{
				Bracket parenStartOut = opening_brackets_stack.top(); // get the latest left bracket, 
				                                                      //remove it from stack
				opening_brackets_stack.pop();   
			    if(!parenStartOut.Matchc(next))  // check if the latest left bracket is matched with
			                                     // the current right bracket
			    {
                    std::cout << (position + 1) << std::endl; // if not, output the position of this right bracket, break loop
				    break;
			    }
			}

        }
		if (position == text.length() - 1)  // if reach the end of the string
		{
			if (!opening_brackets_stack.empty()) // if the stack is not empty, output the position of 
			                                     //left bracket at the end of the stack (the first unmatched one) 
			{
				Bracket firstUnMatched('(',0); // initialization, initial values don't matter here
				while(!opening_brackets_stack.empty())
			    {
				   firstUnMatched = opening_brackets_stack.top();
				   opening_brackets_stack.pop();
			    }
			    std::cout << (firstUnMatched.position + 1) << std::endl;
			}
			else // if stack has no left bracket, which means all the brackets have been matched
			{
				std::cout << "Success" << std::endl;
			}

		}
    }


    return 0;
}




