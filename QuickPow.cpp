long long QuickPow(long long a,long long b,long long p)
{
	long long res=1;
	while(b)
	{
		if(b&1)
		{
			res=(res*a)%p;
		}
		a=(a*a)%p;
		b>>=1;
	}
	return res;
}