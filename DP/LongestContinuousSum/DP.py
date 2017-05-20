# Longest sum continus


def dp(A):
    max_so_far = 0
    max_ending_here = 0

    for i in range(len(A)):
        max_ending_here += A[i];

        if max_ending_here < 0:
            max_ending_here = 0;

        if max_ending_here > max_so_far:
            max_so_far = max_ending_here

    return max_so_far


A = [-2,-3,4,-1,-2,1,5,-3]
print(dp(A))