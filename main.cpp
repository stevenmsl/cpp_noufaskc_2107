#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol2107;

/*
Example 1:
Input: candies = [1,2,2,3,4,3], k = 3
Output: 3
Explanation:
Give the candies in the range [1, 3] (inclusive) with flavors [2,2,3].
You can eat candies with flavors [1,4,3].
There are 3 unique flavors, so return 3.
*/

tuple<vector<int>, int, int> testFixture1()
{
  return make_tuple(vector<int>{1, 2, 2, 3, 4, 3}, 3, 3);
}

/*
Input: candies = [2,2,2,2,3,3], k = 2
Output: 2
Explanation:
Give the candies in the range [3, 4] (inclusive) with flavors [2,3].
You can eat candies with flavors [2,2,2,3].
There are 2 unique flavors, so return 2.
Note that you can also share the candies with flavors
[2,2] and eat the candies with flavors [2,2,3,3].
*/

tuple<vector<int>, int, int> testFixture2()
{
  return make_tuple(vector<int>{2, 2, 2, 2, 3, 3}, 2, 2);
}
/*
Input: candies = [2,4,5], k = 0
Output: 3
Explanation:
You do not have to give any candies.
You can eat the candies with flavors [2,4,5].
There are 3 unique flavors, so return 3.
*/
tuple<vector<int>, int, int> testFixture3()
{
  return make_tuple(vector<int>{2, 4, 5}, 0, 3);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::share(get<0>(f), get<1>(f))) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::share(get<0>(f), get<1>(f))) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - expect to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::share(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}