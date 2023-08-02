#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include "LibraryCode.hpp"


TEST(AccountTest, TestEmptyAccount)
{
  Account account;

  double balance = account.getBalance();

  ASSERT_EQ(0, balance);
}

class AccountTestFixture: public testing::Test
{
  /*
    FIXTURES help write better tests by allowing you to reuse certain 
    pieces of code overriding SetUp & TearDown functions in every single
    test.

    You use them when you have very similar SetUp/TearDown instructions 
    across a lot of different tests.

    Test setup -> SetUp()
    Test cleanup -> TearDown()

    A new fixture is created for each test
  */

  // Fixture flow of execution:
  // 1. Fixture Constructor
  // 2. SetUp
  // 3. Test body
  // 4. TearDown
  // 5. Destructor

  public:
   AccountTestFixture(); //constructor is preferred because you can use consts
   virtual ~AccountTestFixture(); //const/dest will always get called
   void SetUp() override; // SetUp used when calling virtual methods
   void TearDown() override; // TearDown used when throwing exceptions
   static void SetUpTestCase();
   static void TearDownTestCase();
  protected:
   Account account;
};

AccountTestFixture::AccountTestFixture()
{
  std::cout << "Constructor called\n";
}

AccountTestFixture::~AccountTestFixture()
{
  std::cout << "Destructor called\n";
}

void AccountTestFixture::SetUpTestCase()
{
  std::cout << "SetUpTestCase called\n";
}

void AccountTestFixture::TearDownTestCase()
{
  std::cout << "TearDownTestCase called\n";
}

void AccountTestFixture::SetUp()
{
    std::cout << "SetUp called\n";
    account.deposit(10.5);
}

void AccountTestFixture::TearDown()
{
    std::cout << "TearDown called\n";
}


TEST_F(AccountTestFixture, TestDeposit)
{ 
  std::cout << "Test body\n";
  ASSERT_EQ(10.5, account.getBalance());
}


TEST_F(AccountTestFixture,  TestWithdrawOK)
{
  account.withdraw(3);

  ASSERT_EQ(7.5, account.getBalance());
}


TEST_F(AccountTestFixture,  TestWithdrawInsufficientFunds)
{
  ASSERT_THROW(account.withdraw(300), std::runtime_error);
}


TEST_F(AccountTestFixture,  TestTransferOK)
{
  Account to;

  account.transfer(to, 2);
  
  ASSERT_EQ(8.5, account.getBalance());
  ASSERT_EQ(2, to.getBalance());
}


TEST_F(AccountTestFixture,  TestTransferInsufficientFunds)
{
  Account to;

  ASSERT_THROW(account.transfer(to, 200), std::runtime_error);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}