/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidos-sa <tidos-sa@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:40:27 by tidos-sa          #+#    #+#             */
/*   Updated: 2025/05/06 18:40:34 by tidos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_handler(int signal)
{
	static int	count = CHAR_SIZE - 1;
	static int	value = 0;

	if (signal == SIGUSR2)
		value += 1 << count;
	count--;
	if (count < 0)
	{
		if (value == 0)
		{
			ft_putstr("\n", 1);
			exit(0);
		}
		else
			ft_putchar(value, 1);
		count = CHAR_SIZE - 1;
		value = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
		ft_error_message();
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, bit_handler);
	signal(SIGUSR2, bit_handler);
	send_message(message, server_pid);
	while (1)
		pause();
}
