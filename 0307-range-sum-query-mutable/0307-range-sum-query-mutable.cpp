class NumArray {
private:
    int n;
    vector <int> arr;
    vector <int> fenwick;

public:
    NumArray(vector<int>& nums)
    {
        n = nums.size();

        arr.resize(n+1, 0);

        for (int i = 1; i <= n; i ++) arr[i] = nums[i-1];

        fenwick.resize(n+1, 0);

        for (int i = 1; i <= n; i ++) indexUpdate(i, arr[i]);
    }

    void indexUpdate(int index, int val)
    {
        while (index <= n)
        {
            fenwick[index] += val;
            index += (index & -index);
        }
    }

    void update(int index, int val)
    {
        indexUpdate(index+1, val - arr[index+1]);

        arr[index+1] = val;
    }

    int prefix(int index)
    {
        int sum = 0;

        while (index > 0)
        {
            sum += fenwick[index];
            index -= (index & -index);
        }

        return sum;
    }
    
    int sumRange(int left, int right)
    {
        return (prefix(right+1) - prefix(left));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */