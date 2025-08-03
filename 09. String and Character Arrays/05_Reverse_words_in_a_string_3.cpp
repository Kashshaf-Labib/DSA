/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string reverseString(string s)
{
    int i = 0;
    int n = s.size();
    while (i < n)
    {
        while (s[i] == ' ' && i < n)
        {
            i++;
        }
        if (i == n)
        {
            break;
        }
        int j = i;
        while (s[j] != ' ' and j < n)
        {
            j++;
        }
        int k = i, l = j - 1;
        while (k < l)
        {
            swap(s[k++], s[l--]);
        }
        i = j + 1;
    }
    return s;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    string s = "Let's take LeetCode contest";
    cout << reverseString(s) << endl;

    return 0;
}