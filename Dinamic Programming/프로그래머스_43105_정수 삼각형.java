public class Solution {
    public int solution(int[][] triangle) {
        int n = triangle.length;
        int[][] maxSumStorage = new int[n][n];

        maxSumStorage[0][0] = triangle[0][0];

        for (int i = 1; i < triangle.length; i++) {
            maxSumStorage[i][0] = maxSumStorage[i - 1][0] + triangle[i][0];
            maxSumStorage[i][i] = maxSumStorage[i - 1][i - 1] + triangle[i][i];

            for (int j = 1; j < triangle[i].length - 1; j++) {
                maxSumStorage[i][j] = Math.max(maxSumStorage[i - 1][j - 1], maxSumStorage[i - 1][j]) + triangle[i][j];
            }
        }

        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            if (maxSumStorage[n - 1][i] > maxSum) maxSum = maxSumStorage[n - 1][i];
        }

        return maxSum;
    }

}
