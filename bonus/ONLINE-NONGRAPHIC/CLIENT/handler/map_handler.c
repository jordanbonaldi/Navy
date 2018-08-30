/*
** map_handler.c for navy in /home/lucas99.06/PSU_2016_navy/handler
**
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
**
** Started on  Mon Jan 30 15:14:47 2017 Lucas Benkemoun
** Last update Wed Feb  1 15:37:32 2017 Jordan Bonaldi
*/

#include "project.h"

char			**is_swap(char *s)
{
  char			**boat;
  char			swap;

  boat = my_str_to_wordtab(s, ':');
  if (boat[1][1] >= 'A' && boat[1][1] <= 'H')
    {
      swap = boat[1][1];
      boat[1][1] = boat[1][0];
      boat[1][0] = swap;
    }
  if (boat[2][1] >= 'A' && boat[2][1] <= 'H')
    {
      swap = boat[2][1];
      boat[2][1] = boat[2][0];
      boat[2][0] = swap;
    }
  return (boat);
}

int			calcul(t_boat boat, char **tab)
{
  if (boat.boat[1][0] == boat.boat[2][0])
    {
      my_swap(&boat.i, &boat.i_max);
      while (boat.length--)
	{
	  if (tab[boat.i][boat.j] && tab[boat.i][boat.j] == '.' &&
	      (tab[boat.i][boat.j] = boat.boat[0][0])) {}
	  else
	    return (1);
	  boat.i += 1;
	}
    }
  else
    {
      my_swap(&boat.j, &boat.j_max);
      while (boat.length--)
	{
	  if (tab[boat.i][boat.j] && tab[boat.i][boat.j] == '.' &&
	      (tab[boat.i][boat.j] = boat.boat[0][0])) {}
	  else
	    return (1);
	  boat.j += 2;
	}
    }
  return (0);
}

int			draw_boat(char *s, char **tab)
{
  t_boat		boat;

  boat.boat = is_swap(my_strdup(s));
  1 ? boat.j = (boat.boat[1][0] - 'A') * 2 + 2,
    boat.i = boat.boat[1][1] - '0' + 1, boat.length = boat.boat[0][0] - '0',
    boat.j_max = (boat.boat[2][0] - 'A') * 2 + 2,
    boat.i_max = boat.boat[2][1] - '0' + 1 : 0;
  if (boat.boat[0][0] < '2' || boat.boat[0][0] > '5')
    return (1);
  if (boat.boat[1][0] < 'A' || boat.boat[1][0] > 'H')
    return (1);
  if (boat.boat[2][0] < 'A' || boat.boat[2][0] > 'H')
    return (1);
  if (boat.boat[2][1] < '1' || boat.boat[2][1] > '8')
    return (1);
  if (boat.boat[1][1] < '1' || boat.boat[1][1] > '8')
    return (1);
  if (calcul(boat, tab))
    return (1);
  if (!tab[boat.i_max][boat.j_max] || tab[boat.i_max][boat.j_max] == '.')
    return (1);
  return (0);
}

char		**create_tab(char *path)
{
  char		**tab;
  int		fd;
  char		*s;

  if (!(tab = malloc(sizeof(*tab) * 11)) ||
      (fd = open(path, O_RDONLY)) < 0)
    return (NULL);
  tab = init_tab(tab);
  while ((s = get_next_line(fd)))
    {
      if (draw_boat(s, tab))
	return (NULL);
      else
	free(s);
    }
  if (close(fd) < 0)
    return (NULL);
  return (tab);
}
