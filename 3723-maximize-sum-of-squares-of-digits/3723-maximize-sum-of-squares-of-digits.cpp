class Solution {
public:
    inline static int freq[10];
    string maxSumOfSquares(int num, int sum) {
        int cumm_num_of_ds=0;
        for(int d=9;d>0;d--){
            int num_of_d=(sum/d);
            cumm_num_of_ds+=num_of_d;
            if(cumm_num_of_ds>num) return "";
            freq[d]=num_of_d;
            sum=sum%d;
        }
        if(cumm_num_of_ds>num) return "";
        freq[0]=num-cumm_num_of_ds;
        string res="";
        for(int d=9;d>=0;d--){
            while(freq[d]--) res+=static_cast<char>((d+'0'));
        }
        return res;
    }
};