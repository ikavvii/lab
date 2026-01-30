void main() {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int [] array = new int[n];
    for (int i = 0; i < n; i++) array[i] = scanner.nextInt();

    // max element
    int max = array[0];
    for (int i : array) {
        if (i > max) max = i;
    }

    int [] visited = new int [max + 1];
    int count = 0;

    for (int i : array) {
        if (visited[i] == 0) visited[i] = 1;
        else {
            count++;
            visited[i] = -1;
        }
    }

    System.out.println("Total repeated elements = " + count);
    // print
    System.out.print("Repeated elements are ");
    for (int i : array ) {
        if (visited[i] == -1) {
            System.out.print(i + " ");
            visited[i] = 2; // already printed
        }
    }
}