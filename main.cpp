#include <iostream>
#include <cmath>

using namespace std;

const float startingInterval[2] = {0, 3};
const float relativeErrorPercentage = 0.05;

float function_of_x(float x);

int main() {
}


float function_of_x(const float x) {
    return x - cos(x);
}
