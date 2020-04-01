unsigned int BKDRhash(char *s, int len)
{
	unsigned int Seed = 131;
	unsigned int Hash = 0;
	for(int i = 0; i < len; i++)
		Hash = Hash * Seed + s[i];
	return (Hash & 0x7ffff);
}
