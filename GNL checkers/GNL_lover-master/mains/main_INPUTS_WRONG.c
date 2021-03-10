/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_INPUTS_WRONG.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 04:53:26 by charmstr          #+#    #+#             */
/*   Updated: 2021/01/05 23:47:55 by myuonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../copy_in_here_GNL_files/get_next_line.h"
#include "../copy_in_here_GNL_files/GNL_TESTS.h"

int	main(int argc, char *argv[])
{
	int 	fd_test_me;
	char	*line;
	int		result;

	line = NULL;
	result = 1;
	if (argc != 2)
	{
		my_ft_putstr_fd("failed to provide the file to be opened as arg\n", 2);
		return (0);
	}
	if((fd_test_me = open(argv[1], O_RDONLY)) == -1)
	{
		my_ft_putstr_fd("failed to open", 2);
		my_ft_putstr_fd(argv[1], 2);
		my_ft_putstr_fd("filedescriptor.\n", 2);
		return (0);
	}
	if (BUFFER_SIZE == 0)
		assert(-1 == get_next_line(fd_test_me, &line));
	else
	{
        write(1, "\tTEST!!!!!!\n", 12);
		assert(-1 == get_next_line(-1, &line));
		write(1, "-1, &line = OK\n", 15);
        free(line);
		line = NULL;
		assert(-1 == get_next_line(-42, &line));
        write(1, "-42, &line = OK\n", 16);
		free(line);
		line = NULL;
		assert(-1 == get_next_line(32, &line));
        write(1, "42, &line = OK\n", 15);
		free(line);
		line = NULL;
		assert(-1 == get_next_line(42, NULL));
        write(1, "42, NULL = OK\n", 14);
		free(line);
		line = NULL;
		assert(-1 == get_next_line(fd_test_me, NULL));
        write(1, "fd, NULL = OK\n", 14);
	}
	free(line);
	line = NULL;
	close(fd_test_me);
	return (0);
}
