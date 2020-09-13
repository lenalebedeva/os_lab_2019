#include <errno.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <getopt.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
struct Indicators {
  int begin;
  int end;
};
int mod;
int result = 1;

void getFactorial(void *args) {
  struct Indicators *thread_args = (struct Indicators *)args;
  int Multi = 1;
  int i;
  for (i = (*thread_args).begin; i <= (*thread_args).end; i++)
    Multi *= i;
  //Блокируем доступ к общ переменной
  pthread_mutex_lock(&mut);
  int previous = result;
  result = (previous * Multi) % mod;
  printf("Indicators %d - %d\nPrevious_result: %d, Current_result: %d\n", (*thread_args).begin, (*thread_args).end, previous, result);
  //Открываем доступ
  pthread_mutex_unlock(&mut);
}

int main(int argc, char **argv) {
  //Обработка аргументов
  int k = -1;
  int pnum = -1;
  mod = -1;
  while (true) {
    int current_optind = optind ? optind : 1;
    static struct option options[] = {{"k", required_argument, 0, 0},
                                      {"pnum", required_argument, 0, 0},
                                      {"mod", required_argument, 0, 0},
                                      {0, 0, 0, 0}};
    int option_index = 0;
    int c = getopt_long(argc, argv, "f", options, &option_index);
    if (c == -1) break;
    switch (c) {
      case 0:
        switch (option_index) {
          case 0:
            k = atoi(optarg);
            if (k <= 0) {
                printf("k is a positive number\n");
                return 1;
            }
            break;
          case 1:
            pnum = atoi(optarg);
            if (pnum <= 0) {
                printf("pnum is a positive number\n");
                return 1;
            }
            break;
          case 2:
            mod = atoi(optarg);
            if (mod < 1) {
                printf("mod is a positive number\n");
                return 1;
            }
            break;
          defalut:
            printf("Index %d is out of options\n", option_index);
        }
        break;
      case '?':
        break;
      default:
        printf("getopt returned character code 0%o?\n", c);
    }
  }
  if (optind < argc) {
    printf("Has at least one no option argument\n");
    return 1;
  }
  if (k == -1 || pnum == -1 || mod == -1) {
    printf("Usage: %s --k \"num\" --pnum \"num\" --mod \"num\" \n",
           argv[0]);
    return 1;
  }
  
  //Создаём необходимое кол-во потоков
  pthread_t threads[pnum];
  //Создаём соответствующие потокам показатели begin и end
  struct Indicators args[pnum];
  //Разбиваем число k
  int i;
  for (i = 0; i < pnum; i++) {
      args[i].begin = (k/pnum)*i + 1;
      args[i].end = (k/pnum)*(i+1);
      if (pthread_create(&threads[i], NULL, (void *)getFactorial, (void *)(args+i))) {
        printf("Error: pthread_create failed!\n");
        return 1;
      }
  }
  //Завершаем потоки
  for (i = 0; i < pnum; i++) {
    pthread_join(threads[i], NULL);
  }
  printf("Final_result: %d\n", result);
  return 0;
}