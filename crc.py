def xor(a, b):
    result = []
    for i in range(1, len(b)):
        result.append('0' if a[i] == b[i] else '1')
    return ''.join(result)

def crc(data, generator):
    gen_len = len(generator)
    # Append zeros to data
    appended_data = data + '0' * (gen_len - 1)
    temp = appended_data[:gen_len]

    for i in range(len(data)):
        if temp[0] == '1':
            temp = xor(generator, temp) + appended_data[gen_len + i]
        else:
            temp = xor('0' * gen_len, temp) + appended_data[gen_len + i]
    remainder = temp[:-1]
    return remainder

def main():
    data = input("Enter data bits: ")
    generator = input("Enter generator bits: ")

    crc_code = crc(data, generator)
    print("CRC:", crc_code)

    transmitted = data + crc_code
    print("Transmitted data:", transmitted)

    # Simulate receiver side
    check = crc(transmitted, generator)
    if '1' in check:
        print("Error detected at receiver!")
    else:
        print("No error detected. Transmission successful.")

if __name__ == "__main__":
    main()
