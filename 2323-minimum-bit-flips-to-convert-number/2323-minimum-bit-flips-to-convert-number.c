int minBitFlips(int start, int goal) {
    int count = 0;
    int divider = 1;
    while(start > 0 || goal > 0){
        // printf("start & 1: %d, start: %d\n", start & divider, start);
        // printf("goal & 1: %d, goal: %d\n", goal & divider, goal);
        // printf("%d %d\n", start & divider, goal & divider);
        if((start & divider) != (goal & divider)){
            count++;
        }
        
        
        start = start >> 1;
        goal = goal >> 1;
    }
    return count;
}