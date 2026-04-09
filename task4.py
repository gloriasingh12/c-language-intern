# =================================================================
# PROJECT: Data Compression Tool
# DESCRIPTION: Implementing Run-Length Encoding (RLE) Algorithm.
# DELIVERABLE: A tool that handles both compression and decompression.
# =================================================================

class RLECompression:
    def compress(self, data):
        """Compresses text by counting consecutive characters."""
        if not data:
            return ""

        compressed = ""
        i = 0

        while i < len(data):
            count = 1
            while i + 1 < len(data) and data[i] == data[i + 1]:
                i += 1
                count += 1
            compressed += str(count) + data[i]
            i += 1

        return compressed

    def decompress(self, data):
        """Decompresses RLE text back to original form."""
        if not data:
            return ""

        decompressed = ""
        i = 0
        while i < len(data):
            # Extract the count (handles multi-digit counts)
            count_str = ""
            while i < len(data) and data[i].isdigit():
                count_str += data[i]
                i += 1
            
            count = int(count_str)
            char = data[i]
            decompressed += char * count
            i += 1

        return decompressed

# --- MAIN EXECUTION (Tool Simulation) ---
if __name__ == "__main__":
    tool = RLECompression()
    
    # Sample Input with repetitive data
    original_text = "AAAAABBBCCCCCDDEEEEEE"
    
    print(f"📄 Original Data:   {original_text}")
    print(f"📏 Original Size:   {len(original_text)} characters")

    # 1. Compression
    compressed_text = tool.compress(original_text)
    print("\n🚀 Compressing...")
    print(f"📦 Compressed Data: {compressed_text}")
    print(f"📉 Compressed Size: {len(compressed_text)} characters")
    
    # Calculation of Compression Ratio
    ratio = (1 - (len(compressed_text) / len(original_text))) * 100
    print(f"📊 Space Saved:     {ratio:.1f}%")

    # 2. Decompression
    decompressed_text = tool.decompress(compressed_text)
    print("\n🔓 Decompressing...")
    print(f"✨ Restored Data:   {decompressed_text}")

    # Integrity Check
    if original_text == decompressed_text:
        print("\n✅ Integrity Check: Success! Data is identical.")
    else:
        print("\n❌ Integrity Check: Failed.")

    print("\n" + "="*45)
    print("✅ Task 28 Complete: RLE Compression Tool Verified.")
    print("="*45)
