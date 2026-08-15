/* Understanding -> Given an array of size N; and a target -> find the minimum number of operations needed to make all elements of array equal to target -> there are multiple target in order of Q;*/

class Solution{
    public:
    int index(vector<int> &nums , int target){
        int n = nums.size();
        int low =0;
        int high = n-1;
        int lidx;
        int ridx;


        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                lidx = mid-1;
                ridx = mid+1;

            }
            else if(nums[mid]>target){
                if(nums[mid] >target && nums[i-1]<target){
                    lidx = mid-1;
                    ridx = mid;
                }   
                else{
                    high = mid-1;
                } 
            }
            else{
                if(nums[mid]<target && nums[i+1]>target){
                    lidx = mid;
                    ridx = mid+1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return lidx;
    }

    
    vector<int> solve(vector<int> &nums, vector<int> &target){
        //first step is to find left part and right part of array which is bigger and smaller than target

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int q = query.size();

        //prefix sum
        unordered_map<int, int> prefix;
        prefix[0] = nums[0];
        for(int i=1 i<n; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int lidx;
        int ridx;
        vector<int> ans;
        for(int i=0; i<q; i++){
            lidx = index(nums, query[i]);
            ridx = lidx+1;
            int nopr = (query[i]*n-prefix[lidx])+((prefix[n-1]-prefix[lidx])-query[i]*n);
            ans.push_back(nopr);



        }
        return ans;
        
    }
};
