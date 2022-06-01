#include <iostream>
#include <fstream>
#include <sstream>
#include "Legendre.h"
#include "Gauss.h"

double pow(double d, int j);

int main(int argc, char *argv[]) {
    int n;
    std::stringstream convert(argv[1]);
    convert >> n;
    
    std::ofstream out;
    std::string s = "quad";
    if (n < 10) {
        s += "0";
    }
    s += std::to_string(n);
    s += ".dat";
    out.open(s);
    out.setf(std::ios::scientific);
    std::cout.precision(10);
    
    double *ans = rootsLegendre(n);
    double **a, *b, *x;
    a = new double *[n + 1];
    b = new double[n + 1];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n + 1];
        for (int j = 0; j < n; j++) {
            a[i][j] = pow(ans[j], i);
        }
    }
    for (int i = 0; i < n; i++) {
        b[i] = (double) 2.0 * ((i + 1) % 2) / (i + 1);
    }
    x = gaussMod(a, b, n);
    for (int i = 0; i < n; i++) {
        out << ans[i] << " " << x[i] << std::endl;
    }
    out.close();
    
    return 0;
}

double pow(double d, int j) {
    if (j == 0) {
        return (double) 1.0;
    }
    return pow(d * d, j / 2) * (j % 2 ? d : 1);
}
