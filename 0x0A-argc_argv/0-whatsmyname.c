#include <stdio.h>

int main(int argc, char *argv[]) {
    // Declare an integer variable to store the number of arguments
    int num_args;

    // Subtract 1 from the argument count to exclude the name of the program itself
    num_args = argc - 1;

    // Print the number of arguments
    printf("%d\n", num_args);

    // Return 0 to indicate successful program execution
    return 0;
}
