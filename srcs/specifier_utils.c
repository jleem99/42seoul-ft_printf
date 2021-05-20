#include "specifier.h"
#include "libft.h"

void		resolve_specifier(t_specifier *specifier)
{
	specifier->apply_zero =
		specifier->f_zero && specifier->precision == -1 && !specifier->f_minus;
}

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
