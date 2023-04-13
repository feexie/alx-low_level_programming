#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _realloc - Reallocate a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated with malloc
 * @old_size: Size of the allocated space for ptr
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        void *new_ptr = NULL; /* Declare and initialize new_ptr to NULL */

        if (new_size == 0 && ptr != NULL)
        {
                /* If new_size is 0 and ptr is not NULL, equivalent to free(ptr) */
                free(ptr);
                return NULL;
        }

        if (ptr == NULL)
        {
                /* If ptr is NULL, equivalent to malloc(new_size) */
                return malloc(new_size);
        }

        if (new_size == old_size)
        {
                /* If new_size is equal to old_size, do nothing and return ptr */
                return ptr;
        }

        new_ptr = malloc(new_size); /* Allocate memory for the new block */

        if (new_ptr != NULL)
        {
                /* Copy contents from old memory block to new memory block
                 * up to the minimum of old_size and new_size */
                size_t copy_size = old_size < new_size ? old_size : new_size;
                memcpy(new_ptr, ptr, copy_size);

                /* Free the old memory block */
                free(ptr);
        }

        return new_ptr;
}

