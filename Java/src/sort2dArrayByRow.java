void main() {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int [][] arr2D = new int[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr2D[i][j] = sc.nextInt();
        }
    }

    for (int [] row: arr2D) {
        Arrays.sort(row);
    }
    System.out.println(Arrays.deepToString(arr2D));
}