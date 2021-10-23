#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <curses.h>
#include <term.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define ERROR -1
#define EXIT 2
#define SUCCESS 0

typedef struct s_command
{
	char *command;
	char *arg;
	char *option;
	char *redirection;
	bool piped;
	char *output;
	// struct s_command *next;
} t_command;

#include "getNextLine/gnl.h"
#include "tool/tool.h"
#include "command/command.h"
#include "parsing/parsing.h"
#include "execution/execution.h"