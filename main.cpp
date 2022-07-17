#include <bits/stdc++.h>
#include <map>
#include <algorithm>
using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    map<char, uint32_t> charmap;
    map<uint32_t, uint32_t> occurmap;
    for (int i=0;i<s.length();++i)
    {
        charmap[s[i]] = charmap.find(s[i])==charmap.end() ? 1 : ++charmap[s.at(i)];

    }

    for(auto [key,value]:charmap)
    {
        occurmap[value]=occurmap.find(value)==occurmap.end() ? 1 : ++occurmap[value];
    }
    if (occurmap.size()==1)
        return "YES";
    if (occurmap.size()>2)
        return "NO";
    if (occurmap.begin()->first == 1 && occurmap.begin()->second == 1)
        return "YES";
    if((occurmap.rbegin()->first)-1 == occurmap.begin()->first  && occurmap.rbegin()->second == 1)
        return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);
    cout<<result<<endl;
    fout << result << "\n";

    fout.close();

    return 0;
}
