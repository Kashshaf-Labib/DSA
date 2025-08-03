/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    set<int> st;

    st.insert(1);
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(4);

    // for (auto x : st)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // set<int>::iterator it;

    // it = st.begin();
    // it++;

    // st.erase(it);

    // for (auto x : st)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // cout << st.count(10) << endl; // returns 0 or 1

    set<int>::iterator itr = st.find(2); // Returns the iterator or pointer of 2 if it exists

    for (auto it = itr; it != st.end(); it++) // prints the from 2 to the end
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: insert find erase count --> O(logn)

// size ,begin end,empty --> O(1)