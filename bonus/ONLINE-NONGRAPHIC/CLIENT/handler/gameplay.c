/*
** gameplay.c for navy in /home/lucas99.06/PSU_2016_navy
**
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
**
** Started on  Tue Jan 31 14:46:30 2017 Lucas Benkemoun
** Last update Sat Feb  4 15:33:55 2017 Jordan Bonaldi
*/

#include "project.h"

boolean		check_win(char **map)
{
  int		i;
  int		j;

  i = 2;
  while (map[i])
    {
      j = 2;
      while (map[i][j] && map[i][j + 1])
	{
	  if (map[i][j] >= '0' && map[i][j] <= '9')
	    return (false);
	  j += 2;
	}
      i++;
    }
  return (true);
}

boolean		attack_tab(char **map, char *pos, t_string *msg)
{
  int		i;
  int		j;

  1 ? j = (pos[0] - 'A') * 2 + 2, i = pos[1] - '0' + 1 : 0;
  if (msg->equalsIgnoreCase(msg, "hit"))
    map[i][j] = 'x';
  if (msg->equalsIgnoreCase(msg, "missed"))
    map[i][j] = 'o';
  return (true);
}

int		attack(t_client *client, char **map, char *pos, boolean cansend)
{
  int		i;
  int		j;
  char		swap;

  (pos[0] < pos[1]) ? swap = pos[0], pos[0] = pos[1], pos[1] = swap : 0;
  1 ? j = (pos[0] - 'A') * 2 + 2, i = pos[1] - '0' + 1 : 0;
  if ((pos[0] && pos[1] && pos[2]) || (pos[0] && !pos[1]) ||
      (pos[0] < 'A' || pos[0] > 'H') || (pos[1] < '1' || pos[1] > '8'))
    {
      (cansend) ? send_message(client, "wrong position") : 0;
      return (1);
    }
  else if (map[i][j] == '.' || map[i][j] == 'o' || map[i][j] == 'x')
    {
      (cansend) ? send_message(client, "missed") : 0;
      (map[i][j] != 'x') ? map[i][j] = 'o' : 0;
      return (2);
    }
  else if (map[i][j] >= '0' && map[i][j] <= '9')
    {
      (cansend) ? send_message(client, "hit") : 0;
      map[i][j] = 'x';
      return (3);
    }
  return (0);
}
