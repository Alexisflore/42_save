# valgrind --suppressions=my_suppressions.supp --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3D
valgrind --suppressions=my_suppressions.supp --track-origins=yes ./cub3D cub/valid.cub
