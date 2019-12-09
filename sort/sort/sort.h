#ifndef SORT_H_
#define SORT_H_
#include <vector>
using namespace std;;


class sort
{
public:
	sort();
	~sort();
	sort(vector<int> _init_vector);
	void init_random(int _vector_size);
	void bubbble_sort();
	void insert_sort();
	void select_sort();
	void quick_sort();
	void bucket_sort();
	void quick_sort(vector<int>& _vector,int _l_idx,int _r_idx);

	void print_sort();
	vector<int> get_sort();

private:
	int vector_size_;
	vector<int> sort_vector_;

};



#endif