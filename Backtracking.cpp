#include <iostream>
#include <iomanip>

using namespace std;

#define n 4
int w[] = { -1,3,4,5,6 };
bool include[] = { 0,0,0,0,0 };
int W = 13;

bool promising(int i, int weight, int total) {
	return ((weight + total >= W) && ((weight == W) || (weight + w[i + 1] <= W)));
}

void sumOfSubsets(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (weight == W) {
			cout << "Weight" << '\t' << "Status" << endl;
			for (int x = 1; x <= n; x++) {
				cout << setw(6) << w[x] << '\t' << (include[x] ? "include" : "exclude") << endl;
				//cout << endl;
			}
		}
		else {
			include[i + 1] = true;
			sumOfSubsets(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = false;
			sumOfSubsets(i + 1, weight, total - w[i + 1]);
		}
	}
}

int main()
{
	int total = 0;
	for (int i = 1; i <= n; i++) {
		total += w[i];
	}
	sumOfSubsets(0, 0, total);
	return 0;
}
