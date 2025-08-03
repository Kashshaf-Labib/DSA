/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > nums[(i + 1) % nums.size()])
        {
            cnt++;
        }
    }
    if (cnt > 1)
    {
        return false;
    }
    return true;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}