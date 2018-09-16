class Solution{
    public int romanToInt(String s) {
        int total = 0;
        char prev = 'A';
        for (char c : s.toCharArray()) {
            switch(c) {
                case 'M': total += prev == 'C' ? 800 : 1000;
                          break;
                case 'D': total += prev == 'C' ? 300 : 500;
                          break;
                case 'C': total += prev == 'X' ? 80 : 100;
                          break;
                case 'L': total += prev == 'X' ? 30 : 50;
                          break;
                case 'X': total += prev == 'I' ? 8 : 10;
                          break;
                case 'V': total += prev == 'I' ? 3 : 5;
                          break;
                case 'I': total += 1;
            }
            prev = c;
        }
        return total;
    }
}