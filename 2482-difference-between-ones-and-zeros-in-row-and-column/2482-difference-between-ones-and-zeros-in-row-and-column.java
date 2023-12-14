class Solution {
    public int[][] onesMinusZeros(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        int[] rowOnesCount = new int[m];
        int[] colOnesCount = new int[n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    rowOnesCount[i]++;
                    colOnesCount[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int onesRow = rowOnesCount[i];
                int onesCol = colOnesCount[j];
                int zerosRow = n - rowOnesCount[i];
                int zerosCol = m - colOnesCount[j];

                grid[i][j] = onesRow + onesCol - (zerosRow + zerosCol);

            }
        }

        return grid;
    }

}