//In two pass

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> arr1(10,0);
        vector<int> arr2(10,0);

        int bulls=0,cows=0;
   
        for(int i=0;i<secret.length();i++){
            int ele1=secret[i]-'0';
            int ele2=guess[i]-'0';

            arr1[ele1]++;
            arr2[ele2]++;

            if(ele1==ele2) bulls++; 
        }

        int cnt=0; //total matched character count
        for(int i=0;i<10;i++){
            cnt+=min(arr1[i],arr2[i]);
        }

        cows=cnt-bulls;

        return ""+(to_string(bulls))+'A'+(to_string(cows))+'B';

    }
};






//In One Pass--> fully optimised

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> arr1(10,0);
        int bulls=0,cows=0;
   
        for(int i=0;i<secret.length();i++){
            int ele1=secret[i]-'0';
            int ele2=guess[i]-'0';

            if(ele1==ele2) bulls++; 
            else {
                if(arr1[ele1]++<0) cows++;
                if(arr1[ele2]-->0) cows++;
            }
        }

        return ""+(to_string(bulls))+'A'+(to_string(cows))+'B';

    }
};