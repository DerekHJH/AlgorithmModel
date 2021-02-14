bool Map[105][105] = {0}; //Map[x][y] = true表示x与y有边相连 
bool Road[105] = {0}; //Road[x]记录点x是否已在当前增广路中，防止死循环
int Link[105] = {0}; //Link[x]记录增广路上与x相连的前一个节点y的编号，即记录已求出的匹配xy
int ans = 0;
bool find_augment_path(int x) //find_augment_path查找从x点出发是否有可增广路
{
    for(int y = 1; y <= M; y++) //枚举在  下半部  分图中与x点连接的点y 
        if(Map[x][y] && (!Road[y])) //如果该点y不在已经找到的增广路上
        {
            Road[y] = true; //把y标记为已讨论，防止死循环
            if(Link[y] == 0 || find_augment_path(Link[y])) 
			//y是未匹配点（未盖点），即xy是未匹配边 或者
			//y是已匹配点，但是从y出发有可增广路，也就是说xyz，xy是匹配边，yz是未匹配边 
            {
                Link[y] = x;
                return true; //发现从x出发可找到增广路，返回true
            }
        }
    return false; //如果从x出发没有增广路，返回false
}
int main()
{
	//首先读入图结构到Map数组中
    for(int i = 1; i <= N; i++)//依次从  上半部图  的点出发，寻找增广路
    {
        memset(Road, 0, sizeof(Road));
        if(find_augment_path(i))ans++; //每找到一条增广路，匹配数加1(最多N个匹配)
    }
    return 0;
}
//时间复杂度为O(MN) 
