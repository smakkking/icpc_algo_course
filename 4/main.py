with open("input.txt", 'w') as file:
    file.writelines([
        "300000 299999\n",
        " ".join(map(str, range(300000)))
    ])