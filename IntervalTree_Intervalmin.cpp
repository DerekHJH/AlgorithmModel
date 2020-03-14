const int MAX = 50000;
const int inf = 999999999;
int C = 0, S = 0, R = 0;
class Node
{
	public:
		int l, r, Min, Lazy;
}inttree[MAX];
void buildtree(int p, int l, int r)
{
	int lson = (p << 1), rson = (lson | 1), mid = ((l + r) >> 1) ;
	inttree[p].l = l;
	inttree[p].r = r;
	inttree[p].Lazy = 0;
	inttree[p].Min = inf;
	if(l == r)inttree[p].Min = S;
	else
	{
		buildtree(lson, l, mid);
		buildtree(rson, mid + 1, r);
		inttree[p].Min = min(inttree[lson].Min, inttree[rson].Min);
	}
}
void delazy(int p)
{
	int lson = (p << 1), rson = (lson | 1);
	inttree[lson].Min += inttree[p].Lazy;
	inttree[lson].Lazy += inttree[p].Lazy;
	inttree[rson].Min += inttree[p].Lazy;
	inttree[rson].Lazy += inttree[p].Lazy;
	inttree[p].Lazy = 0;
}
void Add(int p, int l, int r, int diff)
{
	if(inttree[p].Lazy != 0)delazy(p);
	if(l <= inttree[p].l && inttree[p].r <= r)
	{
		inttree[p].Min += diff;
		inttree[p].Lazy += diff;
	}
	else
	{
		int lson = (p << 1), rson = (lson | 1);
		if(!(r < inttree[lson].l || l > inttree[lson].r))Add(lson, l, r, diff);
		if(!(r < inttree[rson].l || l > inttree[rson].r))Add(rson, l, r, diff);
		inttree[p].Min = min(inttree[lson].Min, inttree[rson].Min);
	}
}
int getmin(int p, int l, int r)
{
	if(inttree[p].Lazy != 0)delazy(p);
	if(l <= inttree[p].l && inttree[p].r <= r)return inttree[p].Min;
	else
	{
		int lson = (p << 1), rson = lson + 1;
	    int Min = inf;
	    if(!(r < inttree[lson].l || l > inttree[lson].r))Min = min(Min, getmin(lson, l, r));
		if(!(r < inttree[rson].l || l > inttree[rson].r))Min = min(Min, getmin(rson, l, r));
		return Min;
	}
}
