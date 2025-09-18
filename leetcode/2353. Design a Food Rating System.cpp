class FoodRatings
{
public:
    FoodRatings(const vector<string>& foods, const vector<string>& cuisines, const vector<int>& ratings)
    {
        assert(foods.size() == cuisines.size() && foods.size() == ratings.size());
        assert(MIN_LENGTH <= foods.size() && foods.size() <= MAX_LENGTH);

        const size_t n = foods.size();
        for (size_t i = 0; i < n; ++i)
        {
            const string& food = foods[i];
            const string& cuisine = cuisines[i];
            const int rating = ratings[i];

            mFoodInfo.emplace(food, FoodInfo{cuisine, rating});
            mCuisineBuckets[cuisine].insert(Node{food, rating});
        }
    }

    void changeRating(const string& food, const int newRating)
    {
        const auto itFood = mFoodInfo.find(food);
        assert(itFood != mFoodInfo.end());
        const string& cuisine = itFood->second.cuisine;
        const int oldRating = itFood->second.rating;
        auto& bucket = mCuisineBuckets[cuisine]; // 기존 노드를 해당 cuisine 버킷에서 제거
        const Node oldNode{food, oldRating};
        const auto itNode = bucket.find(oldNode);
        if (itNode != bucket.end())
        {
            bucket.erase(itNode);
        }

        itFood->second.rating = newRating;
        bucket.insert(Node{food, newRating});
    }

    string highestRated(const string& cuisine) const
    {
        const auto it = mCuisineBuckets.find(cuisine);
        assert(it != mCuisineBuckets.end());
        const auto& bucket = it->second;
        assert(!bucket.empty());
        
        return bucket.begin()->food; // set의 첫 원소가 (rating 내림차순, food 오름차순) 기준 최상위
    }

private:
    struct FoodInfo
    {
        string cuisine;
        int rating;
    };

    struct Node
    {
        string food;
        int rating;
    };

    struct NodeCmp
    {
        bool operator()(const Node& a, const Node& b) const
        {
            if (a.rating != b.rating)
            {
                return a.rating > b.rating; // 높은 평점 우선
            }
            return a.food < b.food;        // 평점 동률이면 사전식 앞서는 이름
        }
    };

    unordered_map<string, FoodInfo> mFoodInfo; // food → (cuisine, rating)
    unordered_map<string, set<Node, NodeCmp>> mCuisineBuckets; // cuisine → 정렬된 음식 집합

    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 2 * 10000,
        MIN_ELEMENT_LENGTH = 1,
        MAX_ELEMENT_LENGTH = 10,
        MIN_RAITINGS_LENGTH = 1,
        MAX_RAITING_LENGTH = 100000000
    };
};

// https://leetcode.com/problems/design-a-food-rating-system/description/?envType=daily-question&envId=2025-09-17
