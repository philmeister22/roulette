#include <stdlib.h>
#include <time.h>
 int main() {
  int n;
  srand(time(NULL));
  n=0+rand()%37;
  printf(" numero generato %d\n",n );
  system("pause");//da togliere
  return 0;
}
