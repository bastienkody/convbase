/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:44:47 by bguillau          #+#    #+#             */
/*   Updated: 2022/08/31 18:57:55 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convbase.h"

int	ft_reslen(int nbr, char *base)
{
	int	reslen;

	if (nbr < 0)
		reslen = 1;
	else if (nbr == 0)
		reslen = 1;
	else
		reslen = 0;
	while (nbr)
	{
		nbr /= ft_strlen(base);
		reslen += 1;
	}
	reslen += 1;
	return (reslen);
}	

char	*ft_itoa_base(int nbr, char *base)
{
	char			*res;
	unsigned int	nb;
	int				reslen;

	reslen = ft_reslen(nbr, base);
	res = malloc(reslen * sizeof(char));
	if (!res)
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nb = nbr * -1;
	}
	else
		nb = nbr;
	res[reslen--] = '\0';
	if (nb == 0)
		res[--reslen] = base[nb % ft_strlen(base)];
	while (nb)
	{
		res[--reslen] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	return (res);
}
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (check_base(base_from) || check_base(base_to))
	{
		print_base_uncorrect();
		return (NULL);
	}
	if (check_nbr_base(nbr, base_from))
	{
		print_nbr_base_uncorrect();
		return (NULL);
	}
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
}

int	main(int argc, char **argv)
{
	char	*res;

 	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
		print_help();
	if (argc < 4)
	{
		print_usage();
		return (-1);
	}

	res = ft_convert_base(argv[1], argv[2], argv[3]);
	if (res)
	{
//		printf("%p\n", res);
		printf("%s\n", res);
	}
	return (0);
}
