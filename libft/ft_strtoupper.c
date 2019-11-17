#include "libft.h"

char	*ft_strtoupper(const char *src)
{
	char	*s;
	int		i;
	int		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	if (!(s = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (src[i] >= 97 && src[i] <= 122)
			s[i] = src[i] - 32;
		else
			s[i] = src[i];
		i++;
	}
	return (s);
}