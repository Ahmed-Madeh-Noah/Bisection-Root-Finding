#include <iostream>
#include <cmath>

using namespace std;

const float startingInterval[2] = {0, 3};
const float relativeErrorPercentage = 0.05;

float function_of_x(float x);

bool has_solution(const float interval[2]);

int main() {
    cout << has_solution(startingInterval) << endl;
}


float function_of_x(const float x) {
    return x - cos(x);
}


bool has_solution(const float interval[2]) {
    return function_of_x(interval[0]) * function_of_x(interval[1]) < 0;
}
