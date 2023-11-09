#include <bits/stdc++.h>

using namespace std;

struct Match
{
    int start;         // start position of match
    char direction[2]; // LR or RL
};

vector<Match> naiveStringMatching(vector<char> pattern, vector<char> text)
{
    vector<Match> matches;
    int patternSize = pattern.size();
    int textSize = text.size();

    for (int i = 0; i < textSize - patternSize + 1; i++)
    {
        bool match = true;
        for (int j = 0; j < patternSize; j++)
        {
            if (text[i + j] != pattern[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            Match m;
            m.start = i + 1;
            m.direction[0] = 'L';
            m.direction[1] = 'R';
            matches.push_back(m);
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

    vector<char> pattern(patternSize);
    vector<char> text(textSize);

    // Get pattern
    for (int i = 0; i < patternSize; i++)
        cin >> pattern[i];

    // Get text
    for (int i = 0; i < textSize; i++)
        cin >> text[i];

    // Naive String Matching
    vector<Match> matches = naiveStringMatching(pattern, text);

    // Reverse pattern
    reverse(pattern.begin(), pattern.end());

    // Naive String Matching with reverse pattern
    vector<Match> reverseMatches = naiveStringMatching(pattern, text);

    cout << "Naive String Matching Don't have prefix function" << endl;

    // Print result
    cout << matches.size() + reverseMatches.size() << endl;

    for (Match m : matches)
        cout << m.start << " " << m.direction[0] << m.direction[1] << endl;

    for (Match m : reverseMatches)
        cout << m.start + patternSize - 1 << " " << m.direction[1] << m.direction[0] << endl;

    return 0;
}