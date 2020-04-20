int romanToInt(char * s){
    int map[26] = {0};
    map['I' - 'A'] = 1;
    map['V' - 'A'] = 5;
    map['X' - 'A'] = 10;
    map['L' - 'A'] = 50;
    map['C' - 'A'] = 100;
    map['D' - 'A'] = 500;
    map['M' - 'A'] = 1000;
    int prev = 0, res = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (prev < map[s[i] - 'A'])
            res -= (prev * 2);
        res += (prev = map[s[i] - 'A']);
    }
    return res;
}