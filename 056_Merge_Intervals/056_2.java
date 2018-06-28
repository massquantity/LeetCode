class Solution {
    public List<Interval> merge(List<Interval> intervals) {
         Collections.sort(intervals, new Comparator<Interval>()
        {
            @Override
            public int compare(Interval a, Interval b)
            { return a.start - b.start; }
        });

        List<Interval> res = new ArrayList<Interval>();
        Interval init = null;
        for (Interval array : intervals)
        {
            if (init == null || init.end < array.start)
            {
                res.add(array);
                init = array;
            }
            else init.end = Math.max(init.end, array.end);
        }
        return res;
    }
}