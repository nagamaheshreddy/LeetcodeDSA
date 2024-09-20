class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer>s=new HashSet<Integer>();
        for(int num:nums){
            s.add(num);
        }
        return s.size()!=nums.length;
    }
}