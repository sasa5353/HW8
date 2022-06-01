//
// Created by alex on 20.03.2020.
//

#include "myFunc.h"
#include <cmath>

double pow(double d, int j);

double func(double x) {
    return exp(x);
}

double pow(double d, int j) {
    if (j == 0) {
        return 1.0;
    }
    return pow(d * d, j / 2) * (j % 2 ? d : 1);
}
