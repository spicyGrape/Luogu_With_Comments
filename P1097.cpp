//统计数字（提高组里的普及-题目）
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n = 0;
    cin >> n;
    //题目里给定的最大数字很大，所以数组开longlong
    long long a[n+1];
    for ( long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //偷懒用STL（怎么能叫偷懒呢？这是熟悉标准库的操作/doge
    sort(a, a + n);
    //以下输出为测试用输出
    //for (int i = 0; i < n; i++)
    //{
    //   cout << a[i] << endl;
    //}
    long long temp = a[0];
    long long times = 0;
    for (long long i = 0; i < n; i++)
    {
        if (temp != a[i])
        {
            cout << a[i - 1] << " " << times << endl;
            temp = a[i];
            times = 1;
        }
        else
        {
            times++;
        }
    }
    cout << temp << " " << times << endl;
    return 0;
}