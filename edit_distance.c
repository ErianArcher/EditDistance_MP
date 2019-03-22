//
// Created by erian on 3/18/19.
//

#include <stdlib.h>
#include <string.h>
#include "edit_distance.h"
#include <stdio.h>

typedef unsigned int uint;

uint **init_2D_matrix(int width, int height);

void delete_2D_matrix(uint **_2Dm, int width);

void fill_dp_matrix(uint **dp_m, const char *X, const char *Y);

void printMatrix(uint **dp_m, const int width, const int height);


uint min(uint i, uint i1, uint i2);

uint **init_2D_matrix(int width, int height) {
    uint **_2Dm = NULL;
    _2Dm = (uint **) malloc(sizeof(uint *) * width);
    for (int i=0; i < width; i++)
    {
        *(_2Dm+i) = (uint *) malloc(sizeof(uint) * height);
    }
    return _2Dm;
}

void delete_2D_matrix(uint **_2Dm, int width) {
    for (int i=0; i< width; i++)
    {
        free(*(_2Dm+i));
    }
    free(_2Dm);
}


int cal_edit_distance(const char *X, const char *Y) {
    int lenX = (int) strlen(X);
    int lenY = (int) strlen(Y);
    int edit_distance = 0;
    uint **dp_matrix = NULL;

    if ((dp_matrix = init_2D_matrix(lenX+1, lenY+1)) == NULL)
    {
        exit(1);
    }

    // Fill dynamic programming matrix
    fill_dp_matrix(dp_matrix, X, Y);
    edit_distance = dp_matrix[lenX][lenY]; // The last item of the matrix is the edit distance.
    printMatrix(dp_matrix, lenX+1, lenY+1);

    delete_2D_matrix(dp_matrix, lenX+1);
    return edit_distance;
}

void fill_dp_matrix(uint **dp_m, const char *X, const char *Y) {
    int w = (int) (strlen(X) + 1);
    int h = (int) (strlen(Y) + 1);
    // Initialize the matrix
    // First row
    for (int i = 0; i < h; i++) {
        dp_m[0][i] = (uint) i;
    }
    // First column
    for (int i = 1; i < w; i++) {
        dp_m[i][0] = (uint) i;
    }

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (X[j-1] == Y[i-1])
            {
                dp_m[j][i] = min(dp_m[j-1][i-1], dp_m[j-1][i], dp_m[j][i-1]);
            } else {
                dp_m[j][i] = min(dp_m[j-1][i-1], dp_m[j-1][i], dp_m[j][i-1]) + 1;
            }
        }
    }
}

uint min(uint i, uint i1, uint i2) {
    return (((i < i1)? i : i1) < i2) ? : i2;
}

void printMatrix(uint **dp_m, const int width, const int height) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            printf("%u\t", dp_m[i][j]);
        }
        printf("\n");
    }
}

