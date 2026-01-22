class Solution {
    public int minimumPairRemoval(int[] nums) {
        java.util.ArrayList<Integer> list = new java.util.ArrayList<>();
        for (int x : nums) list.add(x);

        int operations = 0;

        while (!isNonDecreasing(list)) {
            int minSum = Integer.MAX_VALUE;
            int idx = 0;

            // Find adjacent pair with minimum sum
            for (int i = 0; i < list.size() - 1; i++) {
                int sum = list.get(i) + list.get(i + 1);
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            // Replace the pair with their sum
            int merged = list.get(idx) + list.get(idx + 1);
            list.remove(idx + 1);
            list.set(idx, merged);

            operations++;
        }

        return operations;
    }

    private boolean isNonDecreasing(java.util.ArrayList<Integer> list) {
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i) < list.get(i - 1)) {
                return false;
            }
        }
        return true;
    }
}
