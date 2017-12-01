/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:48:44 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 17:46:32 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;

	if (argc != 3)
		return (0);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);

	if (fd1== -1 || fd2 == -1)
		return (0);
	/*while (get_next_line(fd, &line))
		printf("%s\n", line);*/

	printf("FDS : %i, %i\n", fd1, fd2);

	get_next_line(fd1, &line);
	printf("%s\n", line);

	get_next_line(fd2, &line);
	printf("%s\n", line);

	get_next_line(fd1, &line);
	printf("%s\n", line);

	get_next_line(fd2, &line);
	printf("%s\n", line);

	close(fd1);
	close(fd2);
	return (0);
}
