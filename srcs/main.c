/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:52:55 by cjullien          #+#    #+#             */
/*   Updated: 2021/10/31 18:08:42 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_tab(long *tab, t_data *data)
{
	long	i;

	i = 0;
	printf("\n");
	while (i < data->len)
	{
		printf("%ld, ", tab[i]);
		i++;
	}
	printf("\n\n\n");
}

void	get_out_of_range_num(t_data *d)
{
	long	i;

	i = 0;
	d->to_fill = -888888;
	while (i < d->len)
	{
		if (d->a[i] == d->to_fill)
		{
			d->to_fill++;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (i < d->len)
	{
		d->b[i] = d->to_fill;
		i++;
	}
}

void	sorter(t_data *d)
{
	get_out_of_range_num(d);
	copy_stacks(d);
	get_a_sorted(d);
	//printf("len = %d, a = %d, b = %d\n", d->len, d->len_a, d->len_b);
	int i = 0;
	while (i < d->len)
	{
		printf("%ld, ", d->a[i]);
		i++;
	}
	printf("\n\n");
	if (d->len <= 2)
		sort_two(d);
	else if (d->len == 3)
		sort_three(d);
	else if (d->len == 4)
		sort_four(d);
	else if (d->len == 5)
		sort_five(d);
	else
		sort_6_or_more(d);
}

void	struct_init(t_data *data)
{
	printf("len = %ld\n", data->len);
	data->a = malloc(sizeof(long) * data->len);
	data->b = malloc(sizeof(long) * data->len);
	data->a_copy = malloc(sizeof(long) * data->len);
	data->b_copy = malloc(sizeof(long) * data->len);
	data->sorted = malloc(sizeof(long) * data->len);
	data->chunks = data->len / 80;
	if (data->len % 80)
		data->chunks++;
	data->med = malloc(sizeof(long) * data->chunks);
	data->med_len = malloc(sizeof(long) * data->chunks);

	if (data->a == NULL || data->b == NULL || data->a_copy == NULL
		|| data->b_copy == NULL || data->sorted == NULL || data->med == NULL ||
		data->med_len == NULL)
		ft_quit(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (0);
	if (check_argvs(ac, av) == 0)
		return (0);
	get_len(&data, ac, av);
	struct_init(&data);
	if (data.len == 1)
		ft_quit(&data);
	parser(&data, ac, av);
	check_no_doublon(&data);
	get_min_max(&data);
	sorter(&data);
	print_tab(data.a, &data);
	return (0);
}
