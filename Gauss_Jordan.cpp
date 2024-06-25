int n;
double a[101][102],eps=1e-9;
int Gauss_Jordan()
{
    int r=1;
    for(int c=1;c<=n;c++)
    {
        int t=r;
        for(int i=r;i<=n;i++)
        {
            if(abs(a[i][c])>abs(a[t][c]))
            {
                t=i;
            }
        }
        if(abs(a[t][c])<eps)
        {
            continue;
        }
        swap(a[r],a[t]);
        for(int i=1;i<=n;i++)
        {
            if(abs(a[i][c])>eps&&i!=r)
            {
                for(int j=n+1;j>=c;j--)
                {
                    a[i][j]-=a[i][c]*a[r][j]/a[r][c];
                }
            }
        }
        r++;
    }
    if(r<n+1)
    {
        for(int i=r;i<=n;i++)
        {
            if(abs(a[i][n+1]/a[i][i])>eps)
            {
                return 2;// No solution
            }
        }
        return 1;// Infinite solution
    }
    return 0;// Solution
}
