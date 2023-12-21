class Solution {
    public int[][] imageSmoother(int[][] img) {
        int m = img.length, n = img[0].length;
        int[][] res = new int[m][n];

        int[] dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        int[] dy = {0, -1, -1, -1, 0, 1, 1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int c = 1;
                int sum = img[i][j];

                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        ++c;
                        sum += img[x][y];
                    }
                }

                res[i][j] = (int) Math.floor((double) sum / c);
            }
        }
        return res;
    }
}