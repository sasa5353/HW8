#include <iostream>
#include <sstream>
#include "myFunc.h"
#include "quadGauss.h"

int main(int argc, char *argv[]) {
    int n;
    double a, b;
    std::stringstream convert_n(argv[1]);
    convert_n >> n;
    std::stringstream convert_a(argv[2]);
    convert_a >> a;
    std::stringstream convert_b(argv[3]);
    convert_b >> b;
    
    double (*funcPointer)(double) = func;
    
    std::cout.setf(std::ios::scientific);
    std::cout.precision(10);
    
    
    double integral = integrate(funcPointer, a, b, n);
    std::cout << integral << std::endl;
    
    return 0;
}
