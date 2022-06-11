#ifndef FINDER_EXECUTER_H
#define FINDER_EXECUTER_H

#include "buffer.h"
#include "instance.h"
#include <dirent.h>
#include <errno.h>

void start_iteration(const char* path);

void dir_open();
void dir_iterate(DIR*);

void process_file(const char*);
void process_dir(const char*);

void process_error(const char*);

void print(const Buffer*);

#endif //FINDER_EXECUTER_H
