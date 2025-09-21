class MovieRentingSystem {
public:

    unordered_map<int, set<pair<int, int>>> unrentedMovies;
    unordered_map<int, unordered_map<int, int>> prices;
    set<tuple<int, int, int>> rentedMovies;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i = 0 ; i < entries.size() ;  i++){
            int shop = entries[i][0], movie = entries[i][1], price = entries[i][2];
            prices[shop][movie] = price;
            unrentedMovies[movie].insert({price, shop});
        }    
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;
        for(auto [price, shop]: unrentedMovies[movie]){
            result.push_back(shop);
            count++;
            if(count == 5) break;
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = prices[shop][movie];
        rentedMovies.insert({price, shop, movie});
        unrentedMovies[movie].erase({price, shop});
    }
    
    void drop(int shop, int movie) {
        int price = prices[shop][movie];
        rentedMovies.erase({price, shop, movie});
        unrentedMovies[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for(auto [price, shop, movie]: rentedMovies){
            result.push_back(vector<int>{shop, movie});
            count++;
            if(count == 5) break;
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */