#include <iostream>
#include <stdexcept>

class Base {
private:
  int m_classSecret;
protected:
  int protectedMember;
public:
  int publicVal = 0;

  Base(int cs): m_classSecret(cs) {
    protectedMember = 10 * m_classSecret;
  }

  void printStatus() {
    std::cout << "Base status\n";
    std::cout << "Base secret = " << m_classSecret << "\n";
    std::cout << "Protected Member = " << protectedMember << "\n";
  }
};

class Derived: public Base {
public:
  Derived(int cs): Base(cs) {
    std::cout << "Constructor Derived called.\n";
  }
  void printStatus() {
    std::cout << "Derived status\n";
    std::cout << "Derived protected = " << protectedMember << "\n";
  }
};

class ProtectedDerived: protected Base {
public:
  ProtectedDerived(int cs): Base(cs) {
    std::cout << "Constructor ProtectedDerived called.\n";
  }

  void printStatus() {
    std::cout << "ProtectedDerived status\n";
    std::cout << "ProtectedDerived protected = " << protectedMember << "\n";
    std::cout << "Protected inherited public val = " << publicVal << "\n";
  }
};

class PrivateDerived: private Base {
public:
  PrivateDerived(int cs) : Base(cs) {
    std::cout << "PrivateDerived Constructor called.\n";
  }

  void printStatus() {
    std::cout << "PrivateDerived status\n";
    std::cout << "No Public or Protected Data Members to display here.\n";
  }

  friend void exposeClass(PrivateDerived& obj);
  friend class PrivateDerivedModifier;
};

class PrivateDerivedModifier {
public:
  void modifyPrivateMembers(PrivateDerived& obj) {
    obj.publicVal = (obj.publicVal + 200) * 1000;
    obj.protectedMember = obj.protectedMember * 69 + 42;

    std::cout << "Modified parameters for the PrivateDerived obj.\n";
  }
};

void exposeClass(PrivateDerived& obj) {
  std::cout << "Exposing the PrivateDerived class:\n";
  std::cout << "publicVal = " << obj.publicVal << "\n";
  std::cout << "protectedMember = " << obj.protectedMember << "\n";
  std::cout << "These are private to the class & not accessible outside it.\n";
}

class Mysterious {
protected:
  int m_classMystry;
public:
  Mysterious(int cm): m_classMystry(cm) {
    std::cout << "Mysterious object created.\n";
  }
  virtual int mystryOperation(int operand) = 0;
};

class Unmysterious: public Mysterious {
public:
  Unmysterious(int cm): Mysterious(cm) {
    std::cout << "Unmysterious object created.\n";
  }

  int mystryOperation(int operand) override {
    std::cout << "Performing Mystry Operation.\n";
    return operand + m_classMystry;
  }
};

class superMys: public Mysterious, public Base {
public:
  superMys(int cm, int cs): Mysterious(cm), Base(cs) {}
  int mystryOperation(int operand) override {
    return 69;
  }
};

int main() {
  Base b(23);
  Derived d(46);
  ProtectedDerived pd(69);
  PrivateDerived prd(42);
  PrivateDerivedModifier pdm;
  Unmysterious um(56);
  superMys sm(29, 78);

  b.printStatus();
  d.printStatus();
  pd.printStatus();
  prd.printStatus();
  sm.printStatus();

  std::cout << "Public value for derived = " << d.publicVal << "\n";

  exposeClass(prd);
  pdm.modifyPrivateMembers(prd);
  exposeClass(prd);

  int mystryResult = um.mystryOperation(5);
  std::cout << "Mystry Result = " << mystryResult << "\n";

  mystryResult = sm.mystryOperation(23);
  std::cout << "Mystry Result = " << mystryResult << "\n";

  return 0;
}
