/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mySqrt(int x)
{
    int start = 0;
    int end = x;
    long long int mid = start + ((end - start) / 2);
    while (start <= end)
    {
        long long int sqr = mid * mid;
        if (sqr == x)
        {
            return mid;
        }
        else if (mid * mid > x)
        {
            end = mid - 1;
        }
        else if (mid * mid < x)
        {
            start = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }
    return mid - 1;
}
double precisesqrt(int n, int precision)
{
    double wholeNum = mySqrt(n);
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = wholeNum; j * j < n; j += factor)
        {
            wholeNum = j;
        }
    }
    return wholeNum;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << mySqrt(n) << endl;
    cout << precisesqrt(n, 2);

    return 0;
}