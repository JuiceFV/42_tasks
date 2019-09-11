
// Checks connection counts, if we have 6 or 8 connections, the tetra is
// valid. Otherwise, our tetra is not continuous.
int	connections(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	//i < 20 if string contains '\n'
	while (i < 16)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 16 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			//+/- 5 if string contains '\n'
			if ((i + 4) < 16 && str[i + 4] == '#')
				block++;
			if ((i - 4) >= 0 && str[i - 4] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

//Checks character counts and that format is valid.
int counts_hecker(char *str, int count)
{
	int i;
	int blocks;

	i = 0;
	blocks = 0;
	//i < 20 if string contains '\n'
	while (i < 16)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocks > 4)
				return (2);
		}
		/* uncomment if you using '\n' (size = 20)
		else if (str[i] != '\n')
			return (3);
			*/
		i++;
	}
	//if str with a '\n' count == 21 and str[20] != '\n'
	if (count == 17 && str[16] != '\n')
		return (4);
	if (!check_connection(str))
		return (5);
	return (0);
}