#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "d_timer.h"

using namespace std;

void swap(double* a,double* b) 
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(vector<double>& v, double size)
{
	for (double step = 0; step < size - 1; step++) 
	{
		double min_idx = step;
		for (int i = step + 1; i < size; i++) 
		{

			// To sort in descending order, change > to < in this line.
			// Select the minimum element in each loop.
			if (v[i] < v[min_idx])
				min_idx = i;
		}

		// put min at the correct position
		swap(v[min_idx], v[step]);
	}
}


void insertionSort(vector<double>& v, int first, int last)
{
	int i, j;
	double target;

	for (i = first + 1; i < last; i++)
	{
		j = i;
		target = v[i];

		while (j > first && target < v[j - 1])
		{
			v[j] = v[j - 1];
			j--;
		}
		v[j] = target;
	}
}

template <typename T>
void merge(vector<T>& v, int first, int mid, int last)
{
	vector<T> tempVector;
	double indexA, indexB, indexV;
	indexA = first;
	indexB = mid;

	while (indexA < mid && indexB < last)
		if (v[indexA] < v[indexB])
		{
			tempVector.push_back(v[indexA]);
			indexA++;
		}
		else
		{
			tempVector.push_back(v[indexB]);
			indexB++;
		}

	while (indexA < mid)
	{
		tempVector.push_back(v[indexA]);
		indexA++;
	}

	while (indexB < last)
	{
		tempVector.push_back(v[indexB]);
		indexB++;
	}
	indexA = first;

	for (indexV = 0; indexV < tempVector.size(); indexV++)
	{
		v[indexA] = tempVector[indexV];
		indexA++;
	}
}

template <typename T>
void mergeSort(vector<T>& v, int first, int last)
{
	if (first + 1 < last)
	{
		int midpt = (last + first) / 2;

		mergeSort(v, first, midpt);
		mergeSort(v, midpt, last);
		merge(v, first, midpt, last);
	}
}


int pivotIndex(vector<double>& v, int first, int last)
{
	// index for the midpoint of [first,last) and the
	// indices that scan the index range in tandem
	int mid, scanUp, scanDown;
	// pivot value and object used for exchanges
	double pivot, temp;

	if (first == last)
		return last;
	else if (first == last - 1)
		return first;
	else
	{
		mid = (last + first) / 2;
		pivot = v[mid];

		// exchange the pivot and the low end of the range
		// and initialize the indices scanUp and scanDown.
		v[mid] = v[first];
		v[first] = pivot;

		scanUp = first + 1;
		scanDown = last - 1;

		// manage the indices to locate elements that are in
		// the wrong sublist; stop when scanDown <= scanUp
		for (;;)
		{
			// move up lower sublist; stop when scanUp enters
			// upper sublist or identifies an element >= pivot
			while (scanUp <= scanDown && v[scanUp] < pivot)
				scanUp++;

			// scan down upper sublist; stop when scanDown locates
			// an element <= pivot; we guarantee we stop at arr[first]
			while (pivot < v[scanDown])
				scanDown--;

			// if indices are not in their sublists, partition complete
			if (scanUp >= scanDown)
				break;

			// indices are still in their sublists and identify
			// two elements in wrong sublists. exchange
			temp = v[scanUp];
			v[scanUp] = v[scanDown];
			v[scanDown] = temp;

			scanUp++;
			scanDown--;
		}

		// copy pivot to index (scanDown) that partitions sublists
		// and return scanDown
		v[first] = v[scanDown];
		v[scanDown] = pivot;
		return scanDown;
	}
}


void quicksort(vector<double>& v, int first, int last)
{
	int pivotLoc;
	double temp;

	if (last - first <= 1)
		return;
	else if (last - first == 2)
	{
		if (v[last - 1] < v[first])
		{
			temp = v[last - 1];
			v[last - 1] = v[first];
			v[first] = temp;
		}
		return;
	}
	else
	{
		pivotLoc = pivotIndex(v, first, last);

		quicksort(v, first, pivotLoc);

		quicksort(v, pivotLoc + 1, last);
	}
}


void bubbleSort(vector<double>& v, int size)
{
	unsigned int i = 0, j = 0;
	for (i = 0;i < (size - 1);i++)
	{
		for (j = 0;j < (size - i - 1);j++)
		{
			if (v[j] > v[j + 1])
			{
				double temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

void shellSort(vector<double>& v, int n) {
	for (int interval = n / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < n; i += 1) {
			double temp = v[i];
			int j;
			for (j = i; j >= interval && v[j - interval] > temp; j -= interval) {
				v[j] = v[j - interval];
			}
			v[j] = temp;
		}
	}
}

int main()
{
	ifstream fPtr("Query.txt", ios::in);
	vector<double> vec, vec2, vec3, vec5, vec4, vec6;
	double input;
	timer timeS, timeI, timeB, timeQ, timeSh, timeM;
	while (!fPtr.eof())
	{
		fPtr >> input;
		vec.push_back(input);
		vec2.push_back(input);
		vec3.push_back(input);
		vec4.push_back(input);
		vec5.push_back(input);
		vec6.push_back(input);
	}
	double vecSize = vec.size();
	//timeS.start();
	//selectionSort(vec,vecSize);
	//timeS.stop();
	timeQ.start();
	quicksort(vec2, 0, vec2.size());
	timeQ.stop();
	/*timeB.start();
	bubbleSort(vec3, vec3.size());
	timeB.stop();
	timeM.start();
	mergeSort(vec4, 1, vec4.size());
	timeM.stop();
	timeSh.start();
	shellSort(vec5, vec5.size());
	timeSh.stop();
	timeI.start();
	insertionSort(vec6, vec6[0], vec6[vec6.size()]);
	timeI.stop();*/

	//cout << "Selection sort time  : " << timeS.time() << " second."<< endl;
	cout << "Quick sort time  : " << timeQ.time() << " second." << endl;
	/*cout << "Bubble sort time  : " << timeB.time() << " second." << endl;
	cout << "Merge sort time  : " << timeM.time() << " second." << endl;
	cout << "Shell sort time  : " << timeSh.time() << " second." << endl;
	cout << "Insertion sort time : " << timeI.time() << " second." << endl;*/

	return 0;
}