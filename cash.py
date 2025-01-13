def get_cents():
    # Ask how much the customer is owed (convert dollars to cents)
    while True:
        try:
            dollars = float(input("How much is owed: "))
            # Check if the value is positive and not zero
            if dollars > 0:
                cents = round(dollars * 100)  # Convert to cents and round
                return cents
            else:
                print("Please enter a positive value.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")


def calculate_quarters(cents):
    # Calculate the number of quarters to give the customer
    quarters = 0
    while cents >= 25:
        cents -= 25
        quarters += 1
    return quarters


def calculate_dimes(cents):
    # Calculate the number of dimes to give the customer
    dimes = 0
    while cents >= 10:
        cents -= 10
        dimes += 1
    return dimes


def calculate_nickels(cents):
    # Calculate the number of nickels to give the customer
    nickels = 0
    while cents >= 5:
        cents -= 5
        nickels += 1
    return nickels


def calculate_pennies(cents):
    # Calculate the number of pennies to give the customer
    pennies = 0
    while cents >= 1:
        cents -= 1
        pennies += 1
    return pennies


def main():
    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents -= nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents -= pennies * 1

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(f"{coins}")


if __name__ == "__main__":
    main()
