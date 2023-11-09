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

KMP_Result KMP(vector<char> pattern, vector<char> text)
{
    KMP_Result result;
    int patternSize = pattern.size();
    int textSize = text.size();

    // Calculate prefix function
    vector<int> prefix_function(patternSize);
    prefix_function[0] = 0;
    for (int i = 1; i < patternSize; i++)
    {
        int j = prefix_function[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = prefix_function[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        prefix_function[i] = j;
    }

    result.prefix_function = prefix_function;

    // KMP
    int j = 0;
    for (int i = 0; i < textSize; i++)
    {
        while (j > 0 && text[i] != pattern[j])
            j = prefix_function[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == patternSize)
        {
            Match match;
            match.start = i - patternSize + 2;
            match.direction[0] = 'L';
            match.direction[1] = 'R';
            result.matches.push_back(match);
            j = prefix_function[j - 1];
        }
    }

    // Reverse pattern
    reverse(pattern.begin(), pattern.end());

    // Calculate prefix function
    prefix_function[0] = 0;
    for (int i = 1; i < patternSize; i++)
    {
        int j = prefix_function[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = prefix_function[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        prefix_function[i] = j;
    }

    // KMP for reverse pattern
    j = 0;
    for (int i = 0; i < textSize; i++)
    {
        while (j > 0 && text[i] != pattern[j])
            j = prefix_function[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == patternSize)
        {
            Match match;
            match.start = i + 1;
            match.direction[0] = 'R';
            match.direction[1] = 'L';
            result.matches.push_back(match);
            j = prefix_function[j - 1];
        }
    }

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

    vector<char> pattern(patternSize);
    vector<char> text(textSize);

    // Get pattern
    for (int i = 0; i < patternSize; i++)
        cin >> pattern[i];

    // Get text
    for (int i = 0; i < textSize; i++)
        cin >> text[i];

    // Run Knuth-Morris-Pratt algorithm
    KMP_Result result = KMP(pattern, text);

    // Print Prefix function
    for (auto c : result.prefix_function)
        cout << c << " ";
    cout << endl;

    // Print number of matches
    cout << result.matches.size() << endl;

    // Print all matches with start position and direction
    for (auto match : result.matches)
        cout << match.start << " " << match.direction[0] << match.direction[1] << endl;

    return 0;
}