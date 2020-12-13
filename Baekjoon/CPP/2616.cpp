#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 50000 + 1
int passengerCarNum;
int passengerCar[MAX];
int maxCarry;
int cache[3][MAX];

int maxPassenger(int trainNum, int idx) {

	if (trainNum == 3 || idx >= passengerCarNum) return 0;

	int &result = cache[trainNum][idx];

	if (result != -1) return result;

	result = 0;

	if (idx + maxCarry - 1 <= passengerCarNum)
		result = max(maxPassenger(trainNum, idx + 1), (passengerCar[idx + maxCarry - 1] - passengerCar[idx - 1]) + maxPassenger(trainNum + 1, idx + maxCarry));



	return result;
}

void solution() {

	cin >> passengerCarNum;

	for (int i = 1; i <= passengerCarNum; i++) {
		int temp;

		cin >> temp;

		passengerCar[i] = passengerCar[i - 1] + temp;
	}

	cin >> maxCarry;

	memset(cache, -1, sizeof(cache));

	cout << maxPassenger(0, 1) << '\n';

}

int main() {

	solution();

	return 0;
}