// include the necessary libraries
#include <iostream>
#include <forward_list>
#include <chrono>
#include "animal.h"
#include "meerkat.h"
using namespace std;
using namespace std::chrono;
int main () {
	forward_list<Meerkat> list1;

	forward_list<Meerkat>::iterator it;

	// get a user specified value
	cout << "How many meerkats do you want to store?" << endl;
	unsigned long int num;
	cin >> num;
	// fill the list with a bunch of objects
	auto start = high_resolution_clock::now();
	for (unsigned long int i = 0; i < num; i++) {
		Meerkat tmp(0);
		list1.push_front(tmp); // this will copy the Meerkat into the list
		//cout << ".";
	}
	cout << endl;
	auto stop = high_resolution_clock::now();
	// compute the elapsed time in microseconds
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Duration (us) for part 1: " << duration.count() << endl;

	// now write code which will insert num Meerkats into list2.
	// the difference is that this code needs to insert each Meerkat
	// at the END of the forward_list
	forward_list<Meerkat> list2;

	start = high_resolution_clock::now();
	for(unsigned long int i = 0; i < num; i++){
		it = distance(list2.begin(), list2.end());
		list2.insert_after(it, Meerkat(0));
	}
	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);
	cout << "Duration (us) for part 2: " << duration.count() << endl;

	return 0;
}