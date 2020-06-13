#ifndef _LAUNCH_H
#define _LAUNCH_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int launch(char **args)
{
    pid_t pid, wpid;
    int status;
	pid = fork();
	if(pid ==0)
	{
		if(execvp(args[0],args)==-1)
		{
			perror("osh");
		}
		exit(EXIT_FAILURE);
	}else if(pid<0)
	{
		perror("osh");
	}else{
		do{
			wpid=waitpid(pid, &status, WUNTRACED);
		}while(!WIFEXITED(status)&&!WIFSIGNALED(status));
	}
	return 1;
}

#endif