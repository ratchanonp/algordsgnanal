#include <bits/stdc++.h>

using namespace std;

struct Match
{
    int start;         // start position of match
    char direction[2]; // LR or RL
};

struct KMP_Result
{
    vector<int> prefix_function; // prefix function
    vector<Match> matches;       // list of matches
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
    vector<Match> matches;
    int textSize = text.size() - 1;
    int patternSize = pattern.size() - 1;

    vector<int> prefix_function = calculate_prefix_function(pattern);

    int q = 0;

    for (int i = 1; i <= textSize; i++)
    {
        while (q > 0 && pattern[q + 1] != text[i])
            q = prefix_function[q];
        if (pattern[q + 1] == text[i])
            q = q + 1;
        if (q == patternSize)
        {
            // Save start position
            Match match;
            match.start = i - patternSize + 1;
            matches.push_back(match);
            q = prefix_function[q];
        }
    }

    return matches;
}

KMP_Result KMP(vector<char> pattern, vector<char> text)
{
    KMP_Result result;
    vector<Match> matches;

    // Do normal KMP
    // Calculate prefix function
    result.prefix_function = calculate_prefix_function(pattern);
    // Find match
    matches = KMP_MATCHER(text, pattern);

    // Loop through all matches mark as LR
    for (int i = 0; i < matches.size(); i++)
    {
        matches[i].direction[0] = 'L';
        matches[i].direction[1] = 'R';
    }

    // Save into result
    result.matches.insert(result.matches.end(), matches.begin(), matches.end());

    // Do KMP with reverse pattern
    reverse(pattern.begin() + 1, pattern.end());

    // Find match
    matches = KMP_MATCHER(text, pattern);

    // Loop through all matches mark as RL
    for (int i = 0; i < matches.size(); i++)
    {
        matches[i].start = matches[i].start + pattern.size() - 2;
        matches[i].direction[0] = 'R';
        matches[i].direction[1] = 'L';
    }

    // Save into result
    result.matches.insert(result.matches.end(), matches.begin(), matches.end());

    return result;
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

    // Run Knuth-Morris-Pratt algorithm
    KMP_Result result = KMP(pattern, text);

    // Print Prefix function
    for (int i = 1; i <= patternSize; i++)
        cout << result.prefix_function[i] << " ";
    cout << endl;

    // Print number of matches
    cout << result.matches.size() << endl;

    // Print all matches with start position and direction
    for (auto match : result.matches)
        cout << match.start << " " << match.direction[0] << match.direction[1] << endl;

    return 0;
}