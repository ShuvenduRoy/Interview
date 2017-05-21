class WB:
    @staticmethod
    def check(str):
        dictionary = ["mobile", "samsung", "sam", "sung", "man", "mango", "icecream", "and", "go", "i", "like", "ice", "cream"]

        n = len(str)
        if n==0:
            return True

        wb = [False] * (n+1)

        for i in range(1, n+1):
            if wb[i] == False and dictionary.__contains__()