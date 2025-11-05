class Solution {
public:
    unordered_map<long long, long long> counts;
    set<pair<long long, long long>, greater<pair<long long, long long>>> top, spare;
    long long sum = 0;


    void insertValue(int value, int x){
        long long count = counts[value];
        counts[value]++;
        pair<long long, long long> prevNode = {count, value};
        pair<long long, long long> newNode = {count + 1, value};
        if(top.find(prevNode) != top.end()){
            top.erase(prevNode);
            sum-=count * value;
            // sum+=value;
            // cout << "exists in top " << value << endl;
        }
        if(spare.find(prevNode) != spare.end()){
            spare.erase(prevNode);
        }
        top.insert(newNode);
        sum+=newNode.first * newNode.second;
        if(top.size() > x){
            // cout << "limit " << sum << endl;
            auto topLow = --top.end();
            // cout << "topLow " << topLow->first << " " << topLow->second << endl;
            sum-= topLow->first * topLow->second;
            spare.insert(*topLow);
            top.erase(topLow);
        }
    }

    void eraseValue(int value, int x){
        long long count = counts[value];
        counts[value]--;
        pair<long long, long long> prevNode = {count, value};
        pair<long long, long long> newNode = {count - 1, value};
         if(top.find(prevNode) != top.end()){
            top.erase(prevNode);
            sum-=count * value;
        }
        if(spare.find(prevNode) != spare.end()){
            spare.erase(prevNode);
            spare.insert(newNode);
            return;
        }
        top.insert(newNode);
        sum+=newNode.first * newNode.second;
        if(spare.empty()) return;
        // cout << sum << endl;

        auto spareHigh = spare.begin();
        top.insert(*spareHigh);
        // sum+=spareHigh->first * newNode.second;
        // cout << "spareHigh: " << spareHigh->first << " " << spareHigh->second << endl;
        sum+=spareHigh->first * spareHigh->second;
        spare.erase(spareHigh);
        if(top.size() > x){
            // cout << "hai" << endl;
            auto topLow = --top.end();
            sum-= topLow->first * topLow->second;
            spare.insert(*topLow);
            top.erase(topLow);
        }
        // cout << "last " << sum << endl;
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> result;
        for (int i = 0; i < k; i++)
        {
            insertValue(nums[i], x);
        	// sum += pairs[pairs.size() - i].first * pairs[pairs.size() - i].second;
        }
        result.push_back(sum);
        // cout << sum << endl;
        for (int i = k; i < nums.size(); i++)
        {
            eraseValue(nums[i-k], x);
            insertValue(nums[i], x);
            // cout << sum << endl;
            result.push_back(sum);
            // cout << sum << endl;
        	// sum += pairs[pairs.size() - i].first * pairs[pairs.size() - i].second;
        }
        return result;
    }
};