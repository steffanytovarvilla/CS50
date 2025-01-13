# Get the height input from the user and ensure it's between 1 and 8
while True:
    user_input = input("Height: ")

    # Check if the input is empty
    if user_input.strip() == "":
        print("Please enter a valid height (a number between 1 and 8).")
        continue

    # Try to convert the input to an integer
    try:
        height = int(user_input)

        # Check if the height is within the valid range
        if height < 1 or height > 8:
            print("Please enter a height between 1 and 8.")
        else:
            break  # Valid input, exit the loop
    except ValueError:
        # If conversion fails, it's not a number
        print("Please enter a valid number.")

# Now that we have a valid height, create the pyramid
for row in range(height):  # Loop through each row
    # Print the spaces
    for spaces in range(height - row - 1):
        print(" ", end="")  # Print spaces without a newline

    # Print the hashes
    for column in range(row + 1):
        print("#", end="")  # Print hashes without a newline

    # Print a newline after each row
    print()
