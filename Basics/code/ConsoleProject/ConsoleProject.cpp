// ConsoleProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

//#include <boost/timer.hpp>
#include <boost/progress.hpp>

#include <libs/date_time/src/gregorian/greg_names.hpp>
//#include <libs/date_time/src/gregorian/date_generators.cpp>
#include <libs/date_time/src/gregorian/greg_month.cpp>
#include <libs/date_time/src/gregorian/gregorian_types.cpp>

#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost;

int main()
{
	boost::timer t;

	boost::progress_display pd(100);

	for (int i = 0; i < 100; ++i) //进度条
	{
		++pd;
	}

	boost::gregorian::date dt(2009, 12, 8); //date_time 库
	assert(dt.year() == 2009);
	assert(dt.day() == 8);
	boost::gregorian::date::ymd_type ymd = dt.year_month_day();
	std::cout << "\n" << ymd.year << "/" << ymd.month << "/" << ymd.day << " the day is "
		<< dt.day_of_year() << " days of this year" << std::endl;

	std::cout << boost::gregorian::to_iso_extended_string(dt) << std::endl; //转换为其他格式
	std::cout << boost::gregorian::to_iso_string(dt) << std::endl;
	std::cout << boost::gregorian::to_simple_string(dt) << std::endl << std::endl;

	//对数组排序操作
	std::vector<int> test_vc(100);
	std::vector<int>::iterator beg_it = test_vc.begin();
	std::vector<int>::iterator end_it = test_vc.end();
	std::srand(std::time(NULL));

	std::for_each(beg_it, end_it, [](int& n) {n = rand(); });
	std::copy(beg_it, end_it, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl << std::endl;
	std::sort(beg_it, end_it, std::greater<int>());
	std::copy(beg_it, end_it, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl << std::endl;

	boost::posix_time::ptime pt(boost::gregorian::date(2005, 2, 6));

	std::cout << t.elapsed() << "s" << std::endl; //程序运行时间

	system("pause");

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
