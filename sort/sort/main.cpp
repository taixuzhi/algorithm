#include <iostream>
#include <vector>
#include "sort.h"
#include <time.h>

using namespace std;

int main(){

	srand((unsigned)time(NULL));
	sort sort_test;
	sort_test.init_random((rand() % 10 + 5));
	sort_test.print_sort();
	//sort_test.bubbble_sort();
	//sort_test.insert_sort();
	//sort_test.select_sort();
	//sort_test.quick_sort();
	sort_test.bucket_sort();
	vector<int> test = sort_test.get_sort();
	sort_test.print_sort();
	system("pause");

}