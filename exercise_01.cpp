#include <stdio.h>
#include <stdlib.h>

// void my_function(int x , int y );
//
// int main(void)
// {
//     my_function(5, 5);
//     return 0;
// }
//
// /* Just a simple comment*/
// void my_function(int x, int y)
// {
//     printf("Y = %d\n", y);
//     printf("Old X = %d\n", x);
//     x = x * y;
//     printf("new X = %d\n", x);
// }

void my_function(int my_veriable, int b, char c);

int main (void)
{
    my_function(0,0,'c');
    return 0;
}

void my_function(int my_veriable, int b, char c )
{
    my_veriable = 5;
    b = my_veriable + 5;
    c = 'A';
    printf ("my_veriable = %d\n", my_veriable);
    printf ("b = %d\n", b);
    printf ("c = %c\n", c);
}