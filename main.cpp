#include <iostream>
#include <cmath>

using namespace std;

const float startingInterval[2] = {0, 3}; // change to search in another interval
const float relativeErrorPercentage = 0.05; // change to get quicker or more accurate solutions
const string function_of_x_str = "x - cos(x)"; // change for the printing

float function_of_x(float x);

bool has_solution(const float SolutionInterval[2]);

float average(const float SolutionInterval[2]);

void bisect(float interval[2], float prev_x = startingInterval[0], unsigned int iterations = 0);

int main() {
    cout << "Solving f(x) = " + function_of_x_str << endl
            << "In the interval [" << startingInterval[0] << "," << startingInterval[1] << "]" << endl
            << "With a relative error percentage of " << relativeErrorPercentage << "%" << endl << endl << endl;
    float interval[2] = {startingInterval[0], startingInterval[1]};
    if (has_solution(interval)) {
        bisect(interval);
    } else {
        cout << "The starting interval doesn't surround the root" << endl;
    }
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

void bisect(float interval[2], float prev_x, unsigned int iterations) {
    iterations++;
    const float average_x = average(interval);
    const float mapped_interval[2] = {function_of_x(interval[0]), function_of_x(interval[1])};
    const float mapped_average_x = function_of_x(average_x);
    const float error = abs(((average_x - prev_x) / average_x) * 100);
    cout << "Iteration: " << iterations
            << "\nx-left: " << interval[0]
            << "\nx-average: " << average_x
            << "\nx-right: " << interval[1]
            << "\nf(x-left): " << mapped_interval[0]
            << "\nf(x-average): " << mapped_average_x
            << "\nf(x-right): " << mapped_interval[1]
            << "\nRelative Error Percentage: " << error << '%' << endl << endl << endl;
    if (error < relativeErrorPercentage) {
        cout << "The root equals " << average_x << " with a relative error percentage of " << error << '%' << endl
                << "It was found in " << iterations << " iterations" << endl;
    } else {
        const float nextInterval[2] = {interval[0], average_x};
        if (has_solution(nextInterval)) {
            interval[1] = average_x;
            bisect(interval, average_x, iterations);
        } else {
            interval[0] = average_x;
            bisect(interval, average_x, iterations);
        }
    }
}
