int		ft_atoi(const char *str)
{
	int num = 0;
	int neg = 1;

	while (*str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' ||
				*str == '\r' || *str == '\v')
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				neg = -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			num = (num * 10) + (*str - '0');
			str++;
		}
		break ;
	}
	return (num * neg);
}