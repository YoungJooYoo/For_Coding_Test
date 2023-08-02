/* BOJ 14681 사분면 고르기 */
#include <iostream>
#define QUADRANT_1 (1)
#define QUADRANT_2 (2)
#define QUADRANT_3 (3)
#define QUADRANT_4 (4)

using namespace std;

int main(void)
{
    int x;
    int y;
    
    cin >> x >> y;
    
    if (x > 0 && y > 0) {
        cout << QUADRANT_1 << endl;
    }
    if (x < 0 && y > 0) {
        cout << QUADRANT_2 << endl;
    }
    if (x < 0 && y < 0) {
        cout << QUADRANT_3 << endl;
    }
    if (x > 0 && y < 0) {
        cout << QUADRANT_4 << endl;
    }
    
    return 0;
}
