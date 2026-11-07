class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        if(start == goal){
            return 0;
        }
        else{
            start = start ^ goal;
            while( start > 1){
                if(start & 1){
                    cnt += 1;
                }
                start = start >> 1;
            }
            if(start == 1){
                cnt +=1;
            }

        }
        return cnt;
    }
};