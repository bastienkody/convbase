#ifndef CONVBASE_H
# define CONVBASE_H

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_nbr_base(char *nbr, char *base);
int	check_base(char *base);
int	ft_strlen(char *str);
void	print_usage(void);
void	print_help();
void	print_base_uncorrect(void);
void	print_nbr_base_uncorrect(void);

#endif
