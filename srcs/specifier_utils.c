#include "specifier.h"
#include "libft.h"

static int	is_specifier(t_specifier *specifier)
{
	return (ft_strchr("diuoxXfFeEgGaAcspn%", specifier->specifier) != NULL);
}

int			is_integer(t_specifier *specifier)
{
	return (ft_strchr("diuoxX", specifier->specifier) != NULL);
}

int			is_float(t_specifier *specifier)
{
	return	(ft_strchr("fFeEgGaA", specifier->specifier) != NULL);
}
