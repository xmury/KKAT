# Драйвер для общния с устройствами через COM порт
# При объявлении объекта класса serialDriver происходит установка соединений
# Для установки соединения self.open(), для закрытия self.close()
# На установку связи требуется некоторое время: time.sleep(2) , 2-х секунд обычно хватает
# Чтение пока работает с дикими перебоями. Но возможно что проблема в arduino (сам почти не верю)
# Собрал всё в класс. Изначальным код тут: 
# https://stackoverflow.com/questions/676172/full-examples-of-using-pyserial-package

import serial.tools.list_ports
import sys

class serialDriver():
    def __init__(self):
        import serial
        for Cports in serial.tools.list_ports.comports():
            if "Arduino" in Cports.description:
                for Ard in Cports:
                    m = int(Ard.find('M'))
                    
                    if Ard.find('(') + 3 == m:
                        port = 'COM' + str(Ard[m+1])
                        print(port)
                    else:
                        print("Device not faund")
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

def serial_ports():
    """ Lists serial port names

        :raises EnvironmentError:
            On unsupported or unknown platforms
        :returns:
            A list of the serial ports available on the system
    """
    if sys.platform.startswith('win'):
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this excludes your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')
    else:
        raise EnvironmentError('Unsupported platform')

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result


if __name__ == "__main__":
    # for Cports in serial.tools.list_ports.comports():
    #     if "Arduino" in Cports.description:
    #         for Ard in Cports:
    #             m = int(Ard.find('M'))

    #             if Ard.find('(') + 3 == m:
    #                 port = 'COM' + str(Ard[m+1])
    #                 print(port)

    #                 test = serialDriver(port)
    #                 test.open()
    #                 test.write('1')
    #                 info = test.read()
    #                 print(info)
    #                 test.close()                    
        
    print(serial_ports())

    # way = input("Get way to serial: ")
