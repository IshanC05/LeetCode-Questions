class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int l = 0, r = people.length - 1;
        int res = 0;
        Arrays.sort(people);
        
        while(l <= r){
            int wt = people[l] + people[r];
            if(wt <= limit){
                ++l;
            }
            --r;
            ++res;
        }
        
        return res;
    }
}