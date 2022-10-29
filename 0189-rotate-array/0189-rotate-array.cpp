class Solution {
private:
    void reverse(int li, int ri, vector<int>& nums){
        // int l1 = 0;
        // int ri = nums.size()-1;
        while(li<ri){
            int temp = nums[li];
            nums[li] = nums[ri];
            nums[ri] = temp;
            li++;
            ri--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        k = n-k;
        reverse(0, k-1, nums);
        reverse(k, n-1, nums);
        reverse(0,n-1, nums);
    }
};