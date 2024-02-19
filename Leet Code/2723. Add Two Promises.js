/**
 * 두 프로미스의 결과를 합산하여 반환하는 함수
 * @param {Promise} promise1 첫 번째 프로미스
 * @param {Promise} promise2 두 번째 프로미스
 * @return {Promise} 두 프로미스의 합을 해결하는 새로운 프로미스
 */
var addTwoPromises = async function(promise1, promise2) {
    try {
        // 두 프로미스가 해결될 때까지 기다립니다.
        const value1 = await promise1;
        const value2 = await promise2;

        // 두 값의 합을 반환하는 프로미스를 해결합니다.
        return value1 + value2;
    } catch (error) {
        // 오류 처리: 필요한 경우 여기서 오류를 처리할 수 있습니다.
        throw error; // 혹은 적절한 오류 처리 로직
    }
};

// 예제 사용법
addTwoPromises(Promise.resolve(2), Promise.resolve(2))
  .then(console.log); // 출력: 4

// https://leetcode.com/problems/add-two-promises/description/
