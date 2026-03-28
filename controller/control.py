import serial


def crc8(data: list) -> int:
    crc = 0x00

    for byte in data:
        crc ^= byte
        for _ in range(8):
            if crc & 0x80:
                crc = ((crc << 1) ^ 0x07) & 0xFF
            else:
                crc = (crc << 1) & 0xFF

    return crc


def connect():
    return serial.Serial('/dev/ttyUSB0', 9600)


def motor_a(conn, ms):
    ms = ms & 0xFFFF
    msb = ms >> 8
    lsb = ms & 0xFF
    print((msb << 8) | lsb)
    crc = crc8([0x00, lsb, msb])
    conn.write(bytes([0xAA, 0x03, 0x00, lsb, msb, crc]))


def motor_b(conn, ms):
    ms = ms & 0xFFFF
    msb = ms >> 8
    lsb = ms & 0xFF
    print((msb << 8) | lsb)
    crc = crc8([0x01, lsb, msb])
    conn.write(bytes([0xAA, 0x03, 0x01, lsb, msb, crc]))
