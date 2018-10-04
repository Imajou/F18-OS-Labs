#include <stdlib.h>
#include <malloc/malloc.h>
#include <memory.h>

void *custom_realloc(void *ptr, size_t size)
{

    if (ptr == NULL)
        return malloc(size);
    if (size == 0)
    {
        free(ptr);
        return ptr;
    }

    void *new_ptr;

    if (malloc_size(ptr) < size)
    {
        new_ptr = malloc(size);

        memcpy(new_ptr, ptr, malloc_size(ptr));

        free(ptr);
    }
    else
    {
        new_ptr = ptr;
    }
    return new_ptr;
}
