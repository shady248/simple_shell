#include "main.h"

/**
  * cd_shell - resposible for changing the current
  * directory
  * @datash: data relevant
  * Return: 1 if successful
  */
int cd_shell(data_shell *datash)
{
	char *dir;
	int ishome;
	int ishome_2;
	int isdouble_dash;

	dir =  datash->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome_2 = _strcmp("~", dir);
		isdouble_dash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome_2 || !isdouble_dash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
