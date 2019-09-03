/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:17:58 by cspider           #+#    #+#             */
/*   Updated: 2019/09/02 22:18:11 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	print_file(char name[])
{
	int		fd;
	char	buf[4];

	fd = open(name, O_RDONLY);
	while (read(fd, buf, sizeof(buf)))
		write(1, buf, sizeof(buf));
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else if (argc < 2)
		write(1, "File name missing.\n", 19);
	else if (argc == 2)
		print_file(argv[1]);
	return (0);
}
