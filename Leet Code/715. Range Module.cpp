class RangeModule {
public:
    RangeModule() {}

    // 구간 [left, right)를 추가합니다.
    void addRange(const int left, const int right) 
    {
        auto it = ranges.upper_bound(left); // left보다 큰 첫 번째 구간을 찾습니다.
        int newRight = right;
        // left와 right 사이에 시작하는 모든 구간을 삭제하고, newRight를 병합된 구간의 끝으로 업데이트합니다.
        while (it != ranges.end() && it->first <= newRight) {
            newRight = max(it->second, newRight);
            it = ranges.erase(it); // 겹치는 구간을 삭제합니다.
        }
        // 이전 구간에 추가할 수 있다면 추가합니다.
        if (it != ranges.begin() && left <= prev(it)->second) {
            prev(it)->second = max(prev(it)->second, newRight);
        } else {
            // 그렇지 않다면 새로운 구간을 추가합니다.
            ranges[left] = newRight;
        }
    }
    
    // 구간 [left, right)가 모두 추적되고 있는지 확인합니다.
    bool queryRange(const int left, const int right) 
    {
        auto it = ranges.upper_bound(left); // left보다 큰 첫 번째 구간을 찾습니다.
        if (it == ranges.begin()) return false; // 첫 번째 구간이라면 false를 반환합니다.
        // 이전 구간의 끝이 right보다 크거나 같다면 true를 반환합니다.
        return prev(it)->second >= right ? true : false;
    }
    
    // 구간 [left, right)의 추적을 중지합니다.
    void removeRange(const int left, const int right) 
    {
        auto it = ranges.lower_bound(left); // left보다 크거나 같은 첫 번째 구간을 찾습니다.
        int cutEnd = -1;
        // right보다 작은 시작점을 가진 모든 구간을 삭제합니다.
        while (it != ranges.end() && it->first < right) {
            cutEnd = max(cutEnd, it->second); // 삭제된 구간의 끝을 기록합니다.
            it = ranges.erase(it); // 겹치는 구간을 삭제합니다.
        }
        // 현재 구간이 이전 구간과 겹친다면, 이전 구간을 업데이트합니다.
        if (it != ranges.begin() && left < prev(it)->second) {
            cutEnd = max(cutEnd, prev(it)->second);
            prev(it)->second = left;
        }
        // 삭제 과정에서 끝이 잘린 구간을 다시 추가합니다.
        if (right < cutEnd) {
            ranges[right] = cutEnd;
        }
    }

private:
    map<int, int> ranges; // 구간을 추적하기 위한 맵
};

// https://leetcode.com/problems/range-module/description/

/*
### 한국어 번역

숫자 범위를 추적하는 모듈인 Range Module을 설계하세요. 반개구간(half-open intervals)으로 표현된 범위를 추적하고 이에 대해 질의하는 데이터 구조를 설계합니다.

반개구간 `[left, right)`은 left <= x < right인 모든 실수 x를 나타냅니다.

RangeModule 클래스를 구현하세요:

- `RangeModule()` 데이터 구조의 객체를 초기화합니다.
- `void addRange(int left, int right)` 반개구간 `[left, right)`을 추가하여, 그 구간에 있는 모든 실수를 추적합니다. 현재 추적 중인 숫자와 부분적으로 겹치는 구간을 추가할 경우, `[left, right)` 구간에 있는 아직 추적되지 않은 모든 숫자를 추적해야 합니다.
- `boolean queryRange(int left, int right)` 구간 `[left, right)`에 있는 모든 실수가 현재 추적되고 있다면 `true`를 반환하고, 그렇지 않다면 `false`를 반환합니다.
- `void removeRange(int left, int right)` 반개구간 `[left, right)`에 현재 추적 중인 모든 실수의 추적을 중단합니다.

### 요약

Range Module은 주어진 숫자 범위를 추적하는 데이터 구조입니다. 이 구조는 반개구간을 사용하여 범위를 추가, 질의, 제거하는 기능을 제공합니다. 주어진 구간에 대해 모든 숫자가 추적되고 있는지 여부를 확인하고, 특정 구간의 숫자 추적을 시작하거나 중단할 수 있습니다.

### 문제 풀이 방향

이 문제를 해결하기 위해서는 효율적인 구간 관리 방법이 필요합니다. 일반적인 접근 방법은 다음과 같습니다:

1. **데이터 구조 선택**: 구간을 효율적으로 관리하기 위해, 균형 이진 검색 트리(Balanced Binary Search Tree) 같은 데이터 구조를 사용할 수 있습니다. 예를 들어, C++의 `std::set`이나 `std::map`을 사용하여 구간의 시작점과 끝점을 관리할 수 있습니다.

2. **구간 추가**: 새로운 구간을 추가할 때는, 기존에 추적 중인 구간과의 겹침을 확인하고, 필요한 경우 구간을 병합합니다.

3. **구간 제거**: 구간을 제거할 때는, 해당 구간과 겹치는 모든 추적 중인 구간을 찾아, 겹치지 않는 부분만 남기고 나머지는 제거합니다.

4. **구간 질의**: 특정 구간이 완전히 추적되고 있는지 확인할 때는, 질의 구간을 완전히 포함하는 추적 중인 구간이 있는지 확인합니다. 구간의 일부만 추적되고 있다면 `false`를 반환합니다.

이러한 기능을 구현하기 위해서는 구간의 추가, 제거, 질의에 대해 세심한 로직이 필요하며, 구간이 서로 겹치는 경우의 처리가 핵심적인 도전 과제입니다.
*/
