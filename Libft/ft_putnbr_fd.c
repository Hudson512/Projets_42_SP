#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	// joga resultado itoa em ft_putstr_fd
	ft_putstr_fd(ft_itoa(n), fd);
}
