// HS 1

void main(String[] args) {
    int units = Integer.parseInt(args[1]);

    double totalBill;

    if (units <= 100) {
        totalBill = units * 1.5;
    } else if (units <= 200) {
        totalBill = 100 * 1.5;
        units -= 100;
        totalBill += units * 2.5;
    } else {
        totalBill = 100 * 1.5 + 100 * 2.5;
        units -= 200;
        totalBill += units * 4;
    }

    // fixed meter charge
    totalBill += 75;
    System.out.println("Consumer name: " + args[0]);
    System.out.println("Units consumed: " + args[1]);

    System.out.println("Total bill amount: " + totalBill);
}