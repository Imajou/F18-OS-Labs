#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    unsigned int referenced;
    int id;
} page;

int p_count;
page *p_list;

int aging(int id)
{

    // Candidate to throw
    unsigned int min_referenced = 0;
    page *candidate = &p_list[0];

    for (int i = 0; i < p_count; ++i)
    {

        // Hit the id
        if (id == p_list[i].id)
        {
            p_list[i].referenced >>= 1;
            p_list[i].referenced |= 0x8000000;
            // Update referenced
            for (int j = i; j < p_count; ++j)
            {
                p_list[j].referenced >>= 1;
                p_list[j].referenced &= 0x7FFFFFFF;
            }
            return 1;
        }
        // Empty space
        if (p_list[i].id == 0)
        {
            p_list[i].id = id;
            p_list[i].referenced |= 0x8000000;
            return 0;
        }

        // Update the victim
        if (p_list[i].referenced < min_referenced)
        {
            candidate = &p_list[i];
        }

        // Update referenced
        p_list[i].referenced >>= 1;
        p_list[i].referenced &= 0x7FFFFFFF;
    }

    candidate->referenced = 0x0;
    candidate->id = id;
    return 0;
}

int main(int argc, char const *argv[])
{

    // Get number of pages
    p_count = atoi(argv[1]);

    // Allocate and initialize "memory"
    p_list = (page *)malloc(p_count * sizeof(page));
    for (int i = 0; i < p_count; ++i)
    {
        p_list[i].referenced = 0x0;
        p_list[i].id = 0x0;
    }

    // Input
    FILE *file;
    file = fopen("Lab 09 input.txt", "r");
    int hits = 0, misses = 0;
    int current_input;
    // Processing
    while (fscanf(file, "%d", &current_input) == 1)
    {
        if (aging(current_input))
            hits++;
        else
            misses++;
    }
    printf("Hits: %d\n", hits);
    printf("Misses: %d\n", misses);
    printf("Rate: %lf\n", (double)hits / (double)misses);

    return 0;
}
