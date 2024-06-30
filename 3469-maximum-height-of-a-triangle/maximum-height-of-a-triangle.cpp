class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int p1 = red;
        int p2 = blue;
        int sum = 0;
        int i=1, j=2;
        bool f = false;
        while (1){
            if (p1>=i && !f){
                p1 -= i;
                i+=2;
                sum++;
                f = !f;
            }
            else{
                break;
            }
            if (p2>=j && f){
                p2 -= j;
                j+=2;
                sum++;
                f = !f;
            }
            else{
                break;
            }
            // if (p1<i && p2<j)
            //     break;
        }
        cout<<sum<<' ';
        int ans = 0;
        p1 = blue;
        p2 = red;
        i=1, j=2;
        f = false;
        while (1){
            if (p1>=i && !f){
                p1 -= i;
                i+=2;
                ans++;
                f = !f;
            }
            else{
                break;
            }
            if (p2>=j && f){
                p2 -= j;
                j+=2;
                ans++;
                f = !f;
            }
            else{
                break;
            }
            // if (p1<i && p2<j)
            //     break;
        }

        return max(ans,sum);
    }
};