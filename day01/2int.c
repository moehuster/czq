int bits(unsigned int d)
{
	int cnt=1;
	while(d>=10){
		d /= 10;
		cnt++;
	}
	return cnt;
}

