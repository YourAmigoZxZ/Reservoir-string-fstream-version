#include "Reservoir.h"

void arr_maker(Reservoir*& Reservoirs, int& size)
{
	system("cls");

	Reservoir* new_Reservoirs = new Reservoir[++size];

	for (int i{ 0 }; i < size - 1; i++)
	{
		new_Reservoirs[i].set_name(Reservoirs[i].get_name());
		new_Reservoirs[i].set_type(Reservoirs[i].get_type());
		new_Reservoirs[i].set_width(Reservoirs[i].get_width());
		new_Reservoirs[i].set_length(Reservoirs[i].get_length());
		new_Reservoirs[i].set_depth(Reservoirs[i].get_depth());
	}

	Reservoirs = new_Reservoirs;
	new_Reservoirs = nullptr;
}