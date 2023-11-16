## Standard Template Library Example in C++

This program demonstrates various operations on vectors using C++'s standard library. It creates a vector of 10 random integers, prints it, shuffles it, prints it again, calculates its sum, finds its minimum and maximum elements, and finally sorts it in ascending order. Throughout the program, it utilizes various algorithms and function objects from the standard library, showcasing their effectiveness in manipulating and analyzing data structures..

### Code 

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <random>

using namespace std;

int main() {
  // Create a vector of 10 random integers in the range [1, 100]
  vector<int> v(10);
  random_device rd; // Random number generator
  mt19937 gen(rd()); // Mersenne Twister engine
  uniform_int_distribution<> dis(1, 100); // Uniform distribution
  generate(v.begin(), v.end(), bind(dis, gen)); // Fill the vector with random numbers

  // Print the vector using an iterator
  cout << "The vector is: ";
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Shuffle the vector using a random engine
  shuffle(v.begin(), v.end(), gen);

  // Print the shuffled vector
  cout << "The shuffled vector is: ";
  for (int x : v) // Use a range-based for loop
  {
    cout << x << " ";
  }
  cout << endl;

  // Find the sum of the vector elements using an algorithm
  int sum = accumulate(v.begin(), v.end(), 0);

  // Print the sum
  cout << "The sum of the vector elements is: " << sum << endl;

  // Find the minimum and maximum elements in the vector using a pair of iterators
  auto minmax = minmax_element(v.begin(), v.end());

  // Print the minimum and maximum elements
  cout << "The minimum element in the vector is: " << *minmax.first << endl
      << "The maximum element in the vector is: " << *minmax.second << endl;

  // Sort the vector in ascending order without using a lambda expression
  sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

  // Print the sorted vector
  cout << "The sorted vector is: ";
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
```
### Usage

To compile and run the program, simply execute the following commands: </br>
 `g++ main.cpp -o main ` </br>
`./main`

### Output

The program will print the following output to the console:

The vector is: 57 73 35 92 1 60 88 52 96 98  </br>
The shuffled vector is: 98 1 35 52 60 73 88 57 92 96 </br>
The sum of the vector elements is: 652  </br>
The minimum element in the vector is: 1  </br>
The maximum element in the vector is: 98  </br>
The sorted vector is: 1 35 52 57 60 73 88 92 96 98

## License
This project is licensed under the MIT License. For more information, please see the LICENSE file.


