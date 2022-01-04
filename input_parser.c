#include "push_swap.h"
#include "libft/libft.h"

void	args_validation(size_t argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (!len)
			exit(EXIT_SUCCESS);
		j = 0;
		while(argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == ' ' || (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))) || (argv[i][j] == ' ' &&  argc != 2))
				ft_error(ERR_MSG);
			++j;
		}
		++i;
	}
}

void	check_int_bounds(size_t argc, char **argv)
{
	size_t	i;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num < MIN_OF_INT || num > MAX_OF_INT)
			ft_error(ERR_MSG);
		++i;
	}
}

void	check_duplicates(size_t argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strncmp(argv[i], argv[i + 1], 11) == 0)
				ft_error(ERR_MSG);
		++i;
	}
}
