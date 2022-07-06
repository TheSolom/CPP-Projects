#include <iostream>
#include <vector>
using namespace std;

//Let k = max ,Then
//Count Sort is O(n+k) time & O(k) space - if k is about n^2 in value then the complexity will be O(n^2)
int main()
{
	vector <int> arr = { 9,3,10,9,5,3,90,9 };
	int max = -1;
	for (int i = 0; i < arr.size(); i++) //max element, O(n) time & space
		if (arr[i] > max)
			max = arr[i];


	int* count = new int[max + 1] {};

	for (int j = 0; j < arr.size(); j++) //frequency array, O(n) time & o(max) space
		count[arr[j]]++;


	for (int i = 0, index = 0 ; i <= max; i++) //count sort, O(max) time & o(1) space
	{
		int j = 0;
		while (j < count[i]) //it's tricky not nested loop it iterate on n elements, O(n) time & o(1) space 
		{
			arr[index++] = i;
			j++;
		}
	}

	for (int i : arr) //print array after sortation
		cout << i << " ";

	delete[] count;
}