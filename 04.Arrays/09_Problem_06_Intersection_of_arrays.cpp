/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    set<int> numset1;

    set<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {
        numset1.insert(nums1[i]);
    }
    for (auto x : numset1)
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            if (x == nums2[i])
            {
                ans.insert(x);
            }
        }
    }
    vector<int> ansvec;
    for (auto x : ans)
    {
        ansvec.push_back(x);
    }

    return ansvec;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}