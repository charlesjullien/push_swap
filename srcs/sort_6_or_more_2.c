#include "../includes/push_swap.h"

void    get_index_min_max_2(t_data *d, long *min, long *max, long i)
{
    if (d->b[i] < *min)
    {
        d->index_min = i;
        *min = d->b[i];
    }
    if (d->b[i] > *max)
    {
        d->index_max = i;
        *max = d->b[i];
    }
}

void	move_chunk_into_a_2(t_data *d)
{
    while (d->moves_selected > 0)
    {
        if (d->dir_selected == 0)
            op_rb(d);
        else
        {
            if (d->len_b > 1)
                op_rrb(d);
        }
        d->moves_selected--;
    }
    op_pa(d);
    if (d->len_a > 1 && d->index_selected != d->index_max)
        op_ra(d);
}