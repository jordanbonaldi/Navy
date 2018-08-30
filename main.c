/*
** main.c for main in /home/Neferett/bin/IMPORT
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update Wed Feb 15 19:57:44 2017 Jordan Bonaldi
*/

#include "project.h"

int		main(int argc, char **argv)
{
  int		ret;

  ret = 0;
  if (((argc != 2 && argc != 3) ||
       (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && !argv[1][2]))
      && !my_printf("USAGE\n\t./navy [first_player_pid] navy_positions"
		    "\n\nDESCRIPTION\n\tfirst_player_pid\tonly for the "
		    "2nd player. pid of the first player.\n\tnavy_posit"
		    "ions\t\tfile representing the positions of the ships.\n"))
    return (84);
  if (argc == 3 &&
      (check_map(argv[2]) ||
       (ret = client(my_getnbr(argv[1]), argv[2])) == 1))
    return (84);
  else if (argc == 2 && (check_map(argv[1]) || (ret = server(argv[1])) == 1))
    return (84);
  return (ret == 2 ? 0 : 1);
}
