//这题segement fault
//信息传递
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
bool pass( vector<vector<int>> inf, vector<int> toWhom)
{
    //建立快照
    vector<vector<int>> tmp = inf;
    for (int i = 0; i < int(inf.size()); i++)
    {
        for (int j = 0; j < int(inf[i].size());j++)
        {
            //利用快照进行信息传递
            inf[toWhom[i]][j] = tmp[i][j];
        }
    }
    //传递完成之后检查有没有见到自己
    for (int i = 0; i < int(inf.size());i++)
    {
        if( inf[i][i])
            return 0;   
    }
    return 1;
}
int main()
{
    vector<int> toWhom ;
    int n = 0;
    scanf("%d", &n);
    //读入谁要把信息告诉谁
    read(n,toWhom);
    vector<vector<int>> inf;
    //每个人的持有信息初始化
    for (int i = 0; i < n;i++)
    {
        inf[i][0] = i;
    }
    long long times = 0;
    while (pass(inf,toWhom))
    {
        times++;
    }
    cout << times << endl;
    return 0;
}