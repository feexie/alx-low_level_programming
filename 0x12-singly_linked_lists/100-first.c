#include <stdio.h>

void first(void)__attribute__((constructor));

/**
 * turtle - prints a quote about turtles before main function
 */
void first(void)
{
    printf("Why did the turtle cross the road?\n");
    printf("To get to the Shell Station!\n");
}
