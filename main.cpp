class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            char currentLet = s[i];
            if(checkSubtraction(currentLet, s[i+1]) == 0){
                int num = convertToNum(currentLet);
                sum += num;
            }
            else{
                sum += checkSubtraction(currentLet, s[i+1]);
                i++;
            }

        }
        return sum;
    }

   int checkSubtraction( char first, char second){
        if(first == 'I'){
            if(second == 'V'){
                return 4;
            }
            if(second == 'X'){
                return 9;
            }
        }
        if(first == 'X'){
            if(second == 'L'){
                return 40;
            }
            if(second == 'C'){
                return 90;
            }
        }
        if(first == 'C'){
            if(second == 'D'){
                return 400;
            }
            if(second == 'M'){
                return 900;
            }
        }
        return 0;
    }

    int convertToNum(char let){
        int number[7] = {1, 5, 10, 50, 100, 500, 1000};
        char numeral[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int index = -1;
        for(int i = 0; i < 7; i++){
            if(let == numeral[i]){
                index = i;
            }
        }
        return number[index];
    }

};
