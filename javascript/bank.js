class Bank {
    #accounts; 

    constructor(bankName, branchName, IFSC, MICR) {
        this.bankName = bankName;
        this.branchName = branchName;
        this.IFSC = IFSC;
        this.MICR = MICR;
        this.#accounts = [];
    }

    createAccount(accNo, accHolder, initBal) {
        let account = new Account(accNo, accHolder, initBal);
        this.#accounts.push(account);
        console.log(`Account created successfully for ${accHolder}.`);
        return account;
    }

    getAccount(accNo) {
        return this.#accounts.find(acc => acc.accNo === accNo);
    }

    displayBankDetails() {
        console.log(`--- ${this.bankName} (${this.branchName}) ---`);
        console.log(`IFSC: ${this.IFSC} | MICR: ${this.MICR}`);
        console.log(`Total Accounts: ${this.#accounts.length}`);
    }
}

class Account {
    #bal;

    constructor(accNo, accHolder, initBal) {
        this.accNo = accNo;
        this.accHolder = accHolder;
        this.#bal = initBal;
    }

    get balance() {
        return this.#bal;
    }

    set withdraw(amount) {
        if (amount > this.#bal) {
            console.error("Error: Insufficient funds.");
        } else if (amount <= 0) {
            console.error("Error: Withdrawal amount must be positive.");
        } else {
            this.#bal -= amount;
            console.log(`Withdrawn: ₹${amount}. New Balance: ₹${this.#bal}`);
        }
    }

    set deposit(amount) {
        if (amount <= 0) {
            console.error("Error: Deposit amount must be positive.");
        } else {
            this.#bal += amount;
            console.log(`Deposited: ₹${amount}. New Balance: ₹${this.#bal}`);
        }
    }
}


let myBank = new Bank("Bank of India", "Tiruchirapalli", "BKID0008300", "620013001");

myBank.createAccount(101, "Kavin", 5000);
myBank.createAccount(102, "Vishal", 2000);

let userAccount = myBank.getAccount(101);

if (userAccount) {
    console.log(`Holder: ${userAccount.accHolder}`);
    console.log(`Initial Balance: ₹${userAccount.balance}`);

    userAccount.deposit = 1500;   // Depositing
    userAccount.withdraw = 2000;  // Withdrawing
    userAccount.withdraw = 10000; // Triggering "Insufficient funds"
}

myBank.displayBankDetails();