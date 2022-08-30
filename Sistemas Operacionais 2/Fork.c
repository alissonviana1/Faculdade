#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 6;
	pid_t pid;
	pid = fork();
	for (int i = 0; i < n; i++)
	{
		if(pid >= 0) // se pid = 0 ou pid > 0, rodará N+1 vezes.
		{
			continue;
		}
		else break;
	}
}

//caso não tenha nenhum erro, o for rodará 2^n vezes.