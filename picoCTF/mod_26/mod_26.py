def mod_encrypt(text: str, mod: int) -> str:
    for i in range(len(text)):
        if text[i].isalpha():
            if text[i].islower():
                text = text[:i] + chr(((ord(text[i]) - 97 + mod) % 26) + 97) + text[i+1:]
            else:
                text = text[:i] + chr(((ord(text[i]) - 65 + mod) % 26) + 65) + text[i+1:]

    return text


if __name__ == "__main__":
    print(mod_encrypt("cvpbPGS{arkg_gvzr_V'yy_gel_2_ebhaqf_bs_ebg13_Ncualgvd}", 13))
