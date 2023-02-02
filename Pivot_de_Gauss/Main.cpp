
#include <iostream>
#include <string>
#include <map>
#include "Utils.h"
#include "Gaussian_Pivot.h"

using namespace std;

/* Example of equations :
 *      {"3a + 2b + -1c = 1", "a + -1b + 4c = 4", "2a + b + c + = 5"}
 *      {"a + 2b + -1c = 3", "2a + -3b + c = -9", "-3a + b + 4c = 14"}
 *      {"2a + 5b = 7", "a + 3b = 9"}
 */

int main()
{
    vector<string> liste_equation = enter_system();

    cout << endl << "How many equations are there : ";
    int n;
    cin >> n;
    
    vector<map<string, long double>> system = system_formatting(liste_equation.data(), n);

    //vector<map<string, long double>> system = enter_system_formatting();
    
    system = gaussian_pivot(system, n);
    map<string, long double> solution = solve_system(system, n);

    // Print the solution
    for (auto it = solution.begin(); it != solution.end(); it++)
    {
        cout << it->first << " = " << it->second << endl;
    }

    // Wait for user input
    cout << endl << "Press enter to exit" << endl;
    string tmp;
    cin >> tmp;
    
    return 0;
}
