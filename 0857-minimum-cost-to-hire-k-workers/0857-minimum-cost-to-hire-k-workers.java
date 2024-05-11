class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        List<Pair<Double, Integer>> ratio = new ArrayList<>();

        for(int i=0; i<wage.length; i++){
            ratio.add(new Pair<>(wage[i]*1.0/quality[i], quality[i]));
        }
        ratio.sort((a, b) -> Double.compare(a.getKey(), b.getKey()));
        //ratio.sort(Comparator.comparingDouble(p -> p.getKey()));

        int total_quality=0;
        double ans = Double.MAX_VALUE;
        for(int i=0; i<ratio.size(); i++){
            pq.offer(ratio.get(i).getValue());
            total_quality += ratio.get(i).getValue();

            if(pq.size() > k){
                total_quality -= pq.poll();
            }
            if(pq.size() == k){
                ans = Math.min(ans, total_quality * ratio.get(i).getKey());
            }
        }
        return ans;


    }
}