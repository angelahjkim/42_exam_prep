unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int i;
	unsigned int lower, greater;

	if (a == 0 || b == 0)
		return (0);
	lower = a;
	greater = b;
	if (a > b)
	{
		lower = b;
		greater = a;
	}
	i = greater;
	while (i <= lower * greater)
	{
		if (i % a == 0 && i % b == 0)
			return (i);
		i++;
	}
	return (0);
}