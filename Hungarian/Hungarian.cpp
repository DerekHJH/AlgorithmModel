bool Map[105][105] = {0}; //Map[x][y] = true��ʾx��y�б����� 
bool Road[105] = {0}; //Road[x]��¼��x�Ƿ����ڵ�ǰ����·�У���ֹ��ѭ��
int Link[105] = {0}; //Link[x]��¼����·����x������ǰһ���ڵ�y�ı�ţ�����¼�������ƥ��xy
int ans = 0;
bool find_augment_path(int x) //find_augment_path���Ҵ�x������Ƿ��п�����·
{
    for(int y = 1; y <= M; y++) //ö����  �°벿  ��ͼ����x�����ӵĵ�y 
        if(Map[x][y] && (!Road[y])) //����õ�y�����Ѿ��ҵ�������·��
        {
            Road[y] = true; //��y���Ϊ�����ۣ���ֹ��ѭ��
            if(Link[y] == 0 || find_augment_path(Link[y])) 
			//y��δƥ��㣨δ�ǵ㣩����xy��δƥ��� ����
			//y����ƥ��㣬���Ǵ�y�����п�����·��Ҳ����˵xyz��xy��ƥ��ߣ�yz��δƥ��� 
            {
                Link[y] = x;
                return true; //���ִ�x�������ҵ�����·������true
            }
        }
    return false; //�����x����û������·������false
}
int main()
{
	//���ȶ���ͼ�ṹ��Map������
    for(int i = 1; i <= N; i++)//���δ�  �ϰ벿ͼ  �ĵ������Ѱ������·
    {
        memset(Road, 0, sizeof(Road));
        if(find_augment_path(i))ans++; //ÿ�ҵ�һ������·��ƥ������1(���N��ƥ��)
    }
    return 0;
}
//ʱ�临�Ӷ�ΪO(MN) 
