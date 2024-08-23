#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

bool possible(vector<double> positions, double msg_dist, double can_move_dist) {
	double last_pos = positions[0] + can_move_dist;

	for (int i = 1; i < (int)positions.size(); i++)
	{
		double last_msg_pos = last_pos + msg_dist;
		if (positions[i] - can_move_dist > last_msg_pos)
			return false;
		
		last_pos = min(last_msg_pos, positions[i] + can_move_dist);
	}
	return true;
}

double min_time(vector<double>& positions, double msg_dist, double biggest_dist = 1e9) {
	double start = 0.0, end = biggest_dist;

	//for(int iter = 0; iter < 100; iter++) {		// also works
	while (end - start > 1e-9) {
		double mid = start + (end - start) / 2.0;

		if (possible(positions, msg_dist, mid))
			end = mid;
		else
			start = mid;
	}
	return start;
}

int main() {
	int cases, n;
	double msg_dist;
	cin >> cases;

	while (cases--) {
		cin >> msg_dist >> n;
		vector<double> positions(n);

		for (int i = 0; i < n; i++)
			cin >> positions[i];

		double time = min_time(positions, msg_dist, positions[n - 1]);

		cout << fixed;
		cout << setprecision(2) << time << "\n";
	}
}

