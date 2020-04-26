#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	unsigned numberOfStrings;
	vector<string> v;
    string str;

	cin >> numberOfStrings;

	while (numberOfStrings) {
		cin >> str;
		v.push_back(str);
		numberOfStrings--;
	}

	sort(v.begin(), v.end(), [](string i,string j)
		{
			for(int c = 0; c < i.size(); ++c) i[c] = tolower(i[c]);
			for(int c = 0; c < j.size(); ++c) j[c] = tolower(j[c]);
			return (i < j);
		});

	for(const auto& i : v) {
		cout << i << " ";
	}

	return 0;
}