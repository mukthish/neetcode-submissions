class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while (b) {
            carry = (a & b) << 1; // bitwise and gives carry for each bit (we shift it once to the left)
            a ^= b; // gives the bitwise sum without the carry
            b = carry; 
        }        
        return a;
    }
};
