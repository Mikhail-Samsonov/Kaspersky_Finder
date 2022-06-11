#include <stdio.h>
#include "instance.h"
#include "executer.h"

int main(int argc, char** argv)
{


	if (argc != 2)
	{
		printf("usage: finder <dir_name>\n");
		return EXIT_FAILURE;
	} else
	{
		get_instance()->buf_start();

		start_iteration(argv[1]);

		get_instance()->destroy();
	};

	return EXIT_SUCCESS;
}
