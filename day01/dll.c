int max(int a[], int n)
{
	int m = a[0];
	for(int i=1; i<n; i++)
		if(m<a[i])
			m = a[i];
	return m;
}
double v=1234.5;
