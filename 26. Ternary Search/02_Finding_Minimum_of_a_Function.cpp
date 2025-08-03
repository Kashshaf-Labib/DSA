#include <bits/stdc++.h>
#define ll long long
using namespace std;

double findMin(double x)
{
    double fx = (2 * x * x) - (12 * x) + 7;
    return fx;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        double l, r;
        cin >> l >> r;

        double m1, m2;

        while (r - l > 0.0000001)
        {
            m1 = l + (r - l) / 3;
            m2 = r - (r - l) / 3;

            double fx1 = findMin(m1);

            double fx2 = findMin(m2);

            if (fx1 > fx2)
            {
                l = m1;
            }
            else if (fx1 < fx2)
            {
                r = m2;
            }
            else
            {
                l = m1, r = m2;
            }
        }
        cout << (ll)findMin(l) << endl;
    }

    return 0;
}