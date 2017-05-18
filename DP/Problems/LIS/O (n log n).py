class LIS:
    @staticmethod
    def ceil_index(tails, l, r, key):
        while r-l > 1:
            m = l + int((r-l)/2)

            if tails[m] >= key:
                r = m
            else:
                l = m
        return r


    @staticmethod
    def get_longest_lis(data):
        if len(data) == 0:
            return 0

        # least is 1
        length = 1

        tails = [data[0]]
        for i in range(1, len(data)):
            if data[i] < tails[0]:
                tails[0] = data[i]

            elif data[i] > tails[len(tails) -1]:
                tails.append(data[i])

            else:
                tails[LIS.ceil_index(tails,-1, len(tails)-1, data[i])] = data[i]

        return tails

data = [2,5,3,7,11,8,10,13,6]
print(LIS.get_longest_lis(data))