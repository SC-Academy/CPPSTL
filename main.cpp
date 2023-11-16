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
