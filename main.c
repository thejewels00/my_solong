#include "so_long.h"

int main(int argc, char **argv)
{
    t_data  all;
    if (argc != 2)
    {
        write(1,"USAGE : ./so_long  Map.ber\n", 28);
        return (0);
    }
    error_management(argv[1], &all);

}