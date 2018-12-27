# Драйвер для общния с устройствами через COM порт
# При объявлении объекта класса serialDriver происходит установка соединений
# Для установки соединения self.open(), для закрытия self.close()
# На установку связи требуется некоторое время: time.sleep(2) , 2-х секунд обычно хватает
# Чтение пока работает с дикими перебоями. Но возможно что проблема в arduino (сам почти не верю)
# Собрал всё в класс. Изначальным код тут: 
# https://stackoverflow.com/questions/676172/full-examples-of-using-pyserial-package

class serialDriver():
    def __init__(self, port):
        import serial

        self.ser = serial.Serial(
            port = port,
            baudrate=9600,
            parity=serial.PARITY_ODD,
            stopbits=serial.STOPBITS_TWO,
            bytesize=serial.SEVENBITS
        )        

    def write(self, input2):
        test = bytes( input2 + '\r\n', encoding = 'utf-8')
        self.ser.write(test)

    def read(self):
        out = ''
        while self.ser.inWaiting() > 0:
            out += str(self.ser.read(1))
        return 'out\t:' + out

    def open(self):
        import time     
        self.ser.isOpen() 
        time.sleep(2)
    def close(self):    self.ser.close()

if __name__ == "__main__":
    way = input("Get way to serial: ")
    test = serialDriver(way)
    test.open()
    test.write('1')
    info = test.read()
    print(info)
    test.close()