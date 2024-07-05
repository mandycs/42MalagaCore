void ft_args_parse(int argc, char **argv)
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
    else if (argc == 6)
    {
        n_phi = ft_atoi(argv[1]);
        t_die = ft_atoi(argv[2]);
        t_eat = ft_atoi(argv[3]);
        t_sleep = ft_atoi(argv[4]);
        n_eat = ft_atoi(argv[5]);
    }
}