#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
using std::string;
using std::cout;
using std::endl;
using std::regex;

// 2 variants to solve email format validity

bool isEmailRegex(const string& email)
{
    const regex pattern
    ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    return regex_match(email, pattern);
}

bool isEmail(string& email)
{
    auto one = count(begin(email), end(email), '@');
    auto it = find(begin(email), end(email), '@');
    if (it == email.begin())
    {
        return false;
    }
    auto nit = find_if(begin(email), it, [](char elem) {return elem >= 48 && elem <= 57 || elem >= 65 && elem <= 122; });
    auto dot = find_if(it + 1, end(email), [](char elem) {return elem == '.'; });
    auto nnnit = find_if(it + 1, end(email), [](char elem) {return elem >= 48 && elem <= 122; });
    if (one == 1 && it != end(email) && nit != end(email) && dot != end(email) && nnnit != end(email))
    {
        return true;
    }
    return false;
}

int main()
{
    string email4 = "@gmail.com";
    string email3 = "aaa@gmail@com";
    string email2 = "aaa@gmail.co.uk";
    string email1 = "aaa@gmail";
    cout << email1 << " : " << (isEmailRegex(email1) ?
        "valid" : "invalid") << endl;
    cout << email2 << " : " << (isEmailRegex(email2) ?
        "valid" : "invalid") << endl;
    cout << email3 << " : " << (isEmailRegex(email3) ?
        "valid" : "invalid") << endl;
    cout << email4 << " : " << (isEmailRegex(email4) ?
        "valid" : "invalid") << endl;
}

