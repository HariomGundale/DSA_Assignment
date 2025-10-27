#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    // mam,madam,racecar,maam
    // list<char> ll;
    // SLL ll;
    stack<char> st;
    cout << "Enter string: ";
    getline(cin, str);
    int n = str.size(), i = 0;
    while (i < n / 2)
    {
        st.push(str[i]);
        // cout << st.top()<<endl;
        i++;
    }
    // cout << "out of loop" << endl;
    if (n % 2 != 0)
    {
        i++;
        // cout << str[i] << endl;
    }
    while (i < n)
    {
        // cout << st.top() << " " << str[i]<<endl;
        if (st.top() != str[i])
        {
            cout << "Not a palindrome" << endl;
            return 0;
        }
        st.pop();
        i++;
    }
    cout << "Is Palindrome" << endl;
    return 0;
}