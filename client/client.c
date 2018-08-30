/*
** client.c for navy-client in /home/neferett/EPITECH/PSU_2016_navy/client
**
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
**
** Started on  Mon Jan 30 13:20:12 2017 Jordan Bonaldi
** Last update	Thu Feb 16 12:08:15 2017 Jordan Bonaldi
*/

# include "project.h"

static void							show_pos(t_client *client)
{
  my_printf("\nmy positions:\n");
  my_show_wordtab(client->map);
  my_printf("\nenemy's positions:\n");
  my_show_wordtab(client->enemy);
  if (client->endgame && client->haswon)
    my_printf("\nI won\n");
  else if (client->endgame)
    my_printf("\nEnemy won\n");
}

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
      send_bin(client->pid, pos->str);
      s->recreate(s, recept_handler());
      if (s->equalsIgnoreCase(s, "wr") &&
	  !my_printf("wrong position\n"))
	continue;
      break;
    }
  my_printf("\n%s: %s\n", pos->str, s->str);
  attack_tab(client->enemy, pos->str, s);
  if (!my_strcmp("w", recept_handler())
      && (client->endgame = true) && (client->haswon = true)) {}
}

static void             recept_attack(t_client *client)
{
  int                   mode;
  t_string              *recpt;

  recpt = init_string("NULL");
  while (true)
    {
      recpt->recreate(recpt, recept_handler());
      if ((mode = attack(client->pid, client->map, recpt->str, true)) == 1)
	continue;
      break;
    }
  if (mode == 2)
    my_printf("%s: missed\n", recpt->str);
  else if (mode == 3)
    my_printf("%s: hit\n", recpt->str);
  if (check_win(client->map) && send_bin(client->pid, "w") &&
        (client->endgame = true))
      show_pos(client);
  else if (send_bin(client->pid, "l"))
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
      show_pos(client);
    }
}

int			client(int pid, char *file)
{
  t_client		*client;
  t_string		*str;

  if (!(client = init_client(pid)))
    return (1);
  my_printf("my_pid: %d\n", getpid());
  str = init_string("0");
  str->toString(str, getpid());
  send_bin(pid, str->str);
  str->recreate(str, recept_handler());
  if (str->equalsIgnoreCase(str, "co"))
    my_printf("successfully connected\n");
  else
    return (1);
  send_bin(pid, "OK");
  if (!(client->map = create_tab(file)))
    return (1);
  my_printf("\nmy positions:\n");
  my_show_wordtab(client->map);
  my_printf("\nenemy's positions:\n");
  my_show_wordtab(client->enemy);
  game_play(client);
  return (client->haswon ? 2 : 3);
}
