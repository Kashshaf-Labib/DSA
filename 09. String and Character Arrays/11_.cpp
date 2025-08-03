/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int compress(vector<char> &chars)
{
    int i = 0, ansIndex = 0;
    while (i < chars.size())
    {
        int j = i + 1;
        while (chars[i] == chars[j] and j < chars.size())
        {
            j++;
        }
        chars[ansIndex++] = chars[i];
        int count = j - i;
        if (count > 1)
        {
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}