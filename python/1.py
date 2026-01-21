s = "aaabbbccdddde"

class Solution:
    def majorityFrequencyGroup(self, s: str) -> str:
        counts = {}
        counts = {c: s.count(c) for c in s if c not in counts}
        counts = {k: v for k, v in counts.items() if v > 0}

        frequency_group = {}

        for c, count in counts.items():
            if count not in frequency_group:
                frequency_group[count] = [c]
            frequency_group[count] += c

        k_group_size = {}
        for count, group in frequency_group.items():
            k_group_size[count]  = len(group)

        selected_groups = {}
        for k, group_size in k_group_size.items():
            if group_size not in selected_groups:
                selected_groups[group_size] = k
            if k > selected_groups[group_size]:
                selected_groups[group_size] = k 

        majority_freq_group = 0
        majority_freq_group_k = 0
        for group_size, k in selected_groups.items():
            if group_size > majority_freq_group :
                majority_freq_group = group_size
                majority_freq_group_k = k
            elif group_size == majority_freq_group:
                if k > majority_freq_group_k:
                    majority_freq_group_k = k

        return selected_groups[majority_freq_group_k]


sol = Solution()
print(sol.majorityFrequencyGroup(s))