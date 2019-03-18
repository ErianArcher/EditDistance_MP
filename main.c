#include <stdio.h>
#include "edit_distance.h"

int main() {
    const char *X = "jary";
    const char *Y = "jerry";
    int dist = 0;
    dist = cal_edit_distance(X, Y);
    printf("Edit distance: %d", dist);
    return 0;
}