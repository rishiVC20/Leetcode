class Solution {
public:
    string belowTen[10]={" ","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    string belowTwenty[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string belowHundred[10]={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

    string numberToWords(int num) {
        if (num==0)
            return "Zero";
        if (num<10){
            return belowTen[num];
        }
        if (num<20){
            return belowTwenty[num-10];
        }
        if (num<100){
            return belowHundred[num/10]  + (num%10==0?"":+ " "+numberToWords(num%10));
        }
        if (num<1000){
            return belowTen[num/100]+" "+"Hundred" +(num%100==0?"":" "+numberToWords(num%100));
        }
        // if (num<10000){
        //     return belowTen[num/1000]+" "+"Thousand"+" "+(num%1000==0?"":numberToWords(num%1000));
        // }
        // if (num<100000){
        //     int p=num/1000;
        //     cout<<p<<' ';
        //     cout<<num%10000;
        //     return (num/10000==1?belowTwenty[p%10]:(belowHundred[num/10000]+" "+belowTen[p%10]))+" "+"Thousand"+" "+numberToWords(num%1000);
        // }
        if (num<1000000){
            // return belowTen[num/100000]+" "+"Hundred"+" "+numberToWords(num%100000);
            return numberToWords(num/1000)+" "+"Thousand"+(num%1000==0?"":" "+numberToWords(num%1000));
        }
        if (num<1000000000){
            // return belowTen[num/1000000]+ " "+"Million"+" "+numberToWords(num%1000000);
            return numberToWords(num/1000000)+" "+"Million"+(num%1000000==0?"":" "+numberToWords(num%1000000));
        }
        // if (num<100000000){
        //     int p=num/1000000;
        //     return belowTwenty[p%10]+ " "+"Million"+" "+numberToWords(num%10000000);
        // }
        //  if (num<1000000000){
        //     int p=num/1000000;
        //     return belowTwenty[p%10]+ " "+"Million"+" "+numberToWords(num%100000000);
        // }
        // if (num<1000000000){
        //     return belowTen[num/1000000]+ " "+"Billion"+" "+numberToWords(num%1000000000);
        // }

        return numberToWords(num/1000000000)+" "+"Billion"+(num%1000000000==0?"":" "+numberToWords(num%1000000000));

        return " ";
    }
};