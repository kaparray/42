int		max(int* tab, unsigned int len)
{
	int max;
	int i = 0;

	if (!tab)
		return (0);

	while(len--) {
		if (tab[i] > tab[i + 1])
			max = tab[i];	
		i++;	
	}
	return (max);
}
