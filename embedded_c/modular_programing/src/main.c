#include <stdio.h>
#include "math_utils.h"

int main (){
    int x = 10;
    int y = 20;

    /*call func to module math_utils*/
    int sum = cong(x,y);
    int diff = tru(x, y);

    printf("Sum is %d\n", sum);
    printf("Diff is %d\n", diff);

    return 0;
}