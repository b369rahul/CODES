#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    char type;
    int position;

    Bracket(char type, int position):
        type(type), position(position)
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

};

int main() {
    std::string text;
    getline(std::cin, text);
    int flag=1;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // write here
            Bracket o(next,position);
            opening_brackets_stack.push(o);
        }

        if (next == ')' || next == ']' || next == '}') {
            // write here
            if(opening_brackets_stack.empty()){std::cout<<position +1<<'\n';
               return 0;}
           auto a=opening_brackets_stack.top();
           opening_brackets_stack.pop();
           if(!a.Matchc(next)){
               flag=0;
               std::cout<<position +1<<'\n';
               return 0;
           }

        }
    }
    if(!opening_brackets_stack.empty()){
        auto a=opening_brackets_stack.top();
        std::cout<<a.position +1<<'\n';}

    else if(flag==1){std::cout<<"Success"<<'\n';}

    // Printing answer, write your code here

    return 0;
}
