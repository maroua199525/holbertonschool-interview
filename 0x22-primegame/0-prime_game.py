#!/usr/bin/python3
""" a module that contain a function that check who is the user"""

is_prime = __import__('prime').isPrime


def isWinner(x, nums):
    """ prime game """
    if x < 1 or not nums or nums == []:
        return None
    x = min(x, len(nums))
    Maria = 0
    Ben = 0
    count = 0
    for i in range(x):
        if nums[i] < 2:
            Ben += 1
        elif nums[i] == 2:
            Maria += 1
        else:
            count = True
            exist = 1
            n = list(range(2, nums[i] + 1))
            while (exist):
                exist = 0
                for i in n:
                    if (is_prime(i)):
                        exist = 1
                        count = not count
                        n = list(filter(lambda x: x % i != 0, n))
            if (count):
                Ben += 1
            else:
                Maria += 1

    if Maria > Ben:
        return 'Maria'
    elif Ben > Maria:
        return 'Ben'
    return None
