#include "buffer.h"
#include "instance.h"

void buffer_widen(Buffer* b)
{
	b->capacity *= 2;
	b->data = realloc(b->data, b->capacity * sizeof(char));
	if (!b->data)
	{
		perror("Buffer malloc data: ");
		get_instance()->destroy();
		exit(EXIT_FAILURE);
	}
}

void buffer_start(Buffer* b)
{
	b->data = NULL;
	b->start = 0;
	b->used = 0;
	b->capacity = 128;

	buffer_widen(b);
}

void buffer_push_back(Buffer* b, const char* c)
{
	while (b->used + strlen(c) >= b->capacity)
		buffer_widen(b);

	memmove(b->data + b->used, c, strlen(c) + 1);

	b->used = b->used + strlen(c);
}

void buffer_stop(Buffer* b)
{
	if (b->data)
	{
		free(b->data);
		b->data = NULL;
	}

	b->start = 0;
	b->used = 0;
	b->capacity = 0;
}