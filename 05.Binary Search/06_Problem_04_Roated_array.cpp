/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int binarySearch(vector<int> &arr, int s, int e, int key)
{

    int left = s;
    int right = e;
    int middle = left + ((right - left) / 2); // this equals to (left+right)/2
    while (left <= right)
    {
        if (arr[middle] == key)
        {
            return middle;
        }
        else if (arr[middle] > key)
        {
            right = middle - 1;
        }
        else if (arr[middle] < key)
        {
            left = middle + 1;
        }
        middle = left + ((right - left) / 2);
    }
    return -1;
}

int getPivotIndex(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else if (arr[mid] < arr[0])
        {
            end = mid;
        }
        mid = (start + end) / 2;
    }
    return start;
}
int search(vector<int> &arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int ans;
    int pivot = getPivotIndex(arr);
    if (arr[0] <= k && k <= arr[pivot - 1])
    {
        ans = binarySearch(arr, 0, pivot - 1, k);
    }
    else
    {
        ans = binarySearch(arr, pivot, n - 1, k);
    }
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}