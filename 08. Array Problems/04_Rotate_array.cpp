/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void rotate(vector<int> &nums, int k)
{
    int n = nums.size() - 1;
    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % n] = nums[i];
    }
    nums = temp;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}