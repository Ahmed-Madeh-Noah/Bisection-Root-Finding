#include <iostream>
#include <cmath>

using namespace std;

const float startingInterval[2] = {0, 3}; // change to search in another interval
const float relativeErrorPercentage = 0.05; // change to get quicker or more accurate solutions
const string function_of_x_str = "x - cos(x)"; // change for the printing
unsigned int iterations = 0;

float function_of_x(float x);

bool has_solution(const float SolutionInterval[2]);

float average(const float SolutionInterval[2]);

void bisect(float prev_x);

int main() {
    cout << "Solving f(x) = " + function_of_x_str << endl
            << "In the interval [" << startingInterval[0] << "," << startingInterval[1] << "]" << endl
            << "With a relative error percentage of " << relativeErrorPercentage << "%" << endl;
    float interval[2] = {startingInterval[0], startingInterval[1]};
    bisect(interval[0]);
    return 0;
}


float function_of_x(const float x) {
    return x - cos(x); // change the function you want to find the roots of
}


bool has_solution(const float SolutionInterval[2]) {
    return function_of_x(SolutionInterval[0]) * function_of_x(SolutionInterval[1]) < 0;
}


float average(const float SolutionInterval[2]) {
    return (SolutionInterval[0] + SolutionInterval[1]) / 2;
}

void bisect(const float prev_x) {
}
