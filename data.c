#include "monty.h"

/**
 * data - data struct singleton pattern returns pointer to secret struct
 * Return: address of static struct
 */

data_t *data(void)
{
	static data_t _data = INIT_DATA;

	return (&_data);
}

/**
 * free_data - central controller method that frees all allocated data
 * @all: on if freeing all data
 */

void free_data(int all)
{
	if (data()->line)
	{
		free(data()->line);
		data()->line = NULL;
		ffree(data()->words);
		data()->words = NULL;
	}
  
	if (all)
	{
		if (data()->stack)
		{
			free_dlistint(data()->stack);
			data()->stack = NULL;
		}
		if (data()->fp)
		{
			fclose(data()->fp);
			data()->fp = NULL;
		}
	}
}
