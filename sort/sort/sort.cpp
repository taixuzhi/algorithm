#include "sort.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

sort::sort(){
	vector_size_ = 0;
	sort_vector_.clear();
}

sort::~sort(){

}

void sort::init_random(int _vector_size){
	vector_size_ = _vector_size;
	sort_vector_.reserve(vector_size_);
	srand((unsigned)time(NULL));
	for (int i = 0; i < vector_size_;i++)
	{
		sort_vector_.push_back(rand());
	}
}

void sort:: print_sort(){
	
	for (int i = 0; i < sort_vector_.size();i++)
	{
		cout << sort_vector_[i] << "    ";
	}
	cout << endl;
}

vector<int> sort::get_sort(){
	return sort_vector_;
}

void sort::bubbble_sort(){
	if (0 == vector_size_ || 1 == vector_size_)
	{
		return;
	}
	for (int i = vector_size_ - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (sort_vector_[j] > sort_vector_[j + 1])
			{
				swap(sort_vector_[j], sort_vector_[j + 1]);
			}
		}
		//print_sort();
	}
}

void sort::insert_sort(){
	if (0 == vector_size_ || 1 == vector_size_)
	{
		return;
	}
	for (int i = 1; i < vector_size_;i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (sort_vector_[j] > sort_vector_[j + 1])
			{
				swap(sort_vector_[j], sort_vector_[j + 1]);
			}
		}
	}
}

void sort::select_sort(){
	if (0 == vector_size_ || 1 == vector_size_)
	{
		return;
	}
	for (int i = vector_size_- 1; i > 0; i--)
	{
		//int min_idx = i;
		//for (int j = i + 1; j < vector_size_;j++)
		//{
		//	min_idx = sort_vector_[j] < sort_vector_[min_idx] ? j : min_idx;
		//}
		//swap(sort_vector_[i], sort_vector_[min_idx]);
		int max_idx = i;
		for (int j = 0; j < i; j++)
		{
			max_idx = sort_vector_[j] > sort_vector_[max_idx] ? j : max_idx;
		}
		swap(sort_vector_[i], sort_vector_[max_idx]);


	}
}

void sort::quick_sort(){
	if ( 0 == vector_size_ || 1 == vector_size_)
	{
		return;
	}
	quick_sort(sort_vector_, 0 , vector_size_ -1);
}

void sort::quick_sort(vector<int>& _vector, int _l_idx, int _r_idx){
	if (_l_idx < _r_idx)
	{
		int l = _l_idx;
		int r = _r_idx;
		srand((unsigned)time(NULL));
		int random_idx = rand() % (r - l) + l;
		swap(_vector[random_idx], _vector[r]);
		int less = l - 1;
		int more = r;
		while (l < more)
		{
			if (_vector[l] < _vector[r])
			{
				swap(_vector[++less], _vector[l++]);

			}
			else if (_vector[l] > _vector[r])
			{
				swap(_vector[--more], _vector[l]);
			}
			else
			{
				l++;
			}
		}
		swap(_vector[more], _vector[r]);
		int less_idx = less + 1;
		int more_idx = more;
		quick_sort(_vector, _l_idx, less);
		quick_sort(_vector, more + 1, _r_idx);
	}
}

void sort::bucket_sort(){
	if (0 == vector_size_ || 1 == vector_size_)
	{
		return;
	}
	int min_vector = INT_MAX;
	int max_vector = -INT_MAX;
	for (int i = 0; i < vector_size_; i++)
	{
		if (min_vector > sort_vector_[i])
		{
			min_vector = sort_vector_[i];
		}
		if (max_vector < sort_vector_[i])
		{
			max_vector = sort_vector_[i];
		}
	}
	int* bucket = new int[max_vector - min_vector +2];
	memset(bucket,0,(max_vector - min_vector +2)*sizeof(int));

	for (int i = 0; i < vector_size_;i++)
	{
		bucket[sort_vector_[i] - min_vector]++;
	}
	int i = 0;
	for (int j = 0; j < max_vector - min_vector + 2;j++)
	{
		while (bucket[j]-- >0)
		{
			sort_vector_[i++] = j + min_vector;
		}
	}

}



