int pos=0,prime[1000001],st[1000001],n;
void EulerSieve(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
		{
			prime[++pos]=i;
		}
		for(int j=1;j<=pos&&i*prime[j]<=n;j++)
		{
			st[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				break;
			}
		}
	}
}
