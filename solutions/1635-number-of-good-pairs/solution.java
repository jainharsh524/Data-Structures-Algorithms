class Solution {
    public int numIdenticalPairs(int[] nums) {
          Map<Integer, Integer> mp = new HashMap<>();
          // Traverse through array elements and
          // count frequencies
          for (int i = 0; i < nums.length; i++)
          {
              if (mp.containsKey(nums[i]))
              {
                  mp.put(nums[i], mp.get(nums[i]) + 1);
              }
              else
              {
                  mp.put(nums[i], 1);
              }
          }
          int identicalPairs = 0;
          for (Map.Entry<Integer, Integer> entry : mp.entrySet())
          {
              int n = entry.getValue();
              identicalPairs+= n*(n-1)/2;
          }
          return identicalPairs;
      }
}
