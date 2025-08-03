/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string removeOccurrences(string s, string part)
{
    std::string original = s;
    std::string sub = part;
    while (original.find(sub) != string::npos)
    {
        std::string::size_type i = original.find(sub);
        if (i != std::string::npos)
        {
            original.erase(i, sub.length());
        }
    }
    return original;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}