// sample_project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//




//#include "tms-nets-3.0.1/include/tms-nets.hpp"

#include <cstdint> // needed for uint*_t types
#include <iostream> // needed for output

#include <cmath>
#include <unordered_set>
#include <cstdint> // needed for uint*_t types
#include <iostream>
#include <time.h>
#include  <random>
#include <algorithm>
#include  <iterator>
#include "tms-nets-3.0.1/include/tms-nets/details/gfppoly.hpp"

#include "tms-nets-3.0.1/include/test.hpp"

#define pi 3.14159265358979




//using namespace tms::gf2poly;
using namespace tms;




long double f(tms::Point x)//функция для проверки
{
	return x[0] * sin(x[1] * pi) / ((x[2] - 5) * cos(x[3] * x[4]));
}

bool is_in_sphere(tms::Point x) {//функция, которая проверяет лежит ли точка в сфере
	double summ = 0.0;
	for (int i = 0; i < x.size(); ++i) {
		summ += x[i] * x[i];
	}
	
	return (summ <= 1);
}
void test1() {//тест для функции f - вычисление многомерного интеграла
	int p = 3;
	int m = 7;
	int s = 5;
	long double                         answer2 = 0.0;
	tms::p_Niederreiter					my(m, s, p);//создаем тмс-сеть, на данный момент ясны генерирующие матрицы
	std::vector<Point> vect(pow(p, m), Point(s));//создаем вектор точек
	vect = my.create_net();//создаем точки с помощью генерирующих матриц


	/*
	uint32_t const                      tms_net_point_count = 1UL << m;
	tms::Sobol                          tms_net(m, s);
	

	long double                         answer1 = 0.0;
	
		
	for (uint32_t point_i = 0; point_i < tms_net_point_count; ++point_i) {
		answer1 += f(tms_net.generate_point(point_i));
	}*/


	for (uint32_t point_i = 0; point_i < pow(p, m); ++point_i) {
		answer2 += f(vect[point_i]);
	}
	//answer1 /= tms_net_point_count;
	answer2 /= pow(p, m);

	//std::cout << "J(x) = " << answer1 << '\n';
	std::cout << "J(x) = " << answer2 << '\n';
}

void test2() {//вычисление обьема сферы. Реализация проста - (количество точек в сфере / количество точек всего)
	int m = 7;
	int s = 3;
	int p = 5;

	uint32_t const                      tms_net_point_count = 1UL << m;
	tms::Niederreiter                   tms_net(m, s);
	uint32_t                            inside_point_count1 = 0;

	for (uint32_t point_i = 0; point_i < tms_net_point_count; ++point_i)
	{
		tms::Point current_point = tms_net.generate_point(point_i);
		inside_point_count1 += is_in_sphere(current_point);
	}
	std::cout << "V(Sigma1) = " << ((tms::Real)(inside_point_count1) / tms_net_point_count) << '\n';



	

	tms::p_Niederreiter					my(m, s, p);
	uint32_t                            inside_point_count = 0;

	std::vector<Point> vect(pow(p, m), Point(s));
	vect = my.create_net();

	for (uint32_t point_i = 0; point_i < pow(p, m); ++point_i) {
		inside_point_count += is_in_sphere(vect[point_i]);
	}

	std::cout << "V(Sigma) = " << ((tms::Real)(inside_point_count) / pow(p, m)) << '\n';
}





void test3() {
	//проверка на правильность тмс-сети
	int p = 5;
	int m = 5;
	int s = 2;
	tms::p_Niederreiter					my(m, s, p);

	long double                         answer1 = 0.0;

	std::vector<Point> vect(pow(p, m), Point(s));
	vect = my.create_net();

	int t = 0;

	int d = m - t;

	generateIntervals(s, d, p, vect, t);

}

int main() {
	test3();
	
	return 0;
}