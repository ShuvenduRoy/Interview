_end = '_end_'

class Trie:
    @staticmethod
    def make_trie(*words):
     root = dict()
     for word in words:
         current_dict = root
         for letter in word:
             current_dict = current_dict.setdefault(letter, {})
         current_dict[_end] = _end
     return root

    @staticmethod
    def in_trie(trie, word):
        current_dict = trie

        for letter in word:
            if letter in current_dict:
                current_dict = current_dict[letter]
            else:
                return False
        else:
            if _end in current_dict:
                return True
            else:
                return False

    @staticmethod
    def insert_into_trie(trie, word):
        current_dict = trie

        for letter in word:
            current_dict = current_dict.setdefault(letter, {})
        current_dict[_end] = _end

    # Gives the right answer but don't clear the tree structure
    @staticmethod
    def simple_delete(trie, word):
        current_dict = trie

        for letter in word:
            current_dict = current_dict.get(letter, None)

            if current_dict is None:
                break

        else:
            del current_dict[_end]

trie = Trie.make_trie('foo', 'bar', 'baz', 'barz')
Trie.insert_into_trie(trie, 'foro')
Trie.delete_from_trie(trie, 'foro')
print(Trie.in_trie(trie, 'foro'))