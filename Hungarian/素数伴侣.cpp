//ţ����-��Ϊ����-�������� 
//��Ŀ����
//�������������ĺ�Ϊ����������������������֮Ϊ���������¡���
//��2��5��6��13��������Ӧ����ͨ�ż��ܡ���������ѧ���������һ������
//�����е�N��NΪż����������������ѡ�����ɶ���ɡ��������¡�����ѡ�������ֶ�����
//������4����������2��5��6��13�������5��6��Ϊһ����ֻ�ܵõ�һ�顰�������¡���
//����2��5��6��13���齫�õ����顰�������¡�������ɡ��������¡����ķ�����Ϊ����ѷ�������
//��Ȼ����ѧ��ϣ����Ѱ�ҳ�����ѷ�������
//
//����:
//
//��һ����ż��N��N��100������ʾ����ѡ����Ȼ���ĸ��������������������֣���ΧΪ[2,30000]��
//
//���:
//
//���һ������K����ʾ����õġ���ѷ�������ɡ��������¡��Ķ�����
//
//
//��������:
//����˵��
//1 ����һ����ż��n
//2 ����n������
//ע�⣺���ݿ����ж���
//
//�������:
//��õġ���ѷ�������ɡ��������¡��Ķ�����
//
//ʾ��1
//����
//4
//2 5 6 13
//2
//3 6
//���
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
