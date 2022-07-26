//汉诺双塔
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 0;
    scanf("%d", &n);
    int ans[400][400] = {};
    ans[1][0] = 2;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 400; j++)
        {
            ans[i][j] = ans[i - 1][j] * 2;
        }
        ans[i][0] += 2;

        for (int j = 0; j < 400; j++)
        {
            while (ans[i][j] > 9)
            {
                ans[i][j] -= 10;
                ans[i][j + 1]++;
            }
        }
    }
    int flag = 0;
    for (int i = 399; i >= 0; i--)
    {

        if (ans[n][i])
        {
            flag = i;
            break;
        }
    }

    for (int i = flag; i >= 0; i--)
    {
        printf("%d", ans[n][i]);
    }
    printf("\n");
      return 0;
}