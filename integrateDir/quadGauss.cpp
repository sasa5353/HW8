//
// Created by alex on 20.03.2020.
//

#include <fstream>
#include "quadGauss.h"

double integrate(double(*funcPointer)(double), double a, double b, unsigned int n) {
    std::ifstream in;
    std::string s = "quad";
    if (n < 10) {
        s += "0";
    }
    s += std::to_string(n);
    s += ".dat";
    in.open(s);
    
    double *rootsLegendre, *coefficientsGaussQuad;
    rootsLegendre = new double[n];
    coefficientsGaussQuad = new double[n];
    
    double integral = 0.0;
    for (int i = 0; i < n; i++) {
        in >> rootsLegendre[i] >> coefficientsGaussQuad[i];
        integral += funcPointer((a + b) / 2 + (b - a) / 2 * rootsLegendre[i]) * coefficientsGaussQuad[i];
    }
    
    in.close();
    
    integral *= (b - a) / 2;
    return integral;
}
