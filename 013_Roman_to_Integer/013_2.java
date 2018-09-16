public class Test
{
    public static int roman(String s)
    {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        int total = 0;
        int prev = 0;
        for (int i = 0; i < s.length(); i++)
        {
            Integer curr = map.get(s.charAt(i));
            total = (i < s.length() - 1 && curr < map.get(s.charAt(i))) ? total - curr : total + curr;
        }
        return total;
    }

    public static void main(String[] args)
    {
        int num = roman("LVIII");
        System.out.println(num);
    }
}