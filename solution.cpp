#include "solution.h"

#include <unordered_map>
#include <functional>
using namespace sol2107;
using namespace std;

/*takeaways
  - the window needs to grow to a fixed size of k and then
    starts sliding to the right until it can't
  - create a map to record how many candies each flavor has
  - use this as an example [1,2,2,3,4,3], k = 3
    - you first have to grow the window to the size of 3
      : candies[0..2] = [1,2,2]
    - during which time you are just giving away candies
      so you deduct one by one per the flavor from the
      map, but never put them back
    - after the window grew big enough, you need to
      start evaluating how many flavors you have left
      in the map
    - next when you move to the next window candies[1..3]=[2,2,3]
      ,you have to put the candy at index 0 back, which is i-k=3-3=0
      - i is the index of the very last candy within the window
*/

int Solution::share(vector<int> &candies, int k)
{
  const int N = candies.size();
  /*record how many candies each flavor has */
  auto cnt = unordered_map<int, int>();
  for (auto c : candies)
    cnt[c]++;

  /* number of flavors from the leftover candies */
  auto f = 0;

  /* i is the index of the very last candy inside the window of size k */
  for (auto i = 0; i < N; i++)
  {
    cnt[candies[i]]--;

    /* once the window is big enough you should start
       putting back the candies sliding out of the
       window one bye one
    */
    if (i >= k)
      cnt[candies[i - k]]++;

    /* once the count of a flavor reaches to 0,
       the flavor needs to be removed so you
       can count the remaining flavors correctly
    */
    if (cnt[candies[i]] == 0)
      cnt.erase(candies[i]);

    /* start evaluating once the window is big enough
       - notice that the criterion is different from
         putting candies back
     */
    if (i >= k - 1)
      f = max(f, (int)cnt.size());
  }

  return f;
}