class Solution {
    struct Kelas{
        int pass;
        int total;
        Kelas(int pass, int total): pass(pass), total(total){}
    };
    class Compare {
    public:
        bool operator()(Kelas a, Kelas b){
            return (double)(a.pass + 1) / (a.total + 1) - (double)a.pass / a.total < 
            (double)(b.pass + 1) / (b.total + 1) - (double)b.pass / b.total;
        }
    };
public:
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Kelas, vector<Kelas>, Compare> deficits; 
        for(auto kelas: classes){
            if(kelas[0] < kelas[1]){
                deficits.push(Kelas(kelas[0], kelas[1]));
            }
        }
        double result = 0;
        if(deficits.empty()) return 1 - result;
        for(int i = 0 ; i < extraStudents ; i++){
            if(deficits.empty()) break;
            Kelas kelas = deficits.top();
            deficits.pop();
            deficits.push(Kelas(kelas.pass+1, kelas.total+1));
        }
        while(!deficits.empty()){
            Kelas kelas = deficits.top();
            result += (1 - (double)kelas.pass / kelas.total);
            deficits.pop();
        }
        
        return 1 - result / classes.size();
    }
};