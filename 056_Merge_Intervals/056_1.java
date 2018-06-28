public class Interval
{
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
}

class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals.size() <= 1)
            return intervals;

        intervals.sort((i1, i2) -> Integer.compare(i1.start, i2.start));
        List<Interval> ans = new ArrayList<>();
        Interval init = intervals.get(0);
        for (Interval array : intervals)
        {
            if (init.end < array.start)
            {
                ans.add(init);
                init = array;
            }
            else
            { init.end = Math.max(init.end, array.end); }
        }
        ans.add(init);
        return ans;
    }
}