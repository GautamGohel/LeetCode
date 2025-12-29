class Solution {
  Map<String, List<Character>> mp;
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        mp = new HashMap<>();
        for ( String f: allowed)
        {
          String key= f.substring(0,2);
          if( !mp.containsKey(key))
          mp.put( key, new ArrayList<>());
          mp.get(key).add(f.charAt(2));
        }
        return fn(bottom, 0, "" ); // dfs
    }
    public boolean fn( String s, int idx, String curr)
    {
      if(s.length()==1) return true;
      int n= s.length();
      if( idx==n-1)
      return fn( curr, 0, "");

      String key= ""+s.charAt(idx)+s.charAt(idx+1);
      if( !mp.containsKey(key)) return false;
      boolean f= false;
      for(char ch: mp.get(key))
      {
        f|= fn(s, idx+1, curr+ch);
        if( f) return true;
      }
      return f;
    }
}