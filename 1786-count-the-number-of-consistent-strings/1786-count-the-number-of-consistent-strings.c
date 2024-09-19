

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int flags[35] = {};
    for(int i = 0; allowed[i]!='\0';i++){
        flags[allowed[i]-'a'] = 1;
    }
    int passed = 0;
    for(int i=0;i<wordsSize;i++){
        int flag = 0;
        for(int j = 0; words[i][j]!='\0' ; j++){
            if(flags[words[i][j] - 'a'] != 1){
                flag = 1;
                break;
            }
        }
        if(flag == 1) continue;
        passed++;
    }
    return passed;
}