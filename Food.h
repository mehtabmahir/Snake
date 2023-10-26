#ifndef FOOD_H
#define FOOD_H
#include <windows.h>
#include <cstdlib>
#include <ctime>
#define WIDTH 80
#define HEIGHT 40

class Food{
	private:
		COORD pos;
	public:
		void gen_food();
		COORD get_pos();
};
#endif
