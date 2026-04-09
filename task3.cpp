# =================================================================
# PROJECT: Lexical Analyzer (Compiler Design)
# DESCRIPTION: Identifies Keywords, Operators, and Identifiers from input.
# DELIVERABLE: Python script demonstrating lexical tokenization.
# =================================================================

import re

class LexicalAnalyzer:
    def __init__(self):
        # Defining Token Categories using Regular Expressions
        self.keywords = {'if', 'else', 'while', 'for', 'int', 'float', 'return', 'break'}
        self.operators = {'+', '-', '*', '/', '=', '==', '<', '>', '<=', '>='}
        self.punctuation = {';', '(', ')', '{', '}', ','}
        
    def analyze(self, code):
        print(f"📄 Input Code: {code}")
        print("\n" + "="*40)
        print(f"{'TOKEN':<15} | {'CATEGORY'}")
        print("="*40)

        # Splitting code into potential tokens using regex
        # This regex identifies words, numbers, and operators
        tokens = re.findall(r'[a-zA-Z_]\w*|\d+|==|<=|>=|[+\-*/=<>!]|[;(){},]', code)

        for token in tokens:
            if token in self.keywords:
                category = "KEYWORD"
            elif token in self.operators:
                category = "OPERATOR"
            elif token in self.punctuation:
                category = "PUNCTUATION"
            elif token.isdigit():
                category = "NUMBER"
            elif re.match(r'[a-zA-Z_]\w*', token):
                category = "IDENTIFIER"
            else:
                category = "UNKNOWN"
            
            print(f"{token:<15} | {category}")

# --- MAIN EXECUTION ---
if __name__ == "__main__":
    scanner = LexicalAnalyzer()

    # Sample Input Code (Simulating a line from a .c or .java file)
    sample_code = "int count = 10; if (count > 5) { return count; }"

    print("🚀 Initializing Lexical Analysis...")
    scanner.analyze(sample_code)

    print("\n" + "="*40)
    print("✅ Task 27 Complete: Lexical tokens identified successfully.")
    print("="*40)
