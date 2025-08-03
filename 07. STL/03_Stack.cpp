/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    stack<string> stk;

    stk.push("first");
    stk.push("second");
    stk.push("third");

    cout << stk.top() << endl;

     stk.pop();
     cout << stk.top() << endl;

    cout << stk.size() << endl;

    cout << stk.empty() << endl;

    return 0;
}

// Stack is like putting one plate on top of another.

// It follows LIFO convention (Last In First Out);