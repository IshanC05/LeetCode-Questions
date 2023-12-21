class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, (int[] a, int[] b) -> Integer.compare(a[0], b[0]));

        int res = 0, n = points.length;

        for(int i = 1; i < n; i++){
            res = Math.max(res, points[i][0] - points[i - 1][0]);
        }

        return res;
    }
}