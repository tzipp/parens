#include <iostream>
#include <string>

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

int main()
{
    cout << "Bracket Balancer" << endl;

    return 0;
}
