void main(String[] args) {
  double curr = Double.parseDouble(args[0]);
  double withdrawalAmount = Double.parseDouble(args[1]);

  if (curr < 1000) {
    return;
  }

  if (withdrawalAmount > curr) {
    System.out.println("Insufficient balance");
    System.out.println("Current balance: " + curr);
    return;
  }

  if (withdrawalAmount % 100 == 0) {
    double newBal = curr - withdrawalAmount;
    if (newBal >= 1000) {
      System.out.println("Withdraw: "+ withdrawalAmount);
      System.out.println("Current balance: " + newBal);
    } else {
      System.out.println("Insufficient balance, minimum balance is 1000");
      System.out.println("Current balance: " + curr);
    }
  } else {
    System.out.println("Amount must be a multiple of 100");
  }
}