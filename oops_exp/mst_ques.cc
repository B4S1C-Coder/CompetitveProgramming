#include <iostream>
#include <string>

class Recipient;

class Donor {
  std::string donor_name;
  double balance;

public:
  void set_details(std::string name, double amount) {
    donor_name = name;
    balance = amount;
  }

  Donor(std::string name = "Default Name", double bal = 100.0) : donor_name(name), balance(bal) {}
  
  double get_balance() { return balance; }

  void display() {
    std::cout << donor_name << " --> $" << balance << "\n";
  }

  friend bool transfer(Donor& donor, Recipient& recipient, double amount);
};

class Recipient {
  std::string recipient_name;
  double account_balance;
  double amount_required;

public:
  void set_details(std::string name, double balance, double amount) {
    recipient_name = name;
    account_balance = balance;
    amount_required = amount;
  }

  Recipient(std::string name="Default Name", double acc=0.0, double req=100.0)
    : recipient_name(name), account_balance(acc), amount_required(req) {}

  void display() {
    std::cout << recipient_name << " Bal: $" <<
      account_balance << " Req: $" << amount_required << "\n";
  }

  double get_balance() { return account_balance; }
  friend bool transfer(Donor& donor, Recipient& recipient, double amount);
};

bool transfer(Donor& donor, Recipient& recipient, double amount) {
  if (amount > donor.balance || amount <= 0 || recipient.amount_required <= 0) { return false; }

  donor.balance -= amount;
  recipient.account_balance += amount;
  recipient.amount_required -= amount;

  return true;
}

int main() {
  Donor donor("d1", 500.0);
  donor.display();

  Recipient recipient("r1", 50.0, 200.0);
  recipient.display();

  if (transfer(donor, recipient, 150.0)) {
    std::cout << "Transaction successful of $150.0\n";
  } else {
    std::cout << "Transaction failed.\n";
  }

  donor.display();
  recipient.display();
  
  if (transfer(donor, recipient, 500.0)) {
    std::cout << "Transaction successful of $50.0\n";
  } else {
    std::cout << "Transaction failed.\n";
  }

  donor.display();
  recipient.display();

  return 0;
}
