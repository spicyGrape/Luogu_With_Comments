//这题segement fault
//信息传递
//这题的问题已经找到了：vector只能按下标从小到大的顺序依次赋值，但是按照我使用的信息传递方式，会出现跳跃式赋值的问题。
//把vector改成静态数组或许可以解决，调换信息传递方向也可以解决，不过这个坑还是以后再填吧，我懒得改了
#include <bits/stdc++.h>

using namespace std;

void read(int n, vector<int> toWhom)
{
    cout << "read" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> toWhom[i];
    }
    cout << "read" << endl;
}
bool pass(vector<vector<int>> inf, vector<int> toWhom)
{
    //建立快照
    vector<vector<int>> tmp = inf;
    for (int i = 0; i < int(inf.size()); i++)
    {
        for (int j = 0; j < int(inf[i].size()); j++)
        {
            //利用快照进行信息传递
            inf[toWhom[i]][j] = tmp[i][j];
        }
    }
    //传递完成之后检查有没有见到自己
    for (int i = 0; i < int(inf.size()); i++)
    {
        if (inf[i][i])
            return 0;
    }
    return 1;
}
int main()
{
    vector<int> toWhom;
    int n = 0;
    scanf("%d", &n);
    //读入谁要把信息告诉谁
    read(n, toWhom);
    vector<vector<int>> inf;
    //每个人的持有信息初始化
    for (int i = 0; i < n; i++)
    {
        inf[i][0] = i;
    }
    long long times = 0;
    while (pass(inf, toWhom))
    {
        times++;
    }
    cout << times << endl;
    return 0;
}