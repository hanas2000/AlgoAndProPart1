#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
int a=0;
int b=0;

    for(;a<101;a+=2)
    {
        b += a;
    }
    
    printf("%d\n",b);
    
  return 0;
}
