#ifndef _EXECUTE_H
#define _EXECUTE_H
#include "builtin.h"
#include "launch.h"
#include <string.h>

int execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    return 1;
  }

  for (i = 0; i < num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return launch(args);
}

#endif