void main() {
    Scanner scanner=new Scanner(System.in);
    int n = scanner.nextInt();

    int [] array = new int[n];

    for (int i = 0; i < n; i++) array[i] = scanner.nextInt();

    int primeCount = 0, compositeCount = 0;
    boolean [] isPrime = new boolean[n];
    for (int i = 0; i < n; i++) {
        if (array[i] <= 1) {
            isPrime[i] = false; compositeCount++;
            continue;
        }

        boolean prime = true;
        // Check for factors from 2 up to the square root of n
        for (int j = 2; j * j <= array[i]; j++) {
            if (array[i] % j == 0) {
                // If a divisor is found, it is not a prime number
                prime= false;
                break;
            }
        }
        if (prime) {
            isPrime[i] = true;
            primeCount++;
        } else {
            isPrime[i] = false;
            compositeCount++;
        }
    }

    int [] prime = new int [primeCount];
    int [] composite = new int [compositeCount];

    int p = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime[i]) {
            prime[p++] = array[i];
        } else {
            composite[c++] = array[i];
        }
    }

    printf("Element of Prime array: ");
    printArray(prime, primeCount);
    printf("Element of Composite array: ");
    printArray(composite, compositeCount);
}

private void printf(String s) {
    System.out.printf(s);
}

private void printArray(int [] array, int count) {
    for(int i=0;i<count;i++) {
        System.out.print(array[i] + " ");
    }
    System.out.println();
}