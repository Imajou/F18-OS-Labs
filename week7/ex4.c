#include <stdlib.h>
#include <malloc/malloc.h>
#include <memory.h>

#ifdef __APPLE__
#define MALLOC_SIZE_FUN malloc_size
#elif __linux__
#define MALLOC_SIZE_FUN malloc_usable_size
#elif __unix__
#define MALLOC_SIZE_FUN malloc_usable_size
#elif _WIN32
#define MALLOC_SIZE_FUN _msize
#endif

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

    new_ptr = malloc(size);
    memcpy(new_ptr, ptr, MALLOC_SIZE_FUN(ptr));
    
    free(ptr);
    return new_ptr;
}
