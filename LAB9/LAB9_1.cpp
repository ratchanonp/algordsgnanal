#include <bits/stdc++.h>

using namespace std;

struct Match
{
    int start;
    char direction[2]; // LR or RL
};

struct KMP_Result
{
    vector<int> prefix_function;
    vector<Match> matches;
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

    // KMP
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

    int patternSize, textSize;
    cin >> patternSize >> textSize;

    vector<char> pattern(patternSize);
    vector<char> text(textSize);

    for (int i = 0; i < patternSize; i++)
        cin >> pattern[i];

    for (int i = 0; i < textSize; i++)
        cin >> text[i];

    KMP_Result result = KMP(pattern, text);

    for (auto c : result.prefix_function)
        cout << c << " ";
    cout << endl;

    cout << result.matches.size() << endl;

    for (auto match : result.matches)
        cout << match.start << " " << match.direction[0] << match.direction[1] << endl;

    return 0;
}