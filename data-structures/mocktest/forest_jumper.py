def can_reach_last_stone(stones):
    max_reach = 0
    for i, jump in enumerate(stones):
        if i > max_reach:
            return False
        max_reach = max(max_reach, i + jump)
        if max_reach >= len(stones) - 1:
            return True
    return max_reach >= len(stones) - 1

# Test Cases
test_cases = [
    ([2, 3, 1, 1, 4], True),
    ([3, 2, 1, 0, 4], False),
    ([1, 0, 0, 0], False),
    ([2, 0, 0], True),
    ([0], True),
    ([1, 0, 0, 0], False),
    ([1, 2, 3], True),
    ([1, 0, 1, 0], False),
]

for i, (stones, expected) in enumerate(test_cases, 1):
    result = can_reach_last_stone(stones)
    print(f"Test Case {i}: {result} (Expected: {expected})")