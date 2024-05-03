def get_correct_bracket_sequence(s):
    stack = []
    to_remove = set()
    
    matching_bracket = {
        ')': '(',
        ']': '[',
        '}': '{'
    }
    
    for i, char in enumerate(s):
        if char in "([{":
            stack.append((char, i))
        elif char in ")]}":
            if not stack or stack[-1][0] != matching_bracket[char]:
                to_remove.add(i)
            else:
                stack.pop()
    
    # Add indices of remaining unmatched opening brackets to to_remove
    to_remove.update(index for _, index in stack)
    
    result = []
    for i, char in enumerate(s):
        if i not in to_remove:
            result.append(char)
    
    return ''.join(result)

# Пример использования
input_string = input()
correct_sequence = get_correct_bracket_sequence(input_string)

print("Правильная скобочная последовательность после удалений:", correct_sequence)
