#include <iostream>
#include <thread>

using namespace std;

/// <summary>
/// threadという文とその横に指定した番号を出力
/// </summary>
/// <param name="num">指定する番号</param>
void PrintThreadNum(int num) {
	cout << "thread " << num << endl;
}

int main() {
	thread  th1(PrintThreadNum, 1);
	th1.join();
	thread  th2(PrintThreadNum, 2);
	th2.join();
	thread  th3(PrintThreadNum, 3);
	th3.join();

	return 0;
}