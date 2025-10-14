public class Solution
{
    public IList<IList<int>> FindMatrix(int[] nums)
    {
        var ans = new List<IList<int>>();
        var freq = new Dictionary<int, int>();

        // Count frequency of each number
        foreach (var num in nums)
        {
            if (!freq.ContainsKey(num))
                freq[num] = 0;
            freq[num]++;
        }

        // Distribute numbers across rows
        foreach (var kvp in freq)
        {
            int value = kvp.Key;
            int count = kvp.Value;

            for (int i = 0; i < count; i++)
            {
                // If not enough rows yet, add a new one
                if (ans.Count < i + 1)
                    ans.Add(new List<int> { value });
                else
                    ans[i].Add(value);
            }
        }

        return ans;
    }
}
