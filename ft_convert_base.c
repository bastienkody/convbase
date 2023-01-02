/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:07:43 by bguillau          #+#    #+#             */
/*   Updated: 2022/08/30 14:01:12 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	search_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_nbr_base(char *nbr, char *base)
{
	while ((*nbr >= '\t' && *nbr <= '\r') || *nbr == ' ' || *nbr == '-' || *nbr == '+')
		nbr++;
	while (*nbr)
	{
		if (search_index(*nbr, base) == -1)
			return (1);
		nbr++;
	}
	return (0);
}

int	check_base(char *base)
{
	char	*ptr;

	if (ft_strlen(base) < 2)
		return (1);
	while (*base)
	{
		if ((*base >= '\t' && *base <= '\r') || *base == ' '
			|| *base == '+' || *base == '-')
			return (1);
		ptr = base;
		while (*ptr++)
		{
			if (*base == *ptr)
				return (1);
		}
		base++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	sign;
	int	len;

	len = ft_strlen(base);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ' )
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	nb = 0;
	while (search_index(*str, base) != -1)
	{
		nb = nb * len + ((search_index(*str, base)) % len);
		str++;
	}
	return (nb * sign);
}
