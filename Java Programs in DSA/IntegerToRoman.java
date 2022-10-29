class Solution 
{
    public String intToRoman(int num) 
    {
        String thousand[] = {"", "M", "MM", "MMM"};
        String hundreds[] = {"", "C", "CC", "CCC", "CD", 
                             "D", "DC", "DCC", "DCCC", "CM"};
        String tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", 
                         "LXX", "LXXX", "XC"};
        String ones[] = {"", "I", "II", "III", "IV", "V", "VI",
                        "VII", "VIII", "IX"};
        return thousand[num/1000] + hundreds[(num%1000)/100] 
                + tens[(num%100)/10] + ones[num%10]; 
    }
}
