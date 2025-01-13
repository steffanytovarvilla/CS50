# Legal Document Keyword Analyzer
#### Video Demo: [(https://youtu.be/hKDcStgCb7Y)]
#### Description:
The **Legal Document Keyword Analyzer** is a Python-based tool designed to analyze legal documents for key terms and phrases. It helps legal professionals identify and count occurrences of critical legal concepts within text files.

### Features:
- **Keyword Detection**: Scans a document for a list of pre-defined keywords provided in `keywords.txt`.
- **Frequency Analysis**: Counts and displays the number of times each keyword appears in the document.
- **Customizable**: Users can modify `keywords.txt` to include their own list of terms to analyze.

### Files Included:
1. `analyzer.py` - The main Python script that performs keyword detection and analysis.
2. `keywords.txt` - A text file containing the list of keywords to search for in the document.
3. `sample.txt` - A sample text file to test the analyzer.

### Usage:
1. **Prepare the Keywords File**:
   - Add the keywords to `keywords.txt`, one per line.

2. **Run the Script**:
   - Use the following command:
     ```bash
     python analyzer.py <document_path>
     ```
   - Replace `<document_path>` with the path to the text document you wish to analyze.

3. **Output**:
   - The script will display the frequency of each keyword in the terminal.

### Example:
For the document `sample2.txt` and keywords in `keywords.txt`, the script outputs the following: 
    Keyword Analysis Results:
    reasonable doubt: 0
    negligence: 1
    jurisdiction: 1
    evidence: 0
    bail: 0
    appellee: 0
    brief: 0
    appellant: 0
    appellate: 0
    damages: 1
    burden of proof: 0
    appeal: 0
    defendant: 0
    plaintiff: 0
    arraignment: 0
    adversary proceeding: 0
    affidavit: 0
    contract: 1
    admissible: 0
    acquittal: 0
    active judge: 0
    affirmed: 0


### This tool can assist legal professionals in quickly identifying and prioritizing documents based on keyword occurrences, saving time in document review processes.

### Additional Notes:
- The project uses Python's `re` module for keyword detection.
- Ensure all files are in the same directory before running the script.
