class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while(high >= mid){
            if(nums[mid] == 0){
                swap(nums[mid++],nums[low++]);
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[high--],nums[mid]);
            }
        }
    }
};
