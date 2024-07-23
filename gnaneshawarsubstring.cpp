
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to find the longest common substring
string findLongestCommonSubstring(const string& str1, const string& str2) {
    int len1 = str1.length(), len2 = str2.length();
    vector<vector<int>> lengthTable(len1 + 1, vector<int>(len2 + 1, 0));
    int maxLen = 0, endIndex = 0;

    // Iterate through each character in the strings
    int i = 1;
    while (i <= len1) {
        int j = 1;
        while (j <= len2) {
            // If characters match, update the length table
            if (str1[i - 1] == str2[j - 1]) {
                lengthTable[i][j] = lengthTable[i - 1][j - 1] + 1;
                if (lengthTable[i][j] > maxLen) {
                    maxLen = lengthTable[i][j];
                    endIndex = i;
                }
            }
            j++;
        }
        i++;
    }

    // Extract the longest common substring
    return str1.substr(endIndex - maxLen, maxLen);
}

// Function to print the DP table for visualization
void displayDPTable(const string& str1, const string& str2) {
    int len1 = str1.length(), len2 = str2.length();
    vector<vector<int>> lengthTable(len1 + 1, vector<int>(len2 + 1, 0));

    // Calculate values for the length table
    int i = 1;
    while (i <= len1) {
        int j = 1;
        while (j <= len2) {
            if (str1[i - 1] == str2[j - 1]) {
                lengthTable[i][j] = lengthTable[i - 1][j - 1] + 1;
            }
            j++;
        }
        i++;
    }

    // Print the DP table for both strings
    cout << "  ";
    for (int j = 0; j < len2; ++j) {
        cout << str2[j] << " ";
    }
    cout << endl;

    for (int i = 0; i <= len1; ++i) {
        if (i > 0) {
            cout << str1[i - 1] << " ";
        } else {
            cout << "  ";
        }
        for (int j = 0; j <= len2; ++j) {
            cout << lengthTable[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string str1, str2;

    // Take input strings from the user
    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    // Print the DP table to show the initial state
    cout << "DP Table:" << endl;
    displayDPTable(str1, str2);

    // Find and display the longest common substring
    string commonSubstring = findLongestCommonSubstring(str1, str2);
    cout << "Longest Common Substring: " << commonSubstring << endl;
    cout << "Length: " << commonSubstring.length() << endl;

    return 0;
}
