/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    int count1[26] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    int count2[26] = {0};
    int windowSize = s1.size();
    int i = 0;
    while (i < windowSize and i < s2.size())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if (checkEqual(count1, count2))
    {
        return true;
    }
    while (i < s2.size())
    {
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;

        if (checkEqual(count1, count2))
        {
            return true;
        }
        i++;
    }
    return false;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}