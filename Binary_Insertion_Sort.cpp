
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void rng (int a[], int length) //method with 2 parameters which will work with an array of a desired size, or length
{
	srand(time(0)); //pseudo-random generator that seeds a random number, in this case it uses time() which is a method that counts the number of seconds since 1970 or so
	//^^ this is used in order to create a more random sequence of numbers 

	int num; //declares an integer named number which will hold the random number being generated 

	for (int i = 0; i < length; i++) //a for loop that iterates up to whatever length is desired 
	{
		num = rand() % 10; //another pseudo-random generator that returns an integer between 0-9, which is determined by the % 10

		a[i] = num; //sets the value at the index i, which is being incremented according to the for loop, equal to whatever random number was generated 
	}
}

int binary(int a[], int item, int left, int right) //method with 4 parameters which will hold the 2 pointers, left and right, as well as the array and the item being sorted
{
	int mid; //declares an integer named mid which will be a pointer to the middle of wherever the left and right pointers are

	if (right <= left) //an if loop that checks whether the right pointer is behind, or pointing at, the left pointer
	{
		if (item > a[left]) //if it is, then it proceeds to check if the item is greater than whatever value is being pointed at by the left pointer
		{
			return left + 1; //if it is, then the index after the left hand point is returned ( left + 1) this is because that is where larger values are placed 
		}
		return left; //if the item isn't larger than the value then the left hand is returned 
	}

	mid = (left + right) / 2; //mid is initialized as being the sum of the left and right hand pointers divided by 2

	if (item == a[mid]) //makes sure that the item being searched for isn't the same as the value at whatever mid value was determined the line before
	{
		return mid + 1; //if it is then it places the item behind the previous mid since they are the same value
	}

	if (item > a[mid]) //checks to see if the item being searched for is larger than the value at the middle
	{
		return binary(a, item, mid + 1, right); //if it is, the the algorithm recursively checks the right hand side, which is where the larger values are,
		//^^it checks the right side by starting the search at the number after mid, since it's larger than mid so it doesn't need to check again, up to the right hand pointer
	}
	return binary(a, item, left, mid - 1); //if the item is smaller then it checks the left hand side, which is where smaller values are placed
	//^^ similarly to the right hand side, it recursively checks from the left pointer, which is the "min", and the number in front of mid, since it's already determined to be smaller
}

void binary_insertion(int a[], int length) //binary insertion method that takes 2 parameters, an array of size "length" 
{
	int item, position, key; //declares 3 integers which will be used to hold the item being sorted as well as the position 

	for (int i = 1; i < length; i++) //a for loop that iterates up to the length of the array and starts at 1, or technically index 2, because the 1st index is automatically sorted
	{
		item = a[i]; //item is set equal to the value at i 
		key = i - 1;  //the key is set equal to wherever i is minus 1, so it will start at 0

		position = binary(a, item, 0, key); //position uses the binary search created to find the proper position of the item being sorted with the minimum at 0 and max at key

		while (key >= position) //while loop that checks whether the key is greater than or equal to the position found using the binary search
		{
			a[key + 1] = a[key]; //if it is then the value behind it must be swapped since it is larger so the value of item 1 index after the key is set equal to the value of key
			key--; //the index of key is decremeneted so that it can correspond to the proper value because so far only the values have been swapped
		}
		a[key + 1] = item; //finally, the swap is complete by setting the value of the array at 1 after key is set equal to whatever the item we were working with is 
	}
}

int main()
{
	int length; //declares an integer which will hold the value of the length/size we want for our array 

	cout << "1.) Welcome to the binary insertion sort algorithm, please enter the length of your array: " << endl; //displays a message to the user
	cin >> length; //takes a value input by the user and sets it equal to the integer declared earlier

	int * a = new int[length]; //this instantializes our array with the length that our user wanted

	rng(a, length); //the empty array is filled with random numbers using our rng method

	cout << "Your original array is: " << endl; //displays a message to the user
	for (int i = 0; i < length; i++) //uses a for loop that iterates up to the length of length
	{
		cout << " " << a[i] << " "; //writes every value in the array for the user to see
	}

	binary_insertion(a, length); //sorts the array using the binary insertion method that we created

	cout << endl << "Your sorted array is: " << endl; //displays a message to the user
	for (int i = 0; i < length; i++) //uses a for loop that iterates up to the length of length 
	{
		cout << " " << a[i] << " "; //writes every value of our now sorted array onto the console
	}
	cout << endl << "2.) Determining the time complexity of a nested loop algorithm: " <<  endl; 
	cout << endl << "i = n;" << endl << "while(i >= 1)" << endl << "{" << endl << "  j = i;" << endl << "  while(j <= n)" << endl << "{" << endl << "    j = 2 * j;" << endl << "}" << endl << "  i = i/2;" << endl << "}" << endl;
	cout << "the first while loop relies on a constant, or 1, therefore it has the time complexity of O(1)" << endl;
	cout << "the second while loop relies on the value of n, j <= n, so it is not constant and has a time complexity of O(n)" << endl;
	cout << "outside of the second while loop, i is set equal to itself halved. This is a O(log n) behavior and is seen in other algorithms such as the binary search " << endl;
	cout << "The other actions being preformed here, i = n, j = i, are all constants and therefore have a time complexity of O(1)" << endl;
	cout << "If you were to multiply all of these together you would get:" << endl << "1 * 1 * 1 * n * log n" << endl << "which would result in a final time complexity of O(n log n)" << endl;
    return 0;
}
