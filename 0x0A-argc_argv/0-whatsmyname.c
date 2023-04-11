#include <stdio.h>

int main(int argc, char *argv[]) {
    /* Mark argc as unused to avoid the warning */
    (void)argc;
    
    /* argv[0] contains the name of the program */
    printf("%s\n", argv[0]);
    
    return 0;
}
