class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum<1||sum>9*num) return "";
        int num_9s=sum/9,r=sum%9;
        string res="";
        res.append(num_9s,'9');num-=num_9s;
        if(r) res.append(1,'0'+r),num--;
        res.append(num,'0');
        return res;
    }
};