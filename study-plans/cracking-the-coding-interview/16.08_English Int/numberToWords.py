# 2023-09-08
class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"

        def trans_ones(num):
            return ('', 'One', 'Two', 'Three', 'Four', 'Five',
                    'Six', 'Seven', 'Eight', 'Nine', 'Ten',
                    'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen',
                    'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen')[num]

        def trans_tens(num):
            return (None, None, 'Twenty', 'Thirty', 'Forty',
                    'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety')[num // 10]

        def build_words(num):
            res = []
            if num // 100 > 0:
                res.append(trans_ones(num // 100) + ' Hundred')
            num %= 100
            if num < 20:
                res.append(trans_ones(num))
            else:
                res.append(trans_tens(num))
                res.append(trans_ones(num % 10))
            return ' '.join(res).strip()

        ans = ''
        for subfix in ('', 'Thousand', 'Million', 'Billion'):
            if num > 0:
                part = build_words(num % 1000)
                if part:
                    ans = ' '.join([part, subfix, ans])
            num //= 1000
        return ans.strip()
