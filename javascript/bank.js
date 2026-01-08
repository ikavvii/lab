class Bank {
    #accounts; 

    constructor(bankName, branchName, IFSC, MICR) {
        this.bankName = bankName;
        this.branchName = branchName;
        this.IFSC = IFSC;
        this.MICR = MICR;
        this.#accounts = [];
    }

    createAccount(type, accNo, accHolder, initBal, extraValue) {
        let account;
        if (type.toLowerCase() === 'savings') {
            account = new SavingsAccount(accNo, accHolder, initBal, extraValue); // extraValue = interestRate
        } else {
            account = new CurrentAccount(accNo, accHolder, initBal, extraValue); // extraValue = overdraftLimit
        }
        
        this.#accounts.push(account);
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

    _updateBalance(amount) {
        this.#bal += amount;
    }

    set withdraw(amount) {
        if (amount > this.#bal) {
            console.log("Insufficient funds.");
            return false;
        }
        this.#bal -= amount;
        console.log(`Withdrawn: ₹${amount}. New Balance: ₹${this.#bal}`);
        return true;
    }
}

class SavingsAccount extends Account {
    constructor(accNo, accHolder, initBal, interestRate) {
        super(accNo, accHolder, initBal);
        this.interestRate = interestRate;
    }

    applyInterest() {
        const interest = this.balance * (this.interestRate / 100);
        this._updateBalance(interest);
        console.log(`Interest of ₹${interest} applied to Account ${this.accNo}.`);
    }
}

class CurrentAccount extends Account {
    constructor (accNo, accHolder, initBal, overdraftLimit) {
        super (accNo, accHolder, initBal);
        this.overdraftLimit = overdraftLimit;
    }

    set withdraw(amount) {
        if (amount > (this.balance + this.overdraftLimit)) {
            console.log("Overdraft limit exceeded!");
        } else {
            this._updateBalance(-amount);
            console.log(`Withdrawn ₹${amount}. New Balance: ₹${this.balance}`);
        }
    }
}

let myBank = new Bank("Bank of India", "Tiruchirapalli", "BKID0008300", "620013001");

myBank.createAccount("savings", 101, "Kavin", 5000, 5);
myBank.createAccount("current", 102, "Vishal", 2000, 10000);

let userAccount = myBank.getAccount(101);

if (userAccount) {
    console.log(`Holder: ${userAccount.accHolder}`);
    console.log(`Initial Balance: ₹${userAccount.balance}`);

    userAccount.withdraw = 2000;  // Withdrawing
    userAccount.withdraw = 10000; // Triggering "Insufficient funds"

    userAccount.applyInterest();
    console.log("Balance: ", userAccount.balance);
    
}

userAccount = myBank.getAccount(102); 

if (userAccount) {
    console.log(`Holder: ${userAccount.accHolder}`);
    console.log(`Initial Balance: ₹${userAccount.balance}`);

    userAccount.withdraw = 3000;  // Withdrawing with OD
    console.log("Balance: ", userAccount.balance);

    userAccount.withdraw = 10000; 
    console.log("Balance: ", userAccount.balance);
}


myBank.displayBankDetails();