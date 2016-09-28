#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    // First text input file
    ifstream is("/Users/Sanjay/Desktop/anna_karenina.txt");

    if (is.fail())
    {
        cout << "Cannot be opened!" << endl;
        return 1;
    }

    // Second text input file
    ifstream ds("/Users/Sanjay/Desktop/don_quixote.txt");

    if (ds.fail())
    {
        cout << "Cannot be opened!" << endl;
        return 2;
    }

    int k;
    cout << "Enter an integer" << endl;
    cin >> k;

    map<string, int> m;
    string s;

    // Maps words in first text input file
    while (is >> s)
        m[s]++;

    // Maps words in second text input file
    while (ds >> s)
        m[s]++;

    vector<pair<int, string>> v;

    // Stores values from Map into a vector (easier to sort)
    for (auto e:m)
        v.push_back(pair<int, string>(e.second, e.first));

    sort(v.begin(), v.end());

    // Outputs values
    int x = v.size();
    for (int i = 1; i <= min(x, k); i++)
    {
        pair<int,string> p = v[x-i];
        cout << p.second << ": " << p.first << endl;
    }

    is.close();
    ds.close();
    return 0;
}
