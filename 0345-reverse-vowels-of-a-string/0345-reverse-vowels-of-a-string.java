class Solution {
    public String reverseVowels(String s) {
        char[] arr = s.toCharArray();
        int l = 0, r = arr.length - 1;

        while (l < r) {
            // Move left pointer to next vowel
            while (l < r && !isVowel(arr[l])) l++;
            // Move right pointer to previous vowel
            while (l < r && !isVowel(arr[r])) r--;

            // Swap vowels
            char temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;

            l++;
            r--;
        }

        return new String(arr);
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
}