/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:06:59 by rvinnako          #+#    #+#             */
/*   Updated: 2017/01/29 19:12:52 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_functions.h"
#include "eval_expr.h"

int		ft_parsenum(char **exp)
{
	int	num;

	while (**exp == ' ')
		(*exp)++;
	if (**exp == '(')
	{
		(*exp)++;
		num = ft_parsesum(exp);
		if (**exp == ')')
			(*exp)++;
		return (num);
	}
	return (ft_atoi(exp));
}

int		ft_parsefact(char **exp)
{
	int 	num;
	int 	num2;
	char	op;

	num = ft_parsenum(exp);
	while (**exp)
	{
		while (**exp == ' ')
			(*exp)++;
		op = **exp;
		if (op != '/' && op != '*' && op != '%')
			return (num);
		(*exp)++;
		num2 = ft_parsenum(exp);
		if (op == '/')
			num = num / num2;
		else if (op == '*')
			num = num * num2;
		else
			num = num % num2;
	}
	return (num);
}

int		ft_parsesum(char **exp)
{
	int		num;
	int		num2;
	char	op;
	
	num = ft_parsefact(exp);
	while (**exp)
	{
		while (**exp == ' ')
			(*exp)++;
		op = **exp;
		if (op != '+' && op != '-')
		   return (num);
		(*exp)++;
		num2 = ft_parsefact(exp);
		if (op == '+')
			num = num + num2;
		else
			num = num - num2;	
	}
	return (num);
}

int		eval_expr(char *exp)
{
	return (ft_parsesum(&exp));
}
