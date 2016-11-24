#include <iostream>
#include <stack>
#include <string>

using namespace std;
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
    bool suc = true;
    int suc1 = 1;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];


        if (next == '(' || next == '[' || next == '{')
        {
            Bracket x(next , position+1 );
            opening_brackets_stack.push(x);
        }

        if (next == ')' || next == ']' || next == '}')
        {

              if (opening_brackets_stack.empty() == true)
                  {
                    suc1 = position+1 ;
                    suc = false;
                    break;
                  }

                  char top = opening_brackets_stack.top().type;

                  if ( (top == '(' && next != ')' )  || (  top == '['  && next !=  ']' ) || (  top == '{'  && next != '}' ) )
                  {
                  suc1 = position+1 ;
                  suc = false;
                  break;
                  }

                  opening_brackets_stack.pop();
        }

    }

    if (suc == false)
        cout << suc1 << endl;

    else if  ( opening_brackets_stack.empty() == false )
    {
      cout << opening_brackets_stack.top().position << endl;
    }

    else
          cout << "Success" << endl;

    return 0;
}
