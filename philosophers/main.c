/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:47:01 by mancorte          #+#    #+#             */
/*   Updated: 2024/07/05 19:53:36 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	if (argc != 5 || argc != 6)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
	if (argc == 5)
	{
		n_phi = ft_atoi(argv[1]);
		t_die = ft_atoi(argv[2]);
		t_eat = ft_atoi(argv[3]);
		t_sleep = ft_atoi(argv[4]);
	}
	if (argc == 6)
	{
		n_phi = ft_atoi(argv[1]);
		t_die = ft_atoi(argv[2]);
		t_eat = ft_atoi(argv[3]);
		t_sleep = ft_atoi(argv[4]);
		n_eat = ft_atoi(argv[5]);
	}
}
