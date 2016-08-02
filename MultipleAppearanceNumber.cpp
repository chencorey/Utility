// Question: Given n+1 integers that are between 0 and n-1 inclusive, find the number that appears more than once. 
// Guaranteed that only 1 number appears more than once in input.
// No changing array, do in constant space.
int MultipleAppearanceNumber(vector<int> arr)
{
	int left = 0;
	int right = arr.size()-2;//n-1
	//init binary search 0 to n-1, we are searching for the number here
	while(left<right)
	{
		int mid = (left+right)/2;
		int count = 0;
		for(int i = 0; i<arr.size(); i++)
		{
			if(arr[i]>mid)
			{
				count++;
			}
		}
		// the heuristic used to determine which side to traverse: always go to the side of mid where there are more elements
		// than expected (=n-1-mid). If n is 9 and mid is 5, we expect 3 elements here (i.e. 6, 7, 8). 
		// This will provably always be the side the duplicated element is on. Proof below
		// Let's start by assuming our heuristic is false, and creating a contradiction.
		// There must exist a set of counterexamples if our heuristic is false. Consider one such counterexample
		// Define R as the number of elems greater than mid, and L as the number of elems less than mid. 
		// Assume WLOG that the element that appears more than once is less than mid. Call this number k. 
		// Then, we are looking only at the instances where R>L (we want to create a counterexample to our heuristic). 
		// Call M the number of times k appears. 
		// Case 1: What if M=2?
		// Then all other numbers must appear exactly once (because there are n+1 integers, going from 0 to n-1)
		// Then our heuristic will hold true. Therefore, M!=2. 
		// Case 2: What if M>2?
		// Then there will always be at least M-2 elements who do not appear. We can transform our counterexample when M>2 to M = 2
		// by removing a duplicate, and adding one of the M-2 numbers that didn't appear. Note that doing so will not change the
		// result of our heuristic. Call Q the element that we added. If Q<mid, then R is still >L, and if Q> mid, R is also still
		// <L. This means that when M>2, there exists an equivalent solution where M=2. 
		// CONTRADICTION! We proved M!=2, so therefore no solution exists for M>2. 
		// Therefore our heuristic is provably correct.
		// QED
		if(count>arr.size()-2-mid) left = mid+1;
		else right = mid;
	}
	return left;
}
// Runtime analysis: logn for the binary search, each iteration through search takes n time.
// O(nlogn)
// To me, the O(n) is pretty hard and long to implement in an interview, and even harder to arrive at
// I came up with the binary search way almost instantly, and said that an effective heuristic is all you need.
// In my opinion, the proof is hard, but this "greedy" way is not all that hard to arrive at. Also, it only takes ~10 lines of code.
// The general intent/direction of the proof is not hard to come up with though, but the more formal approach (above) takes more time.

// for further reference, the O(n) approach uses the values as indices. This will create a cycle in a "linked-list"-esque approach. 
// find collision point by moving a slow runner and a fast runner through "linked list". Fast runner proceeds by 2 for every 1 move
// by slow. 
// Need to find starting point of the cycle, using two new runners. By setting one runner at head and another at the intersection 
// point where the two original runners met, move the two new pointers, 1 move at a time for each of them
// Mathematically possible to prove they will meet (instead of chasing around loop forever)
