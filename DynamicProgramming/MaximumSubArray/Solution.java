package MaximumSubArray;

/**
 * 
 * @author Shuvendu Roy Bikash
 * Source:: LeetCode 53. Maximum SubArray
 * complexity: O(n)
 * Status: accepted but there can be a better solution than O(n) with divide and conquer, i can't
 */

public class Solution {
	
	//Return the maximum subArray with maximum sum
	public int maxSubArray(int[] nums) {
        int sum=0; 
        int max=0; //will store answer return the max
        
        for(int i=0; i<nums.length; i++){
        	sum+=nums[i];
        	if(sum<0){
        		sum=0;
        	}else if(sum>max){
        		max=sum;
        	}
        }
        
        
        
        //check if all is negative. in this case it would return 0
        // but we will find the max of those
        if(max==0){
        	int maxi = Integer.MIN_VALUE;
        	for(int i=0; i<nums.length; i++){
        		if(nums[i]>maxi){
        			maxi=nums[i];
        		}
        	}
        	return maxi; //inside max that is negative
        } //end of if
        
        
        
        return max; //outside max
    }

	public static void main(String[] args) {
		Solution s = new Solution();
		int[] array = {-2,1,-3,4,-1,2,1,-5,4};
		//the contiguous sub array [4,−1,2,1] has the largest sum = 6
		System.out.println(s.maxSubArray(array));

	}

}
