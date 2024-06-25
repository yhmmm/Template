long long mod;
struct Matrix
{
	long long data[301][301],r,c;
	Matrix()
	{
		memset(data,0,sizeof data);
	}
	Matrix(int _r,int _c):r(_r),c(_c)
	{
		memset(data,0,sizeof data);
	}
	Matrix operator+(const Matrix &t)const
	{
		Matrix res;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				res.data[i][j]=(data[i][j]+t.data[i][j])%mod;
			}
		}
		return res;
	}
	Matrix operator*(const Matrix &t)const
	{
		Matrix res;
		res.r=r,res.c=t.c;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=t.c;j++)
			{
				for(int k=1;k<=t.r;k++)
				{
					res.data[i][j]=(((data[i][k]*t.data[k][j])%mod)+res.data[i][j])%mod;
				}
			}
		}
		return res;
	}
	// Matrix operator*(const Matrix &t)const
	// {
	// 	Matrix res;
	// 	res.r=r,res.c=t.c;
	// 	for(int i=1;i<=r;i++)
	// 	{
	// 		for(int k=1;k<=t.r;k++)
	// 		{
	// 			long long tmp=data[i][k];
	// 			for(int j=1;j<=t.c;j++)
	// 			{
	// 				res.data[i][j]=(((tmp*t.data[k][j])%mod)+res.data[i][j])%mod;
	// 			}
	// 		}
	// 	}
	// 	return res;
	// }
	// Faster multiplication
	Matrix operator^(long long x)const
	{
		Matrix res(r,r),base(r,r);
		for(int i=1;i<=r;i++)
		{
			res.data[i][i]=1;
		}
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				base.data[i][j]=data[i][j]%mod;
			}
		}
		while(x)
		{
			if(x&1)
			{
				res=res*base;
			}
			base=base*base;
			x>>=1;
		}
		return res;
	}
};