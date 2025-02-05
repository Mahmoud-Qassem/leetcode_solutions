class Solution {
public:
    bool areAlmostEqual(string s1, string s2)
    {
        for(int i = 0, end = s1.length(), first, count = 0;
            i < end;
            i++)
        {
            if(s1[i] != s2[i])
            {
                count++;
                if(count == 1)
                {
                    first = i;
                }
                else
                {
                    char temp = s1[first];
                    s1[first] = s1[i];
                    s1[i] = temp;
                    break;
                }
            }
        }

        if(s1 == s2)
        {
            return true;
        }

        return false;
    }
};