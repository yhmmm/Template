#define ls(p) (p*2)
#define rs(p) (p*2+1)
int n,a[1000001];
struct AB
{
	int l,r,v,tag;
}tree[4000001];
void build(int p,int l,int r)
{
	tree[p]={l,r,0,0};
	if(l==r)
	{
		tree[p].v=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(ls(p),l,mid),build(rs(p),mid+1,r);
	tree[p].v=tree[ls(p)].v+tree[rs(p)].v;
}
void pushdown(int p)
{
	if(tree[p].l!=tree[p].r&&tree[p].tag)
	{
		tree[ls(p)].tag+=tree[p].tag,tree[rs(p)].tag+=tree[p].tag;
		tree[ls(p)].v+=tree[p].tag*(tree[ls(p)].r-tree[ls(p)].l+1);
		tree[rs(p)].v+=tree[p].tag*(tree[rs(p)].r-tree[rs(p)].l+1);
		tree[p].tag=0;
	}
}
int query(int p,int l,int r)
{
	if(l<=tree[p].l&&tree[p].r<=r)
	{
		return tree[p].v;
	}
	pushdown(p);
	int res=0,mid=(tree[p].l+tree[p].r)/2;
	if(l<=mid)
	{
		res=query(ls(p),l,r);
	}
	if(r>mid)
	{
		res+=query(rs(p),l,r);
	}
	return res;
}
void update(int p,int l,int r,int v)
{
	if(l<=tree[p].l&&tree[p].r<=r)
	{
		tree[p].tag+=v;
		tree[p].v+=v*(tree[p].r-tree[p].l+1);
		return;
	}
	pushdown(p);
	int mid=(tree[p].l+tree[p].r)/2;
	if(l<=mid)
	{
		update(ls(p),l,r,v);
	}
	if(r>mid)
	{
		update(rs(p),l,r,v);
	}
	tree[p].v=tree[ls(p)].v+tree[rs(p)].v;
}
/*
Example:
update(1,l,r,x);
query(1,l,r);
build(1,1,n);
*/
