#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <functional>
		

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */
int cookies(int k, vector<int> A) {
    priority_queue Q(A.begin(), A.end(), greater<int>());
    int counter = 0;
    while(Q.size() > 1 && Q.top() < k) {
        int first = Q.top();
        Q.pop();
        int second = Q.top();
        Q.pop();
        Q.push(first + 2 * second);
        ++counter;
    }
    if(Q.top() < k) return -1;
    return counter;
}

int cookiesAlt(int k, vector<int> A) {
    int counter = 0;
    while(A.size() > 1) {
        vector<int>::iterator lastCookieIndex = min_element(A.begin(), A.end());
        int lastCookie = *lastCookieIndex;
        if(lastCookie < k){
            A.erase(lastCookieIndex);
            vector<int>::iterator lastCookieIndex = min_element(A.begin(), A.end());
            int newValue = lastCookie + 2 * (*lastCookieIndex);
            A.erase(lastCookieIndex);
            A.push_back(newValue);
            counter++;
        } else {
            return counter;
        }
    }
    return -1;
}

int cookiesSubopt(int k, vector<int> A) {
    int counter = 0;
    while(A.size() > 1) {
        int lastCookieIndex = 0;
        int secondLastCookieIndex = 0;
        for(int i = 1; i < A.size(); ++i) {
            if(A.at(i) < k) {
                cout << "Bad cookie: [" << i << "] " << A.at(i) << endl;
                if(A.at(i) < A.at(lastCookieIndex)){
                    cout << "Goes first: [" << i << "] " << A.at(i) << endl;
                    secondLastCookieIndex = lastCookieIndex;
                    lastCookieIndex = i;
                }
            }
            if(
                (A.at(i) < A.at(secondLastCookieIndex) ||
                lastCookieIndex == secondLastCookieIndex) &&
                i != lastCookieIndex
            ) {
                cout << "Goes second: [" << i << "] " << A.at(i) << endl;
                secondLastCookieIndex = i;
            }
        }
        if(A.at(lastCookieIndex) < k) {
            int newValue = A.at(lastCookieIndex) + 2 * A.at(secondLastCookieIndex);
            cout << A.at(lastCookieIndex) << " + 2 * " << A.at(secondLastCookieIndex) << " = "  << newValue << endl;
            cout << "Erasing " << *(A.cbegin() + lastCookieIndex) << " and " << *(A.cbegin() + secondLastCookieIndex) << endl;
            int offset = lastCookieIndex < secondLastCookieIndex ? -1 : 0;
            A.erase(A.cbegin() + lastCookieIndex);
            A.erase(A.cbegin() + secondLastCookieIndex + offset);
            A.push_back(newValue);
            counter++;
        } else {
            cout << "No more bad cookies: " << counter << endl;
            return counter;
        }
    }
    cout << "Not enough cookies: " << counter << endl;
    return -1;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A.at(i) = A_item;
    }

    int result = cookies(k, A);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
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
