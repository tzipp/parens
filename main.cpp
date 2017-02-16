#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using std::string;

bool IsToken(char c)
{
    char tokens[] {'[', ']', '(', ')', '{', '}'};
    bool found = false;
    for (auto token: tokens)
        if (token == c)
            found = true;
    return found;
}

bool IsClosingToken(char c)
{
    char closingTokens[] {')', '}', ']'};
    bool found = false;
    for (auto token: closingTokens)
        if (token == c)
            found = true;
    return found;
}

char Pair(char token)
{
    if (token == '(') return ')';
    if (token == ')') return '(';

    if (token == '{') return '}';
    if (token == '}') return '{';

    if (token == '[') return ']';
    if (token == ']') return '[';

    return '\0';
}

int CountTokens(string text)
{
    int count = 0;
    for (auto letter: text)
    {
        if (IsToken(letter))
            ++count;
    }
    return count;
}

struct Result
{
    string message;
    int position;
};

void Result_Init(Result& r, string message, int position)
{
    r.message = message;
    r.position = position;
}

struct Token
{
    char token;
    int pos;
};

void Token_Init(Token& t, char token, int pos)
{
    t.token = token;
    t.pos = pos;
}

Result IsBalanced(string text)
{
    int numTokens = CountTokens(text);

    Token tokenStack[numTokens];
    int top = -1;

    Result r;

    for (auto i = 0; i < text.length(); i++)
    {
        auto token = text[i];
        if (IsToken(token)) {
            if (IsClosingToken(token)) {

                if (top == -1 || Pair(token) != tokenStack[top].token)
                {
                    Result_Init(r, "Failure", i+1);
                    return r;
                }
                --top;

            } else {
                Token t;
                Token_Init(t, token, i+1);
                tokenStack[++top] = t;
            }
        }
    }

    if (top == -1)
    {
        Result_Init(r, "Success", text.length());
    } else {
        Result_Init(r, "Failure", tokenStack[top].pos);
    }

    return r;
}

string RunBalanceCheck(string text)
{
    auto r = IsBalanced(text);

    string displayValue;
    if (r.message == "Success")
    {
        displayValue = "Success";
    } else {
        displayValue = to_string(r.position);
    }

    return displayValue;
}

int main_0()
{
    string s1 = "Hey (my) {name} is [Tom]";
    string s2 = ") Goodbye (";
    string s3 = "{Dam()eon}[]";
    string s4 = "Yosef";
    string s5 = "{[()]}";
    string s6 = "";

    cout << "Bracket Balancer" << endl;
    cout << "================" << endl;

    RunBalanceCheck(s1);
    cout << endl;

    RunBalanceCheck(s2);
    cout << endl;

    RunBalanceCheck(s3);
    cout << endl;

    RunBalanceCheck(s4);
    cout << endl;

    RunBalanceCheck(s5);
    cout << endl;

    RunBalanceCheck(s6);
    cout << endl;

    return 0;
}

int main()
{
    std::string text;
    getline(std::cin, text);
    cout << RunBalanceCheck(text);
}
