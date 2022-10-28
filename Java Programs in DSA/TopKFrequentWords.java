class Solution 
{
    public List<String> topKFrequent(String[] words, int k)
    {
        Map<String, Integer> hp = new HashMap<>();
        for(String s: words)
            hp.put(s, hp.getOrDefault(s, 0) + 1);
        Queue<Map.Entry<String, Integer>> pq = 
        new PriorityQueue<>((e1, e2) -> 
        {
            if(e1.getValue() == e2.getValue())
                return e2.getKey().compareTo(e1.getKey());
            return e1.getValue() - e2.getValue();
        });
        for(Map.Entry<String, Integer> e: hp.entrySet())
        {
            pq.add(e);
            if(pq.size() > k)
                pq.poll();
        }
        List<String> ans = new ArrayList<>();
        while(!pq.isEmpty())
            ans.add(pq.poll().getKey());
        Collections.reverse(ans);
        return ans;
    }
}
