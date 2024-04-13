#include <iostream>
#include <math.h>

using namespace std;

unsigned long long int countQuadraticRepresentations(const unsigned long long int input) {
  unsigned long long int counter = 0;

  // c1x^2 + c2xy + c3y^2
  int c1 = 1;
  const int c2 = 1;
  int c3 = 41;

  // reduce loop with smaller c3
  if (c3 > c1) {
    c1 = c1 ^ c3;
    c3 = c1 ^ c3;
    c1 = c1 ^ c3;
  }

  // init var for reuse
  const int c1Sq = c1 * c1;
  const int c2Sq = c2 * c2;
  const int twoC3 = c3 * 2;

  // c3y^2 + c2xy + c1x^2 - input = 0
  // a = c3, b = c2x, c = c1x^2 - input
  // delta = b^2 - 4ac
  // root = (-b +- sqrt(discriminant)) / 2a

  // start with x = 0
  double xSquare = 0;
  double discriminant = 4 * c3 * (input);
  double delta = sqrt(discriminant);
  int posRoot = static_cast<int>(floor(delta / twoC3));
  int negRoot = static_cast<int>(ceil(-delta / twoC3));

  // representations = (negRoot, 0), (negRoot+1, 0), ... (posRoot, 0)
  // exclude (0, 0)
  counter = abs(negRoot) + posRoot;

  // check over all possible x
  long long int i = 1;
  while (1) {
    // delta = c2^2 * x^2 - 4 * c3 * (c1x^2 - input)
    xSquare = i * i;
    discriminant = c2Sq * xSquare - 4 * c3 * (c1 * xSquare - input);

    // no real root => no representation
    if (discriminant < 0) break;

    delta = sqrt(discriminant);
    posRoot = static_cast<int>(floor((-(c2 * i) + delta) / twoC3));
    negRoot = static_cast<int>(ceil((-(c2 * i) - delta) / twoC3));

    // representations = (negRoot, +-x), (negRoot+1, +-x), ... (posRoot, +-x)
    counter += (abs(negRoot) + posRoot + 1) * 2;

    i += 1;
  }

  return counter;
}

int main() {
  unsigned long long int input = 1e16;
  unsigned long long int result = countQuadraticRepresentations(input);
  cout << result << endl;
  return 0;
}
