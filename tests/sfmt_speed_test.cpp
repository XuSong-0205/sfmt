#include "../include/format.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>


struct Point
{
	int x_;
	int y_;
	Point(int x, int y) noexcept : x_(x), y_(y) { }

	friend std::ostream& operator<<(std::ostream& os, const Point& p)
	{
		return os << "(" << p.x_ << ", " << p.y_ << ")";
	}
};

void test_sfmt()
{
	std::ofstream ofile1("./temp/file1.txt");
	std::ofstream ofile2("./temp/file2.txt");

	namespace ch = std::chrono;
	const auto get_time_point = [] { return ch::time_point_cast<ch::milliseconds>(ch::system_clock::now()); };
	constexpr int COUNT = 100'000;


	bool b = true;
	char c = 's';
	int num = 42;
	double pi = 3.14159265358;
	const char* ccptr = "hello const char*";
	std::string str = "hello std::string";
	std::string_view sv = "hello std::string_view";
	Point p(1, 1);

	// ostream test
	if constexpr (true)
	{
		std::ostream& os = ofile1;
		//std::ostream& os = std::cout;
		const auto t0 = get_time_point();
		for (int i = 0; i < COUNT; ++i)
		{
			os	<< "[test:" << i << "]"
				<< " b: " << std::boolalpha << b 
				<< ", c: {" << c << "}, num: " << num
				<< ", pi: " << std::setw(8) << std::setprecision(6) << pi
				<< ", ccptr: " << ccptr << ", str: " << str << ", sv: " << sv
				<< ", num: " << std::setfill(' ') << std::left << std::setw(6) << num
				<< ", num: " << std::setfill('x') << std::right << std::setw(6) << num
				<< ", num: " << std::showbase << std::oct << num
				<< ", num: " << std::showbase << std::nouppercase << std::hex << num
				<< ", num: " << std::showbase << std::uppercase << std::hex << num
				<< ", pi: " << std::showbase << std::scientific << std::nouppercase << pi
				<< ", pi: " << std::showbase << std::scientific << std::uppercase << pi
				<< ", pi: " << std::showbase << std::fixed << pi
				<< ", ptr: " << std::showbase << std::hex << std::nouppercase << static_cast<const void*>(ccptr)
				<< ", p: " << std::noshowbase << p
				<< "\n";
			os.unsetf(os.flags());
		}
		const auto t1 = get_time_point();
		sfmt::print("std::ostream 测试共计耗时: {} ms\n", (t1 - t0).count());
	};


	// sfmt test
	if constexpr (true)
	{
		std::ostream& os = ofile2;
		//std::ostream& os = std::cout;
		const auto t0 = get_time_point();
		for (int i = 0; i < COUNT; ++i)
		{
			sfmt::print(os, "[test:{i}] b: {:b}, c: {{1}}, num: {2}, pi: {pi:8.6}, ccptr: {4}, str: {5}, sv: {sv}, "
							"num: {2:<6}, num: {2:x>6}, num: {2:o}, num: {2:x}, num: {2:X}, "
							"pi: {3:e}, pi: {3:E}, pi: {3:f}, ptr: {9:p}, p: {p}\n",
							NAME_ARGS(b, c, num, pi, ccptr, str, sv, p, i), static_cast<const void*>(ccptr));
		}
		const auto t1 = get_time_point();
		sfmt::print("sfmt::print 测试共计耗时: {} ms\n", (t1 - t0).count());
	}


}



int main()
{
	test_sfmt();


	return 0;
}