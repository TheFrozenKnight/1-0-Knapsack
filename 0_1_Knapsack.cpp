#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1]+ knapSack(W - wt[n - 1],wt, val, n - 1),knapSack(W, wt, val, n - 1));
}
int main()
{
    srand((int)time(0));
    int W,n;

    cout << "Enter Total Number of Items: ";
    cin>> n;
    cout << "Enter Max Capacity: ";
    cin>> W;

    int val[n],wt[n];

    for(int i = 0 ; i<n; i++)
        val[i] = rand()%((W*10)-100) +100;

    for(int i = 0 ; i<n; i++)
        wt[i] = rand()%(W);

    cout << knapSack(W, wt, val, n);
    return 0;
}
