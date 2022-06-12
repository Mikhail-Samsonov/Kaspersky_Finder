#ifndef FINDER_CONTROLLER_H
#define FINDER_CONTROLLER_H

#include "buffer.h"

/**
 * структура для создания абстракций
 */
typedef struct
{
	void (* buf_start)(void);

	void (* buf_pushback)(const char*);

	void (* buf_stop)(void);

	void (* destroy)(void);

	Buffer* buffer;
} Controller;

#endif //FINDER_CONTROLLER_H
