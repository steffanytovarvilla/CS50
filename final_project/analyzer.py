import re
import sys

def load_keywords(file_path):
    with open(file_path, "r") as file:
        return [line.strip() for line in file.readlines()]

def analyze_document(document_path, keywords):
    try:
        with open(document_path, "r") as file:
            text = file.read()
        results = {}
        for keyword in keywords:
            matches = re.findall(r"\b" + re.escape(keyword) + r"\b", text, re.IGNORECASE)
            results[keyword] = len(matches)
        return results
    except FileNotFoundError:
        print("Error: File {} not found.".format(document_path))
        sys.exit(1)

def main():
    if len(sys.argv) != 2:
        print("Usage: python analyzer.py <document_path>")
        sys.exit(1)
    document_path = sys.argv[1]
    keywords = load_keywords("keywords.txt")
    results = analyze_document(document_path, keywords)
    print("Keyword Analysis Results:")
    for keyword, count in results.items():
        print("{}: {}".format(keyword, count))

if __name__ == "__main__":
    main()
