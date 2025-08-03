/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class TwoStack
{

public:
    int top1;
    int top2;
    int size;
    int *arr;
    // Initialize TwoStack.
    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = size;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (top2 - 1 > top1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 != -1)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 != size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}