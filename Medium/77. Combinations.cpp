// Top poster solution on Leetcode (with my added comments)

class Solution {
public:

    // Basically, the idea is to start with a vector of [1,...,k] in order.
    // - Take advantage of the fact that push_back will copy your vector for you
    // - Increase the last element as much as you can until you can't increase
    //   it anymore (i.e., get as many combos as you can by just changing the
    //   largest element)
    //     - Then, increase the next last element, and so on...

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};


#if 0
// My shitty recursive solution
class Solution {
public:
    vector<vector<int>> combinations;

    // Takes combo and creates k + 1 combinations (k new combinations since we'll store one in the existing
    //   combo) with each i in [n - k, n] at index
    // assume combo is a vector of the right size already inside combinations
    void addNextValue(int n, int k, int index, int comboIndex) {
        int size = combinations[comboIndex].size();
        if (size == index) return;
        if (n == k) {
            for (int i = 0; i < size - index; ++i) {
                combinations[comboIndex][index + i] = k - i;
            }
            return;
        }
        int originalSize = combinations.size();
        combinations.resize(combinations.size() + (n - k));

        auto &combo = combinations[comboIndex];
        
        // copy combo to make newCombos
        for (int i = 0; i < (n - k); ++i) {
            auto &newCombo = combinations[originalSize + i];
            newCombo.resize(size);
            for (int j = 0; j < index; ++j) {
                newCombo[j] = combo[j];
            }
        }
        
        combo[index] = n;
        
        // add next values and recurse
        for (int i = 0; i < (n - k); ++i) {
            auto &newCombo = combinations[originalSize + i];
            newCombo[index] = n - 1 - i;
        }

        addNextValue(n - 1, k - 1, index + 1, comboIndex);

        for (int i = 0; i < (n - k); ++i) {
            addNextValue(n - 1 - i - 1, k - 1, index + 1, originalSize + i);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        // in any given combo, list the elements in descending order
        //  so we do not get duplicates (we just check that the 
        //   element we're adding is less than the last one we added)
        // this also ensures that all combos are themselves unique
        
        combinations.resize(1);
        combinations[0].resize(k);
        addNextValue(n, k, 0, 0);
        return combinations;
    }
};

#endif