#include <ft_ssl.h>

void		ft_error_malloc()
{
	ft_putstr("Error with malloc\n");
	// ft_putstr("\n");
	// ft_printf("%s\n", s);
	exit(0);
}

static void	ft_str_join_free(char **dest, char *src,
			size_t dest_len, size_t src_len)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!(new = ft_strnew(dest_len + src_len)))
		ft_error_malloc();
	i = 0;
	while (i < dest_len)
	{
		new[i] = (*dest)[i];
		i++;
	}
	j = 0;
	while (j < src_len)
	{
		new[i] = src[j];
		i++;
		j++;
	}
	free(*dest);
	*dest = new;
}

char		*read_data(int fd, size_t *size)
{
	char	buf[BUFF_SIZE];
	char	*data;
	int		tmp;

	data = ft_strdup("");
	ft_bzero(buf, BUFF_SIZE);
	while ((tmp = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_str_join_free(&data, buf, *size, tmp);
		*size += tmp;
		ft_bzero(buf, BUFF_SIZE);
	}
	return (data);
}

size_t		reverse_bytes(size_t n, unsigned char bytes)
{
	size_t			res;
	unsigned char	*res_ptr;
	unsigned char	*n_ptr;
	unsigned char	i;

	res = n;
	n_ptr = (unsigned char *)&n;
	res_ptr = (unsigned char *)&res;
	i = 0;
	while (i < bytes)
	{
		res_ptr[i] = n_ptr[bytes - i - 1];
		i++;
	}
	return (res);
}

size_t		ft_unstrlen(unsigned char *str)
{
	size_t len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_putunstr(unsigned char *s)
{
	if (s)
		write(STDOUT_FILENO, s, ft_unstrlen(s));
}
