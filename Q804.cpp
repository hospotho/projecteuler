#include <math.h>
#include <iostream>
using namespace std;

long long int countQuadraticRepresentations(long long int input) {
    long long int counter = 0;

    long long int i = 0;
    double xSquare = i * i;

    double deltaSq = xSquare - 4 * 41 * (xSquare - input);
    double delta = sqrt(deltaSq);
    int posRoot = static_cast <int> (floor((-i + delta) / (2 * 41)));
    int negRoot = static_cast <int> (floor((-i - delta) / (2 * 41)));
    counter += abs(negRoot) + posRoot - 1;

    i = 1;

    while (1) {
        xSquare = pow(i, 2);

        deltaSq = xSquare - 4 * 41 * (xSquare - input);
        if (deltaSq < 0) break;

        delta = sqrt(deltaSq);
        posRoot = static_cast <int> (floor((-i + delta) / (2 * 41)));
        negRoot = static_cast <int> (floor((-i - delta) / (2 * 41)));
        counter += (abs(negRoot) + posRoot) * 2;

        i += 1;
    }

    return counter;
}

int main() {
    long long int input = 1e16;
    long long int result = countQuadraticRepresentations(input);
    cout << result << endl;
    return 0;
}