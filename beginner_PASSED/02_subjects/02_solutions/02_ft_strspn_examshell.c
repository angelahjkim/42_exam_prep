#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	int j = 0;
	int flag = 1;
	while (s[i] && flag)
	{
		j = 0;
		flag = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				flag = 1;
			j++;
		}
		if (!flag)
			return (i);
		i++;
	}
	return (i);
}