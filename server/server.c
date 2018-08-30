/*
** server.c for server-navy in /home/neferett/EPITECH/PSU_2016_navy
**
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
**
** Started on  Mon Jan 30 13:38:20 2017 Jordan Bonaldi
** Last update	Thu Feb 16 12:16:08 2017 Jordan Bonaldi
*/

# include "project.h"

static void							show_pos(t_server *server)
{
  my_printf("%c", server->endgame ? '\0' : '\n');
  my_printf("\nmy positions:\n");
  my_show_wordtab(server->map);
  my_printf("\nenemy's positions:\n");
  my_show_wordtab(server->enemy);
  if (server->endgame && server->haswon)
    my_printf("\nI won\n");
  else if (server->endgame)
    my_printf("\nEnemy won\n");
}

static void		handle_attack(t_server *server)
{
  t_string		*pos;
  t_string		*s;

  s = init_string("NULL");
  pos = init_string("NULL");
  while (true)
    {
      my_printf("\nattack: ");
      pos->recreate(pos, get_next_line(0));
      if (!pos->first)
	continue;
      send_bin(server->pid, pos->str);
      s->recreate(s, recept_handler());
      if (s->equalsIgnoreCase(s, "wr") &&
	  !my_printf("wrong position\n"))
	continue;
      break;
    }
  my_printf("\n%s: %s\n", pos->str, s->str);
  attack_tab(server->enemy, pos->str, s);
  if (!my_strcmp("w", recept_handler()) &&
      (server->endgame = true)
      && (server->haswon = true))
    show_pos(server);
}

static void		recept_attack(t_server *server)
{
  int			mode;
  t_string		*recpt;

  recpt = init_string("NULL");
  while (true)
    {
      recpt->recreate(recpt, recept_handler());
      if ((mode = attack(server->pid, server->map, recpt->str, true)) == 1)
	continue;
      break;
    }
  if (mode == 2)
    my_printf("%s: missed\n", recpt->str);
  else if (mode == 3)
    my_printf("%s: hit\n", recpt->str);
  my_printf("\nmy positions:\n");
  my_show_wordtab(server->map);
  my_printf("\nenemy's positions:\n");
  my_show_wordtab(server->enemy);
  if (check_win(server->map) && send_bin(server->pid, "w") &&
    (server->endgame = true))
    my_printf("\nEnemy won\n");
  else if (send_bin(server->pid, "l"))
    return;
}

static void		game_play(t_server *server)
{
  while (!server->endgame)
    {
      handle_attack(server);
      if (server->endgame)
	       break;
      my_printf("\nwaiting for enemy's attack...\n");
      recept_attack(server);
    }
}

int			server(char *file)
{
  t_server		*server;
  t_string		*str;

  my_printf("my_pid: %d\n", getpid());
  my_printf("waiting for enemy connection...\n");
  str = init_string(recept_handler());
  if (!(server = init_server(str->toInt(str))))
    return (1);
  send_bin(str->toInt(str), "co");
  str->recreate(str, recept_handler());
  if (str->equalsIgnoreCase(str, "OK"))
    my_printf("\nenemy connected\n");
  else
    return (1);
  if (!(server->map = create_tab(file)))
    return (1);
  my_printf("\nmy positions:\n");
  my_show_wordtab(server->map);
  my_printf("\nenemy's positions:\n");
  my_show_wordtab(server->enemy);
  game_play(server);
  return (server->haswon ? 2 : 3);
}
