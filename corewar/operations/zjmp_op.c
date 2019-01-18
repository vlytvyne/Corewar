/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:00:12 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/11 17:00:12 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void		zjmp_debug(t_car *car, int arg)
{
	if (SHOW_OPERS)
	{
		ft_printf(OPER_INFO);
		ft_printf("%d ", arg);
		if (car->carry)
			ft_printf("OK\n");
		else
			ft_printf("FAILED\n");
	}
}

void		zjmp_op(t_cell *arena, t_car *car)
{
	int arg;

	arg = get_value(arena, (car->position + 1) % MEM_SIZE, OP.t_dir_size);
	if (car->carry)
	{
		car->position = (MEM_SIZE + car->position + arg % IDX_MOD) % MEM_SIZE;
		car->no_jump = 1;
	}
	zjmp_debug(car, arg);
}
