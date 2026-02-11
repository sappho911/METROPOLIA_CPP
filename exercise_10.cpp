#include <stdio.h>
#include <string.h>


int main(void)
{
    char string [256];
    printf ("Insert your full address: ");
    gets (string);
    printf ("Your address is: %s\n",string);
    printf("Length: %d\n ", strlen(string));
    return 0;
}



