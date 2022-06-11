#ifndef FINDER_BUFFER_H
#define FINDER_BUFFER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	char* data;
	size_t start;
	size_t used;
	size_t capacity;
} Buffer;

void buffer_start(Buffer*);
void buffer_push_back(Buffer*, const char*);
void buffer_stop(Buffer*);

#endif //FINDER_BUFFER_H
