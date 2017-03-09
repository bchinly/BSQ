/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:46:35 by biremong          #+#    #+#             */
/*   Updated: 2016/11/16 22:15:12 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	t_node		*begin_list;
	t_node		*tail_list;
	int			i;

	i = 1;
	begin_list = NULL;
	tail_list = NULL;
	if (argc >= 2)
	{
		while (i + 1 <= argc)
		{
			read_files(argv[i], &begin_list, &tail_list);
			mr_list(begin_list);
			i++;
		}
	}
	if (argc == 1)
	{
		save_stdin(&begin_list, &tail_list);
		mr_list(begin_list);
	}
	return (0);
}

int		save_stdin(t_node **begin_list, t_node **tail_list)
{
	int		ret;
	char	buf[1];

	while ((ret = read(0, buf, 1)))
	{
		if (ret < 0)
		{
			write(2, "read() error!", 13);
			return (1);
		}
		push_node(begin_list, tail_list, buf[0]);
	}
	return (0);
}

int		read_files(char *argv, t_node **begin_list, t_node **tail_list)
{
	int		ret;
	int		fd;
	char	buf[1];

	fd = open(((char*)argv), O_RDONLY);
	if (fd == -1)
	{
		write(2, "open() error!", 13);
		return (1);
	}
	while ((ret = read(fd, buf, 1)))
	{
		if (ret < 0)
		{
			write(2, "read() error!", 13);
			return (1);
		}
		push_node(begin_list, tail_list, buf[0]);
	}
	if (close(fd) == -1)
	{
		write(2, "close() error!", 13);
		return (1);
	}
	return (0);
}
