#ifndef FINDER_EXECUTER_H
#define FINDER_EXECUTER_H

#include "buffer.h"
#include "instance.h"
#include <dirent.h>
#include <errno.h>

/// Обход директорий и файлов
/// Конечный автомат

/**
 * Начальное состояние
 * @param path Путь к директории, которую надо обойти
 */
void start_iteration(const char* path);

/**
 * Состояние открытия директории
 */
void dir_open();

/**
 * Состояние итерирования
 */
void dir_iterate(DIR*);

/**
 * Обработка файла
 */
void process_file(const char*);

/**
 * Обработка директории
 */
void process_dir(const char*);

/**
 * бработка ошибок
 */
void process_error(const char*);

/**
 * Вывод в stdout содержимого Buffer
 */
void print(const Buffer*);

#endif //FINDER_EXECUTER_H
