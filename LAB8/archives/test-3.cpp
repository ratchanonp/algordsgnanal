#include <iostream>

using namespace std;

int main()
{
    // Create an array to store the pattern.
    int pattern[20];

    // Initialize the first two numbers in the pattern.
    pattern[0] = 1;
    pattern[1] = 2;

    // Generate the pattern.
    for (int i = 2; i < 20; i++)
    {
        pattern[i] = pattern[i - 1] + pattern[i - 2] + 1;
    }

    // Print the pattern.
    for (int i = 0; i < 20; i++)
    {
        cout << pattern[i] << " ";
    }

    cout << endl;

    return 0;
}
