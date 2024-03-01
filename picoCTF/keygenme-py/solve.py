import hashlib

bUsername_trial = b"MORTON"
key_part_static1_trial = "picoCTF{1n_7h3_|<3y_of_"
key_part_static2_trial = "}"


def get_flag(username_trial):
    indices = [4, 5, 3, 6, 2, 7, 1, 8]
    hashed = hashlib.sha256(username_trial).hexdigest()
    key = ''.join([hashed[i] for i in indices])

    print(key_part_static1_trial + key + key_part_static2_trial)


if __name__ == "__main__":
    get_flag(bUsername_trial)
