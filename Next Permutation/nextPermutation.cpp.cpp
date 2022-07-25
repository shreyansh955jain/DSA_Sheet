class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     int n=nums.size();
     int break_point; 
     bool flag = false; 
     for(int i=n-2;i>=0;i--){
         if(nums[i]<nums[i+1]){
             flag = true;
             break_point=i;
             //cout<<break_point<<endl;
             for(int j=n-1;j>=0;j--){
                 if(nums[j]>nums[break_point]){
                     cout<<" "<<j<<endl;
                     swap(nums[j],nums[break_point]);
                     int x=break_point+1;
                     int y=n-1;
                     while(x<=y){
                         swap(nums[x],nums[y]);
                         x++;
                         y--;
                     }
                     return;
                 }
             }
         }
     }
        if(!flag) reverse(nums.begin(),nums.end());
    }
};