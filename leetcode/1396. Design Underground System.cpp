class UndergroundSystem 
{
public:
    UndergroundSystem() {}

    void checkIn(const int id, const string& stationName, const int t) 
    {
        assert(MIN_ID <= id && id <= MAX_ID);
        assert(MIN_TIME <= t && t <= MAX_TIME);
        assert(MIN_STATION_NAME_LENGTH <= stationName.length() && stationName.length() <= MAX_STATION_NAME_LENGTH);

        const customerInfo_t info{id, stationName, t};
        mActiveCheckIn[id] = info;
    }

    void checkOut(const int id, const string& stationName, const int t) 
    {
        assert(MIN_ID <= id && id <= MAX_ID);
        assert(MIN_TIME <= t && t <= MAX_TIME);
        assert(MIN_STATION_NAME_LENGTH <= stationName.length() && stationName.length() <= MAX_STATION_NAME_LENGTH);
        assert(mActiveCheckIn.find(id) != mActiveCheckIn.end());

        const customerInfo_t& checkInInfo = mActiveCheckIn[id];
        const int travelTime = t - checkInInfo.time;
        const string route = buildRouteKey(checkInInfo.stationName, stationName);

        routeStat_t& stat = mRouteStats[route];
        stat.totalTime += travelTime;
        stat.tripCount += 1;
        mActiveCheckIn.erase(id);
    }

    double getAverageTime(const string& startStation, const string& endStation) const
    {
        assert(MIN_STATION_NAME_LENGTH <= startStation.length() && startStation.length() <= MAX_STATION_NAME_LENGTH);
        assert(MIN_STATION_NAME_LENGTH <= endStation.length() && endStation.length() <= MAX_STATION_NAME_LENGTH);

        const string route = buildRouteKey(startStation, endStation);
        const routeStat_t& stat = mRouteStats.at(route);

        assert(mRouteStats.find(route) != mRouteStats.end());
        assert(stat.tripCount > 0);
        return static_cast<double>(stat.totalTime) / static_cast<double>(stat.tripCount);
    }

private:
    typedef struct customerInfo
    {
        int id;
        string stationName;
        int time;
    } customerInfo_t;

    typedef struct routeStat
    {
        long long totalTime = 0;
        int tripCount = 0;
    } routeStat_t;

private:
    string buildRouteKey(const string& startStation, const string& endStation) const
    {
        return startStation + ROUTE_SEPARATOR + endStation;
    }

private:
    unordered_map<int, customerInfo_t> mActiveCheckIn;
    unordered_map<string, routeStat_t> mRouteStats;

private:
    enum
    {
        MIN_ID = 1,
        MAX_ID = 1000000,
        MIN_TIME = 1,
        MAX_TIME = 1000000,
        MIN_STATION_NAME_LENGTH = 1,
        MAX_STATION_NAME_LENGTH = 10,
        MAX_TOTAL_CALLS = 20000
    };

    static constexpr char ROUTE_SEPARATOR = '#';
};


/**
https://leetcode.com/problems/design-underground-system/
1396. 지하철 시스템 설계 (Design Underground System)
문제 설명
지하철 철도 시스템은 고객의 이동 시간을 기록하여, 한 역에서 다른 역으로 이동하는 데 걸리는 평균 시간을 계산합니다.

UndergroundSystem 클래스를 구현하세요:

void checkIn(int id, string stationName, int t): 카드 ID가 id인 고객이 역 이름 stationName에서 시간 t에 체크인합니다.
(고객은 한 번에 하나의 역에만 체크인할 수 있습니다.)
void checkOut(int id, string stationName, int t): 카드 ID가 id인 고객이 역 이름 stationName에서 시간 t에 체크아웃합니다.
double getAverageTime(string startStation, string endStation): startStation에서 endStation으로 이동한 모든 고객의 평균 이동 시간을 반환합니다.
(이동 시간은 startStation에서 체크인하고 endStation에서 체크아웃한 경우만 포함됩니다.
startStation → endStation의 이동 시간은 endStation → startStation과 다를 수 있습니다.
getAverageTime 호출 시, 최소 한 번 이상 startStation → endStation으로 이동한 기록이 있습니다.)
제약 사항:

1 <= id, t <= 10^6
1 <= stationName.length, startStation.length, endStation.length <= 10
모든 문자열은 대문자/소문자 영어 알파벳과 숫자로만 구성됩니다.
총 checkIn, checkOut, getAverageTime 호출 횟수는 2 * 10^4를 초과하지 않습니다.
checkIn과 checkOut 호출은 일관적입니다. (체크인 시간 t1 < 체크아웃 시간 t2)
예시 1:

입력:
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]
출력: [null, null, null, null, null, null, null, 14.00000, 11.00000, null, 11.00000, null, 12.00000]
설명:
고객 45: "Leyton" → "Waterloo" (15-3=12분)
고객 27: "Leyton" → "Waterloo" (20-10=10분)
고객 32: "Paradise" → "Cambridge" (22-8=14분)
getAverageTime("Paradise", "Cambridge") → 14.0
getAverageTime("Leyton", "Waterloo") → (10+12)/2 = 11.0
고객 10 추가: "Leyton" → "Waterloo" (38-24=14분)
최종 평균: (10+12+14)/3 = 12.0

 */
