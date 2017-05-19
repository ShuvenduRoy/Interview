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

    @staticmethod
    def delete_from_trie(trie, word):
        current_dict = trie
        path = [current_dict]

        for letter in word:
            current_dict = current_dict.get(letter, None)
            path.append(current_dict)
            if current_dict is None:
                break

        else:
            if not path[-1].get(_end, None):
                return

            deleted_branch = []

            for current_dict, letter in zip(reversed(path[:-1]) , reversed(word)):
                if len(current_dict[letter]) <= 1:
                    deleted_branch.append((current_dict, letter))
                else:
                    break

            if len(deleted_branch) > 0:
                del deleted_branch[-1][0][deleted_branch[-1][1]]
            del path[-1][_end]


trie = Trie.make_trie('foo', 'bar', 'baz', 'barz')
Trie.insert_into_trie(trie, 'foro')
Trie.delete_from_trie(trie, 'foro')
print(Trie.in_trie(trie, 'foro'))