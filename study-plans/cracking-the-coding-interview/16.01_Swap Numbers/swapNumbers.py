# 2023-09-12 用XOR交换和
class Solution:
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        numbers[0] = numbers[0] ^ numbers[1]
        numbers[1] = numbers[0] ^ numbers[1]
        numbers[0] = numbers[0] ^ numbers[1]
        return numbers