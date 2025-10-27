#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
    string exp;
    stack<char> st;
    cout << "Enter Exp: ";
    getline(cin, exp);
    // getchar();
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int t1 = st.top() - '0';
            st.pop();
            int t2 = st.top() - '0';
            st.pop();
            int sol = 0;
            switch (exp[i])
            {
            case '+':
                sol = t1 + t2;
                break;
            case '-':
                sol = t2 - t1;
                break;
            case '*':
                sol = t1 * t2;
                break;
            case '/':
                sol = t2 / t1;
                break;
            default:
                break;
            }
            st.push(char(sol)+'0');
        }else{
            st.push(exp[i]);
        }
    }

    cout<<"Ans is: "<<st.top();

    return 0;
}