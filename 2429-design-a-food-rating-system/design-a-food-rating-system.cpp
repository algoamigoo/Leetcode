class FoodRatings {
public:
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };

    map<string, set<pair<int,string>, cmp>> cuisineBest;
    map<string, pair<string,int>> foodtoC;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            cuisineBest[cuisines[i]].insert({ratings[i], foods[i]});
            foodtoC[foods[i]] = {cuisines[i], ratings[i]};
        }
    }

    void changeRating(string food, int newRating) {
        string thiscuisine = foodtoC[food].first;
        int oldRating = foodtoC[food].second;
        cuisineBest[thiscuisine].erase({oldRating, food});
        cuisineBest[thiscuisine].insert({newRating, food});
        foodtoC[food].second = newRating;
    }

    string highestRated(string cuisine) {
        return cuisineBest[cuisine].begin()->second;
    }
};
