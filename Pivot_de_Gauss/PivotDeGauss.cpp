#include "PivotDeGauss.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<map<string, long double>> gaussian_pivot(const vector<map<string, long double>> system, const int nb_equations)
{
    vector<map<string, long double>> result = system;
    
    for (int i = 0; i < nb_equations - 1; i++)
    {
        string var = "a";
        var[0] += i;
        
        // Find the pivot
        pivot pivot = find_pivot(nb_equations, result.data(), i, var);

        // If the pivot line is not the current line, swap the lines
        if (pivot.line != i)
        {
            swap_lines(result.data(), i, pivot.line);
        }

        // For each line after the current line, subtract the current line multiplied by the coefficient of the variable
        for (int j = i + 1; j < nb_equations; j++)
        {
            result[j] = subtract_lines(multiply_line(result[j], result[i][var]), multiply_line(result[i], result[j][var]));
        }
    }
    return result;
}

