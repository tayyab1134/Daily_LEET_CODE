class Solution {
public:
    int nextGreaterElement(int n) {
            
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    
    int size = digits.size();
    int i = size - 2;
    while (i >= 0 && digits[i] >= digits[i + 1]) {
        i--;
    }
    if (i == -1) {
        return -1;
    }
    int j = size - 1;
    while (digits[j] <= digits[i]) {
        j--;
    }
    
    swap(digits[i], digits[j]);
    
    reverse(digits.begin() + i + 1, digits.end());
    
    long long result = 0;
   for (int i = 0; i < digits.size(); i++) {
    int digit = digits[i];
        result = result * 10 + digit;
    }
    
    if (result > INT_MAX) {
        return -1;
    }
    
    return static_cast<int>(result);

    }
};