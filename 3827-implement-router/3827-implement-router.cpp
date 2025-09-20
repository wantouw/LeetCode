class Router {
public:

    struct Data{
        int source;
        int destination;
        int timestamp;
        bool operator==(const Data& other) const {
            return source == other.source && destination == other.destination && timestamp == other.timestamp;
        }
        Data(int source, int destination, int timestamp): source(source), destination(destination), timestamp(timestamp){}
    };

    struct DataHash {
        std::size_t operator()(const Data& d) const noexcept {
            std::size_t h1 = std::hash<int>{}(d.source);
            std::size_t h2 = std::hash<int>{}(d.destination);
            std::size_t h3 = std::hash<int>{}(d.timestamp);
            return h1 ^ (h2 << 1) ^ (h3 << 2); 
        }
    };

    unordered_map<int, vector<Data>> destinationVectors;
    unordered_map<int, int> lefts;
    unordered_map<int, int> rights;
    unordered_set<Data, DataHash> dataSet;
    queue<Data> dataQueue;
    int left, right;
    int size;

    Router(int memoryLimit) {
        size = memoryLimit;
        left = right = 0;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Data newPacket = Data(source, destination, timestamp);
        if(dataSet.find(newPacket) == dataSet.end()){
            // cout << "hai" << endl;
            dataSet.insert(newPacket);
            dataQueue.push(newPacket);
            destinationVectors[destination].push_back(newPacket);
            if(dataQueue.size() > size){
                Data pushed = dataQueue.front();
                dataSet.erase(pushed);
                dataQueue.pop();
                lefts[pushed.destination]++;
            }
            rights[destination]++;
            return true;
        }
        return false;
    }
    
    vector<int> forwardPacket() {
        if(dataQueue.empty()){
            return vector<int>{};
        }
        Data pushed = dataQueue.front();
        dataSet.erase(pushed);
        dataQueue.pop();
        lefts[pushed.destination]++;
        return vector<int> {pushed.source, pushed.destination, pushed.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(dataQueue.empty()) return 0;
        int low = lefts[destination], high = rights[destination] - 1;
        if(lefts[destination] == rights[destination]) return 0;
        while(low < high){
            int mid = (low + high) / 2;
            if(destinationVectors[destination][mid].timestamp < startTime){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        low = max(lefts[destination], low);
        int leftLimit = destinationVectors[destination][low].timestamp < startTime ? low + 1 : low;

        low = lefts[destination];
        high = rights[destination] - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(destinationVectors[destination][mid].timestamp <= endTime){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        high = max(0, high);
        int rightLimit = (high >= rights[destination]) ? high-1 : high;
        if(rightLimit == leftLimit && !(destinationVectors[destination][rightLimit].timestamp <= endTime && destinationVectors[destination][rightLimit].timestamp >= startTime)){
            return 0;
        }
        return rightLimit - leftLimit + 1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */