#include <bits/stdc++.h>

using namespace std;

string lt(const string &);
string rt(const string &);
vector<string> split(const string &);

void plsmns(vector<int> arr) {
    int zero=0,ptve=0,ntve=0;
    for(int i: arr){
        if(i>0)
        ptve++;
        else if (i==0)
         zero++;
        else
         ntve++;
    }
    cout<<(float)ptve/arr.size()<<endl;
    cout<<(float)ntve/arr.size()<<endl;
    cout<<(float)zero/arr.size()<<endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rt(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rt(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plsmns(arr);

    return 0;
}

string lt(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rt(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
