from PrefixDectionary import Dictionary
import sys
sys.path.insert(0, "PrefixDictionary")


if __name__ == '__main__':
    dictionary = Dictionary()

    dictionary.insert("hello")
    dictionary.insert("world")
    dictionary.insert("this")
    dictionary.insert("is")
    dictionary.insert("Prefix")
    dictionary.insert("Dictionary")
    dictionary.insert("data")
    dictionary.insert("structure")

    print("world search:", dictionary.search("world"))
    print("uni search:", dictionary.search("uni"))
    print("Dictionary search:", dictionary.search("Dictionary"))
    print("there search:", dictionary.search("there"))

    dictionary.remove(dictionary.head, "world")
    dictionary.remove(dictionary.head, "Dictionary")
    print("world search:", dictionary.search("world"))
    print("Dictionary search:", dictionary.search("Dictionary"))

    print("words with prefix", dictionary.words_with_prefix("i"))
