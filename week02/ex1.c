#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;

    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("Variable \"a\" type of \"int\": size=%i, value=%i\n", (int) sizeof(a), a);
    printf("Variable \"b\" type of \"float\": size=%i, value=%f\n", (int) sizeof(b), b);
    printf("Variable \"c\" type of \"double\": size=%i, value=%lf\n", (int) sizeof(c), c);

    return 0;
}