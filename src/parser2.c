#include <ft_ssl.h>

void		*md5_sha_init_data(void)
{
	t_md5_sha_data	*data;

	data = ft_memalloc(sizeof(t_md5_sha_data));
	(!data) ? ft_error_malloc() : 0;
	ft_bzero(data, sizeof(t_md5_sha_data));
	return (data);
}

static void	md5_sha_usage(char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putstr(" [-pqrtx] [-s string] [files ...]\n");
	// ft_printf("usage: %s [-pqrtx] [-s string] [files ...]\n", name);
	exit(0);
}

static void	p_handler(int *j, t_md5_sha_data *data)
{
	static char p_used;

	data->flags.p = 1;
	if (!p_used)
	{
		p_used = 1;
		data->input = read_data(0, &data->size);
		ft_putstr(data->input);
		// ft_printf("%s", data->input);
	}
	else
		data->input = ft_strdup("");
	(*j)++;
}

static void	s_handler(char *av[], int *i, int *j, t_command *command)
{
	t_md5_sha_data	*data;

	data = (t_md5_sha_data *)command->data;
	data->flags.s = 1;
	(*j)++;
	if (av[*i][*j])
	{
		data->name = &av[*i][*j];
		data->input = ft_strdup(&av[*i][*j]);
		data->size = ft_strlen(data->input);
		(*i)++;
		*j = 0;
		return ;
	}
	else if (av[*i + 1])
	{
		data->name = av[*i + 1];
		data->input = ft_strdup(av[*i + 1]);
		data->size = ft_strlen(data->input);
		*i += 2;
		*j = 0;
		return ;
	}
	ft_putstr(command->name);
	ft_putstr(": option requires an argument -- s\n");
	// ft_printf("%s: option requires an argument -- s\n", command->name);
	md5_sha_usage(command->name);
}

void		md5_sha_flag_router(char *av[], int *i, int *j, t_command *command)
{
	t_md5_sha_data *data;

	data = (t_md5_sha_data *)command->data;
	if (av[*i][*j] == 'q')
	{
		data->flags.q = 1;
		(*j)++;
	}
	else if (av[*i][*j] == 'r')
	{
		data->flags.r = 1;
		(*j)++;
	}
	else if (av[*i][*j] == 'p')
		p_handler(j, data);
	else if (av[*i][*j] == 's')
		s_handler(av, i, j, command);
	else
	{
		ft_putstr(command->name);
		ft_putstr(": illegal option -- ");
		ft_putchar(av[*i][*j]);
		ft_putstr("\n");
		// ft_printf("%s: illegal option -- %c\n", command->name, av[*i][*j]);
		md5_sha_usage(command->name);
	}
}
