/*
** server.c for server-navy in /home/neferett/EPITECH/PSU_2016_navy
**
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
**
** Started on  Mon Jan 30 13:38:20 2017 Jordan Bonaldi
** Last update Sat Feb  4 16:11:53 2017 Jordan Bonaldi
*/

# include "project.h"

static void		handle_attack(t_server *server)
{
  t_string		*pos;
  t_string		*s;

  s = init_string("NULL");
  pos = init_string("NULL");
  while (true)
    {
      my_printf("attack: ");
      pos->recreate(pos, get_next_line(0));
      if (!pos->first)
	continue;
      send_message(server, pos->str);
      s->recreate(s, receive_message(server));
      if (s->equalsIgnoreCase(s, "wrong position") &&
	  !my_printf("wrong position\n"))
	continue;
      break;
    }
  if (!my_strcmp("win", receive_message(server)) &&
      !my_printf("I win\n") && (server->endgame = true))
    return;
  my_printf("%s: %s\n", pos->str, s->str);
  attack_tab(server->enemy, pos->str, s);
}

static void		recept_attack(t_server *server)
{
  int			mode;
  t_string		*recpt;

  recpt = init_string("NULL");
  while (true)
    {
      recpt->recreate(recpt, receive_message(server));
      if ((mode = attack(server, server->map, recpt->str, true)) == 1)
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
  if (check_win(server->map) && send_message(server, "win")
      && !my_printf("Enemy won\n"))
    server->endgame = false;
  else if (send_message(server, "lolmdr"))
    return;
}

static void		game_play(t_server *server)
{
  while (!server->endgame)
    {
      my_printf("\n");
      handle_attack(server);
      if (server->endgame)
	break;
      my_printf("\nwaiting for enemy's attack...\n");
      recept_attack(server);
    }
}

int			server(int port, char *file)
{
  t_server		*server;
  t_string		*str;

  server = init(port);
  my_printf("waiting for enemy connection...\n");
  wait_connection(server);
  str = init_string(receive_message(server));
  if (str->equalsIgnoreCase(str, "connection"))
    send_message(server, "connected");
  my_printf("\nenemy connected\n");
  if (!(server->map = create_tab(file)))
    return (1);
  my_printf("\nmy positions:\n");
  my_show_wordtab(server->map);
  my_printf("\nenemy's positions:\n");
  my_show_wordtab(server->enemy);
  game_play(server);
  return (0);
}
