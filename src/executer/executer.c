#include "executer.h"

void start_iteration(const char* path)
{
	get_instance()->buf_pushback(path);

	get_instance()->buffer->start = get_instance()->buffer->used;

	dir_open(get_instance()->buffer->data);
}

void dir_open()
{
	size_t used = get_instance()->buffer->used;

	DIR* dir = opendir(get_instance()->buffer->data);
	if (!dir)
	{
		process_error("opendir");
	}

	get_instance()->buf_pushback("/");

	dir_iterate(dir);

	closedir(dir);

	get_instance()->buffer->used = used;
}


void dir_iterate(DIR* dir)
{
	struct dirent* result = NULL;

	while ((result = readdir(dir)))
	{
		if (!strcmp(".", result->d_name) || !strcmp("..", result->d_name))
			continue;

		if (result->d_type == DT_REG)
		{
			process_file(result->d_name);
		}

		if (result->d_type == DT_DIR)
		{
			size_t used = get_instance()->buffer->used;

			process_dir(result->d_name);
			get_instance()->buffer->used = used;
		}
	}

	int err = errno;
	if(err)
	{
		//process_error("readdir");
	}
}

void process_file(const char* filename)
{
	print(get_instance()->buffer);
	puts(filename);
}


void process_dir(const char* dirname)
{
	print(get_instance()->buffer);
	puts(dirname);

	get_instance()->buf_pushback(dirname);

	dir_open();
}

void process_error(const char* src)
{
	int err = errno;
	printf("%s %s: %s\n", src, get_instance()->buffer->data, strerror(err));
	get_instance()->destroy();
	exit(EXIT_FAILURE);
}


void print(const Buffer* buffer)
{
	putchar('.');

	for (size_t i = buffer->start; i < buffer->used; ++i)
	{
		putchar(buffer->data[i]);
	}
}