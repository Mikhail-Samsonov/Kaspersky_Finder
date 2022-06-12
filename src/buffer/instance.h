#ifndef FINDER_INSTANCE_H
#define FINDER_INSTANCE_H

#include "controller.h"

/**
 * Предоставляет доступу к инстансу объекта Буфер
 * @return Указатель но контроллер
 */
Controller* get_instance();

#endif //FINDER_INSTANCE_H