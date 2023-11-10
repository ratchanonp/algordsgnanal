#include <bits/stdc++.h>

using namespace std;

struct Match
{
    int start;         // start position of match
    char direction[2]; // LR or RL
};

vector<int> calculate_prefix_function(vector<char> pattern)
{
    int patternSize = pattern.size();

    vector<int> prefix_function(patternSize);

    prefix_function[1] = 0;

    int k = 0;

    for (int q = 2; q <= patternSize; q++)
    {
        while (k > 0 && pattern[k + 1] != pattern[q])
            k = prefix_function[k];
        if (pattern[k + 1] == pattern[q])
            k = k + 1;

        prefix_function[q] = k;
    }

    return prefix_function;
}

vector<Match> KMP_MATCHER(vector<char> text, vector<char> pattern)
{
    int textSize = text.size() - 1;
    int patternSize = pattern.size() - 1;

    // Repeat text to make it circular
    for (int i = 1; i <= patternSize; i++)
        text.push_back(text[i]);

    vector<Match> matches;

    vector<int> prefix_function = calculate_prefix_function(pattern);

    int q = 0;

    // Text is circular
    for (int i = 1; i <= text.size(); i++)
    {
        while (q > 0 && pattern[q + 1] != text[i])
            q = prefix_function[q];
        if (pattern[q + 1] == text[i])
            q = q + 1;
        if (q == patternSize)
        {
            // Save start position
            Match match;
            match.start = (i - patternSize) % textSize + 1;
            match.direction[0] = 'L';
            match.direction[1] = 'R';

            matches.push_back(match);

            q = prefix_function[q];
        }
    }

    return matches;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char> chars;

    // Get Line and split line with space push into vector chars
    string line;
    getline(cin, line);

    stringstream ss(line);
    char c;
    while (ss >> c)
    {
        chars.push_back(c);
    }

    // Get pattern and text
    int patternSize, textSize;

    // Get pattern and text size
    cin >> patternSize >> textSize;

    vector<char> pattern(patternSize + 1);
    vector<char> text(textSize + 1);

    // Get pattern
    for (int i = 1; i <= patternSize; i++)
        cin >> pattern[i];

    // Get text
    for (int i = 1; i <= textSize; i++)
        cin >> text[i];

    // Prefix function
    vector<int> prefix_function = calculate_prefix_function(pattern);

    // Run Knuth-Morris-Pratt algorithm
    vector<Match> matches = KMP_MATCHER(text, pattern);

    // Reverse pattern
    reverse(pattern.begin() + 1, pattern.end());

    // Run Knuth-Morris-Pratt algorithm with reverse pattern
    vector<Match> matches_reverse = KMP_MATCHER(text, pattern);

    // Print Prefix function
    for (int i = 1; i <= patternSize; i++)
        cout << prefix_function[i] << " ";
    cout << endl;

    // Print number of matches
    cout << matches.size() + matches_reverse.size() << endl;

    // Print all matches with start position and direction
    for (Match m : matches)
        cout << m.start << " " << m.direction[0] << m.direction[1] << endl;

    for (Match m : matches_reverse)
        cout << (m.start + patternSize) % textSize - 1 << " " << m.direction[1] << m.direction[0] << endl;

    return 0;
}