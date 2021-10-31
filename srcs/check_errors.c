#include "../includes/push_swap.h"

void    ft_quit(t_data *d)
{
    write(2, "Error\n", 6);
	if (d->med)
    	free(d->med);
	if (d->med_len)
		free(d->med_len);
	if (d->sorted)
		free(d->sorted);
	if (d->a)
		free(d->a);
	if (d->b)
		free(d->b);
	if (d->a_copy)
		free(d->a_copy);
	if (d->b_copy)
		free(d->b_copy);
    exit(0);
}

int	is_invalid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (ft_is_space(str[i]) != 1 && ft_isdigit(str[i]) != 1 && str[i] != '-')
			return (1);
			i++;
	}
	return (0);
}

void    check_no_doublon(t_data *d)
{
    int i;
    int j;

    i = 0;
    while (i < d->len)
    {
        j = i + 1;
        while (j < d->len)
        {
            if (d->a[i] == d->a[j])
                ft_quit(d);
            j++;
        }
        i++;
    }
}

int	check_argvs(int	ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_invalid(av[i]))
		{
			write(2, "Error\n", 6);//laisser ? checker correction.
			return (0);
		}
		i++;
	}
	return (1);
}
