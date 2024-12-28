class CustomStack 
{
public:
    CustomStack(const int maxSize)
    : mMaxSize(maxSize)
    , mTop(0)
    {
        mStack = new int[maxSize];
        memset(mStack, 0, sizeof(int) * maxSize); // 배열 초기화
    }

    ~CustomStack()
    {
        delete[] mStack;
    }

    void push(const int x) 
    {
        if (mTop == mMaxSize)
        {
            return;
        }

        mStack[mTop] = x;
        ++mTop;
    }

    int pop() 
    {
        if (mTop == 0)
        {
            return EMPTY;
        }

        return mStack[--mTop];
    }

    void increment(const int k, const int val) 
    {
        for (int i = 0; i < mMaxSize && i < k; ++i)
        {
            mStack[i] += val;
        }
    }

private:
    const int mMaxSize;
    int mTop;
    int* mStack;

    enum { EMPTY = -1 };
};

// https://leetcode.com/problems/design-a-stack-with-increment-operation/description/
