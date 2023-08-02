class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) 
    {
        size_big = big;
        size_medium = medium;
        size_small = small;
    }
    
    bool addCar(int carType) 
    {
        switch (carType)  {
            case BIG:
                if (size_big == 0) {
                    return false;
                }
                else 
                    --size_big;
                break;
            case MEDIUM:
                if (size_medium == 0) {
                    return false;
                }
                else 
                    --size_medium;
                break;
            case SMALL:
                if (size_small == 0) {
                    return false;
                }
                else 
                    --size_small;
                break;
            default:
                assert(true);
        }

        return true;
    }

private:
    int size_big;
    int size_medium;
    int size_small;

    enum {
        BIG = 1,
        MEDIUM = 2,
        SMALL = 3
    };
};

https://leetcode.com/problems/design-parking-system/description/
