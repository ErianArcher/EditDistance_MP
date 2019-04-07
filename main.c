#include <stdio.h>
#include <string.h>
#include "edit_distance.h"

int main(int argc, char *args[]) {
    if (argc != 3) {
        printf("./exec [string1] [string2]");
        return 1;
    }
    const char *X = args[1];
    const char *Y = args[2];
    int dist = 0;
    dist = cal_edit_distance(X, Y);
    printf("Edit distance: %d", dist);
    return 0;
}