/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidos-sa <tidos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:41:10 by tidos-sa          #+#    #+#             */
/*   Updated: 2025/05/06 22:11:03 by tidos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_handler(int signal, siginfo_t *info, void *notused)
{
	static int	count = CHAR_SIZE - 1;
	static int	value = 0;

	(void)notused;
	if (signal == SIGUSR2)
		value += 1 << count;
	count--;
	if (count < 0)
	{
		if (value == 0)
		{
			ft_putchar('\n', 1);
			send_message("Done", info->si_pid);
		}
		else
			ft_putchar(value, 1);
		count = CHAR_SIZE - 1;
		value = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	action.sa_sigaction = bit_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	ft_putnbr(pid, 1);
	ft_putstr("\n", 1);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		;
}
