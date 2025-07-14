class Solution
{
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
    {
        assert(MIN_LENGTH <= players.size() && players.size() <= MAX_LENGTH);
        assert(MIN_LENGTH <= trainers.size() && trainers.size() <= MAX_LENGTH);

        ranges::sort(players);
        ranges::sort(trainers);

        const size_t playerCount = players.size();
        const size_t trainerCount = trainers.size();
        size_t playerIndex = 0;
        size_t trainerIndex = 0;
        size_t matchCount = 0;

        while (playerIndex < playerCount && trainerIndex < trainerCount)
        {
            assert(MIN_ABILITY <= players[playerIndex] && players[playerIndex] <= MAX_ABILITY);
            assert(MIN_ABILITY <= trainers[trainerIndex] && trainers[trainerIndex] <= MAX_ABILITY);
            if (players[playerIndex] <= trainers[trainerIndex])
            {
                ++matchCount;
                ++playerIndex;
                ++trainerIndex;
            }
            else
            {
                ++trainerIndex;
            }
        }

        return static_cast<int>(matchCount);
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_ABILITY = 1,
        MAX_ABILITY = 1000000000,
        INVALID_INDEX = -1
    };
};
// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/?envType=daily-question&envId=2025-07-13
