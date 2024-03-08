def repeat_text(filename, repetitions):
    with open(filename, 'r') as file:
        content = file.read()
    with open(filename, 'w') as file:
        file.write(content * repetitions)

repeat_text('test.txt', 300)