#include "Reservoir.h"

int Reservoir :: surf_compare(const Reservoir& reserv1, const Reservoir& reserv2) const noexcept
{
	{
		if (reserv1.check_type(reserv2))
		{
			if (reserv1.surface() > reserv2.surface())
			{
				return 1;
			}
			else if (reserv1.surface() < reserv2.surface())
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