/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void reverseString(vector<char> &s)
{
    int size = s.size();
    for (int i = 0, j = size - 1; i < size / 2; i++, j--)
    {
        swap(s[i], s[j]);
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}