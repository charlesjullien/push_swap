#include "../includes/push_swap.h"

long int	ft_atoi(char *str, int *j)
{
	int	i;
	int	sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-')
    {
		sign = -1;
        i++;
    }
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	*j = *j + i;
	return (nb * sign);
}

void    get_len(t_data *d, int ac, char **av)
{
    int	i;
	int	j;

	i = 1;
	j = 0;
    d->len = 0;
	while (i < ac)
	{
        j = 0;
		while (av[i][j] && is_invalid(av[i]) == 0)
		{
			if (is_invalid(&av[i][j]))
				ft_quit(d);
            while (ft_isdigit(av[i][j]) || av[i][j] == '-')
                j++;
            while (ft_is_space(av[i][j]))
                j++;
            d->len++;
		}
		i++;
	}
	if (d->len == 1)
		ft_quit(d);
	d->len_a = d->len;
	d->len_b = 0;
}

void    parser(t_data *d, int ac, char **av)
{
    int	i;
	int	j;
	int k;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
        j = 0;
		while (av[i][j] && is_invalid(av[i]) == 0)
		{
			if (is_invalid(&av[i][j]))
				ft_quit(d);
			d->a[k] = ft_atoi(&av[i][j], &j);
			if (d->a[k] < -2147483648 || d->a[k] > 2147483647)
				ft_quit(d);
            k++;
		}
		i++;
	}
}