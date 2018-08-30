/*
** client.c for navy-client in /home/neferett/EPITECH/PSU_2016_navy/client
**
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
**
** Started on  Mon Jan 30 13:20:12 2017 Jordan Bonaldi
** Last update Sat Feb  4 16:10:30 2017 Jordan Bonaldi
*/

# include "project.h"

static void             handle_attack(t_client *client)
{
  t_string		*pos;
  t_string              *s;

  s = init_string("NULL");
  pos = init_string("NULL");
  while (true)
    {
      my_printf("\nattack: ");
      pos->recreate(pos, get_next_line(0));
      if (!pos->first)
	continue;
      send_message(client, pos->str);
      s->recreate(s, receive_message(client));
      if (s->equalsIgnoreCase(s, "wrong position") &&
	  !my_printf("wrong position\n"))
	continue;
      break;
    }
  if (!my_strcmp("win", receive_message(client)) &&
      !my_printf("I win\n") && (client->endgame = true))
    return;
  my_printf("%s: %s\n", pos->str, s->str);
  attack_tab(client->enemy, pos->str, s);
}

static void             recept_attack(t_client *client)
{
  int                   mode;
  t_string              *recpt;

  recpt = init_string("NULL");
  while (true)
    {
      recpt->recreate(recpt, receive_message(client));
      if ((mode = attack(client, client->map, recpt->str, true)) == 1)
	continue;
      break;
    }
  if (mode == 2)
    my_printf("%s: missed\n", recpt->str);
  else if (mode == 3)
    my_printf("%s: hit\n", recpt->str);
  if (check_win(client->map))
    {
      send_message(client, "win");
      my_printf("Enemy won\n");
      client->endgame = false;
    }
  else if (send_message(client, "lolmdr"))
    return;
}

static void             game_play(t_client *client)
{
  while (!client->endgame)
    {
      my_printf("\nwaiting for enemy's attack...\n");
      recept_attack(client);
      if (client->endgame)
	break;
      handle_attack(client);
      my_printf("\nmy positions:\n");
      my_show_wordtab(client->map);
      my_printf("\nenemy's positions:\n");
      my_show_wordtab(client->enemy);
    }
}

int			client(int port, char *ip, char *file)
{
  t_client		*client;
  t_string		*str;

  client = init(port, ip);
  str = init_string("0");
  send_message(client, "connection");
  str->recreate(str, receive_message(client));
  if (!(client->map = create_tab(file)))
    return (1);
  my_printf("\nmy positions\n");
  my_show_wordtab(client->map);
  my_printf("\nenemy's positions:\n");
  my_show_wordtab(client->enemy);
  game_play(client);
  return (0);
}
