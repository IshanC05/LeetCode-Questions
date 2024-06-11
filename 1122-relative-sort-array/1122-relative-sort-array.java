class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int i : arr2)
            map.put(i, 0);
        
        for(int i : arr1)
            if(map.containsKey(i))  map.put(i, map.get(i) + 1);
        
        int[] res = new int[arr1.length];
        int j = arr1.length - 1;
        
        for(int i : arr1)
            if(!map.containsKey(i))     res[j--] = i;
        
        Arrays.sort(res);
        
        j = 0;
        
        for(int i : arr2){
            while(map.containsKey(i)){
                res[j++] = i;
                map.put(i, map.get(i) - 1);
                
                if(map.get(i) == 0)     map.remove(i);
            }
        }
        
        return res;
    }
}