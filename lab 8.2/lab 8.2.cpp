#include <iostream>
#include <string>
using namespace std;

size_t find(const string& str, size_t startPos) {//знаходження позиції закриваючої дужки, що відповідає вказаній відкриваючій дужці.
    size_t openCount = 1;
    size_t i = startPos + 1;

    while (i < str.length() && openCount > 0) {
        if (str[i] == '(') {
            openCount++;
        }
        else if (str[i] == ')') {
            openCount--;
        }
        i++;
    }

    return i - 1;
}

string extract(const string& str) {//вилучення груп символів між дужками та самі дужки, включаючи вкладені дужки. 
    size_t startPos = str.find('(');
    string result = str;

    while (startPos != string::npos) {
        size_t endPos = find(result, startPos);

        if (endPos != string::npos) {
            result.erase(startPos, endPos - startPos + 1);
        }

        startPos = result.find('(');
    }

    return result;
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    string modifiedString = extract(str);
    cout << "Modified String: " << modifiedString << endl;

    return 0;
}
