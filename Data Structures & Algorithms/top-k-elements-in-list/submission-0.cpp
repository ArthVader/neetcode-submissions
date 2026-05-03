class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // k tells us how many most frequent nums to return, order doesnt matter
        // nums contains list of integers

        // use the hash map to count the frequency
        map<int, int> IntegerFrequencyMap = {};
        for(const int& num: nums)
        {
            if(IntegerFrequencyMap.contains(num))
            {
                ++IntegerFrequencyMap[num];
            }
            else
            {
                IntegerFrequencyMap[num] = 0;
            }
        }

        // then we need to get the entries in the hash map and sort them from least to greatest.
        vector<pair<int, int>> IntegerFrequencyVector = {};
        for(const pair<int, int>& kv: IntegerFrequencyMap)
        {
            IntegerFrequencyVector.push_back(kv);
        }
        
        // sort the IntegerFrequencyVector based on the values in descending order
        sort(IntegerFrequencyVector.begin(), IntegerFrequencyVector.end(), [=](pair<int, int>& a, pair<int, int>& b)
        {
            return a.second > b.second;
        });

        // then we need to return k amounts of numbers in the return vector
        vector<int> topKFrequentVector = {};
        int currentIteration = 0;
        for(const pair<int, int>& IntegerFrequencyPair: IntegerFrequencyVector)
        {
            if(currentIteration >= k)
            {
                break;
            }

            topKFrequentVector.push_back(IntegerFrequencyPair.first);
            ++currentIteration;
        }

        return topKFrequentVector;
    }
};
