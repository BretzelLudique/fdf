
#include "fdf.h"

void	ptit_free(t_tab *tab)
{
	int	i;

	if (!tab)
		return ;
	if (!tab->data)
	{
		free(tab);
		return ;
	}
	i = -1;
	while (tab->data[++i] && i < tab->y_size)
		free((tab->data)[i]);
	free(tab);
}

t_tab	*new_tab(void **data, int x_size, int y_size)
{
	t_tab	*tab;

	if (!(tab = (t_tab *)malloc(sizeof(t_tab))))
	{
		ptit_free(tab);
		return (0);
	}
	if (data)
		tab->data = data;
	tab->x_size = x_size;
	tab->y_size = y_size;
	return (tab);
}
