#include "ft_ls.h"

void	ft_put_off_t(off_t nb)
{
	if (nb >= 10)
		ft_put_off_t(nb / 10);
	ft_putchar(nb % 10 + '0');
}
