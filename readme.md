## Задание
Необходимо на языку программирования C реализовать программу 
для вывода на консоль всех обнаруженных файлов и каталогов. 
Программа представляет собой утилиту командной строки, которая запускается следующим образом:
 
#### finder  (start folder name)

- finder – имя утилиты
- start folder name – имя каталога с которого начинается поиск.

Вывод содержимого осуществляется, начиная с заданного каталога.
Программа должна вывести все дочерние файлы и каталоги, расположенных на
всех подуровнях заданного каталога. Количество файлов и подуровней каталогов
ничем не ограничено. Пример вывода данных для каталога /etc/X11.

- ./Xsession.options
- ./xsm
- ./xsm/system.xsm

    ####   ...

- ./Xsession.d/95dbus_update-activation-env
- ./Xsession.d/60x11-common_xdg_path
- ./rgb.txt

Если имя каталога не задано, то программа должны вывести сообщение об ошибке и завершиться.
Использование сторонних утилит (find, grep и т.п.)  для формирования
потока вывода не допускается. Не допускается использование семейства библиотек boost.

Возможно использование библиотек для работы со строками, 
файловой системой (за исключение nftw), потоками и т.п. В качестве системы 
сборки желательно использовать CMake.

Желательно включить в проект unit tests. Возможно использование любого 
знакомого\удобного фреймворка тестирования (Например, gtest, gmock и т.п.).

## Build
    chmod +x build.sh
    ./build.sh
## Test
    chmod +x test.sh
    ./test.sh
## Install
    sudo cmake --install ./build

## Usage
    ./finder <folderpath>

после установки

    finder <folderpath>
