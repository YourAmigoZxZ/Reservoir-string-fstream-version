#include "Reservoir.h"

int Reservoir :: surf_compare(const Reservoir& reserv) const noexcept
{
	{
		if (this->check_type(reserv))
		{
			if (this->surface() > reserv.surface())
			{
				return 1;
			}
			else if (this->surface() < reserv.surface())
			{
				return 2;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 400;
		}
	}
}