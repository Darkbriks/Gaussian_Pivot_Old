#ifndef PIVOT_DE_GAUSS
#define PIVOT_DE_GAUSS

#include <map>
#include <string>
#include <vector>

// Gaussian pivot using multiplication between lines
std::vector<std::map<std::string, long double>> gaussian_pivot(std::vector<std::map<std::string, long double>> system, int nb_equations); // TODO : comment and docstring

#endif