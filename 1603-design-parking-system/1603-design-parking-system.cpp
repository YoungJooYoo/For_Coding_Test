class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) 
    {
        count = {big, medium, small};
    }

    bool addCar(int carType) 
    {
        return count[carType - 1]-- > 0;
    }
private:
    vector<int> count;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */