from HashTable import HashTable

if __name__ == '__main__':

    hash_table = HashTable(10)

    hash_table.AddValue(2)
    hash_table.AddValue(3)
    hash_table.AddValue(7)
    hash_table.AddValue(7)

    hash_table.Display()

    print()

    try:
        print(hash_table.getValue(9))
    except Exception as msg:
        print(msg)

    print()

    try:
        hash_table.deleteValue(9)
    except Exception as msg:
        print(msg)

    try:
        hash_table.deleteValue(2)
    except Exception as msg:
        print(msg)

    hash_table.Display()
