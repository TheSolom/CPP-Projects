#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

double circle_area(double r) {
	const double PI = acos(-1.0);
	return PI * r * r;
}

int total_can_eat(vector<double>& areas, double cut_area) {
	int eaters_count{};
	for (int i = 0; i < (int)areas.size(); i++)
		eaters_count += areas[i] / cut_area;

	return eaters_count;
}

double largest_area(vector<double>& pie_radius, int people) {
	double start = 0, end = 0;

	vector<double> areas(pie_radius.size());
	for (int i = 0; i < (int)pie_radius.size(); i++) 
	{
		areas[i] = circle_area(pie_radius[i]);
		end = max(end, areas[i]);
	}

	//while(fabs(start-end) < 1e-3)	// Wrong answers
	for (int i = 0; i < 100; i++) 
	{
		double mid = start + (end - start) / 2;
		if (total_can_eat(areas, mid) >= people)
			start = mid;
		else
			end = mid;
	}

	return start;
}

int main() {
	int cases, n, f;
	cin >> cases;

	while (cases--) {
		cin >> n >> f;
		vector<double> pie_radius(n);

		for (int i = 0; i < n; i++)
			cin >> pie_radius[i];

		double area = largest_area(pie_radius, f + 1);	// +1 for the host person

		cout << fixed;
		cout << setprecision(4) << area << "\n";
	}
}
