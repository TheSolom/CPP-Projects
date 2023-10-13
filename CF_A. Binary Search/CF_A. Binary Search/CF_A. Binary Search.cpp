#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<pair<int, int> > vect;

	vect.push_back(make_pair(1, 20));
	vect.push_back(make_pair(3, 42));
	vect.push_back(make_pair(4, 36));
	vect.push_back(make_pair(2, 80));
	vect.push_back(make_pair(7, 50));
	vect.push_back(make_pair(9, 20));
	vect.push_back(make_pair(3, 29));

	// sorting the vector according to key
	sort(vect.begin(), vect.end());

	// printing the sorted vector
	cout << "KEY" << '\t' << "ELEMENT" << endl;
	for (pair<int, int>& x : vect)
		cout << x.first << '\t' << x.second << endl;

	auto id = distance(vect.begin(), upper_bound(vect.begin(), vect.end(),
		make_pair(3, numeric_limits<int>::max())));

	cout << id;
}
