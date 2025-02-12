#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/Libft/libft.h"

int main(int argc, char *argv[])
{
    t_node  *a;
    t_node  *b;


    if ((argc == 1) || (argc == 2 && argv[1][0] == 0))
        return (1);
    if (argc == 2)
        argv = ft_split(argv[1], 32);
    if (check_args(argv))
    {
        write(1, "Duplicates found!\n", 18);
        return (0);
    }
    
}