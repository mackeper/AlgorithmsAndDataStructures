import socket

# python3 -c "print('\x00'*49968); print('\x00'*32);" | nc mercury.picoctf.net 36449
enc_flag = "551257106e1a52095f654f510a6b4954026c1e0304394100043a1c5654505b6b"
key = "622764205c786131695c7830325c7863645c7862615c7863345c786562316e5c"


def decrypt_flag(enc_flag, key):
    enc_flag = bytes.fromhex(enc_flag)
    key = bytes.fromhex(key)
    print(enc_flag)
    print(key)
    return bytes(map(lambda k, f: k ^ f, key, enc_flag)).decode()


def communicate_with_program(host, port, input_data):
    """ Didn't manage to get this to work for this challenge """
    recv_buffer_size = 1024
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))

        response = s.recv(recv_buffer_size).decode()
        print("Response:", response)

        for data in input_data:
            s.send(data.encode())
            response = s.recv(recv_buffer_size).decode()
            print("Response:", response)


if __name__ == "__main__":
    host = 'mercury.picoctf.net'
    port = 36449

    # Example usage:
    input_data = ["your_input_here",]
    # response = communicate_with_program(host, port, input_data)
    # print("Response:", response)

    print(decrypt_flag(enc_flag, key))
