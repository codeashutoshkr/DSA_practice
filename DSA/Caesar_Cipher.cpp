/*In the ROT-K cipher, each character in the string is shifted a fixed number of positions down the alphabet. The value of K represents the number of positions to shift.
 For instance, in ROT-2, each character is shifted 2 positions. The ROT-2 cipher of the string code is eqfg.
Note that the rotation is performed in a circular manner, meaning that if the character z is shifted by one position,
 we obtain the character a.
You are given strings S,T,and U, each of length N, such that the ROT-K cipher of string S is string T.
Find the ROT-K cipher of string U. */

#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int Q;
    cin >> Q;
    while (Q--) {
        int N, K;
        cin >> N;
        string S, T, U;
        cin >> S >> T >> U;
        K = (T[0] - S[0] + 26) % 26; /*calculate the rotation difference and 26 is added to get positive value and %26 ensures that the ASCII value is under the bound of alphabet*/
        string Result = "";
        for (char C: U) {
            char shifted_Char = (C - 'a' + K) % 26 + 'a';
            /* C - 'a'  Converts the character C into its 0-based position in the alphabet (e.g., 'a' → 0, 'b' → 1 and so on and + K will shift and %26 will handle circular rotation
                           and again + 'a' will convert the shifted position into character*/

            Result += shifted_Char;
        }
        cout << Result << endl;
    }

}