package com.company;

public class Move_last {

    public static void move_at_end(String str, int index, int count, String newstr)
    {
        if (index == str.length()-1)
        {
            for(int i=0; i<count; i++)
            {
                newstr += 'x';

            }
            System.out.println(newstr);
            return;
        }
        char curchar = str.charAt(index);
        if (curchar == 'x')
        {
            count++;
            move_at_end(str, index+1, count, newstr);
        }
        else
        {
            newstr += curchar;
            move_at_end(str, index+1, count, newstr);
        }
    }
    public static void main(String[] args) {
        // write your code here
        move_at_end("abxcxdfxtexgtxhy", 0, 0, "");
    }
}

//output will be - abcdftegthxxxxx

