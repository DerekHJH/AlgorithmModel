//牛客网-华为机试-素数伴侣 
//题目描述
//若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，
//如2和5、6和13，它们能应用于通信加密。现在密码学会请你设计一个程序，
//从已有的N（N为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，
//例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，
//而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，
//当然密码学会希望你寻找出“最佳方案”。
//
//输入:
//
//有一个正偶数N（N≤100），表示待挑选的自然数的个数。后面给出具体的数字，范围为[2,30000]。
//
//输出:
//
//输出一个整数K，表示你求得的“最佳方案”组成“素数伴侣”的对数。
//
//
//输入描述:
//输入说明
//1 输入一个正偶数n
//2 输入n个整数
//注意：数据可能有多组
//
//输出描述:
//求得的“最佳方案”组成“素数伴侣”的对数。
//
//示例1
//输入
//4
//2 5 6 13
//2
//3 6
//输出
//2
//0

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int N = 0, a[105] = {0}, ans = 0;
bool Map[105][105] = {0};
bool Road[105] = {0};
int Link[105] = {0};
bool is_prime(int x)
{
    int Root = sqrt(x + 1);
    for (int i = 2; i <= Root; i++)
        if(x % i == 0)return false;
    return true;
}
bool find_augment_path(int x)
{
    for(int y = 1; y <= N; y++)
        if(Map[x][y] && (!Road[y]))
        {
            Road[y] = true;
            if(Link[y] == 0 || find_augment_path(Link[y]))
            {
                Link[y] = x;
                return true;
            }
        }
    return false;
}
int main()
{
    while(scanf("%d", &N) != EOF)
    {
        //initializeation
        memset(Map, 0, sizeof(Map));
        memset(Road, 0, sizeof(Road));
        memset(Link, 0, sizeof(Link));
        ans = 0;
        //input
        for (int i = 1; i <= N; i++)
            scanf("%d", &a[i]);
        //create graph
        for(int i = 1; i <= N; i++)
            for(int j = i + 1; j <= N; j++)
                if(is_prime(a[i] + a[j]))Map[i][j] = Map[j][i] = true;
        //Hungarian 
        for(int i = 1; i <= N; i++)
        	if(a[i] % 2 == 1)
        	{
            	memset(Road, 0, sizeof(Road));
            	if(find_augment_path(i))ans++;
        	}
        printf("%d\n", ans);
    }
    return 0;
}
