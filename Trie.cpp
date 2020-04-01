struct _node
{
	int next[10];
	int val;
}Trie[MAX];
int tot = 0;
void Insert(string s, int val)
{
	int l = s.length(), p = 1, Index = 0;
	for(int i = 0; i < l; i++)
	{
		Index = s[i] - '0';
		if(Trie[p].next[Index] > 0)p = Trie[p].next[Index];
		else 
		{
			tot++;
			Trie[p].next[Index] = tot;
			p = tot;
		}
	}
	Trie[p].val = val;
}
int Find(string s)
{
	int l = s.length(), p = 1, Index = 0;
	for(int i = 0; i < l; i++)
	{
		Index = s[i] - '0';
		if(Trie[p].next[Index] > 0)p = Trie[p].next[Index];
		else return 0;//Not found
	}
	return Trie[p].val;//Found and return value
}
