def main():
    # Get input text from user
    text = input("Text: ")

    letters = 0
    words = 1  # Start at 1 since the last word doesn't end with a space
    sentences = 0

    # Loop through each character in the text
    for char in text:
        if char.isalpha():
            letters += 1
        elif char == ' ':
            words += 1
        elif char in ['.', '?', '!']:
            sentences += 1

    # Calculate L (average number of letters per 100 words) and S (average number of sentences per 100 words)
    L = (letters / words) * 100
    S = (sentences / words) * 100

    # Calculate the Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # Output the grade level
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()
