class LCS:
    @staticmethod
    def len(str1, str2):
        m = len(str1)
        n = len(str2)
        result = 0

        T = [[0 for i in range (n + 1)] for j in range(m + 1)]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if str1[i-1] == str2[j-1]:
                    T[i][j] = T[i-1][j-1] + 1
                    result = max(result, T[i][j])
                else:
                    T[i][j] = 0

        return result

str1 = "Site:GeeksforGeeks.org";
str2 = "Site:GeeksQuiz.com";

print(LCS.len(str1,str2))