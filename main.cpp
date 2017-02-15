#include <iostream>

using namespace std;

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

int CountTokens()
{

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
