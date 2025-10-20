#include <iostream>
#include <cstdint>

/// <summary>
/// 再帰的な賃金計算
/// </summary>
/// <param name="hour">働く時間</param>
/// /// <param name="hourlyWage">時給</param>
/// <returns>貰えるお金</returns>
uint32_t RecurringWageCalculation(uint32_t hour, uint32_t hourlyWage) {
	if (hour != 0) {
		return hourlyWage + RecurringWageCalculation(hour - 1, hourlyWage * 2 - 50);
	}
	return 0;
}

/// <summary>
/// 一般的な賃金計算
/// </summary>
/// <param name="hour">働く時間</param>
/// <param name="hourlyWage">時給</param>
/// <returns>貰えるお金</returns>
uint32_t GeneralWageCalculation(uint32_t hour, uint32_t hourlyWage) {
	return hour * hourlyWage;
}


int main() {
	//一般的な賃金計算の時給
	const uint32_t generalHourlyWage = 1226;
	//再帰的な賃金体系の最初の時給
	const uint32_t firstRecurringHourlyWage = 100;
	
	//結果の出力
	std::cout << "働く時間, 一般的な賃金体系の給与, 再帰的な賃金体系の給与" << std::endl;
	for (uint32_t workingHours = 1; workingHours <= 10; workingHours++) {
		std::cout <<  workingHours << "時間, " << GeneralWageCalculation(workingHours, generalHourlyWage) << "円, " << RecurringWageCalculation(workingHours, firstRecurringHourlyWage) << "円" << std::endl;
	}


	return 0;
}
