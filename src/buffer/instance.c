#include "instance.h"

void buf_start_impl()
{
	buffer_start(get_instance()->buffer);
}

void buf_pushback_impl(const char* c)
{
	buffer_push_back(get_instance()->buffer, c);
}

void buf_stop_impl()
{
	buffer_stop(get_instance()->buffer);
}

void destroy_impl()
{
	get_instance()->buf_stop();
	free(get_instance()->buffer);
	free(get_instance());
}

Controller* get_instance()
{
	static Controller* instance = NULL;

	if (!instance)
	{
		instance = malloc(sizeof(Controller));
		if (!instance)
		{
			perror("Controller malloc instance: ");
			exit(EXIT_FAILURE);
		}

		instance->buffer = malloc(sizeof(Buffer));
		if (!instance->buffer)
		{
			perror("Controller malloc buffer: ");
			free(instance);
			exit(EXIT_FAILURE);
		}

		instance->buf_start = buf_start_impl;
		instance->buf_pushback = buf_pushback_impl;
		instance->buf_stop = buf_stop_impl;
		instance->destroy = destroy_impl;
	}

	return instance;
};