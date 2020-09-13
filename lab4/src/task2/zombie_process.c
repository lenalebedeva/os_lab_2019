#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t child_pid;
    //Дочерний процесс
    child_pid = fork();
    if (child_pid == 0) {
        //В дочернем немедленно завершаем работу
        exit(0);
        printf("Child - exit \n");
    } 
    else {
        //В родительском - ждем 30с
        sleep(30);
        printf("Parent - 30 \n");
    }
 return 0;
}

// top | grep zombie
// Родительский процесс
// 3-я колонка показывает pid родительского процесса
// ps ajx | grep -w Z
// Смотрим, что за процесс
// ps auxww | grep [pid]
// Убиваем
// kill -9 [pid]